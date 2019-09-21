#include "AbstractEditorTab.h"
#include "FileManager.h"
#include "util/IO.h"
#include <QMessageBox>

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

    try {
        return ::loadFile(file->fileInfo().absoluteFilePath());
    } catch (const IOException& e) {
        QMessageBox::critical(this, tr("Error"), e.message());
        return QByteArray();
    }
}

bool AbstractEditorTab::writeFileData(const QByteArray& data)
{
    Q_ASSERT(mFile != nullptr);
    if (!mFile) {
        QMessageBox::critical(this, tr("Internal Error"), tr("File is not open."));
        return false;
    }

    try {
        saveFile(mFile->fileInfo().absoluteFilePath(), data);
    } catch (const IOException& e) {
        QMessageBox::critical(this, tr("Error"), e.message());
        return false;
    }

    return true;
}
