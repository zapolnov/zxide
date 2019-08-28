#include "TileEditorWidget.h"
#include "TileData.h"
#include <QPainter>
#include <QMessageBox>
#include <QSaveFile>
#include <QFile>
#include <QClipboard>
#include <QMimeData>
#include <QApplication>
#include <QDataStream>
#include <QMouseEvent>
#include <QTimer>
#include <QJsonArray>

static const QString MimeType = QStringLiteral("application/x-zxspectrum-tile");
static const int PixelWidth = 8;
static const int PixelHeight = 8;

static QColor Palette[] = {
    QColor(0x00, 0x00, 0x00),
    QColor(0x00, 0x00, 0xc0),
    QColor(0xc0, 0x00, 0x00),
    QColor(0xc0, 0x00, 0xc0),
    QColor(0x00, 0xc0, 0x00),
    QColor(0x00, 0xc0, 0xc0),
    QColor(0xc0, 0xc0, 0x00),
    QColor(0xc0, 0xc0, 0xc0),
    QColor(0x00, 0x00, 0x00),
    QColor(0x00, 0x00, 0xff),
    QColor(0xff, 0x00, 0x00),
    QColor(0xff, 0x00, 0xff),
    QColor(0x00, 0xff, 0x00),
    QColor(0x00, 0xff, 0xff),
    QColor(0xff, 0xff, 0x00),
    QColor(0xff, 0xff, 0xff),
};

namespace
{
    struct Zone
    {
        int x;
        int y;
        int h;
    };

