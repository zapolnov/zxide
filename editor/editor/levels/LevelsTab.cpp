#include "LevelsTab.h"
#include "ui_LevelsTab.h"

LevelsTab::LevelsTab(QWidget* parent)
    : QWidget(parent)
    , mUi(new Ui_LevelsTab)
{
    mUi->setupUi(this);
}

LevelsTab::~LevelsTab()
{
}

void LevelsTab::init(const QString& path)
{
    mUi->fileManager->init(path, QStringLiteral(".level"));
}
