#ifndef COMPILER_TILESETFILE_H
#define COMPILER_TILESETFILE_H

#include <QString>

class TileSetData;

class TileSetFile
{
public:
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
