#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H

#include "AssemblerToken.h"
#include <memory>

class IErrorReporter;
class ProgramSection;

class EvalError
{
};

class Expression
{
public:
    explicit Expression(const Token& token);
    virtual ~Expression();

    const Token& token() const { return mToken; }

    virtual void resolveAddresses(const ProgramSection* section, unsigned endAddress);

    unsigned char evaluateByte(IErrorReporter* reporter) const;
    unsigned short evaluateWord(IErrorReporter* reporter) const;
    virtual qint64 evaluate(IErrorReporter* reporter) const = 0;

protected:
    void error(IErrorReporter* reporter, const QString& message) const;

private:
    Token mToken;

    Q_DISABLE_COPY(Expression)
};

class ConstantExpression : public Expression
{
public:
    ConstantExpression(const Token& token, qint64 value);
    ~ConstantExpression() override;

    qint64 evaluate(IErrorReporter* reporter) const override;

private:
    qint64 mValue;

    Q_DISABLE_COPY(ConstantExpression)
};

class DollarExpression : public Expression
{
public:
    explicit DollarExpression(const Token& token);
    ~DollarExpression() override;

    void resolveAddresses(const ProgramSection* section, unsigned endAddress) override;
    qint64 evaluate(IErrorReporter* reporter) const override;

private:
    unsigned short mAddress;
    bool mHasValue;

    Q_DISABLE_COPY(DollarExpression)
};

class NegateExpression : public Expression
{
public:
    NegateExpression(const Token& token, std::unique_ptr<Expression> operand);
    ~NegateExpression() override;

    void resolveAddresses(const ProgramSection* section, unsigned endAddress) override;
    qint64 evaluate(IErrorReporter* reporter) const override;

private:
    std::unique_ptr<Expression> mOperand;

    Q_DISABLE_COPY(NegateExpression)
};

class AddExpression : public Expression
{
public:
    AddExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~AddExpression() override;

    void resolveAddresses(const ProgramSection* section, unsigned endAddress) override;
    qint64 evaluate(IErrorReporter* reporter) const override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Q_DISABLE_COPY(AddExpression)
};

class SubtractExpression : public Expression
{
public:
    SubtractExpression(const Token& token, std::unique_ptr<Expression> op1, std::unique_ptr<Expression> op2);
    ~SubtractExpression() override;

    void resolveAddresses(const ProgramSection* section, unsigned endAddress) override;
    qint64 evaluate(IErrorReporter* reporter) const override;

private:
    std::unique_ptr<Expression> mOperand1;
    std::unique_ptr<Expression> mOperand2;

    Q_DISABLE_COPY(SubtractExpression)
};

#endif
