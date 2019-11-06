#include "Compressor.h"
#include "compiler/ProgramDebugInfo.h"
#include "compiler/Compiler.h"

extern "C" {
#include <zx7.h>
}

Compressor::Compressor(ProgramBinary* binary)
    : mBinary(binary)
    , mEndAddress(binary->endAddress())
{
}

Compressor::~Compressor()
{
}

unsigned Compressor::endAddress() const
{
    return mEndAddress;
}

ProgramSection* Compressor::currentSection() const
{
    return mBinary->currentSection();
}

ProgramDebugInfo* Compressor::debugInfo() const
{
    return mBinary->debugInfo();
}

void Compressor::emitByte(const SourceFile* file, int line, quint8 byte)
{
    auto currentFile = mBinary->mCurrentFile;
    QString fileName = (file ? file->name : QString());
    mUncompressedData.emplace_back(byte);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
}

void Compressor::emitWord(const SourceFile* file, int line, quint16 word)
{
    auto currentFile = mBinary->mCurrentFile;
    QString fileName = (file ? file->name : QString());
    mUncompressedData.emplace_back(quint8(word & 0xFF));
    mUncompressedData.emplace_back(quint8((word >> 8) & 0xFF));
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
}

void Compressor::emitDWord(const SourceFile* file, int line, quint32 dword)
{
    auto currentFile = mBinary->mCurrentFile;
    QString fileName = (file ? file->name : QString());
    mUncompressedData.emplace_back(quint8(dword & 0xFF));
    mUncompressedData.emplace_back(quint8((dword >> 8) & 0xFF));
    mUncompressedData.emplace_back(quint8((dword >> 16) & 0xFF));
    mUncompressedData.emplace_back(quint8((dword >> 24) & 0xFF));
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
}

void Compressor::emitQWord(const SourceFile* file, int line, quint64 qword)
{
    auto currentFile = mBinary->mCurrentFile;
    QString fileName = (file ? file->name : QString());
    mUncompressedData.emplace_back(quint8(qword & 0xFF));
    mUncompressedData.emplace_back(quint8((qword >> 8) & 0xFF));
    mUncompressedData.emplace_back(quint8((qword >> 16) & 0xFF));
    mUncompressedData.emplace_back(quint8((qword >> 24) & 0xFF));
    mUncompressedData.emplace_back(quint8((qword >> 32) & 0xFF));
    mUncompressedData.emplace_back(quint8((qword >> 40) & 0xFF));
    mUncompressedData.emplace_back(quint8((qword >> 48) & 0xFF));
    mUncompressedData.emplace_back(quint8((qword >> 56) & 0xFF));
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
    currentFile->second.debugInfo->setSourceLocation(mEndAddress++, fileName, line);
}

size_t Compressor::flush()
{
    auto& code = mBinary->mCurrentFile->second.code;
    size_t oldSize = code.size();
    compress(std::move(mUncompressedData), code);
    mUncompressedData.clear();
    size_t newSize = code.size();
    mBinary->mCurrentFile->second.endAddress += unsigned(newSize - oldSize);
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
