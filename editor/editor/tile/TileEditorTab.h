#ifndef EDITOR_TILE_TILEEDITORTAB_H
#define EDITOR_TILE_TILEEDITORTAB_H

#include "editor/AbstractEditorTab.h"
#include <memory>

class QComboBox;
class Ui_TileEditorTab;

class TileEditorTab : public AbstractEditorTab
{
    Q_OBJECT

public:
    explicit TileEditorTab(QWidget* parent = nullptr);
    ~TileEditorTab() override;

    bool loadFile(File* f) override;

    bool isModified() const override;
    bool canUndo() const override;
    bool canRedo() const override;
    bool canCut() const override;
    bool canCopy() const override;
    bool canPaste() const override;
    bool canClear() const override;
    bool canSelectAll() const override;
    bool canClearSelection() const override;
    bool canDraw() const override;
    bool canDrawRect() const override;
    bool canFill() const override;
    bool canSelect() const override;

    bool isDrawToolActive() const override;
    bool isDrawRectToolActive() const override;
    bool isFillToolActive() const override;
    bool isSelectToolActive() const override;

    bool save() override;
    void undo() override;
    void redo() override;
    void cut() override;
    void copy() override;
    void paste() override;
    void clear() override;
    void selectAll() override;
    void clearSelection() override;
    void draw() override;
    void drawRect() override;
    void fill() override;
    void select() override;

    void reloadSettings() override;

    void setFocusToEditor() override;

private:
    std::unique_ptr<Ui_TileEditorTab> mUi;
    QString mSavedIdentifier;
    QString mSavedSection;
    QString mSavedFormat;
    QString mSavedColorMode;
    int mSavedWidth;
    int mSavedHeight;

    void reset();
    void setSaved();

    Q_SLOT void on_editorWidget_sizeChanged();
    Q_SLOT void on_editorWidget_updateUi() { emit updateUi(); }
    Q_SLOT void on_identifierEdit_textChanged() { emit updateUi(); }
    Q_SLOT void on_sectionEdit_textChanged() { emit updateUi(); }
    Q_SLOT void on_formatCombo_currentIndexChanged(int) { emit updateUi(); }
    Q_SLOT void on_colorModeCombo_currentIndexChanged(int) { emit updateUi(); }
    Q_SLOT void on_widthCombo_currentIndexChanged(int);
    Q_SLOT void on_heightCombo_currentIndexChanged(int);

    static bool selectItem(QComboBox* combo, const QVariant& value);
    static QVariant selectedItem(const QComboBox* combo);

    Q_DISABLE_COPY(TileEditorTab)
};

#endif
