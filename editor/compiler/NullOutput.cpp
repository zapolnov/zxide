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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ImaginaryOutput::ImaginaryOutput(IProgramBinary* binary)
    : mBinary(binary)
    , mEndAddress(binary->endAddress())
{
}

ImaginaryOutput::~ImaginaryOutput()
{
}

std::vector<quint8>& ImaginaryOutput::code()
{
    return mCode;
}

unsigned ImaginaryOutput::endAddress() const
{
    return mEndAddress;
}

void ImaginaryOutput::setEndAddress(unsigned addr)
{
    mEndAddress = addr;
}

void ImaginaryOutput::setAddressForName(const QString& name, unsigned address)
{
    mBinary->setAddressForName(name, address);
}

void ImaginaryOutput::setSourceLocation(unsigned addr, const QString& fileName, int line)
{
    mBinary->setSourceLocation(addr, fileName, line);
}

void ImaginaryOutput::setTStatesForLocation(const SourceFile* file, int line, unsigned taken, unsigned notTaken)
{
    mBinary->setTStatesForLocation(file, line, taken, notTaken);
}

void ImaginaryOutput::emitByte(const SourceFile* file, int line, quint8)
{
    QString fileName = (file ? file->name : QString());
    setSourceLocation(mEndAddress++, fileName, line);
}

void ImaginaryOutput::emitWord(const SourceFile* file, int line, quint16)
{
    QString fileName = (file ? file->name : QString());
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
}

void ImaginaryOutput::emitDWord(const SourceFile* file, int line, quint32)
{
    QString fileName = (file ? file->name : QString());
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
}

void ImaginaryOutput::emitQWord(const SourceFile* file, int line, quint64)
{
    QString fileName = (file ? file->name : QString());
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
}
