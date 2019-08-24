#ifndef COMPILER_CODEEMITTER_H
#define COMPILER_CODEEMITTER_H

#include <QtGlobal>
#include <memory>
#include <vector>

#ifdef emit
#undef emit
#endif

class Program;
class ProgramBinary;
class ProgramOpcode;
class Expression;
class IErrorReporter;
struct Value;

class CodeEmitter
{
public:
    CodeEmitter();
    virtual ~CodeEmitter();

    bool isEmpty() const { return mOpcodes.empty(); }

    template <typename T, typename... ARGS> T* emit(ARGS&&... args)
    {
        auto uniq = std::make_unique<T>(std::forward<ARGS>(args)...);
        auto ptr = uniq.get();
        mOpcodes.emplace_back(std::move(uniq));
        return ptr;
    }

    virtual unsigned totalLengthInBytes(const Program* program, IErrorReporter* reporter) const;
    virtual unsigned totalTStatesIfNotTaken(const Program* program, IErrorReporter* reporter) const;
    virtual unsigned totalTStatesIfTaken(const Program* program, IErrorReporter* reporter) const;

    virtual bool resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const;
    virtual void emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const;

private:
    std::vector<std::unique_ptr<ProgramOpcode>> mOpcodes;

    Q_DISABLE_COPY(CodeEmitter)
};

class RepeatedCodeEmitter : public CodeEmitter
{
public:
    explicit RepeatedCodeEmitter(std::unique_ptr<Expression> repeatCount);
    ~RepeatedCodeEmitter();

    const std::shared_ptr<Value>& counter() const { return mCounter; }

    unsigned totalLengthInBytes(const Program* program, IErrorReporter* reporter) const override;
    unsigned totalTStatesIfNotTaken(const Program* program, IErrorReporter* reporter) const override;
    unsigned totalTStatesIfTaken(const Program* program, IErrorReporter* reporter) const override;

    bool resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const override;
    void emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    std::shared_ptr<Value> mCounter;
    std::unique_ptr<Expression> mRepeatCount;

    bool evaluateRepeatCount(const Program* program, IErrorReporter* reporter, qint64& value) const;

    Q_DISABLE_COPY(RepeatedCodeEmitter)
};

#endif
