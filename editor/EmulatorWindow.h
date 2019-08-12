#ifndef EMULATORWINDOW_H
#define EMULATORWINDOW_H

#include <QWidget>

class QTimer;

class EmulatorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EmulatorWindow(QWidget* parent = nullptr);
    ~EmulatorWindow();

private:
    QTimer* mTimer;
    bool mInitialized;

    void tick();

    Q_DISABLE_COPY(EmulatorWindow)
};

#endif
