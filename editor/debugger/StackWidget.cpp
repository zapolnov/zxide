#include "StackWidget.h"
#include "debugger/EmulatorCore.h"
#include <QPainter>

StackWidget::StackWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
    connect(EmulatorCore::instance(), &EmulatorCore::stackChanged, this, QOverload<>::of(&StackWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::memoryChanged, this, QOverload<>::of(&StackWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::started, this, QOverload<>::of(&StackWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::stopped, this, QOverload<>::of(&StackWidget::update));

    setMinimumWidth(14 * CharWidth);
    setMinimumHeight(CharHeight);
}

StackWidget::~StackWidget()
{
}

QSize StackWidget::sizeHint() const
{
    return QSize(10 * CharWidth, 5 * CharHeight);
}

void StackWidget::paintGL()
{
    QPainter painter(this);

    painter.fillRect(0, 0, width(), height(), Qt::white);
    if (!EmulatorCore::instance()->isRunning())
        return;

    int pixW = width();
    int pixH = height();

    int w = qMax(14, (pixW + CharWidth  - 1) / CharWidth);
    int h = qMax( 1, (pixH + CharHeight - 1) / CharHeight);

    size_t lineBufferSize = w + 1;
    if (lineBufferSize != mLineBuffer.size())
        mLineBuffer.resize(lineBufferSize);

    size_t dataBufferSize = h * 2;
    if (dataBufferSize != mDataBuffer.size())
        mDataBuffer.resize(dataBufferSize);

    unsigned firstAddr = (EmulatorCore::instance()->stackPointer()) & 0xffff;
    unsigned lastAddr = (firstAddr + dataBufferSize) & 0xffff;
    unsigned addr = firstAddr;
    EmulatorCore::instance()->getMemory(firstAddr, mDataBuffer.data(), dataBufferSize);

    for (int i = 0; i < h; i++) {
        quint16 b1 = quint8(mDataBuffer[(addr + 0) - firstAddr]);
        quint16 b2 = quint8(mDataBuffer[(addr + 1) - firstAddr]);
        quint16 value = b1 | (b2 << 8);

        char current[2];
        if (i == 0) {
            current[0] = '\xFD';
            current[1] = '\xFE';
        } else {
            current[0] = ' ';
            current[1] = ' ';
        }

        int color = (i == 0 ? BLACK : GRAY);
        sprintf(mLineBuffer.data(), " %c%c %04X  %04X", current[0], current[1], addr, unsigned(value));

        size_t len = 14;
        if (w > 16) {
            QString name = EmulatorCore::instance()->nameForAddress(unsigned(value));
            if (!name.isEmpty()) {
                mLineBuffer[len++] = ' ';
                mLineBuffer[len++] = ' ';
                for (int j = 0; j < w - 16 && j < name.length(); j++)
                    mLineBuffer[len++] = name[j].toLatin1();
            }
        }

        drawText(&painter, 0, i * CharHeight, mLineBuffer.data(), len, color);
        addr = (addr + 2) & 0xffff;
    }
}
