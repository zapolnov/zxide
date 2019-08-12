#include "EmulatorWindow.h"
#include <QTimer>
#include <QMessageBox>
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

EmulatorWindow::EmulatorWindow(QWidget* parent)
    : QWidget(parent)
    , mTimer(nullptr)
    , mInitialized(false)
{
    int argc = 1;
    const char* const argv[] = { "fuse" };
    if (fuse_init(argc, (char**)argv)) {
        show();
        QMessageBox::critical(this, tr("Error"), tr("Unable to initialize emulator core."));
        return;
    }

    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &EmulatorWindow::tick);

    mInitialized = true;
}

EmulatorWindow::~EmulatorWindow()
{
    fuse_end();
}

void EmulatorWindow::tick()
{
    z80_do_opcodes();
    event_do_events();
}

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
            strcpy(ctx->path, ":/");
            return 1;

        case 1:
            return 0;
    }

    Q_ASSERT(false);
    return 0;
}

static QElapsedTimer timer;

double timer_get_time()
{
    if (timer.isValid())
        return timer.elapsed() * 0.001;
    else {
        timer.start();
        return 0;
    }
}

void timer_sleep(int ms)
{
    QThread::msleep(ms);
}
