#ifndef COMPILER_COMPRESSOR_H
#define COMPILER_COMPRESSOR_H

#include "compiler/ProgramBinary.h"

class Compressor : public IProgramBinary
{
public:
    explicit Compressor(IProgramBinary* binary);
    ~Compressor() override;

    std::vector<quint8>& code() final override;
    unsigned endAddress() const final override;
    void setEndAddress(unsigned address) final override;
    void setAddressForName(const QString& name, unsigned address) final override;
    void setSourceLocation(unsigned addr, const QString& fileName, int line) final override;
    void setTStatesForLocation(const SourceFile* file, int line, unsigned taken, unsigned notTaken) final override;
    void emitByte(const SourceFile* file, int line, quint8 byte) final override;
    void emitWord(const SourceFile* file, int line, quint16 word) final override;
    void emitDWord(const SourceFile* file, int line, quint32 dword) final override;
    void emitQWord(const SourceFile* file, int line, quint64 qword) final override;

    size_t flush();

protected:
    virtual void compress(std::vector<quint8> src, std::vector<quint8>& dst) = 0;

private:
    IProgramBinary* mBinary;
    std::vector<quint8> mUncompressedCode;
    unsigned mEndAddress;

    Q_DISABLE_COPY(Compressor)
};

class Zx7Compressor final : public Compressor
{
public:
    explicit Zx7Compressor(IProgramBinary* binary) : Compressor(binary) {}
    ~Zx7Compressor() override = default;

protected:
    void compress(std::vector<quint8> src, std::vector<quint8>& dst) override;

    Q_DISABLE_COPY(Zx7Compressor)
};

#endif
