// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"
#include "ProgramSection.h"
#include "ProgramBinary.h"
#include "AssemblerParser.h"
#include "AssemblerToken.h"
#include "Util.h"

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

void CP_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xBF);
}

void CP_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB8);
}

void CP_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB9);
}

void CP_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xBA);
}

void CP_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xBB);
}

void CP_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xBC);
}

void CP_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xBD);
}

void CP_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFE);
    bin->emitByte(mLiteral1 & 0xFF);
}

void CP_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xBE);
}

void CP_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xBE);
    bin->emitByte(mLiteral1 & 0xFF);
}

void CP_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xBE);
    bin->emitByte(mLiteral1 & 0xFF);
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

void DEC_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x3D);
}

void DEC_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x05);
}

void DEC_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x0D);
}

void DEC_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x15);
}

void DEC_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x1D);
}

void DEC_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x25);
}

void DEC_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x2D);
}

void DEC_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x35);
}

void DEC_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x35);
    bin->emitByte(mLiteral1 & 0xFF);
}

void DEC_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x35);
    bin->emitByte(mLiteral1 & 0xFF);
}

void DEC_IX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x2B);
}

void DEC_IY::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x2B);
}

void DEC_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x0B);
}

void DEC_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x1B);
}

void DEC_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x2B);
}

void DEC_SP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x3B);
}

void DI::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xF3);
}

void DJNZ_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x10);
    bin->emitByte(mLiteral1 & 0xFF);
}

void EI::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFB);
}

void EX_mSP_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xE3);
}

void EX_mSP_IX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xE3);
}

void EX_mSP_IY::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xE3);
}

void EX_AF_AFs::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x08);
}

void EX_DE_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xEB);
}

void EXX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xD9);
}

void HALT::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x76);
}

void IM_0::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x46);
}

void IM_1::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x56);
}

void IM_2::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x5E);
}

void IN_A_mn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDB);
    bin->emitByte(mLiteral1 & 0xFF);
}

void IN_A_mC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x78);
}

void IN_B_mC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x40);
}

void IN_C_mC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x48);
}

void IN_D_mC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x50);
}

void IN_E_mC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x58);
}

void IN_H_mC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x60);
}

void IN_L_mC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x68);
}

void INC_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x3C);
}

void INC_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x04);
}

void INC_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x0C);
}

void INC_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x14);
}

void INC_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x1C);
}

void INC_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x24);
}

void INC_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x2C);
}

void INC_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x34);
}

void INC_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x34);
    bin->emitByte(mLiteral1 & 0xFF);
}

void INC_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x34);
    bin->emitByte(mLiteral1 & 0xFF);
}

void INC_IX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x23);
}

void INC_IY::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x23);
}

void INC_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x03);
}

void INC_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x13);
}

void INC_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x23);
}

void INC_SP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x33);
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

void JP_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xC3);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void JP_C_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDA);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void JP_M_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFA);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void JP_NC_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xD2);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void JP_NZ_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xC2);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void JP_P_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xF2);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void JP_PE_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xEA);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void JP_PO_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xE2);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void JP_Z_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCA);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void JP_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xE9);
}

void JP_mIX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xE9);
}

void JP_mIY::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xE9);
}

void JR_off::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x18);
    bin->emitByte(mLiteral1 & 0xFF);
}

void JR_C_off::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x38);
    bin->emitByte(mLiteral1 & 0xFF);
}

void JR_NC_off::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x30);
    bin->emitByte(mLiteral1 & 0xFF);
}

void JR_NZ_off::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x20);
    bin->emitByte(mLiteral1 & 0xFF);
}

void JR_Z_off::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x28);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_A_mBC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x0A);
}

void LD_A_mDE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x1A);
}

void LD_A_I::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x57);
}

void LD_A_mnn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x3A);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_A_R::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x5F);
}

void LD_mBC_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x02);
}

void LD_mDE_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x12);
}

void LD_mHL_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x36);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIXn_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x36);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(mLiteral2 & 0xFF);
}

void LD_mIYn_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x36);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(mLiteral2 & 0xFF);
}

