#include "TileSetFile.h"
#include "TileSetData.h"
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

static const int FileFormatVersion = 1;

static const QString JsonKey_Version = QStringLiteral("version");
static const QString JsonKey_Tiles = QStringLiteral("tiles");
static const QString JsonKey_X = QStringLiteral("x");
static const QString JsonKey_Y = QStringLiteral("y");
static const QString JsonKey_File = QStringLiteral("file");

TileSetFile::TileSetFile()
{
}

TileSetFile::TileSetFile(const QByteArray& data)
    : TileSetFile()
{
    setData(data);
}

TileSetFile::~TileSetFile()
{
}

bool TileSetFile::deserializeFromJson(TileSetData* data)
{
    if (mFileData.isEmpty()) {
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

    data->clear();

    QJsonArray tiles = root[JsonKey_Tiles].toArray();
    int n = tiles.count();
    for (int i = 0; i < n; i++) {
        QJsonObject item = tiles[i].toObject();
        int x = item[JsonKey_X].toInt();
        int y = item[JsonKey_Y].toInt();
        QString file = item[JsonKey_File].toString();
        data->setTileAt(x, y, file);
    }

    return true;
}

void TileSetFile::serializeToJson(const TileSetData* data)
{
    QJsonDocument doc;
    QJsonObject root;

    root[JsonKey_Version] = FileFormatVersion;

    QJsonArray tiles;
    for (const auto& it : *data) {
        QJsonObject obj;
        obj[JsonKey_X] = it.x();
        obj[JsonKey_Y] = it.y();
        obj[JsonKey_File] = it.file();
        tiles.append(obj);
    }
    root[JsonKey_Tiles] = tiles;

    doc.setObject(root);
    mFileData = doc.toJson(QJsonDocument::Indented);
}
