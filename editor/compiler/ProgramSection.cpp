#include "ProgramSection.h"
#include "ProgramOpcode.h"
#include "ProgramBinary.h"
#include "IErrorReporter.h"
#include <QApplication>

ProgramSection::ProgramSection(std::string name)
    : mName(std::move(name))
    , mBase(0)
    , mAlignment(1)
    , mHasBase(false)
    , mHasAlignment(false)
{
}

ProgramSection::~ProgramSection()
{
}

bool ProgramSection::resolveAddresses(IErrorReporter* reporter, quint32& address) const
{
    if (mHasBase)
        address = mBase;
    else if (mHasAlignment && mAlignment > 1)
        address = (address + mAlignment - 1) / mAlignment * mAlignment;

    if (address > 0xFFFF) {
        reporter->error(nullptr, 0, QApplication::tr("section '%1' overflows 64K barrier").arg(nameCStr()));
        return false;
    }

    for (auto& opcode : mOpcodes) {
        quint32 old = address;
        opcode->resolveAddress(address);
        Q_ASSERT(address == old + opcode->lengthInBytes());
        if (address > 0xFFFF) {
            reporter->error(opcode->file(), opcode->line(), QApplication::tr("address is over 64K"));
            return false;
        }
    }

    return true;
}

void ProgramSection::emitCode(ProgramBinary* binary) const
{
    if (mHasBase) {
        while (binary->endAddress() < mBase)
            binary->emitByte(0); // NOP
    } else if (mHasAlignment && mAlignment > 1) {
        quint64 alignedAddress = (binary->endAddress() + mAlignment - 1) / mAlignment * mAlignment;
        while (binary->endAddress() < alignedAddress)
            binary->emitByte(0); // NOP
    }

    for (auto& opcode : mOpcodes) {
        unsigned old = binary->endAddress();
        opcode->emitBinary(binary);
        Q_ASSERT(binary->endAddress() == old + opcode->lengthInBytes());
    }
}
