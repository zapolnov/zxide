#ifndef EDITOR_MAP_MAPEDITORWIDGET_H
#define EDITOR_MAP_MAPEDITORWIDGET_H

#include <QWidget>
#include <QHash>
#include <QPixmap>
#include <vector>
#include <memory>

class MapData;
class MapFile;

enum class MapEditorTool
{
    None,
    Draw,
    DrawRect,
    Fill,
    Pick,
    Select,
};

class MapEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapEditorWidget(QWidget* parent = nullptr);
    ~MapEditorWidget() override;

    int width() const;
    int height() const;
    void setSize(int w, int h);

    void setTiles(QHash<int, QPixmap> tiles);

    bool isModified() const;
    void reset();

    bool gridVisible() const { return mGridVisible; }
    void setGridVisible(bool visible);

    void serialize(MapFile& file);
    bool deserialize(MapFile& file);
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

    void setItem(char item);

    MapEditorTool currentTool() const;
    void setTool(MapEditorTool tool);

protected:
    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void leaveEvent(QEvent* event) override;

signals:
    void updateUi();
    void sizeChanged();
    void itemPicked(char item);

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
    class PickTool;
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

    MapData* mMapData;
    std::unique_ptr<Tool> mCurrentTool;
    std::vector<std::unique_ptr<Operation>> mUndoStack;
    size_t mUndoStackIndex;
    size_t mSavedIndex;
    QHash<int, QPixmap> mTiles;
    Rect mSelection;
    QPoint mMousePosition;
    char mCurrentItem;
    bool mMousePressed;
    static bool mGridVisible;

    void cancelInput();
    void updateMousePosition(QMouseEvent* event);

    void pushOperation(Operation* op);
    void pushOperation(std::unique_ptr<Operation>&& op);

    Q_DISABLE_COPY(MapEditorWidget)
};

#endif
