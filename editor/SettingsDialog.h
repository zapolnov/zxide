#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <memory>

class Ui_SettingsDialog;

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget* parent = nullptr);
    ~SettingsDialog() override;

    void done(int r) override;

private:
    std::unique_ptr<Ui_SettingsDialog> mUi;

    Q_DISABLE_COPY(SettingsDialog)
};

#endif
