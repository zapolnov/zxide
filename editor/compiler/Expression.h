#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H

#include "Value.h"
#include "AssemblerToken.h"
#include <string>
#include <memory>

class Program;
class AssemblerContext;
class ExprEvalContext;

class EvalError
{
};

class Expression
{
public:
    explicit Expression(const Token& token);
    virtual ~Expression();

    const Token& token() const { return mToken; }

protected:
    void error(ExprEvalContext& context, const QString& message) const;

private:
    Token mToken;

    virtual Value evaluate(ExprEvalContext& context) const = 0;

    Q_DISABLE_COPY(Expression)
    friend class ExprEvalContext;
};

class ConstantExpression : public Expression
{
public:
    ConstantExpression(const Token& token, qint64 value);
    ~ConstantExpression() override;

private:
    qint64 mValue;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(ConstantExpression)
};

class DollarExpression : public Expression
{
public:
    explicit DollarExpression(const Token& token);
    ~DollarExpression() override;

private:
    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(DollarExpression)
};

class IdentifierExpression : public Expression
{
public:
    explicit IdentifierExpression(const Token& token);
    ~IdentifierExpression() override;

private:
    std::string mName;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(IdentifierExpression)
};

class LocalNameExpression : public Expression
{
public:
    LocalNameExpression(std::unique_ptr<AssemblerContext> context, const Token& token);
    ~LocalNameExpression() override;

private:
    std::unique_ptr<AssemblerContext> mContext;
    std::string mName;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(LocalNameExpression)
};

class MacroVariableExpression : public Expression
{
public:
    MacroVariableExpression(const Token& token, std::shared_ptr<Value> value);
    ~MacroVariableExpression() override;

private:
    std::shared_ptr<Value> mValue;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(MacroVariableExpression)
};

class NegateExpression : public Expression
{
public:
    NegateExpression(const Token& token, std::unique_ptr<Expression> operand);
    ~NegateExpression() override;

private:
    std::unique_ptr<Expression> mOperand;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(NegateExpression)
};

class BitwiseNotExpression : public Expression
{
public:
    BitwiseNotExpression(const Token& token, std::unique_ptr<Expression> operand);
    ~BitwiseNotExpression() override;

private:
    std::unique_ptr<Expression> mOperand;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(BitwiseNotExpression)
};

class LogicNotExpression : public Expression
{
public:
    LogicNotExpression(const Token& token, std::unique_ptr<Expression> operand);
    ~LogicNotExpression() override;

private:
    std::unique_ptr<Expression> mOperand;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(LogicNotExpression)
};

class AddExpression : public Expression
{
public:
    AddExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~AddExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(AddExpression)
};

class SubtractExpression : public Expression
{
public:
    SubtractExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~SubtractExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(SubtractExpression)
};

class MultiplyExpression : public Expression
{
public:
    MultiplyExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~MultiplyExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(MultiplyExpression)
};

class DivideExpression : public Expression
{
public:
    DivideExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~DivideExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(DivideExpression)
};

class RemainderExpression : public Expression
{
public:
    RemainderExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~RemainderExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(RemainderExpression)
};

class ShiftLeftExpression : public Expression
{
public:
    ShiftLeftExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~ShiftLeftExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(ShiftLeftExpression)
};

class ShiftRightExpression : public Expression
{
public:
    ShiftRightExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~ShiftRightExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(ShiftRightExpression)
};

class LessExpression : public Expression
{
public:
    LessExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~LessExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(LessExpression)
};

class LessEqualExpression : public Expression
{
public:
    LessEqualExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~LessEqualExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(LessEqualExpression)
};

class GreaterExpression : public Expression
{
public:
    GreaterExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~GreaterExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(GreaterExpression)
};

class GreaterEqualExpression : public Expression
{
public:
    GreaterEqualExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~GreaterEqualExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(GreaterEqualExpression)
};

class EqualExpression : public Expression
{
public:
    EqualExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~EqualExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(EqualExpression)
};

class NotEqualExpression : public Expression
{
public:
    NotEqualExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~NotEqualExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(NotEqualExpression)
};

class BitwiseAndExpression : public Expression
{
public:
    BitwiseAndExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~BitwiseAndExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(BitwiseAndExpression)
};

class BitwiseOrExpression : public Expression
{
public:
    BitwiseOrExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~BitwiseOrExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(BitwiseOrExpression)
};

class BitwiseXorExpression : public Expression
{
public:
    BitwiseXorExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~BitwiseXorExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(BitwiseXorExpression)
};

class LogicalAndExpression : public Expression
{
public:
    LogicalAndExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~LogicalAndExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(LogicalAndExpression)
};

class LogicalOrExpression : public Expression
{
public:
    LogicalOrExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~LogicalOrExpression() override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(LogicalOrExpression)
};

class ConditionalExpression : public Expression
{
public:
    ConditionalExpression(const Token& token,
        std::unique_ptr<Expression> cond, std::unique_ptr<Expression> opThen, std::unique_ptr<Expression> opElse);
    ~ConditionalExpression() override;

private:
    std::unique_ptr<Expression> mCondition;
    std::unique_ptr<Expression> mThen;
    std::unique_ptr<Expression> mElse;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(ConditionalExpression)
};

#endif
