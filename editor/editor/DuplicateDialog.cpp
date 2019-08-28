#include "DuplicateDialog.h"
#include "editor/EditorTabFactory.h"
#include "editor/FileManager.h"
#include "ui_DuplicateDialog.h"
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>

DuplicateDialog::DuplicateDialog(FileOrDirectory* item, QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_DuplicateDialog)
    , mItem(item)
{
    mUi->setupUi(this);
    mUi->oldNameEdit->setText(mItem->name());
    mUi->newNameEdit->setText(mItem->name());
    mUi->newNameEdit->selectAll();
    mUi->newNameEdit->setFocus();
}

DuplicateDialog::~DuplicateDialog()
{
}

void DuplicateDialog::done(int r)
{
    if (r == QDialog::Accepted) {
        mNewName = mUi->newNameEdit->text().trimmed();
        if (mNewName.isEmpty()) {
            QMessageBox::critical(this, tr("Error"), tr("Name should not be empty."));
            mUi->newNameEdit->setFocus();
            return;
        }

        QString extension = mItem->fileInfo().suffix();
        if (!mNewName.endsWith(QStringLiteral(".%1").arg(extension)))
            mNewName = QStringLiteral("%1.%2").arg(mNewName).arg(extension);

        auto parent = mItem->parentDirectory();
        QDir dir(parent->fileInfo().absoluteFilePath());

        QString oldName = mItem->name();
        QString newName = dir.absoluteFilePath(mNewName);

        if (QFile(newName).exists()) {
            QMessageBox::critical(this, tr("Error"), tr("File or directory \"%1\" already exists.").arg(mNewName));
            mUi->newNameEdit->selectAll();
            mUi->newNameEdit->setFocus();
            return;
        }

        bool shouldAbort = false;
        emit willDuplicateFile(static_cast<File*>(mItem), &shouldAbort);
        if (shouldAbort) {
            mUi->newNameEdit->selectAll();
            mUi->newNameEdit->setFocus();
            return;
        }

        if (!QFile::copy(mItem->fileInfo().absoluteFilePath(), newName)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to copy \"%1\" to \"%2\" in \"%3\".")
                .arg(oldName).arg(mNewName).arg(dir.absolutePath()));
            mUi->newNameEdit->selectAll();
            mUi->newNameEdit->setFocus();
            return;
        }
    }

    QDialog::done(r);
}
