#!/usr/bin/env python -B

from collections import OrderedDict

class Opcode:
    def __init__(self, name, operands, bytes, tstates):
        self.name = name
        self.className = name.upper()
        self.bytes = bytes
        self.operands = operands
        self.tstatesIfNotTaken = (tstates if isinstance(tstates, int) else tstates[1])
        self.tstatesIfTaken = (tstates if isinstance(tstates, int) else tstates[0])
        self.lengthInBytes = len(bytes)
        literalCount = 0
        for op in operands:
            if '##' in op:
                literalCount += 1
                self.lengthInBytes += 2
                self.className += '_nn'
            elif '#' in op:
                literalCount += 1
                self.lengthInBytes += 1
                self.className += '_n'
            elif op in [ '(bc)', '(de)', '(hl)' ]:
                self.className += '_m%s' % op[1:3].upper()
            else:
                self.className += '_%s' % op.upper()
        self.numLiterals = literalCount

    def argsDecl(self):
        args = ''
        for idx in range(0, self.numLiterals):
            args += ', unsigned literal%d' % (idx + 1)
        return args

    def argsCall(self):
        args = ''
        for idx in range(0, self.numLiterals):
            args += ', literal%d' % (idx + 1)
        return args

    def codeForEmit(self):
        code = ''
        for byte in self.bytes:
            code += '    bin->emitByte(0x%02X);\n' % byte
        literalIndex = 1
        for op in self.operands:
            if '##' in op:
                code += '    bin->emitByte(mLiteral%d & 0xFF);\n' % literalIndex
                code += '    bin->emitByte((mLiteral%d >> 8) & 0xFF);\n' % literalIndex
                literalIndex += 1
            elif '#' in op:
                code += '    bin->emitByte(mLiteral%d & 0xFF);\n' % literalIndex
                literalIndex += 1
        return code

