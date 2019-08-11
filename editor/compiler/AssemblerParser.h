#ifndef COMPILER_ASSEMBLERPARSER_H
#define COMPILER_ASSEMBLERPARSER_H

#include <QObject>
#include <memory>

struct Token;
class AssemblerLexer;
class Program;
class ProgramSection;
class Expression;
class Z80OpcodeParser;
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
    QString mExpressionError;

    void parseLine();
    void parseSectionDecl();
    void parseOpcode();
    bool parseOpcode_generated(const std::string& opcode); // in Z80Opcodes_parser.cpp

    std::string readLabelName();

    quint32 parseNumber(int tokenId, quint32 min = 0, quint32 max = 0xFFFFFFFF);
    std::unique_ptr<Expression> parseAtomicExpression(int tokenId, bool allowParen); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseUnaryExpression(int tokenId, bool allowParen); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseExpression(int tokenId, bool allowParen); // in ExpressionParser.cpp
    bool tryParseExpression(int tokenId, std::unique_ptr<Expression>* out, bool allowParen); // in ExpressionParser.cpp

    std::string expectIdentifier(int tokenId);
    void expectComma(int tokenId);
    void expectEol(int tokenId);

    bool matchEol();
    bool matchToken(int token);
    bool matchIdentifier(const char* ident);
    bool matchExpression(std::unique_ptr<Expression>* out);
    bool matchExpressionNegative(const Token& minusToken, std::unique_ptr<Expression>* out);
    bool matchByte(unsigned char* out);
    bool matchWord(unsigned short* out);

    int nextToken() const;
    const Token& lastToken() const;
    int lastTokenId() const;
    const std::string& lastTokenText() const;
    const char* lastTokenCStr() const;

    void error(const QString& message);
    void error(const Token& token, const QString& message);

    Q_DISABLE_COPY(AssemblerParser)
    friend class Z80OpcodeParser;
};

#endif
