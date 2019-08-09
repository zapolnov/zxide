#ifndef IEDITORTAB_H
#define IEDITORTAB_H

#include <functional>

class IEditorTab
{
public:
    std::function<void()> updateUi = []{};

    virtual ~IEditorTab() = default;

    virtual bool canCreateFile() const { return false; }
    virtual bool canCreateDirectory() const { return false; }
    virtual bool hasModifiedFiles() const { return false; }
    virtual bool canRenameFile() const { return false; }
    virtual bool canDeleteFile() const { return false; }
    virtual bool canRefreshFileList() const { return false; }
    virtual bool canUndo() const { return false; }
    virtual bool canRedo() const { return false; }
    virtual bool canCut() const { return false; }
    virtual bool canCopy() const { return false; }
    virtual bool canPaste() const { return false; }
    virtual bool canClear() const { return false; }
    virtual bool canSelectAll() const { return false; }
    virtual bool canClearSelection() const { return false; }
    virtual bool canGoToLine() const { return false; }

    virtual void createFile() {}
    virtual void createDirectory() {}
    virtual bool saveAll() { return true; }
    virtual void renameFile() {}
    virtual void deleteFile() {}
    virtual void refreshFileList() {}
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
