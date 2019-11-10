#include "MapEditorWidget.h"
#include "compiler/MapData.h"
#include "compiler/MapFile.h"
#include "compiler/TileSetData.h"
#include <QPainter>
#include <QMessageBox>
#include <QSaveFile>
#include <QClipboard>
#include <QMimeData>
#include <QApplication>
#include <QDataStream>
#include <QTimer>
#include <QInputDialog>
#include <QMouseEvent>

static const QString MimeType = QStringLiteral("application/x-zxspectrum-map");

///////////////////////////////////////////////////////////////////////////////
// Operations

class MapEditorWidget::Operation
{
public:
    Rect selectionRect;

    Operation() = default;
    virtual ~Operation() = default;

    virtual void redo(MapData* data) = 0;
    virtual void undo(MapData* data) = 0;

    Q_DISABLE_COPY(Operation)
};

class MapEditorWidget::DrawOperation : public Operation
{
public:
    DrawOperation(MapEditorWidget* widget, int x, int y, unsigned char value)
        : mX(x)
        , mY(y)
        , mNewValue(value)
    {
        auto it = widget->mTiles.find(mNewValue);
        mWidth = (it != widget->mTiles.end() ? it->width : 1);
        mHeight = (it != widget->mTiles.end() ? it->height : 1);
    }

    void redo(MapData* data) override
    {
        mOldData = data->bytes(mX, mY, mX + mWidth - 1, mY + mHeight - 1);
        int tileX = mNewValue % TileSetData::GridWidth;
        int tileY = mNewValue / TileSetData::GridWidth;
        for (int y = 0; y < mHeight; y++) {
            for (int x = 0; x < mWidth; x++)
            {
                if (data->isValidCoord(mX + x, mY + y))
                    data->at(mX + x, mY + y) = (tileY + y) * TileSetData::GridWidth + (tileX + x);
            }
        }
    }

    void undo(MapData* data) override
    {
        data->setBytes(mX, mY, mWidth, mHeight, mOldData);
    }

private:
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    QByteArray mOldData;
    unsigned char mNewValue;
};

class MapEditorWidget::DrawRectOperation : public Operation
{
public:
    DrawRectOperation(MapEditorWidget* widget, const Rect& r, unsigned char value)
        : mRect(r)
        , mOldValue(new unsigned char[r.width() * r.height()])
        , mNewValue(value)
    {
        auto it = widget->mTiles.find(mNewValue);
        mTileWidth = (it != widget->mTiles.end() ? it->width : 1);
        mTileHeight = (it != widget->mTiles.end() ? it->height : 1);
    }

    void redo(MapData* data) override
    {
        int w = mRect.width();
        int tileOriginX = mNewValue % TileSetData::GridWidth;
        int tileOriginY = mNewValue / TileSetData::GridWidth;
        int tileY = 0;
        for (int y = mRect.y1; y <= mRect.y2; y++) {
            int tileX = 0;
            for (int x = mRect.x1; x <= mRect.x2; x++) {
                unsigned char& ref = data->at(x, y);
                mOldValue[(y - mRect.y1) * w + (x - mRect.x1)] = ref;
                ref = (tileOriginY + tileY) * TileSetData::GridWidth + (tileOriginX + tileX);
                tileX = (tileX + 1) % mTileWidth;
            }
            tileY = (tileY + 1) % mTileHeight;
        }
    }

    void undo(MapData* data) override
    {
        int w = mRect.width();
        for (int y = mRect.y1; y <= mRect.y2; y++) {
            for (int x = mRect.x1; x <= mRect.x2; x++)
                data->at(x, y) = mOldValue[(y - mRect.y1) * w + (x - mRect.x1)];
        }
    }

private:
    Rect mRect;
    int mTileWidth;
    int mTileHeight;
    std::unique_ptr<unsigned char[]> mOldValue;
    unsigned char mNewValue;
};

class MapEditorWidget::FillOperation : public Operation
{
public:
    FillOperation(int x, int y, unsigned char value)
        : mStart(x, y)
        , mNewValue(value)
    {
    }

