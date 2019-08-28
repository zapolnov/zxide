#include "AbstractEditorTab.h"
#include "FileManager.h"
#include <QMessageBox>
#include <QFile>
#include <QSaveFile>

AbstractEditorTab::AbstractEditorTab(QWidget* parent)
    : QWidget(parent)
    , mFile(nullptr)
{
}

AbstractEditorTab::~AbstractEditorTab()
{
}

QByteArray AbstractEditorTab::loadFileData(File* file)
{
    Q_ASSERT(file != nullptr);
    if (!file) {
        QMessageBox::critical(this, tr("Internal Error"), tr("File is NULL."));
        return QByteArray();
    }

    mFile = file;

    QFile f(file->fileInfo().absoluteFilePath());
    if (!f.open(QFile::ReadOnly)) {
        QMessageBox::critical(this,
            tr("Error"), tr("Unable to open file \"%1\": %2").arg(f.fileName()).arg(f.errorString()));
        return QByteArray();
    }

    return f.readAll();
}

bool AbstractEditorTab::writeFileData(const QByteArray& data)
{
    Q_ASSERT(mFile != nullptr);
    if (!mFile) {
        QMessageBox::critical(this, tr("Internal Error"), tr("File is not open."));
        return false;
    }

    QSaveFile f(mFile->fileInfo().absoluteFilePath());
    if (!f.open(QFile::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to save file \"%1\": %2").arg(f.fileName()).arg(f.errorString()));
        return false;
    }

    qint64 bytesWritten = f.write(data.constData(), data.length());
    if (bytesWritten < 0) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(f.fileName()).arg(f.errorString()));
        return false;
    }

    if (bytesWritten != data.length()) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\".").arg(f.fileName()));
        return false;
    }

    if (!f.commit()) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to save file \"%1\": %2").arg(f.fileName()).arg(f.errorString()));
        return false;
    }

    return true;
}
