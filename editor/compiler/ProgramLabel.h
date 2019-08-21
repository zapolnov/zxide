#ifndef COMPILER_PROGRAMLABEL_H
#define COMPILER_PROGRAMLABEL_H

#include "ProgramOpcode.h"
#include <string>

class ProgramBinary;
class Program;

class ProgramLabel : public ProgramOpcode
{
public:
    ProgramLabel(const Token& token, std::string name);
    ~ProgramLabel() override;

    const std::string& name() const { return mName; }

    bool hasAddress() const { return mHasAddress; }
    unsigned address() const { Q_ASSERT(mHasAddress); return mAddress; }

    unsigned lengthInBytes() const override;
    unsigned tstatesIfNotTaken() const override;
    unsigned tstatesIfTaken() const override;

    void resolveAddress(quint32& address, IErrorReporter* reporter) override;
    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    std::string mName;
    unsigned mAddress;
    bool mHasAddress;

    Q_DISABLE_COPY(ProgramLabel)
};

#endif
