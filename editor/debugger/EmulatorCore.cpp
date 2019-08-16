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
#include <input.h>
#include <timer/timer.h>
#include <z80/z80.h>
#include <z80/z80_macros.h>
#include <debugger/debugger.h>
#include <debugger/debugger_internals.h>
#include <peripherals/ula.h>
#include <../fuse/settings.h> // stupid, but works; otherwise Windows confuses it with Settings.h
int fuse_init(int argc, char** argv);
int fuse_end(void);
extern int display_flash_reversed;
}

static QElapsedTimer elapsedTimer;
static QMutex mutex;
static std::vector<std::function<void()>> commandQueue;
static char memory[0x10000];
static bool memoryPageValid[MEMORY_PAGES_IN_64K];
static bool shouldUpdateUi;
static bool displayFlashReversed;
static bool memoryWasChanged;
static bool paused;
static Registers registers;
static int emulatorSpeed;

EmulatorCore* EmulatorCore::mInstance;

EmulatorCore::EmulatorCore(QObject* parent)
    : QObject(parent)
    , mThread(new Thread(this))
    , mShiftPressed(false)
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

bool EmulatorCore::displayFlashReversed() const
{
    QMutexLocker lock(&mutex);
    return ::displayFlashReversed;
}

void EmulatorCore::getMemory(unsigned address, void* buffer, size_t bufferSize)
{
    QMutexLocker lock(&mutex);
    memcpy(buffer, memory + address, bufferSize);
}

