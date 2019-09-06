#include "ProgramBinary.h"
#include "compiler/ProgramDebugInfo.h"
#include "compiler/ProgramSection.h"

ProgramBinary::ProgramBinary(unsigned baseAddr)
    : mCurrentBank(-1)
{
    createBank(-1, baseAddr);
}

ProgramBinary::~ProgramBinary()
{
}

void ProgramBinary::setCurrentBank(int bank)
{
    auto it = mBanks.find(bank);
    if (it == mBanks.end())
        it = createBank(bank, ProgramSection::BankBaseAddress);
    mCurrentBank = bank;
}

void ProgramBinary::setCurrentBank(int bank, unsigned baseAddress)
{
    auto it = mBanks.find(bank);
    if (it == mBanks.end())
        createBank(bank, baseAddress);
    mCurrentBank = bank;
}

void ProgramBinary::emitByte(File* file, int line, quint8 byte)
{
    Bank& b = bank();
    b.code.emplace_back(byte);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
}

void ProgramBinary::emitWord(File* file, int line, quint16 word)
{
    Bank& b = bank();
    b.code.emplace_back(quint8(word & 0xFF));
    b.code.emplace_back(quint8((word >> 8) & 0xFF));
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
}

void ProgramBinary::emitDWord(File* file, int line, quint32 dword)
{
    Bank& b = bank();
    b.code.emplace_back(quint8(dword & 0xFF));
    b.code.emplace_back(quint8((dword >> 8) & 0xFF));
    b.code.emplace_back(quint8((dword >> 16) & 0xFF));
    b.code.emplace_back(quint8((dword >> 24) & 0xFF));
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
}

void ProgramBinary::emitQWord(File* file, int line, quint64 qword)
{
    Bank& b = bank();
    b.code.emplace_back(quint8(qword & 0xFF));
    b.code.emplace_back(quint8((qword >> 8) & 0xFF));
    b.code.emplace_back(quint8((qword >> 16) & 0xFF));
    b.code.emplace_back(quint8((qword >> 24) & 0xFF));
    b.code.emplace_back(quint8((qword >> 32) & 0xFF));
    b.code.emplace_back(quint8((qword >> 40) & 0xFF));
    b.code.emplace_back(quint8((qword >> 48) & 0xFF));
    b.code.emplace_back(quint8((qword >> 56) & 0xFF));
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
    b.debugInfo->setSourceLocation(b.endAddress++, file, line);
}

const ProgramBinary::Bank& ProgramBinary::bank() const
{
    auto it = mBanks.find(mCurrentBank);
    Q_ASSERT(it != mBanks.end());
    return it->second;
}

ProgramBinary::Bank& ProgramBinary::bank()
{
    auto it = mBanks.find(mCurrentBank);
    Q_ASSERT(it != mBanks.end());
    return it->second;
}

std::map<int, ProgramBinary::Bank>::iterator ProgramBinary::createBank(int bank, unsigned baseAddress)
{
    Bank b;
    b.debugInfo = std::make_unique<ProgramDebugInfo>();
    b.baseAddress = baseAddress;
    b.endAddress = baseAddress;
    return mBanks.emplace(bank, std::move(b)).first;
}
