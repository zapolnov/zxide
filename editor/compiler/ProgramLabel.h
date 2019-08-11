#ifndef COMPILER_PROGRAMLABEL_H
#define COMPILER_PROGRAMLABEL_H

#include "ProgramOpcode.h"
#include <string>

class ProgramBinary;
class ProgramSection;
class Program;

class ProgramLabel : public ProgramOpcode
{
public:
    ProgramLabel(const Token& token, ProgramSection* section, std::string name);
    ~ProgramLabel() override;

    ProgramSection* section() const { return mSection; }
    const std::string& name() const { return mName; }

    bool hasAddress() const { return mHasAddress; }
    unsigned address() const { Q_ASSERT(mHasAddress); return mAddress; }

    unsigned lengthInBytes() const override;
    unsigned tstatesIfNotTaken() const override;
    unsigned tstatesIfTaken() const override;

    void resolveAddress(const ProgramSection* section, quint32& address) override;
    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    ProgramSection* mSection;
    std::string mName;
    unsigned mAddress;
    bool mHasAddress;

    Q_DISABLE_COPY(ProgramLabel)
};

#endif
