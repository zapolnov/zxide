#include "Assembler.h"
#include "IErrorReporter.h"
#include "Program.h"
#include <sstream>

namespace
{
    enum Token
    {
        T_EOF = 0,
        T_EOL,
        T_IDENTIFIER,
        T_NUMBER,
        T_STRING,
        T_LABEL,
        T_LOCAL_LABEL,
        T_AT,
        T_COMMA,
        T_QUESTION,
        T_COLON,
        T_LPAREN,
        T_RPAREN,
        T_LBRACKET,
        T_RBRACKET,
        T_LCURLY,
        T_RCURLY,
        T_AMPERSAND,
        T_LOGIC_AND,
        T_VERTICALBAR,
        T_LOGIC_OR,
        T_CARET,
        T_TILDE,
        T_PLUS,
        T_MINUS,
        T_ASTERISK,
        T_SLASH,
        T_PERCENT,
        T_ASSIGN,
        T_EXCLAMATION,
        T_EQUAL,
        T_NOT_EQUAL,
        T_LESS,
        T_LESS_EQUAL,
        T_SHL,
        T_GREATER,
        T_GREATER_EQUAL,
        T_SHR,
    };

    class CompilationFailed
    {
    };

    #define DIGIT \
             '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9'
    #define HEX_LOWER \
             'a': case 'b': case 'c': case 'd': case 'e': case 'f'
    #define HEX_UPPER \
             'A': case 'B': case 'C': case 'D': case 'E': case 'F'

    #define LETTER \
             'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': \
        case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': \
        case 'u': case 'v': case 'w': case 'x': case 'y': case 'z'

    static bool isDigit(char ch)
    {
        switch (ch) {
            case DIGIT:
                return true;
        }
        return false;
    }

    static bool isHexDigit(char ch)
    {
        switch (ch) {
            case DIGIT:
                return true;
            case HEX_LOWER:
                return true;
            case HEX_UPPER:
                return true;
        }
        return false;
    }

    static bool isBinDigit(char ch)
    {
        switch (ch) {
            case '0':
            case '1':
                return true;
        }
        return false;
    }

    static bool isIdent(char ch)
    {
        switch (ch) {
            case LETTER:
                return true;
            case DIGIT:
                return true;
            case '_':
                return true;
        }
        return false;
    }

    static int numericValue(char ch)
    {
        switch (ch) {
            case DIGIT:
                return (ch - '0');
            case HEX_LOWER:
                return (ch - 'a' + 10);
            case HEX_UPPER:
                return (ch - 'A' + 10);
        }
        Q_ASSERT(false);
        return 0;
    }
}

Assembler::Assembler(Program* program, IErrorReporter* reporter)
    : mProgram(program)
    , mReporter(reporter)
    , mFile(nullptr)
    , mSection(nullptr)
    , mSource(nullptr)
    , mEnd(nullptr)
    , mLine(0)
    , mTokenLine(0)
{
}

Assembler::~Assembler()
{
}

bool Assembler::parse(File* file, const QByteArray& fileData)
{
    try {
        mFile = file;
        mSection = mProgram->getOrCreateSection(std::string());
        mLine = 1;
        mTokenLine = 1;
        mSource = fileData.constData();
        mEnd = mSource + fileData.length();

        while (nextToken() != T_EOF)
            parseLine();

        return true;
    } catch (const CompilationFailed&) {
        return false;
    }
}

void Assembler::parseLine()
{
    ProgramLabel* label = nullptr;

    // read label, if any
    switch (mTokenId) {
        case T_LABEL:
            label = mProgram->addLabel(mFile, mTokenLine, mSection, mTokenText);
            if (!label)
                error(mFile, mTokenLine, tr("duplicate label '%1'").arg(mTokenText.c_str()));
            mLastNonLocalLabel = mTokenText;
            nextToken();
            break;

        case T_LOCAL_LABEL:
            if (mLastNonLocalLabel.empty())
                error(mFile, mTokenLine, tr("local label without previous global one").arg(mTokenText.c_str()));
            label = mProgram->addLabel(mFile, mTokenLine, mSection, mLastNonLocalLabel + "@@" + mTokenText);
            if (!label)
                error(mFile, mTokenLine, tr("duplicate local label '%1'").arg(mTokenText.c_str()));
            nextToken();
            break;
    }

    // skip empty or label-only lines
    if (mTokenId == T_EOL)
        return;

    // read directive / instruction
    if (mTokenId != T_IDENTIFIER)
        error(mFile, mTokenLine, tr("expected opcode or directive"));
    if (mTokenText == "section")
        parseSectionDecl();
    else
        parseOpcode();
}

