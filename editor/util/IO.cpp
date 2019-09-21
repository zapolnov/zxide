#include "IO.h"
#include <QSaveFile>
#include <QFile>
#include <QCoreApplication>
#include <QJsonDocument>

QByteArray loadFile(const QString& file)
{
    QFile f(file);
    if (!f.open(QFile::ReadOnly))
        throw IOException(QCoreApplication::tr("Unable to open file \"%1\": %2").arg(file).arg(f.errorString()));
    return f.readAll();
}

QJsonDocument loadJson(const QString& file)
{
    QByteArray json = loadFile(file);

    QJsonParseError error;
    auto doc = QJsonDocument::fromJson(json, &error);
    if (doc.isNull())
        throw IOException(QCoreApplication::tr("Unable to read file \"%1\": %2").arg(file).arg(error.errorString()));

    return doc;
}

void saveFile(const QString& file, const QByteArray& data)
{
    saveFile(file, data.constData(), size_t(data.length()));
}

void saveFile(const QString& file, const void* data, size_t size)
{
    if (QFile::exists(file))
        throw IOException(QCoreApplication::tr("File \"%1\" already exists.").arg(file));

    QSaveFile f(file);
    if (!f.open(QFile::WriteOnly))
        throw IOException(QCoreApplication::tr("Unable to write file \"%1\": %2").arg(file).arg(f.errorString()));

    qint64 bytesWritten = f.write(reinterpret_cast<const char*>(data), qint64(size));
    if (bytesWritten < 0)
        throw IOException(QCoreApplication::tr("Unable to write file \"%1\": %2").arg(file).arg(f.errorString()));
    if (bytesWritten != qint64(size))
        throw IOException(QCoreApplication::tr("Unable to write file \"%1\".").arg(file));

    if (!f.commit())
        throw IOException(QCoreApplication::tr("Unable to write file \"%1\": %2").arg(file).arg(f.errorString()));
}

void saveJson(const QString& file, const QJsonDocument& doc)
{
    saveFile(file, doc.toJson(QJsonDocument::Indented));
}
