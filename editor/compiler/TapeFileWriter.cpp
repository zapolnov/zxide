#include "TapeFileWriter.h"
#include "BasicProgram.h"
#include "ProgramBinary.h"
#include "IErrorReporter.h"
#include "compiler/Util.h"
#include <QCoreApplication>
#include <sstream>
#include <algorithm>

extern "C" {
#include <libspectrum.h>
}

#ifdef max
#undef max
#endif

namespace
{
    class TapeFileWriterException
    {
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class LibSpectrum
    {
    public:
        explicit LibSpectrum(IErrorReporter* reporter)
        {
            Q_ASSERT(mReporter == nullptr);
            mReporter = reporter;

            libspectrum_error_function = errorFn;
            if (libspectrum_init() == LIBSPECTRUM_ERROR_NONE)
                mInitialized = true;
            else {
                reporter->error(nullptr, 0, QCoreApplication::tr("Unable to initialize libspectrum"));
                throw TapeFileWriterException();
            }
        }

        ~LibSpectrum()
        {
            if (mInitialized)
                libspectrum_end();

            libspectrum_error_function = libspectrum_default_error_function;
            mReporter = nullptr;
        }

    private:
        static IErrorReporter* mReporter;
        bool mInitialized;

        static libspectrum_error errorFn(libspectrum_error, const char* fmt, va_list args)
        {
            char buf[2048];
            vsnprintf(buf, sizeof(buf), fmt, args);
            mReporter->error(nullptr, 0, QCoreApplication::tr("libspectrum: %1").arg(QString::fromUtf8(buf)));
            return LIBSPECTRUM_ERROR_NONE;
        }

        Q_DISABLE_COPY(LibSpectrum)
    };

