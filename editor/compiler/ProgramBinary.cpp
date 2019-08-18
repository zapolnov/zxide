#include "ProgramBinary.h"
#include "compiler/ProgramDebugInfo.h"

ProgramBinary::ProgramBinary(unsigned baseAddr)
    : mDebugInfo(std::make_unique<ProgramDebugInfo>())
    , mBaseAddress(baseAddr)
    , mEndAddress(baseAddr)
{
}

ProgramBinary::~ProgramBinary()
{
}

void ProgramBinary::emitByte(File* file, int line, quint8 byte)
{
    mCode.emplace_back(byte);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
}

void ProgramBinary::emitWord(File* file, int line, quint16 word)
{
    mCode.emplace_back(quint8(word & 0xFF));
    mCode.emplace_back(quint8((word >> 8) & 0xFF));
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
}

void ProgramBinary::emitDWord(File* file, int line, quint32 dword)
{
    mCode.emplace_back(quint8(dword & 0xFF));
    mCode.emplace_back(quint8((dword >> 8) & 0xFF));
    mCode.emplace_back(quint8((dword >> 16) & 0xFF));
    mCode.emplace_back(quint8((dword >> 24) & 0xFF));
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
}

void ProgramBinary::emitQWord(File* file, int line, quint64 qword)
{
    mCode.emplace_back(quint8(qword & 0xFF));
    mCode.emplace_back(quint8((qword >> 8) & 0xFF));
    mCode.emplace_back(quint8((qword >> 16) & 0xFF));
    mCode.emplace_back(quint8((qword >> 24) & 0xFF));
    mCode.emplace_back(quint8((qword >> 32) & 0xFF));
    mCode.emplace_back(quint8((qword >> 40) & 0xFF));
    mCode.emplace_back(quint8((qword >> 48) & 0xFF));
    mCode.emplace_back(quint8((qword >> 56) & 0xFF));
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
    mDebugInfo->setSourceLocation(mEndAddress++, file, line);
}
