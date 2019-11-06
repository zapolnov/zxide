#ifndef COMPILER_PROGRAMOPCODE_H
#define COMPILER_PROGRAMOPCODE_H

#include "AssemblerToken.h"
#include <QByteArray>
#include <memory>
#include <vector>

#ifdef emit
#undef emit
#endif

class IErrorReporter;
class IProgramBinary;
class ProgramSection;
class Program;
class CodeEmitter;
class RepeatedCodeEmitter;
class Expression;

class ProgramOpcode
{
public:
    explicit ProgramOpcode(const Token& token);
    virtual ~ProgramOpcode();

    const Token& token() const { return mToken; }

    virtual unsigned lengthInBytes(const Program* program, IErrorReporter* reporter) const = 0;
    virtual unsigned tstatesIfNotTaken(const Program* program, IErrorReporter* reporter) const = 0;
    virtual unsigned tstatesIfTaken(const Program* program, IErrorReporter* reporter) const = 0;

    virtual bool resolveAddress(quint32& address, Program* program, IErrorReporter* reporter);
    virtual void emitBinary(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const = 0;

private:
    Token mToken;

    Q_DISABLE_COPY(ProgramOpcode)
};

class DEFB final : public ProgramOpcode
{
public:
    DEFB(const Token& token, std::unique_ptr<Expression> value);
    ~DEFB() override;

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 0; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 0; }

    void emitBinary(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mValue;

    Q_DISABLE_COPY(DEFB)
};

class DEFB_STRING final : public ProgramOpcode
{
public:
    DEFB_STRING(const Token& token, std::string text);
    ~DEFB_STRING() override;

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return unsigned(mText.length()); }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 0; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 0; }

    void emitBinary(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::string mText;

    Q_DISABLE_COPY(DEFB_STRING)
};

class DEFB_BYTEARRAY final : public ProgramOpcode
{
public:
    DEFB_BYTEARRAY(const Token& token, const QByteArray& data);
    ~DEFB_BYTEARRAY() override;

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return unsigned(mData.length()); }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 0; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 0; }

    void emitBinary(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    QByteArray mData;

    Q_DISABLE_COPY(DEFB_BYTEARRAY)
};

class DEFW final : public ProgramOpcode
{
public:
    DEFW(const Token& token, std::unique_ptr<Expression> value);
    ~DEFW() override;

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 0; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 0; }

    void emitBinary(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mValue;

    Q_DISABLE_COPY(DEFW)
};

class DEFD final : public ProgramOpcode
{
public:
    DEFD(const Token& token, std::unique_ptr<Expression> value);
    ~DEFD() override;

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 0; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 0; }

    void emitBinary(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mValue;

    Q_DISABLE_COPY(DEFD)
};

class DEFS final : public ProgramOpcode
{
public:
    DEFS(const Token& token, std::unique_ptr<Expression> value);
    ~DEFS() override;

    unsigned lengthInBytes(const Program* program, IErrorReporter* reporter) const final override;
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 0; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 0; }

    void emitBinary(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mValue;

    Q_DISABLE_COPY(DEFS)
};

class IfMacro final : public ProgramOpcode
{
public:
    IfMacro(const Token& token, std::unique_ptr<Expression> condition,
        const std::shared_ptr<CodeEmitter>& thenCodeEmitter, const std::shared_ptr<CodeEmitter>& elseCodeEmitter);
    ~IfMacro() override;

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override;
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override;
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override;

    bool resolveAddress(quint32& address, Program* program, IErrorReporter* reporter) final override;
    void emitBinary(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::weak_ptr<CodeEmitter> mThenCodeEmitter;
    std::weak_ptr<CodeEmitter> mElseCodeEmitter;
    std::unique_ptr<Expression> mCondition;

    CodeEmitter* codeEmitter(const Program* program, IErrorReporter* reporter) const;

    Q_DISABLE_COPY(IfMacro)
};

class RepeatMacro final : public ProgramOpcode
{
public:
    RepeatMacro(const Token& token, const std::shared_ptr<RepeatedCodeEmitter>& codeEmitter);
    ~RepeatMacro() override;

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override;
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override;
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override;

    bool resolveAddress(quint32& address, Program* program, IErrorReporter* reporter) final override;
    void emitBinary(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::weak_ptr<RepeatedCodeEmitter> mCodeEmitter;

    Q_DISABLE_COPY(RepeatMacro)
};

#endif
