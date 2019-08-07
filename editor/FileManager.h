#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QHash>
#include <QFileInfo>
#include <memory>

class FileOrDirectory : public QTreeWidgetItem
{
public:
    FileOrDirectory(const QIcon& icon, const QFileInfo& fileInfo, int type, QTreeWidgetItem* parent)
        : QTreeWidgetItem(parent, QStringList() << fileInfo.completeBaseName(), type)
        , mFileInfo(fileInfo)
    {
        setIcon(0, icon);
    }

    const QFileInfo& fileInfo() const { return mFileInfo; }

private:
    QFileInfo mFileInfo;
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
};

class Ui_FileManager;

class FileManager : public QWidget
{
    Q_OBJECT

public:
    explicit FileManager(QWidget* parent = nullptr);
    ~FileManager() override;

    void initWithPath(const QString& path);

private:
    std::unique_ptr<Ui_FileManager> mUi;
    QIcon mFolderIcon;
    QHash<QString, Directory*> mDirectories;
    QString mPath;

    void refresh();

    Q_DISABLE_COPY(FileManager)
};

#endif
