#include "MainWindow.h"
#include "CompilerDialog.h"
#include "AboutDialog.h"
#include "SettingsDialog.h"
#include "util/Settings.h"
#include "debugger/EmulatorCore.h"
#include "editor/IEditorTab.h"
#include "editor/FileManager.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QCloseEvent>
#include <QCheckBox>
#include <QInputDialog>
#include <QLabel>

namespace
{
    class DummyTab : public IEditorTab
    {
    };

    static DummyTab dummyTab;
}

MainWindow::MainWindow(const QString& path)
    : mUi(new Ui_MainWindow)
{
    mEmulatorCore = new EmulatorCore(this);
    connect(mEmulatorCore, &EmulatorCore::updateUi, this, &MainWindow::updateUi);

    mUi->setupUi(this);

    mInsOverwriteLabel = new QLabel(mUi->statusBar);
    mInsOverwriteLabel->setFixedWidth(35);
    mInsOverwriteLabel->setFrameShape(QFrame::StyledPanel);
    mInsOverwriteLabel->setFrameShadow(QFrame::Sunken);
    mInsOverwriteLabel->setAlignment(Qt::AlignCenter);
    mUi->statusBar->addPermanentWidget(mInsOverwriteLabel);

    mLineColumnLabel = new QLabel(mUi->statusBar);
    mLineColumnLabel->setFixedWidth(120);
    mLineColumnLabel->setFrameShape(QFrame::StyledPanel);
    mLineColumnLabel->setFrameShadow(QFrame::Sunken);
    mLineColumnLabel->setAlignment(Qt::AlignCenter);
    mUi->statusBar->addPermanentWidget(mLineColumnLabel);

    mEmulatorSpeedLabel = new QLabel(mUi->statusBar);
    mEmulatorSpeedLabel->setFixedWidth(50);
    mEmulatorSpeedLabel->setFrameShape(QFrame::StyledPanel);
    mEmulatorSpeedLabel->setFrameShadow(QFrame::Sunken);
    mEmulatorSpeedLabel->setAlignment(Qt::AlignCenter);
    mUi->statusBar->addPermanentWidget(mEmulatorSpeedLabel);

    mBuildResultLabel = new QLabel(mUi->statusBar);
    mUi->statusBar->addWidget(mBuildResultLabel);
    clearBuildResult();

    int n = mUi->tabWidget->count();
    for (int i = 0; i < n; i++) {
        IEditorTab* tab = dynamic_cast<IEditorTab*>(mUi->tabWidget->widget(i));
        Q_ASSERT(tab != nullptr);
        if (tab) {
            tab->updateUi = std::bind(&MainWindow::updateUi, this);
            mEditorTabs.emplace_back(tab);
        }
    }

    mUi->tabWidget->setCurrentWidget(mUi->codeTab);

    mUi->codeTab->init(QStringLiteral("%1/code").arg(path));
    mUi->tilesTab->init(QStringLiteral("%1/tiles").arg(path));
    mUi->levelsTab->init(QStringLiteral("%1/levels").arg(path));

    updateUi();
}

MainWindow::~MainWindow()
{
    delete mEmulatorCore;
}

IEditorTab* MainWindow::currentTab() const
{
    QWidget* widget = mUi->tabWidget->currentWidget();
    if (widget == nullptr)
        return &dummyTab;

    auto tab = dynamic_cast<IEditorTab*>(widget);
    Q_ASSERT(tab != nullptr);
    if (tab == nullptr)
        return &dummyTab;

    return tab;
}

