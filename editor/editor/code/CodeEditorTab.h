#ifndef EDITOR_CODE_CODEEDITORTAB_H
#define EDITOR_CODE_CODEEDITORTAB_H

#include "editor/AbstractEditorTab.h"
#include <memory>

class Ui_CodeEditorTab;
class ScintillaDocument;

class CodeEditorTab : public AbstractEditorTab
{
    Q_OBJECT

public:
    explicit CodeEditorTab(QWidget* parent = nullptr);
    ~CodeEditorTab() override;

    int line() const override;

    bool loadFile(File* f) override;

    QString lineColumnLabelText() const override;
    QString insOverwriteLabelText() const override;

    bool isModified() const override;
    bool canUndo() const override;
    bool canRedo() const override;
    bool canCut() const override;
    bool canCopy() const override;
    bool canPaste() const override;
    bool canClear() const override;
    bool canSelectAll() const override;
    bool canClearSelection() const override;
    bool canGoToLine() const override;
    bool canRunToCursor() const override;

    bool save() override;
    void undo() override;
    void redo() override;
    void cut() override;
    void copy() override;
    void paste() override;
    void clear() override;
    void selectAll() override;
    void clearSelection() override;
    void goToLine(int line) override;

    void updateTStates(ProgramDebugInfo* debugInfo) override;

    void reloadSettings() override;

    void setFocusToEditor() override;

private:
    std::unique_ptr<Ui_CodeEditorTab> mUi;
    std::unique_ptr<ScintillaDocument> mDummyDocument;
    std::unique_ptr<ScintillaDocument> mDocument;

    Q_SLOT void on_textEditor_updateUi(int updated) { emit updateUi(); }
    Q_SLOT void on_textEditor_savePointChanged(bool dirty) { emit updateUi(); }

    Q_DISABLE_COPY(CodeEditorTab)
};

#endif
