// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"
#include "CodeEmitter.h"
#include "ProgramDebugInfo.h"
#include "ProgramBinary.h"
#include "ExprEvalContext.h"

void ADC_A_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x8F);
}

void ADC_A_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x88);
}

void ADC_A_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x89);
}

void ADC_A_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x8A);
}

void ADC_A_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x8B);
}

void ADC_A_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x8C);
}

void ADC_A_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x8D);
}

void ADC_A_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xCE);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void ADC_A_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x8E);
}

void ADC_A_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x8E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void ADC_A_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x8E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void ADC_HL_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x4A);
}

void ADC_HL_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x5A);
}

void ADC_HL_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x6A);
}

void ADC_HL_SP::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x7A);
}

void ADD_A_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x87);
}

void ADD_A_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x80);
}

void ADD_A_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x81);
}

void ADD_A_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x82);
}

void ADD_A_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x83);
}

void ADD_A_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x84);
}

void ADD_A_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x85);
}

void ADD_A_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xC6);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void ADD_A_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x86);
}

void ADD_A_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x86);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void ADD_A_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x86);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void ADD_HL_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0x09);
}

void ADD_HL_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0x19);
}

void ADD_HL_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0x29);
}

void ADD_HL_SP::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0x39);
}

void ADD_IX_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x09);
}

void ADD_IX_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x19);
}

void ADD_IX_IX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x29);
}

void ADD_IX_SP::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x39);
}

void ADD_IY_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x09);
}

void ADD_IY_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x19);
}

void ADD_IY_IY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x29);
}

void ADD_IY_SP::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x39);
}

void AND_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xA7);
}

void AND_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xA0);
}

void AND_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xA1);
}

void AND_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xA2);
}

void AND_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xA3);
}

void AND_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xA4);
}

void AND_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xA5);
}

void AND_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xE6);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void AND_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xA6);
}

void AND_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xA6);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void AND_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xA6);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void BIT_0_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x46);
}

void BIT_1_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x4E);
}

void BIT_2_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x56);
}

void BIT_3_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x5E);
}

void BIT_4_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x66);
}

void BIT_5_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x6E);
}

void BIT_6_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x76);
}

void BIT_7_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x7E);
}

void BIT_0_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x46);
}

void BIT_1_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x4E);
}

void BIT_2_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x56);
}

void BIT_3_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x5E);
}

void BIT_4_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x66);
}

void BIT_5_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x6E);
}

void BIT_6_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x76);
}

void BIT_7_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x7E);
}

void BIT_0_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x46);
}

void BIT_1_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x4E);
}

void BIT_2_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x56);
}

void BIT_3_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x5E);
}

void BIT_4_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x66);
}

void BIT_5_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x6E);
}

void BIT_6_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x76);
}

void BIT_7_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x7E);
}

void BIT_0_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x47);
}

void BIT_0_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x40);
}

void BIT_0_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x41);
}

void BIT_0_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x42);
}

void BIT_0_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x43);
}

void BIT_0_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x44);
}

void BIT_0_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x45);
}

void BIT_1_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x4F);
}

void BIT_1_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x48);
}

void BIT_1_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x49);
}

void BIT_1_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x4A);
}

void BIT_1_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x4B);
}

void BIT_1_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x4C);
}

void BIT_1_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x4D);
}

void BIT_2_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x57);
}

void BIT_2_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x50);
}

void BIT_2_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x51);
}

void BIT_2_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x52);
}

void BIT_2_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x53);
}

void BIT_2_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x54);
}

void BIT_2_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x55);
}

void BIT_3_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x5F);
}

void BIT_3_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x58);
}

void BIT_3_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x59);
}

void BIT_3_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x5A);
}

void BIT_3_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x5B);
}

void BIT_3_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x5C);
}

void BIT_3_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x5D);
}

void BIT_4_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x67);
}

void BIT_4_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x60);
}

void BIT_4_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x61);
}

void BIT_4_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x62);
}

