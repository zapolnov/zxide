#ifndef COMPILER_ASSEMBLER_H
#define COMPILER_ASSEMBLER_H

#include <QString>

class Program;
class File;
class IErrorReporter;

class Assembler
{
public:
    Assembler(Program* program, IErrorReporter* reporter);
    ~Assembler();

    void parse(File* file, const QByteArray& fileData);

private:
    Program* mProgram;
    IErrorReporter* mReporter;
    File* mFile;

    void error(File* file, int line, const QString& message);

    Q_DISABLE_COPY(Assembler)
};

#endif