void Assembler::parseSectionDecl()
{
    std::string sectionName = expectIdentifier(nextToken());
    mSection = mProgram->getOrCreateSection(sectionName);

    if (nextToken() == T_LBRACKET) {
        for (;;) {
            expectIdentifier(nextToken());
            if (mTokenText == "align") {
                auto alignment = (unsigned)expectNumber(nextToken(), 1, 0xFFFF);
                if (mSection->hasAlignment() && mSection->alignment() != alignment) {
                    error(mFile, mTokenLine, tr("conflicting alignment for section '%1' (%2 != %3)")
                        .arg(mSection->name().c_str()).arg(alignment).arg(mSection->alignment()));
                }
                if (mSection->hasBase() && (mSection->base() % alignment) != 0) {
                    error(mFile, mTokenLine, tr("base address 0x%2 of section '%1' is not aligned to %3")
                        .arg(mSection->name().c_str()).arg(mSection->base(), 0, 10).arg(alignment));
                }
                mSection->setAlignment(alignment);
            } else if (mTokenText == "base") {
                auto base = (unsigned)expectNumber(nextToken());
                if (mSection->hasBase() && mSection->base() != base) {
                    error(mFile, mTokenLine, tr("conflicting base address for section '%1' (%2 != %3)")
                        .arg(mSection->name().c_str()).arg(base).arg(mSection->base()));
                }
                if (mSection->hasAlignment() && (base % mSection->alignment()) != 0) {
                    error(mFile, mTokenLine, tr("base address 0x%2 of section '%1' is not aligned to %3")
                        .arg(mSection->name().c_str()).arg(base, 0, 10).arg(mSection->alignment()));
                }
                mSection->setBase(base);
            } else
                error(mFile, mTokenLine, tr("unexpected '%1'").arg(mTokenText.c_str()));

            if (nextToken() == T_RBRACKET) {
                nextToken();
                break;
            }

            expectComma(mTokenId);
        }
    }

    expectEol(mTokenId);
    return;
}

void Assembler::parseOpcode()
{
    if (mTokenText == "ret")
        ; // FIXME
    else
        error(mFile, mTokenLine, tr("unexpected '%1'").arg(mTokenText.c_str()));
}

quint32 Assembler::expectNumber(int tokenId, quint32 min, quint32 max)
{
    if (tokenId != T_NUMBER)
        error(mFile, mTokenLine, tr("expected numeric literal"));

    if (mTokenValue < min || mTokenValue > max) {
        error(mFile, mTokenLine,
            tr("numeric value is out of range (valid range is 0x%1..0x%2 inclusive)").arg(min, 0, 16).arg(max, 0, 16));
    }

    return mTokenValue;
}

std::string Assembler::expectIdentifier(int tokenId)
{
    if (tokenId != T_IDENTIFIER)
        error(mFile, mTokenLine, tr("expected identifier"));
    return mTokenText;
}

void Assembler::expectComma(int tokenId)
{
    if (tokenId != T_COMMA)
        error(mFile, mTokenLine, tr("expected ','"));
}

void Assembler::expectEol(int tokenId)
{
    if (tokenId != T_EOL)
        error(mFile, mTokenLine, tr("expected end of line"));
}

int Assembler::nextToken()
{
    mTokenId = readToken();
    return mTokenId;
}

