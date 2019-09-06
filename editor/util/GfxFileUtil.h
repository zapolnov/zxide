#ifndef UTIL_GFXFILEUTIL_H
#define UTIL_GFXFILEUTIL_H

class QColor;
class QImage;
class GfxData;
enum class GfxColorMode : int;

extern const QColor GfxFilePalette[];

QImage gfxToQImage(const GfxData* data, GfxColorMode mode, int scale = 1, bool flash = false);

#endif
