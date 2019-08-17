#!/usr/bin/env python -B

import zlib
import struct

def writePNG():
    # https://stackoverflow.com/questions/8554282/creating-a-png-file-in-python
    def I1(value):
        return struct.pack("!B", value & (2**8-1))
    def I4(value):
        return struct.pack("!I", value & (2**32-1))
    png = b"\x89" + "PNG\r\n\x1A\n".encode('ascii')
    # IHDR
    width = 128
    height = font_height * 16
    bitdepth = 8 # with one byte per pixel (0..255)
    colortype = 3 # indexed-colour
    compression = 0 # zlib (no choice here)
    filtertype = 0 # adaptive (each scanline seperately)
    interlaced = 0 # no
    IHDR = I4(width) + I4(height) + I1(bitdepth)
    IHDR += I1(colortype) + I1(compression)
    IHDR += I1(filtertype) + I1(interlaced)
    block = "IHDR".encode('ascii') + IHDR
    png += I4(len(IHDR)) + block + I4(zlib.crc32(block))
    # PLTE
    PLTE = I1(0) + I1(0) + I1(0)            # white
    PLTE += I1(0xFF) + I1(0xFF) + I1(0xFF)  # white
    block = "PLTE".encode('ascii') + PLTE
    png += I4(len(PLTE)) + block + I4(zlib.crc32(block))
    # tRNS
    tRNS = I1(0)                            # transparent
    block = "tRNS".encode('ascii') + tRNS
    png += I4(len(tRNS)) + block + I4(zlib.crc32(block))
    # IDAT
    raw = b""
    for y in range(0, height):
        raw += b"\0" # no filter for this scanline
        for x in range(0, width):
            raw += I1(image[y * 128 + x])
    compressor = zlib.compressobj()
    compressed = compressor.compress(raw)
    compressed += compressor.flush()
    block = "IDAT".encode('ascii') + compressed
    png += I4(len(compressed)) + block + I4(zlib.crc32(block))
    # IEND
    block = "IEND".encode('ascii')
    png += I4(0) + block + I4(zlib.crc32(block))
    # ----
    with open("font.png", "wb") as f:
        f.write(png)

font_height = 16

image = []
for i in range(0, 128 * font_height * 16):
    image.append(i)

with open("cp850.f16", "rb") as f:
    cp850 = bytearray(f.read())
with open("thin_ss.f16", "rb") as f:
    thin_ss = bytearray(f.read())

def setChar(code, char, data = thin_ss):
    x = code & 15
    y = code >> 4
    for yy in range(0, font_height):
        for xx in range(0, 8):
            ix = x * 8 + xx
            iy = y * font_height + yy
            image[iy * 128 + ix] = 0 if (data[char * font_height + yy] & (1 << (7 - xx)) != 0) else 1

def setPixels(code, pixels):
    x = code & 15
    y = code >> 4
    for yy in range(0, font_height):
        for xx in range(0, 8):
            ix = x * 8 + xx
            iy = y * font_height + yy
            image[iy * 128 + ix] = 0 if (pixels[yy][xx] == 'x') else 1

for i in range(0x00, 0x20):
    setChar(i, 0x2E)
for i in range(0x20, 0x5E):
    setChar(i, i)
setChar(0x5E, 0x18) # up arrow instead of '^'
setChar(0x5F, 0x5F)
setChar(0x60, 0x9C) # pound sign instead of '`'
for i in range(0x61, 0x7F):
    setChar(i, i)
setChar(0x7F, 0xB8, cp850) # copyright sign instead of DEL

setPixels(0x80, [
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
    ])

setPixels(0x81, [
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
    ])

setPixels(0x82, [
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
    ])

setPixels(0x83, [
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
    ])

setPixels(0x84, [
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
    ])

setPixels(0x85, [
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
    ])

setPixels(0x86, [
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
    ])

setPixels(0x87, [
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
    ])

setPixels(0x88, [
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
    ])

setPixels(0x89, [
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
    ])

setPixels(0x8A, [
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
    ])

setPixels(0x8B, [
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
    ])

setPixels(0x8C, [
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
    ])

setPixels(0x8D, [
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        '....xxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
    ])

setPixels(0x8E, [
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxx....',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
    ])

setPixels(0x8F, [
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
        'xxxxxxxx',
    ])

for i in range(0x90, 0xFD):
    setChar(i, 0x2E)

setPixels(0xFD, [       # custom for the editor
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        'xxxxxxxx',
        'xxxxxxxx',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
    ])

setPixels(0xFE, [       # custom for the editor
        '........',
        '........',
        '........',
        '........',
        '...xx...',
        '....xx..',
        '.....xx.',
        'xxxxxxxx',
        'xxxxxxxx',
        '.....xx.',
        '....xx..',
        '...xx...',
        '........',
        '........',
        '........',
        '........',
    ])

setPixels(0xFF, [       # custom for the editor
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '........',
        '.x..xx..',
        '.x.x....',
        '.x.xxx..',
        '.x.x..x.',
        '.x.x..x.',
        '.x..xx..',
        '........',
    ])

writePNG()
