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
            if op in [ '(bc)', '(de)', '(hl)', '(ix)', '(iy)', '(sp)' ]:
                self.className += '_m%s' % op[1:3].upper()
            elif op in [ '(ix+#)', '(iy+#)' ]:
                literalCount += 1
                self.lengthInBytes += 1
                self.className += '_m%sn' % op[1:3].upper()
            elif op == "(c)":
                self.className += '_mC'
            elif op == "af'":
                self.className += '_AFs'
            elif op == '#':
                literalCount += 1
                self.lengthInBytes += 1
                self.className += '_n'
            elif op == '##':
                literalCount += 1
                self.lengthInBytes += 2
                self.className += '_nn'
            elif op == '(#)':
                literalCount += 1
                self.lengthInBytes += 1
                self.className += '_mn'
            elif op == '(##)':
                literalCount += 1
                self.lengthInBytes += 2
                self.className += '_mnn'
            elif op == 'R#':
                literalCount += 1
                self.lengthInBytes += 1
                self.className += '_off'
            else:
                self.className += '_%s' % op.upper()
        self.numLiterals = literalCount

    def argsDecl(self):
        args = ''
        for idx in range(0, self.numLiterals):
            args += ', std::unique_ptr<Expression> literal%d' % (idx + 1)
        return args

    def argsCall(self):
        args = ''
        for idx in range(0, self.numLiterals):
            args += ', std::move(literal%d)' % (idx + 1)
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
                        code += '    bin->emitWord(mLiteral%d->evaluateWord(reporter));\n' % literalIndex
                        found = True
                        break
                    elif '#' in self.operands[i]:
                        i += 1
                        literalIndex += 1
                        code += '    bin->emitByte(mLiteral%d->evaluateByte(reporter));\n' % literalIndex
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
        Opcode('call', [                  '##' ], [ 0xCD, '#'              ], 17),
        Opcode('call', [        'c',      '##' ], [ 0xDC, '#'              ], [ 17, 10 ]),
        Opcode('call', [        'm',      '##' ], [ 0xFC, '#'              ], [ 17, 10 ]),
        Opcode('call', [       'nc',      '##' ], [ 0xD4, '#'              ], [ 17, 10 ]),
        Opcode('call', [       'nz',      '##' ], [ 0xC4, '#'              ], [ 17, 10 ]),
        Opcode('call', [        'p',      '##' ], [ 0xF4, '#'              ], [ 17, 10 ]),
        Opcode('call', [       'pe',      '##' ], [ 0xEC, '#'              ], [ 17, 10 ]),
        Opcode('call', [       'po',      '##' ], [ 0xE4, '#'              ], [ 17, 10 ]),
        Opcode('call', [        'z',      '##' ], [ 0xCC, '#'              ], [ 17, 10 ]),
        Opcode( 'ccf', [                       ], [ 0x3F                   ],  4),
        Opcode(  'cp', [                   'a' ], [ 0xBF                   ],  4),
        Opcode(  'cp', [                   'b' ], [ 0xB8                   ],  4),
        Opcode(  'cp', [                   'c' ], [ 0xB9                   ],  4),
        Opcode(  'cp', [                   'd' ], [ 0xBA                   ],  4),
        Opcode(  'cp', [                   'e' ], [ 0xBB                   ],  4),
        Opcode(  'cp', [                   'h' ], [ 0xBC                   ],  4),
        Opcode(  'cp', [                   'l' ], [ 0xBD                   ],  4),
        Opcode(  'cp', [                   '#' ], [ 0xFE, '#'              ],  7),
        Opcode(  'cp', [                '(hl)' ], [ 0xBE                   ],  7),
        Opcode(  'cp', [              '(ix+#)' ], [ 0xDD, 0xBE, '#'        ], 19),
        Opcode(  'cp', [              '(iy+#)' ], [ 0xFD, 0xBE, '#'        ], 19),
        Opcode( 'cpd', [                       ], [ 0xED, 0xA9             ], 16),
        Opcode('cpdr', [                       ], [ 0xED, 0xB9             ], [ 21, 16 ]),
        Opcode( 'cpi', [                       ], [ 0xED, 0xA1             ], 16),
        Opcode('cpir', [                       ], [ 0xED, 0xB1             ], [ 21, 16 ]),
        Opcode( 'cpl', [                       ], [ 0x2F                   ],  4),
        Opcode( 'daa', [                       ], [ 0x27                   ],  4),
        Opcode( 'dec', [                   'a' ], [ 0x3D                   ],  4),
        Opcode( 'dec', [                   'b' ], [ 0x05                   ],  4),
        Opcode( 'dec', [                   'c' ], [ 0x0D                   ],  4),
        Opcode( 'dec', [                   'd' ], [ 0x15                   ],  4),
        Opcode( 'dec', [                   'e' ], [ 0x1D                   ],  4),
        Opcode( 'dec', [                   'h' ], [ 0x25                   ],  4),
        Opcode( 'dec', [                   'l' ], [ 0x2D                   ],  4),
        Opcode( 'dec', [                '(hl)' ], [ 0x35                   ], 11),
        Opcode( 'dec', [              '(ix+#)' ], [ 0xDD, 0x35, '#'        ], 23),
        Opcode( 'dec', [              '(iy+#)' ], [ 0xFD, 0x35, '#'        ], 23),
        Opcode( 'dec', [                  'ix' ], [ 0xDD, 0x2B             ], 10),
        Opcode( 'dec', [                  'iy' ], [ 0xFD, 0x2B             ], 10),
        Opcode( 'dec', [                  'bc' ], [ 0x0B                   ],  6),
        Opcode( 'dec', [                  'de' ], [ 0x1B                   ],  6),
        Opcode( 'dec', [                  'hl' ], [ 0x2B                   ],  6),
        Opcode( 'dec', [                  'sp' ], [ 0x3B                   ],  6),
        Opcode(  'di', [                       ], [ 0xF3                   ],  4),
        Opcode('djnz', [                   '#' ], [ 0x10, '#'              ], [ 8, 13 ]),
        Opcode(  'ei', [                       ], [ 0xFB                   ],  4),
        Opcode(  'ex', [     '(sp)',      'hl' ], [ 0xE3                   ], 19),
        Opcode(  'ex', [     '(sp)',      'ix' ], [ 0xDD, 0xE3             ], 23),
        Opcode(  'ex', [     '(sp)',      'iy' ], [ 0xFD, 0xE3             ], 23),
        Opcode(  'ex', [       'af',     "af'" ], [ 0x08                   ],  4),
        Opcode(  'ex', [       'de',      'hl' ], [ 0xEB                   ],  4),
        Opcode( 'exx', [                       ], [ 0xD9                   ],  4),
        Opcode('halt', [                       ], [ 0x76                   ],  4),
        Opcode(  'im', [                   '0' ], [ 0xED, 0x46             ],  8),
        Opcode(  'im', [                   '1' ], [ 0xED, 0x56             ],  8),
        Opcode(  'im', [                   '2' ], [ 0xED, 0x5E             ],  8),
        Opcode(  'in', [        'a',     '(#)' ], [ 0xDB, '#'              ], 11),
        Opcode(  'in', [        'a',     '(c)' ], [ 0xED, 0x78             ], 12),
        Opcode(  'in', [        'b',     '(c)' ], [ 0xED, 0x40             ], 12),
        Opcode(  'in', [        'c',     '(c)' ], [ 0xED, 0x48             ], 12),
        Opcode(  'in', [        'd',     '(c)' ], [ 0xED, 0x50             ], 12),
        Opcode(  'in', [        'e',     '(c)' ], [ 0xED, 0x58             ], 12),
        Opcode(  'in', [        'h',     '(c)' ], [ 0xED, 0x60             ], 12),
        Opcode(  'in', [        'l',     '(c)' ], [ 0xED, 0x68             ], 12),
        Opcode( 'inc', [                   'a' ], [ 0x3C                   ],  4),
        Opcode( 'inc', [                   'b' ], [ 0x04                   ],  4),
        Opcode( 'inc', [                   'c' ], [ 0x0C                   ],  4),
        Opcode( 'inc', [                   'd' ], [ 0x14                   ],  4),
        Opcode( 'inc', [                   'e' ], [ 0x1C                   ],  4),
        Opcode( 'inc', [                   'h' ], [ 0x24                   ],  4),
        Opcode( 'inc', [                   'l' ], [ 0x2C                   ],  4),
        Opcode( 'inc', [                '(hl)' ], [ 0x34                   ], 11),
        Opcode( 'inc', [              '(ix+#)' ], [ 0xDD, 0x34, '#'        ], 23),
        Opcode( 'inc', [              '(iy+#)' ], [ 0xFD, 0x34, '#'        ], 23),
        Opcode( 'inc', [                  'ix' ], [ 0xDD, 0x23             ], 10),
        Opcode( 'inc', [                  'iy' ], [ 0xFD, 0x23             ], 10),
        Opcode( 'inc', [                  'bc' ], [ 0x03                   ],  6),
        Opcode( 'inc', [                  'de' ], [ 0x13                   ],  6),
        Opcode( 'inc', [                  'hl' ], [ 0x23                   ],  6),
        Opcode( 'inc', [                  'sp' ], [ 0x33                   ],  6),
        Opcode( 'ind', [                       ], [ 0xED, 0xAA             ], 16),
        Opcode('indr', [                       ], [ 0xED, 0xBA             ], [ 21, 16 ]),
        Opcode( 'ini', [                       ], [ 0xED, 0xA2             ], 16),
        Opcode('inir', [                       ], [ 0xED, 0xB2             ], [ 21, 16 ]),
        Opcode(  'jp', [                  '##' ], [ 0xC3, '#'              ], 10),
        Opcode(  'jp', [        'c',      '##' ], [ 0xDA, '#'              ], 10),
        Opcode(  'jp', [        'm',      '##' ], [ 0xFA, '#'              ], 10),
        Opcode(  'jp', [       'nc',      '##' ], [ 0xD2, '#'              ], 10),
        Opcode(  'jp', [       'nz',      '##' ], [ 0xC2, '#'              ], 10),
        Opcode(  'jp', [        'p',      '##' ], [ 0xF2, '#'              ], 10),
        Opcode(  'jp', [       'pe',      '##' ], [ 0xEA, '#'              ], 10),
        Opcode(  'jp', [       'po',      '##' ], [ 0xE2, '#'              ], 10),
        Opcode(  'jp', [        'z',      '##' ], [ 0xCA, '#'              ], 10),
        Opcode(  'jp', [                '(hl)' ], [ 0xE9,                  ],  4),
        Opcode(  'jp', [                '(ix)' ], [ 0xDD, 0xE9             ],  8),
        Opcode(  'jp', [                '(iy)' ], [ 0xFD, 0xE9             ],  8),
        Opcode(  'jr', [                  'R#' ], [ 0x18, '#'              ], 12),
        Opcode(  'jr', [         'c',     'R#' ], [ 0x38, '#'              ], [ 12, 7 ]),
        Opcode(  'jr', [        'nc',     'R#' ], [ 0x30, '#'              ], [ 12, 7 ]),
        Opcode(  'jr', [        'nz',     'R#' ], [ 0x20, '#'              ], [ 12, 7 ]),
        Opcode(  'jr', [         'z',     'R#' ], [ 0x28, '#'              ], [ 12, 7 ]),
        Opcode(  'ld', [         'a',   '(bc)' ], [ 0x0A                   ],  7),
        Opcode(  'ld', [         'a',   '(de)' ], [ 0x1A                   ],  7),
        Opcode(  'ld', [         'a',      'i' ], [ 0xED, 0x57             ],  9),
        Opcode(  'ld', [         'a',   '(##)' ], [ 0x3A, '#'              ], 13),
        Opcode(  'ld', [         'a',      'r' ], [ 0xED, 0x5F             ],  9),
        Opcode(  'ld', [      '(bc)',      'a' ], [ 0x02                   ],  7),
        Opcode(  'ld', [      '(de)',      'a' ], [ 0x12                   ],  7),
        Opcode(  'ld', [      '(hl)',      '#' ], [ 0x36, '#'              ], 10),
        Opcode(  'ld', [    '(ix+#)',      '#' ], [ 0xDD, 0x36, '#', '#'   ], 19),
        Opcode(  'ld', [    '(iy+#)',      '#' ], [ 0xFD, 0x36, '#', '#'   ], 19),
        Opcode(  'ld', [      '(##)',      'a' ], [ 0x32, '#'              ], 13),
        Opcode(  'ld', [      '(##)',     'bc' ], [ 0xED, 0x43, '#'        ], 20),
        Opcode(  'ld', [      '(##)',     'de' ], [ 0xED, 0x53, '#'        ], 20),
        Opcode(  'ld', [      '(##)',     'hl' ], [ 0x22, '#'              ], 16),
        Opcode(  'ld', [      '(##)',     'sp' ], [ 0xED, 0x73, '#'        ], 20),
        Opcode(  'ld', [      '(##)',     'ix' ], [ 0xDD, 0x22, '#'        ], 20),
        Opcode(  'ld', [      '(##)',     'iy' ], [ 0xFD, 0x22, '#'        ], 20),
        Opcode(  'ld', [        'bc',     '##' ], [ 0x01, '#'              ], 10),
        Opcode(  'ld', [        'de',     '##' ], [ 0x11, '#'              ], 10),
        Opcode(  'ld', [        'hl',     '##' ], [ 0x21, '#'              ], 10),
        Opcode(  'ld', [        'sp',     '##' ], [ 0x31, '#'              ], 10),
        Opcode(  'ld', [        'bc',   '(##)' ], [ 0xED, 0x4B, '#'        ], 20),
        Opcode(  'ld', [        'de',   '(##)' ], [ 0xED, 0x5B, '#'        ], 20),
        Opcode(  'ld', [        'hl',   '(##)' ], [ 0x2A, '#'              ], 16),
        Opcode(  'ld', [        'sp',   '(##)' ], [ 0xED, 0x7B, '#'        ], 20),
        Opcode(  'ld', [      '(hl)',      'a' ], [ 0x77                   ],  7),
        Opcode(  'ld', [      '(hl)',      'b' ], [ 0x70                   ],  7),
        Opcode(  'ld', [      '(hl)',      'c' ], [ 0x71                   ],  7),
        Opcode(  'ld', [      '(hl)',      'd' ], [ 0x72                   ],  7),
        Opcode(  'ld', [      '(hl)',      'e' ], [ 0x73                   ],  7),
        Opcode(  'ld', [      '(hl)',      'h' ], [ 0x74                   ],  7),
        Opcode(  'ld', [      '(hl)',      'l' ], [ 0x75                   ],  7),
        Opcode(  'ld', [    '(ix+#)',      'a' ], [ 0xDD, 0x77, '#'        ], 19),
        Opcode(  'ld', [    '(ix+#)',      'b' ], [ 0xDD, 0x70, '#'        ], 19),
        Opcode(  'ld', [    '(ix+#)',      'c' ], [ 0xDD, 0x71, '#'        ], 19),
        Opcode(  'ld', [    '(ix+#)',      'd' ], [ 0xDD, 0x72, '#'        ], 19),
        Opcode(  'ld', [    '(ix+#)',      'e' ], [ 0xDD, 0x73, '#'        ], 19),
        Opcode(  'ld', [    '(ix+#)',      'h' ], [ 0xDD, 0x74, '#'        ], 19),
        Opcode(  'ld', [    '(ix+#)',      'l' ], [ 0xDD, 0x75, '#'        ], 19),
        Opcode(  'ld', [    '(iy+#)',      'a' ], [ 0xFD, 0x77, '#'        ], 19),
        Opcode(  'ld', [    '(iy+#)',      'b' ], [ 0xFD, 0x70, '#'        ], 19),
        Opcode(  'ld', [    '(iy+#)',      'c' ], [ 0xFD, 0x71, '#'        ], 19),
        Opcode(  'ld', [    '(iy+#)',      'd' ], [ 0xFD, 0x72, '#'        ], 19),
        Opcode(  'ld', [    '(iy+#)',      'e' ], [ 0xFD, 0x73, '#'        ], 19),
        Opcode(  'ld', [    '(iy+#)',      'h' ], [ 0xFD, 0x74, '#'        ], 19),
        Opcode(  'ld', [    '(iy+#)',      'l' ], [ 0xFD, 0x75, '#'        ], 19),
        Opcode(  'ld', [         'i',      'a' ], [ 0xED, 0x47             ],  9),
        Opcode(  'ld', [        'ix',     '##' ], [ 0xDD, 0x21, '#'        ], 14),
        Opcode(  'ld', [        'ix',   '(##)' ], [ 0xDD, 0x2A, '#'        ], 20),
        Opcode(  'ld', [        'iy',     '##' ], [ 0xFD, 0x21, '#'        ], 14),
        Opcode(  'ld', [        'iy',   '(##)' ], [ 0xFD, 0x2A, '#'        ], 20),
        Opcode(  'ld', [         'r',      'a' ], [ 0xED, 0x4F             ],  9),
        Opcode(  'ld', [         'a',   '(hl)' ], [ 0x7E                   ],  7),
        Opcode(  'ld', [         'b',   '(hl)' ], [ 0x46                   ],  7),
        Opcode(  'ld', [         'c',   '(hl)' ], [ 0x4E                   ],  7),
        Opcode(  'ld', [         'd',   '(hl)' ], [ 0x56                   ],  7),
        Opcode(  'ld', [         'e',   '(hl)' ], [ 0x5E                   ],  7),
        Opcode(  'ld', [         'h',   '(hl)' ], [ 0x66                   ],  7),
        Opcode(  'ld', [         'l',   '(hl)' ], [ 0x6E                   ],  7),
        Opcode(  'ld', [         'a', '(ix+#)' ], [ 0xDD, 0x7E, '#'        ], 19),
        Opcode(  'ld', [         'b', '(ix+#)' ], [ 0xDD, 0x46, '#'        ], 19),
        Opcode(  'ld', [         'c', '(ix+#)' ], [ 0xDD, 0x4E, '#'        ], 19),
        Opcode(  'ld', [         'd', '(ix+#)' ], [ 0xDD, 0x56, '#'        ], 19),
        Opcode(  'ld', [         'e', '(ix+#)' ], [ 0xDD, 0x5E, '#'        ], 19),
        Opcode(  'ld', [         'h', '(ix+#)' ], [ 0xDD, 0x66, '#'        ], 19),
        Opcode(  'ld', [         'l', '(ix+#)' ], [ 0xDD, 0x6E, '#'        ], 19),
        Opcode(  'ld', [         'a', '(iy+#)' ], [ 0xFD, 0x7E, '#'        ], 19),
        Opcode(  'ld', [         'b', '(iy+#)' ], [ 0xFD, 0x46, '#'        ], 19),
        Opcode(  'ld', [         'c', '(iy+#)' ], [ 0xFD, 0x4E, '#'        ], 19),
        Opcode(  'ld', [         'd', '(iy+#)' ], [ 0xFD, 0x56, '#'        ], 19),
        Opcode(  'ld', [         'e', '(iy+#)' ], [ 0xFD, 0x5E, '#'        ], 19),
        Opcode(  'ld', [         'h', '(iy+#)' ], [ 0xFD, 0x66, '#'        ], 19),
        Opcode(  'ld', [         'l', '(iy+#)' ], [ 0xFD, 0x6E, '#'        ], 19),
        Opcode(  'ld', [         'a',      '#' ], [ 0x3E, '#'              ],  7),
        Opcode(  'ld', [         'b',      '#' ], [ 0x06, '#'              ],  7),
        Opcode(  'ld', [         'c',      '#' ], [ 0x0E, '#'              ],  7),
        Opcode(  'ld', [         'd',      '#' ], [ 0x16, '#'              ],  7),
        Opcode(  'ld', [         'e',      '#' ], [ 0x1E, '#'              ],  7),
        Opcode(  'ld', [         'h',      '#' ], [ 0x26, '#'              ],  7),
        Opcode(  'ld', [         'l',      '#' ], [ 0x2E, '#'              ],  7),
        Opcode(  'ld', [         'a',      'a' ], [ 0x7F                   ],  4),
        Opcode(  'ld', [         'b',      'a' ], [ 0x47                   ],  4),
        Opcode(  'ld', [         'c',      'a' ], [ 0x4F                   ],  4),
        Opcode(  'ld', [         'd',      'a' ], [ 0x57                   ],  4),
        Opcode(  'ld', [         'e',      'a' ], [ 0x5F                   ],  4),
        Opcode(  'ld', [         'h',      'a' ], [ 0x67                   ],  4),
        Opcode(  'ld', [         'l',      'a' ], [ 0x6F                   ],  4),
        Opcode(  'ld', [         'a',      'b' ], [ 0x78                   ],  4),
        Opcode(  'ld', [         'b',      'b' ], [ 0x40                   ],  4),
        Opcode(  'ld', [         'c',      'b' ], [ 0x48                   ],  4),
        Opcode(  'ld', [         'd',      'b' ], [ 0x50                   ],  4),
        Opcode(  'ld', [         'e',      'b' ], [ 0x58                   ],  4),
        Opcode(  'ld', [         'h',      'b' ], [ 0x60                   ],  4),
        Opcode(  'ld', [         'l',      'b' ], [ 0x68                   ],  4),
        Opcode(  'ld', [         'a',      'c' ], [ 0x79                   ],  4),
        Opcode(  'ld', [         'b',      'c' ], [ 0x41                   ],  4),
        Opcode(  'ld', [         'c',      'c' ], [ 0x49                   ],  4),
        Opcode(  'ld', [         'd',      'c' ], [ 0x51                   ],  4),
        Opcode(  'ld', [         'e',      'c' ], [ 0x59                   ],  4),
        Opcode(  'ld', [         'h',      'c' ], [ 0x61                   ],  4),
        Opcode(  'ld', [         'l',      'c' ], [ 0x69                   ],  4),
        Opcode(  'ld', [         'a',      'd' ], [ 0x7A                   ],  4),
        Opcode(  'ld', [         'b',      'd' ], [ 0x42                   ],  4),
        Opcode(  'ld', [         'c',      'd' ], [ 0x4A                   ],  4),
        Opcode(  'ld', [         'd',      'd' ], [ 0x52                   ],  4),
        Opcode(  'ld', [         'e',      'd' ], [ 0x5A                   ],  4),
        Opcode(  'ld', [         'h',      'd' ], [ 0x62                   ],  4),
        Opcode(  'ld', [         'l',      'd' ], [ 0x6A                   ],  4),
        Opcode(  'ld', [         'a',      'e' ], [ 0x7B                   ],  4),
        Opcode(  'ld', [         'b',      'e' ], [ 0x43                   ],  4),
        Opcode(  'ld', [         'c',      'e' ], [ 0x4B                   ],  4),
        Opcode(  'ld', [         'd',      'e' ], [ 0x53                   ],  4),
        Opcode(  'ld', [         'e',      'e' ], [ 0x5B                   ],  4),
        Opcode(  'ld', [         'h',      'e' ], [ 0x63                   ],  4),
        Opcode(  'ld', [         'l',      'e' ], [ 0x6B                   ],  4),
        Opcode(  'ld', [         'a',      'h' ], [ 0x7C                   ],  4),
        Opcode(  'ld', [         'b',      'h' ], [ 0x44                   ],  4),
        Opcode(  'ld', [         'c',      'h' ], [ 0x4C                   ],  4),
        Opcode(  'ld', [         'd',      'h' ], [ 0x54                   ],  4),
        Opcode(  'ld', [         'e',      'h' ], [ 0x5C                   ],  4),
        Opcode(  'ld', [         'h',      'h' ], [ 0x64                   ],  4),
        Opcode(  'ld', [         'l',      'h' ], [ 0x6C                   ],  4),
        Opcode(  'ld', [         'a',      'l' ], [ 0x7D                   ],  4),
        Opcode(  'ld', [         'b',      'l' ], [ 0x45                   ],  4),
        Opcode(  'ld', [         'c',      'l' ], [ 0x4D                   ],  4),
        Opcode(  'ld', [         'd',      'l' ], [ 0x55                   ],  4),
        Opcode(  'ld', [         'e',      'l' ], [ 0x5D                   ],  4),
        Opcode(  'ld', [         'h',      'l' ], [ 0x65                   ],  4),
        Opcode(  'ld', [         'l',      'l' ], [ 0x6D                   ],  4),
        Opcode(  'ld', [        'sp',     'hl' ], [ 0xF9                   ],  6),
        Opcode(  'ld', [        'sp',     'ix' ], [ 0xDD, 0xF9             ], 10),
        Opcode(  'ld', [        'sp',     'iy' ], [ 0xFD, 0xF9             ], 10),
        Opcode( 'ldd', [                       ], [ 0xED, 0xA8             ], 16),
        Opcode('lddr', [                       ], [ 0xED, 0xB8             ], [ 21, 16 ]),
        Opcode( 'ldi', [                       ], [ 0xED, 0xA0             ], 16),
        Opcode('ldir', [                       ], [ 0xED, 0xB0             ], [ 21, 17 ]),
        Opcode( 'neg', [                       ], [ 0xED, 0x44             ],  8),
        Opcode( 'nop', [                       ], [ 0x00                   ],  4),
        Opcode(  'or', [                   'a' ], [ 0xB7                   ],  4),
        Opcode(  'or', [                   'b' ], [ 0xB0                   ],  4),
        Opcode(  'or', [                   'c' ], [ 0xB1                   ],  4),
        Opcode(  'or', [                   'd' ], [ 0xB2                   ],  4),
        Opcode(  'or', [                   'e' ], [ 0xB3                   ],  4),
        Opcode(  'or', [                   'h' ], [ 0xB4                   ],  4),
        Opcode(  'or', [                   'l' ], [ 0xB5                   ],  4),
        Opcode(  'or', [                   '#' ], [ 0xF6, '#'              ],  7),
        Opcode(  'or', [                '(hl)' ], [ 0xB6                   ],  7),
        Opcode(  'or', [              '(ix+#)' ], [ 0xDD, 0xB6, '#'        ], 19),
        Opcode(  'or', [              '(iy+#)' ], [ 0xFD, 0xB6, '#'        ], 19),
        Opcode('otdr', [                       ], [ 0xED, 0xBB             ], [ 21, 16 ]),
        Opcode('otir', [                       ], [ 0xED, 0xB3             ], [ 21, 16 ]),
        Opcode( 'out', [      '(#)',       'a' ], [ 0xD3, '#'              ], 11),
        Opcode( 'out', [      '(c)',       'a' ], [ 0xED, 0x79             ], 12),
        Opcode( 'out', [      '(c)',       'b' ], [ 0xED, 0x41             ], 12),
        Opcode( 'out', [      '(c)',       'c' ], [ 0xED, 0x49             ], 12),
        Opcode( 'out', [      '(c)',       'd' ], [ 0xED, 0x51             ], 12),
        Opcode( 'out', [      '(c)',       'e' ], [ 0xED, 0x59             ], 12),
        Opcode( 'out', [      '(c)',       'h' ], [ 0xED, 0x61             ], 12),
        Opcode( 'out', [      '(c)',       'l' ], [ 0xED, 0x69             ], 12),
        Opcode('outd', [                       ], [ 0xED, 0xAB             ], 16),
        Opcode('outi', [                       ], [ 0xED, 0xA3             ], 16),
        Opcode( 'pop', [                  'ix' ], [ 0xDD, 0xE1             ], 14),
        Opcode( 'pop', [                  'iy' ], [ 0xFD, 0xE1             ], 14),
        Opcode( 'pop', [                  'bc' ], [ 0xC1                   ], 10),
        Opcode( 'pop', [                  'de' ], [ 0xD1                   ], 10),
        Opcode( 'pop', [                  'hl' ], [ 0xE1                   ], 10),
        Opcode( 'pop', [                  'af' ], [ 0xF1                   ], 10),
        Opcode('push', [                  'ix' ], [ 0xDD, 0xE5             ], 15),
        Opcode('push', [                  'iy' ], [ 0xFD, 0xE5             ], 15),
        Opcode('push', [                  'bc' ], [ 0xC5                   ], 11),
        Opcode('push', [                  'de' ], [ 0xD5                   ], 11),
        Opcode('push', [                  'hl' ], [ 0xE5                   ], 11),
        Opcode('push', [                  'af' ], [ 0xF5                   ], 11),
        Opcode( 'res', [        '0',       'a' ], [ 0xCB, 0x87             ],  8),
        Opcode( 'res', [        '0',       'b' ], [ 0xCB, 0x80             ],  8),
        Opcode( 'res', [        '0',       'c' ], [ 0xCB, 0x81             ],  8),
        Opcode( 'res', [        '0',       'd' ], [ 0xCB, 0x82             ],  8),
        Opcode( 'res', [        '0',       'e' ], [ 0xCB, 0x83             ],  8),
        Opcode( 'res', [        '0',       'h' ], [ 0xCB, 0x84             ],  8),
        Opcode( 'res', [        '0',       'l' ], [ 0xCB, 0x85             ],  8),
        Opcode( 'res', [        '1',       'a' ], [ 0xCB, 0x8F             ],  8),
        Opcode( 'res', [        '1',       'b' ], [ 0xCB, 0x88             ],  8),
        Opcode( 'res', [        '1',       'c' ], [ 0xCB, 0x89             ],  8),
        Opcode( 'res', [        '1',       'd' ], [ 0xCB, 0x8A             ],  8),
        Opcode( 'res', [        '1',       'e' ], [ 0xCB, 0x8B             ],  8),
        Opcode( 'res', [        '1',       'h' ], [ 0xCB, 0x8C             ],  8),
        Opcode( 'res', [        '1',       'l' ], [ 0xCB, 0x8D             ],  8),
        Opcode( 'res', [        '2',       'a' ], [ 0xCB, 0x97             ],  8),
        Opcode( 'res', [        '2',       'b' ], [ 0xCB, 0x90             ],  8),
        Opcode( 'res', [        '2',       'c' ], [ 0xCB, 0x91             ],  8),
        Opcode( 'res', [        '2',       'd' ], [ 0xCB, 0x92             ],  8),
        Opcode( 'res', [        '2',       'e' ], [ 0xCB, 0x93             ],  8),
        Opcode( 'res', [        '2',       'h' ], [ 0xCB, 0x94             ],  8),
        Opcode( 'res', [        '2',       'l' ], [ 0xCB, 0x95             ],  8),
        Opcode( 'res', [        '3',       'a' ], [ 0xCB, 0x9F             ],  8),
        Opcode( 'res', [        '3',       'b' ], [ 0xCB, 0x98             ],  8),
        Opcode( 'res', [        '3',       'c' ], [ 0xCB, 0x99             ],  8),
        Opcode( 'res', [        '3',       'd' ], [ 0xCB, 0x9A             ],  8),
        Opcode( 'res', [        '3',       'e' ], [ 0xCB, 0x9B             ],  8),
        Opcode( 'res', [        '3',       'h' ], [ 0xCB, 0x9C             ],  8),
        Opcode( 'res', [        '3',       'l' ], [ 0xCB, 0x9D             ],  8),
        Opcode( 'res', [        '4',       'a' ], [ 0xCB, 0xA7             ],  8),
        Opcode( 'res', [        '4',       'b' ], [ 0xCB, 0xA0             ],  8),
        Opcode( 'res', [        '4',       'c' ], [ 0xCB, 0xA1             ],  8),
        Opcode( 'res', [        '4',       'd' ], [ 0xCB, 0xA2             ],  8),
        Opcode( 'res', [        '4',       'e' ], [ 0xCB, 0xA3             ],  8),
        Opcode( 'res', [        '4',       'h' ], [ 0xCB, 0xA4             ],  8),
        Opcode( 'res', [        '4',       'l' ], [ 0xCB, 0xA5             ],  8),
        Opcode( 'res', [        '5',       'a' ], [ 0xCB, 0xAF             ],  8),
        Opcode( 'res', [        '5',       'b' ], [ 0xCB, 0xA8             ],  8),
        Opcode( 'res', [        '5',       'c' ], [ 0xCB, 0xA9             ],  8),
        Opcode( 'res', [        '5',       'd' ], [ 0xCB, 0xAA             ],  8),
        Opcode( 'res', [        '5',       'e' ], [ 0xCB, 0xAB             ],  8),
        Opcode( 'res', [        '5',       'h' ], [ 0xCB, 0xAC             ],  8),
        Opcode( 'res', [        '5',       'l' ], [ 0xCB, 0xAD             ],  8),
        Opcode( 'res', [        '6',       'a' ], [ 0xCB, 0xB7             ],  8),
        Opcode( 'res', [        '6',       'b' ], [ 0xCB, 0xB0             ],  8),
        Opcode( 'res', [        '6',       'c' ], [ 0xCB, 0xB1             ],  8),
        Opcode( 'res', [        '6',       'd' ], [ 0xCB, 0xB2             ],  8),
        Opcode( 'res', [        '6',       'e' ], [ 0xCB, 0xB3             ],  8),
        Opcode( 'res', [        '6',       'h' ], [ 0xCB, 0xB4             ],  8),
        Opcode( 'res', [        '6',       'l' ], [ 0xCB, 0xB5             ],  8),
        Opcode( 'res', [        '7',       'a' ], [ 0xCB, 0xBF             ],  8),
        Opcode( 'res', [        '7',       'b' ], [ 0xCB, 0xB8             ],  8),
        Opcode( 'res', [        '7',       'c' ], [ 0xCB, 0xB9             ],  8),
        Opcode( 'res', [        '7',       'd' ], [ 0xCB, 0xBA             ],  8),
        Opcode( 'res', [        '7',       'e' ], [ 0xCB, 0xBB             ],  8),
        Opcode( 'res', [        '7',       'h' ], [ 0xCB, 0xBC             ],  8),
        Opcode( 'res', [        '7',       'l' ], [ 0xCB, 0xBD             ],  8),
        Opcode( 'res', [        '0',    '(hl)' ], [ 0xCB, 0x86             ], 15),
        Opcode( 'res', [        '1',    '(hl)' ], [ 0xCB, 0x8E             ], 15),
        Opcode( 'res', [        '2',    '(hl)' ], [ 0xCB, 0x96             ], 15),
        Opcode( 'res', [        '3',    '(hl)' ], [ 0xCB, 0x9E             ], 15),
        Opcode( 'res', [        '4',    '(hl)' ], [ 0xCB, 0xA6             ], 15),
        Opcode( 'res', [        '5',    '(hl)' ], [ 0xCB, 0xAE             ], 15),
        Opcode( 'res', [        '6',    '(hl)' ], [ 0xCB, 0xB6             ], 15),
        Opcode( 'res', [        '7',    '(hl)' ], [ 0xCB, 0xBE             ], 15),
        Opcode( 'res', [        '0',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x86  ], 23),
        Opcode( 'res', [        '1',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x8E  ], 23),
        Opcode( 'res', [        '2',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x96  ], 23),
        Opcode( 'res', [        '3',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x9E  ], 23),
        Opcode( 'res', [        '4',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xA6  ], 23),
        Opcode( 'res', [        '5',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xAE  ], 23),
        Opcode( 'res', [        '6',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xB6  ], 23),
        Opcode( 'res', [        '7',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xBE  ], 23),
        Opcode( 'res', [        '0',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x86  ], 23),
        Opcode( 'res', [        '1',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x8E  ], 23),
        Opcode( 'res', [        '2',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x96  ], 23),
        Opcode( 'res', [        '3',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x9E  ], 23),
        Opcode( 'res', [        '4',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xA6  ], 23),
        Opcode( 'res', [        '5',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xAE  ], 23),
        Opcode( 'res', [        '6',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xB6  ], 23),
        Opcode( 'res', [        '7',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xBE  ], 23),
        Opcode( 'ret', [                       ], [ 0xC9                   ], 10),
        Opcode( 'ret', [                   'c' ], [ 0xD8                   ], [ 11, 5 ]),
        Opcode( 'ret', [                   'm' ], [ 0xF8                   ], [ 11, 5 ]),
        Opcode( 'ret', [                  'nc' ], [ 0xD0                   ], [ 11, 5 ]),
        Opcode( 'ret', [                  'nz' ], [ 0xC0                   ], [ 11, 5 ]),
        Opcode( 'ret', [                   'p' ], [ 0xF0                   ], [ 11, 5 ]),
        Opcode( 'ret', [                  'pe' ], [ 0xE8                   ], [ 11, 5 ]),
        Opcode( 'ret', [                  'po' ], [ 0xE0                   ], [ 11, 5 ]),
        Opcode( 'ret', [                   'z' ], [ 0xC8                   ], [ 11, 5 ]),
        Opcode('reti', [                       ], [ 0xED, 0x4D             ], 14),
        Opcode('retn', [                       ], [ 0xED, 0x45             ], 14),
        Opcode(  'rl', [                   'a' ], [ 0xCB, 0x17             ],  8),
        Opcode(  'rl', [                   'b' ], [ 0xCB, 0x10             ],  8),
        Opcode(  'rl', [                   'c' ], [ 0xCB, 0x11             ],  8),
        Opcode(  'rl', [                   'd' ], [ 0xCB, 0x12             ],  8),
        Opcode(  'rl', [                   'e' ], [ 0xCB, 0x13             ],  8),
        Opcode(  'rl', [                   'h' ], [ 0xCB, 0x14             ],  8),
        Opcode(  'rl', [                   'l' ], [ 0xCB, 0x15             ],  8),
        Opcode(  'rl', [                '(hl)' ], [ 0xCB, 0x16             ], 15),
        Opcode(  'rl', [              '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x16  ], 23),
        Opcode(  'rl', [              '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x16  ], 23),
        Opcode( 'rla', [                       ], [ 0x17                   ],  4),
        Opcode( 'rlc', [                   'a' ], [ 0xCB, 0x07             ],  8),
        Opcode( 'rlc', [                   'b' ], [ 0xCB, 0x00             ],  8),
        Opcode( 'rlc', [                   'c' ], [ 0xCB, 0x01             ],  8),
        Opcode( 'rlc', [                   'd' ], [ 0xCB, 0x02             ],  8),
        Opcode( 'rlc', [                   'e' ], [ 0xCB, 0x03             ],  8),
        Opcode( 'rlc', [                   'h' ], [ 0xCB, 0x04             ],  8),
        Opcode( 'rlc', [                   'l' ], [ 0xCB, 0x05             ],  8),
        Opcode( 'rlc', [                '(hl)' ], [ 0xCB, 0x06             ], 15),
        Opcode( 'rlc', [              '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x06  ], 23),
        Opcode( 'rlc', [              '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x06  ], 23),
        Opcode('rlca', [                       ], [ 0x07                   ],  4),
        Opcode( 'rld', [                       ], [ 0xED, 0x6F             ], 18),
        Opcode(  'rr', [                   'a' ], [ 0xCB, 0x1F             ],  8),
        Opcode(  'rr', [                   'b' ], [ 0xCB, 0x18             ],  8),
        Opcode(  'rr', [                   'c' ], [ 0xCB, 0x19             ],  8),
        Opcode(  'rr', [                   'd' ], [ 0xCB, 0x1A             ],  8),
        Opcode(  'rr', [                   'e' ], [ 0xCB, 0x1B             ],  8),
        Opcode(  'rr', [                   'h' ], [ 0xCB, 0x1C             ],  8),
        Opcode(  'rr', [                   'l' ], [ 0xCB, 0x1D             ],  8),
        Opcode(  'rr', [                '(hl)' ], [ 0xCB, 0x1E             ], 15),
        Opcode(  'rr', [              '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x1E  ], 23),
        Opcode(  'rr', [              '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x1E  ], 23),
        Opcode( 'rra', [                       ], [ 0x1F                   ],  4),
        Opcode( 'rrc', [                   'a' ], [ 0xCB, 0x0F             ],  8),
        Opcode( 'rrc', [                   'b' ], [ 0xCB, 0x08             ],  8),
        Opcode( 'rrc', [                   'c' ], [ 0xCB, 0x09             ],  8),
        Opcode( 'rrc', [                   'd' ], [ 0xCB, 0x0A             ],  8),
        Opcode( 'rrc', [                   'e' ], [ 0xCB, 0x0B             ],  8),
        Opcode( 'rrc', [                   'h' ], [ 0xCB, 0x0C             ],  8),
        Opcode( 'rrc', [                   'l' ], [ 0xCB, 0x0D             ],  8),
        Opcode( 'rrc', [                '(hl)' ], [ 0xCB, 0x0E             ], 15),
        Opcode( 'rrc', [              '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x0E  ], 23),
        Opcode( 'rrc', [              '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x0E  ], 23),
        Opcode('rrca', [                       ], [ 0x0F                   ],  4),
        Opcode( 'rrd', [                       ], [ 0xED, 0x67             ], 18),
        Opcode( 'rst', [                  '00' ], [ 0xC7                   ], 11),
        Opcode( 'rst', [                  '08' ], [ 0xCF                   ], 11),
        Opcode( 'rst', [                  '10' ], [ 0xD7                   ], 11),
        Opcode( 'rst', [                  '18' ], [ 0xDF                   ], 11),
        Opcode( 'rst', [                  '20' ], [ 0xE7                   ], 11),
        Opcode( 'rst', [                  '28' ], [ 0xEF                   ], 11),
        Opcode( 'rst', [                  '30' ], [ 0xF7                   ], 11),
        Opcode( 'rst', [                  '38' ], [ 0xFF                   ], 11),
        Opcode( 'sbc', [         'a',      'a' ], [ 0x9F                   ],  4),
        Opcode( 'sbc', [         'a',      'b' ], [ 0x98                   ],  4),
        Opcode( 'sbc', [         'a',      'c' ], [ 0x99                   ],  4),
        Opcode( 'sbc', [         'a',      'd' ], [ 0x9A                   ],  4),
        Opcode( 'sbc', [         'a',      'e' ], [ 0x9B                   ],  4),
        Opcode( 'sbc', [         'a',      'h' ], [ 0x9C                   ],  4),
        Opcode( 'sbc', [         'a',      'l' ], [ 0x9D                   ],  4),
        Opcode( 'sbc', [         'a',      '#' ], [ 0xDE, '#'              ],  7),
        Opcode( 'sbc', [         'a',   '(hl)' ], [ 0x9E                   ],  7),
        Opcode( 'sbc', [         'a', '(ix+#)' ], [ 0xDD, 0x9E, '#'        ], 19),
        Opcode( 'sbc', [         'a', '(iy+#)' ], [ 0xFD, 0x9E, '#'        ], 19),
        Opcode( 'sbc', [        'hl',     'bc' ], [ 0xED, 0x42             ], 15),
        Opcode( 'sbc', [        'hl',     'de' ], [ 0xED, 0x52             ], 15),
        Opcode( 'sbc', [        'hl',     'hl' ], [ 0xED, 0x62             ], 15),
        Opcode( 'sbc', [        'hl',     'sp' ], [ 0xED, 0x72             ], 15),
        Opcode( 'scf', [                       ], [ 0x37                   ],  4),
        Opcode( 'set', [        '0',       'a' ], [ 0xCB, 0xC7             ],  8),
        Opcode( 'set', [        '0',       'b' ], [ 0xCB, 0xC0             ],  8),
        Opcode( 'set', [        '0',       'c' ], [ 0xCB, 0xC1             ],  8),
        Opcode( 'set', [        '0',       'd' ], [ 0xCB, 0xC2             ],  8),
        Opcode( 'set', [        '0',       'e' ], [ 0xCB, 0xC3             ],  8),
        Opcode( 'set', [        '0',       'h' ], [ 0xCB, 0xC4             ],  8),
        Opcode( 'set', [        '0',       'l' ], [ 0xCB, 0xC5             ],  8),
        Opcode( 'set', [        '1',       'a' ], [ 0xCB, 0xCF             ],  8),
        Opcode( 'set', [        '1',       'b' ], [ 0xCB, 0xC8             ],  8),
        Opcode( 'set', [        '1',       'c' ], [ 0xCB, 0xC9             ],  8),
        Opcode( 'set', [        '1',       'd' ], [ 0xCB, 0xCA             ],  8),
        Opcode( 'set', [        '1',       'e' ], [ 0xCB, 0xCB             ],  8),
        Opcode( 'set', [        '1',       'h' ], [ 0xCB, 0xCC             ],  8),
        Opcode( 'set', [        '1',       'l' ], [ 0xCB, 0xCD             ],  8),
        Opcode( 'set', [        '2',       'a' ], [ 0xCB, 0xD7             ],  8),
        Opcode( 'set', [        '2',       'b' ], [ 0xCB, 0xD0             ],  8),
        Opcode( 'set', [        '2',       'c' ], [ 0xCB, 0xD1             ],  8),
        Opcode( 'set', [        '2',       'd' ], [ 0xCB, 0xD2             ],  8),
        Opcode( 'set', [        '2',       'e' ], [ 0xCB, 0xD3             ],  8),
        Opcode( 'set', [        '2',       'h' ], [ 0xCB, 0xD4             ],  8),
        Opcode( 'set', [        '2',       'l' ], [ 0xCB, 0xD5             ],  8),
        Opcode( 'set', [        '3',       'a' ], [ 0xCB, 0xDF             ],  8),
        Opcode( 'set', [        '3',       'b' ], [ 0xCB, 0xD8             ],  8),
        Opcode( 'set', [        '3',       'c' ], [ 0xCB, 0xD9             ],  8),
        Opcode( 'set', [        '3',       'd' ], [ 0xCB, 0xDA             ],  8),
        Opcode( 'set', [        '3',       'e' ], [ 0xCB, 0xDB             ],  8),
        Opcode( 'set', [        '3',       'h' ], [ 0xCB, 0xDC             ],  8),
        Opcode( 'set', [        '3',       'l' ], [ 0xCB, 0xDD             ],  8),
        Opcode( 'set', [        '4',       'a' ], [ 0xCB, 0xE7             ],  8),
        Opcode( 'set', [        '4',       'b' ], [ 0xCB, 0xE0             ],  8),
        Opcode( 'set', [        '4',       'c' ], [ 0xCB, 0xE1             ],  8),
        Opcode( 'set', [        '4',       'd' ], [ 0xCB, 0xE2             ],  8),
        Opcode( 'set', [        '4',       'e' ], [ 0xCB, 0xE3             ],  8),
        Opcode( 'set', [        '4',       'h' ], [ 0xCB, 0xE4             ],  8),
        Opcode( 'set', [        '4',       'l' ], [ 0xCB, 0xE5             ],  8),
        Opcode( 'set', [        '5',       'a' ], [ 0xCB, 0xEF             ],  8),
        Opcode( 'set', [        '5',       'b' ], [ 0xCB, 0xE8             ],  8),
        Opcode( 'set', [        '5',       'c' ], [ 0xCB, 0xE9             ],  8),
        Opcode( 'set', [        '5',       'd' ], [ 0xCB, 0xEA             ],  8),
        Opcode( 'set', [        '5',       'e' ], [ 0xCB, 0xEB             ],  8),
        Opcode( 'set', [        '5',       'h' ], [ 0xCB, 0xEC             ],  8),
        Opcode( 'set', [        '5',       'l' ], [ 0xCB, 0xED             ],  8),
        Opcode( 'set', [        '6',       'a' ], [ 0xCB, 0xF7             ],  8),
        Opcode( 'set', [        '6',       'b' ], [ 0xCB, 0xF0             ],  8),
        Opcode( 'set', [        '6',       'c' ], [ 0xCB, 0xF1             ],  8),
        Opcode( 'set', [        '6',       'd' ], [ 0xCB, 0xF2             ],  8),
        Opcode( 'set', [        '6',       'e' ], [ 0xCB, 0xF3             ],  8),
        Opcode( 'set', [        '6',       'h' ], [ 0xCB, 0xF4             ],  8),
        Opcode( 'set', [        '6',       'l' ], [ 0xCB, 0xF5             ],  8),
        Opcode( 'set', [        '7',       'a' ], [ 0xCB, 0xFF             ],  8),
        Opcode( 'set', [        '7',       'b' ], [ 0xCB, 0xF8             ],  8),
        Opcode( 'set', [        '7',       'c' ], [ 0xCB, 0xF9             ],  8),
        Opcode( 'set', [        '7',       'd' ], [ 0xCB, 0xFA             ],  8),
        Opcode( 'set', [        '7',       'e' ], [ 0xCB, 0xFB             ],  8),
        Opcode( 'set', [        '7',       'h' ], [ 0xCB, 0xFC             ],  8),
        Opcode( 'set', [        '7',       'l' ], [ 0xCB, 0xFD             ],  8),
        Opcode( 'set', [        '0',    '(hl)' ], [ 0xCB, 0xC6             ], 15),
        Opcode( 'set', [        '1',    '(hl)' ], [ 0xCB, 0xCE             ], 15),
        Opcode( 'set', [        '2',    '(hl)' ], [ 0xCB, 0xD6             ], 15),
        Opcode( 'set', [        '3',    '(hl)' ], [ 0xCB, 0xDE             ], 15),
        Opcode( 'set', [        '4',    '(hl)' ], [ 0xCB, 0xE6             ], 15),
        Opcode( 'set', [        '5',    '(hl)' ], [ 0xCB, 0xEE             ], 15),
        Opcode( 'set', [        '6',    '(hl)' ], [ 0xCB, 0xF6             ], 15),
        Opcode( 'set', [        '7',    '(hl)' ], [ 0xCB, 0xFE             ], 15),
        Opcode( 'set', [        '0',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xC6  ], 23),
        Opcode( 'set', [        '1',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xCE  ], 23),
        Opcode( 'set', [        '2',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xD6  ], 23),
        Opcode( 'set', [        '3',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xDE  ], 23),
        Opcode( 'set', [        '4',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xE6  ], 23),
        Opcode( 'set', [        '5',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xEE  ], 23),
        Opcode( 'set', [        '6',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xF6  ], 23),
        Opcode( 'set', [        '7',  '(ix+#)' ], [ 0xDD, 0xCB, '#', 0xFE  ], 23),
        Opcode( 'set', [        '0',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xC6  ], 23),
        Opcode( 'set', [        '1',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xCE  ], 23),
        Opcode( 'set', [        '2',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xD6  ], 23),
        Opcode( 'set', [        '3',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xDE  ], 23),
        Opcode( 'set', [        '4',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xE6  ], 23),
        Opcode( 'set', [        '5',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xEE  ], 23),
        Opcode( 'set', [        '6',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xF6  ], 23),
        Opcode( 'set', [        '7',  '(iy+#)' ], [ 0xFD, 0xCB, '#', 0xFE  ], 23),
        Opcode( 'sla', [                   'a' ], [ 0xCB, 0x27             ],  8),
        Opcode( 'sla', [                   'b' ], [ 0xCB, 0x20             ],  8),
        Opcode( 'sla', [                   'c' ], [ 0xCB, 0x21             ],  8),
        Opcode( 'sla', [                   'd' ], [ 0xCB, 0x22             ],  8),
        Opcode( 'sla', [                   'e' ], [ 0xCB, 0x23             ],  8),
        Opcode( 'sla', [                   'h' ], [ 0xCB, 0x24             ],  8),
        Opcode( 'sla', [                   'l' ], [ 0xCB, 0x25             ],  8),
        Opcode( 'sla', [                '(hl)' ], [ 0xCB, 0x26             ], 15),
        Opcode( 'sla', [              '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x26  ], 23),
        Opcode( 'sla', [              '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x26  ], 23),
        Opcode( 'sra', [                   'a' ], [ 0xCB, 0x2F             ],  8),
        Opcode( 'sra', [                   'b' ], [ 0xCB, 0x28             ],  8),
        Opcode( 'sra', [                   'c' ], [ 0xCB, 0x29             ],  8),
        Opcode( 'sra', [                   'd' ], [ 0xCB, 0x2A             ],  8),
        Opcode( 'sra', [                   'e' ], [ 0xCB, 0x2B             ],  8),
        Opcode( 'sra', [                   'h' ], [ 0xCB, 0x2C             ],  8),
        Opcode( 'sra', [                   'l' ], [ 0xCB, 0x2D             ],  8),
        Opcode( 'sra', [                '(hl)' ], [ 0xCB, 0x2E             ], 15),
        Opcode( 'sra', [              '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x2E  ], 23),
        Opcode( 'sra', [              '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x2E  ], 23),
        Opcode( 'srl', [                   'a' ], [ 0xCB, 0x3F             ],  8),
        Opcode( 'srl', [                   'b' ], [ 0xCB, 0x38             ],  8),
        Opcode( 'srl', [                   'c' ], [ 0xCB, 0x39             ],  8),
        Opcode( 'srl', [                   'd' ], [ 0xCB, 0x3A             ],  8),
        Opcode( 'srl', [                   'e' ], [ 0xCB, 0x3B             ],  8),
        Opcode( 'srl', [                   'h' ], [ 0xCB, 0x3C             ],  8),
        Opcode( 'srl', [                   'l' ], [ 0xCB, 0x3D             ],  8),
        Opcode( 'srl', [                '(hl)' ], [ 0xCB, 0x3E             ], 15),
        Opcode( 'srl', [              '(ix+#)' ], [ 0xDD, 0xCB, '#', 0x3E  ], 23),
        Opcode( 'srl', [              '(iy+#)' ], [ 0xFD, 0xCB, '#', 0x3E  ], 23),
        Opcode( 'sub', [                   'a' ], [ 0x97                   ],  4),
        Opcode( 'sub', [                   'b' ], [ 0x90                   ],  4),
        Opcode( 'sub', [                   'c' ], [ 0x91                   ],  4),
        Opcode( 'sub', [                   'd' ], [ 0x92                   ],  4),
        Opcode( 'sub', [                   'e' ], [ 0x93                   ],  4),
        Opcode( 'sub', [                   'h' ], [ 0x94                   ],  4),
        Opcode( 'sub', [                   'l' ], [ 0x95                   ],  4),
        Opcode( 'sub', [                   '#' ], [ 0xD6, '#'              ],  7),
        Opcode( 'sub', [                '(hl)' ], [ 0x96                   ],  7),
        Opcode( 'sub', [              '(ix+#)' ], [ 0xDD, 0x96, '#'        ], 19),
        Opcode( 'sub', [              '(iy+#)' ], [ 0xFD, 0x96, '#'        ], 19),
        Opcode( 'xor', [                   'a' ], [ 0xAF                   ],  4),
        Opcode( 'xor', [                   'b' ], [ 0xA8                   ],  4),
        Opcode( 'xor', [                   'c' ], [ 0xA9                   ],  4),
        Opcode( 'xor', [                   'd' ], [ 0xAA                   ],  4),
        Opcode( 'xor', [                   'e' ], [ 0xAB                   ],  4),
        Opcode( 'xor', [                   'h' ], [ 0xAC                   ],  4),
        Opcode( 'xor', [                   'l' ], [ 0xAD                   ],  4),
        Opcode( 'xor', [                   '#' ], [ 0xEE, '#'              ],  7),
        Opcode( 'xor', [                '(hl)' ], [ 0xAE                   ],  7),
        Opcode( 'xor', [              '(ix+#)' ], [ 0xDD, 0xAE, '#'        ], 19),
        Opcode( 'xor', [              '(iy+#)' ], [ 0xFD, 0xAE, '#'        ], 19),
    ]

hdr  = '// THIS IS A GENERATED FILE. DO NOT EDIT!\n'
hdr += '#ifndef COMPILER_Z80OPCODES_H\n'
hdr += '#define COMPILER_Z80OPCODES_H\n'
hdr += '\n'
hdr += '#include "ProgramOpcode.h"\n'
hdr += '#include "Expression.h"\n'
hdr += '#include <memory>\n'

src  = '// THIS IS A GENERATED FILE. DO NOT EDIT!\n'
src += '#include "Z80Opcodes.h"\n'
src += '#include "ProgramBinary.h"\n'

src2  = '// THIS IS A GENERATED FILE. DO NOT EDIT!\n'
src2 += '#include "Z80Opcodes.h"\n'
src2 += '#include "ProgramSection.h"\n'
src2 += '#include "AssemblerParser.h"\n'
src2 += '#include "AssemblerToken.h"\n'
src2 += '#include <unordered_map>\n'
src2 += '\n'
src2 += '#ifdef emit\n'
src2 += '#undef emit\n'
src2 += '#endif\n'

for opcode in opcodes:
    hdr += '\n'
    hdr += 'class %s : public ProgramOpcode\n' % opcode.className
    hdr += '{\n'
    hdr += 'public:\n'
    hdr += '    %s(const Token& token%s)\n' % (opcode.className, opcode.argsDecl())
    hdr += '        : ProgramOpcode(token)\n'
    for idx in range(0, opcode.numLiterals):
        hdr += '        , mLiteral%d(std::move(literal%d))\n' % (idx + 1, idx + 1)
    hdr += '    {\n'
    hdr += '    }\n'
    hdr += '\n'
    hdr += '    unsigned lengthInBytes() const override { return %d; }\n' % opcode.lengthInBytes
    hdr += '    unsigned tstatesIfNotTaken() const override { return %d; }\n' % opcode.tstatesIfNotTaken
    hdr += '    unsigned tstatesIfTaken() const override { return %d; }\n' % opcode.tstatesIfTaken
    hdr += '\n'
    hdr += '    void emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const override;\n'
    hdr += '\n'
    if opcode.numLiterals > 0:
        hdr += 'private:\n'
        for idx in range(0, opcode.numLiterals):
            hdr += '    std::unique_ptr<Expression> mLiteral%d;\n' % (idx + 1)
        hdr += '\n'
    hdr += '    Q_DISABLE_COPY(%s)\n' % opcode.className
    hdr += '};\n'

    src += '\n'
    src += 'void %s::emitBinary(IErrorReporter* reporter, ProgramBinary* bin) const\n' % opcode.className
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
    global src2
    for key, value in dict.items():
        src2 += '%sif (%s)' % (indent, key)
        if not isinstance(value, Opcode):
            src2 += ' {\n'
            genCode(value, indent + '    ')
            src2 += '%s}\n' % indent
        else:
            src2 += '\n'
            src2 += '%s    return mSection->emit<%s>(mToken%s);\n' % (indent, value.className, value.argsCall())
    src2 += '%sreturn false;\n' % indent

def addCond(conds, what):
    for condlist in conds:
        condlist.append(what)

def forkConds(conds, orig):
    newlist = []
    for condlist in orig:
        newlist.append(condlist[:])
    for lst in newlist:
        conds.append(lst)
    return newlist

opcodeMap = OrderedDict()
for opcode in opcodes:
    conds = [ [ opcode.name ] ]
    literalIndex = 1
    first = True
    for op in opcode.operands:
        if first:
            first = False
        else:
            addCond(conds, 'token(T_COMMA)')

        if op in [ 'a', 'b', 'c', 'd', 'e', 'h', 'l', 'i', 'r', 'bc', 'de', 'hl', 'sp', 'ix', 'iy', 'af', "af'" ]:
            addCond(conds, 'ident("%s")' % op)
        elif op in [ 'c', 'nc', 'z', 'nz', 'm', 'p', 'pe', 'po' ]:
            addCond(conds, 'ident("%s")' % op)
        elif op in [ '0', '1', '2', '3', '4', '5', '6', '7' ]:
            addCond(conds, 'number(%s)' % op)
        elif op in [ '00', '08', '10', '18', '20', '28', '30', '38' ]:
            addCond(conds, 'number(0x%s)' % op)
        elif op in [ '(bc)', '(de)', '(hl)', '(ix)', '(iy)', '(sp)' ]:
            addCond(conds, 'token(T_LPAREN)')
            addCond(conds, 'ident("%s")' % op[1:3])
            addCond(conds, 'token(T_RPAREN)')
        elif op in [ '(ix+#)', '(iy+#)' ]:
            addCond(conds, 'token(T_LPAREN)')
            addCond(conds, 'ident("%s")' % op[1:3])
            orig = conds[:]
            alt1 = forkConds(conds, orig)
            alt2 = forkConds(conds, orig)
            addCond(orig, 'token(T_RPAREN)')
            addCond(alt1, 'token(T_PLUS)')
            addCond(alt1, 'byteLiteral(&literal%d)' % literalIndex)
            addCond(alt1, 'token(T_RPAREN)')
            addCond(alt2, 'token(T_MINUS)')
            addCond(alt2, 'byteLiteral(&literal%d)' % literalIndex)
            addCond(alt2, 'token(T_RPAREN)')
            literalIndex += 1
        elif op == '(c)':
            addCond(conds, 'token(T_LPAREN)')
            addCond(conds, 'ident("c")')
            addCond(conds, 'token(T_RPAREN)')
        elif op == '(#)':
            addCond(conds, 'token(T_LPAREN)')
            addCond(conds, 'byteLiteral(&literal%d)' % literalIndex)
            addCond(conds, 'token(T_RPAREN)')
            literalIndex += 1
        elif op == '(##)':
            addCond(conds, 'token(T_LPAREN)')
            addCond(conds, 'wordLiteral(&literal%d)' % literalIndex)
            addCond(conds, 'token(T_RPAREN)')
            literalIndex += 1
        elif op == '#':
            addCond(conds, 'byteLiteral(&literal%d)' % literalIndex)
            literalIndex += 1
        elif op == '##':
            addCond(conds, 'wordLiteral(&literal%d)' % literalIndex)
            literalIndex += 1
        elif op == 'R#':
            addCond(conds, 'byteOffset(&literal%d)' % literalIndex)
            literalIndex += 1
        else:
            raise Exception('Unknown operand "%s"' % op)

    for condlist in conds:
        dict = opcodeMap
        for cond in condlist:
            dict = getDict(dict, cond)
        dict['eol()'] = opcode

src2 += '\n'
src2 += 'class Z80OpcodeParser\n'
src2 += '{\n'
src2 += 'private:\n'
src2 += '    AssemblerParser* mParser;\n'
src2 += '    ProgramSection* mSection;\n'
src2 += '    const Token& mToken;\n'
src2 += '\n'
src2 += '    bool eol() const { return mParser->matchEol(); }\n'
src2 += '    bool token(int tok) const { return mParser->matchToken(tok); }\n'
src2 += '    bool ident(const char* id) const { return mParser->matchIdentifier(id); }\n'
src2 += '    bool number(quint32 value) const { return mParser->matchNumber(value); }\n'
src2 += '\n'
src2 += '    bool byteLiteral(std::unique_ptr<Expression>* out) const { return mParser->parseExpression(out); }\n'
src2 += '    bool byteOffset(std::unique_ptr<Expression>* out) const { return mParser->parseExpression(out); }\n'
src2 += '    bool wordLiteral(std::unique_ptr<Expression>* out) const { return mParser->parseExpression(out); }\n'
src2 += '\n'
src2 += 'public:\n'
src2 += '    explicit Z80OpcodeParser(AssemblerParser* parser)\n'
src2 += '        : mParser(parser)\n'
src2 += '        , mSection(parser->mSection)\n'
src2 += '        , mToken(parser->lastToken())\n'
src2 += '    {\n'
src2 += '        mParser->nextToken();\n'
src2 += '    }\n'

for opcode, dict in opcodeMap.items():
    src2 += '\n'
    src2 += '    bool %s()\n' % opcode
    src2 += '    {\n'
    src2 += '        std::unique_ptr<Expression> literal1, literal2;\n'
    src2 += '\n'
    genCode(dict, '        ')
    src2 += '    }\n'

src2 += '};\n'
src2 += '\n'
src2 += 'using Func = bool (Z80OpcodeParser::*)();\n'
src2 += 'static std::unordered_map<std::string, Func> opcodes = {\n'
for opcode, dict in opcodeMap.items():
    src2 += '        { "%s", &Z80OpcodeParser::%s },\n' % (opcode, opcode)
src2 += '    };\n'

src2 += '\n'
src2 += 'bool AssemblerParser::parseOpcode_generated(const std::string& opcode)\n'
src2 += '{\n'
src2 += '    auto it = opcodes.find(opcode);\n'
src2 += '    if (it != opcodes.end()) {\n'
src2 += '        Z80OpcodeParser parser(this);\n'
src2 += '        return (parser.*(it->second))();\n'
src2 += '    }\n'
src2 += '    return false;\n'
src2 += '}\n'

hdr += '\n'
hdr += '#endif\n'

with open("Z80Opcodes.h", "w") as f:
    f.write(hdr)
with open("Z80Opcodes.cpp", "w") as f:
    f.write(src)
with open("Z80Opcodes_parser.cpp", "w") as f:
    f.write(src2)
