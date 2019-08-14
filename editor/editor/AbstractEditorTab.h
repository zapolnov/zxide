#ifndef EDITOR_ABSTRACTEDITORTAB_H
#define EDITOR_ABSTRACTEDITORTAB_H

#include <QWidget>
#include "editor/IEditorTab.h"

class FileManager;

class AbstractEditorTab : public QWidget, public IEditorTab
{
    Q_OBJECT

public:
    explicit AbstractEditorTab(QWidget* parent = nullptr);
    ~AbstractEditorTab() override;

    File* currentFile() const override { return mCurrentFile; }
    void setCurrentFile(File* file);

    bool canCreateFile() const override;
    bool canCreateDirectory() const override;
    bool canRenameFile() const override;
    bool canDeleteFile() const override;
    bool canRefreshFileList() const override;

    void createFile() override;
    void createDirectory() override;
    void renameFile() override;
    void deleteFile() override;
    void refreshFileList() override;

    void enumerateFiles(std::vector<File*>& files) override;

protected:
    void setFileManager(FileManager* manager);

    virtual bool isFileModified(File* file) const { return false; }
    virtual bool loadFile(File* file) { return false; }
    virtual bool saveFile(File* file) { return false; }
    virtual void removeFile(File* file) {}

private:
    FileManager* mFileManager;
    File* mCurrentFile;

    Q_SLOT void on_fileManager_updateUi();
    Q_SLOT void on_fileManager_willRenameFile(File* file, bool* shouldAbort);
    Q_SLOT void on_fileManager_fileSelected(File* file);
    Q_SLOT void on_fileManager_fileDisappeared(File* file);

    Q_DISABLE_COPY(AbstractEditorTab)
};

#endif
