#include "AssemblerParser.h"
#include "AssemblerLexer.h"
#include "IErrorReporter.h"
#include "Z80Opcodes.h"
#include "Util.h"
#include "Program.h"
#include <sstream>

AssemblerParser::AssemblerParser(AssemblerLexer* lexer, Program* program, IErrorReporter* reporter)
    : mLexer(lexer)
    , mProgram(program)
    , mReporter(reporter)
    , mSection(nullptr)
{
    mSection = mProgram->getOrCreateSection(std::string());
}

AssemblerParser::~AssemblerParser()
{
}

void AssemblerParser::parse()
{
    while (nextToken() != T_EOF)
        parseLine();
}

void AssemblerParser::parseLine()
{
    ProgramLabel* label = nullptr;

    // read label, if any
    if (lastTokenId() == T_LABEL || lastTokenId() == T_LOCAL_LABEL) {
        std::string name = readLabelName();
        label = mProgram->addLabel(lastToken(), mSection, name);
        if (!label)
            error(tr("duplicate label '%1'").arg(name.c_str()));
        nextToken();
    }

    // skip empty or label-only lines
    if (lastTokenId() == T_EOL)
        return;

    // read directive / instruction
    if (lastTokenId() != T_IDENTIFIER)
        error(tr("expected opcode or directive"));
    auto directive = toLower(lastTokenText());
    if (directive == "section")
        parseSectionDecl();
    else
        parseOpcode();
}

void AssemblerParser::parseSectionDecl()
{
    std::string sectionName = expectIdentifier(nextToken());
    mSection = mProgram->getOrCreateSection(sectionName);

    if (nextToken() == T_LBRACKET) {
        for (;;) {
            auto param = toLower(expectIdentifier(nextToken()));
            if (param == "align") {
                auto alignment = (unsigned)expectNumber(nextToken(), 1, 0xFFFF);
                if (mSection->hasAlignment() && mSection->alignment() != alignment) {
                    error(tr("conflicting alignment for section '%1' (%2 != %3)")
                        .arg(mSection->nameCStr()).arg(alignment).arg(mSection->alignment()));
                }
                if (mSection->hasBase() && (mSection->base() % alignment) != 0) {
                    error(tr("base address 0x%2 of section '%1' is not aligned to %3")
                        .arg(mSection->nameCStr()).arg(mSection->base(), 0, 10).arg(alignment));
                }
                mSection->setAlignment(alignment);
            } else if (param == "base") {
                auto base = (unsigned)expectNumber(nextToken());
                if (mSection->hasBase() && mSection->base() != base) {
                    error(tr("conflicting base address for section '%1' (%2 != %3)")
                        .arg(mSection->nameCStr()).arg(base).arg(mSection->base()));
                }
                if (mSection->hasAlignment() && (base % mSection->alignment()) != 0) {
                    error(tr("base address 0x%2 of section '%1' is not aligned to %3")
                        .arg(mSection->nameCStr()).arg(base, 0, 10).arg(mSection->alignment()));
                }
                mSection->setBase(base);
            } else
                error(tr("unexpected '%1'").arg(lastTokenCStr()));

            if (nextToken() == T_RBRACKET) {
                nextToken();
                break;
            }

            expectComma(lastTokenId());
        }
    }

    expectEol(lastTokenId());
    return;
}

