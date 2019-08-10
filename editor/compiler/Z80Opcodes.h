// THIS IS A GENERATED FILE. DO NOT EDIT!
#ifndef COMPILER_Z80OPCODES_H
#define COMPILER_Z80OPCODES_H

#include "ProgramOpcode.h"

class ADC_A_A : public ProgramOpcode
{
public:
    ADC_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_A_A)
};

class ADC_A_B : public ProgramOpcode
{
public:
    ADC_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_A_B)
};

class ADC_A_C : public ProgramOpcode
{
public:
    ADC_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_A_C)
};

class ADC_A_D : public ProgramOpcode
{
public:
    ADC_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_A_D)
};

class ADC_A_E : public ProgramOpcode
{
public:
    ADC_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_A_E)
};

class ADC_A_H : public ProgramOpcode
{
public:
    ADC_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_A_H)
};

class ADC_A_L : public ProgramOpcode
{
public:
    ADC_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_A_L)
};

class ADC_A_n : public ProgramOpcode
{
public:
    ADC_A_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(ADC_A_n)
};

class ADC_A_mHL : public ProgramOpcode
{
public:
    ADC_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_A_mHL)
};

class ADC_A_mIXn : public ProgramOpcode
{
public:
    ADC_A_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(ADC_A_mIXn)
};

class ADC_A_mIYn : public ProgramOpcode
{
public:
    ADC_A_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(ADC_A_mIYn)
};

class ADC_HL_BC : public ProgramOpcode
{
public:
    ADC_HL_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_HL_BC)
};

class ADC_HL_DE : public ProgramOpcode
{
public:
    ADC_HL_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_HL_DE)
};

class ADC_HL_HL : public ProgramOpcode
{
public:
    ADC_HL_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_HL_HL)
};

class ADC_HL_SP : public ProgramOpcode
{
public:
    ADC_HL_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_HL_SP)
};

class ADD_A_A : public ProgramOpcode
{
public:
    ADD_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_A_A)
};

class ADD_A_B : public ProgramOpcode
{
public:
    ADD_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_A_B)
};

class ADD_A_C : public ProgramOpcode
{
public:
    ADD_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_A_C)
};

class ADD_A_D : public ProgramOpcode
{
public:
    ADD_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_A_D)
};

class ADD_A_E : public ProgramOpcode
{
public:
    ADD_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_A_E)
};

class ADD_A_H : public ProgramOpcode
{
public:
    ADD_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_A_H)
};

class ADD_A_L : public ProgramOpcode
{
public:
    ADD_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_A_L)
};

class ADD_A_n : public ProgramOpcode
{
public:
    ADD_A_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(ADD_A_n)
};

class ADD_A_mHL : public ProgramOpcode
{
public:
    ADD_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_A_mHL)
};

class ADD_A_mIXn : public ProgramOpcode
{
public:
    ADD_A_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(ADD_A_mIXn)
};

class ADD_A_mIYn : public ProgramOpcode
{
public:
    ADD_A_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(ADD_A_mIYn)
};

class ADD_HL_BC : public ProgramOpcode
{
public:
    ADD_HL_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 11; }
    unsigned tstatesIfTaken() const override { return 11; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_HL_BC)
};

class ADD_HL_DE : public ProgramOpcode
{
public:
    ADD_HL_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 11; }
    unsigned tstatesIfTaken() const override { return 11; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_HL_DE)
};

class ADD_HL_HL : public ProgramOpcode
{
public:
    ADD_HL_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 11; }
    unsigned tstatesIfTaken() const override { return 11; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_HL_HL)
};

class ADD_HL_SP : public ProgramOpcode
{
public:
    ADD_HL_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 11; }
    unsigned tstatesIfTaken() const override { return 11; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_HL_SP)
};

class ADD_IX_BC : public ProgramOpcode
{
public:
    ADD_IX_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_IX_BC)
};

class ADD_IX_DE : public ProgramOpcode
{
public:
    ADD_IX_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_IX_DE)
};

class ADD_IX_IX : public ProgramOpcode
{
public:
    ADD_IX_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_IX_IX)
};

class ADD_IX_SP : public ProgramOpcode
{
public:
    ADD_IX_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_IX_SP)
};

class ADD_IY_BC : public ProgramOpcode
{
public:
    ADD_IY_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_IY_BC)
};

class ADD_IY_DE : public ProgramOpcode
{
public:
    ADD_IY_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_IY_DE)
};

class ADD_IY_IY : public ProgramOpcode
{
public:
    ADD_IY_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_IY_IY)
};

class ADD_IY_SP : public ProgramOpcode
{
public:
    ADD_IY_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 15; }
    unsigned tstatesIfTaken() const override { return 15; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADD_IY_SP)
};

class AND_A : public ProgramOpcode
{
public:
    AND_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(AND_A)
};

class AND_B : public ProgramOpcode
{
public:
    AND_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(AND_B)
};

class AND_C : public ProgramOpcode
{
public:
    AND_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(AND_C)
};

class AND_D : public ProgramOpcode
{
public:
    AND_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(AND_D)
};

class AND_E : public ProgramOpcode
{
public:
    AND_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(AND_E)
};

class AND_H : public ProgramOpcode
{
public:
    AND_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(AND_H)
};

class AND_L : public ProgramOpcode
{
public:
    AND_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(AND_L)
};

class AND_n : public ProgramOpcode
{
public:
    AND_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(AND_n)
};

