#include "Expression.h"
#include "IErrorReporter.h"
#include "Program.h"
#include "ProgramLabel.h"
#include <QCoreApplication>

Expression::Expression(const Token& token)
    : mToken(token)
{
}

Expression::~Expression()
{
}

bool Expression::resolveValues(const Program*, unsigned, IErrorReporter*)
{
    return true;
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

unsigned char Expression::evaluateByteOffset(IErrorReporter* reporter, unsigned baseAddress) const
{
    qint64 value = evaluate(reporter) - baseAddress;

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

DollarExpression::DollarExpression(const Token& token)
    : Expression(token)
    , mAddress(0)
    , mHasValue(false)
{
}

DollarExpression::~DollarExpression()
{
}

bool DollarExpression::resolveValues(const Program*, unsigned endAddress, IErrorReporter*)
{
    Q_ASSERT(!mHasValue);
    mHasValue = true;
    mAddress = endAddress;
    return true;
}

qint64 DollarExpression::evaluate(IErrorReporter* reporter) const
{
    if (!mHasValue)
        error(reporter, QCoreApplication::tr("'$' is not allowed in this context"));

    return mAddress;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IdentifierExpression::IdentifierExpression(const Token& token)
    : Expression(token)
    , mName(token.text)
    , mValue(0)
    , mHasValue(false)
{
}

IdentifierExpression::IdentifierExpression(const Token& token, std::string name)
    : Expression(token)
    , mName(std::move(name))
    , mValue(0)
    , mHasValue(false)
{
}

IdentifierExpression::~IdentifierExpression()
{
}

bool IdentifierExpression::resolveValues(const Program* program, unsigned endAddress, IErrorReporter* reporter)
{
    Q_ASSERT(!mHasValue);

    auto label = program->findLabel(mName);
    if (label != nullptr) {
        Q_ASSERT(label->hasAddress());
        mValue = label->address();
        mHasValue = true;
        return true;
    }

    auto constant = program->findConstant(mName);
    if (constant != nullptr) {
        mValue = constant->evaluate(reporter);
        mHasValue = true;
        return true;
    }

    error(reporter, QCoreApplication::tr("use of undeclared identifier '%1'").arg(mName.c_str()));
    return false;
}

qint64 IdentifierExpression::evaluate(IErrorReporter* reporter) const
{
    if (!mHasValue)
        error(reporter, QCoreApplication::tr("value for '%1' is not yet calculated").arg(mName.c_str()));

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

bool NegateExpression::resolveValues(const Program* program, unsigned endAddress, IErrorReporter* reporter)
{
    return mOperand->resolveValues(program, endAddress, reporter);
}

qint64 NegateExpression::evaluate(IErrorReporter* reporter) const
{
    return -mOperand->evaluate(reporter);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AddExpression::AddExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

AddExpression::~AddExpression()
{
}

bool AddExpression::resolveValues(const Program* program, unsigned endAddress, IErrorReporter* reporter)
{
    return mOperand1->resolveValues(program, endAddress, reporter)
        && mOperand2->resolveValues(program, endAddress, reporter);
}

qint64 AddExpression::evaluate(IErrorReporter* reporter) const
{
    return mOperand1->evaluate(reporter) + mOperand2->evaluate(reporter);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SubtractExpression::SubtractExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

SubtractExpression::~SubtractExpression()
{
}

bool SubtractExpression::resolveValues(const Program* program, unsigned endAddress, IErrorReporter* reporter)
{
    return mOperand1->resolveValues(program, endAddress, reporter)
        && mOperand2->resolveValues(program, endAddress, reporter);
}

qint64 SubtractExpression::evaluate(IErrorReporter* reporter) const
{
    return mOperand1->evaluate(reporter) - mOperand2->evaluate(reporter);
}
