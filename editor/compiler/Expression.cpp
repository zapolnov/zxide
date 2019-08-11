#include "Expression.h"
#include "IErrorReporter.h"
#include <QCoreApplication>

Expression::Expression(const Token& token)
    : mToken(token)
{
}

Expression::~Expression()
{
}

unsigned char Expression::evaluateByte(IErrorReporter* reporter) const
{
    qint64 value = evaluate(reporter);

    if (value < -128 || value > 255)
        error(reporter, QCoreApplication::tr("value %1 does not fit into a byte").arg(value));

    if (value >= 0)
        return (unsigned char)value;
    else
        return (unsigned char)(char)value;
}

unsigned short Expression::evaluateWord(IErrorReporter* reporter) const
{
    qint64 value = evaluate(reporter);

    if (value < -32768 || value > 65535)
        error(reporter, QCoreApplication::tr("value %1 does not fit into a word").arg(value));

    if (value >= 0)
        return (unsigned short)value;
    else
        return (unsigned short)(short)value;
}

void Expression::error(IErrorReporter* reporter, const QString& message) const
{
    reporter->error(mToken.file, mToken.line, message);
    throw EvalError();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ConstantExpression::ConstantExpression(const Token& token, qint64 value)
    : Expression(token)
    , mValue(value)
{
}

ConstantExpression::~ConstantExpression()
{
}

qint64 ConstantExpression::evaluate(IErrorReporter* reporter) const
{
    return mValue;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NegateExpression::NegateExpression(const Token& token, std::unique_ptr<Expression> operand)
    : Expression(token)
    , mOperand(std::move(operand))
{
}

NegateExpression::~NegateExpression()
{
}

qint64 NegateExpression::evaluate(IErrorReporter* reporter) const
{
    return -mOperand->evaluate(reporter);
}
