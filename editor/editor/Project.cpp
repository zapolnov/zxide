#include "Project.h"
#include "compiler/ProjectSettings.h"
#include "compiler/IO.h"
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

const QString Project::FileSuffix = QStringLiteral("zxprj");
const QString Project::GeneratedDirectory = QStringLiteral("generated");
const QString Project::OutDirectory = QStringLiteral("_out");
const QString Project::PortDirectory = QStringLiteral("_port");

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

QString Project::diskFileName() const
{
    mDir.mkpath(OutDirectory);
    return mDir.absoluteFilePath(QStringLiteral("%1/%2.scl")).arg(OutDirectory).arg(name());
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
    try {
        QFileInfo fileInfo(file);
        QDir dir(fileInfo.absolutePath());

        QString gitignore = QStringLiteral("/%1/\n/%2/\n").arg(OutDirectory).arg(GeneratedDirectory);
        saveFile(dir.absoluteFilePath(QStringLiteral(".gitignore")), gitignore.toUtf8(), false);

        QByteArray loader =
            "10 CLEAR @{clearaddr}\n"
            "20 POKE 23610, 255\n"
            "30 LOAD \"\" CODE\n"
            "40 RANDOMIZE USR @{baseaddr}\n";
        saveFile(dir.absoluteFilePath(QStringLiteral("loader.bas")), loader, false);

        QByteArray mainAsm =
            "section main [base 0x8000]\n"
            "ret\n";
        saveFile(dir.absoluteFilePath(QStringLiteral("main.asm")), mainAsm, false);

        ProjectSettings settings;
        settings.save(file);

        mFile = file;
        mDir = dir;
    } catch (const IOException& e) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"), e.message());
        return false;
    }

    return true;
}

bool Project::load(const QString& file)
{
    try {
        ProjectSettings settings;
        settings.load(file);

        mFile = file;
        mDir = QDir(QFileInfo(file).absolutePath());
    } catch (const IOException& e) {
        QMessageBox::critical(static_cast<QWidget*>(parent()), tr("Error"), e.message());
        return false;
    }

    return true;
}
