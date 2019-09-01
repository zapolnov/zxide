#include "GfxEditorWidget.h"
#include "compiler/GfxData.h"
#include "compiler/GfxFile.h"
#include "util/GfxFileUtil.h"
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
#include <QLabel>

static const QString MimeType = QStringLiteral("application/x-zxspectrum-graphic");
static const int PixelWidth = 8;
static const int PixelHeight = 8;

namespace
{
    struct Zone
    {
        int x;
        int y;
        int h;
    };

    Zone getZone(const GfxEditorWidget* widget, int x, int y)
    {
        Zone z;
        z.x = (x & ~7);
        z.y = 0;
        z.h = 0;

        switch (widget->colorMode()) {
            case GfxColorMode::Standard: z.y = (y & ~7); z.h = 8; break;
            case GfxColorMode::Multicolor: z.y = y; z.h = 1; break;
            case GfxColorMode::Bicolor: z.y = (y & ~1); z.h = 2; break;
        }

        return z;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Operations

class GfxEditorWidget::Operation
{
public:
    Rect selectionRect;

    Operation() = default;
    virtual ~Operation() = default;

    virtual void redo(GfxData* data) = 0;
    virtual void undo(GfxData* data) = 0;

    Q_DISABLE_COPY(Operation)
};

class GfxEditorWidget::DrawOperation : public Operation
{
public:
    DrawOperation(int x, int y, char value)
        : mX(x)
        , mY(y)
        , mNewValue(value)
    {
    }

    void redo(GfxData* data) override
    {
        char& ref = data->at(mX, mY);
        mOldValue = ref;
        ref = mNewValue;
    }

    void undo(GfxData* data) override
    {
        data->at(mX, mY) = mOldValue;
    }

private:
    int mX;
    int mY;
    char mOldValue;
    char mNewValue;
};

class GfxEditorWidget::DrawRectOperation : public Operation
{
public:
    DrawRectOperation(const Rect& r, char value)
        : mRect(r)
        , mOldValue(new char[r.width() * r.height()])
        , mNewValue(value)
    {
    }

    void redo(GfxData* data) override
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

    void undo(GfxData* data) override
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

class GfxEditorWidget::FillOperation : public Operation
{
public:
    FillOperation(int x, int y, char value)
        : mStart(x, y)
        , mNewValue(value)
    {
    }

    void redo(GfxData* data) override
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

    void undo(GfxData* data) override
    {
        for (const auto& it : mOldValue)
            data->at(it.first.first, it.first.second) = it.second;
    }

private:
    std::pair<int, int> mStart;
    std::map<std::pair<int, int>, char> mOldValue;
    char mNewValue;
};

class GfxEditorWidget::ColorizeOperation : public Operation
{
public:
    ColorizeOperation(Zone zone, int color, bool ink)
        : mZone(zone)
        , mColor(color)
        , mInk(ink)
    {
    }

    static char calcNewAttrib(GfxData* data, int x, int y, int color, bool ink)
    {
        char attrib = data->attribAt(x, y, GfxColorMode::Multicolor) & 0x3F;
        if (ink)
            attrib = (attrib & ~7) | (color & 7);
        else
            attrib = (attrib & ~0x38) | ((color & 7) << 3);
        return attrib | ((color & 8) << 3) | ((color & 16) << 3);
    }

    void redo(GfxData* data) override
    {
        int x1 = mZone.x;
        int y1 = mZone.y;
        int x2 = x1 + 7;
        int y2 = y1 + mZone.h - 1;

        mOldValue = data->attrib(x1, y1, x2, y2);

        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++)
                data->attribAt(x, y, GfxColorMode::Multicolor) = calcNewAttrib(data, x, y, mColor, mInk);
        }
    }

    void undo(GfxData* data) override
    {
        data->setAttrib(mZone.x, mZone.y, 8, mZone.h, mOldValue);
    }

private:
    QByteArray mOldValue;
    Zone mZone;
    int mColor;
    bool mInk;
};

class GfxEditorWidget::ClearOperation : public Operation
{
public:
    explicit ClearOperation(const Rect& r)
        : mRect(r)
    {
    }

