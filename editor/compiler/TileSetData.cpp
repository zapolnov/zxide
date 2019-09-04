#include "TileSetData.h"

TileSetData::TileSetData(QObject* parent)
    : QObject(parent)
    , tileWidth(8)
    , tileHeight(8)
{
}

TileSetData::~TileSetData()
{
}

void TileSetData::clear()
{
    mTiles.clear();
}

QString TileSetData::tileAt(int x, int y) const
{
    auto it = mTiles.find(std::make_pair(x, y));
    return (it != mTiles.end() ? it->second : QString());
}

void TileSetData::setTileAt(int x, int y, const QString& tile)
{
    mTiles[std::make_pair(x, y)] = tile;
}
