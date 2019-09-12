#include "ExprEvalContext.h"
#include "Compiler.h"
#include "ProgramOpcode.h"
#include "AssemblerToken.h"
#include "IErrorReporter.h"
#include "Expression.h"
#include <QCoreApplication>

ExprEvalContext::ExprEvalContext(const Program* program, IErrorReporter* reporter)
    : mProgram(program)
    , mErrorReporter(reporter)
    , mBaseAddress(-1)
    , mNextAddress(-1)
{
}

ExprEvalContext::ExprEvalContext(
        const Program* program, IErrorReporter* reporter, unsigned address, const ProgramOpcode* opcode)
    : mProgram(program)
    , mErrorReporter(reporter)
    , mBaseAddress(qint32(address))
    , mNextAddress(mBaseAddress + qint32(opcode->lengthInBytes(program, reporter)))
{
}

ExprEvalContext::~ExprEvalContext()
{
}

unsigned ExprEvalContext::baseAddress(const Token& token) const
{
    if (mBaseAddress < 0) {
        QString fileName = (token.file ? token.file->name : QString());
        mErrorReporter->error(fileName, token.line,
            QCoreApplication::tr("instruction address is not available in this context"));
        throw EvalError();
    }

    return unsigned(mBaseAddress);
}

unsigned ExprEvalContext::nextAddress(const Token& token) const
{
    if (mNextAddress < 0) {
        QString fileName = (token.file ? token.file->name : QString());
        mErrorReporter->error(fileName, token.line,
            QCoreApplication::tr("instruction address is not available in this context"));
        throw EvalError();
    }

    return unsigned(mNextAddress);
}


quint8 ExprEvalContext::evaluateByte(const std::unique_ptr<Expression>& expr)
{
    Value value = evaluate(expr);

    if (value.bits == SignificantBits::NoMoreThan8)
        value.truncateTo8Bit();
    else if (value.number < -128 || value.number > 255) {
        auto token = expr->token();
        QString fileName = (token.file ? token.file->name : QString());
        mErrorReporter->error(fileName, token.line,
            QCoreApplication::tr("value %1 (0x%2) does not fit into a byte")
            .arg(value.number).arg(value.number, 0, 16));
        throw EvalError();
    }

    if (value.number >= 0 || value.sign == Sign::Unsigned)
        return (quint8)value.number;
    else
        return (quint8)(qint8)value.number;
}

quint8 ExprEvalContext::evaluateByteOffset(const std::unique_ptr<Expression>& expr)
{
    Value value = evaluate(expr);
    if (value.bits != SignificantBits::All)
        value.truncateTo16Bit();

    qint64 offset = value.number - nextAddress(expr->token());
    if (offset < -128 || offset > 127) {
        auto token = expr->token();
        QString fileName = (token.file ? token.file->name : QString());
        mErrorReporter->error(fileName, token.line,
            QCoreApplication::tr("value %1 (0x%2) does not fit into a byte").arg(offset).arg(offset, 0, 16));
        throw EvalError();
    }

    if (offset >= 0 || value.sign == Sign::Unsigned)
        return (quint8)offset;
    else
        return (quint8)(qint8)offset;
}

quint16 ExprEvalContext::evaluateWord(const std::unique_ptr<Expression>& expr)
{
    Value value = evaluate(expr);

    if (value.bits == SignificantBits::NoMoreThan8 || value.bits == SignificantBits::NoMoreThan16)
        value.truncateTo16Bit();
    else if (value.number < -32768 || value.number > 65535) {
        auto token = expr->token();
        QString fileName = (token.file ? token.file->name : QString());
        mErrorReporter->error(fileName, token.line,
            QCoreApplication::tr("value %1 (0x%2) does not fit into a word")
            .arg(value.number).arg(value.number, 0, 16));
        throw EvalError();
    }

    if (value.number >= 0 || value.sign == Sign::Unsigned)
        return (quint16)value.number;
    else
        return (quint16)(qint16)value.number;
}

quint32 ExprEvalContext::evaluateDWord(const std::unique_ptr<Expression>& expr)
{
    Value value = evaluate(expr);

    if (value.bits == SignificantBits::NoMoreThan8 || value.bits == SignificantBits::NoMoreThan16)
        value.truncateTo32Bit();
    else if (value.number < -qint64(0x80000000) || value.number > 0xffffffff) {
        auto token = expr->token();
        QString fileName = (token.file ? token.file->name : QString());
        mErrorReporter->error(fileName, token.line,
            QCoreApplication::tr("value %1 (0x%2) does not fit into a dword")
            .arg(value.number).arg(value.number, 0, 16));
        throw EvalError();
    }

    if (value.number >= 0 || value.sign == Sign::Unsigned)
        return (quint32)value.number;
    else
        return (quint32)(qint32)value.number;
}

Value ExprEvalContext::evaluate(const std::unique_ptr<Expression>& expr)
{
    if (!mEvaluating.emplace(expr.get()).second) {
        auto token = expr->token();
        QString fileName = (token.file ? token.file->name : QString());
        mErrorReporter->error(fileName, token.line,
            QCoreApplication::tr("hit circular dependency while evaluating expression"));
        throw EvalError();
    }

    Value value;
    try {
        value = expr->evaluate(*this);
    } catch (...) {
        mEvaluating.erase(expr.get());
        throw;
    }

    mEvaluating.erase(expr.get());

    return value;
}
