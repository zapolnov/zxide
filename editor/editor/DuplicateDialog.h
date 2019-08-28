#ifndef EDITOR_DUPLICATEDIALOG_H
#define EDITOR_DUPLICATEDIALOG_H

#include <QDialog>
#include <memory>

class File;
class FileOrDirectory;
class Ui_DuplicateDialog;

class DuplicateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DuplicateDialog(FileOrDirectory* item, QWidget* parent = nullptr);
    ~DuplicateDialog() override;

    const QString& newName() const { return mNewName; }

    void done(int r) override;

signals:
    void willDuplicateFile(File* file, bool* shouldAbort);

private:
    std::unique_ptr<Ui_DuplicateDialog> mUi;
    FileOrDirectory* mItem;
    QString mNewName;

    Q_DISABLE_COPY(DuplicateDialog)
};

#endif
