#include "GfxFileUtil.h"
#include "compiler/GfxData.h"
#include "compiler/GfxFile.h"
#include <QColor>
#include <QImage>

const QColor GfxFilePalette[] = {
        QColor(0x00, 0x00, 0x00),
        QColor(0x00, 0x00, 0xc0),
        QColor(0xc0, 0x00, 0x00),
        QColor(0xc0, 0x00, 0xc0),
        QColor(0x00, 0xc0, 0x00),
        QColor(0x00, 0xc0, 0xc0),
        QColor(0xc0, 0xc0, 0x00),
        QColor(0xc0, 0xc0, 0xc0),
        QColor(0x00, 0x00, 0x00),
        QColor(0x00, 0x00, 0xff),
        QColor(0xff, 0x00, 0x00),
        QColor(0xff, 0x00, 0xff),
        QColor(0x00, 0xff, 0x00),
        QColor(0x00, 0xff, 0xff),
        QColor(0xff, 0xff, 0x00),
        QColor(0xff, 0xff, 0xff),
    };

QImage gfxToQImage(const GfxData* data, GfxColorMode mode, int scale)
{
    int w = data->width();
    int h = data->height();
    QImage image(w * scale, h * scale, QImage::Format_ARGB32);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char value = data->at(x, y);
            char attrib = data->attribAt(x, y, mode);

            int color = (value ? attrib & 7 : (attrib & 0x38) >> 3);
            if (attrib & 0x40)
                color += 8;

            const QColor& colorRef = GfxFilePalette[color];
            for (int yy = 0; yy < scale; yy++) {
                for (int xx = 0; xx < scale; xx++)
                    image.setPixel(x * scale + xx, y * scale + yy, colorRef.rgb());
            }
        }
    }

    return image;
}
