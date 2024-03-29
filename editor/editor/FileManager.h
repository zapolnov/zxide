#ifndef EDITOR_FILEMANAGER_H
#define EDITOR_FILEMANAGER_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QHash>
#include <QFileInfo>
#include <memory>
#include <functional>

class FileManager;
class Ui_FileManager;
class Directory;
class AbstractEditorTab;

class FileOrDirectory : public QTreeWidgetItem
{
public:
    FileOrDirectory(const QIcon& icon, const QFileInfo& fileInfo, int type, QTreeWidgetItem* parent);

    bool isProjectFile() const { return mIsProjectFile; }
    bool isGenerated() const { return mIsGenerated; }

    QString name() const { return mFileInfo.fileName(); }
    QString relativeName() const;
    const QFileInfo& fileInfo() const { return mFileInfo; }
    Directory* parentDirectory() const;
    Directory* rootDirectory() const;

    bool operator<(const QTreeWidgetItem &other) const override;

private:
    QFileInfo mFileInfo;
    bool mIsProjectFile;
    bool mIsGenerated;

    friend class FileManager;
};

class File : public FileOrDirectory
{
public:
    enum { Type = QTreeWidgetItem::UserType + 1 };

    File(const QIcon& icon, const QFileInfo& fileInfo, QTreeWidgetItem* parent);

    AbstractEditorTab* tab() const { return mTab; }
    AbstractEditorTab* createTab(QWidget* parent);
    void destroyTab();

private:
    AbstractEditorTab* mTab;

    friend class FileManager;
};

class Directory : public FileOrDirectory
{
public:
    enum { Type = QTreeWidgetItem::UserType + 2 };

    Directory(const QIcon& icon, const QFileInfo& fileInfo, QTreeWidgetItem* parent);

    Directory* directory(const QString& name) const;
    File* file(const QString& name) const;

    size_t numFiles() const { return mFiles.size(); }
    size_t numSubdirectories() const { return mDirectories.size(); }

    void forEachFile(const std::function<void(File*)>& callback) const
    {
        for (const auto& it : mFiles)
            callback(it);
    }

    void forEachSubdirectory(const std::function<void(Directory*)>& callback) const
    {
        for (const auto& it : mDirectories)
            callback(it);
    }

    FileOrDirectory* findChild(const QString& relativePath) const;

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

    void init(const QString& path);

    void selectFileOrDirectory(FileOrDirectory* item);
    FileOrDirectory* selectedFileOrDirectory() const;
    Directory* directoryOrParent(FileOrDirectory* selected) const;
    Directory* selectedParentDirectory() const;

    FileOrDirectory* fileOrDirectory(const QString& fileName) const;
    File* file(const QString& fileName) const;

    bool canCreateFile() const;
    bool canCreateDirectory() const;
    bool canRename() const;
    bool canDuplicate() const;
    bool canDelete() const;

    void createFile() { on_newFileAction_triggered(); }
    void createDirectory() { on_newDirectoryAction_triggered(); }
    void renameSelected() { on_renameAction_triggered(); }
    void duplicateSelected() { on_duplicateAction_triggered(); }
    void deleteSelected() { on_deleteAction_triggered(); }

    void refresh();
    void refreshDirectory(Directory* directory);

    void enumerateFiles(std::vector<File*>& files, bool includeGenerated);
    void enumerateFilesInDirectory(Directory* directory, std::vector<File*>& files);

signals:
    void updateUi();
    void fileCreated(File* file);
    void willRenameFile(File* file, bool* shouldAbort);
    void didRenameFile(File* file);
    void willDuplicateFile(File* file, bool* shouldAbort);
    void fileSelected(File* file);
    void fileDoubleClicked(File* file);
    void fileDisappeared(File* file);
    void editProjectSettings();

private:
    std::unique_ptr<Ui_FileManager> mUi;
    Directory* mRootDirectory;
    QString mPath;

    Q_SLOT void on_sourcesTree_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);
    Q_SLOT void on_sourcesTree_itemDoubleClicked(QTreeWidgetItem *item, int column);
    Q_SLOT void on_sourcesTree_customContextMenuRequested(const QPoint& pos);

    Q_SLOT void on_refreshAction_triggered();
    Q_SLOT void on_newDirectoryAction_triggered();
    Q_SLOT void on_newFileAction_triggered();
    Q_SLOT void on_renameAction_triggered();
    Q_SLOT void on_duplicateAction_triggered();
    Q_SLOT void on_deleteAction_triggered();
    Q_SLOT void on_editProjectSettingsAction_triggered();

    Q_DISABLE_COPY(FileManager)
};

#endif
