#ifndef COMPILER_PROGRAMSECTION_H
#define COMPILER_PROGRAMSECTION_H

#include "CodeEmitter.h"
#include "compiler/AssemblerToken.h"
#include <string>

class ProgramSection : public CodeEmitter
{
public:
    enum {
        MaxBank = 7,
        BankBaseAddress = 0xC000,
    };

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

    bool hasBank() const { return mHasBank; }
    unsigned bank() const { Q_ASSERT(mHasBank); return mBank; }
    void setBank(unsigned value) { mBank = value; mHasBank = true; }

    bool resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const override;
    void emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

    static bool isValidBankNumber(unsigned bank) { return (bank >= 1 && bank <= MaxBank && bank != 2 && bank != 5); }
    static bool isValidBaseForBank(unsigned bank, unsigned base) { return (base >= BankBaseAddress && base <= 0xFFFF); }

private:
    Program* mProgram;
    Token mToken;
    std::string mName;
    unsigned mBase;
    unsigned mAlignment;
    unsigned mBank;
    bool mHasBase;
    bool mHasAlignment;
    bool mHasBank;

    Q_DISABLE_COPY(ProgramSection)
};

#endif