void BIT_4_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x63);
}

void BIT_4_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x64);
}

void BIT_4_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x65);
}

void BIT_5_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x6F);
}

void BIT_5_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x68);
}

void BIT_5_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x69);
}

void BIT_5_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x6A);
}

void BIT_5_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x6B);
}

void BIT_5_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x6C);
}

void BIT_5_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x6D);
}

void BIT_6_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x77);
}

void BIT_6_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x70);
}

void BIT_6_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x71);
}

void BIT_6_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x72);
}

void BIT_6_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x73);
}

void BIT_6_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x74);
}

void BIT_6_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x75);
}

void BIT_7_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x7F);
}

void BIT_7_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x78);
}

void BIT_7_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x79);
}

void BIT_7_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x7A);
}

void BIT_7_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x7B);
}

void BIT_7_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x7C);
}

void BIT_7_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x7D);
}

void CALL_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 17, 17);
    binary->emitByte(token().file, token().line, 0xCD);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void CALL_C_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 17, 10);
    binary->emitByte(token().file, token().line, 0xDC);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void CALL_M_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 17, 10);
    binary->emitByte(token().file, token().line, 0xFC);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void CALL_NC_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 17, 10);
    binary->emitByte(token().file, token().line, 0xD4);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void CALL_NZ_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 17, 10);
    binary->emitByte(token().file, token().line, 0xC4);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void CALL_P_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 17, 10);
    binary->emitByte(token().file, token().line, 0xF4);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void CALL_PE_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 17, 10);
    binary->emitByte(token().file, token().line, 0xEC);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void CALL_PO_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 17, 10);
    binary->emitByte(token().file, token().line, 0xE4);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void CALL_Z_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 17, 10);
    binary->emitByte(token().file, token().line, 0xCC);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void CCF::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x3F);
}

void CP_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xBF);
}

void CP_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xB8);
}

void CP_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xB9);
}

void CP_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xBA);
}

void CP_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xBB);
}

void CP_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xBC);
}

void CP_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xBD);
}

void CP_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xFE);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void CP_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xBE);
}

void CP_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xBE);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void CP_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xBE);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void CPD::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xA9);
}

void CPDR::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 21, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xB9);
}

void CPI::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xA1);
}

void CPIR::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 21, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xB1);
}

void CPL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x2F);
}

void DAA::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x27);
}

void DEC_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x3D);
}

void DEC_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x05);
}

void DEC_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x0D);
}

void DEC_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x15);
}

void DEC_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x1D);
}

void DEC_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x25);
}

void DEC_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x2D);
}

void DEC_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0x35);
}

void DEC_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x35);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void DEC_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x35);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void DEC_IX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x2B);
}

void DEC_IY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x2B);
}

void DEC_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 6, 6);
    binary->emitByte(token().file, token().line, 0x0B);
}

void DEC_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 6, 6);
    binary->emitByte(token().file, token().line, 0x1B);
}

void DEC_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 6, 6);
    binary->emitByte(token().file, token().line, 0x2B);
}

void DEC_SP::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 6, 6);
    binary->emitByte(token().file, token().line, 0x3B);
}

void DI::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xF3);
}

void DJNZ_off::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 13);
    binary->emitByte(token().file, token().line, 0x10);
    binary->emitByte(token().file, token().line, context1.evaluateByteOffset(mLiteral1));
}

void EI::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xFB);
}

void EX_mSP_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xE3);
}

void EX_mSP_IX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xE3);
}

void EX_mSP_IY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xE3);
}

void EX_AF_AFs::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x08);
}

void EX_DE_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xEB);
}

void EXX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xD9);
}

void HALT::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x76);
}

void IM_0::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x46);
}

void IM_1::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x56);
}

void IM_2::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x5E);
}

void IN_A_mn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xDB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void IN_A_mC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x78);
}

void IN_B_mC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x40);
}

void IN_C_mC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x48);
}

void IN_D_mC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x50);
}