    void redo(MapData* data) override
    {
        mOldValue.clear();

        unsigned char original = data->at(mStart.first, mStart.second);
        if (original == mNewValue)
            return;

        std::vector<std::pair<int, int>> stack;
        stack.emplace_back(mStart);

        do {
            std::pair<int, int> p = stack.back();
            stack.pop_back();

            int x = p.first;
            int y = p.second;
            unsigned char& ref = data->at(x, y);

            if (ref == original) {
                mOldValue[p] = ref;
                ref = mNewValue;

                if (x > 0)
                    stack.emplace_back(x - 1, y);
                if (x < data->width() - 1)
                    stack.emplace_back(x + 1, y);
                if (y > 0)
                    stack.emplace_back(x, y - 1);
                if (y < data->height() - 1)
                    stack.emplace_back(x, y + 1);
            }
        } while (!stack.empty());
    }

    void undo(MapData* data) override
    {
        for (const auto& it : mOldValue)
            data->at(it.first.first, it.first.second) = it.second;
    }

private:
    std::pair<int, int> mStart;
    std::map<std::pair<int, int>, unsigned char> mOldValue;
    unsigned char mNewValue;
};

class MapEditorWidget::ClearOperation : public Operation
{
public:
    explicit ClearOperation(const Rect& r)
        : mRect(r)
    {
    }

    void redo(MapData* data) override
    {
        mOldValue = data->bytes(mRect.x1, mRect.y1, mRect.x2, mRect.y2);
        data->clear(mRect.x1, mRect.y1, mRect.x2, mRect.y2);
    }

    void undo(MapData* data) override
    {
        data->setBytes(mRect.x1, mRect.y1, mRect.width(), mRect.height(), mOldValue);
    }

private:
    Rect mRect;
    QByteArray mOldValue;
};

class MapEditorWidget::PasteOperation : public Operation
{
public:
    PasteOperation(const Rect& r, const QByteArray& data)
        : mRect(r)
        , mNewValue(data)
    {
    }

    void redo(MapData* data) override
    {
        mOldValue = data->bytes(mRect.x1, mRect.y1, mRect.x2, mRect.y2);
        data->setBytes(mRect.x1, mRect.y1, mRect.width(), mRect.height(), mNewValue);
    }

    void undo(MapData* data) override
    {
        data->setBytes(mRect.x1, mRect.y1, mRect.width(), mRect.height(), mOldValue);
    }

private:
    Rect mRect;
    QByteArray mOldValue;
    QByteArray mNewValue;
};

class MapEditorWidget::ResizeOperation : public Operation
{
public:
    ResizeOperation(int newWidth, int newHeight)
        : mNewWidth(newWidth)
        , mNewHeight(newHeight)
    {
    }

    void redo(MapData* data) override
    {
        mOldWidth = data->width();
        mOldHeight = data->height();
        mOldBytes = data->bytes();
        data->resize(mNewWidth, mNewHeight);
    }

    void undo(MapData* data) override
    {
        data->resize(mOldWidth, mOldHeight);
        data->setBytes(mOldBytes);
    }

private:
    QByteArray mOldBytes;
    int mOldWidth;
    int mOldHeight;
    int mNewWidth;
    int mNewHeight;
};

class MapEditorWidget::SetEntityOperation : public Operation
{
public:
    SetEntityOperation(MapEditorWidget* widget, int x, int y, std::string value)
        : mX(x)
        , mY(y)
        , mNewValue(std::move(value))
    {
    }

    void redo(MapData* data) override
    {
        mOldValue = data->entityAt(mX, mY);
        data->entityAt(mX, mY) = mNewValue;
    }

    void undo(MapData* data) override
    {
        data->entityAt(mX, mY) = mOldValue;
    }

private:
    int mX;
    int mY;
    std::string mOldValue;
    std::string mNewValue;
};


///////////////////////////////////////////////////////////////////////////////
// Tools

class MapEditorWidget::Tool
{
public:
    virtual ~Tool() = default;
    virtual MapEditorTool id() const = 0;
    virtual QCursor cursorAt(int x, int y) const { return Qt::ArrowCursor; }
    virtual void drawOverlay(MapEditorWidget* widget, QPainter& painter, int x, int y) const {}
    virtual void beginDrag(MapEditorWidget* widget, int x, int y) {}
    virtual void continueDrag(MapEditorWidget* widget, int x, int y) {}
    virtual void endDrag(MapEditorWidget* widget, bool cancel) {}
};

class MapEditorWidget::DrawTool : public Tool
{
public:
    DrawTool()
    {
    }

    MapEditorTool id() const override
    {
        return MapEditorTool::Draw;
    }

