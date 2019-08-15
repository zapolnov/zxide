#include "EmulatorCore.h"
#include "util/Settings.h"
#include <QFile>
#include <QElapsedTimer>
#include <QTimer>
#include <QThread>
#include <QMutex>
#include <functional>
#include <vector>

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
#include <debugger/debugger.h>
#include <debugger/debugger_internals.h>
#include <peripherals/ula.h>
#include <../fuse/settings.h> // stupid, but works; otherwise Windows confuses it with Settings.h
int fuse_init(int argc, char** argv);
int fuse_end(void);
}

static QElapsedTimer elapsedTimer;
static QMutex mutex;
static std::vector<std::function<void()>> commandQueue;
static char memory[0x10000];
static bool memoryPageValid[MEMORY_PAGES_IN_64K];
static bool shouldUpdateUi;
static bool memoryWasChanged;
static bool paused;
static Registers registers;
static int emulatorSpeed;

EmulatorCore* EmulatorCore::mInstance;

EmulatorCore::EmulatorCore(QObject* parent)
    : QObject(parent)
    , mThread(new Thread(this))
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;

    mTimer = new QTimer(this);
    mTimer->setInterval(1000 / 4);
    connect(mTimer, &QTimer::timeout, this, &EmulatorCore::update);
    connect(mThread, &QThread::started, mTimer, QOverload<>::of(&QTimer::start));
    connect(mThread, &QThread::finished, mTimer, &QTimer::stop);

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

void EmulatorCore::pause()
{
    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return;

    auto cmd = [] {
            debugger_mode = DEBUGGER_MODE_HALTED;
        };

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
}

void EmulatorCore::stepInto()
{
    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return;

    auto cmd = [] {
            debugger_step();
        };

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
}

void EmulatorCore::stepOut()
{
    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return;

    auto cmd = [] {
            debugger_breakpoint_exit();
        };

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
}

void EmulatorCore::stepOver()
{
    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return;

    auto cmd = [] {
            debugger_next();
        };

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
}

void EmulatorCore::runTo(const File* file, int line)
{
    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return;

    auto cmd = [] {
            // FIXME
        };

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
}

void EmulatorCore::unpause()
{
    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return;

    auto cmd = [] {
            debugger_run();
        };

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
}

bool EmulatorCore::isPaused() const
{
    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return false;

    QMutexLocker lock(&mutex);
    return paused;
}

void EmulatorCore::reloadSettings()
{
    // FIXME
}

Registers EmulatorCore::registers() const
{
    QMutexLocker lock(&mutex);
    return ::registers;
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

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
}

int EmulatorCore::currentSpeed() const
{
    if (!mThread->isRunning())
        return 0;

    QMutexLocker lock(&mutex);
    return emulatorSpeed;
}

QString EmulatorCore::currentSpeedString() const
{
    int speed;

    if (!mThread->isRunning())
        return QString();

    {
        QMutexLocker lock(&mutex);
        speed = emulatorSpeed;
    }

    return QStringLiteral("%1%").arg(speed);
}

void EmulatorCore::getMemory(unsigned address, void* buffer, size_t bufferSize)
{
    QMutexLocker lock(&mutex);
    memcpy(buffer, memory + address, bufferSize);
}

void EmulatorCore::update()
{
    bool shouldUpdateUi_ = false;
    bool memoryWasChanged_ = false;

    {
        QMutexLocker lock(&mutex);
        shouldUpdateUi_ = shouldUpdateUi;
        shouldUpdateUi = false;
        memoryWasChanged_ = memoryWasChanged;
        memoryWasChanged = false;
    }

    if (memoryWasChanged_)
        emit memoryChanged();
    if (shouldUpdateUi_)
        emit updateUi();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void syncWithMainThread()
{
    QMutexLocker lock(&mutex);

    if (!commandQueue.empty()) {
        std::vector<std::function<void()>> commands{std::move(commandQueue)};
        commandQueue = std::vector<std::function<void()>>();

        lock.unlock();
        for (const auto& cmd : commands)
            cmd();
        lock.relock();
    }

    registers.tstates = tstates;
    registers.af = AF;
    registers.bc = BC;
    registers.de = DE;
    registers.hl = HL;
    registers.ix = IX;
    registers.iy = IY;
    registers.sp = SP;
    registers.pc = PC;
    registers.af_ = AF_;
    registers.bc_ = BC_;
    registers.de_ = DE_;
    registers.hl_ = HL_;
    registers.a = A;
    registers.b = B;
    registers.c = C;
    registers.d = D;
    registers.e = E;
    registers.h = H;
    registers.l = L;
    registers.f = F;
    registers.i = I;
    registers.r = R;
    registers.a_ = A_;
    registers.b_ = B_;
    registers.c_ = C_;
    registers.d_ = D_;
    registers.e_ = E_;
    registers.h_ = H_;
    registers.l_ = L_;
    registers.f_ = F_;
    registers.im = IM;
    registers.iff1 = IFF1;
    registers.iff2 = IFF2;
    registers.ula = ula_last_byte();
    registers.sf = (registers.f & FLAG_S) != 0;
    registers.zf = (registers.f & FLAG_Z) != 0;
    registers.hf = (registers.f & FLAG_H) != 0;
    registers.pf = (registers.f & FLAG_P) != 0;
    registers.nf = (registers.f & FLAG_N) != 0;
    registers.cf = (registers.f & FLAG_C) != 0;
    registers.halted = z80.halted;

    int offset = 0;
    for (int i = 0; i < MEMORY_PAGES_IN_64K; i++) {
        if (!memoryPageValid[i]) {
            memcpy(memory + offset, memory_map_read[i].page, MEMORY_PAGE_SIZE);
            memoryPageValid[i] = true;
            memoryWasChanged = true;
        }
        offset += MEMORY_PAGE_SIZE;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

EmulatorCore::Thread::Thread(QObject* parent)
    : QThread(parent)
{
}

void EmulatorCore::Thread::run()
{
    int argc = 1;
    const char* const argv[] = { "fuse" };
    if (fuse_init(argc, (char**)argv))
        return;

    memset(memoryPageValid, 0, sizeof(memoryPageValid));

    while (!isInterruptionRequested()) {
        if (paused) // no need to protect it with mutex as it is only set by this thread
            QThread::msleep(10);
        else {
            z80_do_opcodes();
            event_do_events();
        }
        syncWithMainThread();
    }

    if (paused)
        debugger_run(); // "unpause" the debugger before shutting down

    fuse_end();
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

int ui_debugger_activate()
{
    {
        QMutexLocker lock(&mutex);
        if (!paused) {
            paused = true;
            shouldUpdateUi = true;
        }
    }

    while (paused && !QThread::currentThread()->isInterruptionRequested()) {
        QThread::msleep(10);
        syncWithMainThread();
    }

    return 0;
}

int ui_debugger_deactivate(int)
{
    QMutexLocker lock(&mutex);
    if (paused) {
        paused = false;
        shouldUpdateUi = true;
    }
    return 0;
}

extern "C" void ui_notify_memory_page_changed(int page)
{
    QMutexLocker lock(&mutex);
    memoryPageValid[page] = false;
}

int ui_statusbar_update_speed(float speed)
{
    int spd = int(speed);

    {
        QMutexLocker lock(&mutex);
        if (emulatorSpeed != spd) {
            emulatorSpeed = spd;
            shouldUpdateUi = true;
        }
    }

    return 0;
}
