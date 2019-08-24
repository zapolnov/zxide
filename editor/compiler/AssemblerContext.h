#ifndef COMPILER_ASSEMBLERCONTEXT_H
#define COMPILER_ASSEMBLERCONTEXT_H

#include "AssemblerToken.h"
#include <memory>
#include <string>

class Program;
class ProgramSection;
class ProgramLabel;
class CodeEmitter;
class RepeatedCodeEmitter;
class Expression;
class ExprEvalContext;
class IErrorReporter;
struct Value;

class AssemblerContext
{
public:
    explicit AssemblerContext(std::unique_ptr<AssemblerContext> prev);
    AssemblerContext(const AssemblerContext& source);
    virtual ~AssemblerContext();

    virtual std::unique_ptr<AssemblerContext> clone() const = 0;

    AssemblerContext* prev() const { return mPrev.get(); }
    std::unique_ptr<AssemblerContext> takePrev();

    virtual bool isRepeat() const;
    virtual bool hasVariable(const std::string& name) const;
    virtual const std::shared_ptr<Value>& getVariable(const std::string& name) const;

    virtual std::string localLabelsPrefix() const;
    virtual void setLocalLabelsPrefix(std::string prefix, const Token& token, IErrorReporter* reporter);
    Value resolveLocalValue(ExprEvalContext& context, const Token& token) const;
    virtual bool areGlobalLabelsAllowed() const;
    virtual void adjustLabel(ProgramLabel* label);

    virtual CodeEmitter* codeEmitter() const = 0;
    virtual bool setCurrentSection(ProgramSection* section);

private:
    std::unique_ptr<AssemblerContext> mPrev;
    std::string mLocalLabelsPrefix;
};

class AssemblerDefaultContext : public AssemblerContext
{
public:
    explicit AssemblerDefaultContext(Program* program);

    std::unique_ptr<AssemblerContext> clone() const override;

    CodeEmitter* codeEmitter() const override;
    bool setCurrentSection(ProgramSection* section) override;

private:
    ProgramSection* mSection;
};

class AssemblerRepeatContext : public AssemblerContext
{
public:
    AssemblerRepeatContext(std::unique_ptr<AssemblerContext> prev,
        const Token& token, std::string var, std::unique_ptr<Expression> count);

    std::unique_ptr<AssemblerContext> clone() const override;

    bool isRepeat() const final override;
    bool hasVariable(const std::string& name) const override;
    const std::shared_ptr<Value>& getVariable(const std::string& name) const override;

    std::string localLabelsPrefix() const override;
    void setLocalLabelsPrefix(std::string prefix, const Token& token, IErrorReporter* reporter) override;
    bool areGlobalLabelsAllowed() const override;
    void adjustLabel(ProgramLabel* label) override;

    CodeEmitter* codeEmitter() const override;
    const std::shared_ptr<RepeatedCodeEmitter>& codeEmitterSharedPtr() const { return mCodeEmitter; }

private:
    std::string mVariable;
    std::shared_ptr<RepeatedCodeEmitter> mCodeEmitter;
    Token mToken;
};

#endif
