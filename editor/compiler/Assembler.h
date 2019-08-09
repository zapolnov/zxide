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
    ~Assembler();

    bool parse(File* file, const QByteArray& fileData);

private:
    Program* mProgram;
    IErrorReporter* mReporter;
    File* mFile;
    ProgramSection* mSection;
    const char* mSource;
    const char* mEnd;
    std::string mTokenText;
    quint64 mTokenValue;
    int mLine;
    int mTokenLine;

    void parseLine();

    int nextToken();
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
