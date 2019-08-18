#ifndef EDITOR_ABSTRACTEDITORTAB_H
#define EDITOR_ABSTRACTEDITORTAB_H

#include <QWidget>

class File;

class AbstractEditorTab : public QWidget
{
    Q_OBJECT

public:
    explicit AbstractEditorTab(QWidget* parent = nullptr);
    ~AbstractEditorTab() override;

    File* file() const { return mFile; }
    virtual int line() const { return -1; }

    virtual bool loadFile(File*) { return false; }

    virtual QString lineColumnLabelText() const { return QString(); }
    virtual QString insOverwriteLabelText() const { return QString(); }

    virtual bool isModified() const { return false; }
    virtual bool canUndo() const { return false; }
    virtual bool canRedo() const { return false; }
    virtual bool canCut() const { return false; }
    virtual bool canCopy() const { return false; }
    virtual bool canPaste() const { return false; }
    virtual bool canClear() const { return false; }
    virtual bool canSelectAll() const { return false; }
    virtual bool canClearSelection() const { return false; }
    virtual bool canGoToLine() const { return false; }
    virtual bool canRunToCursor() const { return false; }

    virtual bool save() { return true; }
    virtual void undo() {}
    virtual void redo() {}
    virtual void cut() {}
    virtual void copy() {}
    virtual void paste() {}
    virtual void clear() {}
    virtual void selectAll() {}
    virtual void clearSelection() {}
    virtual void goToLine(int line) {}
    virtual void setFocusToEditor() {}

    virtual void reloadSettings() {}

signals:
    void updateUi();

protected:
    QByteArray loadFileData(File* file);
    bool writeFileData(const QByteArray& data);

private:
    File* mFile;

    Q_DISABLE_COPY(AbstractEditorTab)
};

#endif
