#include "ExprEvalContext.h"
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

ExprEvalContext::ExprEvalContext(const Program* program, IErrorReporter* reporter, const ProgramOpcode* opcode)
    : mProgram(program)
    , mErrorReporter(reporter)
    , mBaseAddress(qint32(opcode->address()))
    , mNextAddress(mBaseAddress + qint32(opcode->lengthInBytes()))
{
}

ExprEvalContext::~ExprEvalContext()
{
}

unsigned ExprEvalContext::baseAddress(const Token& token) const
{
    if (mBaseAddress < 0) {
        mErrorReporter->error(token.file, token.line,
            QCoreApplication::tr("instruction address is not available in this context"));
        throw EvalError();
    }

    return unsigned(mBaseAddress);
}

unsigned ExprEvalContext::nextAddress(const Token& token) const
{
    if (mNextAddress < 0) {
        mErrorReporter->error(token.file, token.line,
            QCoreApplication::tr("instruction address is not available in this context"));
        throw EvalError();
    }

    return unsigned(mNextAddress);
}


unsigned char ExprEvalContext::evaluateByte(const std::unique_ptr<Expression>& expr)
{
    Value value = evaluate(expr);

    if (value.bits == SignificantBits::NoMoreThan8)
        value.truncateTo8Bit();
    else if (value.number < -128 || value.number > 255) {
        auto token = expr->token();
        mErrorReporter->error(token.file, token.line,
            QCoreApplication::tr("value %1 (0x%2) does not fit into a byte")
            .arg(value.number).arg(value.number, 0, 16));
        throw EvalError();
    }

    if (value.number >= 0 || value.sign == Sign::Unsigned)
        return (unsigned char)value.number;
    else
        return (unsigned char)(char)value.number;
}

unsigned char ExprEvalContext::evaluateByteOffset(const std::unique_ptr<Expression>& expr)
{
    Value value = evaluate(expr);
    if (value.bits != SignificantBits::All)
        value.truncateTo16Bit();

    qint64 offset = value.number - nextAddress(expr->token());
    if (offset < -128 || offset > 255) {
        auto token = expr->token();
        mErrorReporter->error(token.file, token.line,
            QCoreApplication::tr("value %1 (0x%2) does not fit into a byte").arg(offset).arg(offset, 0, 16));
        throw EvalError();
    }

    if (offset >= 0 || value.sign == Sign::Unsigned)
        return (unsigned char)offset;
    else
        return (unsigned char)(char)offset;
}

unsigned short ExprEvalContext::evaluateWord(const std::unique_ptr<Expression>& expr)
{
    Value value = evaluate(expr);

    if (value.bits == SignificantBits::NoMoreThan8 || value.bits == SignificantBits::NoMoreThan16)
        value.truncateTo16Bit();
    else if (value.number < -32768 || value.number > 65535) {
        auto token = expr->token();
        mErrorReporter->error(token.file, token.line,
            QCoreApplication::tr("value %1 (0x%2) does not fit into a word")
            .arg(value.number).arg(value.number, 0, 16));
        throw EvalError();
    }

    if (value.number >= 0 || value.sign == Sign::Unsigned)
        return (unsigned short)value.number;
    else
        return (unsigned short)(short)value.number;
}

Value ExprEvalContext::evaluate(const std::unique_ptr<Expression>& expr)
{
    if (!mEvaluating.emplace(expr.get()).second) {
        auto token = expr->token();
        mErrorReporter->error(token.file, token.line,
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
