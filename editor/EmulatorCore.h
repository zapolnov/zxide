#ifndef EMULATORCORE_H
#define EMULATORCORE_H

#include <QWidget>

class QTimer;

struct Registers
{
    quint16 af;
    quint16 bc;
    quint16 de;
    quint16 hl;
    quint16 ix;
    quint16 iy;
    quint16 sp;
    quint16 pc;
    quint16 af_;
    quint16 bc_;
    quint16 de_;
    quint16 hl_;
    quint8 a;
    quint8 b;
    quint8 c;
    quint8 d;
    quint8 e;
    quint8 h;
    quint8 l;
    quint8 f;
    quint8 i;
    quint8 r;
    quint8 a_;
    quint8 b_;
    quint8 c_;
    quint8 d_;
    quint8 e_;
    quint8 h_;
    quint8 l_;
    quint8 f_;
};

class EmulatorCore : public QObject
{
    Q_OBJECT

public:
    class Thread;

    explicit EmulatorCore(QObject* parent = nullptr);
    ~EmulatorCore() override;

    static EmulatorCore* instance() { return mInstance; }

    bool start();
    void stop();
    bool isRunning() const;

    void reloadSettings();

    const Registers& registers() const { return mRegisters; }

    float currentSpeed() const;
    QString currentSpeedString() const;

signals:
    void error(const QString& message);
    void updated();
    void stopped();
    void updateUi();

private:
    static EmulatorCore* mInstance;
    Registers mRegisters;
    QTimer* mTimer;
    Thread* mThread;
    float mCurrentSpeed;

    void update();

    Q_DISABLE_COPY(EmulatorCore)
};

#endif
