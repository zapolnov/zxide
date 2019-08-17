#include "ScrollBar.h"

ScrollBar::ScrollBar(QWidget* parent)
    : QScrollBar(parent)
{
}

ScrollBar::~ScrollBar()
{
}

void ScrollBar::keyPressEvent(QKeyEvent* event)
{
    QScrollBar::keyPressEvent(event);
}

void ScrollBar::keyReleaseEvent(QKeyEvent* event)
{
    QScrollBar::keyReleaseEvent(event);
}

void ScrollBar::wheelEvent(QWheelEvent* event)
{
    QScrollBar::wheelEvent(event);
}
