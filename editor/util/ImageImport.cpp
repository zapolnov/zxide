#include "ImageImport.h"
#include "debugger/EmulatorCore.h"
#include "compiler/GfxFile.h"

/*
#define NUM_COLORS 16

static QRgb spectrumColor(int index)
{
    return qRgb(ZXPalette[index].r, ZXPalette[index].g, ZXPalette[index].b);
}

static int colorDistance(QRgb c1, QRgb c2)
{
    int distR = int(qRed(c1)) - int(qRed(c2));
    int distG = int(qGreen(c1)) - int(qGreen(c2));
    int distB = int(qBlue(c1)) - int(qBlue(c2));
    return distR * distR + distG * distG + distB * distB;
}
*/

static quint8 toGrayscale(QRgb color)
{
    double dR = double(qRed(color)) / 255.0;
    double dG = double(qGreen(color)) / 255.0;
    double dB = double(qBlue(color)) / 255.0;
    int i = int((dR * 0.2126 + dG * 0.7152 + dB * 0.0722) * 255.0);
    return (i < 0 ? 0 : (i > 255 ? 255 : i));
}

#if 0

namespace
{
    struct Colors
    {
        int ink;
        int paper;

        Colors()
            : ink(0)
            , paper(0)
        {
        }

        explicit Colors(int c)
            : ink(c)
            , paper(c)
        {
        }

        Colors(int c1, int c2)
        {
            /*
            quint8 lum1 = toGrayscale(c1);
            quint8 lum2 = toGrayscale(c2);
            if (lum1 > lum2) {
                ink = c1;
                paper = c2;
            } else {
                ink = c2;
                paper = c1;
            }*/
            ink = c1;
            paper = c2;
        }
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
                int dist = colorDistance(color, spectrumColor(i));
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

    return Colors(ink, 0);
    /*

    // Choose paper color
    int paper = -1;
    for (int i = 0; i < NUM_COLORS; i++) {
        if (i != ink && histogram[i] > 0 && (paper == -1 || histogram[i] > histogram[paper]))
            paper = i;
    }

    if (paper == -1) // only one color
        return Colors(ink);

    if (ink > 7 && paper > 7) // both are bright
        return Colors(ink, paper);
    if (ink < 8 && paper < 8) // both are dark
        return Colors(ink, paper);

    // colors have different brightness; see if one of them is black
    if (ink == 0)
        return Colors(8, paper);
    if (ink == 8)
        return Colors(0, paper);
    if (paper == 0)
        return Colors(ink, 8);
    if (paper == 8)
        return Colors(ink, 0);

    // colors are unrelated and have different brightness... Shrink the palette
    if (ink > 7) // most important color is bright -- rechoose from a bright palette
        return chooseColors(image, x, y, 8, 16);
    else // most important color is dark -- rechoose from a dark palette
        return chooseColors(image, x, y, 0,  8);
    */
}

/*
static void adjustPixel(QImage& image, int x, int y, int adjust)
{
    QRgb pixel = image.pixel(x, y);
    int r = qMin(qMax(qRed(pixel) + adjust, 0), 255);
    int g = qMin(qMax(qGreen(pixel) + adjust, 0), 255);
    int b = qMin(qMax(qBlue(pixel) + adjust, 0), 255);
    image.setPixel(x, y, qRgb(r, g, b));
}
*/

static void adjustPixel(std::unique_ptr<quint8[]>& image, int x, int y, int w, int h, int adjust)
{
    if (x >= w || y >= h)
        return;

    quint8 luminance = image[y * w + x];
    int value = qMin(qMax(luminance + adjust, 0), 255);
    image[y * w + x] = value;
}

std::unique_ptr<GfxData> importImage(const QImage& image, bool dither)
{
    int w = (image.width() + 7) & ~7;
    int h = (image.height() + 7) & ~7;
    int charsW = w >> 3;
    int charsH = h >> 3;

    std::unique_ptr<Colors[]> colors{new Colors[charsW * charsH]};
    for (int y = 0; y < charsH; y++) {
        for (int x = 0; x < charsW; x++)
            colors[y * charsW + x] = chooseColors(image, x * 8, y * 8, 0, NUM_COLORS);
    }

    std::unique_ptr<quint8[]> grayscale{new quint8[w * h]};
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            grayscale[y * w + x] = toGrayscale(image.pixel(x, y));
    }

