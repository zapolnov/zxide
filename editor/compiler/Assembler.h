#ifndef COMPILER_ASSEMBLER_H
#define COMPILER_ASSEMBLER_H

#include <QObject>
#include <string>

class Program;
class ProgramSection;
class IErrorReporter;
class File;

class Assembler : public QObject
{
    Q_OBJECT

public:
    Assembler(Program* program, IErrorReporter* reporter);
    ~Assembler() override;

    bool parse(File* file, const QByteArray& fileData);

private:
    Program* mProgram;
    IErrorReporter* mReporter;
    File* mFile;
    ProgramSection* mSection;
    std::string mLastNonLocalLabel;
    const char* mSource;
    const char* mEnd;
    std::string mTokenText;
    quint32 mTokenValue;
    int mLine;
    int mTokenLine;
    int mTokenId;

    // parser
    void parseLine();
    void parseSectionDecl();
    void parseOpcode();
    quint32 expectNumber(int tokenId, quint32 min = 0, quint32 max = 0xFFFFFFFF);
    std::string expectIdentifier(int tokenId);
    void expectComma(int tokenId);
    void expectEol(int tokenId);

    // lexer
    int nextToken();
    int readToken();
    void readHexNumber();
    void readBinNumber();
    void readDecNumber();
    void readStringLiteral();
    void skipLineComment();
    void skipMultilineComment();

    void error(File* file, int line, const QString& message);

    Q_DISABLE_COPY(Assembler)
};

#endif
