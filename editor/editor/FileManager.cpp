#include "FileManager.h"
#include "editor/EditorTabFactory.h"
#include "editor/AbstractEditorTab.h"
#include "ui_FileManager.h"
#include <QMenu>
#include <QDir>
#include <QDirIterator>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>

FileOrDirectory::FileOrDirectory(const QIcon& icon, const QFileInfo& fileInfo, int type, QTreeWidgetItem* parent)
    : QTreeWidgetItem(parent, QStringList() << fileInfo.fileName(), type)
    , mFileInfo(fileInfo)
{
    setIcon(0, icon);
}

Directory* FileOrDirectory::parentDirectory() const
{
    auto item = parent();
    if (item == nullptr)
        return nullptr;

    if (item->type() == Directory::Type)
        return static_cast<Directory*>(item);

    return nullptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

File::File(const QIcon& icon, const QFileInfo& fileInfo, QTreeWidgetItem* parent)
    : FileOrDirectory(icon, fileInfo, Type, parent)
    , mTab(nullptr)
{
}

AbstractEditorTab* File::createTab(QWidget* parent)
{
    Q_ASSERT(mTab == nullptr);
    mTab = EditorTabFactory::instance()->createTabForFile(this, parent);
    return mTab;
}

void File::destroyTab()
{
    if (mTab) {
        mTab->deleteLater();
        mTab = nullptr;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Directory::Directory(const QIcon& icon, const QFileInfo& fileInfo, QTreeWidgetItem* parent)
    : FileOrDirectory(icon, fileInfo, Type, parent)
{
}

Directory* Directory::directory(const QString& name) const
{
    auto it = mDirectories.find(name);
    return (it != mDirectories.end() ? it.value() : nullptr);
}

File* Directory::file(const QString& name) const
{
    auto it = mFiles.find(name);
    return (it != mFiles.end() ? it.value() : nullptr);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FileManager::FileManager(QWidget* parent)
    : QWidget(parent)
    , mUi(new Ui_FileManager)
    , mFolderIcon(QStringLiteral(":/resources/fatcow16x16/folder.png"))
    , mFileIcon(QStringLiteral(":/resources/fatcow16x16/page_white.png"))
    , mRootDirectory(nullptr)
{
    mUi->setupUi(this);
    mUi->sourcesTree->setContextMenuPolicy(Qt::CustomContextMenu);
}

FileManager::~FileManager()
{
}

void FileManager::init(const QString& path)
{
    mPath = QDir::cleanPath(QDir(path).absolutePath());
    mRootDirectory = new Directory(mFolderIcon, QFileInfo(mPath), mUi->sourcesTree->invisibleRootItem());
    mRootDirectory->setExpanded(true);
    mUi->sourcesTree->setCurrentItem(mRootDirectory);
    refresh();
}

void FileManager::selectFileOrDirectory(FileOrDirectory* item)
{
    mUi->sourcesTree->setCurrentItem(item);
}

FileOrDirectory* FileManager::selectedFileOrDirectory() const
{
    QTreeWidgetItem* item = mUi->sourcesTree->currentItem();
    if (item == nullptr)
        return nullptr;

    switch (item->type()) {
        case Directory::Type: return static_cast<Directory*>(item);
        case File::Type: return static_cast<File*>(item);
    }

    return nullptr;
}

bool FileManager::canRename() const
{
    auto selected = selectedFileOrDirectory();
    Directory* parent = (selected ? selected->parentDirectory() : nullptr);
    return (parent != nullptr);
}

bool FileManager::canDelete() const
{
    auto selected = selectedFileOrDirectory();
    Directory* parent = (selected ? selected->parentDirectory() : nullptr);
    return (parent != nullptr);
}

void FileManager::refresh()
{
    refreshDirectory(mRootDirectory);
}

void FileManager::refreshDirectory(Directory* directory)
{
    QHash<QString, Directory*> newDirectories, oldDirectories = directory->mDirectories;
    QHash<QString, File*> newFiles, oldFiles = directory->mFiles;

    QString path = directory->fileInfo().absoluteFilePath();
    QStringList filters = EditorTabFactory::instance()->filters();
    QDirIterator it(path, filters, QDir::Files | QDir::AllDirs | QDir::Hidden | QDir::NoDotAndDotDot);
    while (it.hasNext()) {
        it.next();

        QFileInfo info = it.fileInfo();
        QString path = QDir::cleanPath(info.absoluteFilePath());

        if (!info.isDir()) {
            File* file;
            QString name = info.fileName();
            auto it = oldFiles.find(name);
            if (it == oldFiles.end())
                file = new File(mFileIcon, info, directory);
            else {
                file = it.value();
                oldFiles.erase(it);
            }
            newFiles[name] = file;
        } else {
            Directory* subdir;
            QString name = info.fileName();
            auto it = oldDirectories.find(name);
            if (it == oldDirectories.end())
                subdir = new Directory(mFolderIcon, info, directory);
            else {
                subdir = it.value();
                oldDirectories.erase(it);
            }
            newDirectories[name] = subdir;
            refreshDirectory(subdir);
        }
    }

    directory->mDirectories = newDirectories;
    directory->mFiles = newFiles;

    for (auto dir : oldDirectories)
        delete dir;

    for (auto file : oldFiles) {
        emit fileDisappeared(file);
        delete file;
    }

    directory->sortChildren(0, Qt::AscendingOrder);
}

void FileManager::enumerateFiles(std::vector<File*>& files)
{
    enumerateFilesInDirectory(mRootDirectory, files);
}

void FileManager::enumerateFilesInDirectory(Directory* directory, std::vector<File*>& files)
{
    for (Directory* subdir : directory->mDirectories)
        enumerateFilesInDirectory(subdir, files);
    for (File* file : directory->mFiles)
        files.emplace_back(file);
}

void FileManager::on_sourcesTree_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous)
{
    auto selected = selectedFileOrDirectory();
    Directory* parent = (selected ? selected->parentDirectory() : nullptr);
    emit fileSelected(selected && selected->type() == File::Type ? static_cast<File*>(selected) : nullptr);
    emit updateUi();
}

void FileManager::on_sourcesTree_customContextMenuRequested(const QPoint& pos)
{
    auto itemUnderMouse = mUi->sourcesTree->itemAt(pos);
    if (itemUnderMouse == nullptr)
        itemUnderMouse = mRootDirectory;
    mUi->sourcesTree->setCurrentItem(itemUnderMouse);

    mUi->renameAction->setEnabled(itemUnderMouse != mRootDirectory);
    mUi->deleteAction->setEnabled(itemUnderMouse != mRootDirectory);

    QMenu menu;
    menu.addAction(mUi->newFileAction);
    menu.addAction(mUi->newDirectoryAction);
    menu.addSeparator();
    menu.addAction(mUi->renameAction);
    menu.addAction(mUi->deleteAction);
    menu.addSeparator();
    menu.addAction(mUi->refreshAction);
    menu.exec(mapToGlobal(pos));
}

void FileManager::on_refreshAction_triggered()
{
    refresh();
}

void FileManager::on_newDirectoryAction_triggered()
{
    Directory* parent = nullptr;
    auto selected = selectedFileOrDirectory();
    if (!selected)
        selected = mRootDirectory;
    if (selected->type() == Directory::Type)
        parent = static_cast<Directory*>(selected);
    else {
        parent = selected->parentDirectory();
        if (!parent)
            parent = mRootDirectory;
    }
    if (!parent)
        return;

    QInputDialog dlg(this);
    dlg.setInputMode(QInputDialog::TextInput);
    dlg.setWindowTitle(tr("Create directory"));
    dlg.setLabelText(tr("Name:"));
    dlg.setTextValue(tr("New Directory"));
    if (dlg.exec() != QDialog::Accepted)
        return;

    QString name = dlg.textValue().trimmed();
    if (name.isEmpty()) {
        QMessageBox::critical(this, tr("Error"), tr("Directory name should not be empty."));
        return;
    }

    QDir dir(parent->fileInfo().absoluteFilePath());
    if (!dir.mkdir(name)) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to create directory \"%1\" in \"%2\".").arg(name).arg(dir.absolutePath()));
        return;
    }

    refreshDirectory(parent);

    Directory* newDirectory = parent->directory(name);
    Q_ASSERT(newDirectory);
    if (newDirectory)
        mUi->sourcesTree->setCurrentItem(newDirectory);
}

