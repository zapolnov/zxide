#ifndef COMPILER_ASSEMBLERPARSER_H
#define COMPILER_ASSEMBLERPARSER_H

#include <QObject>

struct Token;
class AssemblerLexer;
class Program;
class ProgramSection;
class IErrorReporter;

class ParserError
{
};

class AssemblerParser : public QObject
{
    Q_OBJECT

public:
    AssemblerParser(AssemblerLexer* lexer, Program* program, IErrorReporter* reporter);
    ~AssemblerParser() override;

    void parse();

private:
    AssemblerLexer* mLexer;
    Program* mProgram;
    IErrorReporter* mReporter;
    ProgramSection* mSection;
    std::string mLastNonLocalLabel;

    void parseLine();
    void parseSectionDecl();
    void parseOpcode();
    bool parseOpcode_generated(const std::string& opcode); // in Z80Opcodes_parser.cpp

    std::string readLabelName();

    quint32 expectNumber(int tokenId, quint32 min = 0, quint32 max = 0xFFFFFFFF);
    bool expectByteLiteral(unsigned* out);
    bool expectWordLiteral(unsigned* out);
    bool expectRelativeByteOffset(unsigned* out);
    std::string expectIdentifier(int tokenId);
    void expectComma(int tokenId);
    void expectEol(int tokenId);

    int nextToken() const;
    const Token& lastToken() const;
    int lastTokenId() const;
    const std::string& lastTokenText() const;
    const char* lastTokenCStr() const;

    void error(const QString& message);
    void error(const Token& token, const QString& message);

    Q_DISABLE_COPY(AssemblerParser)
};

#endif
