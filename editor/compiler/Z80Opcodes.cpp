// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"

void ADC_A_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x8F);
}

void ADC_A_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x88);
}

void ADC_A_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x89);
}

void ADC_A_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x8A);
}

void ADC_A_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x8B);
}

void ADC_A_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x8C);
}

void ADC_A_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x8D);
}

void ADC_A_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x8E);
}

void ADC_A_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCE);
    bin->emitByte(mLiteral1 & 0xFF);
}

void CCF::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x3F);
}

void CPD::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA9);
}

void CPDR::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB9);
}

void CPI::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA1);
}

void CPIR::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB1);
}

void CPL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x2F);
}

void DAA::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x27);
}

void DI::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xF3);
}

void EI::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFB);
}

void EXX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xD9);
}

void HALT::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x76);
}

void IND::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xAA);
}

void INDR::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xBA);
}

void INI::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA2);
}

void INIR::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB2);
}

void LDD::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA8);
}

void LDDR::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB8);
}

void LDI::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA0);
}

void LDIR::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB0);
}

void OTDR::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xBB);
}

void OTIR::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB3);
}

void OUTD::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xAB);
}

void OUTI::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA3);
}

void NEG::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x44);
}

void NOP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x00);
}

void RET::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xC9);
}

void RETI::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x4D);
}

void RETN::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x45);
}

void RLA::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x17);
}

void RLCA::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x07);
}

void RLD::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x6F);
}

void RRA::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x1F);
}

void RRCA::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x0F);
}

void RRD::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x67);
}

void SCF::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x37);
}
