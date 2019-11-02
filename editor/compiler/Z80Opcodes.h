// THIS IS A GENERATED FILE. DO NOT EDIT!
#ifndef COMPILER_Z80OPCODES_H
#define COMPILER_Z80OPCODES_H

#include "ProgramOpcode.h"
#include "Expression.h"
#include <memory>

class ADC_A_A final : public ProgramOpcode
{
public:
    ADC_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_A)
};

class ADC_A_B final : public ProgramOpcode
{
public:
    ADC_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_B)
};

class ADC_A_C final : public ProgramOpcode
{
public:
    ADC_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_C)
};

class ADC_A_D final : public ProgramOpcode
{
public:
    ADC_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_D)
};

class ADC_A_E final : public ProgramOpcode
{
public:
    ADC_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_E)
};

class ADC_A_H final : public ProgramOpcode
{
public:
    ADC_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_H)
};

class ADC_A_L final : public ProgramOpcode
{
public:
    ADC_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_L)
};

class ADC_A_n final : public ProgramOpcode
{
public:
    ADC_A_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(ADC_A_n)
};

class ADC_A_mHL final : public ProgramOpcode
{
public:
    ADC_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_mHL)
};

class ADC_A_IXH final : public ProgramOpcode
{
public:
    ADC_A_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_IXH)
};

class ADC_A_IYH final : public ProgramOpcode
{
public:
    ADC_A_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_IYH)
};

class ADC_A_IXL final : public ProgramOpcode
{
public:
    ADC_A_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_IXL)
};

class ADC_A_IYL final : public ProgramOpcode
{
public:
    ADC_A_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_A_IYL)
};

class ADC_A_mIXn final : public ProgramOpcode
{
public:
    ADC_A_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(ADC_A_mIXn)
};

class ADC_A_mIYn final : public ProgramOpcode
{
public:
    ADC_A_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(ADC_A_mIYn)
};

class ADC_HL_BC final : public ProgramOpcode
{
public:
    ADC_HL_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_HL_BC)
};

class ADC_HL_DE final : public ProgramOpcode
{
public:
    ADC_HL_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_HL_DE)
};

class ADC_HL_HL final : public ProgramOpcode
{
public:
    ADC_HL_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_HL_HL)
};

class ADC_HL_SP final : public ProgramOpcode
{
public:
    ADC_HL_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADC_HL_SP)
};

class ADD_A_A final : public ProgramOpcode
{
public:
    ADD_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_A)
};

class ADD_A_B final : public ProgramOpcode
{
public:
    ADD_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_B)
};

class ADD_A_C final : public ProgramOpcode
{
public:
    ADD_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_C)
};

class ADD_A_D final : public ProgramOpcode
{
public:
    ADD_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_D)
};

class ADD_A_E final : public ProgramOpcode
{
public:
    ADD_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_E)
};

class ADD_A_H final : public ProgramOpcode
{
public:
    ADD_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_H)
};

class ADD_A_L final : public ProgramOpcode
{
public:
    ADD_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_L)
};

class ADD_A_n final : public ProgramOpcode
{
public:
    ADD_A_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(ADD_A_n)
};

class ADD_A_mHL final : public ProgramOpcode
{
public:
    ADD_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_mHL)
};

class ADD_A_IXH final : public ProgramOpcode
{
public:
    ADD_A_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_IXH)
};

class ADD_A_IYH final : public ProgramOpcode
{
public:
    ADD_A_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_IYH)
};

class ADD_A_IXL final : public ProgramOpcode
{
public:
    ADD_A_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_IXL)
};

class ADD_A_IYL final : public ProgramOpcode
{
public:
    ADD_A_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_A_IYL)
};

class ADD_A_mIXn final : public ProgramOpcode
{
public:
    ADD_A_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(ADD_A_mIXn)
};

class ADD_A_mIYn final : public ProgramOpcode
{
public:
    ADD_A_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(ADD_A_mIYn)
};

class ADD_HL_BC final : public ProgramOpcode
{
public:
    ADD_HL_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_HL_BC)
};

class ADD_HL_DE final : public ProgramOpcode
{
public:
    ADD_HL_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_HL_DE)
};

class ADD_HL_HL final : public ProgramOpcode
{
public:
    ADD_HL_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_HL_HL)
};

class ADD_HL_SP final : public ProgramOpcode
{
public:
    ADD_HL_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_HL_SP)
};

class ADD_IX_BC final : public ProgramOpcode
{
public:
    ADD_IX_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_IX_BC)
};

class ADD_IX_DE final : public ProgramOpcode
{
public:
    ADD_IX_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_IX_DE)
};

class ADD_IX_IX final : public ProgramOpcode
{
public:
    ADD_IX_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_IX_IX)
};

class ADD_IX_SP final : public ProgramOpcode
{
public:
    ADD_IX_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_IX_SP)
};

class ADD_IY_BC final : public ProgramOpcode
{
public:
    ADD_IY_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_IY_BC)
};

class ADD_IY_DE final : public ProgramOpcode
{
public:
    ADD_IY_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_IY_DE)
};

class ADD_IY_IY final : public ProgramOpcode
{
public:
    ADD_IY_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_IY_IY)
};

class ADD_IY_SP final : public ProgramOpcode
{
public:
    ADD_IY_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(ADD_IY_SP)
};

class AND_A final : public ProgramOpcode
{
public:
    AND_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A)
};

class AND_A_A final : public ProgramOpcode
{
public:
    AND_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_A)
};

class AND_B final : public ProgramOpcode
{
public:
    AND_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_B)
};

class AND_A_B final : public ProgramOpcode
{
public:
    AND_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_B)
};

class AND_C final : public ProgramOpcode
{
public:
    AND_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_C)
};

class AND_A_C final : public ProgramOpcode
{
public:
    AND_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_C)
};

class AND_D final : public ProgramOpcode
{
public:
    AND_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_D)
};

class AND_A_D final : public ProgramOpcode
{
public:
    AND_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_D)
};

class AND_E final : public ProgramOpcode
{
public:
    AND_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_E)
};

class AND_A_E final : public ProgramOpcode
{
public:
    AND_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_E)
};

class AND_H final : public ProgramOpcode
{
public:
    AND_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_H)
};

class AND_A_H final : public ProgramOpcode
{
public:
    AND_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_H)
};

class AND_L final : public ProgramOpcode
{
public:
    AND_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_L)
};

class AND_A_L final : public ProgramOpcode
{
public:
    AND_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_L)
};

class AND_n final : public ProgramOpcode
{
public:
    AND_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(AND_n)
};

class AND_A_n final : public ProgramOpcode
{
public:
    AND_A_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(AND_A_n)
};

class AND_mHL final : public ProgramOpcode
{
public:
    AND_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_mHL)
};

class AND_A_mHL final : public ProgramOpcode
{
public:
    AND_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_mHL)
};

class AND_mIXn final : public ProgramOpcode
{
public:
    AND_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(AND_mIXn)
};

class AND_A_mIXn final : public ProgramOpcode
{
public:
    AND_A_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(AND_A_mIXn)
};

class AND_mIYn final : public ProgramOpcode
{
public:
    AND_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(AND_mIYn)
};

class AND_A_mIYn final : public ProgramOpcode
{
public:
    AND_A_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(AND_A_mIYn)
};

class AND_IXH final : public ProgramOpcode
{
public:
    AND_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_IXH)
};

class AND_A_IXH final : public ProgramOpcode
{
public:
    AND_A_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_IXH)
};

class AND_IYH final : public ProgramOpcode
{
public:
    AND_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_IYH)
};

class AND_A_IYH final : public ProgramOpcode
{
public:
    AND_A_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_IYH)
};

class AND_IXL final : public ProgramOpcode
{
public:
    AND_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_IXL)
};

class AND_A_IXL final : public ProgramOpcode
{
public:
    AND_A_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_IXL)
};

class AND_IYL final : public ProgramOpcode
{
public:
    AND_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_IYL)
};

class AND_A_IYL final : public ProgramOpcode
{
public:
    AND_A_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(AND_A_IYL)
};

class BIT_0_mHL final : public ProgramOpcode
{
public:
    BIT_0_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_0_mHL)
};

class BIT_1_mHL final : public ProgramOpcode
{
public:
    BIT_1_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_1_mHL)
};

class BIT_2_mHL final : public ProgramOpcode
{
public:
    BIT_2_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_2_mHL)
};

class BIT_3_mHL final : public ProgramOpcode
{
public:
    BIT_3_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_3_mHL)
};

class BIT_4_mHL final : public ProgramOpcode
{
public:
    BIT_4_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_4_mHL)
};

class BIT_5_mHL final : public ProgramOpcode
{
public:
    BIT_5_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_5_mHL)
};

class BIT_6_mHL final : public ProgramOpcode
{
public:
    BIT_6_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_6_mHL)
};

class BIT_7_mHL final : public ProgramOpcode
{
public:
    BIT_7_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_7_mHL)
};

class BIT_0_mIXn final : public ProgramOpcode
{
public:
    BIT_0_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_0_mIXn)
};

class BIT_1_mIXn final : public ProgramOpcode
{
public:
    BIT_1_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_1_mIXn)
};

class BIT_2_mIXn final : public ProgramOpcode
{
public:
    BIT_2_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_2_mIXn)
};

class BIT_3_mIXn final : public ProgramOpcode
{
public:
    BIT_3_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_3_mIXn)
};

class BIT_4_mIXn final : public ProgramOpcode
{
public:
    BIT_4_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_4_mIXn)
};

class BIT_5_mIXn final : public ProgramOpcode
{
public:
    BIT_5_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_5_mIXn)
};

class BIT_6_mIXn final : public ProgramOpcode
{
public:
    BIT_6_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_6_mIXn)
};

class BIT_7_mIXn final : public ProgramOpcode
{
public:
    BIT_7_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_7_mIXn)
};

class BIT_0_mIYn final : public ProgramOpcode
{
public:
    BIT_0_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_0_mIYn)
};

class BIT_1_mIYn final : public ProgramOpcode
{
public:
    BIT_1_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_1_mIYn)
};

class BIT_2_mIYn final : public ProgramOpcode
{
public:
    BIT_2_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_2_mIYn)
};

class BIT_3_mIYn final : public ProgramOpcode
{
public:
    BIT_3_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_3_mIYn)
};

class BIT_4_mIYn final : public ProgramOpcode
{
public:
    BIT_4_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_4_mIYn)
};

class BIT_5_mIYn final : public ProgramOpcode
{
public:
    BIT_5_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_5_mIYn)
};

class BIT_6_mIYn final : public ProgramOpcode
{
public:
    BIT_6_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_6_mIYn)
};

class BIT_7_mIYn final : public ProgramOpcode
{
public:
    BIT_7_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(BIT_7_mIYn)
};

class BIT_0_A final : public ProgramOpcode
{
public:
    BIT_0_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_0_A)
};

class BIT_0_B final : public ProgramOpcode
{
public:
    BIT_0_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_0_B)
};

class BIT_0_C final : public ProgramOpcode
{
public:
    BIT_0_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_0_C)
};

class BIT_0_D final : public ProgramOpcode
{
public:
    BIT_0_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_0_D)
};

class BIT_0_E final : public ProgramOpcode
{
public:
    BIT_0_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_0_E)
};