void IN_E_mC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x58);
}

void IN_H_mC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x60);
}

void IN_L_mC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x68);
}

void INC_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x3C);
}

void INC_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x04);
}

void INC_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x0C);
}

void INC_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x14);
}

void INC_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x1C);
}

void INC_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x24);
}

void INC_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x2C);
}

void INC_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0x34);
}

void INC_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x34);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void INC_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x34);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void INC_IX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x23);
}

void INC_IY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x23);
}

void INC_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 6, 6);
    binary->emitByte(token().file, token().line, 0x03);
}

void INC_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 6, 6);
    binary->emitByte(token().file, token().line, 0x13);
}

void INC_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 6, 6);
    binary->emitByte(token().file, token().line, 0x23);
}

void INC_SP::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 6, 6);
    binary->emitByte(token().file, token().line, 0x33);
}

void IND::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xAA);
}

void INDR::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 21, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xBA);
}

void INI::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xA2);
}

void INIR::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 21, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xB2);
}

void JP_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xC3);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void JP_C_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xDA);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void JP_M_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xFA);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void JP_NC_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xD2);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void JP_NZ_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xC2);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void JP_P_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xF2);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void JP_PE_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xEA);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void JP_PO_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xE2);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void JP_Z_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xCA);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void JP_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xE9);
}

void JP_mIX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xE9);
}

void JP_mIY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xE9);
}

void JR_off::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0x18);
    binary->emitByte(token().file, token().line, context1.evaluateByteOffset(mLiteral1));
}

void JR_C_off::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 7);
    binary->emitByte(token().file, token().line, 0x38);
    binary->emitByte(token().file, token().line, context1.evaluateByteOffset(mLiteral1));
}

void JR_NC_off::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 7);
    binary->emitByte(token().file, token().line, 0x30);
    binary->emitByte(token().file, token().line, context1.evaluateByteOffset(mLiteral1));
}

void JR_NZ_off::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 7);
    binary->emitByte(token().file, token().line, 0x20);
    binary->emitByte(token().file, token().line, context1.evaluateByteOffset(mLiteral1));
}

void JR_Z_off::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 7);
    binary->emitByte(token().file, token().line, 0x28);
    binary->emitByte(token().file, token().line, context1.evaluateByteOffset(mLiteral1));
}

void LD_A_mBC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x0A);
}

void LD_A_mDE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x1A);
}

void LD_A_I::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 9, 9);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x57);
}

void LD_A_mnn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 13, 13);
    binary->emitByte(token().file, token().line, 0x3A);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_A_R::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 9, 9);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x5F);
}

void LD_mBC_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x02);
}

void LD_mDE_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x12);
}

void LD_mHL_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0x36);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIXn_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    ExprEvalContext context2(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x36);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, context2.evaluateByte(mLiteral2));
}

void LD_mIYn_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    ExprEvalContext context2(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x36);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, context2.evaluateByte(mLiteral2));
}

void LD_mnn_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 13, 13);
    binary->emitByte(token().file, token().line, 0x32);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_mnn_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x43);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_mnn_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x53);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_mnn_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0x22);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_mnn_SP::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x73);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_mnn_IX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x22);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_mnn_IY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x22);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_BC_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0x01);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_DE_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0x11);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_HL_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0x21);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_SP_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0x31);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_BC_mnn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x4B);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_DE_mnn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x5B);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_HL_mnn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0x2A);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_SP_mnn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x7B);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_mHL_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x77);
}

void LD_mHL_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x70);
}

void LD_mHL_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x71);
}

void LD_mHL_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x72);
}

void LD_mHL_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x73);
}

void LD_mHL_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x74);
}

void LD_mHL_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x75);
}

void LD_mIXn_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x77);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIXn_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x70);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIXn_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x71);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIXn_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x72);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIXn_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x73);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIXn_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x74);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIXn_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x75);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIYn_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x77);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIYn_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x70);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIYn_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x71);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIYn_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x72);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIYn_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x73);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIYn_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x74);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_mIYn_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x75);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_I_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 9, 9);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x47);
}

