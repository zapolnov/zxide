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

    bool deserialize(GfxData* data);
    void serialize(const GfxData* data);

private:
    QString mLastError;
    QByteArray mFileData;

    Q_DISABLE_COPY(GfxFile);
};

#endif
