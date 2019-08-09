#ifndef COMPILER_PROGRAMLABEL_H
#define COMPILER_PROGRAMLABEL_H

#include "ProgramOpcode.h"
#include <string>

class ProgramBinary;
class ProgramSection;

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

    void resolveAddress(quint32& address) override;
    void emitBinary(ProgramBinary* bin) const override;

private:
    ProgramSection* mSection;
    std::string mName;
    unsigned mAddress;
    bool mHasAddress;

    Q_DISABLE_COPY(ProgramLabel)
};

#endif