    static void drawOverlayTile(MapEditorWidget* widget, QPainter& painter, int x, int y)
    {
        int x1 = x * widget->mTileWidth;
        int y1 = y * widget->mTileHeight;

        const auto& tile = widget->mTiles[widget->mCurrentItem];

        painter.setOpacity(0.7f);
        painter.drawPixmap(x1, y1, tile.fullPixmap);
        painter.setOpacity(1.0f);

        painter.setPen(Qt::white);
        painter.setBrush(Qt::transparent);
        painter.drawRect(x1, y1, tile.width * widget->mTileWidth, tile.height * widget->mTileHeight);
    }

    void drawOverlay(MapEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        drawOverlayTile(widget, painter, x, y);
    }

    void beginDrag(MapEditorWidget* widget, int x, int y) override
    {
        emitPixel(widget, x, y);
    }

    void continueDrag(MapEditorWidget* widget, int x, int y) override
    {
        emitPixel(widget, x, y);
    }

private:
    void emitPixel(MapEditorWidget* widget, int x, int y)
    {
        if (!widget->mMapData->isValidCoord(x, y))
            return;
        if (widget->mMapData->at(x, y) == widget->mCurrentItem)
            return;
        widget->pushOperation(new DrawOperation(widget, x, y, widget->mCurrentItem));
    }

    Q_DISABLE_COPY(DrawTool)
};

class MapEditorWidget::DrawRectTool : public Tool
{
public:
    DrawRectTool()
        : mStartX(0)
        , mStartY(0)
        , mEndX(0)
        , mEndY(0)
        , mDragging(false)
    {
    }

    MapEditorTool id() const override
    {
        return MapEditorTool::DrawRect;
    }

    static Rect makeRect(MapData* data, int startX, int startY, int endX, int endY)
    {
        startX = qMin(qMax(startX, 0), data->width() - 1);
        startY = qMin(qMax(startY, 0), data->height() - 1);
        endX = qMin(qMax(endX, 0), data->width() - 1);
        endY = qMin(qMax(endY, 0), data->height() - 1);

        Rect r;
        r.x1 = qMin(startX, endX);
        r.y1 = qMin(startY, endY);
        r.x2 = qMax(startX, endX);
        r.y2 = qMax(startY, endY);

        return r;
    }

    void drawOverlay(MapEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        if (!mDragging) {
            DrawTool::drawOverlayTile(widget, painter, x, y);
            return;
        }

        Rect r = makeMapRect(widget->mMapData);
        QRect visualRect(r.x1 * widget->mTileWidth, r.y1 * widget->mTileHeight,
            r.width() * widget->mTileWidth, r.height() * widget->mTileHeight);

        const auto& tile = widget->mTiles[widget->mCurrentItem];
        int tileW = tile.width;
        int tileH = tile.height;

        painter.setOpacity(0.7f);
        int tileOriginX = widget->mCurrentItem % TileSetData::GridWidth;
        int tileOriginY = widget->mCurrentItem / TileSetData::GridWidth;
        int tileY = 0;
        for (int y = r.y1; y <= r.y2; y++) {
            int tileX = 0;
            for (int x = r.x1; x <= r.x2; x++) {
                int tileIndex = (tileOriginY + tileY) * TileSetData::GridWidth + (tileOriginX + tileX);
                painter.drawPixmap(x * widget->mTileWidth, y * widget->mTileHeight, widget->mTiles[tileIndex].pixmap1);
                tileX = (tileX + 1) % tileW;
            }
            tileY = (tileY + 1) % tileH;
        }
        painter.setOpacity(1.0f);

        painter.setPen(Qt::white);
        painter.setBrush(Qt::transparent);
        painter.drawRect(visualRect);
    }

    void beginDrag(MapEditorWidget* widget, int x, int y) override
    {
        mStartX = x;
        mStartY = y;
        mEndX = x;
        mEndY = y;
        mDragging = true;
    }

    void continueDrag(MapEditorWidget* widget, int x, int y) override
    {
        mEndX = x;
        mEndY = y;
    }

    void endDrag(MapEditorWidget* widget, bool cancel) override
    {
        if (!cancel) {
            Rect r = makeMapRect(widget->mMapData);
            widget->pushOperation(new DrawRectOperation(widget, r, widget->mCurrentItem));
        }
        mDragging = false;
    }

private:
    int mStartX;
    int mStartY;
    int mEndX;
    int mEndY;
    bool mDragging;

