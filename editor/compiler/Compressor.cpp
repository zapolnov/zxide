#include "Compressor.h"
#include "compiler/ProgramDebugInfo.h"
#include "compiler/Compiler.h"

extern "C" {
#include <zx7.h>
}

Compressor::Compressor(IProgramBinary* binary)
    : mBinary(binary)
    , mEndAddress(binary->endAddress())
{
}

Compressor::~Compressor()
{
}

std::vector<quint8>& Compressor::code()
{
    return mUncompressedCode;
}

unsigned Compressor::endAddress() const
{
    return mEndAddress;
}

void Compressor::setEndAddress(unsigned address)
{
    mEndAddress = address;
}

void Compressor::setAddressForName(const QString& name, unsigned address)
{
    mBinary->setAddressForName(name, address);
}

void Compressor::setSourceLocation(unsigned addr, const QString& fileName, int line)
{
    mBinary->setSourceLocation(addr, fileName, line);
}

void Compressor::setTStatesForLocation(const SourceFile* file, int line, unsigned taken, unsigned notTaken)
{
    mBinary->setTStatesForLocation(file, line, taken, notTaken);
}

void Compressor::emitByte(const SourceFile* file, int line, quint8 byte)
{
    QString fileName = (file ? file->name : QString());
    mUncompressedCode.emplace_back(byte);
    setSourceLocation(mEndAddress++, fileName, line);
}

void Compressor::emitWord(const SourceFile* file, int line, quint16 word)
{
    QString fileName = (file ? file->name : QString());
    mUncompressedCode.emplace_back(quint8(word & 0xFF));
    mUncompressedCode.emplace_back(quint8((word >> 8) & 0xFF));
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
}

void Compressor::emitDWord(const SourceFile* file, int line, quint32 dword)
{
    QString fileName = (file ? file->name : QString());
    mUncompressedCode.emplace_back(quint8(dword & 0xFF));
    mUncompressedCode.emplace_back(quint8((dword >> 8) & 0xFF));
    mUncompressedCode.emplace_back(quint8((dword >> 16) & 0xFF));
    mUncompressedCode.emplace_back(quint8((dword >> 24) & 0xFF));
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
}

void Compressor::emitQWord(const SourceFile* file, int line, quint64 qword)
{
    QString fileName = (file ? file->name : QString());
    mUncompressedCode.emplace_back(quint8(qword & 0xFF));
    mUncompressedCode.emplace_back(quint8((qword >> 8) & 0xFF));
    mUncompressedCode.emplace_back(quint8((qword >> 16) & 0xFF));
    mUncompressedCode.emplace_back(quint8((qword >> 24) & 0xFF));
    mUncompressedCode.emplace_back(quint8((qword >> 32) & 0xFF));
    mUncompressedCode.emplace_back(quint8((qword >> 40) & 0xFF));
    mUncompressedCode.emplace_back(quint8((qword >> 48) & 0xFF));
    mUncompressedCode.emplace_back(quint8((qword >> 56) & 0xFF));
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
    setSourceLocation(mEndAddress++, fileName, line);
}

size_t Compressor::flush()
{
    auto& code = mBinary->code();
    size_t oldSize = code.size();
    compress(std::move(mUncompressedCode), code);
    mUncompressedCode.clear();
    size_t newSize = code.size();
    mBinary->setEndAddress(mBinary->endAddress() + unsigned(newSize - oldSize));
    return newSize - oldSize;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Zx7Compressor::compress(std::vector<quint8> src, std::vector<quint8>& dst)
{
    Optimal* optimal = nullptr;
    unsigned char* compressed = nullptr;
    size_t compressedSize = 0;

    if (src.empty())
        return;

    try {
        optimal = zx7_optimize(src.data(), src.size());
        if (!optimal)
            throw std::bad_alloc();

        compressed = zx7_compress(optimal, src.data(), src.size(), &compressedSize);
        if (!compressed)
            throw std::bad_alloc();

        dst.reserve(dst.size() + compressedSize);
        dst.insert(dst.end(), compressed, compressed + compressedSize);
    } catch (...) {
        if (compressed)
            free(compressed);
        if (optimal)
            free(optimal);
        throw;
    }

    free(compressed);
    free(optimal);
}
