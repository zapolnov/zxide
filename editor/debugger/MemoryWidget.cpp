#include "MemoryWidget.h"
#include "util/ScrollBar.h"
#include "ui_EditRegisterDialog.h"
#include <QTimer>
#include <QPainter>
#include <QContextMenuEvent>
#include <QMenu>
#include <QDialog>

static constexpr int AddressWidth = 4;
static constexpr int Spacing = 2;
static constexpr int HexWidth = 3;
static constexpr int SymWidth = 1;

MemoryWidget::MemoryWidget(QWidget* parent)
    : QOpenGLWidget(parent)
    , mScrollBar(nullptr)
{
    connect(EmulatorCore::instance(), &EmulatorCore::memoryChanged, this, QOverload<>::of(&MemoryWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::started, this, QOverload<>::of(&MemoryWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::stopped, this, QOverload<>::of(&MemoryWidget::update));

    setMinimumWidth((AddressWidth + Spacing + HexWidth - 1 + Spacing + SymWidth) * CharWidth);
    setMinimumHeight(CharHeight);
}

MemoryWidget::~MemoryWidget()
{
}

QSize MemoryWidget::sizeHint() const
{
    const int hintWidth = 62;
    const int hintHeight = 7;
    int x = (AddressWidth + Spacing + hintWidth * HexWidth - 1 + Spacing + SymWidth * hintWidth) * CharWidth;
    int y = hintHeight * CharHeight;
    return QSize(x, y);
}

void MemoryWidget::setScrollBar(ScrollBar* scrollBar)
{
    mScrollBar = scrollBar;
    mScrollBar->setSingleStep(CharHeight);
    mScrollBar->setPageStep(CharHeight);
    connect(mScrollBar, &ScrollBar::valueChanged, this, QOverload<>::of(&MemoryWidget::update));
    update();
}

void MemoryWidget::paintGL()
{
    QPainter painter(this);

    painter.fillRect(0, 0, width(), height(), Qt::white);
    if (!EmulatorCore::instance()->isRunning())
        return;

    int pixW = width() - (AddressWidth + Spacing * 2) * CharWidth;
    int pixH = height();

    int w = pixW / ((HexWidth + SymWidth) * CharWidth);
    int h = 1 + (pixH + CharHeight - 1) / CharHeight;

    int totalLines = (0x10000 + w - 1) / w;
    mScrollBar->setRange(0, qMax(totalLines * CharHeight - pixH, 0));
    mScrollBar->setPageStep(qMax(pixH / CharHeight, 1) * CharHeight);

    int offset = mScrollBar->value();
    int address = offset / CharHeight * w;

    size_t lineBufferSize = AddressWidth + Spacing + w * HexWidth - 1 + Spacing + w * SymWidth;
    if (lineBufferSize != mLineBuffer.size())
        mLineBuffer.resize(lineBufferSize);

    int x = (width() - (int(lineBufferSize) * CharWidth)) / 2;
    int y = -(offset % CharHeight);

    int firstAddr = address;
    int lastAddr = qMin(address + h * w, 0xffff);
    size_t dataBufferSize = lastAddr - firstAddr + 1;
    if (dataBufferSize != mDataBuffer.size())
        mDataBuffer.resize(dataBufferSize);

    int dataOffset = 0;
    EmulatorCore::instance()->getMemory(firstAddr, mDataBuffer.data(), dataBufferSize);

    for (int n = 0; n < h; n++) {
        int mid = AddressWidth + Spacing + w * HexWidth - 1 + Spacing;
        int i = 0, j = mid;

        char buf[16];
        sprintf(buf, "%04X", (quint16)address);
        mLineBuffer[i++] = buf[0];
        mLineBuffer[i++] = buf[1];
        mLineBuffer[i++] = buf[2];
        mLineBuffer[i++] = buf[3];
        mLineBuffer[i++] = ' ';
        mLineBuffer[i++] = ' ';

        for (int xx = 0; xx < w && address <= 0xffff; xx++) {
            char byte = mDataBuffer[dataOffset++];

            sprintf(buf, "%02X", (unsigned char)byte);
            mLineBuffer[i++] = buf[0];
            mLineBuffer[i++] = buf[1];
            mLineBuffer[i++] = ' ';

            if (byte == (char)(unsigned char)0xFF) // hide the editor's "subscript 16" character
                byte = 0;
            mLineBuffer[j++] = byte;

            ++address;
        }

        while (i < mid)
            mLineBuffer[i++] = ' ';

        drawText(&painter, x, y, mLineBuffer.data(), j, BLACK);
        y += CharHeight;
    }

    int startX1 = x + AddressWidth * CharWidth;
    int lineX1 = startX1 + (Spacing * CharWidth - 1) / 2;
    painter.setPen(Qt::gray);
    painter.drawLine(lineX1, 0, lineX1, pixH);

    int startX2 = x + (AddressWidth + Spacing + w * HexWidth - 1) * CharWidth;
    int lineX2 = startX2 + (Spacing * CharWidth - 1) / 2;
    painter.setPen(Qt::gray);
    painter.drawLine(lineX2, 0, lineX2, pixH);
}

void MemoryWidget::wheelEvent(QWheelEvent* event)
{
    mScrollBar->wheelEvent(event);
}

void MemoryWidget::contextMenuEvent(QContextMenuEvent* event)
{
    constexpr int charW = SimpleTextPainter::CharWidth;
    constexpr int charH = SimpleTextPainter::CharHeight;

    QPoint pos = event->pos();
    int x = pos.x();
    int y = pos.y();

    // FIXME
}
