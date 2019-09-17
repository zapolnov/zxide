#ifndef COMPILER_MAPFILE_H
#define COMPILER_MAPFILE_H

#include "MapData.h"
#include <QString>

class MapFile
{
public:
    MapFormat format;
    QString tileSetFile;

    MapFile();
    explicit MapFile(const QByteArray& data);
    ~MapFile();

    const QString& lastError() const { return mLastError; }

    const QByteArray& data() const { return mFileData; }
    void setData(const QByteArray& data) { mFileData = data; }
    void clearData() { mFileData.clear(); }

    bool deserializeFromJson(MapData* data);
    void serializeToJson(const MapData* data);

    void serializeToByteArray(const MapData* data);

private:
    QString mLastError;
    QByteArray mFileData;

    Q_DISABLE_COPY(MapFile);
};

#endif
