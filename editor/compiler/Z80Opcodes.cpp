// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"
#include "ProgramSection.h"
#include "ProgramBinary.h"
#include "AssemblerParser.h"
#include "AssemblerToken.h"

#ifdef emit
#undef emit
#endif

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

void ADC_A_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCE);
    bin->emitByte(mLiteral1 & 0xFF);
}

void ADC_A_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x8E);
}

void ADC_A_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x8E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void ADC_A_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x8E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void ADC_HL_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x4A);
}

void ADC_HL_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x5A);
}

void ADC_HL_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x6A);
}

void ADC_HL_SP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x7A);
}

void ADD_A_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x87);
}

void ADD_A_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x80);
}

void ADD_A_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x81);
}

void ADD_A_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x82);
}

void ADD_A_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x83);
}

void ADD_A_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x84);
}

void ADD_A_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x85);
}

void ADD_A_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xC6);
    bin->emitByte(mLiteral1 & 0xFF);
}

void ADD_A_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x86);
}

void ADD_A_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x86);
    bin->emitByte(mLiteral1 & 0xFF);
}

void ADD_A_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x86);
    bin->emitByte(mLiteral1 & 0xFF);
}

void ADD_HL_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x09);
}

void ADD_HL_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x19);
}

void ADD_HL_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x29);
}

void ADD_HL_SP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x39);
}

void ADD_IX_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x09);
}

void ADD_IX_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x19);
}

void ADD_IX_IX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x29);
}

void ADD_IX_SP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x39);
}

void ADD_IY_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x09);
}

void ADD_IY_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x19);
}

void ADD_IY_IY::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x29);
}

void ADD_IY_SP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x39);
}

void AND_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA7);
}

void AND_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA0);
}

void AND_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA1);
}

void AND_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA2);
}

void AND_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA3);
}

void AND_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA4);
}

void AND_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA5);
}

void AND_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xE6);
    bin->emitByte(mLiteral1 & 0xFF);
}

void AND_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA6);
}

void AND_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xA6);
    bin->emitByte(mLiteral1 & 0xFF);
}

void AND_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xA6);
    bin->emitByte(mLiteral1 & 0xFF);
}

void BIT_0_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x46);
}

void BIT_1_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4E);
}

void BIT_2_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x56);
}

void BIT_3_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5E);
}

void BIT_4_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x66);
}

void BIT_5_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6E);
}

void BIT_6_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x76);
}

void BIT_7_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7E);
}

void BIT_0_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x46);
}

void BIT_1_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x4E);
}

void BIT_2_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x56);
}

void BIT_3_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x5E);
}

void BIT_4_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x66);
}

void BIT_5_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x6E);
}

void BIT_6_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x76);
}

void BIT_7_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x7E);
}

void BIT_0_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x46);
}

void BIT_1_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x4E);
}

void BIT_2_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x56);
}

void BIT_3_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x5E);
}

void BIT_4_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x66);
}

void BIT_5_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x6E);
}

void BIT_6_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x76);
}

void BIT_7_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x7E);
}

void BIT_0_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x47);
}

void BIT_0_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x40);
}

void BIT_0_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x41);
}

void BIT_0_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x42);
}

void BIT_0_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x43);
}

void BIT_0_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x44);
}

void BIT_0_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x45);
}

void BIT_1_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4F);
}

void BIT_1_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x48);
}

void BIT_1_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x49);
}

void BIT_1_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4A);
}

void BIT_1_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4B);
}

void BIT_1_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4C);
}

void BIT_1_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4D);
}

void BIT_2_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x57);
}

void BIT_2_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x50);
}

void BIT_2_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x51);
}

void BIT_2_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x52);
}

void BIT_2_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x53);
}

void BIT_2_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x54);
}

void BIT_2_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x55);
}

void BIT_3_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5F);
}

void BIT_3_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x58);
}

void BIT_3_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x59);
}

void BIT_3_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5A);
}

void BIT_3_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5B);
}

void BIT_3_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5C);
}

void BIT_3_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5D);
}

