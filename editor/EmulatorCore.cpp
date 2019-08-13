#include "EmulatorCore.h"
#include "Settings.h"
#include <QTimer>
#include <QThread>
#include <QFile>
#include <QElapsedTimer>
#include <QMutex>
#include <QThread>

extern "C" {
#include <libspectrum.h>
#include <ui/ui.h>
#include <utils.h>
#include <compat.h>
#include <event.h>
#include <fuse.h>
#include <timer/timer.h>
#include <z80/z80.h>
#include <z80/z80_macros.h>
#include <../fuse/settings.h> // stupid, but works; otherwise Windows confuses it with Settings.h
int fuse_init(int argc, char** argv);
int fuse_end(void);
}

static QElapsedTimer elapsedTimer;
static float emulatorSpeed;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class EmulatorCore::Thread : public QThread
{
public:
    QMutex mutex;

    explicit Thread(QObject* parent = nullptr)
        : QThread(parent)
    {
    }

    void run() override
    {
        if (!init())
            return;

        while (!isInterruptionRequested())
            tick();

        cleanup();
    }

private:
    bool init()
    {
        QMutexLocker lock(&mutex);

        int argc = 1;
        const char* const argv[] = { "fuse" };
        if (fuse_init(argc, (char**)argv))
            return false;

        return true;
    }

    void cleanup()
    {
        QMutexLocker lock(&mutex);
        fuse_end();
    }

    void tick()
    {
        QMutexLocker lock(&mutex);
        z80_do_opcodes();
        event_do_events();
    }

    Q_DISABLE_COPY(Thread)
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const compat_fd COMPAT_FILE_OPEN_FAILED = NULL;

compat_fd compat_file_open(const char* path, int write)
{
    auto file = std::make_unique<QFile>(path);
    if (!file->open(write ? QFile::WriteOnly : QFile::ReadOnly))
        return nullptr;
    return (compat_fd)file.release();
}

off_t compat_file_get_length(compat_fd fd)
{
    return ((QFile*)fd)->size();
}

int compat_file_read(compat_fd fd, utils_file* file)
{
    qint64 bytesRead = ((QFile*)fd)->read((char*)file->buffer, file->length);
    if (bytesRead != file->length) {
        ui_error(UI_ERROR_ERROR, "error reading file: expected %lu bytes, but read only %lu",
            (unsigned long)file->length, (unsigned long)bytesRead);
        return 1;
    }
    return 0;
}

int compat_file_write(compat_fd fd, const unsigned char* buffer, size_t length)
{
    qint64 bytesWritten = ((QFile*)fd)->write((const char*)buffer, length);
    if (bytesWritten != length) {
        ui_error(UI_ERROR_ERROR, "error writing file: expected %lu bytes, but wrote only %lu",
            (unsigned long)length, (unsigned long)bytesWritten);
        return 1;
    }
    return 0;
}

int compat_file_close(compat_fd fd)
{
    delete (QFile*)fd;
    return 0;
}

int compat_file_exists(const char* path)
{
    return QFile::exists(path);
}

int compat_is_absolute_path(const char* path)
{
  #ifdef _WIN32
    if (path[0] == '\\') return 1;
    if (path[0] && path[1] == ':') return 1;
  #endif
    return path[0] == '/';
}

int compat_get_next_path(path_context* ctx)
{
    switch ((ctx->state)++) {
        case 0:
            strcpy(ctx->path, ":/fuse/");
            return 1;

        case 1:
            return 0;
    }

    Q_ASSERT(false);
    return 0;
}

double timer_get_time()
{
    if (elapsedTimer.isValid())
        return elapsedTimer.elapsed() * 0.001;
    else {
        elapsedTimer.start();
        return 0;
    }
}

void timer_sleep(int ms)
{
    QThread::msleep(ms);
}

extern "C" int settings_command_line(struct settings_info* fuse, int*, int, char**)
{
    Settings settings;
    fuse->sound = (settings.enableSound() ? 1 : 0);
    return 0;
}

int ui_statusbar_update_speed(float speed)
{
    emulatorSpeed = speed;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

EmulatorCore* EmulatorCore::mInstance;

EmulatorCore::EmulatorCore(QObject* parent)
    : QObject(parent)
    , mTimer(new QTimer(this))
    , mThread(new Thread(this))
    , mCurrentSpeed(0.0f)
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;

    mTimer->setInterval(1000 / 50);
    connect(mTimer, &QTimer::timeout, this, &EmulatorCore::update);

    connect(mThread, &QThread::started, mTimer, QOverload<>::of(&QTimer::start));
    connect(mThread, &QThread::finished, mTimer, &QTimer::stop);
    connect(mThread, &QThread::started, this, &EmulatorCore::updateUi);
    connect(mThread, &QThread::finished, this, &EmulatorCore::updateUi);
    connect(mThread, &QThread::finished, this, &EmulatorCore::stopped);

    reloadSettings();
}

EmulatorCore::~EmulatorCore()
{
    stop();

    Q_ASSERT(mInstance == this);
    mInstance = nullptr;
}

bool EmulatorCore::start()
{
    mThread->start();
    return true;
}

void EmulatorCore::stop()
{
    mThread->requestInterruption();
    mThread->wait();
}

bool EmulatorCore::isRunning() const
{
    return mThread->isRunning();
}

void EmulatorCore::reloadSettings()
{
    // FIXME
}

float EmulatorCore::currentSpeed() const
{
    return (mThread->isRunning() ? mCurrentSpeed : 0.0f);
}

QString EmulatorCore::currentSpeedString() const
{
    if (!mThread->isRunning())
        return QString();
    return QStringLiteral("%1%").arg(int(mCurrentSpeed));
}

void EmulatorCore::update()
{
    bool shouldUpdateUi = false;

    {
        QMutexLocker lock(&mThread->mutex);

        if (mCurrentSpeed != emulatorSpeed) {
            mCurrentSpeed = emulatorSpeed;
            shouldUpdateUi = true;
        }

        mRegisters.af = AF;
        mRegisters.bc = BC;
        mRegisters.de = DE;
        mRegisters.hl = HL;
        mRegisters.ix = IX;
        mRegisters.iy = IY;
        mRegisters.sp = SP;
        mRegisters.pc = PC;
        mRegisters.af_ = AF_;
        mRegisters.bc_ = BC_;
        mRegisters.de_ = DE_;
        mRegisters.hl_ = HL_;
        mRegisters.a = A;
        mRegisters.b = B;
        mRegisters.c = C;
        mRegisters.d = D;
        mRegisters.e = E;
        mRegisters.h = H;
        mRegisters.l = L;
        mRegisters.f = F;
        mRegisters.i = I;
        mRegisters.r = R;
        mRegisters.a_ = A_;
        mRegisters.b_ = B_;
        mRegisters.c_ = C_;
        mRegisters.d_ = D_;
        mRegisters.e_ = E_;
        mRegisters.h_ = H_;
        mRegisters.l_ = L_;
        mRegisters.f_ = F_;
    }

    if (shouldUpdateUi)
        emit updateUi();

    emit updated();
}
