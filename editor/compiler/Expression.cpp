#include "Expression.h"
#include "Compiler.h"
#include "ExprEvalContext.h"
#include "IErrorReporter.h"
#include "AssemblerContext.h"
#include "Program.h"
#include "ProgramLabel.h"
#include <QCoreApplication>

template <bool SUB, typename T> Value smartEvaluate(T&& operatr, Value a, Value b)
{
    auto bits = (a.bits > b.bits ? a.bits : b.bits);
    Sign sign = (a.sign == Sign::Signed || b.sign == Sign::Signed ? Sign::Signed : Sign::Unsigned);

    switch (bits) {
        case SignificantBits::NoMoreThan8: {
            if (sign == Sign::Unsigned) {
                quint8 aa = quint8(a.number & 0xff);
                quint8 bb = quint8(b.number & 0xff);
                if (!SUB || bb <= aa)
                    return Value(operatr(a.number, b.number), sign, Value::significantBitsForNumber(operatr(aa, bb)));
            }
            qint8 aa = qint8(a.number & 0xff);
            qint8 bb = qint8(b.number & 0xff);
            return Value(operatr(a.number, b.number), Sign::Signed, Value::significantBitsForNumber(operatr(aa, bb)));
        }

        case SignificantBits::NoMoreThan16: {
            if (sign == Sign::Unsigned) {
                quint16 aa = quint16(a.number & 0xffff);
                quint16 bb = quint16(b.number & 0xffff);
                if (!SUB || bb <= aa)
                    return Value(operatr(a.number, b.number), sign, Value::significantBitsForNumber(operatr(aa, bb)));
            }
            qint16 aa = qint16(a.number & 0xffff);
            qint16 bb = qint16(b.number & 0xffff);
            return Value(operatr(a.number, b.number), Sign::Signed, Value::significantBitsForNumber(operatr(aa, bb)));
        }

        case SignificantBits::All:
            break;
    }

    return Value(operatr(a.number, b.number), sign);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Expression::Expression(const Token& token)
    : mToken(token)
{
}

Expression::~Expression()
{
}

void Expression::error(ExprEvalContext& context, const QString& message) const
{
    QString fileName = (mToken.file ? mToken.file->name : QString());
    context.errorReporter()->error(fileName, mToken.line, message);
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

Value ConstantExpression::evaluate(ExprEvalContext&) const
{
    return Value(mValue);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DollarExpression::DollarExpression(const Token& token)
    : Expression(token)
{
}

DollarExpression::~DollarExpression()
{
}

Value DollarExpression::evaluate(ExprEvalContext& context) const
{
    return Value(context.baseAddress(token()));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IdentifierExpression::IdentifierExpression(const Token& token)
    : Expression(token)
    , mName(token.text)
{
}

IdentifierExpression::~IdentifierExpression()
{
}

Value IdentifierExpression::evaluate(ExprEvalContext& context) const
{
    auto label = context.program()->findLabel(mName);
    if (label != nullptr) {
        if (!label->hasAddress())
            error(context, QCoreApplication::tr("value for '%1' is not available in this context").arg(mName.c_str()));
        return Value(label->address()->value());
    }

    const auto& constant = context.program()->findConstant(mName);
    if (constant != nullptr)
        return context.evaluate(constant);

    error(context, QCoreApplication::tr("use of undeclared identifier '%1'").arg(mName.c_str()));
    return Value(0, Sign::Unsigned, SignificantBits::NoMoreThan8);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LocalNameExpression::LocalNameExpression(std::unique_ptr<AssemblerContext> context, const Token& token)
    : Expression(token)
    , mContext(std::move(context))
    , mName(token.text)
{
}

LocalNameExpression::~LocalNameExpression()
{
}

Value LocalNameExpression::evaluate(ExprEvalContext& context) const
{
    return mContext->resolveLocalValue(context, token());
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MacroVariableExpression::MacroVariableExpression(const Token& token, std::shared_ptr<Value> value)
    : Expression(token)
    , mValue(std::move(value))
{
}

MacroVariableExpression::~MacroVariableExpression()
{
}

Value MacroVariableExpression::evaluate(ExprEvalContext&) const
{
    return *mValue;
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

Value NegateExpression::evaluate(ExprEvalContext& context) const
{
    Value value = context.evaluate(mOperand);
    switch (value.bits) {
        case SignificantBits::NoMoreThan8:
            if (value.sign == Sign::Unsigned) {
                quint8 x = quint8(value.number & 0xff);
                if (x <= 0x80)
                    return Value(-value.number, Sign::Signed, SignificantBits::NoMoreThan8);
            } else {
                qint8 x = qint8(value.number & 0xff);
                if (x != -128) // +128 does not fit into 8 bits
                    return Value(-value.number, Sign::Signed, SignificantBits::NoMoreThan8);
            }
            return Value(-value.number, Sign::Signed, SignificantBits::NoMoreThan16);

        case SignificantBits::NoMoreThan16:
            if (value.sign == Sign::Unsigned) {
                quint16 x = quint16(value.number & 0xffff);
                if (x <= 0x8000)
                    return Value(-value.number, Sign::Signed, SignificantBits::NoMoreThan16);
            } else {
                qint16 x = qint16(value.number & 0xffff);
                if (x != -32768) // +32768 does not fit into 16 bits
                    return Value(-value.number, Sign::Signed, SignificantBits::NoMoreThan16);
            }
            break;

        case SignificantBits::All:
            break;
    }

    return Value(-value.number, Sign::Signed);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BitwiseNotExpression::BitwiseNotExpression(const Token& token, std::unique_ptr<Expression> operand)
    : Expression(token)
    , mOperand(std::move(operand))
{
}

BitwiseNotExpression::~BitwiseNotExpression()
{
}

Value BitwiseNotExpression::evaluate(ExprEvalContext& context) const
{
    Value operand = context.evaluate(mOperand);
    if (operand.sign == Sign::Unsigned)
        return Value(~operand.number & 0x7fffffffffffffffll, operand.sign, operand.bits);
    return Value(~operand.number, operand.sign, operand.bits);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LogicNotExpression::LogicNotExpression(const Token& token, std::unique_ptr<Expression> operand)
    : Expression(token)
    , mOperand(std::move(operand))
{
}

LogicNotExpression::~LogicNotExpression()
{
}

Value LogicNotExpression::evaluate(ExprEvalContext& context) const
{
    Value operand = context.evaluate(mOperand);
    return Value(!operand.number, Sign::Unsigned, SignificantBits::NoMoreThan8);
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

Value AddExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return smartEvaluate<false>([](qint64 a, qint64 b){ return a + b; }, a, b);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SubtractExpression::SubtractExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

SubtractExpression::~SubtractExpression()
{
}

Value SubtractExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return smartEvaluate<true>([](qint64 a, qint64 b){ return a - b; }, a, b);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MultiplyExpression::MultiplyExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

MultiplyExpression::~MultiplyExpression()
{
}

Value MultiplyExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return smartEvaluate<false>([](qint64 a, qint64 b){ return a * b; }, a, b);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DivideExpression::DivideExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

DivideExpression::~DivideExpression()
{
}

Value DivideExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return smartEvaluate<false>([](qint64 a, qint64 b){ return a / b; }, a, b);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RemainderExpression::RemainderExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

RemainderExpression::~RemainderExpression()
{
}

Value RemainderExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return smartEvaluate<false>([](qint64 a, qint64 b){ return a % b; }, a, b);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ShiftLeftExpression::ShiftLeftExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

ShiftLeftExpression::~ShiftLeftExpression()
{
}

Value ShiftLeftExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);

    if (b.number < 0) {
        b.truncateToSignificantBits();
        if (b.number < 0)
            error(context, QCoreApplication::tr("negative shift count for operator '<<'"));
    }

    if (b.number > 64) {
        b.truncateToSignificantBits();
        if (b.number > 64)
            error(context, QCoreApplication::tr("shift count is too large for operator '<<'"));
    }

    return smartEvaluate<false>([](qint64 a, qint64 b){ return a << b; }, a, b);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ShiftRightExpression::ShiftRightExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

ShiftRightExpression::~ShiftRightExpression()
{
}

Value ShiftRightExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);

    if (b.number < 0) {
        b.truncateToSignificantBits();
        if (b.number < 0)
            error(context, QCoreApplication::tr("negative shift count for operator '>>'"));
    }

    if (b.number > 64) {
        b.truncateToSignificantBits();
        if (b.number > 64)
            error(context, QCoreApplication::tr("shift count is too large for operator '>>'"));
    }

    return smartEvaluate<false>([](qint64 a, qint64 b){ return a >> b; }, a, b);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LessExpression::LessExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

LessExpression::~LessExpression()
{
}

Value LessExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return Value(a.number < b.number ? 1 : 0, Sign::Unsigned, SignificantBits::NoMoreThan8);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LessEqualExpression::LessEqualExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

LessEqualExpression::~LessEqualExpression()
{
}

Value LessEqualExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return Value(a.number <= b.number ? 1 : 0, Sign::Unsigned, SignificantBits::NoMoreThan8);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GreaterExpression::GreaterExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

GreaterExpression::~GreaterExpression()
{
}

Value GreaterExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return Value(a.number > b.number ? 1 : 0, Sign::Unsigned, SignificantBits::NoMoreThan8);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GreaterEqualExpression::GreaterEqualExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

GreaterEqualExpression::~GreaterEqualExpression()
{
}

Value GreaterEqualExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return Value(a.number >= b.number ? 1 : 0, Sign::Unsigned, SignificantBits::NoMoreThan8);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

EqualExpression::EqualExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

EqualExpression::~EqualExpression()
{
}

Value EqualExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return Value(a.number == b.number ? 1 : 0, Sign::Unsigned, SignificantBits::NoMoreThan8);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NotEqualExpression::NotEqualExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

NotEqualExpression::~NotEqualExpression()
{
}

Value NotEqualExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return Value(a.number != b.number ? 1 : 0, Sign::Unsigned, SignificantBits::NoMoreThan8);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BitwiseAndExpression::BitwiseAndExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

BitwiseAndExpression::~BitwiseAndExpression()
{
}

Value BitwiseAndExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    auto bits = (a.bits > b.bits ? a.bits : b.bits);
    auto sign = (a.sign == Sign::Signed || b.sign == Sign::Signed ? Sign::Signed : Sign::Unsigned);
    return Value(a.number & b.number, sign, bits);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BitwiseOrExpression::BitwiseOrExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

BitwiseOrExpression::~BitwiseOrExpression()
{
}

Value BitwiseOrExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    auto bits = (a.bits > b.bits ? a.bits : b.bits);
    auto sign = (a.sign == Sign::Signed || b.sign == Sign::Signed ? Sign::Signed : Sign::Unsigned);
    return Value(a.number | b.number, sign, bits);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BitwiseXorExpression::BitwiseXorExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

BitwiseXorExpression::~BitwiseXorExpression()
{
}

Value BitwiseXorExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    auto bits = (a.bits > b.bits ? a.bits : b.bits);
    auto sign = (a.sign == Sign::Signed || b.sign == Sign::Signed ? Sign::Signed : Sign::Unsigned);
    return Value(a.number ^ b.number, sign, bits);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LogicalAndExpression::LogicalAndExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

LogicalAndExpression::~LogicalAndExpression()
{
}

Value LogicalAndExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return Value(a.number && b.number ? 1 : 0, Sign::Unsigned, SignificantBits::NoMoreThan8);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LogicalOrExpression::LogicalOrExpression(const Token& token,
        std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2)
    : Expression(token)
    , mOperand1(std::move(op1))
    , mOperand2(std::move(op2))
{
}

LogicalOrExpression::~LogicalOrExpression()
{
}

Value LogicalOrExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mOperand1);
    Value b = context.evaluate(mOperand2);
    return Value(a.number || b.number ? 1 : 0, Sign::Unsigned, SignificantBits::NoMoreThan8);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ConditionalExpression::ConditionalExpression(const Token& token,
        std::unique_ptr<Expression> cond, std::unique_ptr<Expression> opThen, std::unique_ptr<Expression> opElse)
    : Expression(token)
    , mCondition(std::move(cond))
    , mThen(std::move(opThen))
    , mElse(std::move(opElse))
{
}

ConditionalExpression::~ConditionalExpression()
{
}

Value ConditionalExpression::evaluate(ExprEvalContext& context) const
{
    Value a = context.evaluate(mCondition);
    if (a.number != 0)
        return context.evaluate(mThen);
    else
        return context.evaluate(mElse);
}
