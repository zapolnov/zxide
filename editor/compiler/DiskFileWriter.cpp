#include "DiskFileWriter.h"
#include "compiler/ProjectSettings.h"
#include "compiler/ProgramBinary.h"
#include "compiler/ProgramSection.h"
#include "compiler/IO.h"
#include <QDataStream>
#include <algorithm>

#ifdef max
#undef max
#endif

// FIXME: duplicate of one in TapeFileWriter
static bool endsWith(const std::string& str, const std::string& end)
{
    if (str.length() < end.length())
        return false;
    return memcmp(str.data() + str.length() - end.length(), end.data(), end.length()) == 0;
}

namespace
{
    #define SECTOR_SIZE 256

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class DiskFile
    {
    public:
        explicit DiskFile(quint8 type)
            : mType(type)
        {
        }

        virtual ~DiskFile()
        {
        }

        DiskFile& setName(std::string name)
        {
            mName = std::move(name);
            if (mName.length() < 8)
                mName.resize(8, ' ');
            return *this;
        }

        size_t dataSize() const
        {
            return mData.size();
        }

        size_t sizeInSectors() const
        {
            return (dataSize() + SECTOR_SIZE - 1) / SECTOR_SIZE;
        }

        DiskFile& appendByte(quint8 data)
        {
            mData.insert(mData.end(), &data, &data + 1);
            return *this;
        }

        DiskFile& appendData(const void* ptr, size_t size)
        {
            const char* p = reinterpret_cast<const char*>(ptr);
            mData.insert(mData.end(), p, p + size);
            return *this;
        }

        DiskFile& appendString(const std::string& str)
        {
            mData.insert(mData.end(), str.begin(), str.end());
            return *this;
        }

        DiskFile& appendByteArray(const QByteArray& arr)
        {
            mData.insert(mData.end(), arr.begin(), arr.end());
            return *this;
        }

        virtual void finalizeData()
        {
        }

        void writeHeader(QDataStream& stream) const
        {
            stream.writeRawData(mName.data(), 8);
            stream << mType;
            writeParams(stream);
            stream << quint8(sizeInSectors());
        }

        void writeData(QDataStream& stream)
        {
            mData.resize(sizeInSectors() * SECTOR_SIZE);
            stream.writeRawData(mData.data(), int(mData.size()));
        }

    protected:
        virtual void writeParams(QDataStream& stream) const = 0;

    private:
        std::string mName;
        quint8 mType;
        std::vector<char> mData;

        Q_DISABLE_COPY(DiskFile)
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class BasicFile : public DiskFile
    {
    public:
        BasicFile()
            : DiskFile(0x42) // 'B'
            , mInMemorySize(0)
            , mAutoStartLine(32768) // no autostart
        {
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

        void finalizeData() override
        {
            appendByte(quint8(128));
            appendByte(quint8(170));
            appendByte(quint8(qint16(mAutoStartLine) & 0xff));
            appendByte(quint8(qint16(mAutoStartLine) >> 8));
            DiskFile::finalizeData();
        }

    protected:
        void writeParams(QDataStream& stream) const override
        {
            stream << quint16(std::max(dataSize(), mInMemorySize));
            stream << quint16(dataSize());
        }

    private:
        size_t mInMemorySize;
        int mAutoStartLine;

        Q_DISABLE_COPY(BasicFile)
    };

    class CodeFile : public DiskFile
    {
    public:
        CodeFile()
            : DiskFile(0x43) // 'C'
            , mStartAddress(0)
        {
        }

        void setStartAddress(unsigned size)
        {
            mStartAddress = size;
        }

    protected:
        void writeParams(QDataStream& stream) const override
        {
            stream << (quint16)mStartAddress;
            stream << (quint16)dataSize();
        }

    private:
        unsigned mStartAddress;

        Q_DISABLE_COPY(CodeFile)
    };
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DiskFileWriter::DiskFileWriter(ProgramBinary* program, IErrorReporter* reporter)
    : mProgram(program)
    , mReporter(reporter)
    , mLoaderName(ProjectSettings::DefaultLoaderFileName)
    , mProgramName(ProjectSettings::DefaultProgramFileName)
    , mDontOutputMainFile(false)
    , mBasicStartLine(-1)
{
}

DiskFileWriter::~DiskFileWriter()
{
}

bool DiskFileWriter::writeSclFile(const QString& fileName)
{
    std::vector<std::unique_ptr<DiskFile>> files;

    if (!mBasicCode.isEmpty()) {
        auto basicFile = std::make_unique<BasicFile>();
        basicFile->setName(mLoaderName);
        if (mBasicStartLine >= 0)
            basicFile->setAutoStartLine(mBasicStartLine);
        basicFile->appendByteArray(mBasicCode);
        basicFile->finalizeData();
        files.emplace_back(std::move(basicFile));
    }

    for (const auto& it : mProgram->files()) {
        mProgram->setCurrentFile(it.first);
        if (mProgram->codeLength() == 0)
            continue;
        if (mDontOutputMainFile && it.first.empty())
            continue;
        if (it.first == "LOADER" || endsWith(it.first, ":imaginary"))
            continue;

        auto codeFile = std::make_unique<CodeFile>();
        codeFile->setName(it.first.empty() ? mProgramName : it.first);
        codeFile->setStartAddress(mProgram->baseAddress());
        codeFile->appendData(mProgram->codeBytes(), mProgram->codeLength());
        codeFile->finalizeData();
        files.emplace_back(std::move(codeFile));
    }

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream.writeRawData("SINCLAIR", 8);
    stream << (quint8)(mProgram->files().size() + 1);
    for (const auto& file : files)
        file->writeHeader(stream);
    for (const auto& file : files)
        file->writeData(stream);

    return writeFile(fileName, data.constData(), size_t(data.size()), mReporter);
}
