#ifndef COMPILER_PROGRAMOPCODE_H
#define COMPILER_PROGRAMOPCODE_H

#include <QtGlobal>
#include <vector>

#ifdef emit
#undef emit
#endif

struct Token;
class File;
class IErrorReporter;
class ProgramBinary;
class ProgramSection;

class ProgramOpcode
{
public:
    explicit ProgramOpcode(const Token& token);
    virtual ~ProgramOpcode();

    File* file() const { return mFile; }
    int line() const { return mLine; }

    virtual unsigned lengthInBytes() const = 0;
    virtual unsigned tstatesIfNotTaken() const = 0;
    virtual unsigned tstatesIfTaken() const = 0;

    virtual void resolveAddress(const ProgramSection* section, quint32& address);
    virtual void emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const = 0;

private:
    File* mFile;
    int mLine;

    Q_DISABLE_COPY(ProgramOpcode)
};

#endif
