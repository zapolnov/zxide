// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"
#include "ProgramSection.h"
#include "ProgramBinary.h"

void ADC_A_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x8F);
}

void ADC_A_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x88);
}

void ADC_A_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x89);
}

void ADC_A_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x8A);
}

void ADC_A_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x8B);
}

void ADC_A_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x8C);
}

void ADC_A_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x8D);
}

void ADC_A_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCE);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool ADC_A_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void ADC_A_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x8E);
}

void ADC_A_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x8E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool ADC_A_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void ADC_A_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x8E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool ADC_A_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void ADC_HL_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x4A);
}

void ADC_HL_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x5A);
}

void ADC_HL_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x6A);
}

void ADC_HL_SP::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x7A);
}

void ADD_A_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x87);
}

void ADD_A_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x80);
}

void ADD_A_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x81);
}

void ADD_A_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x82);
}

void ADD_A_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x83);
}

void ADD_A_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x84);
}

void ADD_A_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x85);
}

void ADD_A_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC6);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool ADD_A_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void ADD_A_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x86);
}

void ADD_A_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x86);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool ADD_A_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void ADD_A_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x86);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool ADD_A_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void ADD_HL_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x09);
}

void ADD_HL_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x19);
}

void ADD_HL_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x29);
}

void ADD_HL_SP::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x39);
}

void ADD_IX_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x09);
}

void ADD_IX_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x19);
}

void ADD_IX_IX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x29);
}

void ADD_IX_SP::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x39);
}

void ADD_IY_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x09);
}

void ADD_IY_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x19);
}

void ADD_IY_IY::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x29);
}

void ADD_IY_SP::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x39);
}

void AND_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA7);
}

void AND_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA0);
}

void AND_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA1);
}

void AND_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA2);
}

void AND_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA3);
}

void AND_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA4);
}

void AND_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA5);
}

void AND_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE6);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool AND_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void AND_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA6);
}

void AND_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xA6);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool AND_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void AND_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xA6);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool AND_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_0_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x46);
}

void BIT_1_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4E);
}

void BIT_2_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x56);
}

void BIT_3_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5E);
}

void BIT_4_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x66);
}

void BIT_5_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6E);
}

void BIT_6_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x76);
}

void BIT_7_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7E);
}

void BIT_0_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x46);
}

bool BIT_0_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_1_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x4E);
}

bool BIT_1_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_2_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x56);
}

bool BIT_2_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_3_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x5E);
}

bool BIT_3_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_4_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x66);
}

bool BIT_4_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_5_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x6E);
}

bool BIT_5_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_6_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x76);
}

bool BIT_6_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_7_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x7E);
}

bool BIT_7_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_0_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x46);
}

bool BIT_0_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_1_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x4E);
}

bool BIT_1_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_2_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x56);
}

bool BIT_2_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_3_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x5E);
}

bool BIT_3_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_4_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x66);
}

bool BIT_4_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_5_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x6E);
}

bool BIT_5_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_6_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x76);
}

bool BIT_6_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_7_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x7E);
}

bool BIT_7_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void BIT_0_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x47);
}

void BIT_0_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x40);
}

void BIT_0_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x41);
}

void BIT_0_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x42);
}

void BIT_0_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x43);
}

void BIT_0_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x44);
}

void BIT_0_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x45);
}

void BIT_1_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4F);
}

void BIT_1_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x48);
}

void BIT_1_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x49);
}

void BIT_1_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4A);
}

void BIT_1_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4B);
}

void BIT_1_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4C);
}

void BIT_1_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x4D);
}

void BIT_2_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x57);
}

void BIT_2_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x50);
}

void BIT_2_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x51);
}

void BIT_2_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x52);
}

void BIT_2_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x53);
}

void BIT_2_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x54);
}

void BIT_2_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x55);
}

void BIT_3_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5F);
}

void BIT_3_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x58);
}

void BIT_3_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x59);
}

