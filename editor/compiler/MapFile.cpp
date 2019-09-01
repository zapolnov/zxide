#include "MapFile.h"
#include <QDataStream>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

static const int FileFormatVersion = 1;

static const QString JsonKey_Version = QStringLiteral("version");
static const QString JsonKey_Format = QStringLiteral("format");
static const QString JsonKey_Width = QStringLiteral("width");
static const QString JsonKey_Height = QStringLiteral("height");
static const QString JsonKey_TileSet = QStringLiteral("tileset");
static const QString JsonKey_Tiles = QStringLiteral("tiles");
static const QString JsonValue_FormatNone = QStringLiteral("none");
static const QString JsonValue_FormatByteArray = QStringLiteral("bytearray");

MapFile::MapFile()
    : format(MapFormat::None)
{
}

MapFile::MapFile(const QByteArray& data)
    : MapFile()
{
    setData(data);
}

MapFile::~MapFile()
{
}

bool MapFile::deserializeFromJson(MapData* data)
{
    if (mFileData.isEmpty()) {
        format = MapFormat::None;
        data->resize(32, 24);
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
    if (fmt == JsonValue_FormatNone) format = MapFormat::None;
    else if (fmt == JsonValue_FormatByteArray) format = MapFormat::ByteArray;
    else {
        mLastError = QCoreApplication::tr("invalid format \"%1\".").arg(fmt);
        return false;
    }

    int width = root[JsonKey_Width].toInt();
    int height = root[JsonKey_Height].toInt();
    tileSetFile = root[JsonKey_TileSet].toString();
    QJsonArray tiles = root[JsonKey_Tiles].toArray();

    if (tiles.size() != height) {
        mLastError = QCoreApplication::tr("file is corrupt.");
        return false;
    }

    data->resize(width, height);
    data->clear();

    for (int y = 0; y < height; y++) {
        QJsonArray line = tiles[y].toArray();
        if (line.size() != width) {
            mLastError = QCoreApplication::tr("file is corrupt.");
            return false;
        }

        for (int x = 0; x < width; x++)
            data->at(x, y) = char(line[x].toInt() & 0xff);
    }

    return true;
}

void MapFile::serializeToJson(const MapData* data)
{
    QJsonDocument doc;
    QJsonObject root;

    root[JsonKey_Version] = FileFormatVersion;
    root[JsonKey_TileSet] = tileSetFile;
    root[JsonKey_Width] = data->width();
    root[JsonKey_Height] = data->height();

    switch (format) {
        case MapFormat::None: root[JsonKey_Format] = JsonValue_FormatNone; break;
        case MapFormat::ByteArray: root[JsonKey_Format] = JsonValue_FormatByteArray; break;
    }

    QJsonArray tiles;
    for (int y = 0; y < data->height(); y++) {
        QJsonArray line;
        for (int x = 0; x < data->width(); x++)
            line.append(data->at(x, y));
        tiles.append(line);
    }
    root[JsonKey_Tiles] = tiles;

    doc.setObject(root);
    mFileData = doc.toJson(QJsonDocument::Indented);
}

void MapFile::serializeToByteArray(const MapData* data)
{
    QDataStream stream(&mFileData, QIODevice::WriteOnly);
    for (int y = 0; y < data->height(); y++) {
        for (int x = 0; x < data->width(); x++)
            stream << quint8(data->at(x, y));
    }
}
