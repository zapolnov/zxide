#include "Assembler.h"
#include "IErrorReporter.h"
#include "Program.h"

Assembler::Assembler(Program* program, IErrorReporter* reporter)
    : mProgram(program)
    , mReporter(reporter)
    , mFile(nullptr)
{
}

Assembler::~Assembler()
{
}

void Assembler::parse(File* file, const QByteArray& fileData)
{
    mFile = file;
}

void Assembler::error(File* file, int line, const QString& message)
{
    mReporter->error(file, line, message);
}