void LD_mnn_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x32);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_mnn_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x43);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_mnn_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x53);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_mnn_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x22);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_mnn_SP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x73);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_mnn_IX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x22);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_mnn_IY::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x22);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_BC_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x01);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_DE_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x11);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_HL_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x21);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_SP_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x31);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_BC_mnn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x4B);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_DE_mnn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x5B);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_HL_mnn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x2A);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_SP_mnn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x7B);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_mHL_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x77);
}

void LD_mHL_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x70);
}

void LD_mHL_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x71);
}

void LD_mHL_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x72);
}

void LD_mHL_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x73);
}

void LD_mHL_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x74);
}

void LD_mHL_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x75);
}

void LD_mIXn_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x77);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIXn_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x70);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIXn_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x71);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIXn_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x72);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIXn_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x73);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIXn_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x74);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIXn_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x75);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIYn_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x77);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIYn_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x70);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIYn_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x71);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIYn_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x72);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIYn_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x73);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIYn_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x74);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_mIYn_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x75);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_I_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x47);
}

void LD_IX_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x21);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_IX_mnn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x2A);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_IY_nn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x21);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_IY_mnn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x2A);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte((mLiteral1 >> 8) & 0xFF);
}

void LD_R_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x4F);
}

void LD_A_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x7E);
}

void LD_B_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x46);
}

void LD_C_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x4E);
}

void LD_D_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x56);
}

void LD_E_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x5E);
}

void LD_H_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x66);
}

void LD_L_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x6E);
}

void LD_A_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x7E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_B_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x46);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_C_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x4E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_D_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x56);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_E_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x5E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_H_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x66);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_L_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x6E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_A_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x7E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_B_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x46);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_C_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x4E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_D_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x56);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_E_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x5E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_H_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x66);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_L_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x6E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_A_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x3E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_B_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x06);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_C_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x0E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_D_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x16);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_E_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x1E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_H_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x26);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_L_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x2E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void LD_A_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x7F);
}

void LD_B_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x47);
}

void LD_C_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x4F);
}

void LD_D_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x57);
}

void LD_E_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x5F);
}

void LD_H_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x67);
}

void LD_L_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x6F);
}

void LD_A_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x78);
}

void LD_B_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x40);
}

void LD_C_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x48);
}

void LD_D_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x50);
}

void LD_E_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x58);
}

void LD_H_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x60);
}

void LD_L_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x68);
}

void LD_A_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x79);
}

void LD_B_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x41);
}

void LD_C_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x49);
}

void LD_D_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x51);
}

void LD_E_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x59);
}

void LD_H_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x61);
}

void LD_L_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x69);
}

void LD_A_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x7A);
}

void LD_B_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x42);
}

void LD_C_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x4A);
}

void LD_D_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x52);
}

void LD_E_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x5A);
}

void LD_H_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x62);
}

void LD_L_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x6A);
}

void LD_A_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x7B);
}

void LD_B_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x43);
}

void LD_C_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x4B);
}

void LD_D_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x53);
}

void LD_E_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x5B);
}

void LD_H_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x63);
}

void LD_L_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x6B);
}

void LD_A_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x7C);
}

void LD_B_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x44);
}

void LD_C_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x4C);
}

void LD_D_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x54);
}

void LD_E_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x5C);
}

void LD_H_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x64);
}

void LD_L_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x6C);
}

void LD_A_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x7D);
}

void LD_B_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x45);
}

void LD_C_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x4D);
}

void LD_D_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x55);
}

void LD_E_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x5D);
}

void LD_H_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x65);
}

void LD_L_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x6D);
}

void LD_SP_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xF9);
}

void LD_SP_IX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xF9);
}

void LD_SP_IY::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xF9);
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

void NEG::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x44);
}

void NOP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x00);
}

void OR_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB7);
}

void OR_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB0);
}

void OR_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB1);
}

void OR_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB2);
}

void OR_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB3);
}

void OR_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB4);
}

void OR_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB5);
}

void OR_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xF6);
    bin->emitByte(mLiteral1 & 0xFF);
}

void OR_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xB6);
}

void OR_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xB6);
    bin->emitByte(mLiteral1 & 0xFF);
}

void OR_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xB6);
    bin->emitByte(mLiteral1 & 0xFF);
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