class AND_mHL : public ProgramOpcode
{
public:
    AND_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(AND_mHL)
};

class AND_mIXn : public ProgramOpcode
{
public:
    AND_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(AND_mIXn)
};

class AND_mIYn : public ProgramOpcode
{
public:
    AND_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(AND_mIYn)
};

class BIT_0_mHL : public ProgramOpcode
{
public:
    BIT_0_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_0_mHL)
};

class BIT_1_mHL : public ProgramOpcode
{
public:
    BIT_1_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_1_mHL)
};

class BIT_2_mHL : public ProgramOpcode
{
public:
    BIT_2_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_2_mHL)
};

class BIT_3_mHL : public ProgramOpcode
{
public:
    BIT_3_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_3_mHL)
};

class BIT_4_mHL : public ProgramOpcode
{
public:
    BIT_4_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_4_mHL)
};

class BIT_5_mHL : public ProgramOpcode
{
public:
    BIT_5_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_5_mHL)
};

class BIT_6_mHL : public ProgramOpcode
{
public:
    BIT_6_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_6_mHL)
};

class BIT_7_mHL : public ProgramOpcode
{
public:
    BIT_7_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_7_mHL)
};

class BIT_0_mIXn : public ProgramOpcode
{
public:
    BIT_0_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_0_mIXn)
};

class BIT_1_mIXn : public ProgramOpcode
{
public:
    BIT_1_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_1_mIXn)
};

class BIT_2_mIXn : public ProgramOpcode
{
public:
    BIT_2_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_2_mIXn)
};

class BIT_3_mIXn : public ProgramOpcode
{
public:
    BIT_3_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_3_mIXn)
};

class BIT_4_mIXn : public ProgramOpcode
{
public:
    BIT_4_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_4_mIXn)
};

class BIT_5_mIXn : public ProgramOpcode
{
public:
    BIT_5_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_5_mIXn)
};

class BIT_6_mIXn : public ProgramOpcode
{
public:
    BIT_6_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_6_mIXn)
};

class BIT_7_mIXn : public ProgramOpcode
{
public:
    BIT_7_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_7_mIXn)
};

class BIT_0_mIYn : public ProgramOpcode
{
public:
    BIT_0_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_0_mIYn)
};

class BIT_1_mIYn : public ProgramOpcode
{
public:
    BIT_1_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_1_mIYn)
};

class BIT_2_mIYn : public ProgramOpcode
{
public:
    BIT_2_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_2_mIYn)
};

class BIT_3_mIYn : public ProgramOpcode
{
public:
    BIT_3_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_3_mIYn)
};

class BIT_4_mIYn : public ProgramOpcode
{
public:
    BIT_4_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_4_mIYn)
};

class BIT_5_mIYn : public ProgramOpcode
{
public:
    BIT_5_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_5_mIYn)
};

class BIT_6_mIYn : public ProgramOpcode
{
public:
    BIT_6_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_6_mIYn)
};

class BIT_7_mIYn : public ProgramOpcode
{
public:
    BIT_7_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(BIT_7_mIYn)
};

class BIT_0_A : public ProgramOpcode
{
public:
    BIT_0_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_0_A)
};

class BIT_0_B : public ProgramOpcode
{
public:
    BIT_0_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_0_B)
};

class BIT_0_C : public ProgramOpcode
{
public:
    BIT_0_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_0_C)
};

class BIT_0_D : public ProgramOpcode
{
public:
    BIT_0_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_0_D)
};

class BIT_0_E : public ProgramOpcode
{
public:
    BIT_0_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_0_E)
};

class BIT_0_H : public ProgramOpcode
{
public:
    BIT_0_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_0_H)
};

class BIT_0_L : public ProgramOpcode
{
public:
    BIT_0_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_0_L)
};

class BIT_1_A : public ProgramOpcode
{
public:
    BIT_1_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_1_A)
};

class BIT_1_B : public ProgramOpcode
{
public:
    BIT_1_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_1_B)
};

class BIT_1_C : public ProgramOpcode
{
public:
    BIT_1_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_1_C)
};

class BIT_1_D : public ProgramOpcode
{
public:
    BIT_1_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_1_D)
};

class BIT_1_E : public ProgramOpcode
{
public:
    BIT_1_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_1_E)
};

class BIT_1_H : public ProgramOpcode
{
public:
    BIT_1_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_1_H)
};

class BIT_1_L : public ProgramOpcode
{
public:
    BIT_1_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_1_L)
};

class BIT_2_A : public ProgramOpcode
{
public:
    BIT_2_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_2_A)
};

class BIT_2_B : public ProgramOpcode
{
public:
    BIT_2_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_2_B)
};

class BIT_2_C : public ProgramOpcode
{
public:
    BIT_2_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_2_C)
};

class BIT_2_D : public ProgramOpcode
{
public:
    BIT_2_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_2_D)
};

class BIT_2_E : public ProgramOpcode
{
public:
    BIT_2_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_2_E)
};

class BIT_2_H : public ProgramOpcode
{
public:
    BIT_2_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_2_H)
};

class BIT_2_L : public ProgramOpcode
{
public:
    BIT_2_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_2_L)
};

class BIT_3_A : public ProgramOpcode
{
public:
    BIT_3_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_3_A)
};

class BIT_3_B : public ProgramOpcode
{
public:
    BIT_3_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_3_B)
};

