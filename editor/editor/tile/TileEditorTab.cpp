#include "TileEditorTab.h"
#include "editor/FileManager.h"
#include "ui_TileEditorTab.h"

TileEditorTab::TileEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_TileEditorTab)
{
    mUi->setupUi(this);

    for (int i = 0; i < 128; i += 8) {
        mUi->widthCombo->addItem(QString::number(i), QVariant(i));
        mUi->heightCombo->addItem(QString::number(i), QVariant(i));
    }

    mUi->colorModeCombo->addItem(tr("Standard"));
    mUi->colorModeCombo->addItem(tr("Multicolor (8x1)"));
    mUi->colorModeCombo->addItem(tr("Bicolor (8x2)"));

    mUi->formatCombo->addItem(tr("Monochrome bitmap"));
    mUi->formatCombo->addItem(tr("NIRVANA+ code"));

    mUi->tabBar->addTab(tr("Pixels"));
    mUi->tabBar->addTab(tr("Colors"));
}

TileEditorTab::~TileEditorTab()
{
}

bool TileEditorTab::loadFile(File* f)
{
    QByteArray data = loadFileData(f);
    // FIXME

    reloadSettings();
    emit updateUi();

    return true;
}

bool TileEditorTab::isModified() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canUndo() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canRedo() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canCut() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canCopy() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canPaste() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canClear() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canSelectAll() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canClearSelection() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canDraw() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canDrawRect() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canFill() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canPick() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canSelect() const
{
    // FIXME
    return false;
}

bool TileEditorTab::save()
{
    // FIXME
    return true;
}

void TileEditorTab::undo()
{
    // FIXME
}

void TileEditorTab::redo()
{
    // FIXME
}

void TileEditorTab::cut()
{
    // FIXME
}

void TileEditorTab::copy()
{
    // FIXME
}

void TileEditorTab::paste()
{
    // FIXME
}

void TileEditorTab::clear()
{
    // FIXME
}

void TileEditorTab::selectAll()
{
    // FIXME
}

void TileEditorTab::clearSelection()
{
    // FIXME
}

void TileEditorTab::draw()
{
    // FIXME
}

void TileEditorTab::drawRect()
{
    // FIXME
}

void TileEditorTab::fill()
{
    // FIXME
}

void TileEditorTab::pick()
{
    // FIXME
}

void TileEditorTab::select()
{
    // FIXME
}

void TileEditorTab::reloadSettings()
{
}

void TileEditorTab::setFocusToEditor()
{
    mUi->editorWidget->setFocus();
}
