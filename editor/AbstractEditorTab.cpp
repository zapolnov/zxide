#include "AbstractEditorTab.h"
#include "FileManager.h"
#include <QMessageBox>
#include <QPushButton>

AbstractEditorTab::AbstractEditorTab(QWidget* parent)
    : QWidget(parent)
    , mFileManager(nullptr)
    , mCurrentFile(nullptr)
{
}

AbstractEditorTab::~AbstractEditorTab()
{
}

void AbstractEditorTab::setCurrentFile(File* file)
{
    if (file == mCurrentFile)
        return;

    if (loadFile(file))
        mCurrentFile = file;
    else
        mCurrentFile = nullptr;

    if (mFileManager && mFileManager->selectedFileOrDirectory() != mCurrentFile)
        mFileManager->selectFileOrDirectory(mCurrentFile);

    updateUi();
}

bool AbstractEditorTab::canCreateFile() const
{
    return mFileManager != nullptr;
}

bool AbstractEditorTab::canCreateDirectory() const
{
    return mFileManager != nullptr;
}

bool AbstractEditorTab::canRenameFile() const
{
    return mFileManager && mFileManager->canRename();
}

bool AbstractEditorTab::canDeleteFile() const
{
    return mFileManager && mFileManager->canDelete();
}

bool AbstractEditorTab::canRefreshFileList() const
{
    return mFileManager != nullptr;
}

void AbstractEditorTab::createFile()
{
    if (mFileManager)
        mFileManager->createFile();
}

void AbstractEditorTab::createDirectory()
{
    if (mFileManager)
        mFileManager->createDirectory();
}

void AbstractEditorTab::renameFile()
{
    if (mFileManager)
        mFileManager->renameSelected();
}

void AbstractEditorTab::deleteFile()
{
    if (mFileManager)
        mFileManager->deleteSelected();
}

void AbstractEditorTab::refreshFileList()
{
    if (mFileManager)
        mFileManager->refresh();
}

void AbstractEditorTab::enumerateFiles(std::vector<File*>& files)
{
    if (mFileManager)
        mFileManager->enumerateFiles(files);
}

void AbstractEditorTab::setFileManager(FileManager* manager)
{
    if (mFileManager != manager) {
        mFileManager = manager;
        updateUi();
    }
}

void AbstractEditorTab::on_fileManager_updateUi()
{
    updateUi();
}

void AbstractEditorTab::on_fileManager_willRenameFile(File* file, bool* shouldAbort)
{
    if (!isFileModified(file))
        return;

    QMessageBox msgbox(QMessageBox::Warning,
        tr("Confirmation"), tr("Save changes to \"%1\"?").arg(file->name()), QMessageBox::NoButton, this);
    auto btnSave = msgbox.addButton(tr("Save"), QMessageBox::AcceptRole);
    auto btnDiscard = msgbox.addButton(tr("Discard"), QMessageBox::DestructiveRole);
    auto btnCancel = msgbox.addButton(tr("Cancel"), QMessageBox::RejectRole);
    msgbox.setDefaultButton(btnCancel);
    msgbox.setEscapeButton(btnCancel);
    msgbox.exec();

    auto clicked = msgbox.clickedButton();
    if (clicked == btnSave) {
        if (!saveFile(file))
            *shouldAbort = true;
    } else if (clicked != btnDiscard)
        *shouldAbort = true;
}

void AbstractEditorTab::on_fileManager_fileSelected(File* file)
{
    setCurrentFile(file);
}

void AbstractEditorTab::on_fileManager_fileDisappeared(File* file)
{
    removeFile(file);
    if (mCurrentFile == file)
        on_fileManager_fileSelected(nullptr);
    updateUi();
}
