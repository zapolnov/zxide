#include "TilesTab.h"
#include "ui_TilesTab.h"

TilesTab::TilesTab(QWidget* parent)
    : QWidget(parent)
    , mUi(new Ui_TilesTab)
{
    mUi->setupUi(this);
}

TilesTab::~TilesTab()
{
}

void TilesTab::init(const QString& path)
{
    mUi->fileManager->init(path, QStringLiteral(".tile"));
}
