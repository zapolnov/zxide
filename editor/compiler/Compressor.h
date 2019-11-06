#ifndef COMPILER_COMPRESSOR_H
#define COMPILER_COMPRESSOR_H

#include "compiler/ProgramBinary.h"

class Compressor : public IProgramBinary
{
public:
    explicit Compressor(ProgramBinary* binary);
    ~Compressor() override;

    unsigned endAddress() const override;
    ProgramSection* currentSection() const override;
    ProgramDebugInfo* debugInfo() const override;
    void emitByte(const SourceFile* file, int line, quint8 byte) override;;
    void emitWord(const SourceFile* file, int line, quint16 word) override;
    void emitDWord(const SourceFile* file, int line, quint32 dword) override;
    void emitQWord(const SourceFile* file, int line, quint64 qword) override;

    size_t flush();

protected:
    virtual void compress(std::vector<quint8> src, std::vector<quint8>& dst) = 0;

private:
    ProgramBinary* mBinary;
    std::vector<quint8> mUncompressedData;
    unsigned mEndAddress;

    Q_DISABLE_COPY(Compressor)
};

class Zx7Compressor final : public Compressor
{
public:
    explicit Zx7Compressor(ProgramBinary* binary) : Compressor(binary) {}
    ~Zx7Compressor() override = default;

protected:
    void compress(std::vector<quint8> src, std::vector<quint8>& dst) override;

    Q_DISABLE_COPY(Zx7Compressor)
};

#endif