void FileManager::on_newFileAction_triggered()
{
    Directory* parent = nullptr;
    auto selected = selectedFileOrDirectory();
    if (!selected)
        selected = mRootDirectory;
    if (selected->type() == Directory::Type)
        parent = static_cast<Directory*>(selected);
    else {
        parent = selected->parentDirectory();
        if (!parent)
            parent = mRootDirectory;
    }
    if (!parent)
        return;

    QInputDialog dlg(this);
    dlg.setInputMode(QInputDialog::TextInput);
    dlg.setWindowTitle(tr("Create file"));
    dlg.setLabelText(tr("Name:"));
    dlg.setTextValue(tr("New File"));
    if (dlg.exec() != QDialog::Accepted)
        return;

    QString name = dlg.textValue().trimmed();
    if (name.isEmpty()) {
        QMessageBox::critical(this, tr("Error"), tr("File name should not be empty."));
        return;
    }

    QDir dir(parent->fileInfo().absoluteFilePath());
    QFile file(dir.absoluteFilePath(name));
    if (file.exists()) {
        QMessageBox::critical(this, tr("Error"), tr("File or directory \"%1\" already exists.").arg(name));
        return;
    }

    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to create file \"%1\" in \"%2\": %3")
            .arg(name).arg(dir.absolutePath()).arg(file.errorString()));
        return;
    }

    file.close();

    refreshDirectory(parent);

    File* newFile = parent->file(name);
    Q_ASSERT(newFile);
    if (newFile)
        mUi->sourcesTree->setCurrentItem(newFile);
}

