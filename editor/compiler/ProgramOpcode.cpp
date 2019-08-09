#include "ProgramOpcode.h"
#include "AssemblerToken.h"

ProgramOpcode::ProgramOpcode(const Token& token)
    : mFile(token.file)
    , mLine(token.line)
{
}

ProgramOpcode::~ProgramOpcode()
{
}

void ProgramOpcode::resolveAddress(quint32& address)
{
    address += lengthInBytes();
}