void BIT_3_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5A);
}

void BIT_3_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5B);
}

void BIT_3_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5C);
}

void BIT_3_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x5D);
}

void BIT_4_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x67);
}

void BIT_4_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x60);
}

void BIT_4_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x61);
}

void BIT_4_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x62);
}

void BIT_4_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x63);
}

void BIT_4_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x64);
}

void BIT_4_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x65);
}

void BIT_5_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6F);
}

void BIT_5_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x68);
}

void BIT_5_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x69);
}

void BIT_5_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6A);
}

void BIT_5_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6B);
}

void BIT_5_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6C);
}

void BIT_5_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x6D);
}

void BIT_6_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x77);
}

void BIT_6_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x70);
}

void BIT_6_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x71);
}

void BIT_6_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x72);
}

void BIT_6_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x73);
}

void BIT_6_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x74);
}

void BIT_6_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x75);
}

void BIT_7_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7F);
}

void BIT_7_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x78);
}

void BIT_7_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x79);
}

void BIT_7_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7A);
}

void BIT_7_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7B);
}

void BIT_7_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7C);
}

void BIT_7_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x7D);
}

void CALL_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCD);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool CALL_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CALL_C_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDC);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool CALL_C_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CALL_M_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFC);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool CALL_M_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CALL_NC_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD4);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool CALL_NC_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CALL_NZ_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC4);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool CALL_NZ_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CALL_P_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF4);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool CALL_P_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CALL_PE_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xEC);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool CALL_PE_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CALL_PO_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE4);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool CALL_PO_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CALL_Z_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCC);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool CALL_Z_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CCF::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x3F);
}

void CP_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xBF);
}

void CP_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB8);
}

void CP_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB9);
}

void CP_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xBA);
}

void CP_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xBB);
}

void CP_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xBC);
}

void CP_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xBD);
}

void CP_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFE);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool CP_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CP_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xBE);
}

void CP_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xBE);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool CP_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CP_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xBE);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool CP_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void CPD::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA9);
}

void CPDR::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB9);
}

void CPI::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA1);
}

void CPIR::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB1);
}

void CPL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x2F);
}

void DAA::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x27);
}

void DEC_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x3D);
}

void DEC_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x05);
}

void DEC_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x0D);
}

void DEC_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x15);
}

void DEC_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x1D);
}

void DEC_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x25);
}

void DEC_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x2D);
}

void DEC_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x35);
}

void DEC_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x35);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool DEC_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void DEC_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x35);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool DEC_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void DEC_IX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x2B);
}

void DEC_IY::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x2B);
}

void DEC_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x0B);
}

void DEC_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x1B);
}

void DEC_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x2B);
}

void DEC_SP::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x3B);
}

void DI::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF3);
}

void DJNZ_off::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    unsigned addr = bin->endAddress() + lengthInBytes();
    bin->emitByte(0x10);
    bin->emitByte(mLiteral1->evaluateByteOffset(reporter, addr));
}

bool DJNZ_off::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void EI::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFB);
}

void EX_mSP_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE3);
}

void EX_mSP_IX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xE3);
}

void EX_mSP_IY::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xE3);
}

void EX_AF_AFs::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x08);
}

void EX_DE_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xEB);
}

void EXX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD9);
}

void HALT::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x76);
}

void IM_0::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x46);
}

void IM_1::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x56);
}

void IM_2::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x5E);
}

void IN_A_mn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool IN_A_mn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void IN_A_mC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x78);
}

void IN_B_mC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x40);
}

void IN_C_mC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x48);
}

void IN_D_mC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x50);
}

void IN_E_mC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x58);
}

void IN_H_mC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x60);
}

void IN_L_mC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x68);
}

void INC_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x3C);
}

void INC_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x04);
}

void INC_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x0C);
}

void INC_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x14);
}

void INC_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x1C);
}

void INC_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x24);
}

void INC_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x2C);
}

void INC_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x34);
}

