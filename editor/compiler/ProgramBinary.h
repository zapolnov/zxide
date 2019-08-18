#ifndef COMPILER_PROGRAMBINARY_H
#define COMPILER_PROGRAMBINARY_H

#include <QtGlobal>
#include <memory>
#include <vector>

class File;
class ProgramDebugInfo;

class ProgramBinary
{
public:
    explicit ProgramBinary(unsigned baseAddr);
    ~ProgramBinary();

    unsigned baseAddress() const { return mBaseAddress; }
    unsigned endAddress() const { return mEndAddress; }

    const quint8* codeBytes() const { return mCode.data(); }
    size_t codeLength() const { return mCode.size(); }

    ProgramDebugInfo* debugInfo() const { return mDebugInfo.get(); }

    void emitByte(File* file, int line, quint8 byte);
    void emitWord(File* file, int line, quint16 word);
    void emitDWord(File* file, int line, quint32 dword);
    void emitQWord(File* file, int line, quint64 qword);

private:
    std::vector<quint8> mCode;
    std::unique_ptr<ProgramDebugInfo> mDebugInfo;
    unsigned mBaseAddress;
    unsigned mEndAddress;

    Q_DISABLE_COPY(ProgramBinary)
};

#endif