class BIT_3_C : public ProgramOpcode
{
public:
    BIT_3_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_3_C)
};

class BIT_3_D : public ProgramOpcode
{
public:
    BIT_3_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_3_D)
};

class BIT_3_E : public ProgramOpcode
{
public:
    BIT_3_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_3_E)
};

class BIT_3_H : public ProgramOpcode
{
public:
    BIT_3_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_3_H)
};

class BIT_3_L : public ProgramOpcode
{
public:
    BIT_3_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_3_L)
};

class BIT_4_A : public ProgramOpcode
{
public:
    BIT_4_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_4_A)
};

class BIT_4_B : public ProgramOpcode
{
public:
    BIT_4_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_4_B)
};

class BIT_4_C : public ProgramOpcode
{
public:
    BIT_4_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_4_C)
};

class BIT_4_D : public ProgramOpcode
{
public:
    BIT_4_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_4_D)
};

class BIT_4_E : public ProgramOpcode
{
public:
    BIT_4_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_4_E)
};

class BIT_4_H : public ProgramOpcode
{
public:
    BIT_4_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_4_H)
};

class BIT_4_L : public ProgramOpcode
{
public:
    BIT_4_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_4_L)
};

class BIT_5_A : public ProgramOpcode
{
public:
    BIT_5_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_5_A)
};

class BIT_5_B : public ProgramOpcode
{
public:
    BIT_5_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_5_B)
};

class BIT_5_C : public ProgramOpcode
{
public:
    BIT_5_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_5_C)
};

class BIT_5_D : public ProgramOpcode
{
public:
    BIT_5_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_5_D)
};

class BIT_5_E : public ProgramOpcode
{
public:
    BIT_5_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_5_E)
};

class BIT_5_H : public ProgramOpcode
{
public:
    BIT_5_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_5_H)
};

class BIT_5_L : public ProgramOpcode
{
public:
    BIT_5_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_5_L)
};

class BIT_6_A : public ProgramOpcode
{
public:
    BIT_6_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_6_A)
};

class BIT_6_B : public ProgramOpcode
{
public:
    BIT_6_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_6_B)
};

class BIT_6_C : public ProgramOpcode
{
public:
    BIT_6_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_6_C)
};

class BIT_6_D : public ProgramOpcode
{
public:
    BIT_6_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_6_D)
};

class BIT_6_E : public ProgramOpcode
{
public:
    BIT_6_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_6_E)
};

class BIT_6_H : public ProgramOpcode
{
public:
    BIT_6_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_6_H)
};

class BIT_6_L : public ProgramOpcode
{
public:
    BIT_6_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_6_L)
};

class BIT_7_A : public ProgramOpcode
{
public:
    BIT_7_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_7_A)
};

class BIT_7_B : public ProgramOpcode
{
public:
    BIT_7_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_7_B)
};

class BIT_7_C : public ProgramOpcode
{
public:
    BIT_7_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_7_C)
};

class BIT_7_D : public ProgramOpcode
{
public:
    BIT_7_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_7_D)
};

class BIT_7_E : public ProgramOpcode
{
public:
    BIT_7_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_7_E)
};

class BIT_7_H : public ProgramOpcode
{
public:
    BIT_7_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_7_H)
};

class BIT_7_L : public ProgramOpcode
{
public:
    BIT_7_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(BIT_7_L)
};

class CALL_nn : public ProgramOpcode
{
public:
    CALL_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 17; }
    unsigned tstatesIfTaken() const override { return 17; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CALL_nn)
};

class CALL_C_nn : public ProgramOpcode
{
public:
    CALL_C_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 17; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CALL_C_nn)
};

class CALL_M_nn : public ProgramOpcode
{
public:
    CALL_M_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 17; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CALL_M_nn)
};

class CALL_NC_nn : public ProgramOpcode
{
public:
    CALL_NC_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 17; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CALL_NC_nn)
};

class CALL_NZ_nn : public ProgramOpcode
{
public:
    CALL_NZ_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 17; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CALL_NZ_nn)
};

class CALL_P_nn : public ProgramOpcode
{
public:
    CALL_P_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 17; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CALL_P_nn)
};

class CALL_PE_nn : public ProgramOpcode
{
public:
    CALL_PE_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 17; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CALL_PE_nn)
};

class CALL_PO_nn : public ProgramOpcode
{
public:
    CALL_PO_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 17; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CALL_PO_nn)
};

class CALL_Z_nn : public ProgramOpcode
{
public:
    CALL_Z_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 17; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CALL_Z_nn)
};

class CCF : public ProgramOpcode
{
public:
    CCF(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CCF)
};

class CP_A : public ProgramOpcode
{
public:
    CP_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CP_A)
};

class CP_B : public ProgramOpcode
{
public:
    CP_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CP_B)
};

class CP_C : public ProgramOpcode
{
public:
    CP_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CP_C)
};

class CP_D : public ProgramOpcode
{
public:
    CP_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CP_D)
};

class CP_E : public ProgramOpcode
{
public:
    CP_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CP_E)
};

class CP_H : public ProgramOpcode
{
public:
    CP_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CP_H)
};

class CP_L : public ProgramOpcode
{
public:
    CP_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CP_L)
};

class CP_n : public ProgramOpcode
{
public:
    CP_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CP_n)
};

class CP_mHL : public ProgramOpcode
{
public:
    CP_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CP_mHL)
};

