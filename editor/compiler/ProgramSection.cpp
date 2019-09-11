#include "ProgramSection.h"
#include "ProgramOpcode.h"
#include "ProgramBinary.h"
#include "IErrorReporter.h"
#include <QCoreApplication>

ProgramSection::ProgramSection(Program* program, const Token& token, std::string name)
    : mProgram(program)
    , mToken(token)
    , mName(std::move(name))
    , mBase(0)
    , mAlignment(1)
    , mHasBase(false)
    , mHasAlignment(false)
    , mHasFileName(false)
{
}

ProgramSection::~ProgramSection()
{
}

unsigned ProgramSection::baseRelativeTo(unsigned address) const
{
    if (mHasBase)
        return mBase;
    else if (mHasAlignment && mAlignment > 1)
        return (address + mAlignment - 1) / mAlignment * mAlignment;
    else
        return address;
}

bool ProgramSection::resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const
{
    address = baseRelativeTo(address);

    if (mHasBank && address < BankBaseAddress) {
        reporter->error(mToken.file, mToken.line,
            QCoreApplication::tr("section '%1' has invalid base address 0x%2").arg(nameCStr()).arg(address, 0, 16));
        return false;
    }

    if (!isEmpty() && address > 0xFFFF) {
        reporter->error(mToken.file, mToken.line,
            QCoreApplication::tr("section '%1' overflows 64K barrier").arg(nameCStr()));
        return false;
    }

    return CodeEmitter::resolveAddresses(reporter, program, address);
}

void ProgramSection::emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    if (mHasBank)
        Q_ASSERT(binary->endAddress() >= BankBaseAddress);

    if (hasCode(program, reporter)) {
        if (mHasBase) {
            if (mBase < binary->endAddress()) {
                reporter->error(mToken.file, mToken.line,
                    QCoreApplication::tr("section '%1' overlaps with address 0x%2 which belongs to another section")
                    .arg(nameCStr()).arg(mBase, 0, 16));
            }
            while (binary->endAddress() < mBase)
                binary->emitByte(nullptr, 0, 0); // NOP
        } else if (mHasAlignment && mAlignment > 1) {
            quint64 alignedAddress = (binary->endAddress() + mAlignment - 1) / mAlignment * mAlignment;
            while (binary->endAddress() < alignedAddress)
                binary->emitByte(nullptr, 0, 0); // NOP
        }
    }

    CodeEmitter::emitCode(program, binary, reporter);
}
