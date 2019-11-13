#include "ImageImport.h"
#include "debugger/EmulatorCore.h"
#include "compiler/GfxFile.h"

#define NUM_COLORS 16

namespace
{
    struct Colors
    {
        int ink;
        int paper;
    };
}

static Colors chooseColors(const QImage& image, int x, int y, int paletteStart, int paletteEnd)
{
    unsigned histogram[NUM_COLORS] = {0};

    // Create histogram
    for (int yy = 0; yy < 8; yy++) {
        if (y + yy >= image.height())
            break;

        for (int xx = 0; xx < 8; xx++) {
            if (x + xx >= image.width())
                break;

            int closestColor = -1, minDist = -1;

            // Find closest color from the spectrum palette
            for (int i = paletteStart; i < paletteEnd; i++) {
                QRgb color = image.pixel(x + xx, y + yy);
                int distR = int(qRed(color)) - int(ZXPalette[i].r);
                int distG = int(qGreen(color)) - int(ZXPalette[i].g);
                int distB = int(qBlue(color)) - int(ZXPalette[i].b);
                int dist = distR * distR + distG * distG + distB * distB;
                if (minDist == -1 || dist < minDist) {
                    minDist = dist;
                    closestColor = i;
                }
            }

            histogram[closestColor]++;
        }
    }

    // Choose ink color
    int ink = 0;
    for (int i = 1; i < NUM_COLORS; i++) {
        if (histogram[i] > histogram[ink])
            ink = i;
    }

    // Choose paper color
    int paper = -1;
    for (int i = 0; i < NUM_COLORS; i++) {
        if (i != ink && histogram[i] > 0 && (paper == -1 || histogram[i] > histogram[paper]))
            paper = i;
    }

    if (paper == -1) // only one color
        return { ink, ink };

    if (ink > 7 && paper > 7) // both are bright
        return { ink, paper };
    if (ink < 8 && paper < 8) // both are dark
        return { ink, paper };

    // colors have different brightness; see if one of them is black
    if (ink == 0)
        return { 8, paper };
    if (ink == 8)
        return { 0, paper };
    if (paper == 0)
        return { ink, 8 };
    if (paper == 8)
        return { ink, 0 };

    // colors are unrelated and have different brightness... Shrink the palette
    if (ink > 7) // most important color is bright -- rechoose from a bright palette
        return chooseColors(image, x, y, 8, 16);
    else // most important color is dark -- rechoose from a dark palette
        return chooseColors(image, x, y, 0,  8);
}

std::unique_ptr<GfxData> importImage(const QImage& image, bool dither)
{
    int w = (image.width() + 7) & ~7;
    int h = (image.height() + 7) & ~7;
    int charsW = w >> 3;
    int charsH = h >> 3;

    auto result = std::make_unique<GfxData>(w, h);
    std::unique_ptr<Colors[]> colors{new Colors[charsW * charsH]};

    for (int y = 0; y < charsH; y++) {
        for (int x = 0; x < charsW; x++)
            colors[y * charsW + x] = chooseColors(image, x * 8, y * 8, 0, NUM_COLORS);
    }

    // FIXME: dither

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            QRgb rgb = image.pixel(x, y);
            const Colors& c = colors[(y >> 3) * charsW + (x >> 3)];

            quint8 attrib = 0;
            attrib  = (c.ink & 7);
            attrib |= (c.paper & 7) << 3;
            attrib |= (c.ink > 7 ? 0x40 : 0);

            int inkDistR = int(qRed(rgb)) - int(ZXPalette[c.ink].r);
            int inkDistG = int(qGreen(rgb)) - int(ZXPalette[c.ink].g);
            int inkDistB = int(qBlue(rgb)) - int(ZXPalette[c.ink].b);
            int inkDist = inkDistR * inkDistR + inkDistG * inkDistG + inkDistB * inkDistB;

            int paperDistR = int(qRed(rgb)) - int(ZXPalette[c.paper].r);
            int paperDistG = int(qGreen(rgb)) - int(ZXPalette[c.paper].g);
            int paperDistB = int(qBlue(rgb)) - int(ZXPalette[c.paper].b);
            int paperDist = paperDistR * paperDistR + paperDistG * paperDistG + paperDistB * paperDistB;

            result->at(x, y) = (inkDist < paperDist ? 1 : 0);
            result->attribAt(x, y, GfxColorMode::Standard) = attrib;
        }
    }

    return result;
}