int Assembler::readToken()
{
    for (;;) {
        mTokenLine = mLine;
        mTokenValue = 0;
        mTokenText.clear();
        switch (*mSource) {
            case 0:
                if (mSource != mEnd)
                    error(mFile, mLine, tr("stray NUL in the program"));
                return T_EOF;

            case ' ':
            case '\t':
            case '\r':
            case '\v':
            case '\f':
                ++mSource;
                continue;

            case '\n':
                ++mSource;
                ++mLine;
                return T_EOL;

            case ';':
                skipLineComment();
                continue;

            case ',':
                ++mSource;
                return T_COMMA;

            case '?':
                ++mSource;
                return T_QUESTION;

            case ':':
                ++mSource;
                return T_COLON;

            case '(':
                ++mSource;
                return T_LPAREN;

            case ')':
                ++mSource;
                return T_RPAREN;

            case '[':
                ++mSource;
                return T_LBRACKET;

            case ']':
                ++mSource;
                return T_RBRACKET;

            case '{':
                ++mSource;
                return T_LCURLY;

            case '}':
                ++mSource;
                return T_RCURLY;

            case '&':
                ++mSource;
                if (*mSource == '&') {
                    ++mSource;
                    return T_LOGIC_AND;
                }
                return T_AMPERSAND;

            case '|':
                ++mSource;
                if (*mSource == '|') {
                    ++mSource;
                    return T_LOGIC_OR;
                }
                return T_VERTICALBAR;

            case '^':
                ++mSource;
                return T_CARET;

            case '~':
                ++mSource;
                return T_TILDE;

            case '+':
                ++mSource;
                return T_PLUS;

            case '-':
                ++mSource;
                return T_MINUS;

            case '*':
                ++mSource;
                return T_ASTERISK;

            case '%':
                ++mSource;
                return T_PERCENT;

            case '/':
                ++mSource;
                if (*mSource == '/') {
                    skipLineComment();
                    continue;
                } else if (*mSource == '*') {
                    skipMultilineComment();
                    continue;
                }
                return T_SLASH;

            case '@': {
                ++mSource;
                if (*mSource == '@') {
                    ++mSource;
                    std::stringstream ss;
                    while (isIdent(*mSource))
                        ss << *mSource++;
                    if (*mSource != ':')
                        error(mFile, mLine, "missing ':' after label name.");
                    ++mSource;
                    mTokenText = ss.str();
                    return T_LOCAL_LABEL;
                }
                return T_AT;
            }

            case '=':
                ++mSource;
                if (*mSource == '=') {
                    ++mSource;
                    return T_EQUAL;
                }
                return T_ASSIGN;

            case '!':
                ++mSource;
                if (*mSource == '=') {
                    ++mSource;
                    return T_NOT_EQUAL;
                }
                return T_EXCLAMATION;

            case '<':
                ++mSource;
                if (*mSource == '<') {
                    ++mSource;
                    return T_SHL;
                } else if (*mSource == '=') {
                    ++mSource;
                    return T_LESS_EQUAL;
                }
                return T_LESS;

            case '>':
                ++mSource;
                if (*mSource == '>') {
                    ++mSource;
                    return T_SHR;
                } else if (*mSource == '=') {
                    ++mSource;
                    return T_GREATER_EQUAL;
                }
                return T_GREATER;

            case '\'':
            case '"':
                readStringLiteral();
                return T_STRING;

            case DIGIT: {
                if (mSource[0] == '0' && mSource[1] == 'x')
                    readHexNumber();
                else if (mSource[0] == '0' && mSource[1] == 'b')
                    readBinNumber();
                else
                    readDecNumber();
                return T_NUMBER;
            }

            case LETTER: {
                std::stringstream ss;
                bool hadAt = false;
                for (;;) {
                    ss << *mSource++;
                    if (!isIdent(*mSource)) {
                        if (mSource[0] == '@' && mSource[1] == '@' && !hadAt) {
                            mSource += 2;
                            ss << '@' << '@';
                            hadAt = true;
                            continue;
                        }
                        break;
                    }
                }
                mTokenText = ss.str();
                if (*mSource == ':') {
                    ++mSource;
                    return T_LABEL;
                }
                return T_IDENTIFIER;
            }

            default:
                if (*mSource >= 32 && *mSource < 127)
                    error(mFile, mLine, tr("unexpected symbol '%1' in the program").arg(QChar(*mSource)));
                else {
                    error(mFile, mLine,
                        tr("unexpected symbol with code #%1 in the program").arg(int((unsigned char)*mSource)));
                }
                ++mSource;
                return T_EOF;
        }
    }
}

