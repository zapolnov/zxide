#include "ProgramOpcode.h"
#include "AssemblerToken.h"

ProgramOpcode::ProgramOpcode(const Token& token)
    : mFile(token.file)
    , mLine(token.line)
    , mAddress(-1)
{
}

ProgramOpcode::~ProgramOpcode()
{
}

void ProgramOpcode::resolveAddress(const ProgramSection*, quint32& address)
{
    mAddress = qint32(address);
    address += lengthInBytes();
}

bool ProgramOpcode::resolveValues(const ProgramSection*, IErrorReporter*)
{
    return true;
}
