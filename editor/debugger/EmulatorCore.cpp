#include "EmulatorCore.h"
#include "util/Settings.h"
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
#include <z80/z80_macros.h>
#include <peripherals/ula.h>
#include <../fuse/settings.h> // stupid, but works; otherwise Windows confuses it with Settings.h
int fuse_init(int argc, char** argv);
int fuse_end(void);
}

static QElapsedTimer elapsedTimer;
static int emulatorSpeed;

EmulatorCore* EmulatorCore::mInstance;

EmulatorCore::EmulatorCore(QObject* parent)
    : QObject(parent)
    , mThread(new Thread(this))
    , mCurrentSpeed(0)
    , mShouldUpdateUi(false)
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;

    connect(mThread, &QThread::started, this, &EmulatorCore::started);
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

Registers EmulatorCore::registers() const
{
    QMutexLocker lock(&mThread->mutex);
    return mRegisters;
}

void EmulatorCore::setRegister(Register reg, quint16 value)
{
    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return;

    auto cmd = [reg, value] {
            switch (reg) {
                case Reg_None: break;
                case Reg_AF: AF = value; return;
                case Reg_BC: BC = value; return;
                case Reg_DE: DE = value; return;
                case Reg_HL: HL = value; return;
                case Reg_IX: IX = value; return;
                case Reg_IY: IY = value; return;
                case Reg_SP: SP = value; return;
                case Reg_PC: PC = value; return;
                case Reg_AF_: AF_ = value; return;
                case Reg_BC_: BC_ = value; return;
                case Reg_DE_: DE_ = value; return;
                case Reg_HL_: HL_ = value; return;
                case Reg_A: Q_ASSERT(value <= 0xff); A = quint8(value & 0xFF); return;
                case Reg_B: Q_ASSERT(value <= 0xff); B = quint8(value & 0xFF); return;
                case Reg_C: Q_ASSERT(value <= 0xff); C = quint8(value & 0xFF); return;
                case Reg_D: Q_ASSERT(value <= 0xff); D = quint8(value & 0xFF); return;
                case Reg_E: Q_ASSERT(value <= 0xff); E = quint8(value & 0xFF); return;
                case Reg_H: Q_ASSERT(value <= 0xff); H = quint8(value & 0xFF); return;
                case Reg_L: Q_ASSERT(value <= 0xff); L = quint8(value & 0xFF); return;
                case Reg_F: Q_ASSERT(value <= 0xff); F = quint8(value & 0xFF); return;
                case Reg_I: Q_ASSERT(value <= 0xff); I = quint8(value & 0xFF); return;
                case Reg_R: Q_ASSERT(value <= 0xff); R = quint8(value & 0xFF); return;
                case Reg_A_: Q_ASSERT(value <= 0xff); A_ = quint8(value & 0xFF); return;
                case Reg_B_: Q_ASSERT(value <= 0xff); B_ = quint8(value & 0xFF); return;
                case Reg_C_: Q_ASSERT(value <= 0xff); C_ = quint8(value & 0xFF); return;
                case Reg_D_: Q_ASSERT(value <= 0xff); D_ = quint8(value & 0xFF); return;
                case Reg_E_: Q_ASSERT(value <= 0xff); E_ = quint8(value & 0xFF); return;
                case Reg_H_: Q_ASSERT(value <= 0xff); H_ = quint8(value & 0xFF); return;
                case Reg_L_: Q_ASSERT(value <= 0xff); L_ = quint8(value & 0xFF); return;
                case Reg_F_: Q_ASSERT(value <= 0xff); F_ = quint8(value & 0xFF); return;
            }
            Q_ASSERT(false);
        };

    QMutexLocker lock(&mThread->mutex);
    mThread->commandQueue.emplace_back(std::move(cmd));
}

int EmulatorCore::currentSpeed() const
{
    if (!mThread->isRunning())
        return 0;

    QMutexLocker lock(&mThread->mutex);
    return mCurrentSpeed;
}

QString EmulatorCore::currentSpeedString() const
{
    int speed;

    if (!mThread->isRunning())
        return QString();

    {
        QMutexLocker lock(&mThread->mutex);
        speed = mCurrentSpeed;
    }

    return QStringLiteral("%1%").arg(speed);
}

void EmulatorCore::update()
{
    bool shouldUpdateUi = false;

    {
        QMutexLocker lock(&mThread->mutex);
        shouldUpdateUi = mShouldUpdateUi;
        mShouldUpdateUi = false;
    }

    if (shouldUpdateUi)
        emit updateUi();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

EmulatorCore::Thread::Thread(QObject* parent)
    : QThread(parent)
{
}

EmulatorCore::Thread::~Thread()
{
}

void EmulatorCore::Thread::run()
{
    int argc = 1;
    const char* const argv[] = { "fuse" };
    if (fuse_init(argc, (char**)argv))
        return;

    while (!isInterruptionRequested()) {
        z80_do_opcodes();
        event_do_events();
        syncWithMainThread();
    }

    fuse_end();
}

void EmulatorCore::Thread::syncWithMainThread()
{
    QMutexLocker lock(&mutex);

    while (!commandQueue.empty()) {
        auto cmd = commandQueue.front();
        commandQueue.pop_front();
        cmd();
    }

    auto emu = EmulatorCore::instance();

    if (emu->mCurrentSpeed != emulatorSpeed) {
        emu->mCurrentSpeed = emulatorSpeed;
        emu->mShouldUpdateUi = true;
    }

    emu->mRegisters.tstates = tstates;
    emu->mRegisters.af = AF;
    emu->mRegisters.bc = BC;
    emu->mRegisters.de = DE;
    emu->mRegisters.hl = HL;
    emu->mRegisters.ix = IX;
    emu->mRegisters.iy = IY;
    emu->mRegisters.sp = SP;
    emu->mRegisters.pc = PC;
    emu->mRegisters.af_ = AF_;
    emu->mRegisters.bc_ = BC_;
    emu->mRegisters.de_ = DE_;
    emu->mRegisters.hl_ = HL_;
    emu->mRegisters.a = A;
    emu->mRegisters.b = B;
    emu->mRegisters.c = C;
    emu->mRegisters.d = D;
    emu->mRegisters.e = E;
    emu->mRegisters.h = H;
    emu->mRegisters.l = L;
    emu->mRegisters.f = F;
    emu->mRegisters.i = I;
    emu->mRegisters.r = R;
    emu->mRegisters.a_ = A_;
    emu->mRegisters.b_ = B_;
    emu->mRegisters.c_ = C_;
    emu->mRegisters.d_ = D_;
    emu->mRegisters.e_ = E_;
    emu->mRegisters.h_ = H_;
    emu->mRegisters.l_ = L_;
    emu->mRegisters.f_ = F_;
    emu->mRegisters.im = IM;
    emu->mRegisters.iff1 = IFF1;
    emu->mRegisters.iff2 = IFF2;
    emu->mRegisters.ula = ula_last_byte();
    emu->mRegisters.sf = (emu->mRegisters.f & FLAG_S) != 0;
    emu->mRegisters.zf = (emu->mRegisters.f & FLAG_Z) != 0;
    emu->mRegisters.hf = (emu->mRegisters.f & FLAG_H) != 0;
    emu->mRegisters.pf = (emu->mRegisters.f & FLAG_P) != 0;
    emu->mRegisters.nf = (emu->mRegisters.f & FLAG_N) != 0;
    emu->mRegisters.cf = (emu->mRegisters.f & FLAG_C) != 0;
    emu->mRegisters.halted = z80.halted;
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
    emulatorSpeed = int(speed);
    return 0;
}
