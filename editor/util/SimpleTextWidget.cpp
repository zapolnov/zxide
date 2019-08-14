#include "SimpleTextWidget.h"
#include <cstring>
#include <QPainter>

static QColor foreColors[16] = {
        QColor(0x00, 0x00, 0x00),
        QColor(0x00, 0x00, 0x80),
        QColor(0x00, 0x80, 0x00),
        QColor(0x00, 0x80, 0x80),
        QColor(0x80, 0x00, 0x00),
        QColor(0x80, 0x00, 0x80),
        QColor(0x80, 0x80, 0x00),
        QColor(0xC0, 0xC0, 0xC0),
        QColor(0x80, 0x80, 0x80),
        QColor(0x00, 0x00, 0xff),
        QColor(0x00, 0xff, 0x00),
        QColor(0x00, 0xff, 0xff),
        QColor(0xff, 0x00, 0x00),
        QColor(0xff, 0x00, 0xff),
        QColor(0xff, 0xff, 0x00),
        QColor(0xff, 0xff, 0xff),
    };

static QColor backColors[16] = {
        QColor(0x00, 0x00, 0x00, 0x00),
        QColor(0x00, 0x00, 0x80),
        QColor(0x00, 0x80, 0x00),
        QColor(0x00, 0x80, 0x80),
        QColor(0x80, 0x00, 0x00),
        QColor(0x80, 0x00, 0x80),
        QColor(0x80, 0x80, 0x00),
        QColor(0xC0, 0xC0, 0xC0),
        QColor(0x80, 0x80, 0x80),
        QColor(0x00, 0x00, 0xff),
        QColor(0x00, 0xff, 0x00),
        QColor(0x00, 0xff, 0xff),
        QColor(0xff, 0x00, 0x00),
        QColor(0xff, 0x00, 0xff),
        QColor(0xff, 0xff, 0x00),
        QColor(0xff, 0xff, 0xff),
    };

SimpleTextWidget::SimpleTextWidget(QWidget* parent)
    : QWidget(parent)
    , mFont(QStringLiteral(":/fonts/font.png"))
{
}

SimpleTextWidget::~SimpleTextWidget()
{
}

void SimpleTextWidget::drawText(QPainter* painter, int x, int y, const char* text, int color)
{
    drawText(painter, x, y, text, strlen(text), color);
}

void SimpleTextWidget::drawText(QPainter* painter, int x, int y, const char* text, size_t len, int color)
{
    painter->setPen(foreColors[color & 0xf]);
    painter->setBackgroundMode(Qt::OpaqueMode);
    painter->setBackground(backColors[(color >> 4) & 0xf]);

    int xx = x;

    while (len > 0) {
        constexpr size_t MaxFragments = 32;
        QPainter::PixmapFragment fragments[MaxFragments];

        int count = 0;
        do {
            int ch = static_cast<unsigned char>(*text++);
            auto& f = fragments[count++];
            f.x = xx;
            f.y = y;
            f.width = 8;
            f.height = 16;
            f.sourceLeft = (ch & 15) * 8;
            f.sourceTop = (ch >> 4) * 16;
            f.rotation = 0.0f;
            f.scaleX = 1.0f;
            f.scaleY = 1.0f;
            f.opacity = 1.0f;
            xx += 8;
        } while (--len > 0 && count < MaxFragments);

        painter->drawPixmapFragments(fragments, count, mFont);
    }
}

void SimpleTextWidget::drawTextAt(QPainter* painter, int x, int y, const char* text, int color)
{
    drawText(painter, x * 8, y * 16, text, strlen(text), color);
}

void SimpleTextWidget::drawTextAt(QPainter* painter, int x, int y, const char* text, size_t len, int color)
{
    drawText(painter, x * 8, y * 16, text, len, color);
}
