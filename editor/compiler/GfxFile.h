#ifndef COMPILER_GFXFILE_H
#define COMPILER_GFXFILE_H

#include "GfxData.h"
#include <QString>

class GfxFile
{
public:
    static const int MinWidth = 8;
    static const int MinHeight = 8;
    static const int MaxWidth = 256;
    static const int MaxHeight = 192;

    GfxFormat format;
    GfxColorMode colorMode;

    GfxFile();
    explicit GfxFile(const QByteArray& data);
    ~GfxFile();

    const QString& lastError() const { return mLastError; }

    const QByteArray& data() const { return mFileData; }
    void setData(const QByteArray& data) { mFileData = data; }
    void clearData() { mFileData.clear(); }

    bool deserializeFromJson(GfxData* data);
    void serializeToJson(const GfxData* data);

    void serializeToMonochrome(const GfxData* data);
    void serializeToStandard(const GfxData* data);
    void serializeToStandardAttributes(const GfxData* data);
    void serializeToBTile16(const GfxData* data);
    void serializeToBTile16Attributes(const GfxData* data);

private:
    QString mLastError;
    QByteArray mFileData;

    Q_DISABLE_COPY(GfxFile);
};

#endif
