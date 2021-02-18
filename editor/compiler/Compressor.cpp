#include "Compressor.h"
#include "compiler/ProgramDebugInfo.h"
#include "compiler/Compiler.h"
#include <stdexcept>

extern "C" {
#include <zx7.h>
#include <lib.h>
#include <shrink_streaming.h>
#include <shrink_context.h>
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
    if (address < 0x10000)
        mBinary->setAddressForName(name, address);
}

void Compressor::setSourceLocation(unsigned addr, const QString& fileName, int line)
{
    //mBinary->setSourceLocation(addr, fileName, line);
}

void Compressor::setTStatesForLocation(const SourceFile* file, int line, unsigned taken, unsigned notTaken)
{
    //mBinary->setTStatesForLocation(file, line, taken, notTaken);
}

void Compressor::addWriteProtection(ProgramWriteProtection protection)
{
    // FIXME
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

void UncompressedCompressor::compress(std::vector<quint8> src, std::vector<quint8>& dst)
{
    dst.insert(dst.end(), src.begin(), src.end());
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace
{
    struct LZSAStream : public lzsa_stream_t
    {
        std::vector<quint8>& data;
        size_t readPos;

        explicit LZSAStream(std::vector<quint8>& v)
            : data(v)
            , readPos(0)
        {
            read = lzsaRead;
            write = lzsaWrite;
            eof = lzsaEof;
            close = lzsaClose;
        }

        static size_t lzsaRead(lzsa_stream_t *stream, void *ptr, size_t size)
        {
            auto s = reinterpret_cast<LZSAStream*>(stream);

            size_t bytesAvailable = s->data.size() - s->readPos;
            if (size > bytesAvailable)
                size = bytesAvailable;

            memcpy(ptr, s->data.data() + s->readPos, size);
            s->readPos += size;

            return size;
        }

        static size_t lzsaWrite(lzsa_stream_t *stream, void *ptr, size_t size)
        {
            auto s = reinterpret_cast<LZSAStream*>(stream);
            s->data.insert(s->data.end(), reinterpret_cast<quint8*>(ptr), reinterpret_cast<quint8*>(ptr) + size);
            return size;
        }

        static int lzsaEof(lzsa_stream_t *stream)
        {
            auto s = reinterpret_cast<LZSAStream*>(stream);
            return s->readPos >= s->data.size();
        }

        static void lzsaClose(lzsa_stream_t* stream)
        {
        }
    };
}

void LzsaCompressor::compress(std::vector<quint8> src, std::vector<quint8>& dst)
{
    if (src.empty())
        return;

    LZSAStream streamIn(src);
    LZSAStream streamOut(dst);

    long long originalSize = 0, compressedSize = 0;
    int commandCount = 0, safeDist = 0;
    lzsa_stats stats;

    int flags = LZSA_FLAG_FAVOR_RATIO | LZSA_FLAG_RAW_BLOCK;
    int version = 2;
    lzsa_status_t status = lzsa_compress_stream(&streamIn, &streamOut, nullptr, 0,
        flags, 0, version, nullptr, &originalSize, &compressedSize, &commandCount, &safeDist, &stats);

    switch (status) {
        case LZSA_OK: break;
        case LZSA_ERROR_SRC: throw std::runtime_error("lzsa: error reading input.");
        case LZSA_ERROR_DST: throw std::runtime_error("lzsa: error writing output.");
        case LZSA_ERROR_DICTIONARY: throw std::runtime_error("lzsa: error reading dictionary.");
        case LZSA_ERROR_MEMORY: throw std::runtime_error("lzsa: out of memory.");
        case LZSA_ERROR_COMPRESSION: throw std::runtime_error("lzsa: internal compression error.");
        case LZSA_ERROR_RAW_TOOLARGE: throw std::runtime_error("lzsa: raw blocks can only be used with files <= 64 Kb.");
        case LZSA_ERROR_RAW_UNCOMPRESSED: throw std::runtime_error("lzsa: incompressible data needs to be <= 64 Kb in raw blocks.");
        default: throw std::runtime_error("lzsa: unknown compression error."); break;
    }
}
