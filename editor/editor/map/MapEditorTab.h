#ifndef EDITOR_MAP_MAPEDITORTAB_H
#define EDITOR_MAP_MAPEDITORTAB_H

#include "editor/AbstractEditorTab.h"
#include <memory>

class QComboBox;
class QListWidgetItem;
class Ui_MapEditorTab;
enum class MapFormat : int;

class MapEditorTab : public AbstractEditorTab
{
    Q_OBJECT

public:
    explicit MapEditorTab(QWidget* parent = nullptr);
    ~MapEditorTab() override;

    void selectTile(unsigned char item);

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
    bool canPick() const override;
    bool canSelect() const override;
    bool canToggleGrid() const override;

    bool isDrawToolActive() const override;
    bool isDrawRectToolActive() const override;
    bool isFillToolActive() const override;
    bool isPickToolActive() const override;
    bool isSelectToolActive() const override;
    bool isGridActive() const override;

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
    void pick() override;
    void select() override;
    void toggleGrid() override;

    void reloadSettings() override;

    void setFocusToEditor() override;

private:
    std::unique_ptr<Ui_MapEditorTab> mUi;
    MapFormat mSavedFormat;
    QString mSavedTileset;
    int mSavedWidth;
    int mSavedHeight;
    int mSelectedTile;

    void reset();
    void setSaved();

    Q_SLOT void on_editorWidget_sizeChanged();
    Q_SLOT void on_editorWidget_itemPicked(unsigned char item);
    Q_SLOT void on_editorWidget_updateUi() { emit updateUi(); }
    Q_SLOT void on_formatCombo_currentIndexChanged(int) { emit updateUi(); }
    Q_SLOT void on_widthSpin_valueChanged(int);
    Q_SLOT void on_heightSpin_valueChanged(int);
    Q_SLOT void on_entitiesVisibleCheck_toggled(bool flag);
    Q_SLOT void on_entityNamesVisibleCheck_toggled(bool flag);
    Q_SLOT void on_flashingCheck_toggled(bool flag);
    Q_SLOT void on_paletteListWidget_currentItemChanged(QListWidgetItem* current, QListWidgetItem* previous);
    Q_SLOT void on_tilesetButton_clicked();
    Q_SLOT void on_exportImageButton_clicked();

    QString tilesetButtonSelection() const;
    void setTilesetButton(const QString& file);

    void refreshTileList();

    Q_DISABLE_COPY(MapEditorTab)
};

#endif
