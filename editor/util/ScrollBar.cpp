#include "ScrollBar.h"

ScrollBar::ScrollBar(QWidget* parent)
    : QScrollBar(parent)
{
}

ScrollBar::~ScrollBar()
{
}

void ScrollBar::wheelEvent(QWheelEvent* event)
{
    QScrollBar::wheelEvent(event);
}
