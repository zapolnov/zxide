#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(QWidget* parent)
    : QLabel(parent)
{
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mouseDoubleClickEvent(QMouseEvent*)
{
    emit doubleClicked();
}
