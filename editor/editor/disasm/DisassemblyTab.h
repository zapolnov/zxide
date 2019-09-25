#ifndef EDITOR_DISASM_DISASSEMBLYTAB_H
#define EDITOR_DISASM_DISASSEMBLYTAB_H

#include "editor/AbstractEditorTab.h"
#include <memory>

class Ui_DisassemblyTab;

class DisassemblyTab : public AbstractEditorTab
{
    Q_OBJECT

public:
    explicit DisassemblyTab(QWidget* parent = nullptr);
    ~DisassemblyTab() override;

    bool isDisassembly() const final override { return true; }

    void setFocusToEditor() override;

private:
    std::unique_ptr<Ui_DisassemblyTab> mUi;

    Q_DISABLE_COPY(DisassemblyTab)
};

#endif