class CP_mIXn : public ProgramOpcode
{
public:
    CP_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CP_mIXn)
};

class CP_mIYn : public ProgramOpcode
{
public:
    CP_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(CP_mIYn)
};

class CPD : public ProgramOpcode
{
public:
    CPD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CPD)
};

class CPDR : public ProgramOpcode
{
public:
    CPDR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 21; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CPDR)
};

class CPI : public ProgramOpcode
{
public:
    CPI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CPI)
};

class CPIR : public ProgramOpcode
{
public:
    CPIR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 21; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CPIR)
};

class CPL : public ProgramOpcode
{
public:
    CPL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(CPL)
};

class DAA : public ProgramOpcode
{
public:
    DAA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DAA)
};

class DEC_A : public ProgramOpcode
{
public:
    DEC_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_A)
};

class DEC_B : public ProgramOpcode
{
public:
    DEC_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_B)
};

class DEC_C : public ProgramOpcode
{
public:
    DEC_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_C)
};

class DEC_D : public ProgramOpcode
{
public:
    DEC_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_D)
};

class DEC_E : public ProgramOpcode
{
public:
    DEC_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_E)
};

class DEC_H : public ProgramOpcode
{
public:
    DEC_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_H)
};

class DEC_L : public ProgramOpcode
{
public:
    DEC_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_L)
};

class DEC_mHL : public ProgramOpcode
{
public:
    DEC_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 11; }
    unsigned tstatesIfTaken() const override { return 11; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_mHL)
};

class DEC_mIXn : public ProgramOpcode
{
public:
    DEC_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 23; }
    unsigned tstatesIfTaken() const override { return 23; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(DEC_mIXn)
};

class DEC_mIYn : public ProgramOpcode
{
public:
    DEC_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 23; }
    unsigned tstatesIfTaken() const override { return 23; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(DEC_mIYn)
};

class DEC_IX : public ProgramOpcode
{
public:
    DEC_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_IX)
};

class DEC_IY : public ProgramOpcode
{
public:
    DEC_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_IY)
};

class DEC_BC : public ProgramOpcode
{
public:
    DEC_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 6; }
    unsigned tstatesIfTaken() const override { return 6; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_BC)
};

class DEC_DE : public ProgramOpcode
{
public:
    DEC_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 6; }
    unsigned tstatesIfTaken() const override { return 6; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_DE)
};

class DEC_HL : public ProgramOpcode
{
public:
    DEC_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 6; }
    unsigned tstatesIfTaken() const override { return 6; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_HL)
};

class DEC_SP : public ProgramOpcode
{
public:
    DEC_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 6; }
    unsigned tstatesIfTaken() const override { return 6; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DEC_SP)
};

class DI : public ProgramOpcode
{
public:
    DI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(DI)
};

class DJNZ_n : public ProgramOpcode
{
public:
    DJNZ_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 13; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(DJNZ_n)
};

class EI : public ProgramOpcode
{
public:
    EI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(EI)
};

class EX_mSP_HL : public ProgramOpcode
{
public:
    EX_mSP_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(EX_mSP_HL)
};

class EX_mSP_IX : public ProgramOpcode
{
public:
    EX_mSP_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 23; }
    unsigned tstatesIfTaken() const override { return 23; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(EX_mSP_IX)
};

class EX_mSP_IY : public ProgramOpcode
{
public:
    EX_mSP_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 23; }
    unsigned tstatesIfTaken() const override { return 23; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(EX_mSP_IY)
};

class EX_AF_AFs : public ProgramOpcode
{
public:
    EX_AF_AFs(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(EX_AF_AFs)
};

class EX_DE_HL : public ProgramOpcode
{
public:
    EX_DE_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(EX_DE_HL)
};

class EXX : public ProgramOpcode
{
public:
    EXX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(EXX)
};

class HALT : public ProgramOpcode
{
public:
    HALT(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(HALT)
};

class IM_0 : public ProgramOpcode
{
public:
    IM_0(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IM_0)
};

class IM_1 : public ProgramOpcode
{
public:
    IM_1(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IM_1)
};

class IM_2 : public ProgramOpcode
{
public:
    IM_2(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IM_2)
};

class IN_A_mn : public ProgramOpcode
{
public:
    IN_A_mn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 11; }
    unsigned tstatesIfTaken() const override { return 11; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(IN_A_mn)
};

class IN_A_mC : public ProgramOpcode
{
public:
    IN_A_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IN_A_mC)
};

class IN_B_mC : public ProgramOpcode
{
public:
    IN_B_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IN_B_mC)
};

class IN_C_mC : public ProgramOpcode
{
public:
    IN_C_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IN_C_mC)
};

class IN_D_mC : public ProgramOpcode
{
public:
    IN_D_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IN_D_mC)
};

class IN_E_mC : public ProgramOpcode
{
public:
    IN_E_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IN_E_mC)
};

class IN_H_mC : public ProgramOpcode
{
public:
    IN_H_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IN_H_mC)
};

class IN_L_mC : public ProgramOpcode
{
public:
    IN_L_mC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IN_L_mC)
};

class INC_A : public ProgramOpcode
{
public:
    INC_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_A)
};

class INC_B : public ProgramOpcode
{
public:
    INC_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_B)
};

class INC_C : public ProgramOpcode
{
public:
    INC_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_C)
};

class INC_D : public ProgramOpcode
{
public:
    INC_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_D)
};

