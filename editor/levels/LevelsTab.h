#ifndef LEVELS_LEVELSTAB_H
#define LEVELS_LEVELSTAB_H

#include <QWidget>
#include "IEditorTab.h"
#include <memory>

class Ui_LevelsTab;

class LevelsTab : public QWidget, public IEditorTab
{
    Q_OBJECT

public:
    explicit LevelsTab(QWidget* parent = nullptr);
    ~LevelsTab() override;

    void init(const QString& path);

private:
    std::unique_ptr<Ui_LevelsTab> mUi;

    Q_DISABLE_COPY(LevelsTab)
};

#endif
