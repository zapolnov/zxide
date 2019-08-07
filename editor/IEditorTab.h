#ifndef IEDITORTAB_H
#define IEDITORTAB_H

class IEditorTab
{
public:
    virtual ~IEditorTab() = default;

    virtual bool hasModifiedFiles() const { return false; }
    virtual bool canUndo() const { return false; }
    virtual bool canRedo() const { return false; }
    virtual bool canCut() const { return false; }
    virtual bool canCopy() const { return false; }
    virtual bool canPaste() const { return false; }
    virtual bool canClear() const { return false; }
    virtual bool canSelectAll() const { return false; }
    virtual bool canClearSelection() const { return false; }
    virtual bool canGoToLine() const { return false; }

    virtual bool saveAll() { return true; }
    virtual void undo() {}
    virtual void redo() {}
    virtual void cut() {}
    virtual void copy() {}
    virtual void paste() {}
    virtual void clear() {}
    virtual void selectAll() {}
    virtual void clearSelection() {}
    virtual void goToLine(int line) {}

    virtual void reloadSettings() {}
};

#endif
