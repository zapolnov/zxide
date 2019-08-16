#ifndef DEBUGGER_DISPLAYWIDGET_H
#define DEBUGGER_DISPLAYWIDGET_H

#include <QOpenGLWidget>

class DisplayWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit DisplayWidget(QWidget* parent = nullptr);
    ~DisplayWidget() override;

    QSize sizeHint() const override;

protected:
    void paintGL() override;

    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private:
    quint8 mScreenBuffer[6144 + 768];
    QImage mImage;

    Q_DISABLE_COPY(DisplayWidget)
};

#endif
