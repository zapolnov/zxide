#ifndef UTIL_IMAGEIMPORT_H
#define UTIL_IMAGEIMPORT_H

#include "compiler/GfxData.h"
#include <QImage>
#include <memory>

std::unique_ptr<GfxData> importImage(const QImage& image, bool dither);

#endif
