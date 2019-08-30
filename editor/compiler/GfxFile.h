#ifndef COMPILER_GFXFILE_H
#define COMPILER_GFXFILE_H

#include "GfxData.h"
#include <QString>

class GfxFile
{
public:
    GfxFormat format;
    GfxColorMode colorMode;

    GfxFile();
    explicit GfxFile(const QByteArray& data);
    ~GfxFile();

    const QString& lastError() const { return mLastError; }

    const QByteArray& data() const { return mFileData; }
    void setData(const QByteArray& data) { mFileData = data; }

    bool deserializeFromJson(GfxData* data);
    void serializeToJson(const GfxData* data);

    void serializeToBTile16(const GfxData* data);

private:
    QString mLastError;
    QByteArray mFileData;

    Q_DISABLE_COPY(GfxFile);
};

#endif
