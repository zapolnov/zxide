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

    void updateUi();

    Q_SLOT void on_enableSoundCheck_toggled() { updateUi(); }
    Q_SLOT void on_fastLoadCheck_toggled() { updateUi(); }
    Q_SLOT void on_tapeSoundCheck_toggled() { updateUi(); }

    Q_DISABLE_COPY(SettingsDialog)
};

#endif
