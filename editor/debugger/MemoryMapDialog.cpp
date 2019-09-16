#include "MemoryMapDialog.h"
#include "ui_MemoryMapDialog.h"

MemoryMapDialog::MemoryMapDialog(QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_MemoryMapDialog)
{
    mUi->setupUi(this);
}

MemoryMapDialog::~MemoryMapDialog()
{
}