class BIT_0_H final : public ProgramOpcode
{
public:
    BIT_0_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_0_H)
};

class BIT_0_L final : public ProgramOpcode
{
public:
    BIT_0_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_0_L)
};

class BIT_1_A final : public ProgramOpcode
{
public:
    BIT_1_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_1_A)
};

class BIT_1_B final : public ProgramOpcode
{
public:
    BIT_1_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_1_B)
};

class BIT_1_C final : public ProgramOpcode
{
public:
    BIT_1_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_1_C)
};

class BIT_1_D final : public ProgramOpcode
{
public:
    BIT_1_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_1_D)
};

class BIT_1_E final : public ProgramOpcode
{
public:
    BIT_1_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_1_E)
};

class BIT_1_H final : public ProgramOpcode
{
public:
    BIT_1_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_1_H)
};

class BIT_1_L final : public ProgramOpcode
{
public:
    BIT_1_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_1_L)
};

class BIT_2_A final : public ProgramOpcode
{
public:
    BIT_2_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_2_A)
};

class BIT_2_B final : public ProgramOpcode
{
public:
    BIT_2_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_2_B)
};

class BIT_2_C final : public ProgramOpcode
{
public:
    BIT_2_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_2_C)
};

class BIT_2_D final : public ProgramOpcode
{
public:
    BIT_2_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_2_D)
};

class BIT_2_E final : public ProgramOpcode
{
public:
    BIT_2_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_2_E)
};

class BIT_2_H final : public ProgramOpcode
{
public:
    BIT_2_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_2_H)
};

class BIT_2_L final : public ProgramOpcode
{
public:
    BIT_2_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_2_L)
};

class BIT_3_A final : public ProgramOpcode
{
public:
    BIT_3_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_3_A)
};

class BIT_3_B final : public ProgramOpcode
{
public:
    BIT_3_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_3_B)
};

class BIT_3_C final : public ProgramOpcode
{
public:
    BIT_3_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_3_C)
};

class BIT_3_D final : public ProgramOpcode
{
public:
    BIT_3_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_3_D)
};

class BIT_3_E final : public ProgramOpcode
{
public:
    BIT_3_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_3_E)
};

class BIT_3_H final : public ProgramOpcode
{
public:
    BIT_3_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_3_H)
};

class BIT_3_L final : public ProgramOpcode
{
public:
    BIT_3_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_3_L)
};

class BIT_4_A final : public ProgramOpcode
{
public:
    BIT_4_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_4_A)
};

class BIT_4_B final : public ProgramOpcode
{
public:
    BIT_4_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_4_B)
};

class BIT_4_C final : public ProgramOpcode
{
public:
    BIT_4_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_4_C)
};

class BIT_4_D final : public ProgramOpcode
{
public:
    BIT_4_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_4_D)
};

class BIT_4_E final : public ProgramOpcode
{
public:
    BIT_4_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_4_E)
};

class BIT_4_H final : public ProgramOpcode
{
public:
    BIT_4_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_4_H)
};

class BIT_4_L final : public ProgramOpcode
{
public:
    BIT_4_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_4_L)
};

class BIT_5_A final : public ProgramOpcode
{
public:
    BIT_5_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_5_A)
};

class BIT_5_B final : public ProgramOpcode
{
public:
    BIT_5_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_5_B)
};

class BIT_5_C final : public ProgramOpcode
{
public:
    BIT_5_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_5_C)
};

class BIT_5_D final : public ProgramOpcode
{
public:
    BIT_5_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_5_D)
};

class BIT_5_E final : public ProgramOpcode
{
public:
    BIT_5_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_5_E)
};

class BIT_5_H final : public ProgramOpcode
{
public:
    BIT_5_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_5_H)
};

class BIT_5_L final : public ProgramOpcode
{
public:
    BIT_5_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_5_L)
};

class BIT_6_A final : public ProgramOpcode
{
public:
    BIT_6_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_6_A)
};

class BIT_6_B final : public ProgramOpcode
{
public:
    BIT_6_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_6_B)
};

class BIT_6_C final : public ProgramOpcode
{
public:
    BIT_6_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_6_C)
};

class BIT_6_D final : public ProgramOpcode
{
public:
    BIT_6_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_6_D)
};

class BIT_6_E final : public ProgramOpcode
{
public:
    BIT_6_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_6_E)
};

class BIT_6_H final : public ProgramOpcode
{
public:
    BIT_6_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_6_H)
};

class BIT_6_L final : public ProgramOpcode
{
public:
    BIT_6_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_6_L)
};

class BIT_7_A final : public ProgramOpcode
{
public:
    BIT_7_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_7_A)
};

class BIT_7_B final : public ProgramOpcode
{
public:
    BIT_7_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_7_B)
};

class BIT_7_C final : public ProgramOpcode
{
public:
    BIT_7_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_7_C)
};

class BIT_7_D final : public ProgramOpcode
{
public:
    BIT_7_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_7_D)
};

class BIT_7_E final : public ProgramOpcode
{
public:
    BIT_7_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_7_E)
};

class BIT_7_H final : public ProgramOpcode
{
public:
    BIT_7_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_7_H)
};

class BIT_7_L final : public ProgramOpcode
{
public:
    BIT_7_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(BIT_7_L)
};

class CALL_nn final : public ProgramOpcode
{
public:
    CALL_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 17; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 17; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CALL_nn)
};

class CALL_C_nn final : public ProgramOpcode
{
public:
    CALL_C_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 17; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CALL_C_nn)
};

class CALL_M_nn final : public ProgramOpcode
{
public:
    CALL_M_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 17; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CALL_M_nn)
};

class CALL_NC_nn final : public ProgramOpcode
{
public:
    CALL_NC_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 17; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CALL_NC_nn)
};

class CALL_NZ_nn final : public ProgramOpcode
{
public:
    CALL_NZ_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 17; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CALL_NZ_nn)
};

class CALL_P_nn final : public ProgramOpcode
{
public:
    CALL_P_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 17; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CALL_P_nn)
};

class CALL_PE_nn final : public ProgramOpcode
{
public:
    CALL_PE_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 17; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CALL_PE_nn)
};

class CALL_PO_nn final : public ProgramOpcode
{
public:
    CALL_PO_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 17; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CALL_PO_nn)
};

class CALL_Z_nn final : public ProgramOpcode
{
public:
    CALL_Z_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 17; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CALL_Z_nn)
};

class CCF final : public ProgramOpcode
{
public:
    CCF(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CCF)
};

class CP_A final : public ProgramOpcode
{
public:
    CP_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A)
};

class CP_A_A final : public ProgramOpcode
{
public:
    CP_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_A)
};

class CP_B final : public ProgramOpcode
{
public:
    CP_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_B)
};

class CP_A_B final : public ProgramOpcode
{
public:
    CP_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_B)
};

class CP_C final : public ProgramOpcode
{
public:
    CP_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_C)
};

class CP_A_C final : public ProgramOpcode
{
public:
    CP_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_C)
};

class CP_D final : public ProgramOpcode
{
public:
    CP_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_D)
};

class CP_A_D final : public ProgramOpcode
{
public:
    CP_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_D)
};

class CP_E final : public ProgramOpcode
{
public:
    CP_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_E)
};

class CP_A_E final : public ProgramOpcode
{
public:
    CP_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_E)
};

class CP_H final : public ProgramOpcode
{
public:
    CP_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_H)
};

class CP_A_H final : public ProgramOpcode
{
public:
    CP_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_H)
};

class CP_L final : public ProgramOpcode
{
public:
    CP_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_L)
};

class CP_A_L final : public ProgramOpcode
{
public:
    CP_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_L)
};

class CP_n final : public ProgramOpcode
{
public:
    CP_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CP_n)
};

class CP_A_n final : public ProgramOpcode
{
public:
    CP_A_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CP_A_n)
};

class CP_mHL final : public ProgramOpcode
{
public:
    CP_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_mHL)
};

class CP_A_mHL final : public ProgramOpcode
{
public:
    CP_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_mHL)
};

class CP_mIXn final : public ProgramOpcode
{
public:
    CP_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CP_mIXn)
};

class CP_A_mIXn final : public ProgramOpcode
{
public:
    CP_A_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CP_A_mIXn)
};

class CP_mIYn final : public ProgramOpcode
{
public:
    CP_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CP_mIYn)
};

class CP_A_mIYn final : public ProgramOpcode
{
public:
    CP_A_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(CP_A_mIYn)
};

class CP_IXH final : public ProgramOpcode
{
public:
    CP_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_IXH)
};

class CP_A_IXH final : public ProgramOpcode
{
public:
    CP_A_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_IXH)
};

class CP_IYH final : public ProgramOpcode
{
public:
    CP_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_IYH)
};

class CP_A_IYH final : public ProgramOpcode
{
public:
    CP_A_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_IYH)
};

class CP_IXL final : public ProgramOpcode
{
public:
    CP_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_IXL)
};

class CP_A_IXL final : public ProgramOpcode
{
public:
    CP_A_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_IXL)
};

class CP_IYL final : public ProgramOpcode
{
public:
    CP_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_IYL)
};

class CP_A_IYL final : public ProgramOpcode
{
public:
    CP_A_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CP_A_IYL)
};

class CPD final : public ProgramOpcode
{
public:
    CPD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CPD)
};

class CPDR final : public ProgramOpcode
{
public:
    CPDR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 21; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CPDR)
};

class CPI final : public ProgramOpcode
{
public:
    CPI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CPI)
};

class CPIR final : public ProgramOpcode
{
public:
    CPIR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 21; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CPIR)
};

class CPL final : public ProgramOpcode
{
public:
    CPL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(CPL)
};

class DAA final : public ProgramOpcode
{
public:
    DAA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DAA)
};

class DEC_A final : public ProgramOpcode
{
public:
    DEC_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_A)
};

class DEC_B final : public ProgramOpcode
{
public:
    DEC_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_B)
};

class DEC_C final : public ProgramOpcode
{
public:
    DEC_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_C)
};

class DEC_D final : public ProgramOpcode
{
public:
    DEC_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_D)
};

class DEC_E final : public ProgramOpcode
{
public:
    DEC_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_E)
};

class DEC_H final : public ProgramOpcode
{
public:
    DEC_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_H)
};

class DEC_L final : public ProgramOpcode
{
public:
    DEC_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_L)
};

class DEC_mHL final : public ProgramOpcode
{
public:
    DEC_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_mHL)
};

class DEC_mIXn final : public ProgramOpcode
{
public:
    DEC_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(DEC_mIXn)
};

class DEC_mIYn final : public ProgramOpcode
{
public:
    DEC_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(DEC_mIYn)
};

class DEC_IX final : public ProgramOpcode
{
public:
    DEC_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_IX)
};

class DEC_IY final : public ProgramOpcode
{
public:
    DEC_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_IY)
};

class DEC_BC final : public ProgramOpcode
{
public:
    DEC_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 6; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 6; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_BC)
};

class DEC_DE final : public ProgramOpcode
{
public:
    DEC_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 6; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 6; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_DE)
};

class DEC_HL final : public ProgramOpcode
{
public:
    DEC_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 6; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 6; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_HL)
};

class DEC_SP final : public ProgramOpcode
{
public:
    DEC_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 6; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 6; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_SP)
};

