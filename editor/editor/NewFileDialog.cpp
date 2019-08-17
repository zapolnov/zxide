#include "NewFileDialog.h"
#include "editor/EditorTabFactory.h"
#include "editor/FileManager.h"
#include "ui_NewFileDialog.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>

NewFileDialog::NewFileDialog(Directory* directory, QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_NewFileDialog)
    , mDirectory(directory)
{
    mUi->setupUi(this);

    mUi->nameEdit->setText(tr("New file"));
    mUi->nameEdit->selectAll();
    mUi->nameEdit->setFocus();

    bool first = true;
    for (const auto& it : EditorTabFactory::instance()->formats()) {
        auto item = new QListWidgetItem(it->icon, it->name, mUi->typeList);
        item->setData(Qt::UserRole, it->extension);
        if (first) {
            mUi->typeList->setCurrentItem(item);
            first = false;
        }
    }
}

NewFileDialog::~NewFileDialog()
{
}

void NewFileDialog::done(int r)
{
    if (r == QDialog::Accepted) {
        mName = mUi->nameEdit->text().trimmed();
        if (mName.isEmpty()) {
            QMessageBox::critical(this, tr("Error"), tr("File name should not be empty."));
            mUi->nameEdit->setFocus();
            return;
        }

        QListWidgetItem* item = mUi->typeList->currentItem();
        if (!item) {
            QMessageBox::critical(this, tr("Error"), tr("Please select file type."));
            return;
        }

        QString extension = item->data(Qt::UserRole).toString();
        if (!mName.endsWith(QStringLiteral(".%1").arg(extension)))
            mName = QStringLiteral("%1.%2").arg(mName).arg(extension);

        QDir dir(mDirectory->fileInfo().absoluteFilePath());
        QFile file(dir.absoluteFilePath(mName));
        if (file.exists()) {
            QMessageBox::critical(this, tr("Error"), tr("File or directory \"%1\" already exists.").arg(mName));
            mUi->nameEdit->selectAll();
            mUi->nameEdit->setFocus();
            return;
        }

        if (!file.open(QFile::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to create file \"%1\" in \"%2\": %3")
                .arg(mName).arg(dir.absolutePath()).arg(file.errorString()));
            mUi->nameEdit->selectAll();
            mUi->nameEdit->setFocus();
            return;
        }

        file.close();
    }

    QDialog::done(r);
}
