#include "Project.h"
#include <QSaveFile>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

const QString Project::FileSuffix = QStringLiteral("zxprj");
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
    mDir.mkpath(QStringLiteral("built"));
    return mDir.absoluteFilePath(QStringLiteral("built/%1.tap")).arg(name());
}

bool Project::create(const QString& file)
{
    QSaveFile f(file);
    if (!f.open(QFile::WriteOnly)) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(file).arg(f.errorString()));
        return false;
    }

    QJsonDocument doc;
    QJsonObject root;
    root[JsonKey_Version] = FileFormatVersion;
    doc.setObject(root);
    QByteArray json = doc.toJson(QJsonDocument::Indented);

    qint64 bytesWritten = f.write(json);
    if (bytesWritten < 0) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(file).arg(f.errorString()));
        return false;
    }
    if (bytesWritten != json.length()) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to write file \"%1\".").arg(file));
        return false;
    }

    if (!f.commit()) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(file).arg(f.errorString()));
        return false;
    }

    mFile = file;
    mDir = QDir(QFileInfo(file).absolutePath());

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