    Zone getZone(const TileEditorWidget* widget, int x, int y)
    {
        Zone z;
        z.x = (x & ~7);
        z.y = 0;
        z.h = 0;

        switch (widget->colorMode()) {
            case TileColorMode::Standard: z.y = (y & ~7); z.h = 8; break;
            case TileColorMode::Multicolor: z.y = y; z.h = 1; break;
            case TileColorMode::Bicolor: z.y = (y & ~1); z.h = 2; break;
        }

        return z;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Operations

class TileEditorWidget::Operation
{
public:
    Rect selectionRect;

    Operation() = default;
    virtual ~Operation() = default;

    virtual void redo(TileData* data) = 0;
    virtual void undo(TileData* data) = 0;

    Q_DISABLE_COPY(Operation)
};

class TileEditorWidget::DrawOperation : public Operation
{
public:
    DrawOperation(int x, int y, char value)
        : mX(x)
        , mY(y)
        , mNewValue(value)
    {
    }

    void redo(TileData* data) override
    {
        char& ref = data->at(mX, mY);
        mOldValue = ref;
        ref = mNewValue;
    }

    void undo(TileData* data) override
    {
        data->at(mX, mY) = mOldValue;
    }

private:
    int mX;
    int mY;
    char mOldValue;
    char mNewValue;
};

class TileEditorWidget::DrawRectOperation : public Operation
{
public:
    DrawRectOperation(const Rect& r, char value)
        : mRect(r)
        , mOldValue(new char[r.width() * r.height()])
        , mNewValue(value)
    {
    }

    void redo(TileData* data) override
    {
        int w = mRect.width();
        for (int y = mRect.y1; y <= mRect.y2; y++) {
            for (int x = mRect.x1; x <= mRect.x2; x++) {
                char& ref = data->at(x, y);
                mOldValue[(y - mRect.y1) * w + (x - mRect.x1)] = ref;
                ref = mNewValue;
            }
        }
    }

    void undo(TileData* data) override
    {
        int w = mRect.width();
        for (int y = mRect.y1; y <= mRect.y2; y++) {
            for (int x = mRect.x1; x <= mRect.x2; x++)
                data->at(x, y) = mOldValue[(y - mRect.y1) * w + (x - mRect.x1)];
        }
    }

private:
    Rect mRect;
    std::unique_ptr<char[]> mOldValue;
    char mNewValue;
};

class TileEditorWidget::FillOperation : public Operation
{
public:
    FillOperation(int x, int y, char value)
        : mStart(x, y)
        , mNewValue(value)
    {
    }

    void redo(TileData* data) override
    {
        mOldValue.clear();

        char original = data->at(mStart.first, mStart.second);
        if (original == mNewValue)
            return;

        std::vector<std::pair<int, int>> stack;
        stack.emplace_back(mStart);

        do {
            std::pair<int, int> p = stack.back();
            stack.pop_back();

            int x = p.first;
            int y = p.second;
            char& ref = data->at(x, y);

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

    void undo(TileData* data) override
    {
        for (const auto& it : mOldValue)
            data->at(it.first.first, it.first.second) = it.second;
    }

private:
    std::pair<int, int> mStart;
    std::map<std::pair<int, int>, char> mOldValue;
    char mNewValue;
};

class TileEditorWidget::ColorizeOperation : public Operation
{
public:
    ColorizeOperation(Zone zone, int color, bool ink)
        : mZone(zone)
        , mColor(color)
        , mInk(ink)
    {
    }

    static char calcNewAttrib(TileData* data, int x, int y, int color, bool ink)
    {
        char attrib = data->attribAt(x, y, TileColorMode::Multicolor) & 0x3F;
        if (ink)
            attrib = (attrib & ~7) | (color & 7);
        else
            attrib = (attrib & ~0x38) | ((color & 7) << 3);
        return attrib | ((color & 8) << 3) | ((color & 16) << 3);
    }

    void redo(TileData* data) override
    {
        int x1 = mZone.x;
        int y1 = mZone.y;
        int x2 = x1 + 7;
        int y2 = y1 + mZone.h - 1;

        mOldValue = data->attrib(x1, y1, x2, y2);

        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++)
                data->attribAt(x, y, TileColorMode::Multicolor) = calcNewAttrib(data, x, y, mColor, mInk);
        }
    }

    void undo(TileData* data) override
    {
        data->setAttrib(mZone.x, mZone.y, 8, mZone.h, mOldValue);
    }

private:
    QByteArray mOldValue;
    Zone mZone;
    int mColor;
    bool mInk;
};

class TileEditorWidget::ClearOperation : public Operation
{
public:
    explicit ClearOperation(const Rect& r)
        : mRect(r)
    {
    }

    void redo(TileData* data) override
    {
        mOldValue = data->bytes(mRect.x1, mRect.y1, mRect.x2, mRect.y2);
        data->clear(mRect.x1, mRect.y1, mRect.x2, mRect.y2);
    }

    void undo(TileData* data) override
    {
        data->setBytes(mRect.x1, mRect.y1, mRect.width(), mRect.height(), mOldValue);
    }

private:
    Rect mRect;
    QByteArray mOldValue;
};

class TileEditorWidget::PasteOperation : public Operation
{
public:
    PasteOperation(const Rect& r, const QByteArray& data)
        : mRect(r)
        , mNewValue(data)
    {
    }

    void redo(TileData* data) override
    {
        mOldValue = data->bytes(mRect.x1, mRect.y1, mRect.x2, mRect.y2);
        data->setBytes(mRect.x1, mRect.y1, mRect.width(), mRect.height(), mNewValue);
    }

    void undo(TileData* data) override
    {
        data->setBytes(mRect.x1, mRect.y1, mRect.width(), mRect.height(), mOldValue);
    }

private:
    Rect mRect;
    QByteArray mOldValue;
    QByteArray mNewValue;
};

class TileEditorWidget::ResizeOperation : public Operation
{
public:
    ResizeOperation(int newWidth, int newHeight)
        : mNewWidth(newWidth)
        , mNewHeight(newHeight)
    {
    }

    void redo(TileData* data) override
    {
        mOldWidth = data->width();
        mOldHeight = data->height();
        mOldBytes = data->bytes();
        data->resize(mNewWidth, mNewHeight);
    }

    void undo(TileData* data) override
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


///////////////////////////////////////////////////////////////////////////////
// Tools

class TileEditorWidget::Tool
{
public:
    virtual ~Tool() = default;
    virtual TileEditorTool id() const = 0;
    virtual QCursor cursorAt(int x, int y) const { return Qt::ArrowCursor; }
    virtual void drawOverlay(TileEditorWidget* widget, QPainter& painter, int x, int y) const {}
    virtual void beginDrag(TileEditorWidget* widget, int x, int y, char value) {}
    virtual void continueDrag(TileEditorWidget* widget, int x, int y) {}
    virtual void endDrag(TileEditorWidget* widget, bool cancel) {}
};

class TileEditorWidget::DrawTool : public Tool
{
public:
    DrawTool()
        : mValue(0)
        , mDragging(false)
    {
    }

    TileEditorTool id() const override
    {
        return TileEditorTool::Draw;
    }

    static void drawOverlayTile(TileEditorWidget* widget, QPainter& painter, int x, int y, char value)
    {
        int x1 = x * PixelWidth;
        int y1 = y * PixelHeight;

        painter.setOpacity(0.7f);
        painter.fillRect(x1, y1, PixelWidth, PixelHeight, (value ? Qt::white : Qt::black));
        painter.setOpacity(1.0f);

        painter.setPen(QColor(128, 128, 128));
        painter.setBrush(Qt::transparent);
        painter.drawRect(x1, y1, PixelWidth, PixelHeight);
    }

    void drawOverlay(TileEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        drawOverlayTile(widget, painter, x, y, (mDragging ? mValue : 1));
    }

    void beginDrag(TileEditorWidget* widget, int x, int y, char value) override
    {
        mDragging = true;
        mValue = value;
        emitPixel(widget, x, y, value);
    }

    void continueDrag(TileEditorWidget* widget, int x, int y) override
    {
        emitPixel(widget, x, y, mValue);
    }

    void endDrag(TileEditorWidget* widget, bool cancel) override
    {
        mDragging = false;
    }

private:
    char mValue;
    bool mDragging;

    void emitPixel(TileEditorWidget* widget, int x, int y, char value)
    {
        if (!widget->mTileData->isValidCoord(x, y))
            return;
        if (widget->mTileData->at(x, y) == value)
            return;
        widget->pushOperation(new DrawOperation(x, y, value));
    }

    Q_DISABLE_COPY(DrawTool)
};

class TileEditorWidget::DrawRectTool : public Tool
{
public:
    DrawRectTool()
        : mStartX(0)
        , mStartY(0)
        , mEndX(0)
        , mEndY(0)
        , mValue(0)
        , mDragging(false)
    {
    }

    TileEditorTool id() const override
    {
        return TileEditorTool::DrawRect;
    }

    static Rect makeRect(TileData* data, int startX, int startY, int endX, int endY)
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

    void drawOverlay(TileEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        if (!mDragging) {
            DrawTool::drawOverlayTile(widget, painter, x, y, 1);
            return;
        }

        Rect r = makeTileRect(widget->mTileData);
        QRect visualRect(r.x1 * PixelWidth, r.y1 * PixelHeight, r.width() * PixelWidth, r.height() * PixelHeight);

        painter.setOpacity(0.7f);
        for (int y = r.y1; y <= r.y2; y++) {
            for (int x = r.x1; x <= r.x2; x++)
                painter.fillRect(x * PixelWidth, y * PixelHeight, PixelWidth, PixelHeight, Qt::white);
        }
        painter.setOpacity(1.0f);

        painter.setPen(QColor(128, 128, 128));
        painter.setBrush(Qt::transparent);
        painter.drawRect(visualRect);
    }

    void beginDrag(TileEditorWidget* widget, int x, int y, char value) override
    {
        mStartX = x;
        mStartY = y;
        mEndX = x;
        mEndY = y;
        mValue = value;
        mDragging = true;
    }

    void continueDrag(TileEditorWidget* widget, int x, int y) override
    {
        mEndX = x;
        mEndY = y;
    }

    void endDrag(TileEditorWidget* widget, bool cancel) override
    {
        if (!cancel) {
            Rect r = makeTileRect(widget->mTileData);
            widget->pushOperation(new DrawRectOperation(r, mValue));
        }
        mDragging = false;
    }

private:
    int mStartX;
    int mStartY;
    int mEndX;
    int mEndY;
    char mValue;
    bool mDragging;

    Rect makeTileRect(TileData* data) const { return makeRect(data, mStartX, mStartY, mEndX, mEndY); }

    Q_DISABLE_COPY(DrawRectTool)
};

class TileEditorWidget::FillTool : public Tool
{
public:
    FillTool()
        : mValue(0)
        , mDragging(false)
    {
    }

    TileEditorTool id() const override
    {
        return TileEditorTool::Fill;
    }

    void drawOverlay(TileEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        DrawTool::drawOverlayTile(widget, painter, x, y, (mDragging ? mValue : 1));
    }

    void beginDrag(TileEditorWidget* widget, int x, int y, char value) override
    {
        mX = x;
        mY = y;
        mDragging = true;
        mValue = value;
    }

    void continueDrag(TileEditorWidget* widget, int x, int y) override
    {
        mX = x;
        mY = y;
    }

    void endDrag(TileEditorWidget* widget, bool cancel) override
    {
        mDragging = false;
        if (cancel)
            return;
        if (!widget->mTileData->isValidCoord(mX, mY))
            return;
        widget->pushOperation(new FillOperation(mX, mY, mValue));
    }

private:
    int mX;
    int mY;
    char mValue;
    bool mDragging;

    Q_DISABLE_COPY(FillTool)
};

class TileEditorWidget::ColorizeTool : public Tool
{
public:
    ColorizeTool()
        : mX(0)
        , mY(0)
        , mValue(0)
    {
    }

    TileEditorTool id() const override
    {
        return TileEditorTool::Colorize;
    }

    void drawOverlay(TileEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        auto z = getZone(widget, x, y);
        painter.setPen(QColor(128, 128, 128));
        painter.setBrush(QColor(128, 128, 128, 128));
        painter.drawRect(z.x * PixelWidth, z.y * PixelHeight, 8 * PixelWidth, z.h * PixelHeight);
    }

    void beginDrag(TileEditorWidget* widget, int x, int y, char value) override
    {
        mX = x;
        mY = y;
        mValue = value;
        colorize(widget, mX, mY, widget->mSelectedColor, mValue != 0);
    }

    void continueDrag(TileEditorWidget* widget, int x, int y) override
    {
        mX = x;
        mY = y;
        colorize(widget, mX, mY, widget->mSelectedColor, mValue != 0);
    }

    void endDrag(TileEditorWidget* widget, bool cancel) override
    {
    }

private:
    int mX;
    int mY;
    char mValue;

    void colorize(TileEditorWidget* widget, int x, int y, int color, bool ink)
    {
        if (!widget->mTileData->isValidCoord(x, y))
            return;

        auto z = getZone(widget, x, y);

        bool equal = true;
        for (int yy = 0; yy < z.h; yy++) {
            int a = ColorizeOperation::calcNewAttrib(widget->mTileData, x, z.y + yy, color, ink);
            if (widget->mTileData->attribAt(x, y, widget->mColorMode) != a) {
                equal = false;
                break;
            }
        }

        if (equal)
            return;

        widget->pushOperation(new ColorizeOperation(z, color, ink));
    }

    Q_DISABLE_COPY(ColorizeTool)
};

class TileEditorWidget::SelectTool : public Tool
{
public:
    SelectTool()
    {
    }

    TileEditorTool id() const override
    {
        return TileEditorTool::Select;
    }

    void drawOverlay(TileEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        painter.setPen(QColor(128, 128, 128));
        painter.setBrush(Qt::transparent);
        painter.drawRect(x * PixelWidth, y * PixelHeight, PixelWidth, PixelHeight);
    }

    void beginDrag(TileEditorWidget* widget, int x, int y, char value) override
    {
        mStartX = x;
        mStartY = y;
        mEndX = x;
        mEndY = y;
        updateSelection(widget);
    }

    void continueDrag(TileEditorWidget* widget, int x, int y) override
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

    void updateSelection(TileEditorWidget* widget)
    {
        widget->mSelection = DrawRectTool::makeRect(widget->mTileData, mStartX, mStartY, mEndX, mEndY);
        widget->update();
        emit widget->updateUi();
    }

    Q_DISABLE_COPY(SelectTool)
};


///////////////////////////////////////////////////////////////////////////////

TileEditorWidget::TileEditorWidget(QWidget* parent)
    : QWidget(parent)
    , mCurrentTool(new DrawTool())
    , mUndoStackIndex(0)
    , mSavedIndex(0)
    , mSelection(Rect::empty())
    , mMousePosition(-1, -1)
    , mColorMode(TileColorMode::Standard)
    , mMousePressed(Qt::NoButton)
    , mSelectedColor(0)
    , mFlash(false)
    , mGridVisible(true)
{
    mTileData = new TileData(8, 8, this);
    setMouseTracking(true);

    mTimer = new QTimer(this);
    mTimer->start(1000 * 16 / 50);
    connect(mTimer, &QTimer::timeout, this, [this]{ mFlash = !mFlash; repaint(); });

    auto onSizeChanged = [this] {
            setFixedSize(mTileData->width() * PixelWidth, mTileData->height() * PixelHeight);
            emit sizeChanged();
        };

    connect(mTileData, &TileData::sizeChanged, this, onSizeChanged);
    onSizeChanged();
}

TileEditorWidget::~TileEditorWidget()
{
}

int TileEditorWidget::width() const
{
    return mTileData->width();
}

int TileEditorWidget::height() const
{
    return mTileData->height();
}

bool TileEditorWidget::isModified() const
{
    return mUndoStackIndex != mSavedIndex;
}

void TileEditorWidget::reset()
{
    cancelInput();
    mTileData->clear();
    mUndoStack.clear();
    mUndoStackIndex = 0;
    mSelection = Rect::empty();
    mSavedIndex = 0;
    update();
    emit updateUi();
}

void TileEditorWidget::setSize(int w, int h)
{
    if (w != mTileData->width() || h != mTileData->height())
        pushOperation(new ResizeOperation(w, h));
}

void TileEditorWidget::setColorMode(TileColorMode mode)
{
    if (mColorMode != mode) {
        mColorMode = mode;
        update();
        emit updateUi();
    }
}

void TileEditorWidget::setColor(int color)
{
    if (mSelectedColor != color) {
        mSelectedColor = color;
        update();
        emit updateUi();
    }
}

void TileEditorWidget::setGridVisible(bool visible)
{
    if (mGridVisible != visible) {
        mGridVisible = visible;
        update();
        emit updateUi();
    }
    repaint();
}

QJsonArray TileEditorWidget::pixels() const
{
    QJsonArray result;
    for (int y = 0; y < mTileData->height(); y++) {
        QString str(mTileData->width(), '?');
        for (int x = 0; x < mTileData->width(); x++)
            str[x] = (mTileData->at(x, y) ? '#' : '.');
        result.append(str);
    }
    return result;
}

QJsonArray TileEditorWidget::attribs() const
{
    QJsonArray result;

    for (int y = 0; y < mTileData->height(); y++) {
        QJsonArray lineAttribs;
        for (int x = 0; x < mTileData->width(); x += 8)
            lineAttribs.append(mTileData->attribAt(x, y, TileColorMode::Multicolor));
        result.append(lineAttribs);
    }

    return result;
}

bool TileEditorWidget::setPixels(int w, int h, QJsonArray data, QJsonArray attribs)
{
    if (data.size() != h || attribs.size() != h)
        return false;

    if (w != mTileData->width() || h != mTileData->height())
        mTileData->resize(w, h);

    mTileData->clear();
    for (int y = 0; y < h; y++) {
        const QString& str = data[y].toString();
        if (str.length() != w)
            return false;

        for (int x = 0; x < w; x++) {
            QChar ch = str[x];
            if (ch == '#')
                mTileData->at(x, y) = 1;
            else if (ch == '.')
                mTileData->at(x, y) = 0;
            else
                return false;
        }

        QJsonArray lineAttribs = attribs[y].toArray();
        if (lineAttribs.size() != ((w + 7) >> 3))
            return false;

        for (int x = 0, i = 0; x < w; x += 8, i++)
            mTileData->attribAt(x, y, TileColorMode::Multicolor) = (char)(lineAttribs[i].toInt() & 0xff);
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

void TileEditorWidget::setSaved()
{
    mSavedIndex = mUndoStackIndex;
    update();
    emit updateUi();
}

bool TileEditorWidget::canUndo() const
{
    return mUndoStackIndex > 0;
}

bool TileEditorWidget::canRedo() const
{
    return mUndoStackIndex < mUndoStack.size();
}

void TileEditorWidget::undo()
{
    if (mUndoStackIndex > 0) {
        cancelInput();

        auto& op = mUndoStack[--mUndoStackIndex];
        op->undo(mTileData);
        mSelection = op->selectionRect;

        update();
        emit updateUi();
    }
}

void TileEditorWidget::redo()
{
    if (mUndoStackIndex < mUndoStack.size()) {
        cancelInput();

        mUndoStack[mUndoStackIndex++]->redo(mTileData);
        if (mUndoStackIndex < mUndoStack.size())
            mSelection = mUndoStack[mUndoStackIndex]->selectionRect;

        update();
        emit updateUi();
    }
}

bool TileEditorWidget::canCut() const
{
    return hasSelection();
}

bool TileEditorWidget::canCopy() const
{
    return hasSelection();
}

bool TileEditorWidget::canClearArea() const
{
    return hasSelection();
}

void TileEditorWidget::cut()
{
    if (!hasSelection())
        return;

    cancelInput();

    copy();

    pushOperation(new ClearOperation(mSelection));
    clearSelection();
}

void TileEditorWidget::copy()
{
    if (!hasSelection())
        return;

    cancelInput();

    QByteArray pixels = mTileData->bytes(mSelection.x1, mSelection.y1, mSelection.x2, mSelection.y2);

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

void TileEditorWidget::paste()
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

void TileEditorWidget::clearArea()
{
    if (!hasSelection())
        return;

    cancelInput();

    pushOperation(new ClearOperation(mSelection));
    clearSelection();
}

void TileEditorWidget::selectAll()
{
    if (mSelection.x1 != 0 || mSelection.y1 != 0
            || mSelection.width() != mTileData->width() || mSelection.height() != mTileData->height()) {
        cancelInput();
        mSelection.x1 = 0;
        mSelection.y1 = 0;
        mSelection.x2 = mTileData->width() - 1;
        mSelection.y2 = mTileData->height() - 1;
        update();
        emit updateUi();
    }
}

void TileEditorWidget::clearSelection()
{
    if (!mSelection.isEmpty()) {
        cancelInput();
        mSelection = Rect::empty();
        update();
        emit updateUi();
    }
}

char TileEditorWidget::at(int x, int y) const
{
    return mTileData->at(x, y);
}

char TileEditorWidget::at(const QPoint& p) const
{
    return mTileData->at(p);
}

TileEditorTool TileEditorWidget::currentTool() const
{
    return (mCurrentTool ? mCurrentTool->id() : TileEditorTool::None);
}

void TileEditorWidget::setTool(TileEditorTool tool)
{
    if (currentTool() != tool) {
        cancelInput();
        switch (tool) {
            case TileEditorTool::None: mCurrentTool.reset(); break;
            case TileEditorTool::Draw: mCurrentTool.reset(new DrawTool()); break;
            case TileEditorTool::DrawRect: mCurrentTool.reset(new DrawRectTool()); break;
            case TileEditorTool::Fill: mCurrentTool.reset(new FillTool()); break;
            case TileEditorTool::Colorize: mCurrentTool.reset(new ColorizeTool()); break;
            case TileEditorTool::Select: mCurrentTool.reset(new SelectTool()); break;
        }
        update();
    }
    emit updateUi();
}

void TileEditorWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    for (int tileY = 0; tileY < mTileData->height(); tileY++) {
        for (int tileX = 0; tileX < mTileData->width(); tileX++) {
            int x = tileX * PixelWidth;
            int y = tileY * PixelHeight;

            char value = mTileData->at(tileX, tileY);
            char attrib = mTileData->attribAt(tileX, tileY, mColorMode);

            if ((attrib & 0x80) != 0 && mFlash)
                value = !value;

            int color = (value ? attrib & 7 : (attrib & 0x38) >> 3);
            if (attrib & 0x40)
                color += 8;

            painter.fillRect(x, y, PixelWidth, PixelHeight, Palette[color]);
        }
    }

    if (mGridVisible) {
        painter.setBrush(Qt::transparent);
        for (int tileY = 0; tileY < mTileData->height(); tileY++) {
            float w = ((tileY & 7) == 0 ? 0.5f : 1.0f);
            int y = tileY * PixelHeight;
            painter.setPen(QPen(QColor(128, 128, 128, 128), w));
            painter.drawLine(0, y, QWidget::width(), y);
        }
        for (int tileX = 0; tileX < mTileData->width(); tileX++) {
            float w = ((tileX & 7) == 0 ? 0.5f : 1.0f);
            int x = tileX * PixelWidth;
            painter.setPen(QPen(QColor(128, 128, 128, 128), w));
            painter.drawLine(x, 0, x, QWidget::height());
        }
    }

    if (!mSelection.isEmpty()) {
        int x = mSelection.x1 * PixelWidth;
        int y = mSelection.y1 * PixelHeight;
        int w = mSelection.width() * PixelWidth;
        int h = mSelection.height() * PixelHeight;

        painter.setPen(QPen(QColor(255, 0, 0), 1.5f, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
        painter.setBrush(QColor(255, 0, 0, 127));
        painter.drawRect(x, y, w, h);
    }

    QCursor cursor = Qt::ArrowCursor;
    if (mCurrentTool && mTileData->isValidCoord(mMousePosition)) {
        cursor = mCurrentTool->cursorAt(mMousePosition.x(), mMousePosition.y());
        mCurrentTool->drawOverlay(this, painter, mMousePosition.x(), mMousePosition.y());
    }

    setCursor(cursor);
}

void TileEditorWidget::mousePressEvent(QMouseEvent* event)
{
    updateMousePosition(event);
    if ((event->button() == Qt::LeftButton || event->button() == Qt::RightButton)
            && mCurrentTool && mMousePressed == Qt::NoButton) {
        mMousePressed = event->button();
        mCurrentTool->beginDrag(this, mMousePosition.x(), mMousePosition.y(), mMousePressed == Qt::LeftButton);
        update();
        emit updateUi();
    }
}

void TileEditorWidget::mouseReleaseEvent(QMouseEvent* event)
{
    updateMousePosition(event);
    if (event->button() == mMousePressed) {
        mMousePressed = Qt::NoButton;
        if (mCurrentTool) {
            mCurrentTool->continueDrag(this, mMousePosition.x(), mMousePosition.y());
            mCurrentTool->endDrag(this, false);
        }
        update();
        emit updateUi();
    }
}

void TileEditorWidget::mouseMoveEvent(QMouseEvent* event)
{
    updateMousePosition(event);
    if (mMousePressed != Qt::NoButton) {
        if (mCurrentTool)
            mCurrentTool->continueDrag(this, mMousePosition.x(), mMousePosition.y());
        update();
        emit updateUi();
    }
}

void TileEditorWidget::leaveEvent(QEvent* event)
{
    if (mMousePosition.x() != -1 || mMousePosition.y() != -1) {
        mMousePosition = QPoint(-1, -1);
        if (mMousePressed != Qt::NoButton && mCurrentTool)
            mCurrentTool->continueDrag(this, mMousePosition.x(), mMousePosition.y());
        update();
        emit updateUi();
    }
}

void TileEditorWidget::cancelInput()
{
    if (mMousePressed != Qt::NoButton) {
        mMousePressed = Qt::NoButton;
        if (mCurrentTool)
            mCurrentTool->endDrag(this, true);
        update();
        emit updateUi();
    }
}

void TileEditorWidget::updateMousePosition(QMouseEvent* event)
{
    QPoint pos = event->pos();
    int x = pos.x() / PixelWidth;
    int y = pos.y() / PixelHeight;
    if (x != mMousePosition.x() || y != mMousePosition.y()) {
        mMousePosition = QPoint(x, y);
        update();
    }
}

void TileEditorWidget::pushOperation(Operation* op)
{
    pushOperation(std::unique_ptr<Operation>(op));
}

void TileEditorWidget::pushOperation(std::unique_ptr<Operation>&& op)
{
    if (mUndoStackIndex < mUndoStack.size()) {
        if (mSavedIndex > mUndoStackIndex)
            mSavedIndex = size_t(-1);
        mUndoStack.resize(mUndoStackIndex);
    }

    op->selectionRect = mSelection;

    mUndoStack.emplace_back(std::move(op));
    mUndoStack.back()->redo(mTileData);
    ++mUndoStackIndex;

    update();
    emit updateUi();
}