class DEC_IXH final : public ProgramOpcode
{
public:
    DEC_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_IXH)
};

class DEC_IYH final : public ProgramOpcode
{
public:
    DEC_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_IYH)
};

class DEC_IXL final : public ProgramOpcode
{
public:
    DEC_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_IXL)
};

class DEC_IYL final : public ProgramOpcode
{
public:
    DEC_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DEC_IYL)
};

class DI final : public ProgramOpcode
{
public:
    DI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(DI)
};

class DJNZ_off final : public ProgramOpcode
{
public:
    DJNZ_off(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 13; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(DJNZ_off)
};

class EI final : public ProgramOpcode
{
public:
    EI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(EI)
};

class EX_mSP_HL final : public ProgramOpcode
{
public:
    EX_mSP_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(EX_mSP_HL)
};

class EX_mSP_IX final : public ProgramOpcode
{
public:
    EX_mSP_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(EX_mSP_IX)
};

class EX_mSP_IY final : public ProgramOpcode
{
public:
    EX_mSP_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(EX_mSP_IY)
};

class EX_AF_AFs final : public ProgramOpcode
{
public:
    EX_AF_AFs(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(EX_AF_AFs)
};

class EX_DE_HL final : public ProgramOpcode
{
public:
    EX_DE_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(EX_DE_HL)
};

class EXX final : public ProgramOpcode
{
public:
    EXX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(EXX)
};

class HALT final : public ProgramOpcode
{
public:
    HALT(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(HALT)
};

class IM_0 final : public ProgramOpcode
{
public:
    IM_0(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IM_0)
};

class IM_1 final : public ProgramOpcode
{
public:
    IM_1(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IM_1)
};

class IM_2 final : public ProgramOpcode
{
public:
    IM_2(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IM_2)
};

class IN_A_mn final : public ProgramOpcode
{
public:
    IN_A_mn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(IN_A_mn)
};

class IN_A_mC final : public ProgramOpcode
{
public:
    IN_A_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IN_A_mC)
};

class IN_B_mC final : public ProgramOpcode
{
public:
    IN_B_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IN_B_mC)
};

class IN_C_mC final : public ProgramOpcode
{
public:
    IN_C_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IN_C_mC)
};

class IN_D_mC final : public ProgramOpcode
{
public:
    IN_D_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IN_D_mC)
};

class IN_E_mC final : public ProgramOpcode
{
public:
    IN_E_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IN_E_mC)
};

class IN_H_mC final : public ProgramOpcode
{
public:
    IN_H_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IN_H_mC)
};

class IN_L_mC final : public ProgramOpcode
{
public:
    IN_L_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IN_L_mC)
};

class INC_A final : public ProgramOpcode
{
public:
    INC_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_A)
};

class INC_B final : public ProgramOpcode
{
public:
    INC_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_B)
};

class INC_C final : public ProgramOpcode
{
public:
    INC_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_C)
};

class INC_D final : public ProgramOpcode
{
public:
    INC_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_D)
};

class INC_E final : public ProgramOpcode
{
public:
    INC_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_E)
};

class INC_H final : public ProgramOpcode
{
public:
    INC_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_H)
};

class INC_L final : public ProgramOpcode
{
public:
    INC_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_L)
};

class INC_mHL final : public ProgramOpcode
{
public:
    INC_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_mHL)
};

class INC_mIXn final : public ProgramOpcode
{
public:
    INC_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(INC_mIXn)
};

class INC_mIYn final : public ProgramOpcode
{
public:
    INC_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(INC_mIYn)
};

class INC_IX final : public ProgramOpcode
{
public:
    INC_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_IX)
};

class INC_IY final : public ProgramOpcode
{
public:
    INC_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_IY)
};

class INC_BC final : public ProgramOpcode
{
public:
    INC_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 6; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 6; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_BC)
};

class INC_DE final : public ProgramOpcode
{
public:
    INC_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 6; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 6; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_DE)
};

class INC_HL final : public ProgramOpcode
{
public:
    INC_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 6; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 6; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_HL)
};

class INC_SP final : public ProgramOpcode
{
public:
    INC_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 6; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 6; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_SP)
};

class INC_IXH final : public ProgramOpcode
{
public:
    INC_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_IXH)
};

class INC_IYH final : public ProgramOpcode
{
public:
    INC_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_IYH)
};

class INC_IXL final : public ProgramOpcode
{
public:
    INC_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_IXL)
};

class INC_IYL final : public ProgramOpcode
{
public:
    INC_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INC_IYL)
};

class IND final : public ProgramOpcode
{
public:
    IND(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(IND)
};

class INDR final : public ProgramOpcode
{
public:
    INDR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 21; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INDR)
};

class INI final : public ProgramOpcode
{
public:
    INI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INI)
};

class INIR final : public ProgramOpcode
{
public:
    INIR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 21; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(INIR)
};

class JP_nn final : public ProgramOpcode
{
public:
    JP_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JP_nn)
};

class JP_C_nn final : public ProgramOpcode
{
public:
    JP_C_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JP_C_nn)
};

class JP_M_nn final : public ProgramOpcode
{
public:
    JP_M_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JP_M_nn)
};

class JP_NC_nn final : public ProgramOpcode
{
public:
    JP_NC_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JP_NC_nn)
};

class JP_NZ_nn final : public ProgramOpcode
{
public:
    JP_NZ_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JP_NZ_nn)
};

class JP_P_nn final : public ProgramOpcode
{
public:
    JP_P_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JP_P_nn)
};

class JP_PE_nn final : public ProgramOpcode
{
public:
    JP_PE_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JP_PE_nn)
};

class JP_PO_nn final : public ProgramOpcode
{
public:
    JP_PO_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JP_PO_nn)
};

class JP_Z_nn final : public ProgramOpcode
{
public:
    JP_Z_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JP_Z_nn)
};

class JP_mHL final : public ProgramOpcode
{
public:
    JP_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(JP_mHL)
};

class JP_mIX final : public ProgramOpcode
{
public:
    JP_mIX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(JP_mIX)
};

class JP_mIY final : public ProgramOpcode
{
public:
    JP_mIY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(JP_mIY)
};

class JR_off final : public ProgramOpcode
{
public:
    JR_off(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JR_off)
};

class JR_C_off final : public ProgramOpcode
{
public:
    JR_C_off(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JR_C_off)
};

class JR_NC_off final : public ProgramOpcode
{
public:
    JR_NC_off(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JR_NC_off)
};

class JR_NZ_off final : public ProgramOpcode
{
public:
    JR_NZ_off(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JR_NZ_off)
};

class JR_Z_off final : public ProgramOpcode
{
public:
    JR_Z_off(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(JR_Z_off)
};

class LD_A_mBC final : public ProgramOpcode
{
public:
    LD_A_mBC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_mBC)
};

class LD_A_mDE final : public ProgramOpcode
{
public:
    LD_A_mDE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_mDE)
};

class LD_A_I final : public ProgramOpcode
{
public:
    LD_A_I(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 9; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 9; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_I)
};

class LD_A_mnn final : public ProgramOpcode
{
public:
    LD_A_mnn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 13; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 13; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_A_mnn)
};

class LD_A_R final : public ProgramOpcode
{
public:
    LD_A_R(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 9; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 9; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_R)
};

class LD_mBC_A final : public ProgramOpcode
{
public:
    LD_mBC_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_mBC_A)
};

class LD_mDE_A final : public ProgramOpcode
{
public:
    LD_mDE_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_mDE_A)
};

class LD_mHL_n final : public ProgramOpcode
{
public:
    LD_mHL_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mHL_n)
};

class LD_mIXn_n final : public ProgramOpcode
{
public:
    LD_mIXn_n(const Token& token, std::unique_ptr<Expression> literal1, std::unique_ptr<Expression> literal2)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
        , mLiteral2(std::move(literal2))
    {
        Q_ASSERT(mLiteral1 != nullptr);
        Q_ASSERT(mLiteral2 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;
    std::unique_ptr<Expression> mLiteral2;

    Q_DISABLE_COPY(LD_mIXn_n)
};

class LD_mIYn_n final : public ProgramOpcode
{
public:
    LD_mIYn_n(const Token& token, std::unique_ptr<Expression> literal1, std::unique_ptr<Expression> literal2)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
        , mLiteral2(std::move(literal2))
    {
        Q_ASSERT(mLiteral1 != nullptr);
        Q_ASSERT(mLiteral2 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;
    std::unique_ptr<Expression> mLiteral2;

    Q_DISABLE_COPY(LD_mIYn_n)
};

class LD_mnn_A final : public ProgramOpcode
{
public:
    LD_mnn_A(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 13; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 13; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mnn_A)
};

class LD_mnn_BC final : public ProgramOpcode
{
public:
    LD_mnn_BC(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mnn_BC)
};

class LD_mnn_DE final : public ProgramOpcode
{
public:
    LD_mnn_DE(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mnn_DE)
};

class LD_mnn_HL final : public ProgramOpcode
{
public:
    LD_mnn_HL(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mnn_HL)
};

class LD_mnn_SP final : public ProgramOpcode
{
public:
    LD_mnn_SP(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mnn_SP)
};

class LD_mnn_IX final : public ProgramOpcode
{
public:
    LD_mnn_IX(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mnn_IX)
};

class LD_mnn_IY final : public ProgramOpcode
{
public:
    LD_mnn_IY(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mnn_IY)
};

class LD_BC_nn final : public ProgramOpcode
{
public:
    LD_BC_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_BC_nn)
};

class LD_DE_nn final : public ProgramOpcode
{
public:
    LD_DE_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_DE_nn)
};

class LD_HL_nn final : public ProgramOpcode
{
public:
    LD_HL_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_HL_nn)
};

class LD_SP_nn final : public ProgramOpcode
{
public:
    LD_SP_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_SP_nn)
};

class LD_BC_mnn final : public ProgramOpcode
{
public:
    LD_BC_mnn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_BC_mnn)
};

class LD_DE_mnn final : public ProgramOpcode
{
public:
    LD_DE_mnn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_DE_mnn)
};

class LD_HL_mnn final : public ProgramOpcode
{
public:
    LD_HL_mnn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_HL_mnn)
};

class LD_SP_mnn final : public ProgramOpcode
{
public:
    LD_SP_mnn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_SP_mnn)
};

class LD_mHL_A final : public ProgramOpcode
{
public:
    LD_mHL_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_mHL_A)
};

class LD_mHL_B final : public ProgramOpcode
{
public:
    LD_mHL_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_mHL_B)
};

class LD_mHL_C final : public ProgramOpcode
{
public:
    LD_mHL_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_mHL_C)
};

class LD_mHL_D final : public ProgramOpcode
{
public:
    LD_mHL_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_mHL_D)
};

class LD_mHL_E final : public ProgramOpcode
{
public:
    LD_mHL_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_mHL_E)
};

class LD_mHL_H final : public ProgramOpcode
{
public:
    LD_mHL_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_mHL_H)
};

class LD_mHL_L final : public ProgramOpcode
{
public:
    LD_mHL_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_mHL_L)
};

class LD_mIXn_A final : public ProgramOpcode
{
public:
    LD_mIXn_A(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_A)
};

class LD_mIXn_B final : public ProgramOpcode
{
public:
    LD_mIXn_B(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_B)
};

