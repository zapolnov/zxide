#include "EmulatorCore.h"
#include <QTimer>
#include <QFile>
#include <QElapsedTimer>
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
int fuse_init(int argc, char** argv);
int fuse_end(void);
}

static QElapsedTimer mElapsedTimer;

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
    if (mElapsedTimer.isValid())
        return mElapsedTimer.elapsed() * 0.001;
    else {
        mElapsedTimer.start();
        return 0;
    }
}

void timer_sleep(int ms)
{
    QThread::msleep(ms);
}

int ui_statusbar_update_speed(float speed)
{
    emit EmulatorCore::instance()->internal_onSpeedChanged(speed);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

EmulatorCore* EmulatorCore::mInstance;

EmulatorCore::EmulatorCore(QObject* parent)
    : QObject(parent)
    , mTimer(nullptr)
    , mCurrentSpeed(0.0f)
    , mRunning(false)
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;
}

EmulatorCore::~EmulatorCore()
{
    stop();

    Q_ASSERT(mInstance == this);
    mInstance = nullptr;
}

bool EmulatorCore::start()
{
    Q_ASSERT(!mRunning);
    if (mRunning)
        return true;

    int argc = 1;
    const char* const argv[] = { "fuse" };
    if (fuse_init(argc, (char**)argv)) {
        emit error(tr("Unable to initialize emulator core."));
        return false;
    }

    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &EmulatorCore::tick);
    mTimer->start(0);

    mRunning = true;
    emit updateUi();

    return true;
}

void EmulatorCore::stop()
{
    if (!mRunning)
        return;

    mTimer->stop();
    mTimer->deleteLater();
    mTimer = nullptr;

    fuse_end();

    mRunning = false;
    emit updateUi();
}

QString EmulatorCore::currentSpeedString() const
{
    if (!mRunning)
        return QString();
    return QStringLiteral("%1%").arg(int(mCurrentSpeed));
}

void EmulatorCore::internal_onSpeedChanged(float speed)
{
    if (mCurrentSpeed != speed) {
        mCurrentSpeed = speed;
        emit updateUi();
    }
}

void EmulatorCore::tick()
{
    if (!mRunning)
        return;

    z80_do_opcodes();
    event_do_events();
}
