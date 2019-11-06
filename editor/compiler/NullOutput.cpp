#include "NullOutput.h"
#include "compiler/Compiler.h"

NullOutput::NullOutput(unsigned addr)
    : mEndAddress(addr)
{
}

NullOutput::~NullOutput()
{
}

std::vector<quint8>& NullOutput::code()
{
    return mCode;
}

unsigned NullOutput::endAddress() const
{
    return mEndAddress;
}

void NullOutput::setEndAddress(unsigned addr)
{
    mEndAddress = addr;
}

void NullOutput::setAddressForName(const QString&, unsigned)
{
}

void NullOutput::setSourceLocation(unsigned, const QString&, int)
{
}

void NullOutput::setTStatesForLocation(const SourceFile*, int, unsigned, unsigned)
{
}

void NullOutput::emitByte(const SourceFile*, int, quint8)
{
    ++mEndAddress;
}

void NullOutput::emitWord(const SourceFile*, int, quint16)
{
    ++mEndAddress;
    ++mEndAddress;
}

void NullOutput::emitDWord(const SourceFile*, int, quint32)
{
    ++mEndAddress;
    ++mEndAddress;
    ++mEndAddress;
    ++mEndAddress;
}

void NullOutput::emitQWord(const SourceFile*, int, quint64)
{
    ++mEndAddress;
    ++mEndAddress;
    ++mEndAddress;
    ++mEndAddress;
    ++mEndAddress;
    ++mEndAddress;
    ++mEndAddress;
    ++mEndAddress;
}
