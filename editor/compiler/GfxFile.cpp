#include "GfxFile.h"
#include <QDataStream>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

static const int FileFormatVersion = 1;

static const QString JsonKey_Version = QStringLiteral("version");
static const QString JsonKey_Format = QStringLiteral("format");
static const QString JsonKey_ColorMode = QStringLiteral("color_mode");
static const QString JsonKey_Width = QStringLiteral("width");
static const QString JsonKey_Height = QStringLiteral("height");
static const QString JsonKey_Pixels = QStringLiteral("pixels");
static const QString JsonKey_Attribs = QStringLiteral("attribs");
static const QString JsonValue_ColorModeStandard = QStringLiteral("standard");
static const QString JsonValue_ColorModeMulticolor = QStringLiteral("multicolor");
static const QString JsonValue_ColorModeBicolor = QStringLiteral("bicolor");
static const QString JsonValue_FormatNone = QStringLiteral("none");
static const QString JsonValue_FormatBTile16 = QStringLiteral("btile16");

GfxFile::GfxFile()
    : format(GfxFormat::None)
    , colorMode(GfxColorMode::Standard)
{
}

GfxFile::GfxFile(const QByteArray& data)
    : GfxFile()
{
    setData(data);
}

GfxFile::~GfxFile()
{
}

bool GfxFile::deserializeFromJson(GfxData* data)
{
    if (mFileData.isEmpty()) {
        format = GfxFormat::None;
        colorMode = GfxColorMode::Standard;
        data->resize(8, 8);
        data->clear();
        return true;
    }

    QJsonParseError error;
    auto doc = QJsonDocument::fromJson(mFileData, &error);
    if (doc.isNull()) {
        mLastError = error.errorString();
        return false;
    }

    QJsonObject root = doc.object();
    int formatVersion = root[JsonKey_Version].toInt();
    if (formatVersion < 1 || formatVersion > FileFormatVersion) {
        mLastError = QCoreApplication::tr("file has unsupported version.");
        return false;
    }

    QString fmt = root[JsonKey_Format].toString();
    if (fmt == JsonValue_FormatNone) format = GfxFormat::None;
    else if (fmt == JsonValue_FormatBTile16) format = GfxFormat::BTile16;
    else {
        mLastError = QCoreApplication::tr("invalid format \"%1\".").arg(fmt);
        return false;
    }

    QString mode = root[JsonKey_ColorMode].toString();
    if (mode == JsonValue_ColorModeStandard) colorMode = GfxColorMode::Standard;
    if (mode == JsonValue_ColorModeMulticolor) colorMode = GfxColorMode::Multicolor;
    if (mode == JsonValue_ColorModeBicolor) colorMode = GfxColorMode::Bicolor;
    else {
        mLastError = QCoreApplication::tr("invalid color mode \"%1\".").arg(mode);
        return false;
    }

    int width = root[JsonKey_Width].toInt();
    int height = root[JsonKey_Height].toInt();
    QJsonArray pixels = root[JsonKey_Pixels].toArray();
    QJsonArray attribs = root[JsonKey_Attribs].toArray();

    if (pixels.size() != height || attribs.size() != height) {
        mLastError = QCoreApplication::tr("file is corrupt.");
        return false;
    }

    data->resize(width, height);
    data->clear();

    for (int y = 0; y < height; y++) {
        const QString& str = pixels[y].toString();
        if (str.length() != width) {
            mLastError = QCoreApplication::tr("file is corrupt.");
            return false;
        }

        for (int x = 0; x < width; x++) {
            QChar ch = str[x];
            if (ch == '#')
                data->at(x, y) = 1;
            else if (ch == '.')
                data->at(x, y) = 0;
            else {
                mLastError = QCoreApplication::tr("file is corrupt.");
                return false;
            }
        }

        QJsonArray lineAttribs = attribs[y].toArray();
        if (lineAttribs.size() != ((width + 7) >> 3)) {
            mLastError = QCoreApplication::tr("file is corrupt.");
            return false;
        }

        for (int x = 0, i = 0; x < width; x += 8, i++)
            data->attribAt(x, y, GfxColorMode::Multicolor) = char(lineAttribs[i].toInt() & 0xff);
    }

    return true;
}

void GfxFile::serializeToJson(const GfxData* data)
{
    QJsonDocument doc;
    QJsonObject root;

    root[JsonKey_Version] = FileFormatVersion;
    root[JsonKey_Width] = data->width();
    root[JsonKey_Height] = data->height();

    switch (format) {
        case GfxFormat::None: root[JsonKey_Format] = JsonValue_FormatNone; break;
        case GfxFormat::BTile16: root[JsonKey_Format] = JsonValue_FormatBTile16; break;
    }

    switch (colorMode) {
        case GfxColorMode::Standard: root[JsonKey_ColorMode] = JsonValue_ColorModeStandard; break;
        case GfxColorMode::Multicolor: root[JsonKey_ColorMode] = JsonValue_ColorModeMulticolor; break;
        case GfxColorMode::Bicolor: root[JsonKey_ColorMode] = JsonValue_ColorModeBicolor; break;
    }

    QJsonArray pixels;
    for (int y = 0; y < data->height(); y++) {
        QString str(data->width(), '?');
        for (int x = 0; x < data->width(); x++)
            str[x] = (data->at(x, y) ? '#' : '.');
        pixels.append(str);
    }
    root[JsonKey_Pixels] = pixels;

    QJsonArray attribs;
    for (int y = 0; y < data->height(); y++) {
        QJsonArray lineAttribs;
        for (int x = 0; x < data->width(); x += 8)
            lineAttribs.append(data->attribAt(x, y, GfxColorMode::Multicolor));
        attribs.append(lineAttribs);
    }
    root[JsonKey_Attribs] = attribs;

    doc.setObject(root);
    mFileData = doc.toJson(QJsonDocument::Indented);
}

void GfxFile::serializeToBTile16(const GfxData* data)
{
    QDataStream stream(&mFileData, QIODevice::WriteOnly);

    for (int y = 0; y < data->height(); y++) {
        for (int x = 0; x < data->width(); ) {
            unsigned char byte = 0;
            for (int i = 0; i < 8; i++, x++) {
                char value = data->at(x, y);
                if (value)
                    byte |= (0x80 >> i);
            }
            stream << quint8(byte);
        }
    }

    for (int x = 0; x < data->width(); x += 8) {
        for (int y = 0; y < data->height(); y += 2)
            stream << quint8(data->attribAt(x, y, GfxColorMode::Bicolor));
    }
}