void OUT_mn_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xD3);
    bin->emitByte(mLiteral1 & 0xFF);
}

void OUT_mC_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x79);
}

void OUT_mC_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x41);
}

void OUT_mC_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x49);
}

void OUT_mC_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x51);
}

void OUT_mC_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x59);
}

void OUT_mC_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x61);
}

void OUT_mC_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x69);
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

void POP_IX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xE1);
}

void POP_IY::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xE1);
}

void POP_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xC1);
}

void POP_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xD1);
}

void POP_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xE1);
}

void POP_AF::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xF1);
}

void PUSH_IX::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xE5);
}

void PUSH_IY::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xE5);
}

void PUSH_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xC5);
}

void PUSH_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xD5);
}

void PUSH_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xE5);
}

void PUSH_AF::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xF5);
}

void RES_0_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x87);
}

void RES_0_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x80);
}

void RES_0_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x81);
}

void RES_0_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x82);
}

void RES_0_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x83);
}

void RES_0_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x84);
}

void RES_0_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x85);
}

void RES_1_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8F);
}

void RES_1_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x88);
}

void RES_1_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x89);
}

void RES_1_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8A);
}

void RES_1_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8B);
}

void RES_1_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8C);
}

void RES_1_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8D);
}

void RES_2_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x97);
}

void RES_2_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x90);
}

void RES_2_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x91);
}

void RES_2_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x92);
}

void RES_2_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x93);
}

void RES_2_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x94);
}

void RES_2_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x95);
}

void RES_3_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9F);
}

void RES_3_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x98);
}

void RES_3_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x99);
}

void RES_3_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9A);
}

void RES_3_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9B);
}

void RES_3_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9C);
}

void RES_3_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9D);
}

void RES_4_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA7);
}

void RES_4_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA0);
}

void RES_4_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA1);
}

void RES_4_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA2);
}

void RES_4_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA3);
}

void RES_4_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA4);
}

void RES_4_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA5);
}

void RES_5_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAF);
}

void RES_5_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA8);
}

void RES_5_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA9);
}

void RES_5_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAA);
}

void RES_5_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAB);
}

void RES_5_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAC);
}

void RES_5_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAD);
}

void RES_6_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB7);
}

void RES_6_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB0);
}

void RES_6_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB1);
}

void RES_6_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB2);
}

void RES_6_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB3);
}

void RES_6_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB4);
}

void RES_6_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB5);
}

void RES_7_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBF);
}

void RES_7_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB8);
}

void RES_7_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB9);
}

void RES_7_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBA);
}

void RES_7_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBB);
}

void RES_7_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBC);
}

void RES_7_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBD);
}

void RES_0_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x86);
}

void RES_1_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8E);
}

void RES_2_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x96);
}

void RES_3_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9E);
}

void RES_4_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA6);
}

void RES_5_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAE);
}

void RES_6_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB6);
}

void RES_7_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBE);
}

void RES_0_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x86);
}

void RES_1_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x8E);
}

void RES_2_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x96);
}

void RES_3_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x9E);
}

void RES_4_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xA6);
}

void RES_5_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xAE);
}

void RES_6_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xB6);
}

void RES_7_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xBE);
}

void RES_0_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x86);
}

void RES_1_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x8E);
}

void RES_2_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x96);
}

void RES_3_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x9E);
}

void RES_4_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xA6);
}

void RES_5_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xAE);
}

void RES_6_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xB6);
}

void RES_7_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xBE);
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

void RL_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x17);
}

void RL_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x10);
}

void RL_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x11);
}

void RL_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x12);
}

void RL_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x13);
}

void RL_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x14);
}

void RL_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x15);
}

void RL_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x16);
}

void RL_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x16);
}

void RL_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x16);
}

void RLA::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x17);
}

void RLC_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x07);
}

void RLC_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x00);
}

void RLC_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x01);
}

void RLC_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x02);
}

void RLC_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x03);
}

void RLC_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x04);
}

void RLC_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x05);
}

void RLC_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x06);
}

void RLC_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x06);
}

void RLC_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x06);
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

void RR_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1F);
}

void RR_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x18);
}

void RR_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x19);
}

