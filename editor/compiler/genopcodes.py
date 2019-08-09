#!/usr/bin/env python -B

class SimpleOpcode:
    def __init__(self, name, bytes, tstates):
        self.name = name
        self.bytes = bytes
        self.lengthInBytes = len(bytes)
        self.tstatesIfNotTaken = tstates
        self.tstatesIfTaken = tstates

    def codeForEmit(self):
        code = ''
        for byte in self.bytes:
            code += '    bin->emitByte(0x%02X);\n' % byte
        return code

opcodes = [
        SimpleOpcode('nop', [ 0x00 ], 4),
        SimpleOpcode('ret', [ 0xC9 ], 10),
    ]

hdr  = '// THIS IS A GENERATED FILE. DO NOT EDIT!\n'
hdr += '#ifndef COMPILER_Z80OPCODES_H\n'
hdr += '#define COMPILER_Z80OPCODES_H\n'
hdr += '\n'
hdr += '#include "ProgramOpcode.h"\n'

src  = '// THIS IS A GENERATED FILE. DO NOT EDIT!\n'
src += '#include "Z80Opcodes.h"\n'
hdr += '#include "ProgramBinary.h"\n'

for opcode in opcodes:
    hdr += '\n'
    hdr += 'class %s : public ProgramOpcode\n' % opcode.name.upper()
    hdr += '{\n'
    hdr += 'public:\n'
    hdr += '    %s(const Token& token)\n' % opcode.name.upper()
    hdr += '        : ProgramOpcode(token)\n'
    hdr += '    {\n'
    hdr += '    }\n'
    hdr += '\n'
    hdr += '    unsigned lengthInBytes() const override { return %d; }\n' % opcode.lengthInBytes
    hdr += '    unsigned tstatesIfNotTaken() const override { return %d; }\n' % opcode.tstatesIfNotTaken
    hdr += '    unsigned tstatesIfTaken() const override { return %d; }\n' % opcode.tstatesIfTaken
    hdr += '\n'
    hdr += '    void emitBinary(ProgramBinary* bin) const override;\n'
    hdr += '\n'
    hdr += '    Q_DISABLE_COPY(%s)\n' % opcode.name.upper()
    hdr += '};\n'

    src += '\n'
    src += 'void %s::emitBinary(ProgramBinary* bin) const\n' % opcode.name.upper()
    src += '{\n'
    src += opcode.codeForEmit()
    src += '}\n'

hdr += '\n'
hdr += '#endif\n'

with open("Z80Opcodes.h", "w") as f:
    f.write(hdr)
with open("Z80Opcodes.cpp", "w") as f:
    f.write(src)