bool MainWindow::hasModifiedFiles() const
{
    for (IEditorTab* tab : mEditorTabs) {
        if (tab->hasModifiedFiles())
            return true;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (confirmSave())
        event->accept();
    else
        event->ignore();
}

bool MainWindow::confirmSave()
{
    if (!hasModifiedFiles())
        return true;

    QMessageBox msgbox(QMessageBox::Warning, tr("Confirmation"), tr("Save changes?"), QMessageBox::NoButton, this);
    auto btnSave = msgbox.addButton(tr("Save changes"), QMessageBox::AcceptRole);
    auto btnDontSave = msgbox.addButton(tr("Discard changes"), QMessageBox::DestructiveRole);
    auto btnCancel = msgbox.addButton(tr("Cancel"), QMessageBox::RejectRole);
    msgbox.setDefaultButton(btnCancel);
    msgbox.setEscapeButton(btnCancel);
    msgbox.exec();

    auto clicked = msgbox.clickedButton();
    if (clicked == btnSave)
        return saveAll();
    if (clicked == btnDontSave)
        return true;

    return false;
}

bool MainWindow::saveAll()
{
    bool success = true;
    for (IEditorTab* tab : mEditorTabs) {
        if (!tab->saveAll())
            success = false;
    }
    return success;
}

bool MainWindow::build()
{
    if (mEmulatorCore->isRunning())
        return false;

    if (hasModifiedFiles()) {
        Settings settings;
        if (!settings.autoSaveBeforeCompile()) {
            QCheckBox* autoSaveCheck = new QCheckBox(this);
            autoSaveCheck->setText(tr("Automatically save files before each build"));

            QMessageBox msgbox(QMessageBox::Warning, tr("Confirmation"),
                QStringLiteral("%1\n\n%2")
                    .arg(tr("All modified files have to be saved before compiling the code."))
                    .arg(tr("Save all files now?")),
                QMessageBox::NoButton, this);
            auto btnSave = msgbox.addButton(tr("Save all and build"), QMessageBox::AcceptRole);
            auto btnCancel = msgbox.addButton(tr("Cancel"), QMessageBox::RejectRole);
            msgbox.setCheckBox(autoSaveCheck);
            msgbox.setDefaultButton(btnCancel);
            msgbox.setEscapeButton(btnCancel);
            msgbox.exec();

            auto clicked = msgbox.clickedButton();
            if (clicked == btnCancel) {
                clearBuildResult();
                return false;
            }

            if (autoSaveCheck->isChecked())
                settings.setAutoSaveBeforeCompile(true);
        }

        if (!saveAll()) {
            clearBuildResult();
            return false;
        }
    }

    mBuildResultLabel->setToolTip(QString());
    mBuildResultLabel->setText(tr("Compiling..."));
    mBuildResultLabel->setStyleSheet(QStringLiteral("color: #ccaa00; font-weight: bold; padding-right: 5px"));

    CompilerDialog dlg(this);

    std::vector<File*> files;
    for (IEditorTab* tab : mEditorTabs)
        tab->enumerateFiles(files);
    for (File* file : files)
        dlg.addSourceFile(file);

    connect(&dlg, &CompilerDialog::compilationSucceeded, this, &MainWindow::clearBuildResult);
    connect(&dlg, &CompilerDialog::compilationFailed, this, [this](File* file, int line, const QString& errorMessage) {
            mUi->tabWidget->setCurrentWidget(mUi->codeTab);

            QString message;
            if (!file)
                message = errorMessage;
            else if (file && line <= 0) {
                mUi->codeTab->setCurrentFile(file);
                message = tr("%1: %2").arg(file->fileInfo().fileName()).arg(errorMessage);
            } else {
                mUi->codeTab->setCurrentFile(file);
                mUi->codeTab->goToLine(line - 1);
                mUi->codeTab->setFocusToEditor();
                message = tr("%1(%2): %3").arg(file->fileInfo().fileName()).arg(line).arg(errorMessage);
            }

            mBuildResultLabel->setText(message);
            mBuildResultLabel->setToolTip(message);
            mBuildResultLabel->setStyleSheet(QStringLiteral("color: red; font-weight: bold; padding-right: 5px"));
        });

    return dlg.runCompiler();
}

void MainWindow::clearBuildResult()
{
    mBuildResultLabel->setToolTip(QString());
    mBuildResultLabel->setText(tr("Ready"));
    mBuildResultLabel->setStyleSheet(QStringLiteral("color: black; font-weight: bold; padding-right: 5px"));
}

void MainWindow::updateUi()
{
    bool modified = hasModifiedFiles();
    setWindowModified(modified);

    IEditorTab* tab = currentTab();
    mUi->actionNewFile->setEnabled(tab->canCreateFile());
    mUi->actionNewDirectory->setEnabled(tab->canCreateDirectory());
    mUi->actionSaveAll->setEnabled(modified);
    mUi->actionRenameFile->setEnabled(tab->canRenameFile());
    mUi->actionDeleteFile->setEnabled(tab->canDeleteFile());
    mUi->actionRefreshFileList->setEnabled(tab->canRefreshFileList());
    mUi->actionUndo->setEnabled(tab->canUndo());
    mUi->actionRedo->setEnabled(tab->canRedo());
    mUi->actionCut->setEnabled(tab->canCut());
    mUi->actionCopy->setEnabled(tab->canCopy());
    mUi->actionPaste->setEnabled(tab->canPaste());
    mUi->actionDelete->setEnabled(tab->canClear());
    mUi->actionSelectAll->setEnabled(tab->canSelectAll());
    mUi->actionClearSelection->setEnabled(tab->canClearSelection());
    mUi->actionGoToLine->setEnabled(tab->canGoToLine());
    mUi->actionBuild->setEnabled(!mEmulatorCore->isRunning());
    mUi->actionRun->setEnabled(!mEmulatorCore->isRunning() || mEmulatorCore->isPaused());
    mUi->actionPause->setEnabled(mEmulatorCore->isRunning() && !mEmulatorCore->isPaused());
    mUi->actionPause->setChecked(mEmulatorCore->isRunning() && mEmulatorCore->isPaused());
    mUi->actionStop->setEnabled(mEmulatorCore->isRunning());
    mUi->actionStepInto->setEnabled(mEmulatorCore->isRunning() && mEmulatorCore->isPaused());
    mUi->actionStepOut->setEnabled(mEmulatorCore->isRunning() && mEmulatorCore->isPaused());
    mUi->actionStepOver->setEnabled(mEmulatorCore->isRunning() && mEmulatorCore->isPaused());
    mUi->actionRunToCursor->setEnabled(mEmulatorCore->isRunning() && mEmulatorCore->isPaused() && tab->canRunToCursor());

    mLineColumnLabel->setText(tab->lineColumnLabelText());
    mInsOverwriteLabel->setText(tab->insOverwriteLabelText());
    mEmulatorSpeedLabel->setText(mEmulatorCore->currentSpeedString());

    mUi->registersDockWidget->setVisible(mEmulatorCore->isRunning());
}

void MainWindow::on_actionNewFile_triggered()
{
    currentTab()->createFile();
}

void MainWindow::on_actionNewDirectory_triggered()
{
    currentTab()->createDirectory();
}

void MainWindow::on_actionSaveAll_triggered()
{
    for (auto tab : mEditorTabs)
        tab->saveAll();
}

void MainWindow::on_actionRenameFile_triggered()
{
    currentTab()->renameFile();
}

void MainWindow::on_actionDeleteFile_triggered()
{
    currentTab()->deleteFile();
}

void MainWindow::on_actionRefreshFileList_triggered()
{
    currentTab()->refreshFileList();
}

void MainWindow::on_actionUndo_triggered()
{
    currentTab()->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    currentTab()->redo();
}

void MainWindow::on_actionCut_triggered()
{
    currentTab()->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    currentTab()->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    currentTab()->paste();
}

void MainWindow::on_actionDelete_triggered()
{
    currentTab()->clear();
}

void MainWindow::on_actionSelectAll_triggered()
{
    currentTab()->selectAll();
}

void MainWindow::on_actionClearSelection_triggered()
{
    currentTab()->clearSelection();
}

void MainWindow::on_actionGoToLine_triggered()
{
    auto tab = currentTab();
    if (tab->canGoToLine()) {
        QInputDialog dlg(this);
        dlg.setInputMode(QInputDialog::IntInput);
        dlg.setWindowTitle(tr("Go to line"));
        dlg.setLabelText(tr("Line number:"));
        dlg.setIntRange(1, INT_MAX);
        dlg.setIntStep(1);
        dlg.setIntValue(1);
        if (dlg.exec() != QDialog::Accepted)
            return;
        tab->goToLine(dlg.intValue() - 1);
    }
}

void MainWindow::on_actionBuild_triggered()
{
    build();
}

void MainWindow::on_actionRun_triggered()
{
    if (!mEmulatorCore->isRunning()) {
        if (build())
            mEmulatorCore->start();
    } else {
        if (mEmulatorCore->isPaused())
            mEmulatorCore->unpause();
    }
}

void MainWindow::on_actionPause_triggered()
{
    if (mEmulatorCore->isRunning() && !mEmulatorCore->isPaused())
        mEmulatorCore->pause();
}

void MainWindow::on_actionStop_triggered()
{
    mEmulatorCore->stop();
}

void MainWindow::on_actionStepInto_triggered()
{
    if (mEmulatorCore->isRunning() && mEmulatorCore->isPaused())
        mEmulatorCore->stepInto();
}

void MainWindow::on_actionStepOut_triggered()
{
    if (mEmulatorCore->isRunning() && mEmulatorCore->isPaused())
        mEmulatorCore->stepOut();
}

void MainWindow::on_actionStepOver_triggered()
{
    if (mEmulatorCore->isRunning() && mEmulatorCore->isPaused())
        mEmulatorCore->stepOver();
}

void MainWindow::on_actionRunToCursor_triggered()
{
    if (mEmulatorCore->isRunning() && mEmulatorCore->isPaused()) {
        // FIXME
        // mEmulatorCore->runToCursor();
    }
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        for (IEditorTab* tab : mEditorTabs)
            tab->reloadSettings();
        mEmulatorCore->reloadSettings();
    }
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dlg(this);
    dlg.exec();
}

void MainWindow::on_tabWidget_currentChanged(int)
{
    updateUi();
}

void MainWindow::on_registersDockWidget_dockLocationChanged(Qt::DockWidgetArea area)
{
    switch (area) {
        case Qt::LeftDockWidgetArea:
        case Qt::RightDockWidgetArea:
            mUi->registersWidget->setOrientation(Qt::Vertical);
            break;

        case Qt::TopDockWidgetArea:
        case Qt::BottomDockWidgetArea:
            mUi->registersWidget->setOrientation(Qt::Horizontal);
            break;
    }
}
