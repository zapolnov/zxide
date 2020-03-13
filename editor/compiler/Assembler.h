#ifndef COMPILER_ASSEMBLER_H
#define COMPILER_ASSEMBLER_H

#include <QObject>

class Compiler;
class Program;
class IErrorReporter;
struct SourceFile;

class Assembler : public QObject
{
    Q_OBJECT

public:
    Assembler(Compiler* compiler, Program* program, IErrorReporter* reporter);
    ~Assembler() override;

    bool parse(const SourceFile* file, const QByteArray& fileData);
    bool parseBlob(const SourceFile* file, const QByteArray& fileData);

private:
    Compiler* mCompiler;
    Program* mProgram;
    IErrorReporter* mReporter;

    Q_DISABLE_COPY(Assembler)
};

void initObfuscator();

#endif
