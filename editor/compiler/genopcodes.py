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
        self.lengthInBytes = 0
        for byte in bytes:
            if byte != '#':
                self.lengthInBytes += 1
        literalCount = 0
        for op in operands:
            if op in [ '(bc)', '(de)', '(hl)', '(ix)', '(iy)' ]:
                self.className += '_m%s' % op[1:3].upper()
            elif op in [ '(ix+#)', '(iy+#)' ]:
                literalCount += 1
                self.lengthInBytes += 1
                self.className += '_m%sn' % op[1:3].upper()
            elif op == '#':
                literalCount += 1
                self.lengthInBytes += 1
                self.className += '_n'
            elif op == '##':
                literalCount += 1
                self.lengthInBytes += 2
                self.className += '_nn'
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
        literalIndex = 0
        i = 0
        for byte in self.bytes:
            if byte == '#':
                found = False
                while i < len(self.operands):
                    if '##' in self.operands[i]:
                        i += 1
                        literalIndex += 1
                        code += '    bin->emitByte(mLiteral%d & 0xFF);\n' % literalIndex
                        code += '    bin->emitByte((mLiteral%d >> 8) & 0xFF);\n' % literalIndex
                        found = True
                        break
                    elif '#' in self.operands[i]:
                        i += 1
                        literalIndex += 1
                        code += '    bin->emitByte(mLiteral%d & 0xFF);\n' % literalIndex
                        found = True
                        break
                    else:
                        i += 1
                if not found:
                    raise Exception('Invalid operand')
            else:
                code += '    bin->emitByte(0x%02X);\n' % byte
        return code

