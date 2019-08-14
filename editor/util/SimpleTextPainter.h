#ifndef UTIL_SIMPLETEXTPAINTER_H
#define UTIL_SIMPLETEXTPAINTER_H

#include <QBitmap>
#include <string>

class SimpleTextPainter
{
public:
    enum {
        CharWidth = 8,
        CharHeight = 16,
    };

    SimpleTextPainter();
    ~SimpleTextPainter();

protected:
    enum {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        YELLOW = 6,
        GRAY = 7,
        INTENSITY = 8,
    };

    static inline int COLOR(int fg, int bg) { return fg | (bg << 4); }

    void drawText(QPainter* painter, int x, int y, const char* text, int color) const;
    void drawText(QPainter* painter, int x, int y, const char* text, size_t len, int color) const;
    void drawText(QPainter* painter, int x, int y, const std::string& text, int color) const;
    void drawTextAt(QPainter* painter, int x, int y, const char* text, int color) const;
    void drawTextAt(QPainter* painter, int x, int y, const char* text, size_t len, int color) const;
    void drawTextAt(QPainter* painter, int x, int y, const std::string& text, int color) const;

private:
    QBitmap mFont;

    Q_DISABLE_COPY(SimpleTextPainter)
};

#endif