    void redo(GfxData* data) override
    {
        mOldValue = data->bytes(mRect.x1, mRect.y1, mRect.x2, mRect.y2);
        data->clear(mRect.x1, mRect.y1, mRect.x2, mRect.y2);
    }

    void undo(GfxData* data) override
    {
        data->setBytes(mRect.x1, mRect.y1, mRect.width(), mRect.height(), mOldValue);
    }

private:
    Rect mRect;
    QByteArray mOldValue;
};

class GfxEditorWidget::PasteOperation : public Operation
{
public:
    PasteOperation(const Rect& r, const QByteArray& data)
        : mRect(r)
        , mNewValue(data)
    {
    }

    void redo(GfxData* data) override
    {
        mOldValue = data->bytes(mRect.x1, mRect.y1, mRect.x2, mRect.y2);
        data->setBytes(mRect.x1, mRect.y1, mRect.width(), mRect.height(), mNewValue);
    }

    void undo(GfxData* data) override
    {
        data->setBytes(mRect.x1, mRect.y1, mRect.width(), mRect.height(), mOldValue);
    }

private:
    Rect mRect;
    QByteArray mOldValue;
    QByteArray mNewValue;
};

class GfxEditorWidget::ResizeOperation : public Operation
{
public:
    ResizeOperation(int newWidth, int newHeight)
        : mNewWidth(newWidth)
        , mNewHeight(newHeight)
    {
    }

    void redo(GfxData* data) override
    {
        mOldWidth = data->width();
        mOldHeight = data->height();
        mOldBytes = data->bytes();
        data->resize(mNewWidth, mNewHeight);
    }

    void undo(GfxData* data) override
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

class GfxEditorWidget::Tool
{
public:
    virtual ~Tool() = default;
    virtual GfxEditorTool id() const = 0;
    virtual QCursor cursorAt(int x, int y) const { return Qt::ArrowCursor; }
    virtual void drawOverlay(GfxEditorWidget* widget, QPainter& painter, int x, int y) const {}
    virtual void beginDrag(GfxEditorWidget* widget, int x, int y, char value) {}
    virtual void continueDrag(GfxEditorWidget* widget, int x, int y) {}
    virtual void endDrag(GfxEditorWidget* widget, bool cancel) {}
};

class GfxEditorWidget::DrawTool : public Tool
{
public:
    DrawTool()
        : mValue(0)
        , mDragging(false)
    {
    }

    GfxEditorTool id() const override
    {
        return GfxEditorTool::Draw;
    }

    static void drawOverlayGfx(GfxEditorWidget* widget, QPainter& painter, int x, int y, char value)
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

    void drawOverlay(GfxEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        drawOverlayGfx(widget, painter, x, y, (mDragging ? mValue : 1));
    }

    void beginDrag(GfxEditorWidget* widget, int x, int y, char value) override
    {
        mDragging = true;
        mValue = value;
        emitPixel(widget, x, y, value);
    }

    void continueDrag(GfxEditorWidget* widget, int x, int y) override
    {
        emitPixel(widget, x, y, mValue);
    }

    void endDrag(GfxEditorWidget* widget, bool cancel) override
    {
        mDragging = false;
    }

private:
    char mValue;
    bool mDragging;

    void emitPixel(GfxEditorWidget* widget, int x, int y, char value)
    {
        if (!widget->mGfxData->isValidCoord(x, y))
            return;
        if (widget->mGfxData->at(x, y) == value)
            return;
        widget->pushOperation(new DrawOperation(x, y, value));
    }

    Q_DISABLE_COPY(DrawTool)
};

class GfxEditorWidget::DrawRectTool : public Tool
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

    GfxEditorTool id() const override
    {
        return GfxEditorTool::DrawRect;
    }

    static Rect makeRect(GfxData* data, int startX, int startY, int endX, int endY)
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

