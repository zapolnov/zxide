#include "CodeEmitter.h"
#include "ProgramOpcode.h"
#include "ProgramBinary.h"
#include "Value.h"
#include "Expression.h"
#include "ExprEvalContext.h"
#include "IErrorReporter.h"
#include <limits>
#include <QCoreApplication>

CodeEmitter::CodeEmitter()
{
}

CodeEmitter::~CodeEmitter()
{
}

unsigned CodeEmitter::totalLengthInBytes(const Program* program, IErrorReporter* reporter) const
{
    unsigned n = 0;
    for (const auto& opcode : mOpcodes)
        n += opcode->lengthInBytes(program, reporter);
    return n;
}

unsigned CodeEmitter::totalTStatesIfNotTaken(const Program* program, IErrorReporter* reporter) const
{
    unsigned n = 0;
    for (const auto& opcode : mOpcodes)
        n += opcode->tstatesIfNotTaken(program, reporter);
    return n;
}

unsigned CodeEmitter::totalTStatesIfTaken(const Program* program, IErrorReporter* reporter) const
{
    unsigned n = 0;
    for (const auto& opcode : mOpcodes)
        n += opcode->tstatesIfTaken(program, reporter);
    return n;
}

bool CodeEmitter::resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const
{
    for (const auto& opcode : mOpcodes) {
        quint32 old = address;
        if (!opcode->resolveAddress(address, program, reporter))
            return false;

        Q_ASSERT(address == old + opcode->lengthInBytes(program, reporter));
        if (address > 0x10000) {
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
        Q_ASSERT(binary->endAddress() == old + opcode->lengthInBytes(program, reporter));
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RepeatedCodeEmitter::RepeatedCodeEmitter(std::unique_ptr<Expression> repeatCount)
    : mCounter(std::make_shared<Value>(0, Sign::Unsigned))
    , mRepeatCount(std::move(repeatCount))
{
}

RepeatedCodeEmitter::~RepeatedCodeEmitter()
{
}

unsigned RepeatedCodeEmitter::totalLengthInBytes(const Program* program, IErrorReporter* reporter) const
{
    qint64 count = 0;
    evaluateRepeatCount(program, reporter, count);

    qint64 total = 0;
    for (qint64 i = 0; i < count; i++) {
        *mCounter = Value(i, Sign::Unsigned);
        total += CodeEmitter::totalLengthInBytes(program, reporter);
    }

    return unsigned(std::min<qint64>(total, std::numeric_limits<unsigned>::max()));
}

unsigned RepeatedCodeEmitter::totalTStatesIfNotTaken(const Program* program, IErrorReporter* reporter) const
{
    qint64 count = 0;
    evaluateRepeatCount(program, reporter, count);

    qint64 total = 0;
    for (qint64 i = 0; i < count; i++) {
        *mCounter = Value(i, Sign::Unsigned);
        total += CodeEmitter::totalTStatesIfNotTaken(program, reporter);
    }

    return unsigned(std::min<qint64>(total, std::numeric_limits<unsigned>::max()));
}

unsigned RepeatedCodeEmitter::totalTStatesIfTaken(const Program* program, IErrorReporter* reporter) const
{
    qint64 count = 0;
    evaluateRepeatCount(program, reporter, count);

    qint64 total = 0;
    for (qint64 i = 0; i < count; i++) {
        *mCounter = Value(i, Sign::Unsigned);
        total += CodeEmitter::totalTStatesIfTaken(program, reporter);
    }

    return unsigned(std::min<qint64>(total, std::numeric_limits<unsigned>::max()));
}

bool RepeatedCodeEmitter::resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const
{
    qint64 count = 0;
    if (!evaluateRepeatCount(program, reporter, count))
        return false;

    for (qint64 i = 0; i < count; i++) {
        *mCounter = Value(i, Sign::Unsigned);
        if (!CodeEmitter::resolveAddresses(reporter, program, address))
            return false;
    }

    return true;
}

void RepeatedCodeEmitter::emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    qint64 count = 0;
    evaluateRepeatCount(program, reporter, count);

    for (qint64 i = 0; i < count; i++) {
        *mCounter = Value(i, Sign::Unsigned);
        CodeEmitter::emitCode(program, binary, reporter);
    }
}

bool RepeatedCodeEmitter::evaluateRepeatCount(const Program* program, IErrorReporter* reporter, qint64& value) const
{
    ExprEvalContext context(program, reporter);
    value = context.evaluate(mRepeatCount).number;
    if (value < 0 || value > 0xffff) {
        const auto& token = mRepeatCount->token();
        reporter->error(token.file, token.line, QCoreApplication::tr("invalid repeat count"));
        return false;
    }

    return true;
}
