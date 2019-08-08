#include "CodeTab.h"
#include <SciLexer.h>
#include "ui_CodeTab.h"
#include <QSaveFile>
#include <QMessageBox>
#include <QPushButton>

CodeTab::CodeTab(QWidget* parent)
    : QWidget(parent)
    , mUi(new Ui_CodeTab)
    , mDummyDocument(new ScintillaDocument(this))
    , mCurrentFile(nullptr)
{
    mUi->setupUi(this);
    mUi->textEditor->setLexer(SCLEX_ASM);
    mUi->textEditor->setEnabled(false);
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
    for (const auto& it : mFiles) {
        if (!it.second->is_save_point())
            return true;
    }

    return false;
}

bool CodeTab::canUndo() const
{
    auto it = mFiles.find(mCurrentFile);
    return mCurrentFile && it != mFiles.end() && it->second->can_undo();
}

bool CodeTab::canRedo() const
{
    auto it = mFiles.find(mCurrentFile);
    return mCurrentFile && it != mFiles.end() && it->second->can_redo();
}

bool CodeTab::canCut() const
{
    auto it = mFiles.find(mCurrentFile);
    return mCurrentFile && it != mFiles.end() && !mUi->textEditor->selectionEmpty();
}

bool CodeTab::canCopy() const
{
    auto it = mFiles.find(mCurrentFile);
    return mCurrentFile && it != mFiles.end() && !mUi->textEditor->selectionEmpty();
}

bool CodeTab::canPaste() const
{
    return mCurrentFile != nullptr;
}

bool CodeTab::canClear() const
{
    return mCurrentFile != nullptr;
}

bool CodeTab::canSelectAll() const
{
    return mCurrentFile != nullptr;
}

bool CodeTab::canClearSelection() const
{
    return mCurrentFile && !mUi->textEditor->selectionEmpty();
}

bool CodeTab::canGoToLine() const
{
    return mCurrentFile != nullptr;
}

bool CodeTab::saveAll()
{
    bool success = true;
    for (auto& it : mFiles) {
        if (!it.second->is_save_point())
            success = saveFile(it.first) && success;
    }

    emit updateUi();
    return success;
}

void CodeTab::undo()
{
    if (mCurrentFile)
        mUi->textEditor->undo();
}

void CodeTab::redo()
{
    if (mCurrentFile)
        mUi->textEditor->redo();
}

void CodeTab::cut()
{
    if (mCurrentFile)
        mUi->textEditor->cut();
}

void CodeTab::copy()
{
    if (mCurrentFile)
        mUi->textEditor->copy();
}

void CodeTab::paste()
{
    if (mCurrentFile)
        mUi->textEditor->paste();
}

void CodeTab::clear()
{
    if (mCurrentFile)
        mUi->textEditor->clear();
}

void CodeTab::selectAll()
{
    if (mCurrentFile)
        mUi->textEditor->selectAll();
}

void CodeTab::clearSelection()
{
    if (mCurrentFile)
        mUi->textEditor->clearSelections();
}

void CodeTab::goToLine(int line)
{
    if (mCurrentFile)
        mUi->textEditor->gotoLine(line);
}

void CodeTab::reloadSettings()
{
    mUi->textEditor->reloadSettings();
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

void CodeTab::on_fileManager_willRenameFile(File* file, bool* shouldAbort)
{
    auto it = mFiles.find(file);
    if (it == mFiles.end() || it->second->is_save_point())
        return;

    QMessageBox msgbox(QMessageBox::Warning,
        tr("Confirmation"), tr("Save changes to \"%1\"?").arg(file->name()), QMessageBox::NoButton, this);
    auto btnSave = msgbox.addButton(tr("Save"), QMessageBox::AcceptRole);
    auto btnDiscard = msgbox.addButton(tr("Discard"), QMessageBox::DestructiveRole);
    auto btnCancel = msgbox.addButton(tr("Cancel"), QMessageBox::RejectRole);
    msgbox.setDefaultButton(btnCancel);
    msgbox.setEscapeButton(btnCancel);
    msgbox.exec();

    auto clicked = msgbox.clickedButton();
    if (clicked == btnSave) {
        if (!saveFile(file))
            *shouldAbort = true;
    } else if (clicked != btnDiscard)
        *shouldAbort = true;
}

void CodeTab::on_fileManager_fileSelected(File* file)
{
    if (file == mCurrentFile)
        return;

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
        mCurrentFile = file;
        mUi->textEditor->set_doc(doc);
        mUi->textEditor->setEnabled(true);
    } else {
        mCurrentFile = nullptr;
        mUi->textEditor->set_doc(mDummyDocument);
        mUi->textEditor->setEnabled(false);
    }

    reloadSettings();
    updateUi();
}

void CodeTab::on_fileManager_fileDisappeared(File* file)
{
    mFiles.erase(file);
    if (mCurrentFile == file)
        on_fileManager_fileSelected(nullptr);
    updateUi();
}

void CodeTab::on_textEditor_updateUi(int)
{
    updateUi();
}

void CodeTab::on_textEditor_savePointChanged(bool)
{
    updateUi();
}
