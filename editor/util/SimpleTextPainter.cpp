#include "SimpleTextPainter.h"
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

SimpleTextPainter::SimpleTextPainter()
    : mFont(QStringLiteral(":/fonts/font.png"))
{
}

SimpleTextPainter::~SimpleTextPainter()
{
}

void SimpleTextPainter::drawText(QPainter* painter, int x, int y, const char* text, int color) const
{
    drawText(painter, x, y, text, strlen(text), color);
}

void SimpleTextPainter::drawText(QPainter* painter, int x, int y, const char* text, size_t len, int color) const
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
            f.x = xx + CharWidth / 2;
            f.y = y + CharHeight / 2;
            f.width = CharWidth;
            f.height = CharHeight;
            f.sourceLeft = (ch & 15) * CharWidth;
            f.sourceTop = (ch >> 4) * CharHeight;
            f.rotation = 0.0f;
            f.scaleX = 1.0f;
            f.scaleY = 1.0f;
            f.opacity = 1.0f;
            xx += CharWidth;
        } while (--len > 0 && count < MaxFragments);

        painter->drawPixmapFragments(fragments, count, mFont);
    }
}

void SimpleTextPainter::drawText(QPainter* painter, int x, int y, const std::string& text, int color) const
{
    drawText(painter, x, y, text.c_str(), text.length(), color);
}

void SimpleTextPainter::drawTextAt(QPainter* painter, int x, int y, const char* text, int color) const
{
    drawText(painter, x * CharWidth, y * CharHeight, text, strlen(text), color);
}

void SimpleTextPainter::drawTextAt(QPainter* painter, int x, int y, const char* text, size_t len, int color) const
{
    drawText(painter, x * CharWidth, y * CharHeight, text, len, color);
}

void SimpleTextPainter::drawTextAt(QPainter* painter, int x, int y, const std::string& text, int color) const
{
    drawText(painter, x * CharWidth, y * CharHeight, text.c_str(), text.length(), color);
}
