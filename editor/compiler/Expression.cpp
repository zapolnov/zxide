#include "Expression.h"
#include "ExprEvalContext.h"
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

void Expression::error(ExprEvalContext& context, const QString& message) const
{
    context.errorReporter()->error(mToken.file, mToken.line, message);
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

qint64 ConstantExpression::evaluate(ExprEvalContext&) const
{
    return mValue;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DollarExpression::DollarExpression(const Token& token)
    : Expression(token)
{
}

DollarExpression::~DollarExpression()
{
}

qint64 DollarExpression::evaluate(ExprEvalContext& context) const
{
    return context.baseAddress(token());
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IdentifierExpression::IdentifierExpression(const Token& token)
    : Expression(token)
    , mName(token.text)
{
}

IdentifierExpression::IdentifierExpression(const Token& token, std::string name)
    : Expression(token)
    , mName(std::move(name))
{
}

IdentifierExpression::~IdentifierExpression()
{
}

qint64 IdentifierExpression::evaluate(ExprEvalContext& context) const
{
    auto label = context.program()->findLabel(mName);
    if (label != nullptr) {
        if (!label->hasAddress())
            error(context, QCoreApplication::tr("value for '%1' is not available in this context").arg(mName.c_str()));
        return label->address();
    }

    const auto& constant = context.program()->findConstant(mName);
    if (constant != nullptr)
        return context.evaluate(constant);

    error(context, QCoreApplication::tr("use of undeclared identifier '%1'").arg(mName.c_str()));
    return 0;
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

qint64 NegateExpression::evaluate(ExprEvalContext& context) const
{
    return -context.evaluate(mOperand);
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

qint64 AddExpression::evaluate(ExprEvalContext& context) const
{
    return context.evaluate(mOperand1) + context.evaluate(mOperand2);
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

qint64 SubtractExpression::evaluate(ExprEvalContext& context) const
{
    return context.evaluate(mOperand1) - context.evaluate(mOperand2);
}
