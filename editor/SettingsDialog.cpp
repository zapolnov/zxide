#include "SettingsDialog.h"
#include "debugger/EmulatorCore.h"
#include "util/Settings.h"
#include "ScintillaEdit/ScintillaEdit.h"
#include "ui_SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_SettingsDialog)
{
    Settings settings;

    mUi->setupUi(this);

    mUi->loadLastProjectCheck->setChecked(settings.loadLastProjectOnStart());
    mUi->autoSaveBeforeCompileCheck->setChecked(settings.autoSaveBeforeCompile());
    mUi->autoIndentCheck->setChecked(settings.autoIndent());
    mUi->tabIndentsCheck->setChecked(settings.tabIndents());
    mUi->backspaceUnindentsCheck->setChecked(settings.backspaceUnindents());
    mUi->useTabsCheck->setChecked(settings.useTabs());
    mUi->tabWidthSpin->setValue(settings.tabWidth());
    mUi->showWhitespaceCheck->setChecked(settings.whitespaceVisibility() != SCWS_INVISIBLE); // FIXME: proper selector
    mUi->showEolCheck->setChecked(settings.showEol());
    mUi->lineNumbersCheck->setChecked(settings.showLineNumbers());
    mUi->enableSoundCheck->setChecked(settings.enableSound());
    mUi->fastLoadCheck->setChecked(settings.fastTapeLoading());
    mUi->tapeSoundCheck->setChecked(settings.playTapeSound());

    mUi->emulatorRestartNotice->setVisible(EmulatorCore::instance()->isRunning());
    mUi->tabWidget->setCurrentWidget(mUi->generalTab);

    updateUi();
}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::done(int r)
{
    if (r == QDialog::Accepted) {
        Settings settings;
        settings.setLoadLastProjectOnStart(mUi->loadLastProjectCheck->isChecked());
        settings.setAutoSaveBeforeCompile(mUi->autoSaveBeforeCompileCheck->isChecked());
        settings.setAutoIndent(mUi->autoIndentCheck->isChecked());
        settings.setTabIndents(mUi->tabIndentsCheck->isChecked());
        settings.setBackspaceUnindents(mUi->backspaceUnindentsCheck->isChecked());
        settings.setUseTabs(mUi->useTabsCheck->isChecked());
        settings.setTabWidth(mUi->tabWidthSpin->value());
        settings.setWhitespaceVisibility(mUi->showWhitespaceCheck->isChecked() ? SCWS_VISIBLEALWAYS : SCWS_INVISIBLE);
        settings.setShowEol(mUi->showEolCheck->isChecked());
        settings.setShowLineNumbers(mUi->lineNumbersCheck->isChecked());
        settings.setEnableSound(mUi->enableSoundCheck->isChecked());
        settings.setFastTapeLoading(mUi->fastLoadCheck->isChecked());
        settings.setPlayTapeSound(mUi->tapeSoundCheck->isChecked());
    }

    QDialog::done(r);
}

void SettingsDialog::updateUi()
{
    mUi->tapeSoundCheck->setEnabled(mUi->enableSoundCheck->isChecked() && !mUi->fastLoadCheck->isChecked());
}
