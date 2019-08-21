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

    virtual bool resolveAddresses(IErrorReporter* reporter, quint32& address) const;
    virtual void emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const;

private:
    std::vector<std::unique_ptr<ProgramOpcode>> mOpcodes;

    Q_DISABLE_COPY(CodeEmitter)
};

#endif
