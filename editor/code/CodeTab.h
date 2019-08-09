#ifndef CODE_CODETAB_H
#define CODE_CODETAB_H

#include <QWidget>
#include "AbstractEditorTab.h"
#include <memory>
#include <unordered_map>

class Ui_CodeTab;
class ScintillaDocument;

class CodeTab : public AbstractEditorTab
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

    bool isFileModified(File* file) const override;
    bool saveFile(File* file) override;
    bool loadFile(File* file) override;
    void removeFile(File* file) override;

    Q_SLOT void on_textEditor_updateUi(int updated) { updateUi(); }
    Q_SLOT void on_textEditor_savePointChanged(bool dirty) { updateUi(); }

    Q_DISABLE_COPY(CodeTab)
};

#endif
