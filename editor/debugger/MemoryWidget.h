#ifndef DEBUGGER_MEMORYWIDGET_H
#define DEBUGGER_MEMORYWIDGET_H

#include <QOpenGLWidget>
#include "debugger/EmulatorCore.h"
#include "util/SimpleTextPainter.h"
#include <memory>
#include <vector>

class QTimer;
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

private:
    ScrollBar* mScrollBar;
    std::vector<char> mDataBuffer;
    std::vector<char> mLineBuffer;

    Q_DISABLE_COPY(MemoryWidget)
};

#endif