static input_key mapKey(int key, bool shift)
{
    switch (key) {
        default: return INPUT_KEY_NONE; break;

        case Qt::Key_Escape: return INPUT_KEY_Escape; break;
        case Qt::Key_1: return INPUT_KEY_1; break;
        case Qt::Key_2: return INPUT_KEY_2; break;
        case Qt::Key_3: return INPUT_KEY_3; break;
        case Qt::Key_4: return INPUT_KEY_4; break;
        case Qt::Key_5: return INPUT_KEY_5; break;
        case Qt::Key_6: return INPUT_KEY_6; break;
        case Qt::Key_7: return INPUT_KEY_7; break;
        case Qt::Key_8: return INPUT_KEY_8; break;
        case Qt::Key_9: return INPUT_KEY_9; break;
        case Qt::Key_0: return INPUT_KEY_0; break;
        case Qt::Key_Minus: return INPUT_KEY_minus; break;
        case Qt::Key_Equal: return INPUT_KEY_equal; break;
        case Qt::Key_Backspace: return INPUT_KEY_BackSpace; break;
        case Qt::Key_Tab: return INPUT_KEY_Tab; break;
        case Qt::Key_Q: return (!shift ? INPUT_KEY_q : INPUT_KEY_Q); break;
        case Qt::Key_W: return (!shift ? INPUT_KEY_w : INPUT_KEY_W); break;
        case Qt::Key_E: return (!shift ? INPUT_KEY_e : INPUT_KEY_E); break;
        case Qt::Key_R: return (!shift ? INPUT_KEY_r : INPUT_KEY_R); break;
        case Qt::Key_T: return (!shift ? INPUT_KEY_t : INPUT_KEY_T); break;
        case Qt::Key_Y: return (!shift ? INPUT_KEY_y : INPUT_KEY_Y); break;
        case Qt::Key_U: return (!shift ? INPUT_KEY_u : INPUT_KEY_U); break;
        case Qt::Key_I: return (!shift ? INPUT_KEY_i : INPUT_KEY_I); break;
        case Qt::Key_O: return (!shift ? INPUT_KEY_o : INPUT_KEY_O); break;
        case Qt::Key_P: return (!shift ? INPUT_KEY_p : INPUT_KEY_P); break;
        case Qt::Key_CapsLock: return INPUT_KEY_Caps_Lock; break;
        case Qt::Key_A: return (!shift ? INPUT_KEY_a : INPUT_KEY_A); break;
        case Qt::Key_S: return (!shift ? INPUT_KEY_s : INPUT_KEY_S); break;
        case Qt::Key_D: return (!shift ? INPUT_KEY_d : INPUT_KEY_D); break;
        case Qt::Key_F: return (!shift ? INPUT_KEY_f : INPUT_KEY_F); break;
        case Qt::Key_G: return (!shift ? INPUT_KEY_g : INPUT_KEY_G); break;
        case Qt::Key_H: return (!shift ? INPUT_KEY_h : INPUT_KEY_H); break;
        case Qt::Key_J: return (!shift ? INPUT_KEY_j : INPUT_KEY_J); break;
        case Qt::Key_K: return (!shift ? INPUT_KEY_k : INPUT_KEY_K); break;
        case Qt::Key_L: return (!shift ? INPUT_KEY_l : INPUT_KEY_L); break;
        case Qt::Key_Semicolon: return INPUT_KEY_semicolon; break;
        case Qt::Key_Apostrophe: return INPUT_KEY_apostrophe; break;
        case Qt::Key_NumberSign: return INPUT_KEY_numbersign; break;
        case Qt::Key_Return: return INPUT_KEY_Return; break;
        case Qt::Key_Z: return (!shift ? INPUT_KEY_z : INPUT_KEY_Z); break;
        case Qt::Key_X: return (!shift ? INPUT_KEY_x : INPUT_KEY_X); break;
        case Qt::Key_C: return (!shift ? INPUT_KEY_c : INPUT_KEY_C); break;
        case Qt::Key_V: return (!shift ? INPUT_KEY_v : INPUT_KEY_V); break;
        case Qt::Key_B: return (!shift ? INPUT_KEY_b : INPUT_KEY_B); break;
        case Qt::Key_N: return (!shift ? INPUT_KEY_n : INPUT_KEY_N); break;
        case Qt::Key_M: return (!shift ? INPUT_KEY_m : INPUT_KEY_M); break;
        case Qt::Key_Comma: return INPUT_KEY_comma; break;
        case Qt::Key_Period: return INPUT_KEY_period; break;
        case Qt::Key_Slash: return INPUT_KEY_slash; break;

        case Qt::Key_Asterisk: return INPUT_KEY_asterisk; break;
        case Qt::Key_Dollar: return INPUT_KEY_dollar; break;
        case Qt::Key_Exclam: return INPUT_KEY_exclam; break;
        case Qt::Key_Less: return INPUT_KEY_less; break;
        case Qt::Key_ParenRight: return INPUT_KEY_parenright; break;
        case Qt::Key_Colon: return INPUT_KEY_colon; break;
        case Qt::Key_Plus: return INPUT_KEY_plus; break;

        case Qt::Key_Space: return INPUT_KEY_space; break;
        case Qt::Key_Menu: return (!shift ? INPUT_KEY_Alt_L : INPUT_KEY_Mode_switch); break;

        case Qt::Key_Left: return INPUT_KEY_Left; break;
        case Qt::Key_Down: return INPUT_KEY_Down; break;
        case Qt::Key_Up: return INPUT_KEY_Up; break;
        case Qt::Key_Right: return INPUT_KEY_Right; break;

        case Qt::Key_Enter: return INPUT_KEY_KP_Enter; break;

        case Qt::Key_QuoteDbl: return INPUT_KEY_quotedbl; break;
        case Qt::Key_Percent: return INPUT_KEY_percent; break;
        case Qt::Key_Ampersand: return INPUT_KEY_ampersand; break;
        case Qt::Key_ParenLeft: return INPUT_KEY_parenleft; break;
        case Qt::Key_Greater: return INPUT_KEY_greater; break;
        case Qt::Key_Question: return INPUT_KEY_question; break;
        case Qt::Key_At: return INPUT_KEY_at; break;
        case Qt::Key_AsciiCircum: return INPUT_KEY_asciicircum; break;
        case Qt::Key_Underscore: return INPUT_KEY_underscore; break;
    }
}

void EmulatorCore::pressKey(int key)
{
    if (key == Qt::Key_Shift) {
        mShiftPressed = true;
        return;
    }

    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return;

    input_key keyCode = mapKey(key, mShiftPressed);
    if (keyCode == INPUT_KEY_NONE)
        return;

    auto cmd = [keyCode] {
            input_event_t ev;
            ev.type = INPUT_EVENT_KEYPRESS;
            ev.types.key.native_key = keyCode;
            ev.types.key.spectrum_key = keyCode;
            input_event(&ev);
        };

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
}

void EmulatorCore::releaseKey(int key)
{
    if (key == Qt::Key_Shift) {
        mShiftPressed = false;
        return;
    }

    Q_ASSERT(mThread->isRunning());
    if (!mThread->isRunning())
        return;

    input_key keyCode = mapKey(key, mShiftPressed);
    if (keyCode == INPUT_KEY_NONE)
        return;

    auto cmd = [keyCode] {
            input_event_t ev;
            ev.type = INPUT_EVENT_KEYRELEASE;
            ev.types.key.native_key = keyCode;
            ev.types.key.spectrum_key = keyCode;
            input_event(&ev);
        };

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
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

    displayFlashReversed = (display_flash_reversed != 0);
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