class INC_E : public ProgramOpcode
{
public:
    INC_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_E)
};

class INC_H : public ProgramOpcode
{
public:
    INC_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_H)
};

class INC_L : public ProgramOpcode
{
public:
    INC_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_L)
};

class INC_mHL : public ProgramOpcode
{
public:
    INC_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 11; }
    unsigned tstatesIfTaken() const override { return 11; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_mHL)
};

class INC_mIXn : public ProgramOpcode
{
public:
    INC_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 23; }
    unsigned tstatesIfTaken() const override { return 23; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(INC_mIXn)
};

class INC_mIYn : public ProgramOpcode
{
public:
    INC_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 23; }
    unsigned tstatesIfTaken() const override { return 23; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(INC_mIYn)
};

class INC_IX : public ProgramOpcode
{
public:
    INC_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_IX)
};

class INC_IY : public ProgramOpcode
{
public:
    INC_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_IY)
};

class INC_BC : public ProgramOpcode
{
public:
    INC_BC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 6; }
    unsigned tstatesIfTaken() const override { return 6; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_BC)
};

class INC_DE : public ProgramOpcode
{
public:
    INC_DE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 6; }
    unsigned tstatesIfTaken() const override { return 6; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_DE)
};

class INC_HL : public ProgramOpcode
{
public:
    INC_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 6; }
    unsigned tstatesIfTaken() const override { return 6; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_HL)
};

class INC_SP : public ProgramOpcode
{
public:
    INC_SP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 6; }
    unsigned tstatesIfTaken() const override { return 6; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INC_SP)
};

class IND : public ProgramOpcode
{
public:
    IND(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(IND)
};

class INDR : public ProgramOpcode
{
public:
    INDR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 21; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INDR)
};

class INI : public ProgramOpcode
{
public:
    INI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INI)
};

class INIR : public ProgramOpcode
{
public:
    INIR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 21; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(INIR)
};

class JP_nn : public ProgramOpcode
{
public:
    JP_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JP_nn)
};

class JP_C_nn : public ProgramOpcode
{
public:
    JP_C_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JP_C_nn)
};

class JP_M_nn : public ProgramOpcode
{
public:
    JP_M_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JP_M_nn)
};

class JP_NC_nn : public ProgramOpcode
{
public:
    JP_NC_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JP_NC_nn)
};

class JP_NZ_nn : public ProgramOpcode
{
public:
    JP_NZ_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JP_NZ_nn)
};

class JP_P_nn : public ProgramOpcode
{
public:
    JP_P_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JP_P_nn)
};

class JP_PE_nn : public ProgramOpcode
{
public:
    JP_PE_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JP_PE_nn)
};

class JP_PO_nn : public ProgramOpcode
{
public:
    JP_PO_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JP_PO_nn)
};

class JP_Z_nn : public ProgramOpcode
{
public:
    JP_Z_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JP_Z_nn)
};

class JP_mHL : public ProgramOpcode
{
public:
    JP_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(JP_mHL)
};

class JP_mIX : public ProgramOpcode
{
public:
    JP_mIX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(JP_mIX)
};

class JP_mIY : public ProgramOpcode
{
public:
    JP_mIY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(JP_mIY)
};

class JR_off : public ProgramOpcode
{
public:
    JR_off(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 12; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JR_off)
};

class JR_C_off : public ProgramOpcode
{
public:
    JR_C_off(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JR_C_off)
};

class JR_NC_off : public ProgramOpcode
{
public:
    JR_NC_off(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JR_NC_off)
};

class JR_NZ_off : public ProgramOpcode
{
public:
    JR_NZ_off(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JR_NZ_off)
};

class JR_Z_off : public ProgramOpcode
{
public:
    JR_Z_off(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 12; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(JR_Z_off)
};

class LD_A_mBC : public ProgramOpcode
{
public:
    LD_A_mBC(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_mBC)
};

class LD_A_mDE : public ProgramOpcode
{
public:
    LD_A_mDE(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_mDE)
};

class LD_A_I : public ProgramOpcode
{
public:
    LD_A_I(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 9; }
    unsigned tstatesIfTaken() const override { return 9; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_I)
};

class LD_A_mnn : public ProgramOpcode
{
public:
    LD_A_mnn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 13; }
    unsigned tstatesIfTaken() const override { return 13; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_A_mnn)
};

class LD_A_R : public ProgramOpcode
{
public:
    LD_A_R(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 9; }
    unsigned tstatesIfTaken() const override { return 9; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_R)
};

class LD_mBC_A : public ProgramOpcode
{
public:
    LD_mBC_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_mBC_A)
};

class LD_mDE_A : public ProgramOpcode
{
public:
    LD_mDE_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_mDE_A)
};

class LD_mHL_n : public ProgramOpcode
{
public:
    LD_mHL_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mHL_n)
};

class LD_mIXn_n : public ProgramOpcode
{
public:
    LD_mIXn_n(const Token& token, unsigned literal1, unsigned literal2)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
        , mLiteral2(literal2)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;
    unsigned mLiteral2;

    Q_DISABLE_COPY(LD_mIXn_n)
};

class LD_mIYn_n : public ProgramOpcode
{
public:
    LD_mIYn_n(const Token& token, unsigned literal1, unsigned literal2)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
        , mLiteral2(literal2)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;
    unsigned mLiteral2;

    Q_DISABLE_COPY(LD_mIYn_n)
};