    IErrorReporter* LibSpectrum::mReporter;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class LibSpectrumTapeBlock
    {
    public:
        explicit LibSpectrumTapeBlock(libspectrum_tape_type type)
        {
            mBlock = libspectrum_tape_block_alloc(type);
            if (!mBlock)
                throw TapeFileWriterException();
        }

        ~LibSpectrumTapeBlock()
        {
            if (mBlock)
                libspectrum_tape_block_free(mBlock);
        }

        void setDataWithChecksum(const void* data, size_t length, quint8 flag = 0)
        {
            auto error = libspectrum_tape_block_set_data_length(mBlock, length + 2);
            if (error != LIBSPECTRUM_ERROR_NONE)
                throw TapeFileWriterException();

            libspectrum_byte* dst = libspectrum_new(libspectrum_byte, length + 2);
            if (!dst)
                throw TapeFileWriterException();

            error = libspectrum_tape_block_set_data(mBlock, dst);
            if (error != LIBSPECTRUM_ERROR_NONE) {
                libspectrum_free(dst);
                throw TapeFileWriterException();
            }

            const char* src = reinterpret_cast<const char*>(data);
            const char* end = src + length;

            *dst++ = flag;
            libspectrum_byte checksum = flag;
            while (src < end) {
                libspectrum_byte byte = *src++;
                *dst++ = byte;
                checksum ^= byte;
            }
            *dst++ = checksum;
        }

        operator libspectrum_tape_block*() const { return mBlock; }

    private:
        libspectrum_tape_block* mBlock;

        Q_DISABLE_COPY(LibSpectrumTapeBlock)
        friend class LibSpectrumTape;
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class LibSpectrumBuffer
    {
    public:
        LibSpectrumBuffer() : mBuffer(nullptr) {}
        ~LibSpectrumBuffer() { if (mBuffer) libspectrum_free(mBuffer); }

        operator libspectrum_byte**() { return &mBuffer; }
        const char* constData() const { return reinterpret_cast<const char*>(mBuffer); }

    private:
        libspectrum_byte* mBuffer;

        Q_DISABLE_COPY(LibSpectrumBuffer)
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class LibSpectrumTape
    {
    public:
        LibSpectrumTape()
        {
            mTape = libspectrum_tape_alloc();
            if (!mTape)
                throw TapeFileWriterException();
        }

        ~LibSpectrumTape()
        {
            if (mTape)
                libspectrum_tape_free(mTape);
        }

        void appendBlock(LibSpectrumTapeBlock& block)
        {
            libspectrum_tape_append_block(mTape, block);
            block.mBlock = nullptr;
        }

        void appendBlock(const void* data, size_t length, quint8 flag = 0)
        {
            LibSpectrumTapeBlock block(LIBSPECTRUM_TAPE_BLOCK_ROM);
            block.setDataWithChecksum(data, length, flag);
            appendBlock(block);
        }

        void appendBlock(const std::string& data, quint8 flag = 0)
        {
            appendBlock(data.data(), data.length(), flag);
        }

        void write(LibSpectrumBuffer& buffer, size_t* length, libspectrum_id_t type)
        {
            auto error = libspectrum_tape_write(buffer, length, mTape, type);
            if (error != LIBSPECTRUM_ERROR_NONE)
                throw TapeFileWriterException();
        }

        void writeFile(libspectrum_id_t type, const QString& file, IErrorReporter* reporter)
        {
            size_t length = 0;
            LibSpectrumBuffer buffer;
            write(buffer, &length, type);
            if (!::writeFile(file, buffer.constData(), length, reporter))
                throw TapeFileWriterException();
        }

        operator libspectrum_tape*() const { return mTape; }

    private:
        libspectrum_tape* mTape;

        Q_DISABLE_COPY(LibSpectrumTape)
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TapeProgramHeader
    {
    public:
        explicit TapeProgramHeader()
            : mInMemorySize(0)
            , mOnTapeSize(0)
            , mAutoStartLine(32768) // no autostart
        {
        }

        void setName(std::string name)
        {
            Q_ASSERT(name.length() <= 10);
            mName = std::move(name);
        }

        void setSize(size_t size)
        {
            Q_ASSERT(size < 0x10000);
            mOnTapeSize = size;
        }

        void setInMemorySize(size_t size)
        {
            Q_ASSERT(size < 0x10000);
            mInMemorySize = size;
        }

        void setAutoStartLine(int line)
        {
            Q_ASSERT(line >= 0 && line <= 9999);
            mAutoStartLine = line;
        }

        std::string toBinary() const
        {
            std::stringstream ss;
            ss << '\x00'; // type: BASIC program

            size_t n = mName.length();
            for (size_t i = 0; i < 10; i++)
                ss << (i < n ? mName[i] : ' ');

            size_t inMemorySize = std::max(mOnTapeSize, mInMemorySize);
            ss << static_cast<char>(inMemorySize & 0xFF);
            ss << static_cast<char>((inMemorySize >> 8) & 0xFF);

            ss << static_cast<char>(mAutoStartLine & 0xFF);
            ss << static_cast<char>((mAutoStartLine >> 8) & 0xFF);
            ss << static_cast<char>(mOnTapeSize & 0xFF);
            ss << static_cast<char>((mOnTapeSize >> 8) & 0xFF);

            return ss.str();
        }

    private:
        std::string mName;
        size_t mInMemorySize;
        size_t mOnTapeSize;
        int mAutoStartLine;

        Q_DISABLE_COPY(TapeProgramHeader)
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TapeCodeHeader
    {
    public:
        explicit TapeCodeHeader()
            : mSize(0)
            , mStartAddress(0)
        {
        }

        void setName(std::string name)
        {
            Q_ASSERT(name.length() <= 10);
            mName = std::move(name);
        }

        void setSize(size_t size)
        {
            Q_ASSERT(size < 0x10000);
            mSize = size;
        }

        void setStartAddress(size_t size)
        {
            Q_ASSERT(size < 0x10000);
            mStartAddress = size;
        }

        std::string toBinary() const
        {
            std::stringstream ss;
            ss << '\x03'; // type: code

            size_t n = mName.length();
            for (size_t i = 0; i < 10; i++)
                ss << (i < n ? mName[i] : ' ');

            ss << static_cast<char>(mSize & 0xFF);
            ss << static_cast<char>((mSize >> 8) & 0xFF);
            ss << static_cast<char>(mStartAddress & 0xFF);
            ss << static_cast<char>((mStartAddress >> 8) & 0xFF);
            ss << '\x00';
            ss << '\x80';

            return ss.str();
        }

    private:
        std::string mName;
        size_t mSize;
        size_t mStartAddress;

        Q_DISABLE_COPY(TapeCodeHeader)
    };
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TapeFileWriter::TapeFileWriter(ProgramBinary* program, IErrorReporter* reporter)
    : mProgram(program)
    , mReporter(reporter)
{
}

TapeFileWriter::~TapeFileWriter()
{
}

bool TapeFileWriter::writeTapeFile(const QString& file)
{
    try {
        LibSpectrum libSpectrum(mReporter);
        LibSpectrumTape tape;

        BasicProgram loader;
        loader.line(10).CLEAR(mProgram->baseAddress() - 1);
        loader.line(20).POKE(23610, 255); // Avoid error message on +3
        loader.line(30).LOAD("").CODE();
        loader.line(40).RANDOMIZE().USR(mProgram->baseAddress());
        std::string loaderData = loader.toBinary();

        TapeProgramHeader loaderHeader;
        loaderHeader.setName("LOADER");
        loaderHeader.setSize(loaderData.length());
        loaderHeader.setAutoStartLine(10);

        TapeCodeHeader programHeader;
        programHeader.setName("PROGRAM");
        programHeader.setSize(mProgram->codeLength());
        programHeader.setStartAddress(mProgram->baseAddress());

        tape.appendBlock(loaderHeader.toBinary(), 0);
        tape.appendBlock(loaderData, 255);
        tape.appendBlock(programHeader.toBinary(), 0);
        tape.appendBlock(mProgram->codeBytes(), mProgram->codeLength(), 255);

        tape.writeFile(LIBSPECTRUM_ID_TAPE_TAP, file, mReporter);
    } catch (const TapeFileWriterException&) {
        return false;
    }

    return true;
}