class LD_mIXn_C final : public ProgramOpcode
{
public:
    LD_mIXn_C(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_C)
};

class LD_mIXn_D final : public ProgramOpcode
{
public:
    LD_mIXn_D(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_D)
};

class LD_mIXn_E final : public ProgramOpcode
{
public:
    LD_mIXn_E(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_E)
};

class LD_mIXn_H final : public ProgramOpcode
{
public:
    LD_mIXn_H(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_H)
};

class LD_mIXn_L final : public ProgramOpcode
{
public:
    LD_mIXn_L(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_L)
};

class LD_mIYn_A final : public ProgramOpcode
{
public:
    LD_mIYn_A(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_A)
};

class LD_mIYn_B final : public ProgramOpcode
{
public:
    LD_mIYn_B(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_B)
};

class LD_mIYn_C final : public ProgramOpcode
{
public:
    LD_mIYn_C(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_C)
};

class LD_mIYn_D final : public ProgramOpcode
{
public:
    LD_mIYn_D(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_D)
};

class LD_mIYn_E final : public ProgramOpcode
{
public:
    LD_mIYn_E(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_E)
};

class LD_mIYn_H final : public ProgramOpcode
{
public:
    LD_mIYn_H(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_H)
};

class LD_mIYn_L final : public ProgramOpcode
{
public:
    LD_mIYn_L(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_L)
};

class LD_I_A final : public ProgramOpcode
{
public:
    LD_I_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 9; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 9; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_I_A)
};

class LD_IX_nn final : public ProgramOpcode
{
public:
    LD_IX_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 14; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 14; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_IX_nn)
};

class LD_IX_mnn final : public ProgramOpcode
{
public:
    LD_IX_mnn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_IX_mnn)
};

class LD_IY_nn final : public ProgramOpcode
{
public:
    LD_IY_nn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 14; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 14; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_IY_nn)
};

class LD_IY_mnn final : public ProgramOpcode
{
public:
    LD_IY_mnn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 20; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 20; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_IY_mnn)
};

class LD_R_A final : public ProgramOpcode
{
public:
    LD_R_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 9; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 9; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_R_A)
};

class LD_A_mHL final : public ProgramOpcode
{
public:
    LD_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_mHL)
};

class LD_B_mHL final : public ProgramOpcode
{
public:
    LD_B_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_mHL)
};

class LD_C_mHL final : public ProgramOpcode
{
public:
    LD_C_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_mHL)
};

class LD_D_mHL final : public ProgramOpcode
{
public:
    LD_D_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_mHL)
};

class LD_E_mHL final : public ProgramOpcode
{
public:
    LD_E_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_mHL)
};

class LD_H_mHL final : public ProgramOpcode
{
public:
    LD_H_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_H_mHL)
};

class LD_L_mHL final : public ProgramOpcode
{
public:
    LD_L_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_L_mHL)
};

class LD_A_mIXn final : public ProgramOpcode
{
public:
    LD_A_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_A_mIXn)
};

class LD_B_mIXn final : public ProgramOpcode
{
public:
    LD_B_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_B_mIXn)
};

class LD_C_mIXn final : public ProgramOpcode
{
public:
    LD_C_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_C_mIXn)
};

class LD_D_mIXn final : public ProgramOpcode
{
public:
    LD_D_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_D_mIXn)
};

class LD_E_mIXn final : public ProgramOpcode
{
public:
    LD_E_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_E_mIXn)
};

class LD_H_mIXn final : public ProgramOpcode
{
public:
    LD_H_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_H_mIXn)
};

class LD_L_mIXn final : public ProgramOpcode
{
public:
    LD_L_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_L_mIXn)
};

class LD_A_mIYn final : public ProgramOpcode
{
public:
    LD_A_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_A_mIYn)
};

class LD_B_mIYn final : public ProgramOpcode
{
public:
    LD_B_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_B_mIYn)
};

class LD_C_mIYn final : public ProgramOpcode
{
public:
    LD_C_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_C_mIYn)
};

class LD_D_mIYn final : public ProgramOpcode
{
public:
    LD_D_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_D_mIYn)
};

class LD_E_mIYn final : public ProgramOpcode
{
public:
    LD_E_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_E_mIYn)
};

class LD_H_mIYn final : public ProgramOpcode
{
public:
    LD_H_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_H_mIYn)
};

class LD_L_mIYn final : public ProgramOpcode
{
public:
    LD_L_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_L_mIYn)
};

class LD_A_n final : public ProgramOpcode
{
public:
    LD_A_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_A_n)
};

class LD_B_n final : public ProgramOpcode
{
public:
    LD_B_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_B_n)
};

class LD_C_n final : public ProgramOpcode
{
public:
    LD_C_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_C_n)
};

class LD_D_n final : public ProgramOpcode
{
public:
    LD_D_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_D_n)
};

class LD_E_n final : public ProgramOpcode
{
public:
    LD_E_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_E_n)
};

class LD_H_n final : public ProgramOpcode
{
public:
    LD_H_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_H_n)
};

class LD_L_n final : public ProgramOpcode
{
public:
    LD_L_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_L_n)
};

class LD_IXH_n final : public ProgramOpcode
{
public:
    LD_IXH_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_IXH_n)
};

class LD_IYH_n final : public ProgramOpcode
{
public:
    LD_IYH_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_IYH_n)
};

class LD_IXL_n final : public ProgramOpcode
{
public:
    LD_IXL_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_IXL_n)
};

class LD_IYL_n final : public ProgramOpcode
{
public:
    LD_IYL_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(LD_IYL_n)
};

class LD_A_A final : public ProgramOpcode
{
public:
    LD_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_A)
};

class LD_B_A final : public ProgramOpcode
{
public:
    LD_B_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_A)
};

class LD_C_A final : public ProgramOpcode
{
public:
    LD_C_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_A)
};

class LD_D_A final : public ProgramOpcode
{
public:
    LD_D_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_A)
};

class LD_E_A final : public ProgramOpcode
{
public:
    LD_E_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_A)
};

class LD_H_A final : public ProgramOpcode
{
public:
    LD_H_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_H_A)
};

class LD_L_A final : public ProgramOpcode
{
public:
    LD_L_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_L_A)
};

class LD_A_B final : public ProgramOpcode
{
public:
    LD_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_B)
};

class LD_B_B final : public ProgramOpcode
{
public:
    LD_B_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_B)
};

class LD_C_B final : public ProgramOpcode
{
public:
    LD_C_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_B)
};

class LD_D_B final : public ProgramOpcode
{
public:
    LD_D_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_B)
};

class LD_E_B final : public ProgramOpcode
{
public:
    LD_E_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_B)
};

class LD_H_B final : public ProgramOpcode
{
public:
    LD_H_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_H_B)
};

class LD_L_B final : public ProgramOpcode
{
public:
    LD_L_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_L_B)
};

class LD_A_C final : public ProgramOpcode
{
public:
    LD_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_C)
};

class LD_B_C final : public ProgramOpcode
{
public:
    LD_B_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_C)
};

class LD_C_C final : public ProgramOpcode
{
public:
    LD_C_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_C)
};

class LD_D_C final : public ProgramOpcode
{
public:
    LD_D_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_C)
};

class LD_E_C final : public ProgramOpcode
{
public:
    LD_E_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_C)
};

class LD_H_C final : public ProgramOpcode
{
public:
    LD_H_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_H_C)
};

class LD_L_C final : public ProgramOpcode
{
public:
    LD_L_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_L_C)
};

class LD_A_D final : public ProgramOpcode
{
public:
    LD_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_D)
};

class LD_B_D final : public ProgramOpcode
{
public:
    LD_B_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_D)
};

class LD_C_D final : public ProgramOpcode
{
public:
    LD_C_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_D)
};

class LD_D_D final : public ProgramOpcode
{
public:
    LD_D_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_D)
};

class LD_E_D final : public ProgramOpcode
{
public:
    LD_E_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_D)
};

class LD_H_D final : public ProgramOpcode
{
public:
    LD_H_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_H_D)
};

class LD_L_D final : public ProgramOpcode
{
public:
    LD_L_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_L_D)
};

class LD_A_E final : public ProgramOpcode
{
public:
    LD_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_E)
};

class LD_B_E final : public ProgramOpcode
{
public:
    LD_B_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_E)
};

class LD_C_E final : public ProgramOpcode
{
public:
    LD_C_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_E)
};

class LD_D_E final : public ProgramOpcode
{
public:
    LD_D_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_E)
};

class LD_E_E final : public ProgramOpcode
{
public:
    LD_E_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_E)
};

class LD_H_E final : public ProgramOpcode
{
public:
    LD_H_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_H_E)
};

class LD_L_E final : public ProgramOpcode
{
public:
    LD_L_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_L_E)
};

class LD_A_H final : public ProgramOpcode
{
public:
    LD_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_H)
};

class LD_B_H final : public ProgramOpcode
{
public:
    LD_B_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_H)
};

class LD_C_H final : public ProgramOpcode
{
public:
    LD_C_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_H)
};

class LD_D_H final : public ProgramOpcode
{
public:
    LD_D_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_H)
};

class LD_E_H final : public ProgramOpcode
{
public:
    LD_E_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_H)
};

class LD_H_H final : public ProgramOpcode
{
public:
    LD_H_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_H_H)
};

class LD_L_H final : public ProgramOpcode
{
public:
    LD_L_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_L_H)
};

class LD_A_L final : public ProgramOpcode
{
public:
    LD_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_L)
};

class LD_B_L final : public ProgramOpcode
{
public:
    LD_B_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_L)
};

class LD_C_L final : public ProgramOpcode
{
public:
    LD_C_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_L)
};

class LD_D_L final : public ProgramOpcode
{
public:
    LD_D_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_L)
};

class LD_E_L final : public ProgramOpcode
{
public:
    LD_E_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_L)
};

class LD_H_L final : public ProgramOpcode
{
public:
    LD_H_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_H_L)
};

class LD_L_L final : public ProgramOpcode
{
public:
    LD_L_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_L_L)
};

class LD_B_IXH final : public ProgramOpcode
{
public:
    LD_B_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_IXH)
};

class LD_B_IYH final : public ProgramOpcode
{
public:
    LD_B_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_IYH)
};

class LD_B_IXL final : public ProgramOpcode
{
public:
    LD_B_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_IXL)
};

class LD_B_IYL final : public ProgramOpcode
{
public:
    LD_B_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_B_IYL)
};

class LD_C_IXH final : public ProgramOpcode
{
public:
    LD_C_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_IXH)
};

class LD_C_IYH final : public ProgramOpcode
{
public:
    LD_C_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_IYH)
};

class LD_C_IXL final : public ProgramOpcode
{
public:
    LD_C_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_IXL)
};

class LD_C_IYL final : public ProgramOpcode
{
public:
    LD_C_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_C_IYL)
};

class LD_D_IXH final : public ProgramOpcode
{
public:
    LD_D_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_IXH)
};

class LD_D_IYH final : public ProgramOpcode
{
public:
    LD_D_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_IYH)
};

class LD_D_IXL final : public ProgramOpcode
{
public:
    LD_D_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_IXL)
};

class LD_D_IYL final : public ProgramOpcode
{
public:
    LD_D_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_D_IYL)
};

