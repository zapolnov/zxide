#ifndef DEBUGGER_STACKWIDGET_H
#define DEBUGGER_STACKWIDGET_H

#include <QOpenGLWidget>
#include "util/SimpleTextPainter.h"
#include <vector>

class QTimer;

class StackWidget : public QOpenGLWidget, public SimpleTextPainter
{
    Q_OBJECT

public:
    explicit StackWidget(QWidget* parent = nullptr);
    ~StackWidget() override;

    QSize sizeHint() const override;

protected:
    void paintGL() override;

private:
    std::vector<char> mLineBuffer;
    std::vector<char> mDataBuffer;

    Q_DISABLE_COPY(StackWidget)
};

#endif
