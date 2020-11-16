#include "EmulatorCore.h"
#include "compiler/ProgramBinary.h"
#include "compiler/ProgramDebugInfo.h"
#include "editor/FileManager.h"
#include "util/Settings.h"
#include <QImage>
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
#include <ui/uidisplay.h>
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
int dxsoundShouldAbort;
int fuse_init(int argc, char** argv);
int fuse_end(void);
int debugger_run_to_address(unsigned addr);
}

namespace
{
    struct Breakpoint
    {
        debugger_breakpoint_type type;
        int page;
        libspectrum_word offset;
        size_t ignore;
    };
}

const Color ZXPalette[] = {
    { 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0xc0 },
    { 0xc0, 0x00, 0x00 },
    { 0xc0, 0x00, 0xc0 },
    { 0x00, 0xc0, 0x00 },
    { 0x00, 0xc0, 0xc0 },
    { 0xc0, 0xc0, 0x00 },
    { 0xc0, 0xc0, 0xc0 },
    { 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0xff },
    { 0xff, 0x00, 0x00 },
    { 0xff, 0x00, 0xff },
    { 0x00, 0xff, 0x00 },
    { 0x00, 0xff, 0xff },
    { 0xff, 0xff, 0x00 },
    { 0xff, 0xff, 0xff },
};

namespace
{
    struct AllowStack
    {
        unsigned start;
        unsigned size;
        std::vector<uint8_t> values;
    };
}

static QElapsedTimer elapsedTimer;
static QMutex mutex;
static std::vector<std::function<void()>> commandQueue;
static std::vector<MemoryOperationInfo> memoryOperations;
static std::vector<MemoryOperationInfo> memoryOperations_mainThread;
static std::vector<ControlFlowInfo> controlFlows;
static std::vector<ControlFlowInfo> controlFlows_mainThread;
static std::vector<Breakpoint> breakpoints;
static bool writeAllowed[0x10000];
static std::vector<AllowStack> writeAllowStack;
static std::unordered_map<unsigned, std::vector<ProgramWriteProtection>> writeProtection;
static std::unique_ptr<ProgramBinary> programBinary;
static QImage screenBack;
static QImage screenFront;
static char memory[0x10000];
static bool memoryPageValid[MEMORY_PAGES_IN_64K];
static volatile bool collectMemoryOperations;
static volatile bool collectControlFlow;
static bool shouldUpdateUi;
static bool shouldUpdateBreakpoints = true;
static bool shouldEmitPausedSignal;
static bool shouldEmitUnpausedSignal;
static int runtoAddress = -1;
static int lastHighlightedRuntoAddress = -1;
static unsigned pausePC;
static unsigned prevSP;
static unsigned prevPC;
static bool memoryWasChanged;
static bool emulatorPaused;
static bool paused;
static Registers registers;
static QString tapeFile;
static Machine currentMachine;
static int emulatorSpeed;

EmulatorCore* EmulatorCore::mInstance;
const int EmulatorCore::ScreenWidth = DISPLAY_WIDTH_COLS * 8 + 2 * DISPLAY_BORDER_WIDTH_COLS * 8;
const int EmulatorCore::ScreenHeight = DISPLAY_SCREEN_HEIGHT;

static const SourceLocation dummySourceLocation{};

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
    connect(mThread, &QThread::finished, this, &EmulatorCore::update);

    connect(mThread, &QThread::started, this, &EmulatorCore::started);
    connect(mThread, &QThread::started, this, &EmulatorCore::updateUi);
    connect(mThread, &QThread::finished, this, &EmulatorCore::updateUi);
    connect(mThread, &QThread::finished, this, &EmulatorCore::stopped);

    connect(BreakpointsModel::instance(), &BreakpointsModel::breakpointAdded, this, &EmulatorCore::onBreakpointAdded);
    connect(BreakpointsModel::instance(), &BreakpointsModel::breakpointRemoved, this, &EmulatorCore::onBreakpointRemoved);

    connect(this, &EmulatorCore::internal_sendError, this, &EmulatorCore::error, Qt::QueuedConnection);
    ::currentMachine = Settings().emulatorMachine();
}

EmulatorCore::~EmulatorCore()
{
    stop();

    Q_ASSERT(mInstance == this);
    mInstance = nullptr;
}

bool EmulatorCore::start()
{
    Q_ASSERT(!mThread->isRunning());
    if (mThread->isRunning())
        return false;

    updateBreakpoints();

    memset(writeAllowed, true, sizeof(writeAllowed));
    writeAllowStack.clear();

    tapeFile = mTapeFile;
    prevSP = unsigned(-1);
    prevPC = unsigned(-1);
    dxsoundShouldAbort = 0;
    mThread->start();

    return true;
}

