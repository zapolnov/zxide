#include "GfxData.h"
#include <cstring>

GfxData::GfxData(int w, int h, QObject* parent)
    : QObject(parent)
    , mData(new char[w * h])
    , mAttrib(new char[((w + 7) >> 3) * h])
    , mWidth(w)
    , mHeight(h)
{
    clear();
}

GfxData::~GfxData()
{
}

void GfxData::resize(int w, int h)
{
    Q_ASSERT(w > 0);
    Q_ASSERT(h > 0);

    std::unique_ptr<char[]> newData{new char[w * h]};
    std::unique_ptr<char[]> newAttrib{new char[((w + 7) >> 3) * h]};
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            newData[y * w + x] = (isValidCoord(x, y) ? at(x, y) : 0);
            newAttrib[y * ((w + 7) >> 3) + (x >> 3)] =
                (isValidCoord(x, y) ? mAttrib[y * ((mWidth + 7) >> 3) + (x >> 3)] : 7);
        }
    }

    mData = std::move(newData);
    mAttrib = std::move(newAttrib);
    mWidth = w;
    mHeight = h;

    emit sizeChanged();
}

bool GfxData::isValidCoord(int x, int y) const
{
    return (x >= 0 && y >= 0 && x < mWidth && y < mHeight);
}

bool GfxData::isValidCoord(const QPoint& pt) const
{
    return isValidCoord(pt.x(), pt.y());
}

char GfxData::at(int x, int y) const
{
    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y))
        return 0;

    return mData[y * mWidth + x];
}

char GfxData::at(const QPoint& p) const
{
    return at(p.x(), p.y());
}

char& GfxData::at(int x, int y)
{
    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y)) {
        static char dummy;
        dummy = 0;
        return dummy;
    }

    return mData[y * mWidth + x];
}

char& GfxData::at(const QPoint& p)
{
    return at(p.x(), p.y());
}

char GfxData::attribAt(int x, int y, GfxColorMode mode) const
{
    x &= ~7;
    switch (mode) {
        case GfxColorMode::Standard: y &= ~7; break;
        case GfxColorMode::Bicolor: y &= ~1; break;
        case GfxColorMode::Multicolor: break;
    }

    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y))
        return 7;

    return mAttrib[y * ((mWidth + 7) >> 3) + (x >> 3)];
}

char& GfxData::attribAt(int x, int y, GfxColorMode mode)
{
    x &= ~7;
    switch (mode) {
        case GfxColorMode::Standard: y &= ~7; break;
        case GfxColorMode::Bicolor: y &= ~1; break;
        case GfxColorMode::Multicolor: break;
    }

    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y)) {
        static char dummy;
        dummy = 7;
        return dummy;
    }

    return mAttrib[y * ((mWidth + 7) >> 3) + (x >> 3)];
}

void GfxData::clear()
{
    memset(mData.get(), 0, mWidth * mHeight);
    memset(mAttrib.get(), 7, ((mWidth + 7) >> 3) * mHeight);
}

void GfxData::clear(int x1, int y1, int x2, int y2)
{
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++)
            at(x, y) = 0;
    }
}

QByteArray GfxData::bytes() const
{
    return QByteArray(mData.get(), mWidth * mHeight) + QByteArray(mAttrib.get(), ((mWidth + 7) >> 3) * mHeight);
}

QByteArray GfxData::bytes(int x1, int y1, int x2, int y2) const
{
    int w = (x2 - x1 + 1);
    int h = (y2 - y1 + 1);
    Q_ASSERT(w >= 0);
    Q_ASSERT(h >= 0);

    QByteArray result(w * h, Qt::Uninitialized);
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++)
            result[(y - y1) * w + (x - x1)] = isValidCoord(x, y) ? at(x, y) : 0;
    }

    return result;
}

QByteArray GfxData::attrib(int x1, int y1, int x2, int y2) const
{
    int w = (x2 - x1 + 1);
    int h = (y2 - y1 + 1);
    Q_ASSERT(w >= 0);
    Q_ASSERT(h >= 0);

    QByteArray result(w * h, Qt::Uninitialized);
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++)
            result[(y - y1) * w + (x - x1)] = isValidCoord(x, y) ? attribAt(x, y, GfxColorMode::Multicolor) : 7;
    }

    return result;
}

void GfxData::setBytes(const QByteArray& data)
{
    Q_ASSERT(data.length() == mWidth * mHeight + ((mWidth + 7) >> 3) * mHeight);
    memcpy(mData.get(), data.constData(), mWidth * mHeight);
    memcpy(mAttrib.get(), data.constData() + mWidth * mHeight, ((mWidth + 7) >> 3) * mHeight);
}

void GfxData::setBytes(int x, int y, int w, int h, const QByteArray& data)
{
    Q_ASSERT(data.length() == w * h);
    for (int iy = 0; iy < h; iy++) {
        for (int ix = 0; ix < w; ix++) {
            int xx = x + ix;
            int yy = y + iy;
            if (isValidCoord(xx, yy))
                at(xx, yy) = data[iy * w + ix];
        }
    }
}

void GfxData::setAttrib(int x, int y, int w, int h, const QByteArray& data)
{
    Q_ASSERT(data.length() == w * h);
    for (int iy = 0; iy < h; iy++) {
        for (int ix = 0; ix < w; ix++) {
            int xx = x + ix;
            int yy = y + iy;
            if (isValidCoord(xx, yy))
                attribAt(xx, yy, GfxColorMode::Multicolor) = data[iy * w + ix];
        }
    }
}
