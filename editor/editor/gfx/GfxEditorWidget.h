#ifndef EDITOR_GFX_GFXEDITORWIDGET_H
#define EDITOR_GFX_GFXEDITORWIDGET_H

#include <QWidget>
#include <QHash>
#include <QPixmap>
#include <vector>
#include <memory>

class GfxData;
class GfxFile;
class QJsonArray;
class QTimer;
class QLabel;

enum class GfxColorMode : int;

enum class GfxEditorTool
{
    None,
    Draw,
    DrawRect,
    Fill,
    Colorize,
    Select,
};

class GfxEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GfxEditorWidget(QWidget* parent = nullptr);
    ~GfxEditorWidget() override;

    int width() const;
    int height() const;

    bool isModified() const;
    void reset();
    void setSize(int w, int h);

    void setPreviewWidget(QLabel* preview);

    GfxColorMode colorMode() const { return mColorMode; }
    void setColorMode(GfxColorMode mode);
    void setColor(int color);

    bool gridVisible() const { return mGridVisible; }
    void setGridVisible(bool visible);

    void serialize(GfxFile& file);
    bool deserialize(GfxFile& file);
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

    GfxEditorTool currentTool() const;
    void setTool(GfxEditorTool tool);

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
    class ColorizeOperation;
    class ClearOperation;
    class PasteOperation;
    class ResizeOperation;

    class Tool;
    class DrawTool;
    class DrawRectTool;
    class FillTool;
    class ColorizeTool;
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

    GfxData* mGfxData;
    QTimer* mTimer;
    QLabel* mPreview;
    std::unique_ptr<Tool> mCurrentTool;
    std::vector<std::unique_ptr<Operation>> mUndoStack;
    size_t mUndoStackIndex;
    size_t mSavedIndex;
    Rect mSelection;
    QPoint mMousePosition;
    GfxColorMode mColorMode;
    Qt::MouseButton mMousePressed;
    int mSelectedColor;
    bool mFlash;
    static bool mGridVisible;

    void cancelInput();
    void updateMousePosition(QMouseEvent* event);

    void pushOperation(Operation* op);
    void pushOperation(std::unique_ptr<Operation>&& op);

    Q_DISABLE_COPY(GfxEditorWidget)
};

#endif
