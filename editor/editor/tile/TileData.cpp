#include "TileData.h"
#include <cstring>

TileData::TileData(int w, int h, QObject* parent)
    : QObject(parent)
    , mData(new char[w * h])
    , mWidth(w)
    , mHeight(h)
{
    clear();
}

TileData::~TileData()
{
}

void TileData::resize(int w, int h)
{
    Q_ASSERT(w > 0);
    Q_ASSERT(h > 0);

    std::unique_ptr<char[]> newData{new char[w * h]};
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            newData[y * w + x] = (isValidCoord(x, y) ? at(x, y) : 0);
    }

    mData = std::move(newData);
    mWidth = w;
    mHeight = h;

    emit sizeChanged();
}

bool TileData::isValidCoord(int x, int y) const
{
    return (x >= 0 && y >= 0 && x < mWidth && y < mHeight);
}

bool TileData::isValidCoord(const QPoint& pt) const
{
    return isValidCoord(pt.x(), pt.y());
}

char TileData::at(int x, int y) const
{
    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y))
        return 0;

    return mData[y * mWidth + x];
}

char TileData::at(const QPoint& p) const
{
    return at(p.x(), p.y());
}

char& TileData::at(int x, int y)
{
    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y)) {
        static char dummy;
        dummy = 0;
        return dummy;
    }

    return mData[y * mWidth + x];
}

char& TileData::at(const QPoint& p)
{
    return at(p.x(), p.y());
}

void TileData::clear()
{
    memset(mData.get(), 0, mWidth * mHeight);
}

void TileData::clear(int x1, int y1, int x2, int y2)
{
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++)
            at(x, y) = 0;
    }
}

QByteArray TileData::bytes() const
{
    return QByteArray(mData.get(), mWidth * mHeight);
}

QByteArray TileData::bytes(int x1, int y1, int x2, int y2) const
{
    int w = (x2 - x1 + 1);
    int h = (y2 - y1 + 1);

    QByteArray result(w * h, Qt::Uninitialized);
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++)
            result[(y - y1) * w + (x - x1)] = isValidCoord(x, y) ? at(x, y) : 0;
    }

    return result;
}

void TileData::setBytes(const QByteArray& data)
{
    Q_ASSERT(data.length() == mWidth * mHeight);
    memcpy(mData.get(), data.constData(), mWidth * mHeight);
}

void TileData::setBytes(int x, int y, int w, int h, const QByteArray& data)
{
    for (int iy = 0; iy < h; iy++) {
        for (int ix = 0; ix < w; ix++) {
            int xx = x + ix;
            int yy = y + iy;
            if (isValidCoord(xx, yy))
                at(xx, yy) = data[iy * w + ix];
        }
    }
}