void RR_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1A);
}

void RR_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1B);
}

void RR_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1C);
}

void RR_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1D);
}

void RR_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1E);
}

void RR_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x1E);
}

void RR_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x1E);
}

void RRA::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x1F);
}

void RRC_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0F);
}

void RRC_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x08);
}

void RRC_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x09);
}

void RRC_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0A);
}

void RRC_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0B);
}

void RRC_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0C);
}

void RRC_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0D);
}

void RRC_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0E);
}

void RRC_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x0E);
}

void RRC_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x0E);
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

void RST_00::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xC7);
}

void RST_08::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCF);
}

void RST_10::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xD7);
}

void RST_18::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDF);
}

void RST_20::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xE7);
}

void RST_28::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xEF);
}

void RST_30::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xF7);
}

void RST_38::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFF);
}

void SBC_A_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x9F);
}

void SBC_A_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x98);
}

void SBC_A_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x99);
}

void SBC_A_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x9A);
}

void SBC_A_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x9B);
}

void SBC_A_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x9C);
}

void SBC_A_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x9D);
}

void SBC_A_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDE);
    bin->emitByte(mLiteral1 & 0xFF);
}

void SBC_A_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x9E);
}

void SBC_A_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x9E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void SBC_A_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x9E);
    bin->emitByte(mLiteral1 & 0xFF);
}

void SBC_HL_BC::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x42);
}

void SBC_HL_DE::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x52);
}

void SBC_HL_HL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x62);
}

void SBC_HL_SP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x72);
}

void SCF::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x37);
}

void SET_0_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC7);
}

void SET_0_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC0);
}

void SET_0_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC1);
}

void SET_0_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC2);
}

void SET_0_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC3);
}

void SET_0_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC4);
}

void SET_0_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC5);
}

void SET_1_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCF);
}

void SET_1_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC8);
}

void SET_1_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC9);
}

void SET_1_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCA);
}

void SET_1_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCB);
}

void SET_1_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCC);
}

void SET_1_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCD);
}

void SET_2_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD7);
}

void SET_2_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD0);
}

void SET_2_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD1);
}

void SET_2_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD2);
}

void SET_2_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD3);
}

void SET_2_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD4);
}

void SET_2_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD5);
}

void SET_3_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDF);
}

void SET_3_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD8);
}

void SET_3_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD9);
}

void SET_3_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDA);
}

void SET_3_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDB);
}

void SET_3_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDC);
}

void SET_3_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDD);
}

void SET_4_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE7);
}

void SET_4_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE0);
}

void SET_4_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE1);
}

void SET_4_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE2);
}

void SET_4_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE3);
}

void SET_4_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE4);
}

void SET_4_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE5);
}

void SET_5_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEF);
}

void SET_5_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE8);
}

void SET_5_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE9);
}

void SET_5_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEA);
}

void SET_5_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEB);
}

void SET_5_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEC);
}

void SET_5_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xED);
}

void SET_6_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF7);
}

void SET_6_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF0);
}

void SET_6_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF1);
}

void SET_6_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF2);
}

void SET_6_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF3);
}

void SET_6_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF4);
}

void SET_6_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF5);
}

void SET_7_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFF);
}

void SET_7_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF8);
}

void SET_7_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF9);
}

void SET_7_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFA);
}

void SET_7_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFB);
}

void SET_7_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFC);
}

void SET_7_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFD);
}

void SET_0_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC6);
}

void SET_1_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCE);
}

void SET_2_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD6);
}

void SET_3_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDE);
}

void SET_4_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE6);
}

void SET_5_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEE);
}

void SET_6_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF6);
}

void SET_7_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFE);
}

void SET_0_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xC6);
}

void SET_1_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xCE);
}

void SET_2_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xD6);
}

void SET_3_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xDE);
}

void SET_4_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xE6);
}

void SET_5_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xEE);
}

void SET_6_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xF6);
}

void SET_7_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xFE);
}

void SET_0_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xC6);
}

void SET_1_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xCE);
}

void SET_2_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xD6);
}

void SET_3_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xDE);
}

void SET_4_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xE6);
}

void SET_5_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xEE);
}

void SET_6_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xF6);
}

