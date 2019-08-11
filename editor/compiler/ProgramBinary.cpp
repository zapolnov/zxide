#include "ProgramBinary.h"

ProgramBinary::ProgramBinary(unsigned baseAddr)
    : mBaseAddress(baseAddr)
    , mEndAddress(baseAddr)
{
}

ProgramBinary::~ProgramBinary()
{
}

void ProgramBinary::emitByte(quint8 byte)
{
    mCode.emplace_back(byte);
    ++mEndAddress;
}

void ProgramBinary::emitWord(quint16 word)
{
    mCode.emplace_back(quint8(word & 0xFF));
    mCode.emplace_back(quint8((word >> 8) & 0xFF));
    mEndAddress += 2;
}

void ProgramBinary::emitDWord(quint32 dword)
{
    mCode.emplace_back(quint8(dword & 0xFF));
    mCode.emplace_back(quint8((dword >> 8) & 0xFF));
    mCode.emplace_back(quint8((dword >> 16) & 0xFF));
    mCode.emplace_back(quint8((dword >> 24) & 0xFF));
    mEndAddress += 4;
}

void ProgramBinary::emitQWord(quint64 qword)
{
    mCode.emplace_back(quint8(qword & 0xFF));
    mCode.emplace_back(quint8((qword >> 8) & 0xFF));
    mCode.emplace_back(quint8((qword >> 16) & 0xFF));
    mCode.emplace_back(quint8((qword >> 24) & 0xFF));
    mCode.emplace_back(quint8((qword >> 32) & 0xFF));
    mCode.emplace_back(quint8((qword >> 40) & 0xFF));
    mCode.emplace_back(quint8((qword >> 48) & 0xFF));
    mCode.emplace_back(quint8((qword >> 56) & 0xFF));
    mEndAddress += 8;
}