    Rect makeMapRect(MapData* data) const { return makeRect(data, mStartX, mStartY, mEndX, mEndY); }

    Q_DISABLE_COPY(DrawRectTool)
};

class MapEditorWidget::FillTool : public Tool
{
public:
    FillTool()
    {
    }

    MapEditorTool id() const override
    {
        return MapEditorTool::Fill;
    }

    void drawOverlay(MapEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        DrawTool::drawOverlayTile(widget, painter, x, y);
    }

    void beginDrag(MapEditorWidget* widget, int x, int y) override
    {
        mX = x;
        mY = y;
    }

    void continueDrag(MapEditorWidget* widget, int x, int y) override
    {
        mX = x;
        mY = y;
    }

    void endDrag(MapEditorWidget* widget, bool cancel) override
    {
        if (cancel)
            return;
        if (!widget->mMapData->isValidCoord(mX, mY))
            return;
        widget->pushOperation(new FillOperation(mX, mY, widget->mCurrentItem));
    }

private:
    int mX;
    int mY;

    Q_DISABLE_COPY(FillTool)
};

class MapEditorWidget::PickTool : public Tool
{
public:
    PickTool()
    {
    }

    MapEditorTool id() const override
    {
        return MapEditorTool::Pick;
    }

    void drawOverlay(MapEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        painter.setPen(Qt::white);
        painter.setBrush(Qt::transparent);
        painter.drawRect(x * widget->mTileWidth, y * widget->mTileHeight, widget->mTileWidth, widget->mTileHeight);
    }

    void beginDrag(MapEditorWidget* widget, int x, int y) override
    {
        pickPixel(widget, x, y);
    }

    void continueDrag(MapEditorWidget* widget, int x, int y) override
    {
        pickPixel(widget, x, y);
    }

private:
    void pickPixel(MapEditorWidget* widget, int x, int y)
    {
        if (!widget->mMapData->isValidCoord(x, y))
            return;
        emit widget->itemPicked(widget->mMapData->at(x, y));
    }

    Q_DISABLE_COPY(PickTool)
};

class MapEditorWidget::SelectTool : public Tool
{
public:
    SelectTool()
    {
    }

    MapEditorTool id() const override
    {
        return MapEditorTool::Select;
    }

    void drawOverlay(MapEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        painter.setPen(Qt::white);
        painter.setBrush(Qt::transparent);
        painter.drawRect(x * widget->mTileWidth, y * widget->mTileHeight, widget->mTileWidth, widget->mTileHeight);
    }

    void beginDrag(MapEditorWidget* widget, int x, int y) override
    {
        mStartX = x;
        mStartY = y;
        mEndX = x;
        mEndY = y;
        updateSelection(widget);
    }

    void continueDrag(MapEditorWidget* widget, int x, int y) override
    {
        mEndX = x;
        mEndY = y;
        updateSelection(widget);
    }

private:
    int mStartX;
    int mStartY;
    int mEndX;
    int mEndY;

    void updateSelection(MapEditorWidget* widget)
    {
        widget->mSelection = DrawRectTool::makeRect(widget->mMapData, mStartX, mStartY, mEndX, mEndY);
        widget->update();
        emit widget->updateUi();
    }

    Q_DISABLE_COPY(SelectTool)
};


///////////////////////////////////////////////////////////////////////////////

bool MapEditorWidget::mGridVisible = false;

MapEditorWidget::MapEditorWidget(QWidget* parent)
    : QWidget(parent)
    , mTileWidth(8)
    , mTileHeight(8)
    , mCurrentTool(new DrawTool())
    , mUndoStackIndex(0)
    , mSavedIndex(0)
    , mSelection(Rect::empty())
    , mMousePosition(-1, -1)
    , mCurrentItem(0)
    , mMousePressed(false)
    , mFlash(false)
{
    mMapData = new MapData(1, 1, this);
    setMouseTracking(true);

    mTimer = new QTimer(this);
    mTimer->start(1000 * 16 / 50);
    connect(mTimer, &QTimer::timeout, this, [this]{ mFlash = !mFlash; repaint(); });

    connect(mMapData, &MapData::sizeChanged, this, &MapEditorWidget::onSizeChanged);
    onSizeChanged();
}

