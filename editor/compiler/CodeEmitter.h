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

    virtual unsigned totalLengthInBytes() const;
    virtual unsigned totalTStatesIfNotTaken() const;
    virtual unsigned totalTStatesIfTaken() const;

    virtual bool resolveAddresses(IErrorReporter* reporter, quint32& address) const;
    virtual void emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const;

private:
    std::vector<std::unique_ptr<ProgramOpcode>> mOpcodes;

    Q_DISABLE_COPY(CodeEmitter)
};

class RepeatedCodeEmitter : public CodeEmitter
{
public:
    explicit RepeatedCodeEmitter(qint64 repeatCount);
    ~RepeatedCodeEmitter();

    const std::shared_ptr<Value>& counter() const { return mCounter; }

    unsigned totalLengthInBytes() const override;
    unsigned totalTStatesIfNotTaken() const override;
    unsigned totalTStatesIfTaken() const override;

    bool resolveAddresses(IErrorReporter* reporter, quint32& address) const override;
    void emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    qint64 mRepeatCount;
    std::shared_ptr<Value> mCounter;

    Q_DISABLE_COPY(RepeatedCodeEmitter)
};

#endif