void INC_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x34);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool INC_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void INC_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x34);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool INC_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void INC_IX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x23);
}

void INC_IY::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x23);
}

void INC_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x03);
}

void INC_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x13);
}

void INC_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x23);
}

void INC_SP::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x33);
}

void IND::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xAA);
}

void INDR::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xBA);
}

void INI::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA2);
}

void INIR::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB2);
}

void JP_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC3);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool JP_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JP_C_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDA);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool JP_C_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JP_M_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFA);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool JP_M_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JP_NC_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD2);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool JP_NC_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JP_NZ_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC2);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool JP_NZ_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JP_P_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF2);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool JP_P_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JP_PE_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xEA);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool JP_PE_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JP_PO_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE2);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool JP_PO_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JP_Z_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCA);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool JP_Z_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JP_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE9);
}

void JP_mIX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xE9);
}

void JP_mIY::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xE9);
}

void JR_off::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    unsigned addr = bin->endAddress() + lengthInBytes();
    bin->emitByte(0x18);
    bin->emitByte(mLiteral1->evaluateByteOffset(reporter, addr));
}

bool JR_off::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JR_C_off::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    unsigned addr = bin->endAddress() + lengthInBytes();
    bin->emitByte(0x38);
    bin->emitByte(mLiteral1->evaluateByteOffset(reporter, addr));
}

bool JR_C_off::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JR_NC_off::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    unsigned addr = bin->endAddress() + lengthInBytes();
    bin->emitByte(0x30);
    bin->emitByte(mLiteral1->evaluateByteOffset(reporter, addr));
}

bool JR_NC_off::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JR_NZ_off::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    unsigned addr = bin->endAddress() + lengthInBytes();
    bin->emitByte(0x20);
    bin->emitByte(mLiteral1->evaluateByteOffset(reporter, addr));
}

bool JR_NZ_off::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void JR_Z_off::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    unsigned addr = bin->endAddress() + lengthInBytes();
    bin->emitByte(0x28);
    bin->emitByte(mLiteral1->evaluateByteOffset(reporter, addr));
}

bool JR_Z_off::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_A_mBC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x0A);
}

void LD_A_mDE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x1A);
}

void LD_A_I::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x57);
}

void LD_A_mnn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x3A);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_A_mnn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_A_R::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x5F);
}

void LD_mBC_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x02);
}

void LD_mDE_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x12);
}

void LD_mHL_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x36);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mHL_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIXn_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x36);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(mLiteral2->evaluateByte(reporter));
}

bool LD_mIXn_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter)
        && mLiteral2->resolveValues(section->program(), address(), reporter);
}

void LD_mIYn_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x36);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(mLiteral2->evaluateByte(reporter));
}

bool LD_mIYn_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter)
        && mLiteral2->resolveValues(section->program(), address(), reporter);
}

void LD_mnn_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x32);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_mnn_A::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mnn_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x43);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_mnn_BC::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mnn_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x53);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_mnn_DE::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mnn_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x22);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_mnn_HL::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mnn_SP::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x73);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_mnn_SP::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mnn_IX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x22);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_mnn_IX::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mnn_IY::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x22);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_mnn_IY::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_BC_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x01);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_BC_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_DE_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x11);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_DE_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_HL_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x21);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_HL_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_SP_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x31);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_SP_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_BC_mnn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x4B);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_BC_mnn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_DE_mnn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x5B);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_DE_mnn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_HL_mnn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x2A);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_HL_mnn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_SP_mnn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x7B);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_SP_mnn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mHL_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x77);
}

void LD_mHL_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x70);
}

void LD_mHL_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x71);
}

void LD_mHL_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x72);
}

void LD_mHL_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x73);
}

void LD_mHL_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x74);
}

void LD_mHL_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x75);
}

