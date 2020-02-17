#ifndef UTIL_IMAGEIMPORT_H
#define UTIL_IMAGEIMPORT_H

#include "compiler/GfxData.h"
#include <QImage>
#include <memory>

std::unique_ptr<GfxData> importMonochromeImage(const QImage& image);
std::unique_ptr<GfxData> importScrFile(const QByteArray& data);

#endif
