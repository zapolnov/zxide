// THIS IS A GENERATED FILE. DO NOT EDIT!
#ifndef COMPILER_Z80OPCODES_H
#define COMPILER_Z80OPCODES_H

#include "ProgramOpcode.h"
#include "ProgramBinary.h"

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

class ADC_A_mHL : public ProgramOpcode
{
public:
    ADC_A_mHL(const Token& token)
        : ProgramOpcode(token)
    {
    }

    unsigned lengthInBytes() const override { return 1; }
    unsigned tstatesIfNotTaken() const override { return 4; }
    unsigned tstatesIfTaken() const override { return 4; }

    void emitBinary(ProgramBinary* bin) const override;

    Q_DISABLE_COPY(ADC_A_mHL)
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

#define PARSE_OPCODE \
    if (opcode == "adc") { \
        nextToken(); \
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") { \
            nextToken(); \
            if (lastTokenId() == T_COMMA) { \
                nextToken(); \
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") { \
                    nextToken(); \
                    if (lastTokenId() == T_EOL) { \
                        mSection->emit<ADC_A_A>(token); \
                        return; \
                    } \
                } \
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") { \
                    nextToken(); \
                    if (lastTokenId() == T_EOL) { \
                        mSection->emit<ADC_A_B>(token); \
                        return; \
                    } \
                } \
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") { \
                    nextToken(); \
                    if (lastTokenId() == T_EOL) { \
                        mSection->emit<ADC_A_C>(token); \
                        return; \
                    } \
                } \
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") { \
                    nextToken(); \
                    if (lastTokenId() == T_EOL) { \
                        mSection->emit<ADC_A_D>(token); \
                        return; \
                    } \
                } \
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") { \
                    nextToken(); \
                    if (lastTokenId() == T_EOL) { \
                        mSection->emit<ADC_A_E>(token); \
                        return; \
                    } \
                } \
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") { \
                    nextToken(); \
                    if (lastTokenId() == T_EOL) { \
                        mSection->emit<ADC_A_H>(token); \
                        return; \
                    } \
                } \
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") { \
                    nextToken(); \
                    if (lastTokenId() == T_EOL) { \
                        mSection->emit<ADC_A_L>(token); \
                        return; \
                    } \
                } \
                if (lastTokenId() == T_LPAREN) { \
                    nextToken(); \
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") { \
                        nextToken(); \
                        if (lastTokenId() == T_RPAREN) { \
                            nextToken(); \
                            if (lastTokenId() == T_EOL) { \
                                mSection->emit<ADC_A_mHL>(token); \
                                return; \
                            } \
                        } \
                    } \
                } \
                if (expectByteLiteral(&literal1)) { \
                    nextToken(); \
                    if (lastTokenId() == T_EOL) { \
                        mSection->emit<ADC_A_n>(token, literal1); \
                        return; \
                    } \
                } \
            } \
        } \
    } \
    if (opcode == "ccf") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<CCF>(token); \
            return; \
        } \
    } \
    if (opcode == "cpd") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<CPD>(token); \
            return; \
        } \
    } \
    if (opcode == "cpdr") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<CPDR>(token); \
            return; \
        } \
    } \
    if (opcode == "cpi") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<CPI>(token); \
            return; \
        } \
    } \
    if (opcode == "cpir") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<CPIR>(token); \
            return; \
        } \
    } \
    if (opcode == "cpl") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<CPL>(token); \
            return; \
        } \
    } \
    if (opcode == "daa") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<DAA>(token); \
            return; \
        } \
    } \
    if (opcode == "di") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<DI>(token); \
            return; \
        } \
    } \
    if (opcode == "ei") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<EI>(token); \
            return; \
        } \
    } \
    if (opcode == "exx") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<EXX>(token); \
            return; \
        } \
    } \
    if (opcode == "halt") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<HALT>(token); \
            return; \
        } \
    } \
    if (opcode == "ind") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<IND>(token); \
            return; \
        } \
    } \
    if (opcode == "indr") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<INDR>(token); \
            return; \
        } \
    } \
    if (opcode == "ini") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<INI>(token); \
            return; \
        } \
    } \
    if (opcode == "inir") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<INIR>(token); \
            return; \
        } \
    } \
    if (opcode == "ldd") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<LDD>(token); \
            return; \
        } \
    } \
    if (opcode == "lddr") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<LDDR>(token); \
            return; \
        } \
    } \
    if (opcode == "ldi") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<LDI>(token); \
            return; \
        } \
    } \
    if (opcode == "ldir") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<LDIR>(token); \
            return; \
        } \
    } \
    if (opcode == "otdr") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<OTDR>(token); \
            return; \
        } \
    } \
    if (opcode == "otir") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<OTIR>(token); \
            return; \
        } \
    } \
    if (opcode == "outd") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<OUTD>(token); \
            return; \
        } \
    } \
    if (opcode == "outi") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<OUTI>(token); \
            return; \
        } \
    } \
    if (opcode == "neg") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<NEG>(token); \
            return; \
        } \
    } \
    if (opcode == "nop") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<NOP>(token); \
            return; \
        } \
    } \
    if (opcode == "ret") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<RET>(token); \
            return; \
        } \
    } \
    if (opcode == "reti") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<RETI>(token); \
            return; \
        } \
    } \
    if (opcode == "retn") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<RETN>(token); \
            return; \
        } \
    } \
    if (opcode == "rla") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<RLA>(token); \
            return; \
        } \
    } \
    if (opcode == "rlca") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<RLCA>(token); \
            return; \
        } \
    } \
    if (opcode == "rld") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<RLD>(token); \
            return; \
        } \
    } \
    if (opcode == "rra") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<RRA>(token); \
            return; \
        } \
    } \
    if (opcode == "rrca") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<RRCA>(token); \
            return; \
        } \
    } \
    if (opcode == "rrd") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<RRD>(token); \
            return; \
        } \
    } \
    if (opcode == "scf") { \
        nextToken(); \
        if (lastTokenId() == T_EOL) { \
            mSection->emit<SCF>(token); \
            return; \
        } \
    } \

#endif