class LD_E_IXH final : public ProgramOpcode
{
public:
    LD_E_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_IXH)
};

class LD_E_IYH final : public ProgramOpcode
{
public:
    LD_E_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_IYH)
};

class LD_E_IXL final : public ProgramOpcode
{
public:
    LD_E_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_IXL)
};

class LD_E_IYL final : public ProgramOpcode
{
public:
    LD_E_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_E_IYL)
};

class LD_IXH_B final : public ProgramOpcode
{
public:
    LD_IXH_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXH_B)
};

class LD_IYH_B final : public ProgramOpcode
{
public:
    LD_IYH_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYH_B)
};

class LD_IXH_C final : public ProgramOpcode
{
public:
    LD_IXH_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXH_C)
};

class LD_IYH_C final : public ProgramOpcode
{
public:
    LD_IYH_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYH_C)
};

class LD_IXH_D final : public ProgramOpcode
{
public:
    LD_IXH_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXH_D)
};

class LD_IYH_D final : public ProgramOpcode
{
public:
    LD_IYH_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYH_D)
};

class LD_IXH_E final : public ProgramOpcode
{
public:
    LD_IXH_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXH_E)
};

class LD_IYH_E final : public ProgramOpcode
{
public:
    LD_IYH_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYH_E)
};

class LD_IXH_IXH final : public ProgramOpcode
{
public:
    LD_IXH_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXH_IXH)
};

class LD_IYH_IYH final : public ProgramOpcode
{
public:
    LD_IYH_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYH_IYH)
};

class LD_IXH_IXL final : public ProgramOpcode
{
public:
    LD_IXH_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXH_IXL)
};

class LD_IYH_IYL final : public ProgramOpcode
{
public:
    LD_IYH_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYH_IYL)
};

class LD_IXH_A final : public ProgramOpcode
{
public:
    LD_IXH_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXH_A)
};

class LD_IYH_A final : public ProgramOpcode
{
public:
    LD_IYH_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYH_A)
};

class LD_IXL_B final : public ProgramOpcode
{
public:
    LD_IXL_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXL_B)
};

class LD_IYL_B final : public ProgramOpcode
{
public:
    LD_IYL_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYL_B)
};

class LD_IXL_C final : public ProgramOpcode
{
public:
    LD_IXL_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXL_C)
};

class LD_IYL_C final : public ProgramOpcode
{
public:
    LD_IYL_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYL_C)
};

class LD_IXL_D final : public ProgramOpcode
{
public:
    LD_IXL_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXL_D)
};

class LD_IYL_D final : public ProgramOpcode
{
public:
    LD_IYL_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYL_D)
};

class LD_IXL_E final : public ProgramOpcode
{
public:
    LD_IXL_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXL_E)
};

class LD_IYL_E final : public ProgramOpcode
{
public:
    LD_IYL_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYL_E)
};

class LD_IXL_IXH final : public ProgramOpcode
{
public:
    LD_IXL_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXL_IXH)
};

class LD_IYL_IYH final : public ProgramOpcode
{
public:
    LD_IYL_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYL_IYH)
};

class LD_IXL_IXL final : public ProgramOpcode
{
public:
    LD_IXL_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXL_IXL)
};

class LD_IYL_IYL final : public ProgramOpcode
{
public:
    LD_IYL_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYL_IYL)
};

class LD_IXL_A final : public ProgramOpcode
{
public:
    LD_IXL_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IXL_A)
};

class LD_IYL_A final : public ProgramOpcode
{
public:
    LD_IYL_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_IYL_A)
};

class LD_A_IXH final : public ProgramOpcode
{
public:
    LD_A_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_IXH)
};

class LD_A_IYH final : public ProgramOpcode
{
public:
    LD_A_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_IYH)
};

class LD_A_IXL final : public ProgramOpcode
{
public:
    LD_A_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_IXL)
};

class LD_A_IYL final : public ProgramOpcode
{
public:
    LD_A_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_A_IYL)
};

class LD_SP_HL final : public ProgramOpcode
{
public:
    LD_SP_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 6; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 6; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_SP_HL)
};

class LD_SP_IX final : public ProgramOpcode
{
public:
    LD_SP_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_SP_IX)
};

class LD_SP_IY final : public ProgramOpcode
{
public:
    LD_SP_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LD_SP_IY)
};

class LDD final : public ProgramOpcode
{
public:
    LDD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LDD)
};

class LDDR final : public ProgramOpcode
{
public:
    LDDR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 21; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LDDR)
};

class LDI final : public ProgramOpcode
{
public:
    LDI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LDI)
};

class LDIR final : public ProgramOpcode
{
public:
    LDIR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 17; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 21; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(LDIR)
};

class NEG final : public ProgramOpcode
{
public:
    NEG(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(NEG)
};

class NOP final : public ProgramOpcode
{
public:
    NOP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(NOP)
};

class OR_A final : public ProgramOpcode
{
public:
    OR_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A)
};

class OR_A_A final : public ProgramOpcode
{
public:
    OR_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_A)
};

class OR_B final : public ProgramOpcode
{
public:
    OR_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_B)
};

class OR_A_B final : public ProgramOpcode
{
public:
    OR_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_B)
};

class OR_C final : public ProgramOpcode
{
public:
    OR_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_C)
};

class OR_A_C final : public ProgramOpcode
{
public:
    OR_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_C)
};

class OR_D final : public ProgramOpcode
{
public:
    OR_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_D)
};

class OR_A_D final : public ProgramOpcode
{
public:
    OR_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_D)
};

class OR_E final : public ProgramOpcode
{
public:
    OR_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_E)
};

class OR_A_E final : public ProgramOpcode
{
public:
    OR_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_E)
};

class OR_H final : public ProgramOpcode
{
public:
    OR_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_H)
};

class OR_A_H final : public ProgramOpcode
{
public:
    OR_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_H)
};

class OR_L final : public ProgramOpcode
{
public:
    OR_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_L)
};

class OR_A_L final : public ProgramOpcode
{
public:
    OR_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_L)
};

class OR_n final : public ProgramOpcode
{
public:
    OR_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(OR_n)
};

class OR_A_n final : public ProgramOpcode
{
public:
    OR_A_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(OR_A_n)
};

class OR_mHL final : public ProgramOpcode
{
public:
    OR_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_mHL)
};

class OR_A_mHL final : public ProgramOpcode
{
public:
    OR_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_mHL)
};

class OR_mIXn final : public ProgramOpcode
{
public:
    OR_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(OR_mIXn)
};

class OR_A_mIXn final : public ProgramOpcode
{
public:
    OR_A_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(OR_A_mIXn)
};

class OR_mIYn final : public ProgramOpcode
{
public:
    OR_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(OR_mIYn)
};

class OR_A_mIYn final : public ProgramOpcode
{
public:
    OR_A_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(OR_A_mIYn)
};

class OR_IXH final : public ProgramOpcode
{
public:
    OR_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_IXH)
};

class OR_A_IXH final : public ProgramOpcode
{
public:
    OR_A_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_IXH)
};

class OR_IYH final : public ProgramOpcode
{
public:
    OR_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_IYH)
};

class OR_A_IYH final : public ProgramOpcode
{
public:
    OR_A_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_IYH)
};

class OR_IXL final : public ProgramOpcode
{
public:
    OR_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_IXL)
};

class OR_A_IXL final : public ProgramOpcode
{
public:
    OR_A_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_IXL)
};

class OR_IYL final : public ProgramOpcode
{
public:
    OR_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_IYL)
};

class OR_A_IYL final : public ProgramOpcode
{
public:
    OR_A_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OR_A_IYL)
};

class OTDR final : public ProgramOpcode
{
public:
    OTDR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 21; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OTDR)
};

class OTIR final : public ProgramOpcode
{
public:
    OTIR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 21; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OTIR)
};

class OUT_mn_A final : public ProgramOpcode
{
public:
    OUT_mn_A(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(OUT_mn_A)
};

class OUT_mC_A final : public ProgramOpcode
{
public:
    OUT_mC_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OUT_mC_A)
};

class OUT_mC_B final : public ProgramOpcode
{
public:
    OUT_mC_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OUT_mC_B)
};

class OUT_mC_C final : public ProgramOpcode
{
public:
    OUT_mC_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OUT_mC_C)
};

class OUT_mC_D final : public ProgramOpcode
{
public:
    OUT_mC_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OUT_mC_D)
};

class OUT_mC_E final : public ProgramOpcode
{
public:
    OUT_mC_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OUT_mC_E)
};

class OUT_mC_H final : public ProgramOpcode
{
public:
    OUT_mC_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OUT_mC_H)
};

class OUT_mC_L final : public ProgramOpcode
{
public:
    OUT_mC_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 12; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 12; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OUT_mC_L)
};

class OUTD final : public ProgramOpcode
{
public:
    OUTD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OUTD)
};

class OUTI final : public ProgramOpcode
{
public:
    OUTI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 16; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 16; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(OUTI)
};

class POP_IX final : public ProgramOpcode
{
public:
    POP_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 14; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 14; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(POP_IX)
};

class POP_IY final : public ProgramOpcode
{
public:
    POP_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 14; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 14; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(POP_IY)
};

class POP_BC final : public ProgramOpcode
{
public:
    POP_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(POP_BC)
};

class POP_DE final : public ProgramOpcode
{
public:
    POP_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(POP_DE)
};

class POP_HL final : public ProgramOpcode
{
public:
    POP_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(POP_HL)
};

class POP_AF final : public ProgramOpcode
{
public:
    POP_AF(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(POP_AF)
};

class PUSH_IX final : public ProgramOpcode
{
public:
    PUSH_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(PUSH_IX)
};

class PUSH_IY final : public ProgramOpcode
{
public:
    PUSH_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(PUSH_IY)
};

class PUSH_BC final : public ProgramOpcode
{
public:
    PUSH_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(PUSH_BC)
};

class PUSH_DE final : public ProgramOpcode
{
public:
    PUSH_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(PUSH_DE)
};

class PUSH_HL final : public ProgramOpcode
{
public:
    PUSH_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(PUSH_HL)
};

class PUSH_AF final : public ProgramOpcode
{
public:
    PUSH_AF(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(PUSH_AF)
};

class RES_0_A final : public ProgramOpcode
{
public:
    RES_0_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_0_A)
};

class RES_0_B final : public ProgramOpcode
{
public:
    RES_0_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_0_B)
};

class RES_0_C final : public ProgramOpcode
{
public:
    RES_0_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_0_C)
};

class RES_0_D final : public ProgramOpcode
{
public:
    RES_0_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_0_D)
};

class RES_0_E final : public ProgramOpcode
{
public:
    RES_0_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_0_E)
};

class RES_0_H final : public ProgramOpcode
{
public:
    RES_0_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_0_H)
};

class RES_0_L final : public ProgramOpcode
{
public:
    RES_0_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_0_L)
};

class RES_1_A final : public ProgramOpcode
{
public:
    RES_1_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_1_A)
};

class RES_1_B final : public ProgramOpcode
{
public:
    RES_1_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_1_B)
};

class RES_1_C final : public ProgramOpcode
{
public:
    RES_1_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_1_C)
};

class RES_1_D final : public ProgramOpcode
{
public:
    RES_1_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_1_D)
};

