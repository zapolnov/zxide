#include "ProgramLabel.h"

ProgramLabel::ProgramLabel(const Token& token, std::string name)
    : ProgramOpcode(token)
    , mName(std::move(name))
    , mAddress(0)
    , mHasAddress(false)
{
}

ProgramLabel::~ProgramLabel()
{
}

unsigned ProgramLabel::lengthInBytes(const Program*, IErrorReporter*) const
{
    return 0;
}

unsigned ProgramLabel::tstatesIfNotTaken(const Program*, IErrorReporter*) const
{
    return 0;
}

unsigned ProgramLabel::tstatesIfTaken(const Program*, IErrorReporter*) const
{
    return 0;
}

void ProgramLabel::resolveAddress(quint32& address, Program*, IErrorReporter*)
{
    Q_ASSERT(!mHasAddress);
    mHasAddress = true;
    mAddress = unsigned(address);
}

void ProgramLabel::emitBinary(Program*, ProgramBinary*, IErrorReporter*) const
{
}
