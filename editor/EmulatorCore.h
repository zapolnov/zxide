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

    float currentSpeed() const { return (mRunning ? mCurrentSpeed : 0.0f); }
    QString currentSpeedString() const;

    void internal_onSpeedChanged(float speed);

signals:
    void error(const QString& message);
    void updateUi();

private:
    static EmulatorCore* mInstance;
    QTimer* mTimer;
    float mCurrentSpeed;
    bool mRunning;

    void tick();

    Q_DISABLE_COPY(EmulatorCore)
};

#endif