void LD_mIXn_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x77);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIXn_A::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIXn_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x70);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIXn_B::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIXn_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x71);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIXn_C::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIXn_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x72);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIXn_D::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIXn_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x73);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIXn_E::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIXn_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x74);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIXn_H::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIXn_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x75);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIXn_L::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIYn_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x77);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIYn_A::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIYn_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x70);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIYn_B::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIYn_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x71);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIYn_C::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIYn_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x72);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIYn_D::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIYn_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x73);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIYn_E::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIYn_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x74);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIYn_H::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_mIYn_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x75);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_mIYn_L::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_I_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x47);
}

void LD_IX_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x21);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_IX_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_IX_mnn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x2A);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_IX_mnn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_IY_nn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x21);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_IY_nn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_IY_mnn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x2A);
    bin->emitWord(mLiteral1->evaluateWord(reporter));
}

bool LD_IY_mnn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_R_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x4F);
}

void LD_A_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x7E);
}

void LD_B_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x46);
}

void LD_C_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x4E);
}

void LD_D_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x56);
}

void LD_E_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x5E);
}

void LD_H_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x66);
}

void LD_L_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x6E);
}

void LD_A_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x7E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_A_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_B_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x46);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_B_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_C_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x4E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_C_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_D_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x56);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_D_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_E_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x5E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_E_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_H_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x66);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_H_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_L_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x6E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_L_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_A_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x7E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_A_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_B_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x46);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_B_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_C_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x4E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_C_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_D_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x56);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_D_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_E_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x5E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_E_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_H_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x66);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_H_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_L_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x6E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_L_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_A_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x3E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_A_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_B_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x06);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_B_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_C_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x0E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_C_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_D_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x16);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_D_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_E_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x1E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_E_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_H_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x26);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_H_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_L_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x2E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool LD_L_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void LD_A_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x7F);
}

void LD_B_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x47);
}

void LD_C_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x4F);
}

void LD_D_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x57);
}

void LD_E_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x5F);
}

void LD_H_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x67);
}

void LD_L_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x6F);
}

void LD_A_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x78);
}

void LD_B_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x40);
}

void LD_C_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x48);
}

void LD_D_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x50);
}

void LD_E_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x58);
}

void LD_H_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x60);
}

void LD_L_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x68);
}

void LD_A_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x79);
}

void LD_B_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x41);
}

void LD_C_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x49);
}

void LD_D_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x51);
}

void LD_E_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x59);
}

void LD_H_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x61);
}

void LD_L_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x69);
}

void LD_A_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x7A);
}

void LD_B_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x42);
}

void LD_C_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x4A);
}

void LD_D_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x52);
}

void LD_E_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x5A);
}

void LD_H_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x62);
}

void LD_L_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x6A);
}

void LD_A_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x7B);
}

void LD_B_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x43);
}

void LD_C_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x4B);
}

void LD_D_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x53);
}

void LD_E_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x5B);
}

void LD_H_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x63);
}

void LD_L_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x6B);
}

void LD_A_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x7C);
}

void LD_B_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x44);
}

void LD_C_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x4C);
}

void LD_D_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x54);
}

void LD_E_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x5C);
}

void LD_H_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x64);
}

void LD_L_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x6C);
}

void LD_A_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x7D);
}

void LD_B_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x45);
}

void LD_C_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x4D);
}

void LD_D_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x55);
}

void LD_E_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x5D);
}

void LD_H_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x65);
}

void LD_L_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x6D);
}

void LD_SP_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF9);
}

void LD_SP_IX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xF9);
}

void LD_SP_IY::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xF9);
}

void LDD::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA8);
}

void LDDR::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB8);
}

void LDI::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA0);
}

void LDIR::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB0);
}

void NEG::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x44);
}

void NOP::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x00);
}

void OR_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB7);
}

void OR_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB0);
}

void OR_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB1);
}

void OR_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB2);
}

void OR_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB3);
}

void OR_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB4);
}

void OR_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB5);
}

void OR_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF6);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool OR_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void OR_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xB6);
}

