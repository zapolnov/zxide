#include "MapData.h"
#include <cstring>

MapData::MapData(int w, int h, QObject* parent)
    : QObject(parent)
    , mData(new unsigned char[w * h])
    , mEntities(new std::string[w * h])
    , mWidth(w)
    , mHeight(h)
{
    clear();
}

MapData::~MapData()
{
}

void MapData::resize(int w, int h)
{
    Q_ASSERT(w > 0);
    Q_ASSERT(h > 0);

    if (mWidth == w && mHeight == h)
        return;

    std::unique_ptr<unsigned char[]> newData{new unsigned char[w * h]};
    std::unique_ptr<std::string[]> newEntities{new std::string[w * h]};

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            newData[y * w + x] = (isValidCoord(x, y) ? at(x, y) : 0);
            newEntities[y * w + x] = (isValidCoord(x, y) ? entityAt(x, y) : std::string());
        }
    }

    mData = std::move(newData);
    mEntities = std::move(newEntities);
    mWidth = w;
    mHeight = h;

    emit sizeChanged();
}

bool MapData::isValidCoord(int x, int y) const
{
    return (x >= 0 && y >= 0 && x < mWidth && y < mHeight);
}

bool MapData::isValidCoord(const QPoint& pt) const
{
    return isValidCoord(pt.x(), pt.y());
}

unsigned char MapData::at(int x, int y) const
{
    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y))
        return 0;

    return mData[y * mWidth + x];
}

unsigned char MapData::at(const QPoint& p) const
{
    return at(p.x(), p.y());
}

unsigned char& MapData::at(int x, int y)
{
    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y)) {
        static unsigned char dummy;
        dummy = 0;
        return dummy;
    }

    return mData[y * mWidth + x];
}

unsigned char& MapData::at(const QPoint& p)
{
    return at(p.x(), p.y());
}

const std::string& MapData::entityAt(int x, int y) const
{
    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y)) {
        static const std::string empty;
        return empty;
    }

    return mEntities[y * mWidth + x];
}

const std::string& MapData::entityAt(const QPoint& p) const
{
    return entityAt(p.x(), p.y());
}

std::string& MapData::entityAt(int x, int y)
{
    Q_ASSERT(isValidCoord(x, y));
    if (!isValidCoord(x, y)) {
        static std::string dummy;
        dummy.clear();
        return dummy;
    }

    return mEntities[y * mWidth + x];
}

std::string& MapData::entityAt(const QPoint& p)
{
    return entityAt(p.x(), p.y());
}

void MapData::clear()
{
    memset(mData.get(), 0, mWidth * mHeight);
    for (int i = 0; i < mWidth * mHeight; i++)
        mEntities[i].clear();
}

void MapData::clear(int x1, int y1, int x2, int y2)
{
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            at(x, y) = 0;
            entityAt(x, y).clear();
        }
    }
}

QByteArray MapData::bytes() const
{
    return bytes(0, 0, mWidth, mHeight);
}

QByteArray MapData::bytes(int x1, int y1, int x2, int y2) const
{
    int w = (x2 - x1 + 1);
    int h = (y2 - y1 + 1);

    QByteArray result(w * h * 5, Qt::Uninitialized);
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++)
            result[(y - y1) * w + (x - x1)] = isValidCoord(x, y) ? at(x, y) : 0;
    }

    QByteArray strings;
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            qint32 index;
            const auto& e = entityAt(x, y);
            if (!isValidCoord(x, y) || e.empty())
                index = -1;
            else {
                index = strings.length();
                strings.append(e.data(), int(e.length() + 1));
            }

            int offset = w * h + ((y - y1) * w + (x - x1)) * 4;
            result[offset+0] = index & 0xff;
            result[offset+1] = (index >>  8) & 0xff;
            result[offset+2] = (index >> 16) & 0xff;
            result[offset+3] = (index >> 24) & 0xff;
        }
    }

    return result + strings;
}

void MapData::setBytes(const QByteArray& data)
{
    setBytes(0, 0, mWidth, mHeight, data);
}

void MapData::setBytes(int x, int y, int w, int h, const QByteArray& data)
{
    for (int iy = 0; iy < h; iy++) {
        for (int ix = 0; ix < w; ix++) {
            int xx = x + ix;
            int yy = y + iy;
            if (isValidCoord(xx, yy))
                at(xx, yy) = data[iy * w + ix];
        }
    }

    for (int iy = 0; iy < h; iy++) {
        for (int ix = 0; ix < w; ix++) {
            int xx = x + ix;
            int yy = y + iy;
            if (isValidCoord(xx, yy)) {
                qint32 index;
                int offset = w * h + (iy * w + ix) * 4;
                index  = qint32(data[offset+0]);
                index |= qint32(data[offset+1]) <<  8;
                index |= qint32(data[offset+2]) << 16;
                index |= qint32(data[offset+3]) << 24;
                if (index == -1)
                    entityAt(xx, yy).clear();
                else
                    entityAt(xx, yy) = data.constData() + w * h * 5 + index;
            }
        }
    }
}