class RES_1_E final : public ProgramOpcode
{
public:
    RES_1_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_1_E)
};

class RES_1_H final : public ProgramOpcode
{
public:
    RES_1_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_1_H)
};

class RES_1_L final : public ProgramOpcode
{
public:
    RES_1_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_1_L)
};

class RES_2_A final : public ProgramOpcode
{
public:
    RES_2_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_2_A)
};

class RES_2_B final : public ProgramOpcode
{
public:
    RES_2_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_2_B)
};

class RES_2_C final : public ProgramOpcode
{
public:
    RES_2_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_2_C)
};

class RES_2_D final : public ProgramOpcode
{
public:
    RES_2_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_2_D)
};

class RES_2_E final : public ProgramOpcode
{
public:
    RES_2_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_2_E)
};

class RES_2_H final : public ProgramOpcode
{
public:
    RES_2_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_2_H)
};

class RES_2_L final : public ProgramOpcode
{
public:
    RES_2_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_2_L)
};

class RES_3_A final : public ProgramOpcode
{
public:
    RES_3_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_3_A)
};

class RES_3_B final : public ProgramOpcode
{
public:
    RES_3_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_3_B)
};

class RES_3_C final : public ProgramOpcode
{
public:
    RES_3_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_3_C)
};

class RES_3_D final : public ProgramOpcode
{
public:
    RES_3_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_3_D)
};

class RES_3_E final : public ProgramOpcode
{
public:
    RES_3_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_3_E)
};

class RES_3_H final : public ProgramOpcode
{
public:
    RES_3_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_3_H)
};

class RES_3_L final : public ProgramOpcode
{
public:
    RES_3_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_3_L)
};

class RES_4_A final : public ProgramOpcode
{
public:
    RES_4_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_4_A)
};

class RES_4_B final : public ProgramOpcode
{
public:
    RES_4_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_4_B)
};

class RES_4_C final : public ProgramOpcode
{
public:
    RES_4_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_4_C)
};

class RES_4_D final : public ProgramOpcode
{
public:
    RES_4_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_4_D)
};

class RES_4_E final : public ProgramOpcode
{
public:
    RES_4_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_4_E)
};

class RES_4_H final : public ProgramOpcode
{
public:
    RES_4_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_4_H)
};

class RES_4_L final : public ProgramOpcode
{
public:
    RES_4_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_4_L)
};

class RES_5_A final : public ProgramOpcode
{
public:
    RES_5_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_5_A)
};

class RES_5_B final : public ProgramOpcode
{
public:
    RES_5_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_5_B)
};

class RES_5_C final : public ProgramOpcode
{
public:
    RES_5_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_5_C)
};

class RES_5_D final : public ProgramOpcode
{
public:
    RES_5_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_5_D)
};

class RES_5_E final : public ProgramOpcode
{
public:
    RES_5_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_5_E)
};

class RES_5_H final : public ProgramOpcode
{
public:
    RES_5_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_5_H)
};

class RES_5_L final : public ProgramOpcode
{
public:
    RES_5_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_5_L)
};

class RES_6_A final : public ProgramOpcode
{
public:
    RES_6_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_6_A)
};

class RES_6_B final : public ProgramOpcode
{
public:
    RES_6_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_6_B)
};

class RES_6_C final : public ProgramOpcode
{
public:
    RES_6_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_6_C)
};

class RES_6_D final : public ProgramOpcode
{
public:
    RES_6_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_6_D)
};

class RES_6_E final : public ProgramOpcode
{
public:
    RES_6_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_6_E)
};

class RES_6_H final : public ProgramOpcode
{
public:
    RES_6_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_6_H)
};

class RES_6_L final : public ProgramOpcode
{
public:
    RES_6_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_6_L)
};

class RES_7_A final : public ProgramOpcode
{
public:
    RES_7_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_7_A)
};

class RES_7_B final : public ProgramOpcode
{
public:
    RES_7_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_7_B)
};

class RES_7_C final : public ProgramOpcode
{
public:
    RES_7_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_7_C)
};

class RES_7_D final : public ProgramOpcode
{
public:
    RES_7_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_7_D)
};

class RES_7_E final : public ProgramOpcode
{
public:
    RES_7_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_7_E)
};

class RES_7_H final : public ProgramOpcode
{
public:
    RES_7_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_7_H)
};

class RES_7_L final : public ProgramOpcode
{
public:
    RES_7_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_7_L)
};

class RES_0_mHL final : public ProgramOpcode
{
public:
    RES_0_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_0_mHL)
};

class RES_1_mHL final : public ProgramOpcode
{
public:
    RES_1_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_1_mHL)
};

class RES_2_mHL final : public ProgramOpcode
{
public:
    RES_2_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_2_mHL)
};

class RES_3_mHL final : public ProgramOpcode
{
public:
    RES_3_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_3_mHL)
};

class RES_4_mHL final : public ProgramOpcode
{
public:
    RES_4_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_4_mHL)
};

class RES_5_mHL final : public ProgramOpcode
{
public:
    RES_5_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_5_mHL)
};

class RES_6_mHL final : public ProgramOpcode
{
public:
    RES_6_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_6_mHL)
};

class RES_7_mHL final : public ProgramOpcode
{
public:
    RES_7_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RES_7_mHL)
};

class RES_0_mIXn final : public ProgramOpcode
{
public:
    RES_0_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_0_mIXn)
};

class RES_1_mIXn final : public ProgramOpcode
{
public:
    RES_1_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_1_mIXn)
};

class RES_2_mIXn final : public ProgramOpcode
{
public:
    RES_2_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_2_mIXn)
};

class RES_3_mIXn final : public ProgramOpcode
{
public:
    RES_3_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_3_mIXn)
};

class RES_4_mIXn final : public ProgramOpcode
{
public:
    RES_4_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_4_mIXn)
};

class RES_5_mIXn final : public ProgramOpcode
{
public:
    RES_5_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_5_mIXn)
};

class RES_6_mIXn final : public ProgramOpcode
{
public:
    RES_6_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_6_mIXn)
};

class RES_7_mIXn final : public ProgramOpcode
{
public:
    RES_7_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_7_mIXn)
};

class RES_0_mIYn final : public ProgramOpcode
{
public:
    RES_0_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_0_mIYn)
};

class RES_1_mIYn final : public ProgramOpcode
{
public:
    RES_1_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_1_mIYn)
};

class RES_2_mIYn final : public ProgramOpcode
{
public:
    RES_2_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_2_mIYn)
};

class RES_3_mIYn final : public ProgramOpcode
{
public:
    RES_3_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_3_mIYn)
};

class RES_4_mIYn final : public ProgramOpcode
{
public:
    RES_4_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_4_mIYn)
};

class RES_5_mIYn final : public ProgramOpcode
{
public:
    RES_5_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_5_mIYn)
};

class RES_6_mIYn final : public ProgramOpcode
{
public:
    RES_6_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_6_mIYn)
};

class RES_7_mIYn final : public ProgramOpcode
{
public:
    RES_7_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RES_7_mIYn)
};

class RET final : public ProgramOpcode
{
public:
    RET(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 10; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 10; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RET)
};

class RET_C final : public ProgramOpcode
{
public:
    RET_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 5; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RET_C)
};

class RET_M final : public ProgramOpcode
{
public:
    RET_M(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 5; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RET_M)
};

class RET_NC final : public ProgramOpcode
{
public:
    RET_NC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 5; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RET_NC)
};

class RET_NZ final : public ProgramOpcode
{
public:
    RET_NZ(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 5; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RET_NZ)
};

class RET_P final : public ProgramOpcode
{
public:
    RET_P(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 5; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RET_P)
};

class RET_PE final : public ProgramOpcode
{
public:
    RET_PE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 5; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RET_PE)
};

class RET_PO final : public ProgramOpcode
{
public:
    RET_PO(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 5; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RET_PO)
};

class RET_Z final : public ProgramOpcode
{
public:
    RET_Z(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 5; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RET_Z)
};

class RETI final : public ProgramOpcode
{
public:
    RETI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 14; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 14; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RETI)
};

class RETN final : public ProgramOpcode
{
public:
    RETN(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 14; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 14; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RETN)
};

class RL_A final : public ProgramOpcode
{
public:
    RL_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RL_A)
};

class RL_B final : public ProgramOpcode
{
public:
    RL_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RL_B)
};

class RL_C final : public ProgramOpcode
{
public:
    RL_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RL_C)
};

class RL_D final : public ProgramOpcode
{
public:
    RL_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RL_D)
};

class RL_E final : public ProgramOpcode
{
public:
    RL_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RL_E)
};

class RL_H final : public ProgramOpcode
{
public:
    RL_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RL_H)
};

class RL_L final : public ProgramOpcode
{
public:
    RL_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RL_L)
};

class RL_mHL final : public ProgramOpcode
{
public:
    RL_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RL_mHL)
};

class RL_mIXn final : public ProgramOpcode
{
public:
    RL_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RL_mIXn)
};

class RL_mIYn final : public ProgramOpcode
{
public:
    RL_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RL_mIYn)
};

class RLA final : public ProgramOpcode
{
public:
    RLA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLA)
};

class RLC_A final : public ProgramOpcode
{
public:
    RLC_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLC_A)
};

class RLC_B final : public ProgramOpcode
{
public:
    RLC_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLC_B)
};

class RLC_C final : public ProgramOpcode
{
public:
    RLC_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLC_C)
};

class RLC_D final : public ProgramOpcode
{
public:
    RLC_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLC_D)
};

class RLC_E final : public ProgramOpcode
{
public:
    RLC_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLC_E)
};

class RLC_H final : public ProgramOpcode
{
public:
    RLC_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLC_H)
};

class RLC_L final : public ProgramOpcode
{
public:
    RLC_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLC_L)
};

class RLC_mHL final : public ProgramOpcode
{
public:
    RLC_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLC_mHL)
};

class RLC_mIXn final : public ProgramOpcode
{
public:
    RLC_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RLC_mIXn)
};

class RLC_mIYn final : public ProgramOpcode
{
public:
    RLC_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RLC_mIYn)
};

class RLCA final : public ProgramOpcode
{
public:
    RLCA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLCA)
};

class RLD final : public ProgramOpcode
{
public:
    RLD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 18; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 18; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RLD)
};

class RR_A final : public ProgramOpcode
{
public:
    RR_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RR_A)
};

class RR_B final : public ProgramOpcode
{
public:
    RR_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RR_B)
};

class RR_C final : public ProgramOpcode
{
public:
    RR_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RR_C)
};

class RR_D final : public ProgramOpcode
{
public:
    RR_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RR_D)
};

class RR_E final : public ProgramOpcode
{
public:
    RR_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RR_E)
};

class RR_H final : public ProgramOpcode
{
public:
    RR_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RR_H)
};

class RR_L final : public ProgramOpcode
{
public:
    RR_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RR_L)
};

class RR_mHL final : public ProgramOpcode
{
public:
    RR_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RR_mHL)
};

class RR_mIXn final : public ProgramOpcode
{
public:
    RR_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RR_mIXn)
};

class RR_mIYn final : public ProgramOpcode
{
public:
    RR_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RR_mIYn)
};

class RRA final : public ProgramOpcode
{
public:
    RRA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRA)
};

