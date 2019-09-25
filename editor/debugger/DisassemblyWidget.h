#ifndef DEBUGGER_DISASSEMBLYWIDGET_H
#define DEBUGGER_DISASSEMBLYWIDGET_H

#include <QOpenGLWidget>
#include "util/SimpleTextPainter.h"
#include <vector>

class QTimer;

class DisassemblyWidget : public QOpenGLWidget, public SimpleTextPainter
{
    Q_OBJECT

public:
    explicit DisassemblyWidget(QWidget* parent = nullptr);
    ~DisassemblyWidget() override;

    QSize sizeHint() const override;

protected:
    void paintGL() override;

    Q_DISABLE_COPY(DisassemblyWidget)
};

#endif
