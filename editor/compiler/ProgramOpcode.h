#ifndef COMPILER_PROGRAMOPCODE_H
#define COMPILER_PROGRAMOPCODE_H

#include "AssemblerToken.h"
#include <vector>

#ifdef emit
#undef emit
#endif

class File;
class IErrorReporter;
class ProgramBinary;
class ProgramSection;
class Program;

class ProgramOpcode
{
public:
    explicit ProgramOpcode(const Token& token);
    virtual ~ProgramOpcode();

    const Token& token() const { return mToken; }
    unsigned address() const { Q_ASSERT(mAddress >= 0); return unsigned(mAddress); }

    virtual unsigned lengthInBytes() const = 0;
    virtual unsigned tstatesIfNotTaken() const = 0;
    virtual unsigned tstatesIfTaken() const = 0;

    virtual void resolveAddress(const ProgramSection* section, quint32& address);
    virtual void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const = 0;

private:
    Token mToken;
    qint32 mAddress;

    Q_DISABLE_COPY(ProgramOpcode)
};

#endif