class RRC_A final : public ProgramOpcode
{
public:
    RRC_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRC_A)
};

class RRC_B final : public ProgramOpcode
{
public:
    RRC_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRC_B)
};

class RRC_C final : public ProgramOpcode
{
public:
    RRC_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRC_C)
};

class RRC_D final : public ProgramOpcode
{
public:
    RRC_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRC_D)
};

class RRC_E final : public ProgramOpcode
{
public:
    RRC_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRC_E)
};

class RRC_H final : public ProgramOpcode
{
public:
    RRC_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRC_H)
};

class RRC_L final : public ProgramOpcode
{
public:
    RRC_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRC_L)
};

class RRC_mHL final : public ProgramOpcode
{
public:
    RRC_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRC_mHL)
};

class RRC_mIXn final : public ProgramOpcode
{
public:
    RRC_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RRC_mIXn)
};

class RRC_mIYn final : public ProgramOpcode
{
public:
    RRC_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(RRC_mIYn)
};

class RRCA final : public ProgramOpcode
{
public:
    RRCA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRCA)
};

class RRD final : public ProgramOpcode
{
public:
    RRD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 18; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 18; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RRD)
};

class RST_00 final : public ProgramOpcode
{
public:
    RST_00(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RST_00)
};

class RST_08 final : public ProgramOpcode
{
public:
    RST_08(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RST_08)
};

class RST_10 final : public ProgramOpcode
{
public:
    RST_10(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RST_10)
};

class RST_18 final : public ProgramOpcode
{
public:
    RST_18(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RST_18)
};

class RST_20 final : public ProgramOpcode
{
public:
    RST_20(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RST_20)
};

class RST_28 final : public ProgramOpcode
{
public:
    RST_28(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RST_28)
};

class RST_30 final : public ProgramOpcode
{
public:
    RST_30(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RST_30)
};

class RST_38 final : public ProgramOpcode
{
public:
    RST_38(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 11; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 11; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(RST_38)
};

class SBC_A_A final : public ProgramOpcode
{
public:
    SBC_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_A)
};

class SBC_A_B final : public ProgramOpcode
{
public:
    SBC_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_B)
};

class SBC_A_C final : public ProgramOpcode
{
public:
    SBC_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_C)
};

class SBC_A_D final : public ProgramOpcode
{
public:
    SBC_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_D)
};

class SBC_A_E final : public ProgramOpcode
{
public:
    SBC_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_E)
};

class SBC_A_H final : public ProgramOpcode
{
public:
    SBC_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_H)
};

class SBC_A_L final : public ProgramOpcode
{
public:
    SBC_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_L)
};

class SBC_A_n final : public ProgramOpcode
{
public:
    SBC_A_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SBC_A_n)
};

class SBC_A_mHL final : public ProgramOpcode
{
public:
    SBC_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_mHL)
};

class SBC_A_mIXn final : public ProgramOpcode
{
public:
    SBC_A_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SBC_A_mIXn)
};

class SBC_A_mIYn final : public ProgramOpcode
{
public:
    SBC_A_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SBC_A_mIYn)
};

class SBC_HL_BC final : public ProgramOpcode
{
public:
    SBC_HL_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_HL_BC)
};

class SBC_HL_DE final : public ProgramOpcode
{
public:
    SBC_HL_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_HL_DE)
};

class SBC_HL_HL final : public ProgramOpcode
{
public:
    SBC_HL_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_HL_HL)
};

class SBC_HL_SP final : public ProgramOpcode
{
public:
    SBC_HL_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_HL_SP)
};

class SBC_A_IXH final : public ProgramOpcode
{
public:
    SBC_A_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_IXH)
};

class SBC_A_IYH final : public ProgramOpcode
{
public:
    SBC_A_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_IYH)
};

class SBC_A_IXL final : public ProgramOpcode
{
public:
    SBC_A_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_IXL)
};

class SBC_A_IYL final : public ProgramOpcode
{
public:
    SBC_A_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SBC_A_IYL)
};

class SCF final : public ProgramOpcode
{
public:
    SCF(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SCF)
};

class SET_0_A final : public ProgramOpcode
{
public:
    SET_0_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_0_A)
};

class SET_0_B final : public ProgramOpcode
{
public:
    SET_0_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_0_B)
};

class SET_0_C final : public ProgramOpcode
{
public:
    SET_0_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_0_C)
};

class SET_0_D final : public ProgramOpcode
{
public:
    SET_0_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_0_D)
};

class SET_0_E final : public ProgramOpcode
{
public:
    SET_0_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_0_E)
};

class SET_0_H final : public ProgramOpcode
{
public:
    SET_0_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_0_H)
};

class SET_0_L final : public ProgramOpcode
{
public:
    SET_0_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_0_L)
};

class SET_1_A final : public ProgramOpcode
{
public:
    SET_1_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_1_A)
};

class SET_1_B final : public ProgramOpcode
{
public:
    SET_1_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_1_B)
};

class SET_1_C final : public ProgramOpcode
{
public:
    SET_1_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_1_C)
};

class SET_1_D final : public ProgramOpcode
{
public:
    SET_1_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_1_D)
};

class SET_1_E final : public ProgramOpcode
{
public:
    SET_1_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_1_E)
};

class SET_1_H final : public ProgramOpcode
{
public:
    SET_1_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_1_H)
};

class SET_1_L final : public ProgramOpcode
{
public:
    SET_1_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_1_L)
};

class SET_2_A final : public ProgramOpcode
{
public:
    SET_2_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_2_A)
};

class SET_2_B final : public ProgramOpcode
{
public:
    SET_2_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_2_B)
};

class SET_2_C final : public ProgramOpcode
{
public:
    SET_2_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_2_C)
};

class SET_2_D final : public ProgramOpcode
{
public:
    SET_2_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_2_D)
};

class SET_2_E final : public ProgramOpcode
{
public:
    SET_2_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_2_E)
};

class SET_2_H final : public ProgramOpcode
{
public:
    SET_2_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_2_H)
};

class SET_2_L final : public ProgramOpcode
{
public:
    SET_2_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_2_L)
};

class SET_3_A final : public ProgramOpcode
{
public:
    SET_3_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_3_A)
};

class SET_3_B final : public ProgramOpcode
{
public:
    SET_3_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_3_B)
};

class SET_3_C final : public ProgramOpcode
{
public:
    SET_3_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_3_C)
};

class SET_3_D final : public ProgramOpcode
{
public:
    SET_3_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_3_D)
};

class SET_3_E final : public ProgramOpcode
{
public:
    SET_3_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_3_E)
};

class SET_3_H final : public ProgramOpcode
{
public:
    SET_3_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_3_H)
};

class SET_3_L final : public ProgramOpcode
{
public:
    SET_3_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_3_L)
};

class SET_4_A final : public ProgramOpcode
{
public:
    SET_4_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_4_A)
};

class SET_4_B final : public ProgramOpcode
{
public:
    SET_4_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_4_B)
};

class SET_4_C final : public ProgramOpcode
{
public:
    SET_4_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_4_C)
};

class SET_4_D final : public ProgramOpcode
{
public:
    SET_4_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_4_D)
};

class SET_4_E final : public ProgramOpcode
{
public:
    SET_4_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_4_E)
};

class SET_4_H final : public ProgramOpcode
{
public:
    SET_4_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_4_H)
};

class SET_4_L final : public ProgramOpcode
{
public:
    SET_4_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_4_L)
};

class SET_5_A final : public ProgramOpcode
{
public:
    SET_5_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_5_A)
};

class SET_5_B final : public ProgramOpcode
{
public:
    SET_5_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_5_B)
};

class SET_5_C final : public ProgramOpcode
{
public:
    SET_5_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_5_C)
};

class SET_5_D final : public ProgramOpcode
{
public:
    SET_5_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_5_D)
};

class SET_5_E final : public ProgramOpcode
{
public:
    SET_5_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_5_E)
};

class SET_5_H final : public ProgramOpcode
{
public:
    SET_5_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_5_H)
};

class SET_5_L final : public ProgramOpcode
{
public:
    SET_5_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_5_L)
};

class SET_6_A final : public ProgramOpcode
{
public:
    SET_6_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_6_A)
};

class SET_6_B final : public ProgramOpcode
{
public:
    SET_6_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_6_B)
};

class SET_6_C final : public ProgramOpcode
{
public:
    SET_6_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_6_C)
};

class SET_6_D final : public ProgramOpcode
{
public:
    SET_6_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_6_D)
};

class SET_6_E final : public ProgramOpcode
{
public:
    SET_6_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_6_E)
};

class SET_6_H final : public ProgramOpcode
{
public:
    SET_6_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_6_H)
};

class SET_6_L final : public ProgramOpcode
{
public:
    SET_6_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_6_L)
};

class SET_7_A final : public ProgramOpcode
{
public:
    SET_7_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_7_A)
};

class SET_7_B final : public ProgramOpcode
{
public:
    SET_7_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_7_B)
};

class SET_7_C final : public ProgramOpcode
{
public:
    SET_7_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_7_C)
};

class SET_7_D final : public ProgramOpcode
{
public:
    SET_7_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_7_D)
};

class SET_7_E final : public ProgramOpcode
{
public:
    SET_7_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_7_E)
};

class SET_7_H final : public ProgramOpcode
{
public:
    SET_7_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_7_H)
};

class SET_7_L final : public ProgramOpcode
{
public:
    SET_7_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_7_L)
};

class SET_0_mHL final : public ProgramOpcode
{
public:
    SET_0_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_0_mHL)
};

class SET_1_mHL final : public ProgramOpcode
{
public:
    SET_1_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_1_mHL)
};

class SET_2_mHL final : public ProgramOpcode
{
public:
    SET_2_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_2_mHL)
};

class SET_3_mHL final : public ProgramOpcode
{
public:
    SET_3_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_3_mHL)
};

class SET_4_mHL final : public ProgramOpcode
{
public:
    SET_4_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_4_mHL)
};

class SET_5_mHL final : public ProgramOpcode
{
public:
    SET_5_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_5_mHL)
};

class SET_6_mHL final : public ProgramOpcode
{
public:
    SET_6_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_6_mHL)
};

class SET_7_mHL final : public ProgramOpcode
{
public:
    SET_7_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SET_7_mHL)
};

class SET_0_mIXn final : public ProgramOpcode
{
public:
    SET_0_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_0_mIXn)
};

class SET_1_mIXn final : public ProgramOpcode
{
public:
    SET_1_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_1_mIXn)
};

class SET_2_mIXn final : public ProgramOpcode
{
public:
    SET_2_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_2_mIXn)
};

class SET_3_mIXn final : public ProgramOpcode
{
public:
    SET_3_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_3_mIXn)
};

class SET_4_mIXn final : public ProgramOpcode
{
public:
    SET_4_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_4_mIXn)
};

class SET_5_mIXn final : public ProgramOpcode
{
public:
    SET_5_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_5_mIXn)
};

class SET_6_mIXn final : public ProgramOpcode
{
public:
    SET_6_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_6_mIXn)
};

class SET_7_mIXn final : public ProgramOpcode
{
public:
    SET_7_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_7_mIXn)
};

class SET_0_mIYn final : public ProgramOpcode
{
public:
    SET_0_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_0_mIYn)
};

