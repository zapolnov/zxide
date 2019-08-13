#include "SettingsDialog.h"
#include "Settings.h"
#include "ScintillaEdit/ScintillaEdit.h"
#include "ui_SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_SettingsDialog)
{
    Settings settings;

    mUi->setupUi(this);

    mUi->autoIndentCheck->setChecked(settings.autoIndent());
    mUi->tabIndentsCheck->setChecked(settings.tabIndents());
    mUi->backspaceUnindentsCheck->setChecked(settings.backspaceUnindents());
    mUi->useTabsCheck->setChecked(settings.useTabs());
    mUi->tabWidthSpin->setValue(settings.tabWidth());
    mUi->showWhitespaceCheck->setChecked(settings.whitespaceVisibility() != SCWS_INVISIBLE); // FIXME: proper selector
    mUi->showEolCheck->setChecked(settings.showEol());
    mUi->autoSaveBeforeCompileCheck->setChecked(settings.autoSaveBeforeCompile());
    mUi->enableSoundCheck->setChecked(settings.enableSound());

    mUi->tabWidget->setCurrentWidget(mUi->editorTab);
}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::done(int r)
{
    if (r == QDialog::Accepted) {
        Settings settings;
        settings.setAutoIndent(mUi->autoIndentCheck->isChecked());
        settings.setTabIndents(mUi->tabIndentsCheck->isChecked());
        settings.setBackspaceUnindents(mUi->backspaceUnindentsCheck->isChecked());
        settings.setUseTabs(mUi->useTabsCheck->isChecked());
        settings.setTabWidth(mUi->tabWidthSpin->value());
        settings.setWhitespaceVisibility(mUi->showWhitespaceCheck->isChecked() ? SCWS_VISIBLEALWAYS : SCWS_INVISIBLE);
        settings.setShowEol(mUi->showEolCheck->isChecked());
        settings.setAutoSaveBeforeCompile(mUi->autoSaveBeforeCompileCheck->isChecked());
        settings.setEnableSound(mUi->enableSoundCheck->isChecked());
    }

    QDialog::done(r);
}
