#include "MainWindow.h"
#include "AboutDialog.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QCloseEvent>

MainWindow::MainWindow(const QString& path)
    : mUi(new Ui_MainWindow)
{
    mUi->setupUi(this);
    mUi->tabWidget->setCurrentWidget(mUi->codeTab);
    mUi->codeFileManager->init(QStringLiteral("%1/code").arg(path), QStringLiteral(".asm"));
    updateUi();
}

MainWindow::~MainWindow()
{
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
    if (!isWindowModified())
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
    // FIXME
    return true;
}

void MainWindow::updateUi()
{
    setWindowModified(false); // FIXME
    mUi->actionUndo->setEnabled(false); // FIXME
    mUi->actionRedo->setEnabled(false); // FIXME
    mUi->actionCut->setEnabled(false); // FIXME
    mUi->actionCopy->setEnabled(false); // FIXME
    mUi->actionPaste->setEnabled(false); // FIXME
    mUi->actionDelete->setEnabled(false); // FIXME
    mUi->actionSelectAll->setEnabled(false); // FIXME
    mUi->actionClearSelection->setEnabled(false); // FIXME
    mUi->stackedWidget->setCurrentIndex(0); // FIXME
}

void MainWindow::on_actionSaveAll_triggered()
{
    // FIXME
}

void MainWindow::on_actionUndo_triggered()
{
    // FIXME
}

void MainWindow::on_actionRedo_triggered()
{
    // FIXME
}

void MainWindow::on_actionCut_triggered()
{
    // FIXME
}

void MainWindow::on_actionCopy_triggered()
{
    // FIXME
}

void MainWindow::on_actionPaste_triggered()
{
    // FIXME
}

void MainWindow::on_actionDelete_triggered()
{
    // FIXME
}

void MainWindow::on_actionSelectAll_triggered()
{
    // FIXME
}

void MainWindow::on_actionClearSelection_triggered()
{
    // FIXME
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
