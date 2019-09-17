#ifndef DEBUGGER_EMULATORCORE_H
#define DEBUGGER_EMULATORCORE_H

#include <QObject>
#include <QThread>
#include "debugger/BreakpointsModel.h"
#include <map>
#include <vector>

enum Register
{
    Reg_None,
    Reg_AF,
    Reg_BC,
    Reg_DE,
    Reg_HL,
    Reg_IX,
    Reg_IY,
    Reg_SP,
    Reg_PC,
    Reg_AF_,
    Reg_BC_,
    Reg_DE_,
    Reg_HL_,
    Reg_A,
    Reg_B,
    Reg_C,
    Reg_D,
    Reg_E,
    Reg_H,
    Reg_L,
    Reg_F,
    Reg_I,
    Reg_R,
    Reg_A_,
    Reg_B_,
    Reg_C_,
    Reg_D_,
    Reg_E_,
    Reg_H_,
    Reg_L_,
    Reg_F_,
};

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

enum class MemoryOperation
{
    WriteByte,
};

struct MemoryOperationInfo
{
    MemoryOperation operation;
    int bank;
    unsigned memoryAddress;
    unsigned codeAddress;
    unsigned value;
};

enum class Machine : int
{
    Spectrum16,
    Spectrum48,
    Spectrum48NTSC,
    Spectrum128,
    SpectrumPlus2,
    SpectrumPlus2A,
    SpectrumPlus3,
};

class File;
class ProgramBinary;
class QTimer;
struct ProgramSectionInfo;
struct SourceLocation;

class EmulatorCore : public QObject
{
    Q_OBJECT

public:
    static const int ScreenWidth;
    static const int ScreenHeight;

    explicit EmulatorCore(QObject* parent = nullptr);
    ~EmulatorCore() override;

    static EmulatorCore* instance() { return mInstance; }

    bool start();
    void stop();
    bool isRunning() const;

    void pause();
    void stepInto();
    void stepOut();
    void stepOver();
    void runTo(const File* file, int line);
    void unpause();
    bool isPaused() const;

    void setTapeFile(const QString& file) { mTapeFile = file; }

    bool hasProgramBinary() const;
    void setProgramBinary(std::unique_ptr<ProgramBinary> binary);
    SourceLocation sourceLocationForAddress(unsigned address) const;
    QString nameForAddress(unsigned address) const;
    std::map<QString, std::vector<ProgramSectionInfo>> programSectionInfo() const;

    void setCollectMemoryOperations(bool flag);

    Registers registers() const;
    quint16 instructionPointer() const;
    quint16 stackPointer() const;
    void setRegister(Register reg, quint16 value);

    Machine currentMachine() const;
    QString currentMachineName() const;
    QString currentMachineShortName() const;
    static QString machineName(Machine machine);

    int currentSpeed() const;
    QString currentSpeedString() const;

    void getMemory(unsigned address, void* buffer, size_t bufferSize) const;
    QImage getScreen() const;

    void pressKey(int key);
    void releaseKey(int key);

signals:
    void started();
    void enterDebugger(unsigned pc);
    void leaveDebugger();
    void stopped();
    void memoryChanged();
    void memoryOperations(std::vector<MemoryOperationInfo>& operations);
    void stackChanged();
    void error(QString message);
    void updateUi();
    void runtoAddressChanged(int address);

    void internal_sendError(QString message);

private:
    class Thread : public QThread
    {
    public:
        explicit Thread(QObject* parent = nullptr);
        void run() override;
        Q_DISABLE_COPY(Thread)
    };

    static EmulatorCore* mInstance;
    QString mTapeFile;
    QTimer* mTimer;
    Thread* mThread;
    bool mShiftPressed;

    void onBreakpointAdded(const BreakpointsModel::Item& breakpoint);
    void onBreakpointRemoved(const BreakpointsModel::Item& breakpoint);
    void updateBreakpoints();

    void update();

    Q_DISABLE_COPY(EmulatorCore)
};

#endif
