#include "ProgramBinary.h"

ProgramBinary::ProgramBinary(unsigned baseAddr)
    : mBaseAddress(baseAddr)
    , mEndAddress(baseAddr)
{
}

ProgramBinary::~ProgramBinary()
{
}

void ProgramBinary::emitByte(unsigned char byte)
{
    mCode.emplace_back(byte);
    ++mEndAddress;
}
