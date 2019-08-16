#include "DisplayWidget.h"
#include "debugger/EmulatorCore.h"
#include <QPainter>
#include <QKeyEvent>

typedef struct { quint8 r, g, b; } Color;

static Color Palette[] = {
    { 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0xc0 },
    { 0xc0, 0x00, 0x00 },
    { 0xc0, 0x00, 0xc0 },
    { 0x00, 0xc0, 0x00 },
    { 0x00, 0xc0, 0xc0 },
    { 0xc0, 0xc0, 0x00 },
    { 0xc0, 0xc0, 0xc0 },
    { 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0xff },
    { 0xff, 0x00, 0x00 },
    { 0xff, 0x00, 0xff },
    { 0x00, 0xff, 0x00 },
    { 0x00, 0xff, 0xff },
    { 0xff, 0xff, 0x00 },
    { 0xff, 0xff, 0xff },
};

DisplayWidget::DisplayWidget(QWidget* parent)
    : QOpenGLWidget(parent)
    , mImage(256, 192, QImage::Format_ARGB32)
{
    connect(EmulatorCore::instance(), &EmulatorCore::memoryChanged, this, QOverload<>::of(&DisplayWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::started, this, QOverload<>::of(&DisplayWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::started, this, QOverload<>::of(&DisplayWidget::setFocus));
    connect(EmulatorCore::instance(), &EmulatorCore::stopped, this, QOverload<>::of(&DisplayWidget::update));
}

DisplayWidget::~DisplayWidget()
{
}

QSize DisplayWidget::sizeHint() const
{
    return QSize(256, 192);
}

void DisplayWidget::paintGL()
{
    QPainter painter(this);

    if (!EmulatorCore::instance()->isRunning()) {
        painter.fillRect(0, 0, width(), height(), Qt::black);
        return;
    }

    bool reversed = EmulatorCore::instance()->displayFlashReversed();
    EmulatorCore::instance()->getMemory(0x4000, mScreenBuffer, sizeof(mScreenBuffer));

    for (unsigned y = 0; y < 192; y++) {
        unsigned offset = ((y & 7) << 8) | ((y << 2) & 0xe0) | ((y << 5) & 0x1800);
        unsigned attribOffset = 6144 + (y / 8) * (256 / 8);
        uchar* dst = mImage.scanLine(y);
        for (int x = 0; x < 256 / 8; x++) {
            quint8 pixels = mScreenBuffer[offset];
            quint8 attrib = mScreenBuffer[attribOffset];

            int ink = attrib & 7;
            int paper = (attrib >> 3) & 7;
            if ((attrib & 0x80) && reversed)
                std::swap(ink, paper);
            if (attrib & 0x40) {
                ink += 8;
                paper += 8;
            }

            for (int i = 0; i < 8; i++) {
                const Color* color;
                if (pixels & (1 << (7 - i)))
                    color = &Palette[ink];
                else
                    color = &Palette[paper];

                *dst++ = color->b;
                *dst++ = color->g;
                *dst++ = color->r;
                *dst++ = 0xff;
            }

            ++offset;
            ++attribOffset;
        }
    }

    painter.drawImage(0, 0, mImage);
}

void DisplayWidget::keyPressEvent(QKeyEvent* event)
{
    EmulatorCore::instance()->pressKey(event->key());
}

void DisplayWidget::keyReleaseEvent(QKeyEvent* event)
{
    EmulatorCore::instance()->releaseKey(event->key());
}
