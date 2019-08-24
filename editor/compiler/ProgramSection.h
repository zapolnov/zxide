#ifndef COMPILER_PROGRAMSECTION_H
#define COMPILER_PROGRAMSECTION_H

#include "CodeEmitter.h"
#include <string>

class ProgramSection : public CodeEmitter
{
public:
    ProgramSection(Program* program, std::string name);
    ~ProgramSection();

    Program* program() const { return mProgram; }

    const std::string& name() const { return mName; }
    const char* nameCStr() const { return mName.c_str(); }

    bool hasBase() const { return mHasBase; }
    unsigned base() const { Q_ASSERT(mHasBase); return mBase; }
    void setBase(unsigned value) { mBase = value; mHasBase = true; }

    bool hasAlignment() const { return mHasAlignment; }
    unsigned alignment() const { return mAlignment; }
    void setAlignment(unsigned value) { mAlignment = value; mHasAlignment = true; }

    bool resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const override;
    void emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    Program* mProgram;
    std::string mName;
    unsigned mBase;
    unsigned mAlignment;
    bool mHasBase;
    bool mHasAlignment;

    Q_DISABLE_COPY(ProgramSection)
};

#endif