    auto result = std::make_unique<GfxData>(w, h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            quint8 luminance = grayscale[y * w + x];
            const Colors& c = colors[(y >> 3) * charsW + (x >> 3)];

            quint8 attrib = 0;
            attrib  = (c.ink & 7);
            attrib |= (c.paper & 7) << 3;
            attrib |= (c.ink > 7 ? 0x40 : 0);

            quint8 resultPixel = (luminance < 128 ? 0 : 255);
            result->at(x, y) = resultPixel;
            result->attribAt(x, y, GfxColorMode::Standard) = 0x47;//attrib;

            int error = int(luminance) - int(toGrayscale(spectrumColor(resultPixel ? c.ink : c.paper)));
            /*
            adjustPixel(grayscale, x + 1, y,     w, h, (error * 7) >> 4);
            adjustPixel(grayscale, x - 1, y + 1, w, h, (error * 3) >> 4);
            adjustPixel(grayscale, x,     y + 1, w, h, (error * 5) >> 4);
            adjustPixel(grayscale, x + 1, y + 1, w, h, (error * 1) >> 4);
            */

            /*
            adjustPixel(grayscale, x + 1, y,     w, h, (error * 7) / 48);
            adjustPixel(grayscale, x + 2, y,     w, h, (error * 5) / 48);
            adjustPixel(grayscale, x - 2, y + 1, w, h, (error * 3) / 48);
            adjustPixel(grayscale, x - 1, y + 1, w, h, (error * 5) / 48);
            adjustPixel(grayscale, x,     y + 1, w, h, (error * 7) / 48);
            adjustPixel(grayscale, x + 1, y + 1, w, h, (error * 5) / 48);
            adjustPixel(grayscale, x + 2, y + 1, w, h, (error * 3) / 48);
            adjustPixel(grayscale, x - 2, y + 2, w, h, (error * 1) / 48);
            adjustPixel(grayscale, x - 1, y + 2, w, h, (error * 3) / 48);
            adjustPixel(grayscale, x,     y + 2, w, h, (error * 5) / 48);
            adjustPixel(grayscale, x + 1, y + 2, w, h, (error * 3) / 48);
            adjustPixel(grayscale, x + 2, y + 2, w, h, (error * 1) / 48);
            */

            adjustPixel(grayscale, x + 1, y,     w, h, error / 8);
            adjustPixel(grayscale, x + 2, y,     w, h, error / 8);
            adjustPixel(grayscale, x - 1, y + 1, w, h, error / 8);
            adjustPixel(grayscale, x,     y + 1, w, h, error / 8);
            adjustPixel(grayscale, x + 1, y + 1, w, h, error / 8);
            adjustPixel(grayscale, x,     y + 2, w, h, error / 8);
        }
    }

    return result;
}

#endif

std::unique_ptr<GfxData> importMonochromeImage(const QImage& image)
{
    int w = (image.width() + 7) & ~7;
    int h = (image.height() + 7) & ~7;
    int charsW = w >> 3;
    int charsH = h >> 3;

    std::unique_ptr<quint8[]> grayscale{new quint8[w * h]};
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            grayscale[y * w + x] = toGrayscale(image.pixel(x, y));
    }

    auto result = std::make_unique<GfxData>(w, h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            quint8 luminance = grayscale[y * w + x];
            quint8 resultPixel = (luminance < 128 ? 0 : 255);
            result->at(x, y) = resultPixel;
            result->attribAt(x, y, GfxColorMode::Standard) = 0x07;
        }
    }

    return result;
}

std::unique_ptr<GfxData> importScrFile(const QByteArray& data)
{
    int w = 256;
    int h = 192;

    auto result = std::make_unique<GfxData>(w, h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int offset = ((y & 7) << 8) | ((y << 2) & 0xe0) | ((y << 5) & 0x1800) | (x >> 3);
            bool pixel = data.at(offset) & (0x80 >> (x & 7));
            uint8_t attrib = data.at(0x1800 + (y / 8) * 32 + (x / 8));
            result->at(x, y) = (char)(unsigned char)(pixel ? 255 : 0);
            result->attribAt(x, y, GfxColorMode::Standard) = attrib;
        }
    }

    return result;
}