MapEditorWidget::~MapEditorWidget()
{
}

int MapEditorWidget::width() const
{
    return mMapData->width();
}

int MapEditorWidget::height() const
{
    return mMapData->height();
}

void MapEditorWidget::setSize(int w, int h)
{
    if (w != mMapData->width() || h != mMapData->height())
        pushOperation(new ResizeOperation(w, h));
}

void MapEditorWidget::setTiles(QHash<int, MapEditorTile> tiles, int tileWidth, int tileHeight)
{
    mTiles = tiles;

    if (mTileWidth != tileWidth || mTileHeight != tileHeight) {
        mTileWidth = tileWidth;
        mTileHeight = tileHeight;
        onSizeChanged();
    }

    repaint();
}

bool MapEditorWidget::isModified() const
{
    return mUndoStackIndex != mSavedIndex;
}

void MapEditorWidget::reset()
{
    cancelInput();
    mMapData->clear();
    mUndoStack.clear();
    mUndoStackIndex = 0;
    mSelection = Rect::empty();
    mSavedIndex = 0;
    mTileWidth = 8;
    mTileHeight = 8;
    onSizeChanged();
    update();
    emit updateUi();
}

void MapEditorWidget::setGridVisible(bool visible)
{
    if (mGridVisible != visible) {
        mGridVisible = visible;
        update();
        emit updateUi();
    }
    repaint();
}

void MapEditorWidget::serialize(MapFile& file)
{
    file.serializeToJson(mMapData);
}

bool MapEditorWidget::deserialize(MapFile& file)
{
    if (!file.deserializeFromJson(mMapData)) {
        reset();
        return false;
    }

    cancelInput();
    mUndoStack.clear();
    mUndoStackIndex = 0;
    mSelection = Rect::empty();
    mSavedIndex = 0;
    update();
    emit updateUi();

    return true;
}

void MapEditorWidget::setSaved()
{
    mSavedIndex = mUndoStackIndex;
    update();
    emit updateUi();
}

bool MapEditorWidget::canUndo() const
{
    return mUndoStackIndex > 0;
}

bool MapEditorWidget::canRedo() const
{
    return mUndoStackIndex < mUndoStack.size();
}

void MapEditorWidget::undo()
{
    if (mUndoStackIndex > 0) {
        cancelInput();

        auto& op = mUndoStack[--mUndoStackIndex];
        op->undo(mMapData);
        mSelection = op->selectionRect;

        update();
        emit updateUi();
    }
}

void MapEditorWidget::redo()
{
    if (mUndoStackIndex < mUndoStack.size()) {
        cancelInput();

        mUndoStack[mUndoStackIndex++]->redo(mMapData);
        if (mUndoStackIndex < mUndoStack.size())
            mSelection = mUndoStack[mUndoStackIndex]->selectionRect;

        update();
        emit updateUi();
    }
}

bool MapEditorWidget::canCut() const
{
    return hasSelection();
}

bool MapEditorWidget::canCopy() const
{
    return hasSelection();
}

bool MapEditorWidget::canClearArea() const
{
    return hasSelection();
}

void MapEditorWidget::cut()
{
    if (!hasSelection())
        return;

    cancelInput();

    copy();

    pushOperation(new ClearOperation(mSelection));
    clearSelection();
}

void MapEditorWidget::copy()
{
    if (!hasSelection())
        return;

    cancelInput();

    QByteArray pixels = mMapData->bytes(mSelection.x1, mSelection.y1, mSelection.x2, mSelection.y2);

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream << mSelection.width();
    stream << mSelection.height();
    stream << pixels;

    auto mime = std::make_unique<QMimeData>();
    mime->setData(MimeType, data);
    mime->setText("");

    auto clipboard = QApplication::clipboard();
    clipboard->clear();
    clipboard->setMimeData(mime.release());
}

