#ifndef COMPILER_PROGRAMOPCODE_H
#define COMPILER_PROGRAMOPCODE_H

#include "AssemblerToken.h"
#include <memory>
#include <vector>

#ifdef emit
#undef emit
#endif

class File;
class IErrorReporter;
class ProgramBinary;
class ProgramSection;
class Program;
class RepeatedCodeEmitter;
class Expression;

class ProgramOpcode
{
public:
    explicit ProgramOpcode(const Token& token);
    virtual ~ProgramOpcode();

    const Token& token() const { return mToken; }
    unsigned address() const { Q_ASSERT(mAddress >= 0); return unsigned(mAddress); }

    virtual unsigned lengthInBytes() const = 0;
    virtual unsigned tstatesIfNotTaken() const = 0;
    virtual unsigned tstatesIfTaken() const = 0;

    virtual void resolveAddress(quint32& address, IErrorReporter* reporter);
    virtual void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const = 0;

protected:
    void setAddress(quint32 address);

private:
    Token mToken;
    qint32 mAddress;

    Q_DISABLE_COPY(ProgramOpcode)
};

class DEFB final : public ProgramOpcode
{
public:
    DEFB(const Token& token, std::unique_ptr<Expression> value);
    ~DEFB() override;

    unsigned lengthInBytes() const final override { return 1; }
    unsigned tstatesIfNotTaken() const final override { return 0; }
    unsigned tstatesIfTaken() const final override { return 0; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    Token mToken;
    std::unique_ptr<Expression> mValue;

    Q_DISABLE_COPY(DEFB)
};

class DEFB_STRING final : public ProgramOpcode
{
public:
    DEFB_STRING(const Token& token, std::string text);
    ~DEFB_STRING() override;

    unsigned lengthInBytes() const final override { return unsigned(mText.length()); }
    unsigned tstatesIfNotTaken() const final override { return 0; }
    unsigned tstatesIfTaken() const final override { return 0; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    Token mToken;
    std::string mText;

    Q_DISABLE_COPY(DEFB_STRING)
};

class DEFW final : public ProgramOpcode
{
public:
    DEFW(const Token& token, std::unique_ptr<Expression> value);
    ~DEFW() override;

    unsigned lengthInBytes() const final override { return 2; }
    unsigned tstatesIfNotTaken() const final override { return 0; }
    unsigned tstatesIfTaken() const final override { return 0; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    Token mToken;
    std::unique_ptr<Expression> mValue;

    Q_DISABLE_COPY(DEFW)
};

class DEFD final : public ProgramOpcode
{
public:
    DEFD(const Token& token, std::unique_ptr<Expression> value);
    ~DEFD() override;

    unsigned lengthInBytes() const final override { return 4; }
    unsigned tstatesIfNotTaken() const final override { return 0; }
    unsigned tstatesIfTaken() const final override { return 0; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    Token mToken;
    std::unique_ptr<Expression> mValue;

    Q_DISABLE_COPY(DEFD)
};

class RepeatMacro final : public ProgramOpcode
{
public:
    RepeatMacro(const Token& token, std::shared_ptr<RepeatedCodeEmitter> codeEmitter);
    ~RepeatMacro() override;

    unsigned lengthInBytes() const final override;
    unsigned tstatesIfNotTaken() const final override;
    unsigned tstatesIfTaken() const final override;

    void resolveAddress(quint32& address, IErrorReporter* reporter) final override;
    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    Token mToken;
    std::shared_ptr<RepeatedCodeEmitter> mCodeEmitter;

    Q_DISABLE_COPY(RepeatMacro)
};

#endif
