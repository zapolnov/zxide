#include "DisassemblyWidget.h"
#include "debugger/EmulatorCore.h"
#include <QPainter>

DisassemblyWidget::DisassemblyWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
    connect(EmulatorCore::instance(), &EmulatorCore::memoryChanged, this, QOverload<>::of(&DisassemblyWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::instructionPointerChanged, this, QOverload<>::of(&DisassemblyWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::started, this, QOverload<>::of(&DisassemblyWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::stopped, this, QOverload<>::of(&DisassemblyWidget::update));

    setMinimumWidth(14 * CharWidth);
    setMinimumHeight(CharHeight);
}

DisassemblyWidget::~DisassemblyWidget()
{
}

QSize DisassemblyWidget::sizeHint() const
{
    return QSize(10 * CharWidth, 5 * CharHeight);
}

void DisassemblyWidget::paintGL()
{
    QPainter painter(this);

    painter.fillRect(0, 0, width(), height(), Qt::white);
    if (!EmulatorCore::instance()->isRunning())
        return;

    //int pixW = width();
    int pixH = height();

    //int w = qMax(14, (pixW + CharWidth  - 1) / CharWidth);
    int h = qMax( 1, (pixH + CharHeight - 1) / CharHeight);

    unsigned addr = (EmulatorCore::instance()->instructionPointer()) & 0xffff;
    std::vector<std::string> lines = EmulatorCore::instance()->disassemble(addr, h);

    for (int i = 0; i < h; i++) {
        int color = GRAY;

        if (i == 0) {
            color = BLACK;
            drawText(&painter, 1 * CharWidth, i * CharHeight, "\xFD\xFE", 2, color);
        }

        drawText(&painter, 4 * CharWidth, i * CharHeight, lines[i].data(), color);
    }
}