void OR_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xB6);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool OR_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void OR_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xB6);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool OR_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void OTDR::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xBB);
}

void OTIR::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xB3);
}

void OUT_mn_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD3);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool OUT_mn_A::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void OUT_mC_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x79);
}

void OUT_mC_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x41);
}

void OUT_mC_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x49);
}

void OUT_mC_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x51);
}

void OUT_mC_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x59);
}

void OUT_mC_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x61);
}

void OUT_mC_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x69);
}

void OUTD::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xAB);
}

void OUTI::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0xA3);
}

void POP_IX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xE1);
}

void POP_IY::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xE1);
}

void POP_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC1);
}

void POP_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD1);
}

void POP_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE1);
}

void POP_AF::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF1);
}

void PUSH_IX::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xE5);
}

void PUSH_IY::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xE5);
}

void PUSH_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC5);
}

void PUSH_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD5);
}

void PUSH_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE5);
}

void PUSH_AF::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF5);
}

void RES_0_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x87);
}

void RES_0_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x80);
}

void RES_0_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x81);
}

void RES_0_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x82);
}

void RES_0_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x83);
}

void RES_0_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x84);
}

void RES_0_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x85);
}

void RES_1_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8F);
}

void RES_1_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x88);
}

void RES_1_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x89);
}

void RES_1_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8A);
}

void RES_1_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8B);
}

void RES_1_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8C);
}

void RES_1_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8D);
}

void RES_2_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x97);
}

void RES_2_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x90);
}

void RES_2_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x91);
}

void RES_2_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x92);
}

void RES_2_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x93);
}

void RES_2_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x94);
}

void RES_2_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x95);
}

void RES_3_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9F);
}

void RES_3_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x98);
}

void RES_3_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x99);
}

void RES_3_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9A);
}

void RES_3_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9B);
}

void RES_3_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9C);
}

void RES_3_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9D);
}

void RES_4_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA7);
}

void RES_4_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA0);
}

void RES_4_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA1);
}

void RES_4_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA2);
}

void RES_4_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA3);
}

void RES_4_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA4);
}

void RES_4_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA5);
}

void RES_5_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAF);
}

void RES_5_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA8);
}

void RES_5_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA9);
}

void RES_5_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAA);
}

void RES_5_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAB);
}

void RES_5_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAC);
}

void RES_5_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAD);
}

void RES_6_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB7);
}

void RES_6_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB0);
}

void RES_6_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB1);
}

void RES_6_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB2);
}

void RES_6_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB3);
}

void RES_6_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB4);
}

void RES_6_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB5);
}

void RES_7_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBF);
}

void RES_7_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB8);
}

void RES_7_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB9);
}

void RES_7_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBA);
}

void RES_7_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBB);
}

void RES_7_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBC);
}

void RES_7_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBD);
}

void RES_0_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x86);
}

void RES_1_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x8E);
}

void RES_2_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x96);
}

void RES_3_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x9E);
}

void RES_4_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xA6);
}

void RES_5_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xAE);
}

void RES_6_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xB6);
}

void RES_7_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xBE);
}

void RES_0_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x86);
}

bool RES_0_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_1_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x8E);
}

bool RES_1_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_2_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x96);
}

bool RES_2_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_3_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x9E);
}

bool RES_3_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_4_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xA6);
}

bool RES_4_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_5_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xAE);
}

bool RES_5_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_6_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xB6);
}

bool RES_6_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_7_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xBE);
}

bool RES_7_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_0_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x86);
}

bool RES_0_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_1_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x8E);
}

bool RES_1_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_2_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x96);
}

bool RES_2_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_3_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x9E);
}

bool RES_3_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_4_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xA6);
}

bool RES_4_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_5_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xAE);
}

bool RES_5_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_6_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xB6);
}

bool RES_6_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RES_7_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xBE);
}

bool RES_7_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RET::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC9);
}

void RET_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD8);
}

void RET_M::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF8);
}

void RET_NC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD0);
}