void EmulatorCore::stop()
{
    dxsoundShouldAbort = 1;
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
            if (debugger_mode == DEBUGGER_MODE_RUN_TO_ADDRESS) {
                QMutexLocker lock(&mutex);
                runtoAddress = -1;
            }
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

    QMutexLocker lock(&mutex);

    ProgramDebugInfo* debugInfo;
    if (!programBinary || (debugInfo = programBinary->debugInfo()) == nullptr) {
        lock.unlock();
        emit error(tr("No debug information available."));
        return;
    }

    int addr = debugInfo->resolveAddress(file->relativeName(), line, true);
    if (addr < 0) {
        lock.unlock();
        emit error(tr("Selected location has no associated code."));
        return;
    }

    auto cmd = [addr] {
            debugger_run_to_address(unsigned(addr));
        };

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

bool EmulatorCore::hasProgramBinary() const
{
    QMutexLocker lock(&mutex);
    return programBinary != nullptr;
}

void EmulatorCore::setProgramBinary(std::unique_ptr<ProgramBinary> binary)
{
    std::unique_ptr<ProgramBinary> old;
    {
        QMutexLocker lock(&mutex);
        old = std::move(programBinary);
        programBinary = std::move(binary);
        if (programBinary && programBinary->debugInfo() != nullptr)
            programBinary->debugInfo()->getWriteProtection(writeProtection);
        else
            writeProtection.clear();
    }
}

SourceLocation EmulatorCore::sourceLocationForAddress(unsigned address, bool withAux) const
{
    Q_ASSERT(address < 0x10000 * 8);
    if (address < 0x10000 * 8) {
        QMutexLocker lock(&mutex);
        ProgramDebugInfo* debugInfo;
        if (programBinary && (debugInfo = programBinary->debugInfo()) != nullptr)
            return debugInfo->sourceLocationForAddress(address, withAux);
    }

    return dummySourceLocation;
}

QString EmulatorCore::nameForAddress(unsigned address, bool withAux) const
{
    Q_ASSERT(address < 0x10000 * 8);
    if (address < 0x10000 * 8) {
        QMutexLocker lock(&mutex);
        ProgramDebugInfo* debugInfo;
        if (programBinary && (debugInfo = programBinary->debugInfo()) != nullptr)
            return debugInfo->nameForAddress(address, withAux);
    }

    return QString();
}

std::map<QString, std::vector<ProgramSectionInfo>> EmulatorCore::programSectionInfo() const
{
    std::map<QString, std::vector<ProgramSectionInfo>> result;

    {
        QMutexLocker lock(&mutex);
        if (programBinary) {
            auto saved = programBinary->currentFile();
            try {
                for (const auto& it : programBinary->files()) {
                    programBinary->setCurrentFile(it.first);
                    if (auto debugInfo = programBinary->debugInfo())
                        result[QString::fromUtf8(it.first.c_str())] = debugInfo->sections();
                }
            } catch (...) {
                programBinary->setCurrentFile(saved);
                throw;
            }
            programBinary->setCurrentFile(saved);
        }
    }

    return result;
}

void EmulatorCore::setCollectMemoryOperations(bool flag)
{
    QMutexLocker lock(&mutex);
    collectMemoryOperations = flag;
}

void EmulatorCore::setCollectControlFlow(bool flag)
{
    QMutexLocker lock(&mutex);
    collectControlFlow = flag;
}

Registers EmulatorCore::registers() const
{
    QMutexLocker lock(&mutex);
    return ::registers;
}

quint32 EmulatorCore::instructionPointer() const
{
    QMutexLocker lock(&mutex);
    return ::registers.pc;
}

quint16 EmulatorCore::stackPointer() const
{
    QMutexLocker lock(&mutex);
    return ::registers.sp;
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

Machine EmulatorCore::currentMachine() const
{
    QMutexLocker lock(&mutex);
    return ::currentMachine;
}

QString EmulatorCore::currentMachineName() const
{
    if (!mThread->isRunning())
        return QString();

    return machineName(currentMachine());
}

QString EmulatorCore::currentMachineShortName() const
{
    if (!mThread->isRunning())
        return QString();

    switch (currentMachine()) {
        case Machine::Spectrum16: return QStringLiteral("16K");
        case Machine::Spectrum48: return QStringLiteral("48K");
        case Machine::Spectrum48NTSC: return QStringLiteral("NTSC");
        case Machine::Spectrum128: return QStringLiteral("128");
        case Machine::SpectrumPlus2: return QStringLiteral("+2");
        case Machine::SpectrumPlus2A: return QStringLiteral("+2A");
        case Machine::SpectrumPlus3: return QStringLiteral("+3");
    }

    Q_ASSERT(false);
    return QStringLiteral("???");
}

QString EmulatorCore::machineName(Machine machine)
{
    switch (machine) {
        case Machine::Spectrum16: return QStringLiteral("Spectrum 16K");
        case Machine::Spectrum48: return QStringLiteral("Spectrum 48K");
        case Machine::Spectrum48NTSC: return QStringLiteral("Spectrum 48K NTSC");
        case Machine::Spectrum128: return QStringLiteral("Spectrum 128");
        case Machine::SpectrumPlus2: return QStringLiteral("Spectrum +2");
        case Machine::SpectrumPlus2A: return QStringLiteral("Spectrum +2A");
        case Machine::SpectrumPlus3: return QStringLiteral("Spectrum +3");
    }

    Q_ASSERT(false);
    return tr("Spectrum");
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

void EmulatorCore::getMemory(unsigned address, void* buffer, size_t bufferSize) const
{
    char* ptr = reinterpret_cast<char*>(buffer);
    size_t addr = address;

    QMutexLocker lock(&mutex);
    while (bufferSize > 0) {
        addr &= 0xffff;

        size_t bytes = bufferSize;
        if (addr + bufferSize > 0x10000)
            bytes = 0x10000 - addr;

        memcpy(ptr, memory + addr, bytes);
        bufferSize -= bytes;
        ptr += bytes;
        addr += bytes;
    }
}

void EmulatorCore::setMemory(unsigned address, unsigned value)
{
    auto cmd = [address, value] {
            debugger_poke(address & 0xffff, value & 0xff);
        };

    QMutexLocker lock(&mutex);
    commandQueue.emplace_back(std::move(cmd));
}

QImage EmulatorCore::getScreen() const
{
    QMutexLocker lock(&mutex);
    return screenBack;
}

static const char hex[] = "0123456789ABCDEF";

std::vector<std::string> EmulatorCore::disassemble(unsigned address, size_t count) const
{
    enum { BufSize = 128 };
    size_t len;

    std::vector<std::string> result;
    result.reserve(count);
    for (size_t i = 0; i < count; i++) {
        std::string s(BufSize, '\0');
        s[4] = ' ';
        s[5] = ' ';
        s[6] = ' ';
        result.emplace_back(std::move(s));
    }

    {
        QMutexLocker lock(&mutex);
        for (size_t i = 0; i < count; i++) {
            std::string& s = result[i];
            s[0] = hex[(address >> 12) & 0xf];
            s[1] = hex[(address >>  8) & 0xf];
            s[2] = hex[(address >>  4) & 0xf];
            s[3] = hex[(address      ) & 0xf];

            len = 0;
            debugger_disassemble(&s[7], BufSize - 7, &len, address);
            address = (address + len) & 0xffff;
        }
    }

    return result;
}

static input_key mapKey(int key, bool shift)
{
    switch (key) {
        default: return INPUT_KEY_NONE; break;

        case Qt::Key_Pause: return INPUT_KEY_Break; break;
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

void EmulatorCore::onBreakpointAdded(const BreakpointsModel::Item&)
{
    if (isRunning())
        updateBreakpoints();
}

void EmulatorCore::onBreakpointRemoved(const BreakpointsModel::Item&)
{
    if (isRunning())
        updateBreakpoints();
}

void EmulatorCore::updateBreakpoints()
{
    QMutexLocker lock(&mutex);

    breakpoints.clear();

    ProgramDebugInfo* debugInfo = nullptr;
    if (programBinary)
        debugInfo = programBinary->debugInfo();

    bool notifyBreakpointsUpdated = false;

    const auto& items = BreakpointsModel::instance()->items();
    auto end = items.end();
    for (auto it = items.begin(); it != end; ++it) {
        switch (it->type) {
            case BreakpointType::Code: {
                int addr = (debugInfo ? debugInfo->resolveAddress(it->file, it->line, true) : -1);
                if (addr < 0) {
                    notifyBreakpointsUpdated = true;
                    BreakpointsModel::instance()->setBreakpointInvalid(it, false);
                } else {
                    notifyBreakpointsUpdated = true;
                    BreakpointsModel::instance()->setBreakpointValid(it, false);
                    breakpoints.emplace_back(Breakpoint{
                        DEBUGGER_BREAKPOINT_TYPE_EXECUTE, 0, libspectrum_word(addr), 0 });
                }
                break;
            }

            case BreakpointType::MemoryRead:
                breakpoints.emplace_back(Breakpoint{
                    DEBUGGER_BREAKPOINT_TYPE_READ, 0, libspectrum_word(it->address), 0 });
                break;

            case BreakpointType::MemoryWrite:
                breakpoints.emplace_back(Breakpoint{
                    DEBUGGER_BREAKPOINT_TYPE_WRITE, 0, libspectrum_word(it->address), 0 });
                break;

            default:
                Q_ASSERT(false);
        }
    }

    shouldUpdateBreakpoints = true;

    lock.unlock();

    if (notifyBreakpointsUpdated)
        emit BreakpointsModel::instance()->breakpointsChanged();
}

void EmulatorCore::update()
{
    bool shouldUpdateUi_ = false;
    bool shouldEmitUnpausedSignal_ = false;
    bool shouldEmitPausedSignal_ = false;
    bool memoryWasChanged_ = false;
    unsigned pausePC_ = 0;
    unsigned SP_ = 0;
    unsigned PC_ = 0;
    int runtoAddress_ = -1;

    {
        QMutexLocker lock(&mutex);
        shouldUpdateUi_ = shouldUpdateUi;
        shouldUpdateUi = false;
        shouldEmitUnpausedSignal_ = shouldEmitUnpausedSignal;
        shouldEmitUnpausedSignal = false;
        shouldEmitPausedSignal_ = shouldEmitPausedSignal;
        shouldEmitPausedSignal = false;
        memoryWasChanged_ = memoryWasChanged;
        memoryWasChanged = false;
        pausePC_ = pausePC;
        SP_ = SP;
        PC_ = PC;
        quint32 bank = (quint32)(machine_current->ram.current_page);
        if (bank != 2 && bank != 5 && PC_ >= 0xc000)
            PC_ |= bank << 16;
        runtoAddress_ = runtoAddress;
        std::swap(::memoryOperations, memoryOperations_mainThread);
        std::swap(::controlFlows, controlFlows_mainThread);
    }

    if (memoryWasChanged_)
        emit memoryChanged();
    if (shouldEmitUnpausedSignal_)
        emit leaveDebugger();
    if (shouldEmitPausedSignal_)
        emit enterDebugger(pausePC_);
    if (shouldUpdateUi_)
        emit updateUi();

    if (runtoAddress_ != lastHighlightedRuntoAddress) {
        lastHighlightedRuntoAddress = runtoAddress_;
        emit runtoAddressChanged(runtoAddress_);
    }

    if (!memoryOperations_mainThread.empty()) {
        emit memoryOperations(memoryOperations_mainThread);
        memoryOperations_mainThread.clear();
    }

    if (!controlFlows_mainThread.empty()) {
        emit controlFlow(controlFlows_mainThread);
        controlFlows_mainThread.clear();
    }

    if (prevSP != SP_) {
        prevSP = SP_;
        emit stackChanged();
    }

    if (prevPC != PC_) {
        prevPC = PC_;
        emit instructionPointerChanged();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void getRegisters(Registers& regs)
{
    regs.tstates = tstates;
    regs.af = AF;
    regs.bc = BC;
    regs.de = DE;
    regs.hl = HL;
    regs.ix = IX;
    regs.iy = IY;
    regs.sp = SP;
    regs.pc = PC;
    quint32 bank = (quint32)(machine_current->ram.current_page);
    if (bank != 2 && bank != 5 && regs.pc >= 0xc000)
        regs.pc |= bank << 16;
    regs.af_ = AF_;
    regs.bc_ = BC_;
    regs.de_ = DE_;
    regs.hl_ = HL_;
    regs.a = A;
    regs.b = B;
    regs.c = C;
    regs.d = D;
    regs.e = E;
    regs.h = H;
    regs.l = L;
    regs.f = F;
    regs.i = I;
    regs.r = R;
    regs.a_ = A_;
    regs.b_ = B_;
    regs.c_ = C_;
    regs.d_ = D_;
    regs.e_ = E_;
    regs.h_ = H_;
    regs.l_ = L_;
    regs.f_ = F_;
    regs.im = IM;
    regs.iff1 = IFF1;
    regs.iff2 = IFF2;
    regs.ula = ula_last_byte();
    regs.sf = (regs.f & FLAG_S) != 0;
    regs.zf = (regs.f & FLAG_Z) != 0;
    regs.hf = (regs.f & FLAG_H) != 0;
    regs.pf = (regs.f & FLAG_P) != 0;
    regs.nf = (regs.f & FLAG_N) != 0;
    regs.cf = (regs.f & FLAG_C) != 0;
    regs.halted = z80.halted;
}

static void syncWithMainThread()
{
    if (emulatorPaused != paused) {
        emulatorPaused = paused;
        if (paused)
            fuse_emulation_pause();
        else
            fuse_emulation_unpause();
    }

    QMutexLocker lock(&mutex);

    if (!commandQueue.empty()) {
        std::vector<std::function<void()>> commands{std::move(commandQueue)};
        commandQueue = std::vector<std::function<void()>>();

        lock.unlock();
        for (const auto& cmd : commands)
            cmd();
        lock.relock();
    }

    getRegisters(registers);

    int offset = 0;
    for (int i = 0; i < MEMORY_PAGES_IN_64K; i++) {
        if (!memoryPageValid[i]) {
            memcpy(memory + offset, memory_map_read[i].page, MEMORY_PAGE_SIZE);
            memoryPageValid[i] = true;
            memoryWasChanged = true;
        }
        offset += MEMORY_PAGE_SIZE;
    }

    if (shouldUpdateBreakpoints) {
        shouldUpdateBreakpoints = false;
        debugger_breakpoint_remove_all();
        for (const auto& it : breakpoints) {
            debugger_breakpoint_add_address(it.type, memory_source_any, it.page, it.offset, it.ignore,
                DEBUGGER_BREAKPOINT_LIFE_PERMANENT, nullptr);
        }
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
    emulatorPaused = false;

    while (!isInterruptionRequested()) {
        syncWithMainThread();
        if (paused) // no need to protect it with mutex as it is only set by this thread
            QThread::msleep(10);
        else {
            z80_do_opcodes();
            event_do_events();
        }
    }

    if (paused)
        debugger_run(); // "unpause" the debugger before shutting down

    fuse_end();

    emulatorPaused = false;

    screenFront.fill(Qt::black);
    QMutexLocker locker(&mutex);
    screenBack.fill(Qt::black);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const compat_fd COMPAT_FILE_OPEN_FAILED = NULL;

compat_fd compat_file_open(const char* path, int write)
{
    auto file = std::make_unique<QFile>(QString::fromUtf8(path));
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

extern "C" int settings_command_line(struct settings_info* fuse, int* first_arg, int, char**)
{
    Settings settings;
    fuse->sound = (settings.enableSound() ? 1 : 0);
    fuse->fastload = (settings.fastTapeLoading() ? 1 : 0);
    fuse->accelerate_loader = fuse->fastload;
    fuse->detect_loader = fuse->fastload;
    fuse->sound_load = (settings.playTapeSound() ? 1 : 0);
    fuse->tape_traps = 1;
    fuse->auto_load = 1;

    #define SETSTRING(N, V) if (fuse->N) libspectrum_free(fuse->N); fuse->N = utils_safe_strdup(V)

    if (!tapeFile.isEmpty())
        SETSTRING(tape_file, tapeFile.toUtf8().constData());

    Machine machine = settings.emulatorMachine();
    switch (machine) {
        case Machine::Spectrum16: SETSTRING(start_machine, "16"); break;
        case Machine::Spectrum48: SETSTRING(start_machine, "48"); break;
        case Machine::Spectrum48NTSC: SETSTRING(start_machine, "48_ntsc"); break;
        case Machine::Spectrum128: SETSTRING(start_machine, "128"); break;
        case Machine::SpectrumPlus2: SETSTRING(start_machine, "plus2"); break;
        case Machine::SpectrumPlus2A: SETSTRING(start_machine, "plus2a"); break;
        case Machine::SpectrumPlus3: SETSTRING(start_machine, "plus3"); break;
        default: Q_ASSERT(false);
    }

    {
        QMutexLocker lock(&mutex);
        currentMachine = machine;
        shouldUpdateUi = true;
    }

    *first_arg = 1;
    return 0;
}

int ui_debugger_activate()
{
    {
        QMutexLocker lock(&mutex);

        /*
        ProgramDebugInfo* debugInfo;
        if (programBinary && (debugInfo = programBinary->debugInfo()) != nullptr) {
            const auto& loc = debugInfo->sourceLocationForAddress(PC);
            if (loc.file.isEmpty())
                return 0;
        }
        */

        if (!paused) {
            paused = true;
            shouldEmitPausedSignal = true;
            shouldUpdateUi = true;
            pausePC = PC;

            quint32 page = (quint32)(machine_current->ram.current_page);
            if (page != 2 && page != 5 && pausePC >= 0xc000)
                pausePC |= page << 16;
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
        shouldEmitUnpausedSignal = true;
        shouldUpdateUi = true;
    }
    return 0;
}

extern "C" void ui_notify_memory_page_changed(int page)
{
    QMutexLocker lock(&mutex);
    memoryPageValid[page] = false;
}

extern "C" void ui_notify_memory_write(int bank, unsigned memoryAddress, unsigned codeAddress, unsigned value)
{
    Q_ASSERT(memoryAddress < 0x10000);
    if (!writeAllowed[memoryAddress]) {
        if (debugger_mode == DEBUGGER_MODE_RUN_TO_ADDRESS) {
            QMutexLocker lock(&mutex);
            runtoAddress = -1;
        }
        debugger_mode = DEBUGGER_MODE_HALTED;
    }

    if (collectMemoryOperations) {
        MemoryOperationInfo info;
        info.operation = MemoryOperation::WriteByte;
        info.bank = bank;
        info.memoryAddress = memoryAddress;
        info.codeAddress = codeAddress;
        info.value = value;

        QMutexLocker lock(&mutex);
        memoryOperations.emplace_back(std::move(info));
    }
}

extern "C" void ui_notify_control_flow(int bank, unsigned address)
{
    unsigned addr = address;
    if (bank != 2 && bank != 5 && addr >= 0xc000)
        addr |= bank << 16;

    {
        QMutexLocker lock(&mutex);
        auto it = writeProtection.find(addr);
        if (it != writeProtection.end()) {
            for (const auto& jt : it->second) {
                unsigned start = jt.startAddress;
                unsigned size = jt.size;
                switch (jt.what) {
                    case ProgramWriteProtection::What::AllowWrite:
                    case ProgramWriteProtection::What::DisallowWrite:
                        for (unsigned i = 0; i < size; i++) {
                            unsigned addr1 = start + i;
                            Q_ASSERT(addr1 < 0x10000);
                            if (addr1 >= 0x10000) {
                                static volatile unsigned value;
                                value = addr1;
                                abort();
                            } else
                                writeAllowed[addr1] = (jt.what == ProgramWriteProtection::What::AllowWrite);
                        }
                        break;

                    case ProgramWriteProtection::What::PushAllowWrite:
                    case ProgramWriteProtection::What::PushDisallowWrite: {
                        AllowStack s;
                        s.start = start;
                        s.size = size;
                        s.values.resize(size);
                        uint8_t* p = &s.values[0];
                        for (unsigned i = 0; i < size; i++) {
                            unsigned addr1 = start + i;
                            Q_ASSERT(addr1 < 0x10000);
                            if (addr1 >= 0x10000) {
                                static volatile unsigned value;
                                value = addr1;
                                abort();
                            } else {
                                *p++ = writeAllowed[addr1] ? 1 : 0;
                                writeAllowed[addr1] = (jt.what == ProgramWriteProtection::What::PushAllowWrite);
                            }
                        }
                        s.values.resize(p - &s.values[0]);
                        writeAllowStack.emplace_back(std::move(s));
                        break;
                    }

                    case ProgramWriteProtection::What::PopAllowWriteEarly:
                        Q_ASSERT(!writeAllowStack.empty());
                        if (!writeAllowStack.empty()) {
                            AllowStack s = std::move(writeAllowStack.back());
                            writeAllowStack.pop_back();
                            Q_ASSERT(s.start == start);
                            Q_ASSERT(s.size == size);
                            if (s.start != start) {
                                static volatile unsigned value1, value2;
                                value1 = s.start;
                                value2 = start;
                                abort();
                            }
                            if (s.size != size) {
                                static volatile unsigned value1, value2;
                                value1 = s.size;
                                value2 = size;
                                abort();
                            }
                            const uint8_t* p = &s.values[0];
                            for (unsigned i = 0; i < s.size; i++) {
                                unsigned addr1 = s.start + i;
                                Q_ASSERT(addr1 < 0x10000);
                                if (addr1 >= 0x10000) {
                                    static volatile unsigned value;
                                    value = addr1;
                                    abort();
                                } else
                                    writeAllowed[addr1] = *p++ != 0;
                            }
                        }
                        break;

                    case ProgramWriteProtection::What::AssertBank:
                        if (bank != start) {
                            if (debugger_mode == DEBUGGER_MODE_RUN_TO_ADDRESS) {
                                QMutexLocker lock(&mutex);
                                runtoAddress = -1;
                            }
                            debugger_mode = DEBUGGER_MODE_HALTED;
                        }
                        break;

                    case ProgramWriteProtection::What::PopAllowWrite:
                        break;
                }
            }
        }
    }

    if (collectControlFlow) {
        ControlFlowInfo info;
        info.bank = bank;
        info.codeAddress = address;
        info.regs.sp = SP;
        info.regs.af = AF;
        info.regs.bc = BC;
        info.regs.de = DE;
        info.regs.hl = HL;
        info.regs.ix = IX;
        info.regs.iy = IY;
        size_t len = 0;
        debugger_disassemble(info.instruction, sizeof(info.instruction), &len, info.codeAddress);

        QMutexLocker lock(&mutex);
        controlFlows.emplace_back(std::move(info));
    }
}

extern "C" void ui_notify_control_flow_after(int bank, unsigned address)
{
    unsigned addr = address;
    if (bank != 2 && bank != 5 && addr >= 0xc000)
        addr |= bank << 16;

    {
        QMutexLocker lock(&mutex);
        auto it = writeProtection.find(addr);
        if (it != writeProtection.end()) {
            for (const auto& jt : it->second) {
                unsigned start = jt.startAddress;
                unsigned size = jt.size;
                switch (jt.what) {
                    case ProgramWriteProtection::What::AllowWrite:
                    case ProgramWriteProtection::What::DisallowWrite:
                    case ProgramWriteProtection::What::PushAllowWrite:
                    case ProgramWriteProtection::What::PushDisallowWrite:
                    case ProgramWriteProtection::What::PopAllowWriteEarly:
                        break;

                    case ProgramWriteProtection::What::PopAllowWrite:
                        Q_ASSERT(!writeAllowStack.empty());
                        if (writeAllowStack.empty())
                            abort();
                        else {
                            AllowStack s = std::move(writeAllowStack.back());
                            writeAllowStack.pop_back();
                            Q_ASSERT(s.start == start);
                            Q_ASSERT(s.size == size);
                            if (s.start != start) {
                                static volatile unsigned value1, value2;
                                value1 = s.start;
                                value2 = start;
                                abort();
                            }
                            if (s.size != size) {
                                static volatile unsigned value1, value2;
                                value1 = s.size;
                                value2 = size;
                                abort();
                            }
                            const uint8_t* p = &s.values[0];
                            for (unsigned i = 0; i < s.size; i++) {
                                unsigned addr1 = s.start + i;
                                Q_ASSERT(addr1 < 0x10000);
                                if (addr1 >= 0x10000) {
                                    static volatile unsigned value;
                                    value = addr1;
                                    abort();
                                } else
                                    writeAllowed[addr1] = *p++ != 0;
                            }
                        }
                        break;
                }
            }
        }
    }
}

int uidisplay_init(int width, int height)
{
    screenFront = QImage(EmulatorCore::ScreenWidth, EmulatorCore::ScreenHeight, QImage::Format_ARGB32);
    return 0;
}

static void setPixel(uchar* line, int x, int color)
{
    if (x < 0 || x >= EmulatorCore::ScreenWidth)
        return;

    const Color* c = &ZXPalette[color];
    uchar* dst = &line[x * 4];
    *dst++ = c->b;
    *dst++ = c->g;
    *dst++ = c->r;
    *dst++ = 0xff;
}

void uidisplay_plot16(int x, int y, libspectrum_word data, libspectrum_byte ink, libspectrum_byte paper)
{
    x <<= 4;
    y <<= 1;
    for (int i = 0; i < 2; i++, y++) {
        if (y < 0 || y >= EmulatorCore::ScreenHeight)
            break;

        uchar* line = screenFront.scanLine(y);
        setPixel(line, x +  0, (data & 0x8000 ? ink : paper));
        setPixel(line, x +  1, (data & 0x4000 ? ink : paper));
        setPixel(line, x +  2, (data & 0x2000 ? ink : paper));
        setPixel(line, x +  3, (data & 0x1000 ? ink : paper));
        setPixel(line, x +  4, (data & 0x0800 ? ink : paper));
        setPixel(line, x +  5, (data & 0x0400 ? ink : paper));
        setPixel(line, x +  6, (data & 0x0200 ? ink : paper));
        setPixel(line, x +  7, (data & 0x0100 ? ink : paper));
        setPixel(line, x +  8, (data & 0x0080 ? ink : paper));
        setPixel(line, x +  9, (data & 0x0040 ? ink : paper));
        setPixel(line, x + 10, (data & 0x0020 ? ink : paper));
        setPixel(line, x + 11, (data & 0x0010 ? ink : paper));
        setPixel(line, x + 12, (data & 0x0008 ? ink : paper));
        setPixel(line, x + 13, (data & 0x0004 ? ink : paper));
        setPixel(line, x + 14, (data & 0x0002 ? ink : paper));
        setPixel(line, x + 15, (data & 0x0001 ? ink : paper));
    }
}

void uidisplay_plot8(int x, int y, libspectrum_byte data, libspectrum_byte ink, libspectrum_byte paper)
{
    x <<= 3;

    if (!machine_current->timex) {
        if (y < 0 || y >= EmulatorCore::ScreenHeight)
            return;

        uchar* line = screenFront.scanLine(y);
        setPixel(line, x + 0, (data & 0x80 ? ink : paper));
        setPixel(line, x + 1, (data & 0x40 ? ink : paper));
        setPixel(line, x + 2, (data & 0x20 ? ink : paper));
        setPixel(line, x + 3, (data & 0x10 ? ink : paper));
        setPixel(line, x + 4, (data & 0x08 ? ink : paper));
        setPixel(line, x + 5, (data & 0x04 ? ink : paper));
        setPixel(line, x + 6, (data & 0x02 ? ink : paper));
        setPixel(line, x + 7, (data & 0x01 ? ink : paper));
    } else {
        x <<= 1;
        y <<= 1;
        for (int i = 0; i < 2; i++, y++) {
            if (y < 0 || y >= EmulatorCore::ScreenHeight)
                break;

            uchar* line = screenFront.scanLine(y);
            setPixel(line, x +  0, (data & 0x80 ? ink : paper));
            setPixel(line, x +  1, (data & 0x80 ? ink : paper));
            setPixel(line, x +  2, (data & 0x40 ? ink : paper));
            setPixel(line, x +  3, (data & 0x40 ? ink : paper));
            setPixel(line, x +  4, (data & 0x20 ? ink : paper));
            setPixel(line, x +  5, (data & 0x20 ? ink : paper));
            setPixel(line, x +  6, (data & 0x10 ? ink : paper));
            setPixel(line, x +  7, (data & 0x10 ? ink : paper));
            setPixel(line, x +  8, (data & 0x08 ? ink : paper));
            setPixel(line, x +  9, (data & 0x08 ? ink : paper));
            setPixel(line, x + 10, (data & 0x04 ? ink : paper));
            setPixel(line, x + 11, (data & 0x04 ? ink : paper));
            setPixel(line, x + 12, (data & 0x02 ? ink : paper));
            setPixel(line, x + 13, (data & 0x02 ? ink : paper));
            setPixel(line, x + 14, (data & 0x01 ? ink : paper));
            setPixel(line, x + 15, (data & 0x01 ? ink : paper));
        }
    }
}

void uidisplay_putpixel(int x, int y, int colour)
{
    if (!machine_current->timex) {
        if (y < 0 || y >= EmulatorCore::ScreenHeight)
            return;

        setPixel(screenFront.scanLine(y), x, colour);
    } else {
        x <<= 1;
        y <<= 1;
        if (y < 0 || y >= EmulatorCore::ScreenHeight)
            return;

        uchar* line1 = screenFront.scanLine(y + 0);
        uchar* line2 = screenFront.scanLine(y + 1);
        setPixel(line1, x + 0, colour);
        setPixel(line1, x + 1, colour);
        setPixel(line2, x + 0, colour);
        setPixel(line2, x + 1, colour);
    }
}

void uidisplay_frame_end()
{
    QImage copy = screenFront.copy();

    QMutexLocker lock(&mutex);
    screenBack = copy;
}

int ui_error_specific(ui_error_level severity, const char* message)
{
    switch (severity) {
        case UI_ERROR_INFO:
        default:
            qDebug("%s", message);
            break;

        case UI_ERROR_WARNING:
            qWarning("%s", message);
            break;

        case UI_ERROR_ERROR:
            qCritical("%s", message);
            emit EmulatorCore::instance()->internal_sendError(QString::fromUtf8(message));
            break;
    }

    return 0;
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

extern "C" void ui_runto_address_activated(unsigned addr)
{
    QMutexLocker lock(&mutex);
    runtoAddress = int(addr);
}

extern "C" void ui_runto_address_reached()
{
    QMutexLocker lock(&mutex);
    runtoAddress = -1;
}
