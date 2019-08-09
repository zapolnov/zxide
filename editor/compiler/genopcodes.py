#!/usr/bin/env python -B

class SimpleOpcode:
    def __init__(self, name, bytes, tstates):
        self.name = name
        self.bytes = bytes
        self.lengthInBytes = len(bytes)
        self.tstatesIfNotTaken = (tstates if isinstance(tstates, int) else tstates[1])
        self.tstatesIfTaken = (tstates if isinstance(tstates, int) else tstates[0])

    def codeForEmit(self):
        code = ''
        for byte in self.bytes:
            code += '    bin->emitByte(0x%02X);\n' % byte
        return code

opcodes = [
        SimpleOpcode( 'ccf', [ 0x3F       ],  4),
        SimpleOpcode( 'cpd', [ 0xED, 0xA9 ], 16),
        SimpleOpcode('cpdr', [ 0xED, 0xB9 ], [ 21, 16 ]),
        SimpleOpcode( 'cpi', [ 0xED, 0xA1 ], 16),
        SimpleOpcode('cpir', [ 0xED, 0xB1 ], [ 21, 16 ]),
        SimpleOpcode( 'cpl', [ 0x2F       ],  4),
        SimpleOpcode( 'daa', [ 0x27       ],  4),
        SimpleOpcode(  'di', [ 0xF3       ],  4),
        SimpleOpcode(  'ei', [ 0xFB       ],  4),
        SimpleOpcode( 'exx', [ 0xD9       ],  4),
        SimpleOpcode('halt', [ 0x76       ],  4),
        SimpleOpcode( 'ind', [ 0xED, 0xAA ], 16),
        SimpleOpcode('indr', [ 0xED, 0xBA ], [ 21, 16 ]),
        SimpleOpcode( 'ini', [ 0xED, 0xA2 ], 16),
        SimpleOpcode('inir', [ 0xED, 0xB2 ], [ 21, 16 ]),
        SimpleOpcode( 'ldd', [ 0xED, 0xA8 ], 16),
        SimpleOpcode('lddr', [ 0xED, 0xB8 ], [ 21, 16 ]),
        SimpleOpcode( 'ldi', [ 0xED, 0xA0 ], 16),
        SimpleOpcode('ldir', [ 0xED, 0xB0 ], [ 21, 17 ]),
        SimpleOpcode( 'neg', [ 0xED, 0x44 ],  8),
        SimpleOpcode( 'nop', [ 0x00       ],  4),
        SimpleOpcode( 'ret', [ 0xC9       ], 10),
        SimpleOpcode('rrca', [ 0x0F       ],  4),
        SimpleOpcode( 'rrd', [ 0xED, 0x67 ], 18),
        SimpleOpcode( 'scf', [ 0x37       ],  4),
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
