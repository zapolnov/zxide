#ifndef COMPILER_ASSEMBLERCONTEXT_H
#define COMPILER_ASSEMBLERCONTEXT_H

#include <QtGlobal>
#include <memory>
#include <string>

class Program;
class ProgramSection;
class CodeEmitter;
class RepeatedCodeEmitter;
class Expression;
struct Value;

class AssemblerContext
{
public:
    explicit AssemblerContext(std::unique_ptr<AssemblerContext> prev);
    virtual ~AssemblerContext();

    AssemblerContext* prev() const { return mPrev.get(); }
    std::unique_ptr<AssemblerContext> takePrev();

    virtual bool isRepeat() const;
    virtual bool hasVariable(const std::string& name) const;
    virtual const std::shared_ptr<Value>& getVariable(const std::string& name) const;

    virtual CodeEmitter* codeEmitter() const = 0;
    virtual bool setCurrentSection(ProgramSection* section);

private:
    std::unique_ptr<AssemblerContext> mPrev;

    Q_DISABLE_COPY(AssemblerContext)
};

class AssemblerDefaultContext : public AssemblerContext
{
public:
    explicit AssemblerDefaultContext(Program* program);

    CodeEmitter* codeEmitter() const override;
    bool setCurrentSection(ProgramSection* section) override;

private:
    ProgramSection* mSection;

    Q_DISABLE_COPY(AssemblerDefaultContext)
};

class AssemblerRepeatContext : public AssemblerContext
{
public:
    AssemblerRepeatContext(std::unique_ptr<AssemblerContext> prev, std::string var, std::unique_ptr<Expression> count);

    bool isRepeat() const final override;
    bool hasVariable(const std::string& name) const override;
    const std::shared_ptr<Value>& getVariable(const std::string& name) const override;

    CodeEmitter* codeEmitter() const override;
    const std::shared_ptr<RepeatedCodeEmitter>& codeEmitterSharedPtr() const { return mCodeEmitter; }

private:
    std::string mVariable;
    std::shared_ptr<RepeatedCodeEmitter> mCodeEmitter;

    Q_DISABLE_COPY(AssemblerRepeatContext)
};

#endif