void LD_IX_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 14, 14);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x21);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_IX_mnn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x2A);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_IY_nn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 14, 14);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x21);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_IY_mnn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 20, 20);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x2A);
    binary->emitWord(token().file, token().line, context1.evaluateWord(mLiteral1));
}

void LD_R_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 9, 9);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x4F);
}

void LD_A_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x7E);
}

void LD_B_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x46);
}

void LD_C_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x4E);
}

void LD_D_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x56);
}

void LD_E_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x5E);
}

void LD_H_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x66);
}

void LD_L_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x6E);
}

void LD_A_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x7E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_B_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x46);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_C_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x4E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_D_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x56);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_E_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x5E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_H_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x66);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_L_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x6E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_A_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x7E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_B_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x46);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_C_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x4E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_D_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x56);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_E_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x5E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_H_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x66);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_L_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x6E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_A_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x3E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_B_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x06);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_C_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x0E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_D_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x16);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_E_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x1E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_H_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x26);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_L_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x2E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void LD_A_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x7F);
}

void LD_B_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x47);
}

void LD_C_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x4F);
}

void LD_D_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x57);
}

void LD_E_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x5F);
}

void LD_H_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x67);
}

void LD_L_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x6F);
}

void LD_A_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x78);
}

void LD_B_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x40);
}

void LD_C_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x48);
}

void LD_D_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x50);
}

void LD_E_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x58);
}

void LD_H_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x60);
}

void LD_L_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x68);
}

void LD_A_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x79);
}

void LD_B_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x41);
}

void LD_C_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x49);
}

void LD_D_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x51);
}

void LD_E_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x59);
}

void LD_H_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x61);
}

void LD_L_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x69);
}

void LD_A_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x7A);
}

void LD_B_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x42);
}

void LD_C_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x4A);
}

void LD_D_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x52);
}

void LD_E_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x5A);
}

void LD_H_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x62);
}

void LD_L_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x6A);
}

void LD_A_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x7B);
}

void LD_B_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x43);
}

void LD_C_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x4B);
}

void LD_D_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x53);
}

void LD_E_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x5B);
}

void LD_H_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x63);
}

void LD_L_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x6B);
}

void LD_A_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x7C);
}

void LD_B_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x44);
}

void LD_C_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x4C);
}

void LD_D_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x54);
}

void LD_E_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x5C);
}

void LD_H_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x64);
}

void LD_L_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x6C);
}

void LD_A_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x7D);
}

void LD_B_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x45);
}

void LD_C_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x4D);
}

void LD_D_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x55);
}

void LD_E_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x5D);
}

void LD_H_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x65);
}

void LD_L_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x6D);
}

void LD_SP_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 6, 6);
    binary->emitByte(token().file, token().line, 0xF9);
}

void LD_SP_IX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xF9);
}

void LD_SP_IY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xF9);
}

void LDD::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xA8);
}

void LDDR::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 21, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xB8);
}

void LDI::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xA0);
}

void LDIR::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 21, 17);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xB0);
}

void NEG::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x44);
}

void NOP::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x00);
}

void OR_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xB7);
}

void OR_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xB0);
}

void OR_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xB1);
}

void OR_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xB2);
}

void OR_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xB3);
}

void OR_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xB4);
}

void OR_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xB5);
}

void OR_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xF6);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void OR_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xB6);
}

void OR_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xB6);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void OR_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xB6);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void OTDR::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 21, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xBB);
}

void OTIR::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 21, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xB3);
}

void OUT_mn_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xD3);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void OUT_mC_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x79);
}

void OUT_mC_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x41);
}

void OUT_mC_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x49);
}

void OUT_mC_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x51);
}

void OUT_mC_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x59);
}

void OUT_mC_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x61);
}

void OUT_mC_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 12, 12);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x69);
}

