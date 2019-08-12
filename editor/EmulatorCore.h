#ifndef EMULATORCORE_H
#define EMULATORCORE_H

#include <QWidget>

class QTimer;

class EmulatorCore : public QObject
{
    Q_OBJECT

public:
    explicit EmulatorCore(QObject* parent = nullptr);
    ~EmulatorCore() override;

    static EmulatorCore* instance() { return mInstance; }

    bool isRunning() const { return mRunning; }
    bool start();
    void stop();

signals:
    void error(const QString& message);
    void updateUi();

private:
    static EmulatorCore* mInstance;
    QTimer* mTimer;
    bool mRunning;

    void tick();

    Q_DISABLE_COPY(EmulatorCore)
};

#endif