void RET_NZ::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC0);
}

void RET_P::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF0);
}

void RET_PE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE8);
}

void RET_PO::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE0);
}

void RET_Z::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC8);
}

void RETI::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x4D);
}

void RETN::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x45);
}

void RL_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x17);
}

void RL_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x10);
}

void RL_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x11);
}

void RL_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x12);
}

void RL_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x13);
}

void RL_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x14);
}

void RL_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x15);
}

void RL_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x16);
}

void RL_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x16);
}

bool RL_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RL_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x16);
}

bool RL_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RLA::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x17);
}

void RLC_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x07);
}

void RLC_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x00);
}

void RLC_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x01);
}

void RLC_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x02);
}

void RLC_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x03);
}

void RLC_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x04);
}

void RLC_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x05);
}

void RLC_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x06);
}

void RLC_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x06);
}

bool RLC_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RLC_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x06);
}

bool RLC_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RLCA::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x07);
}

void RLD::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x6F);
}

void RR_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1F);
}

void RR_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x18);
}

void RR_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x19);
}

void RR_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1A);
}

void RR_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1B);
}

void RR_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1C);
}

void RR_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1D);
}

void RR_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x1E);
}

void RR_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x1E);
}

bool RR_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RR_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x1E);
}

bool RR_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RRA::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x1F);
}

void RRC_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0F);
}

void RRC_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x08);
}

void RRC_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x09);
}

void RRC_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0A);
}

void RRC_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0B);
}

void RRC_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0C);
}

void RRC_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0D);
}

void RRC_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x0E);
}

void RRC_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x0E);
}

bool RRC_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RRC_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x0E);
}

bool RRC_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void RRCA::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x0F);
}

void RRD::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x67);
}

void RST_00::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xC7);
}

void RST_08::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCF);
}

void RST_10::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD7);
}

void RST_18::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDF);
}

void RST_20::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xE7);
}

void RST_28::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xEF);
}

void RST_30::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xF7);
}

void RST_38::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFF);
}

void SBC_A_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x9F);
}

void SBC_A_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x98);
}

void SBC_A_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x99);
}

void SBC_A_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x9A);
}

void SBC_A_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x9B);
}

void SBC_A_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x9C);
}

void SBC_A_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x9D);
}

void SBC_A_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDE);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool SBC_A_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SBC_A_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x9E);
}

void SBC_A_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x9E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool SBC_A_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SBC_A_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x9E);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool SBC_A_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SBC_HL_BC::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x42);
}

void SBC_HL_DE::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x52);
}

void SBC_HL_HL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x62);
}

void SBC_HL_SP::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xED);
    bin->emitByte(0x72);
}

void SCF::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x37);
}

void SET_0_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC7);
}

void SET_0_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC0);
}

void SET_0_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC1);
}

void SET_0_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC2);
}

void SET_0_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC3);
}

void SET_0_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC4);
}

void SET_0_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC5);
}

void SET_1_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCF);
}

void SET_1_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC8);
}

void SET_1_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC9);
}

void SET_1_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCA);
}

void SET_1_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCB);
}

void SET_1_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCC);
}

void SET_1_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCD);
}

void SET_2_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD7);
}

void SET_2_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD0);
}

void SET_2_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD1);
}

void SET_2_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD2);
}

void SET_2_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD3);
}

void SET_2_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD4);
}

void SET_2_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD5);
}

void SET_3_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDF);
}

void SET_3_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD8);
}

void SET_3_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD9);
}

void SET_3_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDA);
}

void SET_3_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDB);
}

void SET_3_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDC);
}

void SET_3_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDD);
}

void SET_4_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE7);
}

void SET_4_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE0);
}

void SET_4_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE1);
}

void SET_4_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE2);
}

void SET_4_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE3);
}

void SET_4_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE4);
}

void SET_4_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE5);
}

void SET_5_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEF);
}

void SET_5_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE8);
}

void SET_5_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE9);
}

void SET_5_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEA);
}