void OUTD::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xAB);
}

void OUTI::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 16, 16);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0xA3);
}

void POP_IX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 14, 14);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xE1);
}

void POP_IY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 14, 14);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xE1);
}

void POP_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xC1);
}

void POP_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xD1);
}

void POP_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xE1);
}

void POP_AF::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xF1);
}

void PUSH_IX::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xE5);
}

void PUSH_IY::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xE5);
}

void PUSH_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xC5);
}

void PUSH_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xD5);
}

void PUSH_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xE5);
}

void PUSH_AF::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xF5);
}

void RES_0_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x87);
}

void RES_0_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x80);
}

void RES_0_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x81);
}

void RES_0_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x82);
}

void RES_0_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x83);
}

void RES_0_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x84);
}

void RES_0_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x85);
}

void RES_1_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x8F);
}

void RES_1_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x88);
}

void RES_1_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x89);
}

void RES_1_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x8A);
}

void RES_1_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x8B);
}

void RES_1_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x8C);
}

void RES_1_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x8D);
}

void RES_2_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x97);
}

void RES_2_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x90);
}

void RES_2_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x91);
}

void RES_2_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x92);
}

void RES_2_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x93);
}

void RES_2_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x94);
}

void RES_2_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x95);
}

void RES_3_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x9F);
}

void RES_3_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x98);
}

void RES_3_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x99);
}

void RES_3_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x9A);
}

void RES_3_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x9B);
}

void RES_3_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x9C);
}

void RES_3_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x9D);
}

void RES_4_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA7);
}

void RES_4_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA0);
}

void RES_4_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA1);
}

void RES_4_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA2);
}

void RES_4_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA3);
}

void RES_4_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA4);
}

void RES_4_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA5);
}

void RES_5_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xAF);
}

void RES_5_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA8);
}

void RES_5_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA9);
}

void RES_5_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xAA);
}

void RES_5_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xAB);
}

void RES_5_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xAC);
}

void RES_5_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xAD);
}

void RES_6_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB7);
}

void RES_6_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB0);
}

void RES_6_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB1);
}

void RES_6_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB2);
}

void RES_6_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB3);
}

void RES_6_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB4);
}

void RES_6_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB5);
}

void RES_7_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xBF);
}

void RES_7_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB8);
}

void RES_7_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB9);
}

void RES_7_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xBA);
}

void RES_7_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xBB);
}

void RES_7_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xBC);
}

void RES_7_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xBD);
}

void RES_0_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x86);
}

void RES_1_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x8E);
}

void RES_2_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x96);
}

void RES_3_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x9E);
}

void RES_4_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xA6);
}

void RES_5_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xAE);
}

void RES_6_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xB6);
}

void RES_7_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xBE);
}

void RES_0_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x86);
}

void RES_1_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x8E);
}

void RES_2_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x96);
}

void RES_3_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x9E);
}

void RES_4_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xA6);
}

void RES_5_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xAE);
}

void RES_6_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xB6);
}

void RES_7_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xBE);
}

void RES_0_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x86);
}

void RES_1_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x8E);
}

void RES_2_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x96);
}

void RES_3_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x9E);
}

void RES_4_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xA6);
}

void RES_5_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xAE);
}

void RES_6_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xB6);
}

void RES_7_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xBE);
}

void RET::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 10, 10);
    binary->emitByte(token().file, token().line, 0xC9);
}

void RET_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 5);
    binary->emitByte(token().file, token().line, 0xD8);
}

void RET_M::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 5);
    binary->emitByte(token().file, token().line, 0xF8);
}

void RET_NC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 5);
    binary->emitByte(token().file, token().line, 0xD0);
}

void RET_NZ::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 5);
    binary->emitByte(token().file, token().line, 0xC0);
}

void RET_P::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 5);
    binary->emitByte(token().file, token().line, 0xF0);
}

void RET_PE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 5);
    binary->emitByte(token().file, token().line, 0xE8);
}