class LD_mnn_A : public ProgramOpcode
{
public:
    LD_mnn_A(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 13; }
    unsigned tstatesIfTaken() const override { return 13; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mnn_A)
};

class LD_mnn_BC : public ProgramOpcode
{
public:
    LD_mnn_BC(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mnn_BC)
};

class LD_mnn_DE : public ProgramOpcode
{
public:
    LD_mnn_DE(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mnn_DE)
};

class LD_mnn_HL : public ProgramOpcode
{
public:
    LD_mnn_HL(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mnn_HL)
};

class LD_mnn_SP : public ProgramOpcode
{
public:
    LD_mnn_SP(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mnn_SP)
};

class LD_mnn_IX : public ProgramOpcode
{
public:
    LD_mnn_IX(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mnn_IX)
};

class LD_mnn_IY : public ProgramOpcode
{
public:
    LD_mnn_IY(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mnn_IY)
};

class LD_BC_nn : public ProgramOpcode
{
public:
    LD_BC_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_BC_nn)
};

class LD_DE_nn : public ProgramOpcode
{
public:
    LD_DE_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_DE_nn)
};

class LD_HL_nn : public ProgramOpcode
{
public:
    LD_HL_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_HL_nn)
};

class LD_SP_nn : public ProgramOpcode
{
public:
    LD_SP_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_SP_nn)
};

class LD_BC_mnn : public ProgramOpcode
{
public:
    LD_BC_mnn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_BC_mnn)
};

class LD_DE_mnn : public ProgramOpcode
{
public:
    LD_DE_mnn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_DE_mnn)
};

class LD_HL_mnn : public ProgramOpcode
{
public:
    LD_HL_mnn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_HL_mnn)
};

class LD_SP_mnn : public ProgramOpcode
{
public:
    LD_SP_mnn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_SP_mnn)
};

class LD_mHL_A : public ProgramOpcode
{
public:
    LD_mHL_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_mHL_A)
};

class LD_mHL_B : public ProgramOpcode
{
public:
    LD_mHL_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_mHL_B)
};

class LD_mHL_C : public ProgramOpcode
{
public:
    LD_mHL_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_mHL_C)
};

class LD_mHL_D : public ProgramOpcode
{
public:
    LD_mHL_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_mHL_D)
};

class LD_mHL_E : public ProgramOpcode
{
public:
    LD_mHL_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_mHL_E)
};

class LD_mHL_H : public ProgramOpcode
{
public:
    LD_mHL_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_mHL_H)
};

class LD_mHL_L : public ProgramOpcode
{
public:
    LD_mHL_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_mHL_L)
};

class LD_mIXn_A : public ProgramOpcode
{
public:
    LD_mIXn_A(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_A)
};

class LD_mIXn_B : public ProgramOpcode
{
public:
    LD_mIXn_B(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_B)
};

class LD_mIXn_C : public ProgramOpcode
{
public:
    LD_mIXn_C(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_C)
};

class LD_mIXn_D : public ProgramOpcode
{
public:
    LD_mIXn_D(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_D)
};

class LD_mIXn_E : public ProgramOpcode
{
public:
    LD_mIXn_E(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_E)
};

class LD_mIXn_H : public ProgramOpcode
{
public:
    LD_mIXn_H(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_H)
};

class LD_mIXn_L : public ProgramOpcode
{
public:
    LD_mIXn_L(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIXn_L)
};

class LD_mIYn_A : public ProgramOpcode
{
public:
    LD_mIYn_A(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_A)
};

class LD_mIYn_B : public ProgramOpcode
{
public:
    LD_mIYn_B(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_B)
};

class LD_mIYn_C : public ProgramOpcode
{
public:
    LD_mIYn_C(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_C)
};

class LD_mIYn_D : public ProgramOpcode
{
public:
    LD_mIYn_D(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_D)
};

class LD_mIYn_E : public ProgramOpcode
{
public:
    LD_mIYn_E(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_E)
};

class LD_mIYn_H : public ProgramOpcode
{
public:
    LD_mIYn_H(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_H)
};

class LD_mIYn_L : public ProgramOpcode
{
public:
    LD_mIYn_L(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_mIYn_L)
};

class LD_I_A : public ProgramOpcode
{
public:
    LD_I_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 9; }
    unsigned tstatesIfTaken() const override { return 9; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_I_A)
};

class LD_IX_nn : public ProgramOpcode
{
public:
    LD_IX_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 14; }
    unsigned tstatesIfTaken() const override { return 14; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_IX_nn)
};

class LD_IX_mnn : public ProgramOpcode
{
public:
    LD_IX_mnn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_IX_mnn)
};

class LD_IY_nn : public ProgramOpcode
{
public:
    LD_IY_nn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 14; }
    unsigned tstatesIfTaken() const override { return 14; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_IY_nn)
};

class LD_IY_mnn : public ProgramOpcode
{
public:
    LD_IY_mnn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 4; }
    unsigned tstatesIfNotTaken() const override { return 20; }
    unsigned tstatesIfTaken() const override { return 20; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_IY_mnn)
};

class LD_R_A : public ProgramOpcode
{
public:
    LD_R_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 9; }
    unsigned tstatesIfTaken() const override { return 9; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_R_A)
};

class LD_A_mHL : public ProgramOpcode
{
public:
    LD_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_mHL)
};

