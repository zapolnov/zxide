#ifndef COMPILER_EXPREVALCONTEXT_H
#define COMPILER_EXPREVALCONTEXT_H

#include "Value.h"
#include <unordered_set>
#include <memory>

struct Token;
class Program;
class ProgramOpcode;
class Expression;
class IErrorReporter;

class ExprEvalContext
{
public:
    ExprEvalContext(const Program* program, IErrorReporter* reporter);
    ExprEvalContext(const Program* program, IErrorReporter* reporter, const ProgramOpcode* opcode);
    ~ExprEvalContext();

    const Program* program() const { return mProgram; }
    IErrorReporter* errorReporter() const { return mErrorReporter; }

    unsigned baseAddress(const Token& token) const;
    unsigned nextAddress(const Token& token) const;

    unsigned char evaluateByte(const std::unique_ptr<Expression>& expr);
    unsigned char evaluateByteOffset(const std::unique_ptr<Expression>& expr);
    unsigned short evaluateWord(const std::unique_ptr<Expression>& expr);
    Value evaluate(const std::unique_ptr<Expression>& expr);

private:
    const Program* mProgram;
    IErrorReporter* mErrorReporter;
    qint32 mBaseAddress;
    qint32 mNextAddress;
    std::unordered_set<Expression*> mEvaluating;

    Q_DISABLE_COPY(ExprEvalContext)
};

#endif
