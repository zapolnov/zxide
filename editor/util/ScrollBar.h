#ifndef UTIL_SCROLLBAR_H
#define UTIL_SCROLLBAR_H

#include <QScrollBar>

class ScrollBar : public QScrollBar
{
    Q_OBJECT

public:
    explicit ScrollBar(QWidget* parent = nullptr);
    ~ScrollBar();

    void wheelEvent(QWheelEvent* event) override;

    Q_DISABLE_COPY(ScrollBar)
};

#endif