opcodes = [
        Opcode( 'adc', [         'a',      'a' ], [ 0x8F                   ],  4),
        Opcode( 'adc', [         'a',      'b' ], [ 0x88                   ],  4),
        Opcode( 'adc', [         'a',      'c' ], [ 0x89                   ],  4),
        Opcode( 'adc', [         'a',      'd' ], [ 0x8A                   ],  4),
        Opcode( 'adc', [         'a',      'e' ], [ 0x8B                   ],  4),
        Opcode( 'adc', [         'a',      'h' ], [ 0x8C                   ],  4),
        Opcode( 'adc', [         'a',      'l' ], [ 0x8D                   ],  4),
        Opcode( 'adc', [         'a',      '#' ], [ 0xCE, '#'              ],  7),
        Opcode( 'adc', [         'a',   '(hl)' ], [ 0x8E                   ],  7),
        Opcode( 'adc', [         'a', '(ix+#)' ], [ 0xDD, 0x8E, '#'        ], 19),
        Opcode( 'adc', [         'a', '(iy+#)' ], [ 0xFD, 0x8E, '#'        ], 19),
        Opcode( 'adc', [        'hl',     'bc' ], [ 0xED, 0x4A             ], 15),
        Opcode( 'adc', [        'hl',     'de' ], [ 0xED, 0x5A             ], 15),
        Opcode( 'adc', [        'hl',     'hl' ], [ 0xED, 0x6A             ], 15),
        Opcode( 'adc', [        'hl',     'sp' ], [ 0xED, 0x7A             ], 15),
        Opcode( 'add', [         'a',      'a' ], [ 0x87                   ],  4),
        Opcode( 'add', [         'a',      'b' ], [ 0x80                   ],  4),
        Opcode( 'add', [         'a',      'c' ], [ 0x81                   ],  4),
        Opcode( 'add', [         'a',      'd' ], [ 0x82                   ],  4),
        Opcode( 'add', [         'a',      'e' ], [ 0x83                   ],  4),
        Opcode( 'add', [         'a',      'h' ], [ 0x84                   ],  4),
        Opcode( 'add', [         'a',      'l' ], [ 0x85                   ],  4),
        Opcode( 'add', [         'a',      '#' ], [ 0xC6, '#'              ],  7),
        Opcode( 'add', [         'a',   '(hl)' ], [ 0x86                   ],  7),
        Opcode( 'add', [         'a', '(ix+#)' ], [ 0xDD, 0x86, '#'        ], 19),
        Opcode( 'add', [         'a', '(iy+#)' ], [ 0xFD, 0x86, '#'        ], 19),
        Opcode( 'add', [        'hl',     'bc' ], [ 0x09                   ], 11),
        Opcode( 'add', [        'hl',     'de' ], [ 0x19                   ], 11),
        Opcode( 'add', [        'hl',     'hl' ], [ 0x29                   ], 11),
        Opcode( 'add', [        'hl',     'sp' ], [ 0x39                   ], 11),
        Opcode( 'add', [        'ix',     'bc' ], [ 0xDD, 0x09             ], 15),
        Opcode( 'add', [        'ix',     'de' ], [ 0xDD, 0x19             ], 15),
        Opcode( 'add', [        'ix',     'ix' ], [ 0xDD, 0x29             ], 15),
        Opcode( 'add', [        'ix',     'sp' ], [ 0xDD, 0x39             ], 15),
        Opcode( 'add', [        'iy',     'bc' ], [ 0xFD, 0x09             ], 15),
        Opcode( 'add', [        'iy',     'de' ], [ 0xFD, 0x19             ], 15),
        Opcode( 'add', [        'iy',     'iy' ], [ 0xFD, 0x29             ], 15),
        Opcode( 'add', [        'iy',     'sp' ], [ 0xFD, 0x39             ], 15),
        Opcode( 'and', [                   'a' ], [ 0xA7                   ],  4),
        Opcode( 'and', [                   'b' ], [ 0xA0                   ],  4),
        Opcode( 'and', [                   'c' ], [ 0xA1                   ],  4),
        Opcode( 'and', [                   'd' ], [ 0xA2                   ],  4),
        Opcode( 'and', [                   'e' ], [ 0xA3                   ],  4),
        Opcode( 'and', [                   'h' ], [ 0xA4                   ],  4),
        Opcode( 'and', [                   'l' ], [ 0xA5                   ],  4),
        Opcode( 'and', [                   '#' ], [ 0xE6, '#'              ],  7),
        Opcode( 'and', [                '(hl)' ], [ 0xA6                   ],  7),
        Opcode( 'and', [              '(ix+#)' ], [ 0xDD, 0xA6, '#'        ], 19),
        Opcode( 'and', [              '(iy+#)' ], [ 0xFD, 0xA6, '#'        ], 19),
        Opcode( 'bit', [        '0',    '(hl)' ], [ 0xCB, 0x46             ], 12),
        Opcode( 'bit', [        '1',    '(hl)' ], [ 0xCB, 0x4E             ], 12),
        Opcode( 'bit', [        '2',    '(hl)' ], [ 0xCB, 0x56             ], 12),
        Opcode( 'bit', [        '3',    '(hl)' ], [ 0xCB, 0x5E             ], 12),
        Opcode( 'bit', [        '4',    '(hl)' ], [ 0xCB, 0x66             ], 12),
        Opcode( 'bit', [        '5',    '(hl)' ], [ 0xCB, 0x6E             ], 12),
        Opcode( 'bit', [        '6',    '(hl)' ], [ 0xCB, 0x76             ], 12),
        Opcode( 'bit', [        '7',    '(hl)' ], [ 0xCB, 0x7E             ], 12),
        Opcode( 'bit', [        '0',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x46  ], 20),
        Opcode( 'bit', [        '1',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x4E  ], 20),
        Opcode( 'bit', [        '2',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x56  ], 20),
        Opcode( 'bit', [        '3',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x5E  ], 20),
        Opcode( 'bit', [        '4',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x66  ], 20),
        Opcode( 'bit', [        '5',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x6E  ], 20),
        Opcode( 'bit', [        '6',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x76  ], 20),
        Opcode( 'bit', [        '7',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x7E  ], 20),
        Opcode( 'bit', [        '0',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x46  ], 20),
        Opcode( 'bit', [        '1',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x4E  ], 20),
        Opcode( 'bit', [        '2',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x56  ], 20),
        Opcode( 'bit', [        '3',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x5E  ], 20),
        Opcode( 'bit', [        '4',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x66  ], 20),
        Opcode( 'bit', [        '5',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x6E  ], 20),
        Opcode( 'bit', [        '6',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x76  ], 20),
        Opcode( 'bit', [        '7',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x7E  ], 20),
        Opcode( 'bit', [        '0',       'a' ], [ 0xCB, 0x47             ],  8),
        Opcode( 'bit', [        '0',       'b' ], [ 0xCB, 0x40             ],  8),
        Opcode( 'bit', [        '0',       'c' ], [ 0xCB, 0x41             ],  8),
        Opcode( 'bit', [        '0',       'd' ], [ 0xCB, 0x42             ],  8),
        Opcode( 'bit', [        '0',       'e' ], [ 0xCB, 0x43             ],  8),
        Opcode( 'bit', [        '0',       'h' ], [ 0xCB, 0x44             ],  8),
        Opcode( 'bit', [        '0',       'l' ], [ 0xCB, 0x45             ],  8),
        Opcode( 'bit', [        '1',       'a' ], [ 0xCB, 0x4F             ],  8),
        Opcode( 'bit', [        '1',       'b' ], [ 0xCB, 0x48             ],  8),
        Opcode( 'bit', [        '1',       'c' ], [ 0xCB, 0x49             ],  8),
        Opcode( 'bit', [        '1',       'd' ], [ 0xCB, 0x4A             ],  8),
        Opcode( 'bit', [        '1',       'e' ], [ 0xCB, 0x4B             ],  8),
        Opcode( 'bit', [        '1',       'h' ], [ 0xCB, 0x4C             ],  8),
        Opcode( 'bit', [        '1',       'l' ], [ 0xCB, 0x4D             ],  8),
        Opcode( 'bit', [        '2',       'a' ], [ 0xCB, 0x57             ],  8),
        Opcode( 'bit', [        '2',       'b' ], [ 0xCB, 0x50             ],  8),
        Opcode( 'bit', [        '2',       'c' ], [ 0xCB, 0x51             ],  8),
        Opcode( 'bit', [        '2',       'd' ], [ 0xCB, 0x52             ],  8),
        Opcode( 'bit', [        '2',       'e' ], [ 0xCB, 0x53             ],  8),
        Opcode( 'bit', [        '2',       'h' ], [ 0xCB, 0x54             ],  8),
        Opcode( 'bit', [        '2',       'l' ], [ 0xCB, 0x55             ],  8),
        Opcode( 'bit', [        '3',       'a' ], [ 0xCB, 0x5F             ],  8),
        Opcode( 'bit', [        '3',       'b' ], [ 0xCB, 0x58             ],  8),
        Opcode( 'bit', [        '3',       'c' ], [ 0xCB, 0x59             ],  8),
        Opcode( 'bit', [        '3',       'd' ], [ 0xCB, 0x5A             ],  8),
        Opcode( 'bit', [        '3',       'e' ], [ 0xCB, 0x5B             ],  8),
        Opcode( 'bit', [        '3',       'h' ], [ 0xCB, 0x5C             ],  8),
        Opcode( 'bit', [        '3',       'l' ], [ 0xCB, 0x5D             ],  8),
        Opcode( 'bit', [        '4',       'a' ], [ 0xCB, 0x67             ],  8),
        Opcode( 'bit', [        '4',       'b' ], [ 0xCB, 0x60             ],  8),
        Opcode( 'bit', [        '4',       'c' ], [ 0xCB, 0x61             ],  8),
        Opcode( 'bit', [        '4',       'd' ], [ 0xCB, 0x62             ],  8),
        Opcode( 'bit', [        '4',       'e' ], [ 0xCB, 0x63             ],  8),
        Opcode( 'bit', [        '4',       'h' ], [ 0xCB, 0x64             ],  8),
        Opcode( 'bit', [        '4',       'l' ], [ 0xCB, 0x65             ],  8),
        Opcode( 'bit', [        '5',       'a' ], [ 0xCB, 0x6F             ],  8),
        Opcode( 'bit', [        '5',       'b' ], [ 0xCB, 0x68             ],  8),
        Opcode( 'bit', [        '5',       'c' ], [ 0xCB, 0x69             ],  8),
        Opcode( 'bit', [        '5',       'd' ], [ 0xCB, 0x6A             ],  8),
        Opcode( 'bit', [        '5',       'e' ], [ 0xCB, 0x6B             ],  8),
        Opcode( 'bit', [        '5',       'h' ], [ 0xCB, 0x6C             ],  8),
        Opcode( 'bit', [        '5',       'l' ], [ 0xCB, 0x6D             ],  8),
        Opcode( 'bit', [        '6',       'a' ], [ 0xCB, 0x77             ],  8),
        Opcode( 'bit', [        '6',       'b' ], [ 0xCB, 0x70             ],  8),
        Opcode( 'bit', [        '6',       'c' ], [ 0xCB, 0x71             ],  8),
        Opcode( 'bit', [        '6',       'd' ], [ 0xCB, 0x72             ],  8),
        Opcode( 'bit', [        '6',       'e' ], [ 0xCB, 0x73             ],  8),
        Opcode( 'bit', [        '6',       'h' ], [ 0xCB, 0x74             ],  8),
        Opcode( 'bit', [        '6',       'l' ], [ 0xCB, 0x75             ],  8),
        Opcode( 'bit', [        '7',       'a' ], [ 0xCB, 0x7F             ],  8),
        Opcode( 'bit', [        '7',       'b' ], [ 0xCB, 0x78             ],  8),
        Opcode( 'bit', [        '7',       'c' ], [ 0xCB, 0x79             ],  8),
        Opcode( 'bit', [        '7',       'd' ], [ 0xCB, 0x7A             ],  8),
        Opcode( 'bit', [        '7',       'e' ], [ 0xCB, 0x7B             ],  8),
        Opcode( 'bit', [        '7',       'h' ], [ 0xCB, 0x7C             ],  8),
        Opcode( 'bit', [        '7',       'l' ], [ 0xCB, 0x7D             ],  8),

        Opcode( 'ccf', [                       ], [ 0x3F                   ],  4),
        Opcode( 'cpd', [                       ], [ 0xED, 0xA9             ], 16),
        Opcode('cpdr', [                       ], [ 0xED, 0xB9             ], [ 21, 16 ]),
        Opcode( 'cpi', [                       ], [ 0xED, 0xA1             ], 16),
        Opcode('cpir', [                       ], [ 0xED, 0xB1             ], [ 21, 16 ]),
        Opcode( 'cpl', [                       ], [ 0x2F                   ],  4),
        Opcode( 'daa', [                       ], [ 0x27                   ],  4),
        Opcode(  'di', [                       ], [ 0xF3                   ],  4),
        Opcode(  'ei', [                       ], [ 0xFB                   ],  4),
        Opcode( 'exx', [                       ], [ 0xD9                   ],  4),
        Opcode('halt', [                       ], [ 0x76                   ],  4),
        Opcode( 'ind', [                       ], [ 0xED, 0xAA             ], 16),
        Opcode('indr', [                       ], [ 0xED, 0xBA             ], [ 21, 16 ]),
        Opcode( 'ini', [                       ], [ 0xED, 0xA2             ], 16),
        Opcode('inir', [                       ], [ 0xED, 0xB2             ], [ 21, 16 ]),
        Opcode( 'ldd', [                       ], [ 0xED, 0xA8             ], 16),
        Opcode('lddr', [                       ], [ 0xED, 0xB8             ], [ 21, 16 ]),
        Opcode( 'ldi', [                       ], [ 0xED, 0xA0             ], 16),
        Opcode('ldir', [                       ], [ 0xED, 0xB0             ], [ 21, 17 ]),
        Opcode('otdr', [                       ], [ 0xED, 0xBB             ], [ 21, 16 ]),
        Opcode('otir', [                       ], [ 0xED, 0xB3             ], [ 21, 16 ]),
        Opcode('outd', [                       ], [ 0xED, 0xAB             ], 16),
        Opcode('outi', [                       ], [ 0xED, 0xA3             ], 16),
        Opcode( 'neg', [                       ], [ 0xED, 0x44             ],  8),
        Opcode( 'nop', [                       ], [ 0x00                   ],  4),
        Opcode( 'ret', [                       ], [ 0xC9                   ], 10),
        Opcode('reti', [                       ], [ 0xED, 0x4D             ], 14),
        Opcode('retn', [                       ], [ 0xED, 0x45             ], 14),
        Opcode( 'rla', [                       ], [ 0x17                   ],  4),
        Opcode('rlca', [                       ], [ 0x07                   ],  4),
        Opcode( 'rld', [                       ], [ 0xED, 0x6F             ], 18),
        Opcode( 'rra', [                       ], [ 0x1F                   ],  4),
        Opcode('rrca', [                       ], [ 0x0F                   ],  4),
        Opcode( 'rrd', [                       ], [ 0xED, 0x67             ], 18),
        Opcode( 'scf', [                       ], [ 0x37                   ],  4),
    ]

