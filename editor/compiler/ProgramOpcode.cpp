#include "ProgramOpcode.h"
#include "AssemblerToken.h"

ProgramOpcode::ProgramOpcode(const Token& token)
    : mToken(token)
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
