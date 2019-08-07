#include "CodeTab.h"
#include "ui_CodeTab.h"

CodeTab::CodeTab(QWidget* parent)
    : QWidget(parent)
    , mUi(new Ui_CodeTab)
{
    mUi->setupUi(this);
}

CodeTab::~CodeTab()
{
}

void CodeTab::init(const QString& path)
{
    mUi->fileManager->init(path, QStringLiteral(".asm"));
}

void CodeTab::reloadSettings()
{
    mUi->textEditor->reloadSettings();
}
