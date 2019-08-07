#ifndef CODE_CODETAB_H
#define CODE_CODETAB_H

#include <QWidget>
#include "IEditorTab.h"
#include <memory>

class Ui_CodeTab;

class CodeTab : public QWidget, public IEditorTab
{
    Q_OBJECT

public:
    explicit CodeTab(QWidget* parent = nullptr);
    ~CodeTab() override;

    void init(const QString& path);

    void reloadSettings() override;

private:
    std::unique_ptr<Ui_CodeTab> mUi;

    Q_DISABLE_COPY(CodeTab)
};

#endif
