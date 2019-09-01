#include "Project.h"
#include <QSaveFile>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

const QString Project::FileSuffix = QStringLiteral("zxprj");
const QString Project::GeneratedDirectory = QStringLiteral("generated");
const QString Project::OutDirectory = QStringLiteral("_out");
static const QString JsonKey_Version = QStringLiteral("version");
static const int FileFormatVersion = 1;

Project::Project(QWidget* parent)
    : QObject(parent)
{
}

Project::~Project()
{
}

QString Project::name() const
{
    return QFileInfo(mFile).completeBaseName();
}

QString Project::tapeFileName() const
{
    mDir.mkpath(OutDirectory);
    return mDir.absoluteFilePath(QStringLiteral("%1/%2.tap")).arg(OutDirectory).arg(name());
}

QString Project::wavFileName() const
{
    mDir.mkpath(OutDirectory);
    return mDir.absoluteFilePath(QStringLiteral("%1/%2.wav")).arg(OutDirectory).arg(name());
}

QDir Project::generatedFilesDirectory() const
{
    return mDir.absoluteFilePath(GeneratedDirectory);
}

bool Project::create(const QString& file)
{
    QFileInfo fileInfo(file);
    QDir dir(fileInfo.absolutePath());

    QString gitignore = QStringLiteral("/%1/\n/%2/\n").arg(OutDirectory).arg(GeneratedDirectory);
    if (!writeFile(dir.absoluteFilePath(QStringLiteral(".gitignore")), gitignore.toUtf8()))
        return false;

    QByteArray loader =
        "10 CLEAR @{clearaddr}\n"
        "20 POKE 23610, 255\n"
        "30 LOAD \"\" CODE\n"
        "40 RANDOMIZE USR @{baseaddr}\n";
    if (!writeFile(dir.absoluteFilePath(QStringLiteral("loader.bas")), loader))
        return false;

    QByteArray mainAsm =
        "section main [base 0x8000]\n"
        "ret\n";
    if (!writeFile(dir.absoluteFilePath(QStringLiteral("main.asm")), loader))
        return false;

    QJsonDocument doc;
    QJsonObject root;
    root[JsonKey_Version] = FileFormatVersion;
    doc.setObject(root);
    QByteArray json = doc.toJson(QJsonDocument::Indented);
    if (!writeFile(file, json))
        return false;

    mFile = file;
    mDir = dir;
    return true;
}

bool Project::load(const QString& file)
{
    QFile f(file);
    if (!f.open(QFile::ReadOnly)) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to open file \"%1\": %2").arg(file).arg(f.errorString()));
        return false;
    }

    QByteArray json = f.readAll();
    f.close();

    QJsonParseError error;
    auto doc = QJsonDocument::fromJson(json, &error);
    if (doc.isNull()) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to read file \"%1\": %2").arg(file).arg(error.errorString()));
        return false;
    }

    QJsonObject root = doc.object();
    int formatVersion = root[JsonKey_Version].toInt();
    if (formatVersion < 1 || formatVersion > FileFormatVersion) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to read file \"%1\": file has unsupported format.").arg(file));
        return false;
    }

    mFile = file;
    mDir = QDir(QFileInfo(file).absolutePath());

    return true;
}

bool Project::writeFile(const QString& file, const QByteArray& data)
{
    return writeFile(file, data.constData(), data.length());
}

bool Project::writeFile(const QString& file, const void* data, int length)
{
    if (QFile::exists(file)) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("File \"%1\" already exists.").arg(file));
        return false;
    }

    QSaveFile f(file);
    if (!f.open(QFile::WriteOnly)) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(file).arg(f.errorString()));
        return false;
    }

    qint64 bytesWritten = f.write(reinterpret_cast<const char*>(data), qint64(length));
    if (bytesWritten < 0) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(file).arg(f.errorString()));
        return false;
    }
    if (bytesWritten != qint64(length)) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to write file \"%1\".").arg(file));
        return false;
    }

    if (!f.commit()) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(file).arg(f.errorString()));
        return false;
    }

    return true;
}
