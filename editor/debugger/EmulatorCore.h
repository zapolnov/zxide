#ifndef DEBUGGER_EMULATORCORE_H
#define DEBUGGER_EMULATORCORE_H

#include <QWidget>
#include <QThread>
#include <QMutex>

struct Registers
{
    quint32 tstates;
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
    quint8 im;
    quint8 iff1;
    quint8 iff2;
    quint8 ula;
    bool sf;
    bool zf;
    bool hf;
    bool pf;
    bool nf;
    bool cf;
    bool halted;
};

class EmulatorCore : public QObject
{
    Q_OBJECT

public:
    explicit EmulatorCore(QObject* parent = nullptr);
    ~EmulatorCore() override;

    static EmulatorCore* instance() { return mInstance; }

    bool start();
    void stop();
    bool isRunning() const;

    void reloadSettings();

    Registers registers() const;

    int currentSpeed() const;
    QString currentSpeedString() const;

signals:
    void started();
    void stopped();
    void updateUi();

private:
    class Thread : public QThread
    {
    public:
        QMutex mutex;
        explicit Thread(QObject* parent = nullptr);
        void run() override;

    private:
        void syncWithMainThread();
        Q_DISABLE_COPY(Thread)
    };

    static EmulatorCore* mInstance;
    Registers mRegisters;
    Thread* mThread;
    int mCurrentSpeed;
    bool mShouldUpdateUi;

    void update();

    Q_DISABLE_COPY(EmulatorCore)
};

#endif