void SET_7_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0xFE);
}

void SLA_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x27);
}

void SLA_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x20);
}

void SLA_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x21);
}

void SLA_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x22);
}

void SLA_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x23);
}

void SLA_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x24);
}

void SLA_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x25);
}

void SLA_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x26);
}

void SLA_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x26);
}

void SLA_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x26);
}

void SRA_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2F);
}

void SRA_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x28);
}

void SRA_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x29);
}

void SRA_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2A);
}

void SRA_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2B);
}

void SRA_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2C);
}

void SRA_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2D);
}

void SRA_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2E);
}

void SRA_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x2E);
}

void SRA_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x2E);
}

void SRL_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3F);
}

void SRL_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x38);
}

void SRL_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x39);
}

void SRL_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3A);
}

void SRL_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3B);
}

void SRL_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3C);
}

void SRL_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3D);
}

void SRL_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3E);
}

void SRL_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x3E);
}

void SRL_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1 & 0xFF);
    bin->emitByte(0x3E);
}

void SUB_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x97);
}

void SUB_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x90);
}

void SUB_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x91);
}

void SUB_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x92);
}

void SUB_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x93);
}

void SUB_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x94);
}

void SUB_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x95);
}

void SUB_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xD6);
    bin->emitByte(mLiteral1 & 0xFF);
}

void SUB_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x96);
}

void SUB_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x96);
    bin->emitByte(mLiteral1 & 0xFF);
}

void SUB_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x96);
    bin->emitByte(mLiteral1 & 0xFF);
}

void XOR_A::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xAF);
}

void XOR_B::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA8);
}

void XOR_C::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xA9);
}

void XOR_D::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xAA);
}

void XOR_E::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xAB);
}

void XOR_H::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xAC);
}

void XOR_L::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xAD);
}

void XOR_n::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xEE);
    bin->emitByte(mLiteral1 & 0xFF);
}

void XOR_mHL::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xAE);
}

void XOR_mIXn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xAE);
    bin->emitByte(mLiteral1 & 0xFF);
}

void XOR_mIYn::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xAE);
    bin->emitByte(mLiteral1 & 0xFF);
}