opcodes = [
        Opcode( 'adc', [         'a',      'a' ], [ 0x8F       ], 4),
        Opcode( 'adc', [         'a',      'b' ], [ 0x88       ], 4),
        Opcode( 'adc', [         'a',      'c' ], [ 0x89       ], 4),
        Opcode( 'adc', [         'a',      'd' ], [ 0x8A       ], 4),
        Opcode( 'adc', [         'a',      'e' ], [ 0x8B       ], 4),
        Opcode( 'adc', [         'a',      'h' ], [ 0x8C       ], 4),
        Opcode( 'adc', [         'a',      'l' ], [ 0x8D       ], 4),
        Opcode( 'adc', [         'a',   '(hl)' ], [ 0x8E       ], 4),
        Opcode( 'adc', [         'a',      '#' ], [ 0xCE       ], 7),
        Opcode( 'ccf', [                       ], [ 0x3F       ],  4),
        Opcode( 'cpd', [                       ], [ 0xED, 0xA9 ], 16),
        Opcode('cpdr', [                       ], [ 0xED, 0xB9 ], [ 21, 16 ]),
        Opcode( 'cpi', [                       ], [ 0xED, 0xA1 ], 16),
        Opcode('cpir', [                       ], [ 0xED, 0xB1 ], [ 21, 16 ]),
        Opcode( 'cpl', [                       ], [ 0x2F       ],  4),
        Opcode( 'daa', [                       ], [ 0x27       ],  4),
        Opcode(  'di', [                       ], [ 0xF3       ],  4),
        Opcode(  'ei', [                       ], [ 0xFB       ],  4),
        Opcode( 'exx', [                       ], [ 0xD9       ],  4),
        Opcode('halt', [                       ], [ 0x76       ],  4),
        Opcode( 'ind', [                       ], [ 0xED, 0xAA ], 16),
        Opcode('indr', [                       ], [ 0xED, 0xBA ], [ 21, 16 ]),
        Opcode( 'ini', [                       ], [ 0xED, 0xA2 ], 16),
        Opcode('inir', [                       ], [ 0xED, 0xB2 ], [ 21, 16 ]),
        Opcode( 'ldd', [                       ], [ 0xED, 0xA8 ], 16),
        Opcode('lddr', [                       ], [ 0xED, 0xB8 ], [ 21, 16 ]),
        Opcode( 'ldi', [                       ], [ 0xED, 0xA0 ], 16),
        Opcode('ldir', [                       ], [ 0xED, 0xB0 ], [ 21, 17 ]),
        Opcode('otdr', [                       ], [ 0xED, 0xBB ], [ 21, 16 ]),
        Opcode('otir', [                       ], [ 0xED, 0xB3 ], [ 21, 16 ]),
        Opcode('outd', [                       ], [ 0xED, 0xAB ], 16),
        Opcode('outi', [                       ], [ 0xED, 0xA3 ], 16),
        Opcode( 'neg', [                       ], [ 0xED, 0x44 ],  8),
        Opcode( 'nop', [                       ], [ 0x00       ],  4),
        Opcode( 'ret', [                       ], [ 0xC9       ], 10),
        Opcode('reti', [                       ], [ 0xED, 0x4D ], 14),
        Opcode('retn', [                       ], [ 0xED, 0x45 ], 14),
        Opcode( 'rla', [                       ], [ 0x17       ],  4),
        Opcode('rlca', [                       ], [ 0x07       ],  4),
        Opcode( 'rld', [                       ], [ 0xED, 0x6F ], 18),
        Opcode( 'rra', [                       ], [ 0x1F       ],  4),
        Opcode('rrca', [                       ], [ 0x0F       ],  4),
        Opcode( 'rrd', [                       ], [ 0xED, 0x67 ], 18),
        Opcode( 'scf', [                       ], [ 0x37       ],  4),
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
    hdr += 'class %s : public ProgramOpcode\n' % opcode.className
    hdr += '{\n'
    hdr += 'public:\n'
    hdr += '    %s(const Token& token%s)\n' % (opcode.className, opcode.argsDecl())
    hdr += '        : ProgramOpcode(token)\n'
    for idx in range(0, opcode.numLiterals):
        hdr += '        , mLiteral%d(literal%d)\n' % (idx + 1, idx + 1)
    hdr += '    {\n'
    hdr += '    }\n'
    hdr += '\n'
    hdr += '    unsigned lengthInBytes() const override { return %d; }\n' % opcode.lengthInBytes
    hdr += '    unsigned tstatesIfNotTaken() const override { return %d; }\n' % opcode.tstatesIfNotTaken
    hdr += '    unsigned tstatesIfTaken() const override { return %d; }\n' % opcode.tstatesIfTaken
    hdr += '\n'
    hdr += '    void emitBinary(ProgramBinary* bin) const override;\n'
    hdr += '\n'
    if opcode.numLiterals > 0:
        hdr += 'private:\n'
        for idx in range(0, opcode.numLiterals):
            hdr += '    unsigned mLiteral%d;\n' % (idx + 1)
        hdr += '\n'
    hdr += '    Q_DISABLE_COPY(%s)\n' % opcode.className
    hdr += '};\n'

    src += '\n'
    src += 'void %s::emitBinary(ProgramBinary* bin) const\n' % opcode.className
    src += '{\n'
    src += opcode.codeForEmit()
    src += '}\n'

def getDict(dict, key):
    if key in dict:
        return dict[key]
    else:
        obj = OrderedDict()
        dict[key] = obj
        return obj

def genCode(dict, indent):
    global hdr
    for key, value in dict.items():
        hdr += '%sif (%s) { \\\n' % (indent, key)
        if not isinstance(value, Opcode):
            hdr += '%s    nextToken(); \\\n' % indent
            genCode(value, indent + '    ')
        else:
            hdr += '%s    mSection->emit<%s>(token%s); \\\n' % (indent, value.className, value.argsCall())
            hdr += '%s    return; \\\n' % indent
        hdr += '%s} \\\n' % indent

opcodeMap = OrderedDict()
for opcode in opcodes:
    conds = [ 'opcode == "%s"' % opcode.name ]
    literalIndex = 1
    first = True
    for op in opcode.operands:
        if first:
            first = False
        else:
            conds.append('lastTokenId() == T_COMMA')

        if op in [ 'a', 'b', 'c', 'd', 'e', 'h', 'l' ]:
            conds.append('lastTokenId() == T_IDENTIFIER && lastTokenText() == "%s"' % op)
        elif op in [ '(bc)', '(de)', '(hl)' ]:
            conds.append('lastTokenId() == T_LPAREN')
            conds.append('lastTokenId() == T_IDENTIFIER && lastTokenText() == "%s"' % op[1:3])
            conds.append('lastTokenId() == T_RPAREN')
        elif op == '#':
            conds.append('expectByteLiteral(&literal%d)' % literalIndex)
            literalIndex += 1
        elif op == '##':
            conds.append('expectWordLiteral(&literal%d)' % literalIndex)
            literalIndex += 1
        else:
            raise Exception('Unknown operand "%s"' % op)

    dict = opcodeMap
    for cond in conds:
        dict = getDict(dict, cond)
    dict['lastTokenId() == T_EOL'] = opcode

hdr += '\n'
hdr += '#define PARSE_OPCODE \\\n'
genCode(opcodeMap, '    ')

hdr += '\n'
hdr += '#endif\n'

with open("Z80Opcodes.h", "w") as f:
    f.write(hdr)
with open("Z80Opcodes.cpp", "w") as f:
    f.write(src)
