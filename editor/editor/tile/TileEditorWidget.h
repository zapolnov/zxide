#ifndef EDITOR_TILE_TILEEDITORWIDGET_H
#define EDITOR_TILE_TILEEDITORWIDGET_H

#include <QWidget>
#include <QHash>
#include <QPixmap>
#include <vector>
#include <memory>

class TileData;
class QJsonArray;

enum class TileEditorTool
{
    None,
    Draw,
    DrawRect,
    Fill,
    Select,
};

class TileEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TileEditorWidget(QWidget* parent = nullptr);
    ~TileEditorWidget() override;

    int width() const;
    int height() const;

    bool isModified() const;
    void reset();
    void setSize(int w, int h);

    QJsonArray pixels() const;
    bool setPixels(int w, int h, QJsonArray data);
    void setSaved();

    bool canUndo() const;
    bool canRedo() const;
    void undo();
    void redo();

    bool canCut() const;
    bool canCopy() const;
    bool canClearArea() const;

    void cut();
    void copy();
    void paste();
    void clearArea();

    bool hasSelection() const { return !mSelection.isEmpty(); }
    void selectAll();
    void clearSelection();

    char at(int x, int y) const;
    char at(const QPoint& p) const;

    TileEditorTool currentTool() const;
    void setTool(TileEditorTool tool);

protected:
    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void leaveEvent(QEvent* event) override;

signals:
    void updateUi();
    void sizeChanged();

private:
    class Operation;
    class DrawOperation;
    class DrawRectOperation;
    class FillOperation;
    class ClearOperation;
    class PasteOperation;
    class ResizeOperation;

    class Tool;
    class DrawTool;
    class DrawRectTool;
    class FillTool;
    class SelectTool;

    struct Rect
    {
        int x1;
        int y1;
        int x2;
        int y2;

        bool isEmpty() const { return x1 == 0 && y1 == 0 && x2 == -1 && y2 == -1; }
        int width() const { return (x2 - x1 + 1); }
        int height() const { return (y2 - y1 + 1); }

        static Rect empty()
        {
            Rect r;
            r.x1 = 0;
            r.y1 = 0;
            r.x2 = -1;
            r.y2 = -1;
            return r;
        }
    };

    TileData* mTileData;
    std::unique_ptr<Tool> mCurrentTool;
    std::vector<std::unique_ptr<Operation>> mUndoStack;
    size_t mUndoStackIndex;
    size_t mSavedIndex;
    Rect mSelection;
    QPoint mMousePosition;
    Qt::MouseButton mMousePressed;

    void cancelInput();
    void updateMousePosition(QMouseEvent* event);

    void pushOperation(Operation* op);
    void pushOperation(std::unique_ptr<Operation>&& op);

    Q_DISABLE_COPY(TileEditorWidget)
};

#endif
