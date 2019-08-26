#ifndef COMPILER_ASSEMBLERPARSER_H
#define COMPILER_ASSEMBLERPARSER_H

#include <QObject>
#include <unordered_map>
#include <memory>

struct Token;
class AssemblerLexer;
class AssemblerContext;
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
    enum class OpcodeParseResult
    {
        Success,
        UnknownOpcode,
        SyntaxError,
    };

    AssemblerParser(AssemblerLexer* lexer, Program* program, IErrorReporter* reporter);
    ~AssemblerParser() override;

    void parse();

private:
    AssemblerLexer* mLexer;
    Program* mProgram;
    IErrorReporter* mReporter;
    QString mExpressionError;
    std::unique_ptr<AssemblerContext> mContext;
    static std::unordered_map<std::string, void(AssemblerParser::*)()> mDataDirectives;
    static std::unordered_map<std::string, void(AssemblerParser::*)()> mDirectives;

    template <typename T, typename... ARGS> T* pushContext(ARGS&&... args);
    void popContext();

    void parseLine();

    void parseSectionDecl();
    void parseRepeatDecl();
    void parseEndRepeatDecl();
    void parseIfDecl();
    void parseElseDecl();
    void parseEndIfDecl();

    void parseDefByte();
    void parseDefWord();
    void parseDefDWord();

    bool parseOpcode(const std::string& str);
    OpcodeParseResult parseOpcode_generated(const std::string& opcode); // in Z80Opcodes_parser.cpp

    std::string readLabelName(int tokenId);

    quint32 parseNumber(int tokenId, quint32 min = 0, quint32 max = 0xFFFFFFFF);
    std::unique_ptr<Expression> parseAtomicExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseUnaryExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseMultiplicationExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseAdditionExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseShiftExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseRelationalExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseEqualityExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseBitwiseAndExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseBitwiseXorExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseBitwiseOrExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseLogicalAndExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseLogicalOrExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseConditionalExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    std::unique_ptr<Expression> parseExpression(int tokenId, bool unambiguous); // in ExpressionParser.cpp
    bool tryParseExpression(int tokenId, std::unique_ptr<Expression>* out, bool unambiguous); // in ExpressionParser.cpp

    std::string expectIdentifier(int tokenId);
    void expectComma(int tokenId);
    void expectEol(int tokenId);

    bool matchEol();
    bool matchToken(int token);
    bool matchIdentifier(const char* ident);
    bool matchExpression(std::unique_ptr<Expression>* out);
    bool matchExpressionNegative(const Token& minusToken, std::unique_ptr<Expression>* out);
    bool matchByte(quint8* out);

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
