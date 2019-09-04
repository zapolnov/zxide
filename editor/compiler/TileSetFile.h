#ifndef COMPILER_TILESETFILE_H
#define COMPILER_TILESETFILE_H

#include <QString>

class TileSetData;

class TileSetFile
{
public:
    static const int MinTileWidth = 8;
    static const int MinTileHeight = 8;
    static const int MaxTileWidth = 64;
    static const int MaxTileHeight = 64;

    TileSetFile();
    explicit TileSetFile(const QByteArray& data);
    ~TileSetFile();

    const QString& lastError() const { return mLastError; }

    const QByteArray& data() const { return mFileData; }
    void setData(const QByteArray& data) { mFileData = data; }

    bool deserializeFromJson(TileSetData* data);
    void serializeToJson(const TileSetData* data);

private:
    QString mLastError;
    QByteArray mFileData;

    Q_DISABLE_COPY(TileSetFile);
};

#endif
