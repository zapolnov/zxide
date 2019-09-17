#include "ProgramOpcode.h"
#include "Compiler.h"
#include "AssemblerToken.h"
#include "Expression.h"
#include "ExprEvalContext.h"
#include "CodeEmitter.h"
#include "ProgramBinary.h"
#include "IErrorReporter.h"
#include <QCoreApplication>

ProgramOpcode::ProgramOpcode(const Token& token)
    : mToken(token)
{
}

ProgramOpcode::~ProgramOpcode()
{
}

bool ProgramOpcode::resolveAddress(quint32& address, Program* program, IErrorReporter* reporter)
{
    if (address > 0xFFFF) {
        QString fileName = (token().file ? token().file->name : QString());
        reporter->error(fileName, token().line, QCoreApplication::tr("address is over 64K"));
        return false;
    }

    address += lengthInBytes(program, reporter);
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DEFB::DEFB(const Token& token, std::unique_ptr<Expression> value)
    : ProgramOpcode(token)
    , mValue(std::move(value))
{
}

DEFB::~DEFB()
{
}

void DEFB::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context(program, reporter, binary->endAddress(), this);
    binary->emitByte(token().file, token().line, context.evaluateByte(mValue));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DEFB_STRING::DEFB_STRING(const Token& token, std::string text)
    : ProgramOpcode(token)
    , mText(std::move(text))
{
}

DEFB_STRING::~DEFB_STRING()
{
}

void DEFB_STRING::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    for (auto ch : mText)
        binary->emitByte(token().file, token().line, ch);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DEFB_BYTEARRAY::DEFB_BYTEARRAY(const Token& token, const QByteArray& data)
    : ProgramOpcode(token)
    , mData(data)
{
}

DEFB_BYTEARRAY::~DEFB_BYTEARRAY()
{
}

void DEFB_BYTEARRAY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    for (auto ch : mData)
        binary->emitByte(token().file, token().line, ch);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DEFW::DEFW(const Token& token, std::unique_ptr<Expression> value)
    : ProgramOpcode(token)
    , mValue(std::move(value))
{
}

DEFW::~DEFW()
{
}

void DEFW::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context(program, reporter, binary->endAddress(), this);
    binary->emitWord(token().file, token().line, context.evaluateWord(mValue));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DEFD::DEFD(const Token& token, std::unique_ptr<Expression> value)
    : ProgramOpcode(token)
    , mValue(std::move(value))
{
}

DEFD::~DEFD()
{
}

void DEFD::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context(program, reporter, binary->endAddress(), this);
    binary->emitDWord(token().file, token().line, context.evaluateDWord(mValue));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IfMacro::IfMacro(const Token& token, std::unique_ptr<Expression> condition,
        std::shared_ptr<CodeEmitter> thenCodeEmitter, std::shared_ptr<CodeEmitter> elseCodeEmitter)
    : ProgramOpcode(token)
    , mThenCodeEmitter(std::move(thenCodeEmitter))
    , mElseCodeEmitter(std::move(elseCodeEmitter))
    , mCondition(std::move(condition))
{
}

IfMacro::~IfMacro()
{
}

unsigned IfMacro::lengthInBytes(const Program* program, IErrorReporter* reporter) const
{
    return codeEmitter(program, reporter)->totalLengthInBytes(program, reporter);
}

unsigned IfMacro::tstatesIfNotTaken(const Program* program, IErrorReporter* reporter) const
{
    return codeEmitter(program, reporter)->totalTStatesIfNotTaken(program, reporter);
}

unsigned IfMacro::tstatesIfTaken(const Program* program, IErrorReporter* reporter) const
{
    return codeEmitter(program, reporter)->totalTStatesIfTaken(program, reporter);
}

bool IfMacro::resolveAddress(quint32& address, Program* program, IErrorReporter* reporter)
{
    return codeEmitter(program, reporter)->resolveAddresses(reporter, program, address);
}

void IfMacro::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    codeEmitter(program, reporter)->emitCode(program, binary, reporter);
}

CodeEmitter* IfMacro::codeEmitter(const Program* program, IErrorReporter* reporter) const
{
    ExprEvalContext context(program, reporter);
    return context.evaluate(mCondition).number ? mThenCodeEmitter.get() : mElseCodeEmitter.get();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RepeatMacro::RepeatMacro(const Token& token, std::shared_ptr<RepeatedCodeEmitter> codeEmitter)
    : ProgramOpcode(token)
    , mCodeEmitter(std::move(codeEmitter))
{
}

RepeatMacro::~RepeatMacro()
{
}

unsigned RepeatMacro::lengthInBytes(const Program* program, IErrorReporter* reporter) const
{
    return mCodeEmitter->totalLengthInBytes(program, reporter);
}

unsigned RepeatMacro::tstatesIfNotTaken(const Program* program, IErrorReporter* reporter) const
{
    return mCodeEmitter->totalTStatesIfNotTaken(program, reporter);
}

unsigned RepeatMacro::tstatesIfTaken(const Program* program, IErrorReporter* reporter) const
{
    return mCodeEmitter->totalTStatesIfTaken(program, reporter);
}

bool RepeatMacro::resolveAddress(quint32& address, Program* program, IErrorReporter* reporter)
{
    return mCodeEmitter->resolveAddresses(reporter, program, address);
}

void RepeatMacro::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    mCodeEmitter->emitCode(program, binary, reporter);
}
