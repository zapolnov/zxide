#ifndef COMPILER_NULLOUTPUT_H
#define COMPILER_NULLOUTPUT_H

#include "compiler/ProgramBinary.h"

class NullOutput final : public IProgramBinary
{
public:
    explicit NullOutput(unsigned addr);
    ~NullOutput() override;

    std::vector<quint8>& code() override;
    unsigned endAddress() const override;
    void setEndAddress(unsigned addr) override;
    void setAddressForName(const QString& name, unsigned address) override;
    void setSourceLocation(unsigned addr, const QString& fileName, int line) override;
    void setTStatesForLocation(const SourceFile* file, int line, unsigned taken, unsigned notTaken) override;
    void emitByte(const SourceFile* file, int line, quint8 byte) override;;
    void emitWord(const SourceFile* file, int line, quint16 word) override;
    void emitDWord(const SourceFile* file, int line, quint32 dword) override;
    void emitQWord(const SourceFile* file, int line, quint64 qword) override;

private:
    unsigned mEndAddress;
    std::vector<quint8> mCode;

    Q_DISABLE_COPY(NullOutput)
};

#endif
