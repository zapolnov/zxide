#ifndef COMPILER_PROGRAMSECTION_H
#define COMPILER_PROGRAMSECTION_H

#include "CodeEmitter.h"
#include "compiler/AssemblerToken.h"
#include <string>

class Expression;

class ProgramSection : public CodeEmitter
{
public:
    ProgramSection(Program* program, const Token& token, std::string name);
    ~ProgramSection() override;

    Program* program() const { return mProgram; }

    const std::string& name() const { return mName; }
    const char* nameCStr() const { return mName.c_str(); }

    bool hasBase() const { return mBase != nullptr; }
    void setBase(std::unique_ptr<Expression> expr);
    unsigned base(IErrorReporter* reporter) const;

    bool hasAlignment() const { return mAlignment != nullptr; }
    void setAlignment(std::unique_ptr<Expression> expr);
    unsigned alignment(IErrorReporter* reporter) const;

    bool hasFileName() const { return mHasFileName; }
    const std::string& fileName() const { Q_ASSERT(mHasFileName || mFileName.empty()); return mFileName; }
    void setFileName(std::string value) { mFileName = std::move(value); mHasFileName = true; }

    unsigned resolvedBase() const { return mResolvedBase; }
    bool resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const override;
    void emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    Program* mProgram;
    Token mToken;
    std::string mName;
    std::unique_ptr<Expression> mBase;
    std::unique_ptr<Expression> mAlignment;
    std::string mFileName;
    mutable unsigned mResolvedBase;
    mutable unsigned mCalculatedBase;
    mutable unsigned mCalculatedAlignment;
    mutable bool mHasCalculatedBase;
    mutable bool mHasCalculatedAlignment;
    bool mHasFileName;

    Q_DISABLE_COPY(ProgramSection)
};

#endif