void MapEditorWidget::paste()
{
    auto clipboard = QApplication::clipboard();
    const QMimeData* mime = clipboard->mimeData();

    bool found = false;
    for (const auto& format : mime->formats()) {
        if (format == MimeType) {
            found = true;
            break;
        }
    }

    if (!found)
        return;

    cancelInput();

    QByteArray data = mime->data(MimeType);
    QDataStream stream(&data, QIODevice::ReadOnly);

    int w, h;
    stream >> w;
    stream >> h;
    if (w < 1 || h < 1)
        return;

    QByteArray pixels;
    stream >> pixels;

    int x, y;
    if (mMousePosition.x() >= 0 && mMousePosition.y() >= 0) {
        x = mMousePosition.x();
        y = mMousePosition.y();
    } else if (hasSelection()) {
        x = mSelection.x1;
        y = mSelection.y1;
    } else {
        x = 0;
        y = 0;
    }

    Rect r;
    r.x1 = x;
    r.y1 = y;
    r.x2 = x + w - 1;
    r.y2 = y + h - 1;

    pushOperation(new PasteOperation(r, pixels));
    clearSelection();
}

void MapEditorWidget::clearArea()
{
    if (!hasSelection())
        return;

    cancelInput();

    pushOperation(new ClearOperation(mSelection));
    clearSelection();
}

void MapEditorWidget::selectAll()
{
    if (mSelection.x1 != 0 || mSelection.y1 != 0
            || mSelection.width() != mMapData->width() || mSelection.height() != mMapData->height()) {
        cancelInput();
        mSelection.x1 = 0;
        mSelection.y1 = 0;
        mSelection.x2 = mMapData->width() - 1;
        mSelection.y2 = mMapData->height() - 1;
        update();
        emit updateUi();
    }
}

void MapEditorWidget::clearSelection()
{
    if (!mSelection.isEmpty()) {
        cancelInput();
        mSelection = Rect::empty();
        update();
        emit updateUi();
    }
}

unsigned char MapEditorWidget::at(int x, int y) const
{
    return mMapData->at(x, y);
}

unsigned char MapEditorWidget::at(const QPoint& p) const
{
    return mMapData->at(p);
}

void MapEditorWidget::setItem(unsigned char item)
{
    if (item != mCurrentItem) {
        cancelInput();
        mCurrentItem = item;
        update();
        emit updateUi();
    }
}

MapEditorTool MapEditorWidget::currentTool() const
{
    return (mCurrentTool ? mCurrentTool->id() : MapEditorTool::None);
}

void MapEditorWidget::setTool(MapEditorTool tool)
{
    if (currentTool() != tool) {
        cancelInput();
        switch (tool) {
            case MapEditorTool::None: mCurrentTool.reset(); break;
            case MapEditorTool::Draw: mCurrentTool.reset(new DrawTool()); break;
            case MapEditorTool::DrawRect: mCurrentTool.reset(new DrawRectTool()); break;
            case MapEditorTool::Fill: mCurrentTool.reset(new FillTool()); break;
            case MapEditorTool::Pick: mCurrentTool.reset(new PickTool()); break;
            case MapEditorTool::Select: mCurrentTool.reset(new SelectTool()); break;
        }
        update();
    }
    emit updateUi();
}

void MapEditorWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    for (int mapY = 0; mapY < mMapData->height(); mapY++) {
        for (int mapX = 0; mapX < mMapData->width(); mapX++) {
            const auto& tile = mTiles[mMapData->at(mapX, mapY)];
            int x = mapX * mTileWidth;
            int y = mapY * mTileHeight;
            painter.drawPixmap(x, y, (mFlash ? tile.pixmap2 : tile.pixmap1));

            const auto& e = mMapData->entityAt(mapX, mapY);
            if (!e.empty()) {
                painter.setPen(QPen(QColor(255, 255, 0), 0.5f, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
                painter.setBrush(QColor(255, 255, 0, 127));
                painter.drawRect(x, y, mTileWidth, mTileHeight);
            }
        }
    }

    if (mGridVisible) {
        painter.setCompositionMode(QPainter::RasterOp_SourceXorDestination);
        painter.setBrush(Qt::transparent);
        for (int gridY = 1; gridY < mMapData->height(); gridY++) {
            int y = gridY * mTileHeight;
            painter.setPen(QPen(QColor(255, 255, 255, 128), 1.0f));
            painter.drawLine(0, y, QWidget::width(), y);
        }
        for (int gridX = 1; gridX < mMapData->width(); gridX++) {
            int x = gridX * mTileWidth;
            painter.setPen(QPen(QColor(255, 255, 255, 128), 1.0f));
            painter.drawLine(x, 0, x, QWidget::height());
        }
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    }

    if (!mSelection.isEmpty()) {
        int x = mSelection.x1 * mTileWidth;
        int y = mSelection.y1 * mTileHeight;
        int w = mSelection.width() * mTileWidth;
        int h = mSelection.height() * mTileHeight;

        painter.setPen(QPen(QColor(0, 0, 255), 1.5f, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
        painter.setBrush(QColor(0, 0, 255, 127));
        painter.drawRect(x, y, w, h);
    }

    QCursor cursor = Qt::ArrowCursor;
    if (mCurrentTool && mMapData->isValidCoord(mMousePosition)) {
        cursor = mCurrentTool->cursorAt(mMousePosition.x(), mMousePosition.y());
        mCurrentTool->drawOverlay(this, painter, mMousePosition.x(), mMousePosition.y());
    }

    setCursor(cursor);
}

void MapEditorWidget::mousePressEvent(QMouseEvent* event)
{
    updateMousePosition(event);

    if (event->button() == Qt::LeftButton && mCurrentTool && !mMousePressed) {
        mMousePressed = true;
        mCurrentTool->beginDrag(this, mMousePosition.x(), mMousePosition.y());
        update();
        emit updateUi();
    }
}

void MapEditorWidget::mouseReleaseEvent(QMouseEvent* event)
{
    updateMousePosition(event);

    if (event->button() == Qt::LeftButton && mMousePressed) {
        mMousePressed = false;
        if (mCurrentTool) {
            mCurrentTool->continueDrag(this, mMousePosition.x(), mMousePosition.y());
            mCurrentTool->endDrag(this, false);
        }
        update();
        emit updateUi();
    }

    if (event->button() == Qt::RightButton && !mMousePressed) {
        auto pos = mMousePosition;
        if (mMapData->isValidCoord(pos)) {
            QString entity = QString::fromUtf8(mMapData->entityAt(pos).c_str());

            QInputDialog dlg(this);
            dlg.setInputMode(QInputDialog::TextInput);
            dlg.setWindowTitle(tr("Edit entity"));
            dlg.setLabelText(tr("Entity:"));
            dlg.setTextValue(entity);
            if (dlg.exec() != QDialog::Accepted)
                return;

            QString newEntity = dlg.textValue().trimmed();
            if (newEntity != entity)
                pushOperation(new SetEntityOperation(this, pos.x(), pos.y(), newEntity.toUtf8().constData()));
        }
    }
}

void MapEditorWidget::mouseMoveEvent(QMouseEvent* event)
{
    updateMousePosition(event);
    if (mMousePressed) {
        if (mCurrentTool)
            mCurrentTool->continueDrag(this, mMousePosition.x(), mMousePosition.y());
        update();
        emit updateUi();
    }
}

void MapEditorWidget::leaveEvent(QEvent* event)
{
    if (mMousePosition.x() != -1 || mMousePosition.y() != -1) {
        mMousePosition = QPoint(-1, -1);
        if (mMousePressed && mCurrentTool)
            mCurrentTool->continueDrag(this, mMousePosition.x(), mMousePosition.y());
        update();
        emit updateUi();
    }
}

void MapEditorWidget::cancelInput()
{
    if (mMousePressed) {
        mMousePressed = false;
        if (mCurrentTool)
            mCurrentTool->endDrag(this, true);
        update();
        emit updateUi();
    }
}

void MapEditorWidget::updateMousePosition(QMouseEvent* event)
{
    QPoint pos = event->pos();
    int x = pos.x() / mTileWidth;
    int y = pos.y() / mTileHeight;
    if (x != mMousePosition.x() || y != mMousePosition.y()) {
        mMousePosition = QPoint(x, y);
        update();
    }
}

void MapEditorWidget::pushOperation(Operation* op)
{
    pushOperation(std::unique_ptr<Operation>(op));
}

void MapEditorWidget::pushOperation(std::unique_ptr<Operation>&& op)
{
    if (mUndoStackIndex < mUndoStack.size()) {
        if (mSavedIndex > mUndoStackIndex)
            mSavedIndex = size_t(-1);
        mUndoStack.resize(mUndoStackIndex);
    }

    op->selectionRect = mSelection;

    mUndoStack.emplace_back(std::move(op));
    mUndoStack.back()->redo(mMapData);
    ++mUndoStackIndex;

    update();
    emit updateUi();
}

void MapEditorWidget::onSizeChanged()
{
    setFixedSize(mMapData->width() * mTileWidth, mMapData->height() * mTileHeight);
    emit sizeChanged();
}
