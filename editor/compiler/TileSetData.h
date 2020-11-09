#ifndef EDITOR_COMPILER_TILESETDATA_H
#define EDITOR_COMPILER_TILESETDATA_H

#include <QObject>
#include <QPoint>
#include <map>

class TileSetData : public QObject
{
    Q_OBJECT

public:
    static const int GridWidth = 16;
    static const int GridHeight = 18;

    class Iterator
    {
    public:
        explicit Iterator(std::map<std::pair<int, int>, QString>::const_iterator it) : mIterator(it) {}

        int x() const { return mIterator->first.first; }
        int y() const { return mIterator->first.second; }
        const QString& file() const { return mIterator->second; }

        Iterator& operator*() { return *this; }
        Iterator& operator++() { ++mIterator; return *this; }

        bool operator==(const Iterator& other) const { return mIterator == other.mIterator; }
        bool operator!=(const Iterator& other) const { return mIterator != other.mIterator; }

    private:
        std::map<std::pair<int, int>, QString>::const_iterator mIterator;
    };

    int tileWidth;
    int tileHeight;

    explicit TileSetData(QObject* parent = nullptr);
    ~TileSetData() override;

    void clear();

    Iterator begin() const { return Iterator(mTiles.begin()); }
    Iterator end() const { return Iterator(mTiles.end()); }

    QString tileAt(int x, int y) const;
    void setTileAt(int x, int y, const QString& tile);

private:
    std::map<std::pair<int, int>, QString> mTiles;

    Q_DISABLE_COPY(TileSetData)
};

#endif
