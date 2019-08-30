#include "FileManager.h"
#include "editor/Project.h"
#include "editor/EditorTabFactory.h"
#include "editor/AbstractEditorTab.h"
#include "editor/RenameDialog.h"
#include "editor/DuplicateDialog.h"
#include "editor/NewFileDialog.h"
#include "ui_FileManager.h"
#include <QMenu>
#include <QDir>
#include <QDirIterator>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>

static bool isReservedName(const QString& name)
{
    static const QSet<QString> reservedNames = {
            QStringLiteral(".git"),
            QStringLiteral(".gitignore"),
        };

    return reservedNames.contains(name);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FileOrDirectory::FileOrDirectory(const QIcon& icon, const QFileInfo& fileInfo, int type, QTreeWidgetItem* parent)
    : QTreeWidgetItem(parent, QStringList() << fileInfo.fileName(), type)
    , mFileInfo(fileInfo)
    , mIsProjectFile(!fileInfo.isDir() && fileInfo.suffix() == Project::FileSuffix)
{
    setIcon(0, icon);
    setExpanded(true);
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

bool FileOrDirectory::operator<(const QTreeWidgetItem& other) const
{
    bool isDir1 = (type() == Directory::Type);
    bool isDir2 = (other.type() == Directory::Type);

    if (isDir1 && !isDir2)
        return true;
    else if (!isDir1 && isDir2)
        return false;

    return QTreeWidgetItem::operator<(other);
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
    , mRootDirectoryIcon(QStringLiteral(":/resources/fatcow16x16/book.png"))
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
    mRootDirectory = new Directory(mRootDirectoryIcon, QFileInfo(mPath), mUi->sourcesTree->invisibleRootItem());
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
    return (parent != nullptr && !selected->isProjectFile());
}

bool FileManager::canDuplicate() const
{
    auto selected = selectedFileOrDirectory();
    return (selected && selected->type() == File::Type && !selected->isProjectFile());
}

bool FileManager::canDelete() const
{
    auto selected = selectedFileOrDirectory();
    Directory* parent = (selected ? selected->parentDirectory() : nullptr);
    return (parent != nullptr && !selected->isProjectFile());
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
    QDirIterator it(path, QDir::Files | QDir::AllDirs | QDir::Hidden | QDir::NoDotAndDotDot);
    while (it.hasNext()) {
        it.next();
        QFileInfo info = it.fileInfo();

        QString fileName = info.fileName();
        if (isReservedName(fileName))
            continue;

        if (directory == mRootDirectory) {
            if (!info.isDir() && info.suffix() == Project::FileSuffix)
                continue;
            if (fileName == Project::BuildDirectory)
                continue;
        }

        QString path = QDir::cleanPath(info.absoluteFilePath());
        if (!info.isDir()) {
            File* file;
            QString name = info.fileName();
            auto it = oldFiles.find(name);
            if (it == oldFiles.end())
                file = new File(EditorTabFactory::instance()->iconForFile(info), info, directory);
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

void FileManager::enumerateFiles(std::vector<File*>& files, bool includeGenerated)
{
    for (Directory* subdir : mRootDirectory->mDirectories) {
        if (!includeGenerated && subdir->name() == QStringLiteral("generated"))
            continue;
        enumerateFilesInDirectory(subdir, files);
    }

    for (File* file : mRootDirectory->mFiles)
        files.emplace_back(file);
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
    emit fileSelected(selected && selected->type() == File::Type ? static_cast<File*>(selected) : nullptr);
    emit updateUi();
}

void FileManager::on_sourcesTree_itemDoubleClicked(QTreeWidgetItem *item, int)
{
    if (item && item->type() == File::Type)
        emit fileDoubleClicked(static_cast<File*>(item));
}

void FileManager::on_sourcesTree_customContextMenuRequested(const QPoint& pos)
{
    auto itemUnderMouse = mUi->sourcesTree->itemAt(pos);
    if (itemUnderMouse == nullptr)
        itemUnderMouse = mRootDirectory;
    mUi->sourcesTree->setCurrentItem(itemUnderMouse);

    FileOrDirectory* fileOrDirectory = nullptr;
    switch (itemUnderMouse->type()) {
        case File::Type: fileOrDirectory = static_cast<File*>(itemUnderMouse); break;
        case Directory::Type: fileOrDirectory = static_cast<Directory*>(itemUnderMouse); break;
    }

    Q_ASSERT(fileOrDirectory != nullptr);
    if (!fileOrDirectory)
        return;

    mUi->renameAction->setEnabled(itemUnderMouse != mRootDirectory && !fileOrDirectory->isProjectFile());
    mUi->duplicateAction->setEnabled(fileOrDirectory->type() == File::Type && !fileOrDirectory->isProjectFile());
    mUi->deleteAction->setEnabled(itemUnderMouse != mRootDirectory && !fileOrDirectory->isProjectFile());

    QMenu menu;
    menu.addAction(mUi->newFileAction);
    menu.addAction(mUi->newDirectoryAction);
    menu.addSeparator();
    menu.addAction(mUi->renameAction);
    menu.addAction(mUi->duplicateAction);
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

    NewFileDialog dlg(parent, this);
    if (dlg.exec() != QDialog::Accepted)
        return;

    refreshDirectory(parent);

    File* newFile = parent->file(dlg.name());
    Q_ASSERT(newFile);
    if (newFile) {
        mUi->sourcesTree->setCurrentItem(newFile);
        emit fileCreated(newFile);
    }
}

void FileManager::on_renameAction_triggered()
{
    auto selected = selectedFileOrDirectory();
    if (!selected)
        return;

    auto parent = selected->parentDirectory();
    if (!parent)
        return;

    bool isDirectory = (selected->type() == Directory::Type);

  #ifndef NDEBUG
    if (isDirectory)
        Q_ASSERT(parent->directory(selected->name()) == selected);
    else
        Q_ASSERT(parent->file(selected->name()) == selected);
  #endif

    RenameDialog dlg(selected, this);
    connect(&dlg, &RenameDialog::willRenameFile, this, &FileManager::willRenameFile);
    if (dlg.exec() != QDialog::Accepted)
        return;

    refreshDirectory(parent);

    if (isDirectory) {
        Directory* newDirectory = parent->directory(dlg.newName());
        Q_ASSERT(newDirectory);
        if (newDirectory)
            mUi->sourcesTree->setCurrentItem(newDirectory);
    } else {
        File* newFile = parent->file(dlg.newName());
        Q_ASSERT(newFile);
        if (newFile) {
            mUi->sourcesTree->setCurrentItem(newFile);
            emit didRenameFile(newFile);
        }
    }
}

void FileManager::on_duplicateAction_triggered()
{
    auto selected = selectedFileOrDirectory();
    if (!selected)
        return;

    auto parent = selected->parentDirectory();
    if (!parent)
        return;

    if (selected->type() != File::Type)
        return;

  #ifndef NDEBUG
    Q_ASSERT(parent->file(selected->name()) == selected);
  #endif

    DuplicateDialog dlg(selected, this);
    connect(&dlg, &DuplicateDialog::willDuplicateFile, this, &FileManager::willDuplicateFile);
    if (dlg.exec() != QDialog::Accepted)
        return;

    refreshDirectory(parent);

    File* newFile = parent->file(dlg.newName());
    Q_ASSERT(newFile);
    if (newFile) {
        mUi->sourcesTree->setCurrentItem(newFile);
        emit fileDoubleClicked(newFile);
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
