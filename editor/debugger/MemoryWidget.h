#ifndef DEBUGGER_MEMORYWIDGET_H
#define DEBUGGER_MEMORYWIDGET_H

#include <QOpenGLWidget>
#include "util/SimpleTextPainter.h"
#include <vector>

class ScrollBar;

class MemoryWidget : public QOpenGLWidget, public SimpleTextPainter
{
    Q_OBJECT

public:
    explicit MemoryWidget(QWidget* parent = nullptr);
    ~MemoryWidget() override;

    QSize sizeHint() const override;

    void setScrollBar(ScrollBar* scrollBar);

protected:
    void paintGL() override;

    void wheelEvent(QWheelEvent* event) override;
    void contextMenuEvent(QContextMenuEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void hideEvent(QHideEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private:
    ScrollBar* mScrollBar;
    std::vector<char> mDataBuffer;
    std::vector<char> mLineBuffer;
    int mMouseX;
    int mMouseY;
    int mAddressUnderMouse;
    bool mShowingToolTip;

    void showToolTip(int tooltipX, int tooltipY, const QString& text);
    void hideToolTip();

    Q_DISABLE_COPY(MemoryWidget)
};

#endif
