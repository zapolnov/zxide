#include "MainWindow.h"
#include "AboutDialog.h"
#include "IEditorTab.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QCloseEvent>
#include <QInputDialog>

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
    mUi->setupUi(this);

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
    for (auto tab : mEditorTabs) {
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
    auto btnSave = msgbox.addButton(tr("Save"), QMessageBox::AcceptRole);
    auto btnDiscard = msgbox.addButton(tr("Discard"), QMessageBox::DestructiveRole);
    auto btnCancel = msgbox.addButton(tr("Cancel"), QMessageBox::RejectRole);
    msgbox.setDefaultButton(btnCancel);
    msgbox.setEscapeButton(btnCancel);
    msgbox.exec();

    auto clicked = msgbox.clickedButton();
    if (clicked == btnSave)
        return saveAll();
    if (clicked == btnDiscard)
        return true;

    return false;
}

bool MainWindow::saveAll()
{
    bool success = true;
    for (auto tab : mEditorTabs) {
        if (!tab->saveAll())
            success = false;
    }
    return success;
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

    mUi->stackedWidget->setCurrentIndex(0); // FIXME
}

void MainWindow::on_actionNewFile_triggered()
{
    currentTab()->createFile();
}

void MainWindow::on_actionSaveAll_triggered()
{
    for (auto tab : mEditorTabs)
        tab->saveAll();
}

void MainWindow::on_actionCreateDirectory_triggered()
{
    currentTab()->createDirectory();
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

void MainWindow::on_actionRun_triggered()
{
    // FIXME
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
