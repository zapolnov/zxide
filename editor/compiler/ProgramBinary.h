#ifndef COMPILER_PROGRAMBINARY_H
#define COMPILER_PROGRAMBINARY_H

#include <QtGlobal>
#include <map>
#include <memory>
#include <string>
#include <vector>

struct SourceFile;
class ProgramDebugInfo;
class ProgramSection;

class IProgramBinary
{
public:
    virtual ~IProgramBinary() = default;
    virtual unsigned endAddress() const = 0;
    virtual ProgramSection* currentSection() const = 0;
    virtual ProgramDebugInfo* debugInfo() const = 0;
    virtual void emitByte(const SourceFile* file, int line, quint8 byte) = 0;;
    virtual void emitWord(const SourceFile* file, int line, quint16 word) = 0;
    virtual void emitDWord(const SourceFile* file, int line, quint32 dword) = 0;
    virtual void emitQWord(const SourceFile* file, int line, quint64 qword) = 0;
};

class ProgramBinary final : public IProgramBinary
{
public:
    struct File
    {
        std::vector<quint8> code;
        std::unique_ptr<ProgramDebugInfo> debugInfo;
        unsigned baseAddress;
        unsigned endAddress;
    };

    using FileMap = std::map<std::string, File>;

    ProgramBinary();
    ~ProgramBinary() override;

    unsigned baseAddress() const { return mCurrentFile->second.baseAddress; }
    unsigned endAddress() const override { return mCurrentFile->second.endAddress; }

    ProgramSection* currentSection() const override { return mCurrentSection; }
    void setCurrentSection(ProgramSection* section) { mCurrentSection = section; }

    const std::string& currentFile() const { return mCurrentFile->first; }
    void setCurrentFile(const std::string& fileName);
    void setCurrentFile(const std::string& fileName, unsigned baseAddress);

    const quint8* codeBytes() const { return mCurrentFile->second.code.data(); }
    size_t codeLength() const { return mCurrentFile->second.code.size(); }

    ProgramDebugInfo* debugInfo() const override { return mCurrentFile->second.debugInfo.get(); }

    const FileMap& files() const { return mFiles; }

    void emitByte(const SourceFile* file, int line, quint8 byte) override;
    void emitWord(const SourceFile* file, int line, quint16 word) override;
    void emitDWord(const SourceFile* file, int line, quint32 dword) override;
    void emitQWord(const SourceFile* file, int line, quint64 qword) override;

private:
    FileMap mFiles;
    FileMap::iterator mCurrentFile;
    ProgramSection* mCurrentSection;

    FileMap::iterator createFile(std::string fileName, unsigned baseAddress);

    Q_DISABLE_COPY(ProgramBinary)
    friend class Compressor;
};

#endif
