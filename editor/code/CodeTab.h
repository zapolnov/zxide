#ifndef CODE_CODETAB_H
#define CODE_CODETAB_H

#include <QWidget>
#include "IEditorTab.h"
#include <memory>
#include <unordered_map>

class File;
class ScintillaDocument;
class Ui_CodeTab;

class CodeTab : public QWidget, public IEditorTab
{
    Q_OBJECT

public:
    explicit CodeTab(QWidget* parent = nullptr);
    ~CodeTab() override;

    void init(const QString& path);

    bool hasModifiedFiles() const override;
    bool canUndo() const override;
    bool canRedo() const override;
    bool canCut() const override;
    bool canCopy() const override;
    bool canPaste() const override;
    bool canClear() const override;
    bool canSelectAll() const override;
    bool canClearSelection() const override;
    bool canGoToLine() const override;

    bool saveAll() override;
    void undo() override;
    void redo() override;
    void cut() override;
    void copy() override;
    void paste() override;
    void clear() override;
    void selectAll() override;
    void clearSelection() override;
    void goToLine(int line) override;

    void reloadSettings() override;

private:
    std::unique_ptr<Ui_CodeTab> mUi;
    std::unordered_map<File*, ScintillaDocument*> mFiles;
    ScintillaDocument* mDummyDocument;
    File* mCurrentFile;

    bool saveFile(File* file);

    Q_SLOT void on_fileManager_willRenameFile(File* file, bool* shouldAbort);
    Q_SLOT void on_fileManager_fileSelected(File* file);
    Q_SLOT void on_fileManager_fileDisappeared(File* file);

    Q_SLOT void on_textEditor_updateUi(int updated);
    Q_SLOT void on_textEditor_savePointChanged(bool dirty);

    Q_DISABLE_COPY(CodeTab)
};

#endif
