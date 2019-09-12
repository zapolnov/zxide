#ifndef UTIL_CLICKABLELABEL_H
#define UTIL_CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = nullptr);
    ~ClickableLabel();

signals:
    void doubleClicked();

protected:
    void mouseDoubleClickEvent(QMouseEvent* event) override;

    Q_DISABLE_COPY(ClickableLabel)
};

#endif
