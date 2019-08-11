#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H

#include "Value.h"
#include "AssemblerToken.h"
#include <string>
#include <memory>

class Program;
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
    IdentifierExpression(const Token& token, std::string name);
    ~IdentifierExpression() override;

private:
    std::string mName;

    Value evaluate(ExprEvalContext& context) const override;

    Q_DISABLE_COPY(IdentifierExpression)
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

#endif
