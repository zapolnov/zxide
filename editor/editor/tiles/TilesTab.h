#ifndef EDITOR_TILES_TILESTAB_H
#define EDITOR_TILES_TILESTAB_H

#include <QWidget>
#include "editor/IEditorTab.h"
#include <memory>

class Ui_TilesTab;

class TilesTab : public QWidget, public IEditorTab
{
    Q_OBJECT

public:
    explicit TilesTab(QWidget* parent = nullptr);
    ~TilesTab() override;

    void init(const QString& path);

private:
    std::unique_ptr<Ui_TilesTab> mUi;

    Q_DISABLE_COPY(TilesTab)
};

#endif