    void drawOverlay(GfxEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        if (!mDragging) {
            DrawTool::drawOverlayGfx(widget, painter, x, y, 1);
            return;
        }

        Rect r = makeGfxRect(widget->mGfxData);
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

    void beginDrag(GfxEditorWidget* widget, int x, int y, char value) override
    {
        mStartX = x;
        mStartY = y;
        mEndX = x;
        mEndY = y;
        mValue = value;
        mDragging = true;
    }

    void continueDrag(GfxEditorWidget* widget, int x, int y) override
    {
        mEndX = x;
        mEndY = y;
    }

    void endDrag(GfxEditorWidget* widget, bool cancel) override
    {
        if (!cancel) {
            Rect r = makeGfxRect(widget->mGfxData);
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

    Rect makeGfxRect(GfxData* data) const { return makeRect(data, mStartX, mStartY, mEndX, mEndY); }

    Q_DISABLE_COPY(DrawRectTool)
};

class GfxEditorWidget::FillTool : public Tool
{
public:
    FillTool()
        : mValue(0)
        , mDragging(false)
    {
    }

    GfxEditorTool id() const override
    {
        return GfxEditorTool::Fill;
    }

    void drawOverlay(GfxEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        DrawTool::drawOverlayGfx(widget, painter, x, y, (mDragging ? mValue : 1));
    }

    void beginDrag(GfxEditorWidget* widget, int x, int y, char value) override
    {
        mX = x;
        mY = y;
        mDragging = true;
        mValue = value;
    }

    void continueDrag(GfxEditorWidget* widget, int x, int y) override
    {
        mX = x;
        mY = y;
    }

    void endDrag(GfxEditorWidget* widget, bool cancel) override
    {
        mDragging = false;
        if (cancel)
            return;
        if (!widget->mGfxData->isValidCoord(mX, mY))
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

class GfxEditorWidget::ColorizeTool : public Tool
{
public:
    ColorizeTool()
        : mX(0)
        , mY(0)
        , mValue(0)
    {
    }

    GfxEditorTool id() const override
    {
        return GfxEditorTool::Colorize;
    }

    void drawOverlay(GfxEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        auto z = getZone(widget, x, y);
        painter.setPen(QColor(128, 128, 128));
        painter.setBrush(QColor(128, 128, 128, 128));
        painter.drawRect(z.x * PixelWidth, z.y * PixelHeight, 8 * PixelWidth, z.h * PixelHeight);
    }

    void beginDrag(GfxEditorWidget* widget, int x, int y, char value) override
    {
        mX = x;
        mY = y;
        mValue = value;
        colorize(widget, mX, mY, widget->mSelectedColor, mValue != 0);
    }

    void continueDrag(GfxEditorWidget* widget, int x, int y) override
    {
        mX = x;
        mY = y;
        colorize(widget, mX, mY, widget->mSelectedColor, mValue != 0);
    }

    void endDrag(GfxEditorWidget* widget, bool cancel) override
    {
    }

private:
    int mX;
    int mY;
    char mValue;

    void colorize(GfxEditorWidget* widget, int x, int y, int color, bool ink)
    {
        if (!widget->mGfxData->isValidCoord(x, y))
            return;

        auto z = getZone(widget, x, y);

        bool equal = true;
        for (int yy = 0; yy < z.h; yy++) {
            int a = ColorizeOperation::calcNewAttrib(widget->mGfxData, x, z.y + yy, color, ink);
            if (widget->mGfxData->attribAt(x, y, widget->mColorMode) != a) {
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

class GfxEditorWidget::SelectTool : public Tool
{
public:
    SelectTool()
    {
    }

    GfxEditorTool id() const override
    {
        return GfxEditorTool::Select;
    }

    void drawOverlay(GfxEditorWidget* widget, QPainter& painter, int x, int y) const override
    {
        painter.setPen(QColor(128, 128, 128));
        painter.setBrush(Qt::transparent);
        painter.drawRect(x * PixelWidth, y * PixelHeight, PixelWidth, PixelHeight);
    }

    void beginDrag(GfxEditorWidget* widget, int x, int y, char value) override
    {
        mStartX = x;
        mStartY = y;
        mEndX = x;
        mEndY = y;
        updateSelection(widget);
    }

    void continueDrag(GfxEditorWidget* widget, int x, int y) override
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

    void updateSelection(GfxEditorWidget* widget)
    {
        widget->mSelection = DrawRectTool::makeRect(widget->mGfxData, mStartX, mStartY, mEndX, mEndY);
        widget->update();
        emit widget->updateUi();
    }

    Q_DISABLE_COPY(SelectTool)
};


///////////////////////////////////////////////////////////////////////////////

bool GfxEditorWidget::mGridVisible = true;

GfxEditorWidget::GfxEditorWidget(QWidget* parent)
    : QWidget(parent)
    , mPreview(nullptr)
    , mCurrentTool(new DrawTool())
    , mUndoStackIndex(0)
    , mSavedIndex(0)
    , mSelection(Rect::empty())
    , mMousePosition(-1, -1)
    , mColorMode(GfxColorMode::Standard)
    , mMousePressed(Qt::NoButton)
    , mSelectedColor(0)
    , mFlash(false)
{
    mGfxData = new GfxData(8, 8, this);
    setMouseTracking(true);

    mTimer = new QTimer(this);
    mTimer->start(1000 * 16 / 50);
    connect(mTimer, &QTimer::timeout, this, [this]{ mFlash = !mFlash; repaint(); });

    auto onSizeChanged = [this] {
            setFixedSize(mGfxData->width() * PixelWidth, mGfxData->height() * PixelHeight);
            if (mPreview)
                mPreview->setFixedSize(mGfxData->width() * 2, mGfxData->height() * 2);
            emit sizeChanged();
        };

    connect(mGfxData, &GfxData::sizeChanged, this, onSizeChanged);
    onSizeChanged();
}

GfxEditorWidget::~GfxEditorWidget()
{
}

int GfxEditorWidget::width() const
{
    return mGfxData->width();
}

int GfxEditorWidget::height() const
{
    return mGfxData->height();
}

bool GfxEditorWidget::isModified() const
{
    return mUndoStackIndex != mSavedIndex;
}

void GfxEditorWidget::reset()
{
    cancelInput();
    mGfxData->clear();
    mUndoStack.clear();
    mUndoStackIndex = 0;
    mSelection = Rect::empty();
    mSavedIndex = 0;
    update();
    emit updateUi();
}

void GfxEditorWidget::setSize(int w, int h)
{
    if (w != mGfxData->width() || h != mGfxData->height())
        pushOperation(new ResizeOperation(w, h));
}

void GfxEditorWidget::setPreviewWidget(QLabel* preview)
{
    mPreview = preview;
    if (preview) {
        preview->setFixedSize(mGfxData->width() * 2, mGfxData->height() * 2);
        update();
    }
}

void GfxEditorWidget::setColorMode(GfxColorMode mode)
{
    if (mColorMode != mode) {
        mColorMode = mode;
        update();
        emit updateUi();
    }
}

void GfxEditorWidget::setColor(int color)
{
    if (mSelectedColor != color) {
        mSelectedColor = color;
        update();
        emit updateUi();
    }
}

void GfxEditorWidget::setGridVisible(bool visible)
{
    if (mGridVisible != visible) {
        mGridVisible = visible;
        update();
        emit updateUi();
    }
    repaint();
}

void GfxEditorWidget::serialize(GfxFile& file)
{
    file.serializeToJson(mGfxData);
}

bool GfxEditorWidget::deserialize(GfxFile& file)
{
    if (!file.deserializeFromJson(mGfxData)) {
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

void GfxEditorWidget::setSaved()
{
    mSavedIndex = mUndoStackIndex;
    update();
    emit updateUi();
}

bool GfxEditorWidget::canUndo() const
{
    return mUndoStackIndex > 0;
}

bool GfxEditorWidget::canRedo() const
{
    return mUndoStackIndex < mUndoStack.size();
}

void GfxEditorWidget::undo()
{
    if (mUndoStackIndex > 0) {
        cancelInput();

        auto& op = mUndoStack[--mUndoStackIndex];
        op->undo(mGfxData);
        mSelection = op->selectionRect;

        update();
        emit updateUi();
    }
}

void GfxEditorWidget::redo()
{
    if (mUndoStackIndex < mUndoStack.size()) {
        cancelInput();

        mUndoStack[mUndoStackIndex++]->redo(mGfxData);
        if (mUndoStackIndex < mUndoStack.size())
            mSelection = mUndoStack[mUndoStackIndex]->selectionRect;

        update();
        emit updateUi();
    }
}

bool GfxEditorWidget::canCut() const
{
    return hasSelection();
}

bool GfxEditorWidget::canCopy() const
{
    return hasSelection();
}

bool GfxEditorWidget::canClearArea() const
{
    return hasSelection();
}

void GfxEditorWidget::cut()
{
    if (!hasSelection())
        return;

    cancelInput();

    copy();

    pushOperation(new ClearOperation(mSelection));
    clearSelection();
}

void GfxEditorWidget::copy()
{
    if (!hasSelection())
        return;

    cancelInput();

    QByteArray pixels = mGfxData->bytes(mSelection.x1, mSelection.y1, mSelection.x2, mSelection.y2);

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

void GfxEditorWidget::paste()
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

void GfxEditorWidget::clearArea()
{
    if (!hasSelection())
        return;

    cancelInput();

    pushOperation(new ClearOperation(mSelection));
    clearSelection();
}

void GfxEditorWidget::selectAll()
{
    if (mSelection.x1 != 0 || mSelection.y1 != 0
            || mSelection.width() != mGfxData->width() || mSelection.height() != mGfxData->height()) {
        cancelInput();
        mSelection.x1 = 0;
        mSelection.y1 = 0;
        mSelection.x2 = mGfxData->width() - 1;
        mSelection.y2 = mGfxData->height() - 1;
        update();
        emit updateUi();
    }
}

void GfxEditorWidget::clearSelection()
{
    if (!mSelection.isEmpty()) {
        cancelInput();
        mSelection = Rect::empty();
        update();
        emit updateUi();
    }
}

char GfxEditorWidget::at(int x, int y) const
{
    return mGfxData->at(x, y);
}

char GfxEditorWidget::at(const QPoint& p) const
{
    return mGfxData->at(p);
}

GfxEditorTool GfxEditorWidget::currentTool() const
{
    return (mCurrentTool ? mCurrentTool->id() : GfxEditorTool::None);
}

void GfxEditorWidget::setTool(GfxEditorTool tool)
{
    if (currentTool() != tool) {
        cancelInput();
        switch (tool) {
            case GfxEditorTool::None: mCurrentTool.reset(); break;
            case GfxEditorTool::Draw: mCurrentTool.reset(new DrawTool()); break;
            case GfxEditorTool::DrawRect: mCurrentTool.reset(new DrawRectTool()); break;
            case GfxEditorTool::Fill: mCurrentTool.reset(new FillTool()); break;
            case GfxEditorTool::Colorize: mCurrentTool.reset(new ColorizeTool()); break;
            case GfxEditorTool::Select: mCurrentTool.reset(new SelectTool()); break;
        }
        update();
    }
    emit updateUi();
}

void GfxEditorWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QImage image(mGfxData->width() * 2, mGfxData->height() * 2, QImage::Format_ARGB32);

    for (int gfxY = 0; gfxY < mGfxData->height(); gfxY++) {
        for (int gfxX = 0; gfxX < mGfxData->width(); gfxX++) {
            int x = gfxX * PixelWidth;
            int y = gfxY * PixelHeight;

            char value = mGfxData->at(gfxX, gfxY);
            char attrib = mGfxData->attribAt(gfxX, gfxY, mColorMode);

            if ((attrib & 0x80) != 0 && mFlash)
                value = !value;

            int color = (value ? attrib & 7 : (attrib & 0x38) >> 3);
            if (attrib & 0x40)
                color += 8;

            const QColor& colorRef = GfxFilePalette[color];
            uint rgb = colorRef.rgb();

            for (int yy = 0; yy < 2; yy++) {
                for (int xx = 0; xx < 2; xx++)
                    image.setPixel(gfxX * 2 + xx, gfxY * 2 + yy, rgb);
            }

            painter.fillRect(x, y, PixelWidth, PixelHeight, colorRef);
        }
    }

    if (mPreview)
        mPreview->setPixmap(QPixmap::fromImage(image));

    if (mGridVisible) {
        painter.setCompositionMode(QPainter::RasterOp_SourceXorDestination);
        painter.setBrush(Qt::transparent);
        for (int gridY = 1; gridY < mGfxData->height(); gridY++) {
            float w = ((gridY & 7) == 0 ? 1.5f : 1.0f);
            int c = ((gridY & 7) == 0 ? 255 : 128);
            int y = gridY * PixelHeight;
            painter.setPen(QPen(QColor(c, c, c, 128), w));
            painter.drawLine(0, y, QWidget::width(), y);
        }
        for (int gridX = 1; gridX < mGfxData->width(); gridX++) {
            float w = ((gridX & 7) == 0 ? 1.5f : 1.0f);
            int c = ((gridX & 7) == 0 ? 255 : 128);
            int x = gridX * PixelWidth;
            painter.setPen(QPen(QColor(c, c, c, 128), w));
            painter.drawLine(x, 0, x, QWidget::height());
        }
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
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
    if (mCurrentTool && mGfxData->isValidCoord(mMousePosition)) {
        cursor = mCurrentTool->cursorAt(mMousePosition.x(), mMousePosition.y());
        mCurrentTool->drawOverlay(this, painter, mMousePosition.x(), mMousePosition.y());
    }

    setCursor(cursor);
}

void GfxEditorWidget::mousePressEvent(QMouseEvent* event)
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

void GfxEditorWidget::mouseReleaseEvent(QMouseEvent* event)
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

void GfxEditorWidget::mouseMoveEvent(QMouseEvent* event)
{
    updateMousePosition(event);
    if (mMousePressed != Qt::NoButton) {
        if (mCurrentTool)
            mCurrentTool->continueDrag(this, mMousePosition.x(), mMousePosition.y());
        update();
        emit updateUi();
    }
}

void GfxEditorWidget::leaveEvent(QEvent* event)
{
    if (mMousePosition.x() != -1 || mMousePosition.y() != -1) {
        mMousePosition = QPoint(-1, -1);
        if (mMousePressed != Qt::NoButton && mCurrentTool)
            mCurrentTool->continueDrag(this, mMousePosition.x(), mMousePosition.y());
        update();
        emit updateUi();
    }
}

void GfxEditorWidget::cancelInput()
{
    if (mMousePressed != Qt::NoButton) {
        mMousePressed = Qt::NoButton;
        if (mCurrentTool)
            mCurrentTool->endDrag(this, true);
        update();
        emit updateUi();
    }
}

void GfxEditorWidget::updateMousePosition(QMouseEvent* event)
{
    QPoint pos = event->pos();
    int x = pos.x() / PixelWidth;
    int y = pos.y() / PixelHeight;
    if (x != mMousePosition.x() || y != mMousePosition.y()) {
        mMousePosition = QPoint(x, y);
        update();
    }
}

void GfxEditorWidget::pushOperation(Operation* op)
{
    pushOperation(std::unique_ptr<Operation>(op));
}

void GfxEditorWidget::pushOperation(std::unique_ptr<Operation>&& op)
{
    if (mUndoStackIndex < mUndoStack.size()) {
        if (mSavedIndex > mUndoStackIndex)
            mSavedIndex = size_t(-1);
        mUndoStack.resize(mUndoStackIndex);
    }

    op->selectionRect = mSelection;

    mUndoStack.emplace_back(std::move(op));
    mUndoStack.back()->redo(mGfxData);
    ++mUndoStackIndex;

    update();
    emit updateUi();
}