class LD_B_mHL : public ProgramOpcode
{
public:
    LD_B_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_B_mHL)
};

class LD_C_mHL : public ProgramOpcode
{
public:
    LD_C_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_C_mHL)
};

class LD_D_mHL : public ProgramOpcode
{
public:
    LD_D_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_D_mHL)
};

class LD_E_mHL : public ProgramOpcode
{
public:
    LD_E_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_E_mHL)
};

class LD_H_mHL : public ProgramOpcode
{
public:
    LD_H_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_H_mHL)
};

class LD_L_mHL : public ProgramOpcode
{
public:
    LD_L_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_L_mHL)
};

class LD_A_mIXn : public ProgramOpcode
{
public:
    LD_A_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_A_mIXn)
};

class LD_B_mIXn : public ProgramOpcode
{
public:
    LD_B_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_B_mIXn)
};

class LD_C_mIXn : public ProgramOpcode
{
public:
    LD_C_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_C_mIXn)
};

class LD_D_mIXn : public ProgramOpcode
{
public:
    LD_D_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_D_mIXn)
};

class LD_E_mIXn : public ProgramOpcode
{
public:
    LD_E_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_E_mIXn)
};

class LD_H_mIXn : public ProgramOpcode
{
public:
    LD_H_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_H_mIXn)
};

class LD_L_mIXn : public ProgramOpcode
{
public:
    LD_L_mIXn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_L_mIXn)
};

class LD_A_mIYn : public ProgramOpcode
{
public:
    LD_A_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_A_mIYn)
};

class LD_B_mIYn : public ProgramOpcode
{
public:
    LD_B_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_B_mIYn)
};

class LD_C_mIYn : public ProgramOpcode
{
public:
    LD_C_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_C_mIYn)
};

class LD_D_mIYn : public ProgramOpcode
{
public:
    LD_D_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_D_mIYn)
};

class LD_E_mIYn : public ProgramOpcode
{
public:
    LD_E_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_E_mIYn)
};

class LD_H_mIYn : public ProgramOpcode
{
public:
    LD_H_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_H_mIYn)
};

class LD_L_mIYn : public ProgramOpcode
{
public:
    LD_L_mIYn(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 3; }
    unsigned tstatesIfNotTaken() const override { return 19; }
    unsigned tstatesIfTaken() const override { return 19; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_L_mIYn)
};

class LD_A_n : public ProgramOpcode
{
public:
    LD_A_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_A_n)
};

class LD_B_n : public ProgramOpcode
{
public:
    LD_B_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_B_n)
};

class LD_C_n : public ProgramOpcode
{
public:
    LD_C_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_C_n)
};

class LD_D_n : public ProgramOpcode
{
public:
    LD_D_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_D_n)
};

class LD_E_n : public ProgramOpcode
{
public:
    LD_E_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_E_n)
};

class LD_H_n : public ProgramOpcode
{
public:
    LD_H_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_H_n)
};

class LD_L_n : public ProgramOpcode
{
public:
    LD_L_n(const Token& token, unsigned literal1)
        : ProgramOpcode(token)
        , mLiteral1(literal1)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 7; }
    unsigned tstatesIfTaken() const override { return 7; }

    void emitBinary(ProgramBinary* bin) const override;

private:
    unsigned mLiteral1;

    Q_DISABLE_COPY(LD_L_n)
};

class LD_A_A : public ProgramOpcode
{
public:
    LD_A_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_A)
};

class LD_B_A : public ProgramOpcode
{
public:
    LD_B_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_B_A)
};

class LD_C_A : public ProgramOpcode
{
public:
    LD_C_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_C_A)
};

class LD_D_A : public ProgramOpcode
{
public:
    LD_D_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_D_A)
};

class LD_E_A : public ProgramOpcode
{
public:
    LD_E_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_E_A)
};

class LD_H_A : public ProgramOpcode
{
public:
    LD_H_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_H_A)
};

class LD_L_A : public ProgramOpcode
{
public:
    LD_L_A(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_L_A)
};

class LD_A_B : public ProgramOpcode
{
public:
    LD_A_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_B)
};

class LD_B_B : public ProgramOpcode
{
public:
    LD_B_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_B_B)
};

class LD_C_B : public ProgramOpcode
{
public:
    LD_C_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_C_B)
};

class LD_D_B : public ProgramOpcode
{
public:
    LD_D_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_D_B)
};

class LD_E_B : public ProgramOpcode
{
public:
    LD_E_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_E_B)
};

class LD_H_B : public ProgramOpcode
{
public:
    LD_H_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_H_B)
};

class LD_L_B : public ProgramOpcode
{
public:
    LD_L_B(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_L_B)
};

class LD_A_C : public ProgramOpcode
{
public:
    LD_A_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_C)
};

class LD_B_C : public ProgramOpcode
{
public:
    LD_B_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_B_C)
};

class LD_C_C : public ProgramOpcode
{
public:
    LD_C_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_C_C)
};

class LD_D_C : public ProgramOpcode
{
public:
    LD_D_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_D_C)
};

class LD_E_C : public ProgramOpcode
{
public:
    LD_E_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_E_C)
};

class LD_H_C : public ProgramOpcode
{
public:
    LD_H_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_H_C)
};

class LD_L_C : public ProgramOpcode
{
public:
    LD_L_C(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_L_C)
};

class LD_A_D : public ProgramOpcode
{
public:
    LD_A_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_D)
};