void Assembler::readHexNumber()
{
    mSource += 2;
    if (!isHexDigit(*mSource))
        error(mFile, mTokenLine, tr("invalid hexadecimal literal"));

    quint64 value = 0;
    do {
        value <<= 4;
        value |= numericValue(*mSource++);
        if (value > 0xFFFFFFFF)
            error(mFile, mTokenLine, tr("hexadecimal literal is too large"));
    } while (isHexDigit(*mSource));
    mTokenValue = (quint32)value;
}

void Assembler::readBinNumber()
{
    mSource += 2;
    if (!isBinDigit(*mSource))
        error(mFile, mTokenLine, tr("invalid binary literal"));

    quint64 value = 0;
    do {
        value <<= 1;
        value |= numericValue(*mSource++);
        if (value > 0xFFFFFFFF)
            error(mFile, mTokenLine, tr("binary literal is too large"));
    } while (isBinDigit(*mSource));
    mTokenValue = (quint32)value;
}

void Assembler::readDecNumber()
{
    quint64 value = 0;
    do {
        value *= 10;
        value += numericValue(*mSource++);
        if (value > 0xFFFFFFFF)
            error(mFile, mTokenLine, tr("numeric literal is too large"));
    } while (isDigit(*mSource));
    mTokenValue = (quint32)value;
}

void Assembler::readStringLiteral()
{
    std::stringstream ss;

    char quote = *mSource++;
    while (*mSource != quote) {
        switch (*mSource) {
            case 0:
                if (mSource != mEnd)
                    error(mFile, mLine, tr("stray NUL in the program"));
                else
                    error(mFile, mTokenLine, tr("unterminated string literal"));
                break;

            case '\n':
                error(mFile, mTokenLine, tr("unterminated string literal"));
                break;

            case '\\':
                ++mSource;
                switch (*mSource) {
                    case 0:
                        break;

                    case '\n':
                        ++mSource;
                        ++mLine;
                        ss << '\n';
                        break;

                    case '\r':
                        if (mSource[1] == '\n') {
                            ++mLine;
                            mSource += 2;
                            ss << '\n';
                            break;
                        }
                        goto bad;

                    case '\\':
                    case '"':
                    case '\'':
                        ss << *mSource++;
                        break;

                    case 'x': {
                        ++mSource;
                        if (!isHexDigit(mSource[0]) || !isHexDigit(mSource[1]))
                            error(mFile, mLine, tr("invalid hexadecimal escape sequence"));
                        unsigned value = numericValue(*mSource++) << 4;
                        value |= numericValue(*mSource++);
                        ss << (char)(unsigned char)value;
                        break;
                    }

                    case DIGIT: {
                        unsigned value = 0;
                        do {
                            value *= 10;
                            value += numericValue(*mSource++);
                            if (value > 0xFF)
                                error(mFile, mLine, tr("value does not fit into a byte"));
                        } while (isDigit(*mSource));
                        ss << (char)(unsigned char)value;
                        break;
                    }

                    default:
                    bad:
                        error(mFile, mLine, tr("invalid escape sequence"));
                }
                break;

            default:
                ss << *mSource++;
                break;
        }
    }

    mTokenText = ss.str();
}

void Assembler::skipLineComment()
{
    ++mSource;
    while (*mSource && *mSource != '\n')
        ++mSource;
    if (!*mSource && mSource != mEnd)
        error(mFile, mLine, tr("stray NUL in the program"));
}

void Assembler::skipMultilineComment()
{
    for (;;) {
        ++mSource;
        switch (*mSource) {
            case 0:
                if (mSource != mEnd)
                    error(mFile, mLine, tr("stray NUL in the program"));
                else
                    error(mFile, mTokenLine, tr("unterminated comment"));
                return;

            case '\n':
                ++mLine;
                break;

            case '*':
                if (mSource[1] == '/') {
                    mSource += 2;
                    return;
                }
                break;
        }
    }
}

void Assembler::error(File* file, int line, const QString& message)
{
    mReporter->error(file, line, message);
    throw CompilationFailed();
}
