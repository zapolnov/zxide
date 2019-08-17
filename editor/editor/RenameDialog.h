#ifndef EDITOR_RENAMEDIALOG_H
#define EDITOR_RENAMEDIALOG_H

#include <QDialog>
#include <memory>

class File;
class FileOrDirectory;
class Ui_RenameDialog;

class RenameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RenameDialog(FileOrDirectory* item, QWidget* parent = nullptr);
    ~RenameDialog() override;

    const QString& newName() const { return mNewName; }

    void done(int r) override;

signals:
    void willRenameFile(File* file, bool* shouldAbort);

private:
    std::unique_ptr<Ui_RenameDialog> mUi;
    FileOrDirectory* mItem;
    QString mNewName;

    Q_DISABLE_COPY(RenameDialog)
};

#endif
