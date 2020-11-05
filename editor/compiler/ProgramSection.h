#ifndef COMPILER_PROGRAMSECTION_H
#define COMPILER_PROGRAMSECTION_H

#include "CodeEmitter.h"
#include "compiler/AssemblerToken.h"
#include <string>

class Expression;
class IProgramBinary;

enum class Compression
{
    Unspecified,
    None,
    Zx7,
    Lzsa2,
};

class ProgramSection : public CodeEmitter
{
public:
    ProgramSection(Program* program, const Token& token, std::string name);
    ~ProgramSection() override;

    Program* program() const { return mProgram; }

    const std::string& name() const { return mName; }
    const char* nameCStr() const { return mName.c_str(); }
    unsigned bankAddress() const { return mBankAddress; }

    bool hasBase() const { return mBase != nullptr; }
    void setBase(std::unique_ptr<Expression> expr);
    unsigned base(IErrorReporter* reporter) const;

    bool hasAlignment() const { return mAlignment != nullptr; }
    void setAlignment(std::unique_ptr<Expression> expr);
    unsigned alignment(IErrorReporter* reporter) const;

    Compression compression() const { return mCompression; }
    bool isCompressed() const { return mCompression != Compression::None && mCompression != Compression::Unspecified; }
    void setCompression(Compression compression) { mCompression = compression; }

    bool isImaginary() const { return mIsImaginary; }
    void setIsImaginary(bool flag) { mIsImaginary = flag; }

    bool hasFileName() const { return mHasFileName; }
    const std::string& fileName() const { Q_ASSERT(mHasFileName || mFileName.empty()); return mFileName; }
    void setFileName(std::string value) { mFileName = std::move(value); mHasFileName = true; }

    unsigned resolvedBase() const { return mResolvedBase; }
    bool resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address, bool compressed) const override;
    size_t emitCode(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    Program* mProgram;
    Token mToken;
    Compression mCompression;
    std::string mName;
    std::unique_ptr<Expression> mBase;
    std::unique_ptr<Expression> mAlignment;
    std::string mFileName;
    mutable unsigned mResolvedBase;
    mutable unsigned mCalculatedBase;
    mutable unsigned mCalculatedAlignment;
    mutable bool mHasCalculatedBase;
    mutable bool mHasCalculatedAlignment;
    unsigned mBankAddress;
    bool mHasFileName;
    bool mIsImaginary;

    Q_DISABLE_COPY(ProgramSection)
};

#endif
