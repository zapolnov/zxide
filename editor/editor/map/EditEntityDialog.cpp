#include "EditEntityDialog.h"
#include "ui_EditEntityDialog.h"

EditEntityDialog::EditEntityDialog(const QString& entity, QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_EditEntityDialog)
{
    mUi->setupUi(this);
    mUi->entityEdit->setPlainText(entity);
}

EditEntityDialog::~EditEntityDialog()
{
}

QString EditEntityDialog::entity() const
{
    return mUi->entityEdit->toPlainText().trimmed();
}