class SET_1_mIYn final : public ProgramOpcode
{
public:
    SET_1_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_1_mIYn)
};

class SET_2_mIYn final : public ProgramOpcode
{
public:
    SET_2_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_2_mIYn)
};

class SET_3_mIYn final : public ProgramOpcode
{
public:
    SET_3_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_3_mIYn)
};

class SET_4_mIYn final : public ProgramOpcode
{
public:
    SET_4_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_4_mIYn)
};

class SET_5_mIYn final : public ProgramOpcode
{
public:
    SET_5_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_5_mIYn)
};

class SET_6_mIYn final : public ProgramOpcode
{
public:
    SET_6_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_6_mIYn)
};

class SET_7_mIYn final : public ProgramOpcode
{
public:
    SET_7_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SET_7_mIYn)
};

class SLA_A final : public ProgramOpcode
{
public:
    SLA_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLA_A)
};

class SLA_B final : public ProgramOpcode
{
public:
    SLA_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLA_B)
};

class SLA_C final : public ProgramOpcode
{
public:
    SLA_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLA_C)
};

class SLA_D final : public ProgramOpcode
{
public:
    SLA_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLA_D)
};

class SLA_E final : public ProgramOpcode
{
public:
    SLA_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLA_E)
};

class SLA_H final : public ProgramOpcode
{
public:
    SLA_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLA_H)
};

class SLA_L final : public ProgramOpcode
{
public:
    SLA_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLA_L)
};

class SLA_mHL final : public ProgramOpcode
{
public:
    SLA_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLA_mHL)
};

class SLA_mIXn final : public ProgramOpcode
{
public:
    SLA_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SLA_mIXn)
};

class SLA_mIYn final : public ProgramOpcode
{
public:
    SLA_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SLA_mIYn)
};

class SLL_B final : public ProgramOpcode
{
public:
    SLL_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLL_B)
};

class SLL_C final : public ProgramOpcode
{
public:
    SLL_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLL_C)
};

class SLL_D final : public ProgramOpcode
{
public:
    SLL_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLL_D)
};

class SLL_E final : public ProgramOpcode
{
public:
    SLL_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLL_E)
};

class SLL_H final : public ProgramOpcode
{
public:
    SLL_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLL_H)
};

class SLL_L final : public ProgramOpcode
{
public:
    SLL_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLL_L)
};

class SLL_mHL final : public ProgramOpcode
{
public:
    SLL_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLL_mHL)
};

class SLL_mIXn final : public ProgramOpcode
{
public:
    SLL_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SLL_mIXn)
};

class SLL_mIYn final : public ProgramOpcode
{
public:
    SLL_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SLL_mIYn)
};

class SLL_A final : public ProgramOpcode
{
public:
    SLL_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SLL_A)
};

class SRA_A final : public ProgramOpcode
{
public:
    SRA_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRA_A)
};

class SRA_B final : public ProgramOpcode
{
public:
    SRA_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRA_B)
};

class SRA_C final : public ProgramOpcode
{
public:
    SRA_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRA_C)
};

class SRA_D final : public ProgramOpcode
{
public:
    SRA_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRA_D)
};

class SRA_E final : public ProgramOpcode
{
public:
    SRA_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRA_E)
};

class SRA_H final : public ProgramOpcode
{
public:
    SRA_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRA_H)
};

class SRA_L final : public ProgramOpcode
{
public:
    SRA_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRA_L)
};

class SRA_mHL final : public ProgramOpcode
{
public:
    SRA_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRA_mHL)
};

class SRA_mIXn final : public ProgramOpcode
{
public:
    SRA_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SRA_mIXn)
};

class SRA_mIYn final : public ProgramOpcode
{
public:
    SRA_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SRA_mIYn)
};

class SRL_A final : public ProgramOpcode
{
public:
    SRL_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRL_A)
};

class SRL_B final : public ProgramOpcode
{
public:
    SRL_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRL_B)
};

class SRL_C final : public ProgramOpcode
{
public:
    SRL_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRL_C)
};

class SRL_D final : public ProgramOpcode
{
public:
    SRL_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRL_D)
};

class SRL_E final : public ProgramOpcode
{
public:
    SRL_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRL_E)
};

class SRL_H final : public ProgramOpcode
{
public:
    SRL_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRL_H)
};

class SRL_L final : public ProgramOpcode
{
public:
    SRL_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRL_L)
};

class SRL_mHL final : public ProgramOpcode
{
public:
    SRL_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 15; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 15; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SRL_mHL)
};

class SRL_mIXn final : public ProgramOpcode
{
public:
    SRL_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SRL_mIXn)
};

class SRL_mIYn final : public ProgramOpcode
{
public:
    SRL_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 23; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 23; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SRL_mIYn)
};

class SUB_A final : public ProgramOpcode
{
public:
    SUB_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A)
};

class SUB_A_A final : public ProgramOpcode
{
public:
    SUB_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_A)
};

class SUB_B final : public ProgramOpcode
{
public:
    SUB_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_B)
};

class SUB_A_B final : public ProgramOpcode
{
public:
    SUB_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_B)
};

class SUB_C final : public ProgramOpcode
{
public:
    SUB_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_C)
};

class SUB_A_C final : public ProgramOpcode
{
public:
    SUB_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_C)
};

class SUB_D final : public ProgramOpcode
{
public:
    SUB_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_D)
};

class SUB_A_D final : public ProgramOpcode
{
public:
    SUB_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_D)
};

class SUB_E final : public ProgramOpcode
{
public:
    SUB_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_E)
};

class SUB_A_E final : public ProgramOpcode
{
public:
    SUB_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_E)
};

class SUB_H final : public ProgramOpcode
{
public:
    SUB_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_H)
};

class SUB_A_H final : public ProgramOpcode
{
public:
    SUB_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_H)
};

class SUB_L final : public ProgramOpcode
{
public:
    SUB_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_L)
};

class SUB_A_L final : public ProgramOpcode
{
public:
    SUB_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_L)
};

class SUB_n final : public ProgramOpcode
{
public:
    SUB_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SUB_n)
};

class SUB_A_n final : public ProgramOpcode
{
public:
    SUB_A_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SUB_A_n)
};

class SUB_mHL final : public ProgramOpcode
{
public:
    SUB_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_mHL)
};

class SUB_A_mHL final : public ProgramOpcode
{
public:
    SUB_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_mHL)
};

class SUB_IXH final : public ProgramOpcode
{
public:
    SUB_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_IXH)
};

class SUB_A_IXH final : public ProgramOpcode
{
public:
    SUB_A_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_IXH)
};

class SUB_IYH final : public ProgramOpcode
{
public:
    SUB_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_IYH)
};

class SUB_A_IYH final : public ProgramOpcode
{
public:
    SUB_A_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_IYH)
};

class SUB_IXL final : public ProgramOpcode
{
public:
    SUB_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_IXL)
};

class SUB_A_IXL final : public ProgramOpcode
{
public:
    SUB_A_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_IXL)
};

class SUB_IYL final : public ProgramOpcode
{
public:
    SUB_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_IYL)
};

class SUB_A_IYL final : public ProgramOpcode
{
public:
    SUB_A_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(SUB_A_IYL)
};

class SUB_mIXn final : public ProgramOpcode
{
public:
    SUB_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SUB_mIXn)
};

class SUB_A_mIXn final : public ProgramOpcode
{
public:
    SUB_A_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SUB_A_mIXn)
};

class SUB_mIYn final : public ProgramOpcode
{
public:
    SUB_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SUB_mIYn)
};

class SUB_A_mIYn final : public ProgramOpcode
{
public:
    SUB_A_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(SUB_A_mIYn)
};

class XOR_A final : public ProgramOpcode
{
public:
    XOR_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A)
};

class XOR_A_A final : public ProgramOpcode
{
public:
    XOR_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_A)
};

class XOR_B final : public ProgramOpcode
{
public:
    XOR_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_B)
};

class XOR_A_B final : public ProgramOpcode
{
public:
    XOR_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_B)
};

class XOR_C final : public ProgramOpcode
{
public:
    XOR_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_C)
};

class XOR_A_C final : public ProgramOpcode
{
public:
    XOR_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_C)
};

class XOR_D final : public ProgramOpcode
{
public:
    XOR_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_D)
};

class XOR_A_D final : public ProgramOpcode
{
public:
    XOR_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_D)
};

class XOR_E final : public ProgramOpcode
{
public:
    XOR_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_E)
};

class XOR_A_E final : public ProgramOpcode
{
public:
    XOR_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_E)
};

class XOR_H final : public ProgramOpcode
{
public:
    XOR_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_H)
};

class XOR_A_H final : public ProgramOpcode
{
public:
    XOR_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_H)
};

class XOR_L final : public ProgramOpcode
{
public:
    XOR_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_L)
};

class XOR_A_L final : public ProgramOpcode
{
public:
    XOR_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 4; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 4; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_L)
};

class XOR_n final : public ProgramOpcode
{
public:
    XOR_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(XOR_n)
};

class XOR_A_n final : public ProgramOpcode
{
public:
    XOR_A_n(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(XOR_A_n)
};

class XOR_mHL final : public ProgramOpcode
{
public:
    XOR_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_mHL)
};

class XOR_A_mHL final : public ProgramOpcode
{
public:
    XOR_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 1; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 7; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 7; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_mHL)
};

class XOR_mIXn final : public ProgramOpcode
{
public:
    XOR_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(XOR_mIXn)
};

class XOR_A_mIXn final : public ProgramOpcode
{
public:
    XOR_A_mIXn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(XOR_A_mIXn)
};

class XOR_mIYn final : public ProgramOpcode
{
public:
    XOR_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(XOR_mIYn)
};

class XOR_A_mIYn final : public ProgramOpcode
{
public:
    XOR_A_mIYn(const Token& token, std::unique_ptr<Expression> literal1)
        : ProgramOpcode(token)
        , mLiteral1(std::move(literal1))
    {
        Q_ASSERT(mLiteral1 != nullptr);
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 3; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 19; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 19; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

private:
    std::unique_ptr<Expression> mLiteral1;

    Q_DISABLE_COPY(XOR_A_mIYn)
};

class XOR_IXH final : public ProgramOpcode
{
public:
    XOR_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_IXH)
};

class XOR_A_IXH final : public ProgramOpcode
{
public:
    XOR_A_IXH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_IXH)
};

class XOR_IYH final : public ProgramOpcode
{
public:
    XOR_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_IYH)
};

class XOR_A_IYH final : public ProgramOpcode
{
public:
    XOR_A_IYH(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_IYH)
};

class XOR_IXL final : public ProgramOpcode
{
public:
    XOR_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_IXL)
};

class XOR_A_IXL final : public ProgramOpcode
{
public:
    XOR_A_IXL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_IXL)
};

class XOR_IYL final : public ProgramOpcode
{
public:
    XOR_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_IYL)
};

class XOR_A_IYL final : public ProgramOpcode
{
public:
    XOR_A_IYL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes(const Program*, IErrorReporter*) const final override { return 2; }
    unsigned tstatesIfNotTaken(const Program*, IErrorReporter*) const final override { return 8; }
    unsigned tstatesIfTaken(const Program*, IErrorReporter*) const final override { return 8; }

    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const final override;

    Q_DISABLE_COPY(XOR_A_IYL)
};

#endif
