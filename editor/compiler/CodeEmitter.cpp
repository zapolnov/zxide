#include "CodeEmitter.h"
#include "ProgramOpcode.h"
#include "ProgramBinary.h"
#include "Value.h"
#include "IErrorReporter.h"
#include <limits>
#include <QCoreApplication>

CodeEmitter::CodeEmitter()
{
}

CodeEmitter::~CodeEmitter()
{
}

unsigned CodeEmitter::totalLengthInBytes() const
{
    unsigned n = 0;
    for (const auto& opcode : mOpcodes)
        n += opcode->lengthInBytes();
    return n;
}

unsigned CodeEmitter::totalTStatesIfNotTaken() const
{
    unsigned n = 0;
    for (const auto& opcode : mOpcodes)
        n += opcode->tstatesIfNotTaken();
    return n;
}

unsigned CodeEmitter::totalTStatesIfTaken() const
{
    unsigned n = 0;
    for (const auto& opcode : mOpcodes)
        n += opcode->tstatesIfTaken();
    return n;
}

bool CodeEmitter::resolveAddresses(IErrorReporter* reporter, quint32& address) const
{
    for (const auto& opcode : mOpcodes) {
        quint32 old = address;
        opcode->resolveAddress(address, reporter);
        Q_ASSERT(address == old + opcode->lengthInBytes());
        if (address > 0xFFFF) {
            reporter->error(opcode->token().file, opcode->token().line, QCoreApplication::tr("address is over 64K"));
            return false;
        }
    }

    return true;
}

void CodeEmitter::emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    for (const auto& opcode : mOpcodes) {
        unsigned old = binary->endAddress();
        opcode->emitBinary(program, binary, reporter);
        Q_ASSERT(binary->endAddress() == old + opcode->lengthInBytes());
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RepeatedCodeEmitter::RepeatedCodeEmitter(qint64 repeatCount)
    : mRepeatCount(repeatCount)
    , mCounter(std::make_shared<Value>(0, Sign::Unsigned))
{
}

RepeatedCodeEmitter::~RepeatedCodeEmitter()
{
}

unsigned RepeatedCodeEmitter::totalLengthInBytes() const
{
    qint64 n = CodeEmitter::totalLengthInBytes();
    return unsigned(std::min<qint64>(n * mRepeatCount, std::numeric_limits<unsigned>::max()));
}

unsigned RepeatedCodeEmitter::totalTStatesIfNotTaken() const
{
    qint64 n = CodeEmitter::totalTStatesIfNotTaken();
    return unsigned(std::min<qint64>(n * mRepeatCount, std::numeric_limits<unsigned>::max()));
}

unsigned RepeatedCodeEmitter::totalTStatesIfTaken() const
{
    qint64 n = CodeEmitter::totalTStatesIfTaken();
    return unsigned(std::min<qint64>(n * mRepeatCount, std::numeric_limits<unsigned>::max()));
}

bool RepeatedCodeEmitter::resolveAddresses(IErrorReporter* reporter, quint32& address) const
{
    for (qint64 i = 0; i < mRepeatCount; i++) {
        *mCounter = Value(i, Sign::Unsigned);
        if (!CodeEmitter::resolveAddresses(reporter, address))
            return false;
    }
    return true;
}

void RepeatedCodeEmitter::emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    for (qint64 i = 0; i < mRepeatCount; i++) {
        *mCounter = Value(i, Sign::Unsigned);
        CodeEmitter::emitCode(program, binary, reporter);
    }
}
