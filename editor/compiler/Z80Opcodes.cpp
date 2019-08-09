// THIS IS A GENERATED FILE. DO NOT EDIT!
#include "Z80Opcodes.h"

void NOP::emit(std::vector<unsigned char>& out) const
{
    out.emplace_back(0x00);
}

void RET::emit(std::vector<unsigned char>& out) const
{
    out.emplace_back(0xC9);
}
