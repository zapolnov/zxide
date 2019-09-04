#ifndef EDITOR_TILESET_TILESETEDITORTAB_H
#define EDITOR_TILESET_TILESETEDITORTAB_H

#include "compiler/TileSetData.h"
#include "editor/AbstractEditorTab.h"
#include <QIcon>
#include <vector>
#include <memory>

class QToolButton;
class QComboBox;
class Ui_TileSetEditorTab;
class GfxData;
enum class GfxColorMode : int;

class TileSetEditorTab : public AbstractEditorTab
{
    Q_OBJECT

public:
    explicit TileSetEditorTab(QWidget* parent = nullptr);
    ~TileSetEditorTab() override;

    bool isModified() const override;

    bool loadFile(File* f) override;
    bool save() override;

private:
    std::unique_ptr<Ui_TileSetEditorTab> mUi;
    std::vector<QToolButton*> mButtons;
    QIcon mImageMissingIcon;
    TileSetData mData;
    int mSavedTileWidth;
    int mSavedTileHeight;
    bool mModified;

    Q_SLOT void on_tileWidthCombo_currentIndexChanged(int);
    Q_SLOT void on_tileHeightCombo_currentIndexChanged(int);

    void setSaved();

    void reset();

    void refresh();
    bool loadTile(const QString& fileName, GfxData* data, GfxColorMode* colorMode = nullptr);

    void onButtonClicked(QToolButton* button, int x, int y);

    static bool selectItem(QComboBox* combo, const QVariant& value);
    static QVariant selectedItem(const QComboBox* combo);

    Q_DISABLE_COPY(TileSetEditorTab)
};

#endif
