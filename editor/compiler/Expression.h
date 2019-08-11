#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H

#include "AssemblerToken.h"

class IErrorReporter;

class EvalError
{
};

class Expression
{
public:
    explicit Expression(const Token& token);
    virtual ~Expression();

    const Token& token() const { return mToken; }

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

#endif