void BIT_4_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x67);
}

void BIT_4_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x60);
}

void BIT_4_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x61);
}

void BIT_4_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x62);
}

void BIT_4_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x63);
}

void BIT_4_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x64);
}

void BIT_4_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x65);
}

void BIT_5_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6F);
}

void BIT_5_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x68);
}

void BIT_5_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x69);
}

void BIT_5_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6A);
}

void BIT_5_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6B);
}

void BIT_5_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6C);
}

void BIT_5_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6D);
}

void BIT_6_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x77);
}

void BIT_6_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x70);
}

void BIT_6_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x71);
}

void BIT_6_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x72);
}

void BIT_6_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x73);
}

void BIT_6_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x74);
}

void BIT_6_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x75);
}

void BIT_7_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7F);
}

void BIT_7_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x78);
}

void BIT_7_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x79);
}

void BIT_7_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7A);
}

void BIT_7_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7B);
}

void BIT_7_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7C);
}

void BIT_7_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7D);
}

void CALL_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCD);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void CALL_C_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDC);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void CALL_M_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFC);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void CALL_NC_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xD4);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void CALL_NZ_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xC4);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void CALL_P_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xF4);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void CALL_PE_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xEC);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void CALL_PO_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xE4);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void CALL_Z_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCC);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
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

bool AssemblerParser::parseOpcode_generated(const std::string& opcode)
{
    unsigned literal1, literal2;
    Token token = lastToken();
    if (opcode == "adc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_L>(token);
                        return true;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<ADC_A_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<ADC_A_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<ADC_A_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_SP>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "add") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_L>(token);
                        return true;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<ADD_A_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<ADD_A_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<ADD_A_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_SP>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_IX>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_SP>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_IY>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_SP>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "and") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<AND_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<AND_mIXn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<AND_mIYn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "bit") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_0_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_0_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_0_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 1) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_1_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_1_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_1_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 2) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_2_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_2_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_2_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 3) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_3_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_3_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_3_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 4) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_4_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_4_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_4_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 5) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_5_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_5_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_5_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 6) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_6_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_6_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_6_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 7) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<BIT_7_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_7_mIXn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<BIT_7_mIYn>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "call") {
        nextToken();
        if (expectWordLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CALL_nn>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_C_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "m") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_M_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "nc") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_NC_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "nz") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_NZ_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "p") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_P_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "pe") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_PE_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "po") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_PO_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && lastTokenText() == "z") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CALL_Z_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    if (opcode == "ccf") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CCF>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cpd") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cpdr") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPDR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cpi") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cpir") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPIR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "cpl") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<CPL>(token);
            return true;
        }
        return false;
    }
    if (opcode == "daa") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<DAA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "di") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<DI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ei") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<EI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "exx") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<EXX>(token);
            return true;
        }
        return false;
    }
    if (opcode == "halt") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<HALT>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ind") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<IND>(token);
            return true;
        }
        return false;
    }
    if (opcode == "indr") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<INDR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ini") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<INI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "inir") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<INIR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ldd") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<LDD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "lddr") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<LDDR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ldi") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<LDI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ldir") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<LDIR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "otdr") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<OTDR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "otir") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<OTIR>(token);
            return true;
        }
        return false;
    }
    if (opcode == "outd") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<OUTD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "outi") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<OUTI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "neg") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<NEG>(token);
            return true;
        }
        return false;
    }
    if (opcode == "nop") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<NOP>(token);
            return true;
        }
        return false;
    }
    if (opcode == "ret") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RET>(token);
            return true;
        }
        return false;
    }
    if (opcode == "reti") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RETI>(token);
            return true;
        }
        return false;
    }
    if (opcode == "retn") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RETN>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rla") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RLA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rlca") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RLCA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rld") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RLD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rra") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RRA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rrca") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RRCA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rrd") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RRD>(token);
            return true;
        }
        return false;
    }
    if (opcode == "scf") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<SCF>(token);
            return true;
        }
        return false;
    }
    return false;
    return false;
}
