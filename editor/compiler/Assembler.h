#ifndef COMPILER_ASSEMBLER_H
#define COMPILER_ASSEMBLER_H

#include <QObject>

class Program;
class IErrorReporter;
struct SourceFile;

class Assembler : public QObject
{
    Q_OBJECT

public:
    Assembler(Program* program, IErrorReporter* reporter);
    ~Assembler() override;

    bool parse(const SourceFile* file, const QByteArray& fileData);

private:
    Program* mProgram;
    IErrorReporter* mReporter;

    Q_DISABLE_COPY(Assembler)
};

#endif
