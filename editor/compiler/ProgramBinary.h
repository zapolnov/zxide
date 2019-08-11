#ifndef COMPILER_PROGRAMBINARY_H
#define COMPILER_PROGRAMBINARY_H

#include <QtGlobal>
#include <vector>

class ProgramBinary
{
public:
    explicit ProgramBinary(unsigned baseAddr);
    ~ProgramBinary();

    unsigned baseAddress() const { return mBaseAddress; }
    unsigned endAddress() const { return mEndAddress; }

    const quint8* codeBytes() const { return mCode.data(); }
    size_t codeLength() const { return mCode.size(); }

    void emitByte(quint8 byte);
    void emitWord(quint16 word);
    void emitDWord(quint32 dword);
    void emitQWord(quint64 qword);

private:
    std::vector<quint8> mCode;
    unsigned mBaseAddress;
    unsigned mEndAddress;

    Q_DISABLE_COPY(ProgramBinary)
};

#endif