void RET_PO::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 5);
    binary->emitByte(token().file, token().line, 0xE0);
}

void RET_Z::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 5);
    binary->emitByte(token().file, token().line, 0xC8);
}

void RETI::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 14, 14);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x4D);
}

void RETN::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 14, 14);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x45);
}

void RL_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x17);
}

void RL_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x10);
}

void RL_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x11);
}

void RL_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x12);
}

void RL_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x13);
}

void RL_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x14);
}

void RL_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x15);
}

void RL_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x16);
}

void RL_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x16);
}

void RL_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x16);
}

void RLA::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x17);
}

void RLC_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x07);
}

void RLC_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x00);
}

void RLC_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x01);
}

void RLC_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x02);
}

void RLC_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x03);
}

void RLC_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x04);
}

void RLC_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x05);
}

void RLC_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x06);
}

void RLC_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x06);
}

void RLC_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x06);
}

void RLCA::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x07);
}

void RLD::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 18, 18);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x6F);
}

void RR_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x1F);
}

void RR_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x18);
}

void RR_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x19);
}

void RR_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x1A);
}

void RR_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x1B);
}

void RR_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x1C);
}

void RR_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x1D);
}

void RR_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x1E);
}

void RR_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x1E);
}

void RR_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x1E);
}

void RRA::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x1F);
}

void RRC_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x0F);
}

void RRC_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x08);
}

void RRC_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x09);
}

void RRC_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x0A);
}

void RRC_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x0B);
}

void RRC_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x0C);
}

void RRC_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x0D);
}

void RRC_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x0E);
}

void RRC_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x0E);
}

void RRC_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x0E);
}

void RRCA::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x0F);
}

void RRD::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 18, 18);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x67);
}

void RST_00::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xC7);
}

void RST_08::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xCF);
}

void RST_10::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xD7);
}

void RST_18::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xDF);
}

void RST_20::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xE7);
}

void RST_28::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xEF);
}

void RST_30::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xF7);
}

void RST_38::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 11, 11);
    binary->emitByte(token().file, token().line, 0xFF);
}

void SBC_A_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x9F);
}

void SBC_A_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x98);
}

void SBC_A_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x99);
}

void SBC_A_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x9A);
}

void SBC_A_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x9B);
}

void SBC_A_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x9C);
}

void SBC_A_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x9D);
}

void SBC_A_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xDE);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void SBC_A_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x9E);
}

void SBC_A_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x9E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void SBC_A_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x9E);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void SBC_HL_BC::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x42);
}

void SBC_HL_DE::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x52);
}

void SBC_HL_HL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x62);
}

void SBC_HL_SP::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xED);
    binary->emitByte(token().file, token().line, 0x72);
}

void SCF::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x37);
}

void SET_0_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC7);
}

void SET_0_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC0);
}

void SET_0_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC1);
}

void SET_0_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC2);
}

void SET_0_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC3);
}

void SET_0_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC4);
}

void SET_0_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC5);
}

void SET_1_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xCF);
}

void SET_1_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC8);
}

void SET_1_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC9);
}

void SET_1_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xCA);
}

void SET_1_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xCB);
}

void SET_1_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xCC);
}

void SET_1_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xCD);
}

void SET_2_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD7);
}

void SET_2_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD0);
}

void SET_2_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD1);
}

void SET_2_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD2);
}

void SET_2_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD3);
}

void SET_2_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD4);
}

void SET_2_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD5);
}

void SET_3_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xDF);
}

void SET_3_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD8);
}

void SET_3_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD9);
}

void SET_3_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xDA);
}

void SET_3_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xDB);
}

void SET_3_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xDC);
}

void SET_3_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xDD);
}

void SET_4_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE7);
}

void SET_4_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE0);
}

void SET_4_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE1);
}

void SET_4_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE2);
}

void SET_4_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE3);
}

void SET_4_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE4);
}

void SET_4_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE5);
}

void SET_5_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xEF);
}

