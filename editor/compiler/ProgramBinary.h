#ifndef COMPILER_PROGRAMBINARY_H
#define COMPILER_PROGRAMBINARY_H

#include <QtGlobal>
#include <map>
#include <memory>
#include <vector>

class File;
class ProgramDebugInfo;

class ProgramBinary
{
public:
    explicit ProgramBinary(unsigned baseAddr);
    ~ProgramBinary();

    unsigned baseAddress() const { return bank().baseAddress; }
    unsigned endAddress() const { return bank().endAddress; }

    int currentBank() const { return mCurrentBank; }
    void setCurrentBank(int bank);
    void setCurrentBank(int bank, unsigned baseAddress);
    bool hasBank(int bank) { return bank == -1 || mBanks.find(bank) != mBanks.end(); }

    const quint8* codeBytes() const { return bank().code.data(); }
    size_t codeLength() const { return bank().code.size(); }

    ProgramDebugInfo* debugInfo() const { return bank().debugInfo.get(); }

    void emitByte(File* file, int line, quint8 byte);
    void emitWord(File* file, int line, quint16 word);
    void emitDWord(File* file, int line, quint32 dword);
    void emitQWord(File* file, int line, quint64 qword);

private:
    struct Bank
    {
        std::vector<quint8> code;
        std::unique_ptr<ProgramDebugInfo> debugInfo;
        unsigned baseAddress;
        unsigned endAddress;
    };

    std::map<int, Bank> mBanks;
    int mCurrentBank;

    const Bank& bank() const;
    Bank& bank();
    std::map<int, Bank>::iterator createBank(int bank, unsigned baseAddress);

    Q_DISABLE_COPY(ProgramBinary)
};

#endif
