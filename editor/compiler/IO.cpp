#include "IO.h"
#include "IErrorReporter.h"
#include <QSaveFile>
#include <QFile>
#include <QFileInfo>
#include <QDir>
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

bool writeFile(const QString& fileName, const std::string& str, IErrorReporter* reporter)
{
    return writeFile(fileName, str.data(), str.length(), reporter);
}

bool writeFile(const QString& fileName, const void* data, size_t size, IErrorReporter* reporter)
{
    QFileInfo info(fileName);
    QDir dir = info.path();
    dir.mkpath(QStringLiteral("."));

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        reporter->error(nullptr, 0, QCoreApplication::tr("unable to write file '%1': %2")
            .arg(fileName).arg(file.errorString()));
        QFile::remove(fileName);
        return false;
    }

    qint64 bytesWritten = file.write(reinterpret_cast<const char*>(data), qint64(size));
    if (bytesWritten < 0) {
        reporter->error(nullptr, 0, QCoreApplication::tr("unable to write file '%1': %2")
            .arg(fileName).arg(file.errorString()));
        file.close();
        QFile::remove(fileName);
        return false;
    }

    if (bytesWritten != qint64(size)) {
        reporter->error(nullptr, 0, QCoreApplication::tr("unable to write file '%1'").arg(fileName));
        file.close();
        QFile::remove(fileName);
        return false;
    }

    if (!file.flush()) {
        reporter->error(nullptr, 0, QCoreApplication::tr("unable to write file '%1': %2")
            .arg(fileName).arg(file.errorString()));
        file.close();
        QFile::remove(fileName);
        return false;
    }

    return true;
}

void saveFile(const QString& file, const QByteArray& data, bool canOverwrite)
{
    saveFile(file, data.constData(), size_t(data.length()), canOverwrite);
}

void saveFile(const QString& file, const void* data, size_t size, bool canOverwrite)
{
    if (!canOverwrite && QFile::exists(file))
        throw IOException(QCoreApplication::tr("File \"%1\" already exists.").arg(file));

    QFileInfo info(file);
    QDir dir = info.path();
    dir.mkpath(QStringLiteral("."));

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
