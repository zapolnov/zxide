#ifndef COMPILER_PROGRAMBINARY_H
#define COMPILER_PROGRAMBINARY_H

#include <QtGlobal>
#include <map>
#include <memory>
#include <string>
#include <vector>

struct SourceFile;
class ProgramDebugInfo;

class ProgramBinary
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
    ~ProgramBinary();

    unsigned baseAddress() const { return mCurrentFile->second.baseAddress; }
    unsigned endAddress() const { return mCurrentFile->second.endAddress; }

    const std::string& currentFile() const { return mCurrentFile->first; }
    void setCurrentFile(const std::string& fileName);
    void setCurrentFile(const std::string& fileName, unsigned baseAddress);

    const quint8* codeBytes() const { return mCurrentFile->second.code.data(); }
    size_t codeLength() const { return mCurrentFile->second.code.size(); }

    ProgramDebugInfo* debugInfo() const { return mCurrentFile->second.debugInfo.get(); }

    const FileMap& files() const { return mFiles; }

    void emitByte(const SourceFile* file, int line, quint8 byte);
    void emitWord(const SourceFile* file, int line, quint16 word);
    void emitDWord(const SourceFile* file, int line, quint32 dword);
    void emitQWord(const SourceFile* file, int line, quint64 qword);

private:
    FileMap mFiles;
    FileMap::iterator mCurrentFile;

    FileMap::iterator createFile(std::string fileName, unsigned baseAddress);

    Q_DISABLE_COPY(ProgramBinary)
};

#endif
