#include "DisassemblyTab.h"
#include "ui_DisassemblyTab.h"

DisassemblyTab::DisassemblyTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_DisassemblyTab)
{
    mUi->setupUi(this);
}

DisassemblyTab::~DisassemblyTab()
{
}

void DisassemblyTab::setFocusToEditor()
{
    mUi->disassemblyWidget->setFocus();
}
