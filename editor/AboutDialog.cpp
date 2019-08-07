#include "AboutDialog.h"
#include "ui_AboutDialog.h"

AboutDialog::AboutDialog(QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_AboutDialog)
{
    mUi->setupUi(this);
}

AboutDialog::~AboutDialog()
{
}