void SET_5_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEB);
}

void SET_5_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEC);
}

void SET_5_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xED);
}

void SET_6_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF7);
}

void SET_6_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF0);
}

void SET_6_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF1);
}

void SET_6_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF2);
}

void SET_6_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF3);
}

void SET_6_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF4);
}

void SET_6_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF5);
}

void SET_7_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFF);
}

void SET_7_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF8);
}

void SET_7_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF9);
}

void SET_7_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFA);
}

void SET_7_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFB);
}

void SET_7_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFC);
}

void SET_7_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFD);
}

void SET_0_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xC6);
}

void SET_1_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xCE);
}

void SET_2_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xD6);
}

void SET_3_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xDE);
}

void SET_4_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xE6);
}

void SET_5_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xEE);
}

void SET_6_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xF6);
}

void SET_7_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0xFE);
}

void SET_0_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xC6);
}

bool SET_0_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_1_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xCE);
}

bool SET_1_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_2_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xD6);
}

bool SET_2_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_3_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xDE);
}

bool SET_3_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_4_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xE6);
}

bool SET_4_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_5_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xEE);
}

bool SET_5_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_6_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xF6);
}

bool SET_6_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_7_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xFE);
}

bool SET_7_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_0_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xC6);
}

bool SET_0_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_1_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xCE);
}

bool SET_1_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_2_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xD6);
}

bool SET_2_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_3_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xDE);
}

bool SET_3_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_4_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xE6);
}

bool SET_4_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_5_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xEE);
}

bool SET_5_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_6_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xF6);
}

bool SET_6_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SET_7_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0xFE);
}

bool SET_7_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SLA_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x27);
}

void SLA_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x20);
}

void SLA_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x21);
}

void SLA_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x22);
}

void SLA_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x23);
}

void SLA_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x24);
}

void SLA_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x25);
}

void SLA_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x26);
}

void SLA_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x26);
}

bool SLA_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SLA_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x26);
}

bool SLA_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SRA_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2F);
}

void SRA_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x28);
}

void SRA_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x29);
}

void SRA_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2A);
}

void SRA_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2B);
}

void SRA_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2C);
}

void SRA_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2D);
}

void SRA_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x2E);
}

void SRA_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x2E);
}

bool SRA_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SRA_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x2E);
}

bool SRA_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SRL_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3F);
}

void SRL_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x38);
}

void SRL_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x39);
}

void SRL_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3A);
}

void SRL_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3B);
}

void SRL_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3C);
}

void SRL_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3D);
}

void SRL_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xCB);
    bin->emitByte(0x3E);
}

void SRL_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x3E);
}

bool SRL_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SRL_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xCB);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
    bin->emitByte(0x3E);
}

bool SRL_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SUB_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x97);
}

void SUB_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x90);
}

void SUB_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x91);
}

void SUB_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x92);
}

void SUB_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x93);
}

void SUB_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x94);
}

void SUB_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x95);
}

void SUB_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xD6);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool SUB_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SUB_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0x96);
}

void SUB_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0x96);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool SUB_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void SUB_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0x96);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool SUB_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void XOR_A::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xAF);
}

void XOR_B::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA8);
}

void XOR_C::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xA9);
}

void XOR_D::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xAA);
}

void XOR_E::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xAB);
}

void XOR_H::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xAC);
}

void XOR_L::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xAD);
}

void XOR_n::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xEE);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool XOR_n::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void XOR_mHL::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xAE);
}

void XOR_mIXn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xDD);
    bin->emitByte(0xAE);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool XOR_mIXn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}

void XOR_mIYn::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const
{
    bin->emitByte(0xFD);
    bin->emitByte(0xAE);
    bin->emitByte(mLiteral1->evaluateByte(reporter));
}

bool XOR_mIYn::resolveValues(const ProgramSection* section, IErrorReporter* reporter)
{
    return mLiteral1->resolveValues(section->program(), address(), reporter);
}
