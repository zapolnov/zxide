#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QHash>
#include <QFileInfo>
#include <memory>

class FileManager;
class Ui_FileManager;
class Directory;

class FileOrDirectory : public QTreeWidgetItem
{
public:
    FileOrDirectory(const QIcon& icon, const QFileInfo& fileInfo, int type, QTreeWidgetItem* parent)
        : QTreeWidgetItem(parent, QStringList() << name(fileInfo), type)
        , mFileInfo(fileInfo)
    {
        setIcon(0, icon);
    }

    QString name() const { return name(mFileInfo); }
    const QFileInfo& fileInfo() const { return mFileInfo; }
    Directory* parentDirectory() const;

private:
    QFileInfo mFileInfo;

    static QString name(const QFileInfo& info) { return info.isDir() ? info.fileName() : info.completeBaseName(); }
};

class File : public FileOrDirectory
{
public:
    enum { Type = QTreeWidgetItem::UserType + 1 };

    File(const QIcon& icon, const QFileInfo& fileInfo, QTreeWidgetItem* parent)
        : FileOrDirectory(icon, fileInfo, Type, parent)
    {
    }
};

class Directory : public FileOrDirectory
{
public:
    enum { Type = QTreeWidgetItem::UserType + 2 };

    Directory(const QIcon& icon, const QFileInfo& fileInfo, QTreeWidgetItem* parent)
        : FileOrDirectory(icon, fileInfo, Type, parent)
    {
    }

    Directory* directory(const QString& name) const
    {
        auto it = mDirectories.find(name);
        return (it != mDirectories.end() ? it.value() : nullptr);
    }

    File* file(const QString& name) const
    {
        auto it = mFiles.find(name);
        return (it != mFiles.end() ? it.value() : nullptr);
    }

private:
    QHash<QString, Directory*> mDirectories;
    QHash<QString, File*> mFiles;

    friend class FileManager;
};

class FileManager : public QWidget
{
    Q_OBJECT

public:
    explicit FileManager(QWidget* parent = nullptr);
    ~FileManager() override;

    void init(const QString& path, const QString& extension);

    FileOrDirectory* selectedFileOrDirectory() const;

    bool canRename() const;
    bool canDelete() const;

    void createFile() { on_newFileAction_triggered(); }
    void createDirectory() { on_newDirectoryAction_triggered(); }
    void renameSelected() { on_renameAction_triggered(); }
    void deleteSelected() { on_deleteAction_triggered(); }

    void refresh();
    void refreshDirectory(Directory* directory);

signals:
    void updateUi();
    void willRenameFile(File* file, bool* shouldAbort);
    void fileSelected(File* file);
    void fileDisappeared(File* file);

private:
    std::unique_ptr<Ui_FileManager> mUi;
    QIcon mFolderIcon;
    QIcon mFileIcon;
    Directory* mRootDirectory;
    QString mPath;
    QString mExtension;

    Q_SLOT void on_sourcesTree_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
    Q_SLOT void on_sourcesTree_customContextMenuRequested(const QPoint& pos);

    Q_SLOT void on_refreshAction_triggered();
    Q_SLOT void on_newDirectoryAction_triggered();
    Q_SLOT void on_newFileAction_triggered();
    Q_SLOT void on_renameAction_triggered();
    Q_SLOT void on_deleteAction_triggered();

    Q_DISABLE_COPY(FileManager)
};

#endif
