#include "CodeEditorTab.h"
#include "editor/FileManager.h"
#include "ui_CodeEditorTab.h"
#include <SciLexer.h>

CodeEditorTab::CodeEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_CodeEditorTab)
{
    mUi->setupUi(this);
    mUi->textEditor->setEnabled(false);
}

CodeEditorTab::~CodeEditorTab()
{
}

int CodeEditorTab::line() const
{
    if (!mDocument)
        return -1;
    return mUi->textEditor->lineFromPosition(mUi->textEditor->currentPos()) + 1;
}

bool CodeEditorTab::loadFile(File* f)
{
    bool doLoadFile;
    if (mDocument)
        doLoadFile = (f != file() || mDocument->is_save_point());
    else {
        mDocument = std::make_unique<ScintillaDocument>(this);
        connect(mDocument.get(), &ScintillaDocument::save_point,
            this, &CodeEditorTab::on_textEditor_savePointChanged);
        doLoadFile = true;
    }

    if (doLoadFile) {
        QByteArray fileData = loadFileData(f);
        QByteArray editorData = mDocument->get_char_range(0, mDocument->length());
        if (editorData != fileData) {
            mDocument->delete_chars(0, mDocument->length());
            mDocument->insert_string(0, fileData);
            mDocument->delete_undo_history();
            mDocument->set_save_point();
        }
    }

    bool success = (mDocument != nullptr);
    if (!mDocument) {
        if (!mDummyDocument)
            mDummyDocument = std::make_unique<ScintillaDocument>(this);
        mUi->textEditor->set_doc(mDummyDocument.get());
        mUi->textEditor->setEnabled(false);
    } else {
        mUi->textEditor->set_doc(mDocument.get());
        mUi->textEditor->setLexer(SCLEX_ASM);
        mUi->textEditor->setEnabled(true);
    }

    reloadSettings();
    emit updateUi();

    return success;
}

QString CodeEditorTab::lineColumnLabelText() const
{
    if (!mDocument)
        return QString();

    auto pos = mUi->textEditor->currentPos();
    int line = mUi->textEditor->lineFromPosition(pos) + 1;
    int column = mUi->textEditor->column(pos) + 1;
    return tr("Line %1, column %2").arg(line).arg(column);
}

QString CodeEditorTab::insOverwriteLabelText() const
{
    if (!mDocument)
        return QString();

    return (mUi->textEditor->overtype() ? tr("OVR") : tr("INS"));
}

bool CodeEditorTab::isModified() const
{
    return mDocument && !mDocument->is_save_point();
}

bool CodeEditorTab::canUndo() const
{
    return mDocument && mDocument->can_undo();
}

bool CodeEditorTab::canRedo() const
{
    return mDocument && mDocument->can_redo();
}

bool CodeEditorTab::canCut() const
{
    return mDocument && !mUi->textEditor->selectionEmpty();
}

bool CodeEditorTab::canCopy() const
{
    return mDocument && !mUi->textEditor->selectionEmpty();
}

bool CodeEditorTab::canPaste() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::canClear() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::canSelectAll() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::canClearSelection() const
{
    return mDocument && !mUi->textEditor->selectionEmpty();
}

bool CodeEditorTab::canGoToLine() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::canRunToCursor() const
{
    return mDocument != nullptr;
}

bool CodeEditorTab::save()
{
    bool success = true;
    if (mDocument && !mDocument->is_save_point()) {
        success = writeFileData(mDocument->get_char_range(0, mDocument->length()));
        if (success)
            mDocument->set_save_point();
    }

    emit updateUi();
    return success;
}

void CodeEditorTab::undo()
{
    if (mDocument)
        mUi->textEditor->undo();
}

void CodeEditorTab::redo()
{
    if (mDocument)
        mUi->textEditor->redo();
}

void CodeEditorTab::cut()
{
    if (mDocument)
        mUi->textEditor->cut();
}

void CodeEditorTab::copy()
{
    if (mDocument)
        mUi->textEditor->copy();
}

void CodeEditorTab::paste()
{
    if (mDocument)
        mUi->textEditor->paste();
}

void CodeEditorTab::clear()
{
    if (mDocument)
        mUi->textEditor->clear();
}

void CodeEditorTab::selectAll()
{
    if (mDocument)
        mUi->textEditor->selectAll();
}

void CodeEditorTab::clearSelection()
{
    if (mDocument)
        mUi->textEditor->clearSelections();
}

void CodeEditorTab::goToLine(int line)
{
    if (mDocument)
        mUi->textEditor->gotoLine(line);
}

void CodeEditorTab::reloadSettings()
{
    mUi->textEditor->reloadSettings();
}

void CodeEditorTab::setFocusToEditor()
{
    static_cast<QWidget*>(mUi->textEditor)->setFocus();
}