bool AssemblerParser::parseOpcode_generated(const std::string& opcode)
{
    unsigned literal1, literal2;
    Token token = lastToken();
    if (opcode == "adc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADC_HL_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_HL_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IX_IX>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<ADD_IY_IY>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<AND_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_0_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_1_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_2_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_3_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_4_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_5_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_6_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
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
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<BIT_7_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "m") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nc") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nz") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "p") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "pe") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "po") {
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "z") {
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
    if (opcode == "cp") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<CP_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<CP_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<CP_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<CP_mIYn>(token, literal1);
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
    if (opcode == "dec") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<DEC_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<DEC_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<DEC_mIYn>(token, literal1);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_IX>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_IY>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_BC>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_DE>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_HL>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DEC_SP>(token);
                return true;
            }
            return false;
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
    if (opcode == "djnz") {
        nextToken();
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<DJNZ_n>(token, literal1);
                return true;
            }
            return false;
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
    if (opcode == "ex") {
        nextToken();
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<EX_mSP_HL>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<EX_mSP_IX>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<EX_mSP_IY>(token);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "af") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "af'") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<EX_AF_AFs>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<EX_DE_HL>(token);
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
    if (opcode == "im") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<IM_0>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 1) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<IM_1>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 2) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<IM_2>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "in") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_A_mn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_A_mC>(token);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_B_mC>(token);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_C_mC>(token);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_D_mC>(token);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_E_mC>(token);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_H_mC>(token);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<IN_L_mC>(token);
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
    if (opcode == "inc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<INC_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<INC_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<INC_mIYn>(token, literal1);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_IX>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_IY>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_BC>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_DE>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_HL>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<INC_SP>(token);
                return true;
            }
            return false;
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
    if (opcode == "jp") {
        nextToken();
        if (expectWordLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<JP_nn>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_C_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "m") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_M_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nc") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_NC_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nz") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_NZ_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "p") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_P_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "pe") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_PE_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "po") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_PO_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "z") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_Z_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_mIX>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JP_mIY>(token);
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
    if (opcode == "jr") {
        nextToken();
        if (expectRelativeByteOffset(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<JR_off>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectRelativeByteOffset(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JR_C_off>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nc") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectRelativeByteOffset(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JR_NC_off>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "nz") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectRelativeByteOffset(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JR_NZ_off>(token, literal1);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "z") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectRelativeByteOffset(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<JR_Z_off>(token, literal1);
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
    if (opcode == "ld") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_A_mBC>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_A_mDE>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_A_mnn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_A_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_A_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_A_mIYn>(token, literal1);
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
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "i") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_I>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "r") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_R>(token);
                        return true;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_A_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mBC_A>(token);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mDE_A>(token);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (expectByteLiteral(&literal1)) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_n>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_A>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_B>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_C>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_D>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_E>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_H>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mHL_L>(token);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_COMMA) {
                                nextToken();
                                if (expectByteLiteral(&literal2)) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_n>(token, literal1, literal2);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_A>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_B>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_C>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_D>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_E>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_H>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIXn_L>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_COMMA) {
                                nextToken();
                                if (expectByteLiteral(&literal2)) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_n>(token, literal1, literal2);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_A>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_B>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_C>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_D>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_E>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_H>(token, literal1);
                                        return true;
                                    }
                                    return false;
                                }
                                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_mIYn_L>(token, literal1);
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
            if (expectWordLiteral(&literal1)) {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_A>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_BC>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_DE>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_HL>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_SP>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_IX>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_mnn_IY>(token, literal1);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_BC_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_BC_mnn>(token, literal1);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_DE_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_DE_mnn>(token, literal1);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_HL_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_HL_mnn>(token, literal1);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_SP_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_SP_mnn>(token, literal1);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_SP_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_SP_IX>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_SP_IY>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "i") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_I_A>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_IX_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_IX_mnn>(token, literal1);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (expectWordLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_IY_nn>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (expectWordLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_IY_mnn>(token, literal1);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "r") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_R_A>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_B_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_B_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_B_mIYn>(token, literal1);
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
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_B_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_C_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_C_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_C_mIYn>(token, literal1);
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
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_C_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_D_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_D_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_D_mIYn>(token, literal1);
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
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_D_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_E_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_E_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_E_mIYn>(token, literal1);
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
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_E_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_H_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_H_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_H_mIYn>(token, literal1);
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
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_H_L>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<LD_L_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_L_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<LD_L_mIYn>(token, literal1);
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
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<LD_L_L>(token);
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
    if (opcode == "or") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<OR_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<OR_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OR_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OR_mIYn>(token, literal1);
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
    if (opcode == "out") {
        nextToken();
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (expectByteLiteral(&literal1)) {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mn_A>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_COMMA) {
                        nextToken();
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_A>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_B>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_C>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_D>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_E>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_H>(token);
                                return true;
                            }
                            return false;
                        }
                        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<OUT_mC_L>(token);
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
    if (opcode == "pop") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_IX>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_IY>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_BC>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_DE>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_HL>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "af") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<POP_AF>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "push") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_IX>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_IY>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_BC>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_DE>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_HL>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "af") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<PUSH_AF>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "res") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_0_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_0_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_0_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_0_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 1) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_1_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_1_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_1_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_1_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 2) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_2_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_2_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_2_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_2_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 3) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_3_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_3_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_3_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_3_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 4) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_4_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_4_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_4_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_4_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 5) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_5_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_5_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_5_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_5_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 6) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_6_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_6_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_6_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_6_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 7) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RES_7_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RES_7_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_7_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<RES_7_mIYn>(token, literal1);
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
    if (opcode == "rl") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RL_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RL_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RL_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RL_mIYn>(token, literal1);
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
    if (opcode == "rla") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RLA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rlc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RLC_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RLC_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RLC_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RLC_mIYn>(token, literal1);
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
    if (opcode == "rr") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RR_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RR_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RR_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RR_mIYn>(token, literal1);
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
    if (opcode == "rra") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<RRA>(token);
            return true;
        }
        return false;
    }
    if (opcode == "rrc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RRC_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<RRC_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RRC_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<RRC_mIYn>(token, literal1);
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
    if (opcode == "rst") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x00) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_00>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x08) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_08>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x10) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_10>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x18) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_18>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x20) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_20>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x28) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_28>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x30) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_30>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_NUMBER && lastToken().number == 0x38) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<RST_38>(token);
                return true;
            }
            return false;
        }
        return false;
    }
    if (opcode == "sbc") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_L>(token);
                        return true;
                    }
                    return false;
                }
                if (expectByteLiteral(&literal1)) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_A_n>(token, literal1);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SBC_A_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SBC_A_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SBC_A_mIYn>(token, literal1);
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
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "bc") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_HL_BC>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "de") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_HL_DE>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_HL_HL>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "sp") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SBC_HL_SP>(token);
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
    if (opcode == "scf") {
        nextToken();
        if (lastTokenId() == T_EOL) {
            mSection->emit<SCF>(token);
            return true;
        }
        return false;
    }
    if (opcode == "set") {
        nextToken();
        if (lastTokenId() == T_NUMBER && lastToken().number == 0) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_0_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_0_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_0_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_0_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 1) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_1_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_1_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_1_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_1_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 2) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_2_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_2_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_2_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_2_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 3) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_3_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_3_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_3_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_3_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 4) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_4_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_4_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_4_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_4_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 5) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_5_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_5_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_5_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_5_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 6) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_6_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_6_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_6_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_6_mIYn>(token, literal1);
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
        if (lastTokenId() == T_NUMBER && lastToken().number == 7) {
            nextToken();
            if (lastTokenId() == T_COMMA) {
                nextToken();
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_A>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_B>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_C>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_D>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_E>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_H>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SET_7_L>(token);
                        return true;
                    }
                    return false;
                }
                if (lastTokenId() == T_LPAREN) {
                    nextToken();
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SET_7_mHL>(token);
                                return true;
                            }
                            return false;
                        }
                        return false;
                    }
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_7_mIXn>(token, literal1);
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
                    if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                        nextToken();
                        if (lastTokenId() == T_PLUS) {
                            nextToken();
                            if (expectByteLiteral(&literal1)) {
                                nextToken();
                                if (lastTokenId() == T_RPAREN) {
                                    nextToken();
                                    if (lastTokenId() == T_EOL) {
                                        mSection->emit<SET_7_mIYn>(token, literal1);
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
        return false;
    }
    if (opcode == "sla") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SLA_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SLA_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SLA_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SLA_mIYn>(token, literal1);
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
    if (opcode == "sra") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRA_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SRA_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SRA_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SRA_mIYn>(token, literal1);
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
    if (opcode == "srl") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SRL_L>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SRL_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SRL_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SRL_mIYn>(token, literal1);
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
    if (opcode == "sub") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<SUB_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<SUB_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SUB_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<SUB_mIYn>(token, literal1);
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
    if (opcode == "xor") {
        nextToken();
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "a") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_A>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "b") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_B>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "c") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_C>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "d") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_D>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "e") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_E>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "h") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_H>(token);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "l") {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_L>(token);
                return true;
            }
            return false;
        }
        if (expectByteLiteral(&literal1)) {
            nextToken();
            if (lastTokenId() == T_EOL) {
                mSection->emit<XOR_n>(token, literal1);
                return true;
            }
            return false;
        }
        if (lastTokenId() == T_LPAREN) {
            nextToken();
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "hl") {
                nextToken();
                if (lastTokenId() == T_RPAREN) {
                    nextToken();
                    if (lastTokenId() == T_EOL) {
                        mSection->emit<XOR_mHL>(token);
                        return true;
                    }
                    return false;
                }
                return false;
            }
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "ix") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<XOR_mIXn>(token, literal1);
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
            if (lastTokenId() == T_IDENTIFIER && toLower(lastTokenText()) == "iy") {
                nextToken();
                if (lastTokenId() == T_PLUS) {
                    nextToken();
                    if (expectByteLiteral(&literal1)) {
                        nextToken();
                        if (lastTokenId() == T_RPAREN) {
                            nextToken();
                            if (lastTokenId() == T_EOL) {
                                mSection->emit<XOR_mIYn>(token, literal1);
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
    return false;
}