class LD_B_D : public ProgramOpcode
{
public:
    LD_B_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_B_D)
};

class LD_C_D : public ProgramOpcode
{
public:
    LD_C_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_C_D)
};

class LD_D_D : public ProgramOpcode
{
public:
    LD_D_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_D_D)
};

class LD_E_D : public ProgramOpcode
{
public:
    LD_E_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_E_D)
};

class LD_H_D : public ProgramOpcode
{
public:
    LD_H_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_H_D)
};

class LD_L_D : public ProgramOpcode
{
public:
    LD_L_D(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_L_D)
};

class LD_A_E : public ProgramOpcode
{
public:
    LD_A_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_E)
};

class LD_B_E : public ProgramOpcode
{
public:
    LD_B_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_B_E)
};

class LD_C_E : public ProgramOpcode
{
public:
    LD_C_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_C_E)
};

class LD_D_E : public ProgramOpcode
{
public:
    LD_D_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_D_E)
};

class LD_E_E : public ProgramOpcode
{
public:
    LD_E_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_E_E)
};

class LD_H_E : public ProgramOpcode
{
public:
    LD_H_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_H_E)
};

class LD_L_E : public ProgramOpcode
{
public:
    LD_L_E(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_L_E)
};

class LD_A_H : public ProgramOpcode
{
public:
    LD_A_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_H)
};

class LD_B_H : public ProgramOpcode
{
public:
    LD_B_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_B_H)
};

class LD_C_H : public ProgramOpcode
{
public:
    LD_C_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_C_H)
};

class LD_D_H : public ProgramOpcode
{
public:
    LD_D_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_D_H)
};

class LD_E_H : public ProgramOpcode
{
public:
    LD_E_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_E_H)
};

class LD_H_H : public ProgramOpcode
{
public:
    LD_H_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_H_H)
};

class LD_L_H : public ProgramOpcode
{
public:
    LD_L_H(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_L_H)
};

class LD_A_L : public ProgramOpcode
{
public:
    LD_A_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_A_L)
};

class LD_B_L : public ProgramOpcode
{
public:
    LD_B_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_B_L)
};

class LD_C_L : public ProgramOpcode
{
public:
    LD_C_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_C_L)
};

class LD_D_L : public ProgramOpcode
{
public:
    LD_D_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_D_L)
};

class LD_E_L : public ProgramOpcode
{
public:
    LD_E_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_E_L)
};

class LD_H_L : public ProgramOpcode
{
public:
    LD_H_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_H_L)
};

class LD_L_L : public ProgramOpcode
{
public:
    LD_L_L(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_L_L)
};

class LD_SP_HL : public ProgramOpcode
{
public:
    LD_SP_HL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 6; }
    unsigned tstatesIfTaken() const override { return 6; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_SP_HL)
};

class LD_SP_IX : public ProgramOpcode
{
public:
    LD_SP_IX(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_SP_IX)
};

class LD_SP_IY : public ProgramOpcode
{
public:
    LD_SP_IY(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LD_SP_IY)
};

class LDD : public ProgramOpcode
{
public:
    LDD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LDD)
};

class LDDR : public ProgramOpcode
{
public:
    LDDR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 21; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LDDR)
};

class LDI : public ProgramOpcode
{
public:
    LDI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LDI)
};

class LDIR : public ProgramOpcode
{
public:
    LDIR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 17; }
    unsigned tstatesIfTaken() const override { return 21; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(LDIR)
};

class NEG : public ProgramOpcode
{
public:
    NEG(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 8; }
    unsigned tstatesIfTaken() const override { return 8; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(NEG)
};

class NOP : public ProgramOpcode
{
public:
    NOP(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(NOP)
};

class OTDR : public ProgramOpcode
{
public:
    OTDR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 21; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(OTDR)
};

class OTIR : public ProgramOpcode
{
public:
    OTIR(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 21; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(OTIR)
};

class OUTD : public ProgramOpcode
{
public:
    OUTD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(OUTD)
};

class OUTI : public ProgramOpcode
{
public:
    OUTI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 16; }
    unsigned tstatesIfTaken() const override { return 16; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(OUTI)
};

class RET : public ProgramOpcode
{
public:
    RET(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 10; }
    unsigned tstatesIfTaken() const override { return 10; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(RET)
};

class RETI : public ProgramOpcode
{
public:
    RETI(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 14; }
    unsigned tstatesIfTaken() const override { return 14; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(RETI)
};

class RETN : public ProgramOpcode
{
public:
    RETN(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 14; }
    unsigned tstatesIfTaken() const override { return 14; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(RETN)
};

class RLA : public ProgramOpcode
{
public:
    RLA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(RLA)
};

class RLCA : public ProgramOpcode
{
public:
    RLCA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(RLCA)
};

class RLD : public ProgramOpcode
{
public:
    RLD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 18; }
    unsigned tstatesIfTaken() const override { return 18; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(RLD)
};

class RRA : public ProgramOpcode
{
public:
    RRA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(RRA)
};

class RRCA : public ProgramOpcode
{
public:
    RRCA(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(RRCA)
};

class RRD : public ProgramOpcode
{
public:
    RRD(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 2; }
    unsigned tstatesIfNotTaken() const override { return 18; }
    unsigned tstatesIfTaken() const override { return 18; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(RRD)
};

class SCF : public ProgramOpcode
{
public:
    SCF(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(SCF)
};

#endif
