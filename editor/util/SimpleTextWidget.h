#ifndef SIMPLETEXTWIDGET_H
#define SIMPLETEXTWIDGET_H

#include <QWidget>
#include <QBitmap>

class SimpleTextWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleTextWidget(QWidget* parent = nullptr);
    ~SimpleTextWidget() override;

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

    void drawText(QPainter* painter, int x, int y, const char* text, int color);
    void drawText(QPainter* painter, int x, int y, const char* text, size_t len, int color);
    void drawTextAt(QPainter* painter, int x, int y, const char* text, int color);
    void drawTextAt(QPainter* painter, int x, int y, const char* text, size_t len, int color);

private:
    QBitmap mFont;

    Q_DISABLE_COPY(SimpleTextWidget)
};

#endif
