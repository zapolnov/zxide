#ifndef EDITOR_MAP_EDITENTITYDIALOG_H
#define EDITOR_MAP_EDITENTITYDIALOG_H

#include <QDialog>
#include <memory>

class Ui_EditEntityDialog;

class EditEntityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditEntityDialog(const QString& entity, QWidget* parent = nullptr);
    ~EditEntityDialog() override;

    QString entity() const;

private:
    std::unique_ptr<Ui_EditEntityDialog> mUi;

    Q_DISABLE_COPY(EditEntityDialog)
};

#endif
