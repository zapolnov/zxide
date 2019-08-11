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

void ProgramBinary::emitWord(unsigned short word)
{
    mCode.emplace_back(word & 0xFF);
    mCode.emplace_back((word >> 8) & 0xFF);
    mEndAddress += 2;
}