void SET_5_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE8);
}

void SET_5_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE9);
}

void SET_5_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xEA);
}

void SET_5_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xEB);
}

void SET_5_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xEC);
}

void SET_5_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xED);
}

void SET_6_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF7);
}

void SET_6_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF0);
}

void SET_6_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF1);
}

void SET_6_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF2);
}

void SET_6_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF3);
}

void SET_6_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF4);
}

void SET_6_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF5);
}

void SET_7_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xFF);
}

void SET_7_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF8);
}

void SET_7_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF9);
}

void SET_7_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xFA);
}

void SET_7_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xFB);
}

void SET_7_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xFC);
}

void SET_7_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xFD);
}

void SET_0_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xC6);
}

void SET_1_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xCE);
}

void SET_2_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xD6);
}

void SET_3_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xDE);
}

void SET_4_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xE6);
}

void SET_5_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xEE);
}

void SET_6_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xF6);
}

void SET_7_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0xFE);
}

void SET_0_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xC6);
}

void SET_1_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xCE);
}

void SET_2_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xD6);
}

void SET_3_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xDE);
}

void SET_4_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xE6);
}

void SET_5_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xEE);
}

void SET_6_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xF6);
}

void SET_7_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xFE);
}

void SET_0_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xC6);
}

void SET_1_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xCE);
}

void SET_2_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xD6);
}

void SET_3_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xDE);
}

void SET_4_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xE6);
}

void SET_5_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xEE);
}

void SET_6_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xF6);
}

void SET_7_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0xFE);
}

void SLA_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x27);
}

void SLA_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x20);
}

void SLA_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x21);
}

void SLA_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x22);
}

void SLA_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x23);
}

void SLA_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x24);
}

void SLA_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x25);
}

void SLA_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x26);
}

void SLA_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x26);
}

void SLA_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x26);
}

void SRA_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x2F);
}

void SRA_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x28);
}

void SRA_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x29);
}

void SRA_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x2A);
}

void SRA_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x2B);
}

void SRA_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x2C);
}

void SRA_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x2D);
}

void SRA_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x2E);
}

void SRA_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x2E);
}

void SRA_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x2E);
}

void SRL_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x3F);
}

void SRL_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x38);
}

void SRL_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x39);
}

void SRL_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x3A);
}

void SRL_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x3B);
}

void SRL_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x3C);
}

void SRL_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 8, 8);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x3D);
}

void SRL_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 15, 15);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, 0x3E);
}

void SRL_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x3E);
}

void SRL_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 23, 23);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xCB);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
    binary->emitByte(token().file, token().line, 0x3E);
}

void SUB_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x97);
}

void SUB_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x90);
}

void SUB_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x91);
}

void SUB_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x92);
}

void SUB_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x93);
}

void SUB_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x94);
}

void SUB_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0x95);
}

void SUB_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xD6);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void SUB_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0x96);
}

void SUB_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0x96);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void SUB_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0x96);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void XOR_A::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xAF);
}

void XOR_B::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xA8);
}

void XOR_C::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xA9);
}

void XOR_D::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xAA);
}

void XOR_E::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xAB);
}

void XOR_H::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xAC);
}

void XOR_L::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 4, 4);
    binary->emitByte(token().file, token().line, 0xAD);
}

void XOR_n::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xEE);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void XOR_mHL::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 7, 7);
    binary->emitByte(token().file, token().line, 0xAE);
}

void XOR_mIXn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xDD);
    binary->emitByte(token().file, token().line, 0xAE);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}

void XOR_mIYn::emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    ExprEvalContext context1(program, reporter, binary->endAddress(), this);
    binary->debugInfo()->setTStatesForLocation(token().file, token().line, 19, 19);
    binary->emitByte(token().file, token().line, 0xFD);
    binary->emitByte(token().file, token().line, 0xAE);
    binary->emitByte(token().file, token().line, context1.evaluateByte(mLiteral1));
}
