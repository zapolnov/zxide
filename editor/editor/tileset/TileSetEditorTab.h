#ifndef EDITOR_TILESET_TILESETEDITORTAB_H
#define EDITOR_TILESET_TILESETEDITORTAB_H

#include "compiler/TileSetData.h"
#include "editor/AbstractEditorTab.h"
#include <QIcon>
#include <vector>
#include <memory>

class QToolButton;
class Ui_TileSetEditorTab;

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
    bool mModified;

    void refresh();

    void onButtonClicked(QToolButton* button, int x, int y);

    Q_DISABLE_COPY(TileSetEditorTab)
};

#endif