hdr  = '// THIS IS A GENERATED FILE. DO NOT EDIT!\n'
hdr += '#ifndef COMPILER_Z80OPCODES_H\n'
hdr += '#define COMPILER_Z80OPCODES_H\n'
hdr += '\n'
hdr += '#include "ProgramOpcode.h"\n'

src  = '// THIS IS A GENERATED FILE. DO NOT EDIT!\n'
src += '#include "Z80Opcodes.h"\n'
src += '#include "ProgramSection.h"\n'
src += '#include "ProgramBinary.h"\n'
src += '#include "AssemblerParser.h"\n'
src += '#include "AssemblerToken.h"\n'
src += '\n'
src += '#ifdef emit\n'
src += '#undef emit\n'
src += '#endif\n'

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
    global src
    for key, value in dict.items():
        src += '%sif (%s) {\n' % (indent, key)
        if not isinstance(value, Opcode):
            src += '%s    nextToken();\n' % indent
            genCode(value, indent + '    ')
        else:
            src += '%s    mSection->emit<%s>(token%s);\n' % (indent, value.className, value.argsCall())
            src += '%s    return true;\n' % indent
        src += '%s}\n' % indent

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

        if op in [ 'a', 'b', 'c', 'd', 'e', 'h', 'l', 'bc', 'de', 'hl', 'sp', 'ix', 'iy', 'af' ]:
            conds.append('lastTokenId() == T_IDENTIFIER && lastTokenText() == "%s"' % op)
        elif op in [ '0', '1', '2', '3', '4', '5', '6', '7' ]:
            conds.append('lastTokenId() == T_NUMBER && lastToken().number == %s' % op)
        elif op in [ '(bc)', '(de)', '(hl)', '(ix)', '(iy)' ]:
            conds.append('lastTokenId() == T_LPAREN')
            conds.append('lastTokenId() == T_IDENTIFIER && lastTokenText() == "%s"' % op[1:3])
            conds.append('lastTokenId() == T_RPAREN')
        elif op in [ '(ix+#)', '(iy+#)' ]:
            conds.append('lastTokenId() == T_LPAREN')
            conds.append('lastTokenId() == T_IDENTIFIER && lastTokenText() == "%s"' % op[1:3])
            conds.append('lastTokenId() == T_PLUS')
            conds.append('expectByteLiteral(&literal%d)' % literalIndex)
            conds.append('lastTokenId() == T_RPAREN')
            literalIndex += 1
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

src += '\n'
src += 'bool AssemblerParser::parseOpcode_generated(const std::string& opcode)\n'
src += '{\n'
src += '    unsigned literal1, literal2;\n'
src += '    Token token = lastToken();\n'
genCode(opcodeMap, '    ')
src += '    return false;\n'
src += '}\n'

hdr += '\n'
hdr += '#endif\n'

with open("Z80Opcodes.h", "w") as f:
    f.write(hdr)
with open("Z80Opcodes.cpp", "w") as f:
    f.write(src)
