#ifndef COMPILER_PROGRAMSECTION_H
#define COMPILER_PROGRAMSECTION_H

#include "CodeEmitter.h"
#include "compiler/AssemblerToken.h"
#include <string>

class ProgramSection : public CodeEmitter
{
public:
    ProgramSection(Program* program, const Token& token, std::string name);
    ~ProgramSection();

    Program* program() const { return mProgram; }

    const std::string& name() const { return mName; }
    const char* nameCStr() const { return mName.c_str(); }

    bool hasBase() const { return mHasBase; }
    unsigned base() const { Q_ASSERT(mHasBase); return mBase; }
    unsigned baseRelativeTo(unsigned address) const;
    void setBase(unsigned value) { mBase = value; mHasBase = true; }

    bool hasAlignment() const { return mHasAlignment; }
    unsigned alignment() const { return mAlignment; }
    void setAlignment(unsigned value) { mAlignment = value; mHasAlignment = true; }

    bool hasFileName() const { return mHasFileName; }
    const std::string& fileName() const { Q_ASSERT(mHasFileName || mFileName.empty()); return mFileName; }
    void setFileName(std::string value) { mFileName = std::move(value); mHasFileName = true; }

    bool resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const override;
    void emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    Program* mProgram;
    Token mToken;
    std::string mName;
    unsigned mBase;
    unsigned mAlignment;
    std::string mFileName;
    bool mHasBase;
    bool mHasAlignment;
    bool mHasFileName;

    Q_DISABLE_COPY(ProgramSection)
};

#endif
