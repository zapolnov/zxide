// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"

void NOP::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0x00);
}

void RET::emitBinary(ProgramBinary* bin) const
{
    bin->emitByte(0xC9);
}
