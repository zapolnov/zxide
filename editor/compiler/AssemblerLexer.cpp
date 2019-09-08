#include "AssemblerLexer.h"
#include "IErrorReporter.h"
#include <sstream>

namespace
{
    #define DIGIT \
             '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9'
    #define HEX_LOWER \
             'a': case 'b': case 'c': case 'd': case 'e': case 'f'
    #define HEX_UPPER \
             'A': case 'B': case 'C': case 'D': case 'E': case 'F'

    #define LETTER \
             'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': \
        case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': \
        case 'u': case 'v': case 'w': case 'x': case 'y': case 'z': \
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': \
        case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': \
        case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z'

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

AssemblerLexer::AssemblerLexer(File* file, const QByteArray& fileData, IErrorReporter* reporter)
    : mReporter(reporter)
    , mFile(file)
    , mSource(fileData.constData())
    , mSavedSource(nullptr)
    , mEnd(mSource + fileData.length())
    , mLine(1)
    , mSavedLine(1)
{
}

AssemblerLexer::~AssemblerLexer()
{
}

void AssemblerLexer::save()
{
    Q_ASSERT(mSavedSource == nullptr);
    mSavedSource = mSource;
    mSavedLine = mLine;
    mSavedToken = mToken;
}

void AssemblerLexer::restore()
{
    Q_ASSERT(mSavedSource != nullptr);
    mSource = mSavedSource;
    mLine = mSavedLine;
    mToken = mSavedToken;
    mSavedSource = nullptr;
}

void AssemblerLexer::forget()
{
    Q_ASSERT(mSavedSource != nullptr);
    mSavedSource = nullptr;
}

const Token& AssemblerLexer::nextToken()
{
    mToken.id = readToken();
    return mToken;
}

int AssemblerLexer::readToken()
{
    for (;;) {
        mToken.file = mFile;
        mToken.line = mLine;
        mToken.number = 0;
        mToken.text.clear();

        switch (*mSource) {
            case 0:
                if (mSource != mEnd)
                    error(mLine, tr("stray NUL in the program"));
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

            case '$':
                ++mSource;
                return T_DOLLAR;

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
                    if (*mSource == ':') {
                        ++mSource;
                        mToken.text = ss.str();
                        return T_LOCAL_LABEL;
                    }
                    mToken.text = ss.str();
                    return T_LOCAL_LABEL_NAME;
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

            case '_':
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
                mToken.text = ss.str();
                if (*mSource == '\''
                        && mToken.text.length() == 2
                        && tolower(mToken.text[0]) == 'a'
                        && tolower(mToken.text[1]) == 'f') {
                    ++mSource;
                    mToken.text += '\'';
                    return T_AF_SHADOW;
                } else if (*mSource == ':') {
                    ++mSource;
                    return (hadAt ? T_FULL_LABEL : T_LABEL);
                }
                return T_IDENTIFIER;
            }

            default:
                if (*mSource >= 32 && *mSource < 127)
                    error(mLine, tr("unexpected symbol '%1' in the program").arg(QChar(*mSource)));
                else {
                    error(mLine,
                        tr("unexpected symbol with code #%1 in the program").arg(int((unsigned char)*mSource)));
                }
                ++mSource;
                return T_EOF;
        }
    }
}

void AssemblerLexer::readHexNumber()
{
    mSource += 2;
    if (!isHexDigit(*mSource))
        error(mToken.line, tr("invalid hexadecimal literal"));

    quint64 value = 0;
    do {
        value <<= 4;
        value |= numericValue(*mSource++);
        if (value > 0xFFFFFFFF)
            error(mToken.line, tr("hexadecimal literal is too large"));
    } while (isHexDigit(*mSource));
    mToken.number = (quint32)value;
}

void AssemblerLexer::readBinNumber()
{
    mSource += 2;
    if (!isBinDigit(*mSource))
        error(mToken.line, tr("invalid binary literal"));

    quint64 value = 0;
    do {
        value <<= 1;
        value |= numericValue(*mSource++);
        if (value > 0xFFFFFFFF)
            error(mToken.line, tr("binary literal is too large"));
    } while (isBinDigit(*mSource));
    mToken.number = (quint32)value;
}

void AssemblerLexer::readDecNumber()
{
    quint64 value = 0;
    do {
        value *= 10;
        value += numericValue(*mSource++);
        if (value > 0xFFFFFFFF)
            error(mToken.line, tr("numeric literal is too large"));
    } while (isDigit(*mSource));
    mToken.number = (quint32)value;
}

void AssemblerLexer::readStringLiteral()
{
    std::stringstream ss;

    char quote = *mSource++;
    while (*mSource != quote) {
        switch (*mSource) {
            case 0:
                if (mSource != mEnd)
                    error(mLine, tr("stray NUL in the program"));
                else
                    error(mToken.line, tr("unterminated string literal"));
                break;

            case '\n':
                error(mToken.line, tr("unterminated string literal"));
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

                    case 'a': ++mSource; ss << '\a'; break;
                    case 'b': ++mSource; ss << '\b'; break;
                    case 'f': ++mSource; ss << '\f'; break;
                    case 'n': ++mSource; ss << '\n'; break;
                    case 'r': ++mSource; ss << '\r'; break;
                    case 't': ++mSource; ss << '\t'; break;
                    case 'v': ++mSource; ss << '\v'; break;

                    case 'x': {
                        ++mSource;
                        if (!isHexDigit(mSource[0]) || !isHexDigit(mSource[1]))
                            error(mLine, tr("invalid hexadecimal escape sequence"));
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
                                error(mLine, tr("value does not fit into a byte"));
                        } while (isDigit(*mSource));
                        ss << (char)(unsigned char)value;
                        break;
                    }

                    default:
                    bad:
                        error(mLine, tr("invalid escape sequence"));
                }
                break;

            default:
                ss << *mSource++;
                break;
        }
    }

    ++mSource;
    mToken.text = ss.str();
}

void AssemblerLexer::skipLineComment()
{
    ++mSource;
    while (*mSource && *mSource != '\n')
        ++mSource;
    if (!*mSource && mSource != mEnd)
        error(mLine, tr("stray NUL in the program"));
}

void AssemblerLexer::skipMultilineComment()
{
    for (;;) {
        ++mSource;
        switch (*mSource) {
            case 0:
                if (mSource != mEnd)
                    error(mLine, tr("stray NUL in the program"));
                else
                    error(mToken.line, tr("unterminated comment"));
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

void AssemblerLexer::error(int line, const QString& message)
{
    mReporter->error(mFile, line, message);
    throw LexerError();
}
