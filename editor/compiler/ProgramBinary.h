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

    const unsigned char* codeBytes() const { return mCode.data(); }
    size_t codeLength() const { return mCode.size(); }

    void emitByte(unsigned char byte);

private:
    std::vector<unsigned char> mCode;
    unsigned mBaseAddress;
    unsigned mEndAddress;

    Q_DISABLE_COPY(ProgramBinary)
};

#endif
