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
    qint64 value = evaluate(expr);

    if (value < -128 || value > 255) {
        auto token = expr->token();
        mErrorReporter->error(token.file, token.line,
            QCoreApplication::tr("value %1 does not fit into a byte").arg(value));
        throw EvalError();
    }

    if (value >= 0)
        return (unsigned char)value;
    else
        return (unsigned char)(char)value;
}

unsigned char ExprEvalContext::evaluateByteOffset(const std::unique_ptr<Expression>& expr)
{
    qint64 value = evaluate(expr) - nextAddress(expr->token());

    if (value < -128 || value > 255) {
        auto token = expr->token();
        mErrorReporter->error(token.file, token.line,
            QCoreApplication::tr("value %1 does not fit into a byte").arg(value));
        throw EvalError();
    }

    if (value >= 0)
        return (unsigned char)value;
    else
        return (unsigned char)(char)value;
}

unsigned short ExprEvalContext::evaluateWord(const std::unique_ptr<Expression>& expr)
{
    qint64 value = evaluate(expr);

    if (value < -32768 || value > 65535) {
        auto token = expr->token();
        mErrorReporter->error(token.file, token.line,
            QCoreApplication::tr("value %1 does not fit into a word").arg(value));
        throw EvalError();
    }

    if (value >= 0)
        return (unsigned short)value;
    else
        return (unsigned short)(short)value;
}

qint64 ExprEvalContext::evaluate(const std::unique_ptr<Expression>& expr)
{
    if (!mEvaluating.emplace(expr.get()).second) {
        auto token = expr->token();
        mErrorReporter->error(token.file, token.line,
            QCoreApplication::tr("hit circular dependency while evaluating expression"));
        throw EvalError();
    }

    qint64 value;
    try {
        value = expr->evaluate(*this);
    } catch (...) {
        mEvaluating.erase(expr.get());
        throw;
    }

    mEvaluating.erase(expr.get());

    return value;
}
