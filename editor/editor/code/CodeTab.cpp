#include "CodeTab.h"
#include <SciLexer.h>
#include "ui_CodeTab.h"
#include <QSaveFile>
#include <QMessageBox>

CodeTab::CodeTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_CodeTab)
    , mDummyDocument(new ScintillaDocument(this))
{
    mUi->setupUi(this);
    mUi->stackedWidget->setCurrentWidget(mUi->noEditor);
    mUi->textEditor->setEnabled(false);
    setFileManager(mUi->fileManager);
}

CodeTab::~CodeTab()
{
}

void CodeTab::init(const QString& path)
{
    mUi->fileManager->init(path, QStringLiteral(".asm"));
}

QString CodeTab::lineColumnLabelText() const
{
    if (!currentFile())
        return QString();

    auto pos = mUi->textEditor->currentPos();
    int line = mUi->textEditor->lineFromPosition(pos) + 1;
    int column = mUi->textEditor->column(pos) + 1;
    return tr("Line %1, column %2").arg(line).arg(column);
}

QString CodeTab::insOverwriteLabelText() const
{
    return (mUi->textEditor->overtype() ? tr("OVR") : tr("INS"));
}

bool CodeTab::hasModifiedFiles() const
{
    for (const auto& it : mFiles) {
        if (!it.second->is_save_point())
            return true;
    }

    return false;
}

bool CodeTab::canUndo() const
{
    auto it = mFiles.find(currentFile());
    return currentFile() && it != mFiles.end() && it->second->can_undo();
}

bool CodeTab::canRedo() const
{
    auto it = mFiles.find(currentFile());
    return currentFile() && it != mFiles.end() && it->second->can_redo();
}

bool CodeTab::canCut() const
{
    auto it = mFiles.find(currentFile());
    return currentFile() && it != mFiles.end() && !mUi->textEditor->selectionEmpty();
}

bool CodeTab::canCopy() const
{
    auto it = mFiles.find(currentFile());
    return currentFile() && it != mFiles.end() && !mUi->textEditor->selectionEmpty();
}

bool CodeTab::canPaste() const
{
    return currentFile() != nullptr;
}

bool CodeTab::canClear() const
{
    return currentFile() != nullptr;
}

bool CodeTab::canSelectAll() const
{
    return currentFile() != nullptr;
}

bool CodeTab::canClearSelection() const
{
    return currentFile() && !mUi->textEditor->selectionEmpty();
}

bool CodeTab::canGoToLine() const
{
    return currentFile() != nullptr;
}

bool CodeTab::canRunToCursor() const
{
    // FIXME
    return false;
}

bool CodeTab::saveAll()
{
    bool success = true;
    for (auto& it : mFiles) {
        if (!it.second->is_save_point())
            success = saveFile(it.first) && success;
    }

    updateUi();
    return success;
}

void CodeTab::undo()
{
    if (currentFile())
        mUi->textEditor->undo();
}

void CodeTab::redo()
{
    if (currentFile())
        mUi->textEditor->redo();
}

void CodeTab::cut()
{
    if (currentFile())
        mUi->textEditor->cut();
}

void CodeTab::copy()
{
    if (currentFile())
        mUi->textEditor->copy();
}

void CodeTab::paste()
{
    if (currentFile())
        mUi->textEditor->paste();
}

void CodeTab::clear()
{
    if (currentFile())
        mUi->textEditor->clear();
}

void CodeTab::selectAll()
{
    if (currentFile())
        mUi->textEditor->selectAll();
}

void CodeTab::clearSelection()
{
    if (currentFile())
        mUi->textEditor->clearSelections();
}

void CodeTab::goToLine(int line)
{
    if (currentFile())
        mUi->textEditor->gotoLine(line);
}

void CodeTab::reloadSettings()
{
    mUi->textEditor->reloadSettings();
}

void CodeTab::setFocusToEditor()
{
    mUi->textEditor->setFocus(true);
}

bool CodeTab::isFileModified(File* file) const
{
    auto it = mFiles.find(file);
    return (it != mFiles.end() && !it->second->is_save_point());
}

bool CodeTab::saveFile(File* file)
{
    auto it = mFiles.find(file);
    Q_ASSERT(it != mFiles.end());
    if (it == mFiles.end())
        return false;

    auto doc = it->second;

    QSaveFile f(file->fileInfo().absoluteFilePath());
    if (!f.open(QFile::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to save file \"%1\": %2").arg(f.fileName()).arg(f.errorString()));
        return false;
    }

    QByteArray data = doc->get_char_range(0, doc->length());
    qint64 bytesWritten = f.write(data.constData(), data.length());
    if (bytesWritten < 0) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(f.fileName()).arg(f.errorString()));
        return false;
    }

    if (bytesWritten != data.length()) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\".").arg(f.fileName()));
        return false;
    }

    if (!f.commit()) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to save file \"%1\": %2").arg(f.fileName()).arg(f.errorString()));
        return false;
    }

    doc->set_save_point();
    return true;
}

bool CodeTab::loadFile(File* file)
{
    ScintillaDocument* doc = nullptr;
    if (file) {
        int load_file = false;

        auto it = mFiles.find(file);
        if (it != mFiles.end()) {
            doc = it->second;
            load_file = doc->is_save_point();
        } else {
            doc = new ScintillaDocument(this);
            connect(doc, &ScintillaDocument::save_point, this, &CodeTab::on_textEditor_savePointChanged);
            mFiles[file] = doc;
            load_file = true;
        }

        if (load_file) {
            QByteArray fileData;
            QFile f(file->fileInfo().absoluteFilePath());
            if (f.open(QFile::ReadOnly))
                fileData = f.readAll();
            else {
                QMessageBox::critical(this, tr("Error"),
                    tr("Unable to open file \"%1\": %2").arg(f.fileName()).arg(f.errorString()));
            }

            QByteArray editorData = doc->get_char_range(0, doc->length());
            if (editorData != fileData) {
                doc->delete_chars(0, doc->length());
                doc->insert_string(0, fileData);
                doc->delete_undo_history();
                doc->set_save_point();
            }
        }
    }

    if (doc) {
        mUi->textEditor->set_doc(doc);
        mUi->textEditor->setLexer(SCLEX_ASM);
        mUi->textEditor->setEnabled(true);
        mUi->stackedWidget->setCurrentWidget(mUi->textEditor);
    } else {
        mUi->textEditor->set_doc(mDummyDocument);
        mUi->textEditor->setEnabled(false);
        mUi->stackedWidget->setCurrentWidget(mUi->noEditor);
    }

    reloadSettings();

    return doc != nullptr;
}

void CodeTab::removeFile(File* file)
{
    mFiles.erase(file);
}
