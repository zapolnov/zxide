#include "ProgramOpcode.h"
#include "AssemblerToken.h"
#include "Expression.h"
#include "ExprEvalContext.h"
#include "CodeEmitter.h"
#include "ProgramBinary.h"

ProgramOpcode::ProgramOpcode(const Token& token)
    : mToken(token)
    , mAddress(-1)
{
}

ProgramOpcode::~ProgramOpcode()
{
}

void ProgramOpcode::resolveAddress(quint32& address, Program* program, IErrorReporter* reporter)
{
    setAddress(address);
    address += lengthInBytes(program, reporter);
}

void ProgramOpcode::setAddress(quint32 address)
{
    mAddress = qint32(address);
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
    ExprEvalContext context(program, reporter, this);
    binary->emitByte(mToken.file, mToken.line, context.evaluateByte(mValue));
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
        binary->emitByte(mToken.file, mToken.line, ch);
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
    ExprEvalContext context(program, reporter, this);
    binary->emitWord(mToken.file, mToken.line, context.evaluateWord(mValue));
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
    ExprEvalContext context(program, reporter, this);
    binary->emitDWord(mToken.file, mToken.line, context.evaluateDWord(mValue));
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

void RepeatMacro::resolveAddress(quint32& address, Program* program, IErrorReporter* reporter)
{
    mCodeEmitter->resolveAddresses(reporter, program, address);
}

void RepeatMacro::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    mCodeEmitter->emitCode(program, binary, reporter);
}
