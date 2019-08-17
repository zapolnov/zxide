#include "RenameDialog.h"
#include "editor/EditorTabFactory.h"
#include "editor/FileManager.h"
#include "ui_RenameDialog.h"
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>

RenameDialog::RenameDialog(FileOrDirectory* item, QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_RenameDialog)
    , mItem(item)
{
    mUi->setupUi(this);

    bool isDirectory = (mItem->type() == Directory::Type);
    if (isDirectory) {
        setWindowTitle(tr("Rename directory"));
        mUi->oldNameLabel->setText(tr("Rename directory"));
        mUi->oldNameEdit->setText(mItem->name());
        mUi->newNameEdit->setText(mItem->name());
    } else {
        setWindowTitle(tr("Rename file"));
        mUi->oldNameLabel->setText(tr("Rename file"));
        mUi->oldNameEdit->setText(mItem->name());
        mUi->newNameEdit->setText(mItem->fileInfo().completeBaseName());
    }

    mUi->newNameEdit->selectAll();
    mUi->newNameEdit->setFocus();
}

RenameDialog::~RenameDialog()
{
}

void RenameDialog::done(int r)
{
    if (r == QDialog::Accepted) {
        mNewName = mUi->newNameEdit->text().trimmed();
        if (mNewName.isEmpty()) {
            QMessageBox::critical(this, tr("Error"), tr("Name should not be empty."));
            mUi->newNameEdit->setFocus();
            return;
        }

        bool isDirectory = (mItem->type() == Directory::Type);
        if (!isDirectory) {
            QString extension = mItem->fileInfo().suffix();
            if (!mNewName.endsWith(QStringLiteral(".%1").arg(extension)))
                mNewName = QStringLiteral("%1.%2").arg(mNewName).arg(extension);
        }

        QString oldName = mItem->name();
        if (mNewName == oldName) {
            QDialog::done(QDialog::Rejected);
            return;
        }

        auto parent = mItem->parentDirectory();
        QDir dir(parent->fileInfo().absoluteFilePath());
        if (QFile(dir.absoluteFilePath(mNewName)).exists()) {
            QMessageBox::critical(this, tr("Error"), tr("File or directory \"%1\" already exists.").arg(mNewName));
            mUi->newNameEdit->selectAll();
            mUi->newNameEdit->setFocus();
            return;
        }

        if (mItem->type() == File::Type) {
            bool shouldAbort = false;
            emit willRenameFile(static_cast<File*>(mItem), &shouldAbort);
            if (shouldAbort) {
                mUi->newNameEdit->selectAll();
                mUi->newNameEdit->setFocus();
                return;
            }
        }

        if (!dir.rename(oldName, mNewName)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to rename \"%1\" to \"%2\" in \"%3\".")
                .arg(oldName).arg(mNewName).arg(dir.absolutePath()));
            mUi->newNameEdit->selectAll();
            mUi->newNameEdit->setFocus();
            return;
        }
    }

    QDialog::done(r);
}