void AssemblerParser::parseOpcode()
{
    auto opcode = toLower(lastTokenText());
    if (opcode == "ccf")
        mSection->emit<CCF>(lastToken());
    else if (opcode == "cpd")
        mSection->emit<CPD>(lastToken());
    else if (opcode == "cpdr")
        mSection->emit<CPDR>(lastToken());
    else if (opcode == "cpi")
        mSection->emit<CPI>(lastToken());
    else if (opcode == "cpir")
        mSection->emit<CPIR>(lastToken());
    else if (opcode == "cpl")
        mSection->emit<CPL>(lastToken());
    else if (opcode == "daa")
        mSection->emit<DAA>(lastToken());
    else if (opcode == "di")
        mSection->emit<DI>(lastToken());
    else if (opcode == "ei")
        mSection->emit<EI>(lastToken());
    else if (opcode == "exx")
        mSection->emit<EXX>(lastToken());
    else if (opcode == "halt")
        mSection->emit<HALT>(lastToken());
    else if (opcode == "ind")
        mSection->emit<IND>(lastToken());
    else if (opcode == "indr")
        mSection->emit<INDR>(lastToken());
    else if (opcode == "ini")
        mSection->emit<INI>(lastToken());
    else if (opcode == "inir")
        mSection->emit<INIR>(lastToken());
    else if (opcode == "ldd")
        mSection->emit<LDD>(lastToken());
    else if (opcode == "lddr")
        mSection->emit<LDDR>(lastToken());
    else if (opcode == "ldi")
        mSection->emit<LDI>(lastToken());
    else if (opcode == "ldir")
        mSection->emit<LDIR>(lastToken());
    else if (opcode == "neg")
        mSection->emit<NEG>(lastToken());
    else if (opcode == "nop")
        mSection->emit<NOP>(lastToken());
    else if (opcode == "otdr")
        mSection->emit<OTDR>(lastToken());
    else if (opcode == "otir")
        mSection->emit<OTIR>(lastToken());
    else if (opcode == "outd")
        mSection->emit<OUTD>(lastToken());
    else if (opcode == "outi")
        mSection->emit<OUTI>(lastToken());
    else if (opcode == "ret")
        mSection->emit<RET>(lastToken());
    else if (opcode == "reti")
        mSection->emit<RETI>(lastToken());
    else if (opcode == "retn")
        mSection->emit<RETN>(lastToken());
    else if (opcode == "rla")
        mSection->emit<RLA>(lastToken());
    else if (opcode == "rlca")
        mSection->emit<RLCA>(lastToken());
    else if (opcode == "rld")
        mSection->emit<RLD>(lastToken());
    else if (opcode == "rra")
        mSection->emit<RRA>(lastToken());
    else if (opcode == "rrca")
        mSection->emit<RRCA>(lastToken());
    else if (opcode == "rrd")
        mSection->emit<RRD>(lastToken());
    else if (opcode == "scf")
        mSection->emit<SCF>(lastToken());
    else
        error(tr("unexpected '%1'").arg(lastTokenCStr()));
}

std::string AssemblerParser::readLabelName()
{
    switch (lastTokenId()) {
        case T_LABEL: {
            const auto& name = lastTokenText();
            mLastNonLocalLabel = name;
            return name;
        }

        case T_LOCAL_LABEL: {
            if (mLastNonLocalLabel.empty())
                error(tr("local label without previous global one"));
            std::stringstream ss;
            ss << mLastNonLocalLabel;
            ss << "@@";
            ss << lastTokenText();
            return ss.str();
        }
    }

    Q_ASSERT(false);
    error(tr("internal compiler error"));
    return std::string();
}

quint32 AssemblerParser::expectNumber(int tokenId, quint32 min, quint32 max)
{
    if (tokenId != T_NUMBER)
        error(tr("expected numeric literal"));

    quint32 number = lastToken().number;
    if (number < min || number > max) {
        error(tr("numeric value is out of range (valid range is 0x%1..0x%2 inclusive)")
            .arg(min, 0, 16).arg(max, 0, 16));
    }

    return number;
}

std::string AssemblerParser::expectIdentifier(int tokenId)
{
    if (tokenId != T_IDENTIFIER)
        error(tr("expected identifier"));
    return lastTokenText();
}

void AssemblerParser::expectComma(int tokenId)
{
    if (tokenId != T_COMMA)
        error(tr("expected ','"));
}

void AssemblerParser::expectEol(int tokenId)
{
    if (tokenId != T_EOL)
        error(tr("expected end of line"));
}

int AssemblerParser::nextToken() const
{
    return mLexer->nextToken().id;
}

const Token& AssemblerParser::lastToken() const
{
    return mLexer->lastToken();
}

int AssemblerParser::lastTokenId() const
{
    return lastToken().id;
}

const std::string& AssemblerParser::lastTokenText() const
{
    return mLexer->lastToken().text;
}

const char* AssemblerParser::lastTokenCStr() const
{
    return mLexer->lastToken().text.c_str();
}

void AssemblerParser::error(const QString& message)
{
    error(mLexer->lastToken(), message);
}

void AssemblerParser::error(const Token& token, const QString& message)
{
    mReporter->error(token.file, token.line, message);
    throw ParserError();
}