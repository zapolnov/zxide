#include "CodeTab.h"
#include <SciLexer.h>
#include "ui_CodeTab.h"

CodeTab::CodeTab(QWidget* parent)
    : QWidget(parent)
    , mUi(new Ui_CodeTab)
{
    mUi->setupUi(this);
    mUi->textEditor->setLexer(SCLEX_ASM);
}

CodeTab::~CodeTab()
{
}

void CodeTab::init(const QString& path)
{
    mUi->fileManager->init(path, QStringLiteral(".asm"));
}

bool CodeTab::hasModifiedFiles() const
{
    // FIXME
    return false;
}

bool CodeTab::canUndo() const
{
    return mUi->textEditor->isEnabled() && mUi->textEditor->canUndo();
}

bool CodeTab::canRedo() const
{
    return mUi->textEditor->isEnabled() && mUi->textEditor->canRedo();
}

bool CodeTab::canCut() const
{
    return mUi->textEditor->isEnabled() && !mUi->textEditor->selectionEmpty();
}

bool CodeTab::canCopy() const
{
    return mUi->textEditor->isEnabled() && !mUi->textEditor->selectionEmpty();
}

bool CodeTab::canPaste() const
{
    return mUi->textEditor->isEnabled() && mUi->textEditor->canPaste();
}

bool CodeTab::canClear() const
{
    return mUi->textEditor->isEnabled();
}

bool CodeTab::canSelectAll() const
{
    return mUi->textEditor->isEnabled();
}

bool CodeTab::canClearSelection() const
{
    return mUi->textEditor->isEnabled() && !mUi->textEditor->selectionEmpty();
}

bool CodeTab::canGoToLine() const
{
    return mUi->textEditor->isEnabled();
}

bool CodeTab::saveAll()
{
    // FIXME
    mUi->textEditor->setSavePoint();
    return true;
}

void CodeTab::undo()
{
    mUi->textEditor->undo();
}

void CodeTab::redo()
{
    mUi->textEditor->redo();
}

void CodeTab::cut()
{
    mUi->textEditor->cut();
}

void CodeTab::copy()
{
    mUi->textEditor->copy();
}

void CodeTab::paste()
{
    mUi->textEditor->paste();
}

void CodeTab::clear()
{
    mUi->textEditor->clear();
}

void CodeTab::selectAll()
{
    mUi->textEditor->selectAll();
}

void CodeTab::clearSelection()
{
    mUi->textEditor->clearSelections();
}

void CodeTab::goToLine(int line)
{
    mUi->textEditor->gotoLine(line);
}

void CodeTab::reloadSettings()
{
    mUi->textEditor->reloadSettings();
}

void CodeTab::on_textEditor_updateUi(int)
{
    updateUi();
}
