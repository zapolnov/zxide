// THIS IS A GENERATED FILE. DO NOT EDIT!
#ifndef COMPILER_Z80OPCODES_H
#define COMPILER_Z80OPCODES_H

#include "ProgramOpcode.h"
#include "ProgramBinary.h"

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
