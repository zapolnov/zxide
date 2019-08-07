#include "FileManager.h"
#include "ui_FileManager.h"
#include <QDir>
#include <QDirIterator>

FileManager::FileManager(QWidget* parent)
    : QWidget(parent)
    , mUi(new Ui_FileManager)
{
    mUi->setupUi(this);
}

FileManager::~FileManager()
{
}

void FileManager::initWithPath(const QString& path)
{
    mPath = QDir::cleanPath(QDir(path).absolutePath());
    refresh();
}

void FileManager::refresh()
{
    const auto flags = QDir::Files | QDir::AllDirs | QDir::Hidden | QDir::NoDotAndDotDot;
    QDirIterator it(mPath, flags, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();

        QFileInfo info = it.fileInfo();
        QString path = QDir::cleanPath(info.absoluteFilePath());

        if (info.isDir()) {
            Directory*& dir = mDirectories[path];
            if (!dir) {
                dir = new Directory(mFolderIcon, info, mUi->sourcesTree->invisibleRootItem());
            }
        }
    }
}