void FileManager::on_renameAction_triggered()
{
    auto selected = selectedFileOrDirectory();
    if (!selected)
        return;

    auto parent = selected->parentDirectory();
    if (!parent)
        return;

    QString oldName = selected->name();
    bool isDirectory = (selected->type() == Directory::Type);

  #ifndef NDEBUG
    if (isDirectory)
        Q_ASSERT(parent->directory(oldName) == selected);
    else
        Q_ASSERT(parent->file(oldName) == selected);
  #endif

    QInputDialog dlg(this);
    dlg.setInputMode(QInputDialog::TextInput);
    dlg.setWindowTitle(selected->type() == Directory::Type ? tr("Rename directory") : tr("Rename file"));
    dlg.setLabelText(tr("Name:"));
    dlg.setTextValue(oldName);
    if (dlg.exec() != QDialog::Accepted)
        return;

    QString newName = dlg.textValue().trimmed();
    if (newName == oldName)
        return;
    if (newName.isEmpty()) {
        QMessageBox::critical(this, tr("Error"), tr("Name should not be empty."));
        return;
    }

    QString fullOldName = oldName;
    QString fullNewName = newName;

    QDir dir(parent->fileInfo().absoluteFilePath());
    if (QFile(dir.absoluteFilePath(fullNewName)).exists()) {
        QMessageBox::critical(this, tr("Error"), tr("File or directory \"%1\" already exists.").arg(fullNewName));
        return;
    }

    if (selected->type() == File::Type) {
        bool shouldAbort = false;
        emit willRenameFile(static_cast<File*>(selected), &shouldAbort);
        if (shouldAbort)
            return;
    }

    if (!dir.rename(fullOldName, fullNewName)) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to rename \"%1\" to \"%2\" in \"%3\".")
            .arg(fullOldName).arg(fullNewName).arg(dir.absolutePath()));
        return;
    }

    refreshDirectory(parent);

    if (isDirectory) {
        Directory* newDirectory = parent->directory(newName);
        Q_ASSERT(newDirectory);
        if (newDirectory)
            mUi->sourcesTree->setCurrentItem(newDirectory);
    } else {
        File* newFile = parent->file(newName);
        Q_ASSERT(newFile);
        if (newFile)
            mUi->sourcesTree->setCurrentItem(newFile);
    }
}

void FileManager::on_deleteAction_triggered()
{
    auto selected = selectedFileOrDirectory();
    if (!selected)
        return;

    auto parent = selected->parentDirectory();
    if (!parent)
        return;

    QString question = QStringLiteral("%1\n\n%2")
        .arg(tr("Do you really with to delete \"%1\"?").arg(selected->name()))
        .arg(tr("Note: this operation cannot be undone."));

    QMessageBox msgbox(QMessageBox::Question, tr("Confirmation"), question, QMessageBox::NoButton, this);
    auto btnDelete = msgbox.addButton(tr("Delete"), QMessageBox::DestructiveRole);
    auto btnCancel = msgbox.addButton(tr("Cancel"), QMessageBox::RejectRole);
    msgbox.setDefaultButton(btnCancel);
    msgbox.setEscapeButton(btnCancel);
    msgbox.exec();
    if (msgbox.clickedButton() != btnDelete)
        return;

    if (selected->type() == Directory::Type) {
        if (!QDir(selected->fileInfo().absoluteFilePath()).rmdir(QStringLiteral("."))) {
            QMessageBox::critical(this, tr("Error"), QStringLiteral("%1\n\n%2")
                .arg(tr("Unable to delete directory \"%1\".").arg(selected->fileInfo().absoluteFilePath()))
                .arg(tr("Is it empty?")));
            return;
        }
    } else {
        if (!QFile::remove(selected->fileInfo().absoluteFilePath())) {
            QMessageBox::critical(this, tr("Error"),
                tr("Unable to delete file \"%1\".").arg(selected->fileInfo().absoluteFilePath()));
            return;
        }
    }

    refreshDirectory(parent);
}
