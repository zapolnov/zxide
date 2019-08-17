#ifndef EDITOR_NEWFILEDIALOG_H
#define EDITOR_NEWFILEDIALOG_H

#include <QDialog>
#include <memory>

class Directory;
class Ui_NewFileDialog;

class NewFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFileDialog(Directory* directory, QWidget* parent = nullptr);
    ~NewFileDialog() override;

    const QString& name() const { return mName; }

    void done(int r) override;

private:
    std::unique_ptr<Ui_NewFileDialog> mUi;
    Directory* mDirectory;
    QString mName;

    Q_DISABLE_COPY(NewFileDialog)
};

#endif
