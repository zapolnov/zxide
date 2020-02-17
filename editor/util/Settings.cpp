#include "Settings.h"
#include "ScintillaEdit/ScintillaEdit.h"
#include "debugger/EmulatorCore.h"

static const QString SettingLoadLastProject = QStringLiteral("LoadLastProject");
static const QString SettingLastProjectFile = QStringLiteral("LastProjectFile");
static const QString SettingLastImportedPNG = QStringLiteral("LastImportedPNG");
static const QString SettingLastImportedSCR = QStringLiteral("LastImportedSCR");
static const QString SettingAutoIndent = QStringLiteral("AutoIndent");
static const QString SettingTabIndents = QStringLiteral("TabIndents");
static const QString SettingBackspaceUnindents = QStringLiteral("BackspaceUnindents");
static const QString SettingShowEndOfLine = QStringLiteral("ShowEndOfLine");
static const QString SettingShowWhitespace = QStringLiteral("ShowWhitespace");
static const QString SettingShowLineNumbers = QStringLiteral("ShowLineNumbers");
static const QString SettingTabWidth = QStringLiteral("TabWidth");
static const QString SettingUseTabs = QStringLiteral("UseTabs");
static const QString SettingAutoSaveBeforeCompile = QStringLiteral("AutoSaveBeforeCompile");
static const QString SettingEnableSound = QStringLiteral("EnableSound");
static const QString SettingFastTapeLoading = QStringLiteral("FastTapeLoading");
static const QString SettingPlayTapeSound = QStringLiteral("PlayTapeSound");
static const QString SettingEmulatorMachine = QStringLiteral("EmulatorMachine");

static const QString MachineSpectrum16 = QStringLiteral("Spectrum16");
static const QString MachineSpectrum48 = QStringLiteral("Spectrum48");
static const QString MachineSpectrum48NTSC = QStringLiteral("Spectrum48NTSC");
static const QString MachineSpectrum128 = QStringLiteral("Spectrum128");
static const QString MachineSpectrumPlus2 = QStringLiteral("SpectrumPlus2");
static const QString MachineSpectrumPlus2A = QStringLiteral("SpectrumPlus2A");
static const QString MachineSpectrumPlus3 = QStringLiteral("SpectrumPlus3");

Settings::Settings()
{
}

Settings::~Settings()
{
}

QString Settings::lastProjectFile() const
{
    return mSettings.value(SettingLastProjectFile).toString();
}

QString Settings::lastImportedPNG() const
{
    return mSettings.value(SettingLastImportedPNG).toString();
}

QString Settings::lastImportedSCR() const
{
    return mSettings.value(SettingLastImportedSCR).toString();
}

bool Settings::loadLastProjectOnStart() const
{
    return mSettings.value(SettingLoadLastProject, true).toBool();
}

bool Settings::autoIndent() const
{
    return mSettings.value(SettingAutoIndent, true).toBool();
}

bool Settings::tabIndents() const
{
    return mSettings.value(SettingTabIndents, true).toBool();
}

bool Settings::backspaceUnindents() const
{
    return mSettings.value(SettingBackspaceUnindents, true).toBool();
}

bool Settings::useTabs() const
{
    return mSettings.value(SettingUseTabs, false).toBool();
}

int Settings::tabWidth() const
{
    return mSettings.value(SettingTabWidth, 4).toInt();
}

int Settings::whitespaceVisibility() const
{
    return mSettings.value(SettingShowWhitespace, SCWS_VISIBLEALWAYS).toInt();
}

bool Settings::showEol() const
{
    return mSettings.value(SettingShowEndOfLine, false).toBool();
}

bool Settings::showLineNumbers() const
{
    return mSettings.value(SettingShowLineNumbers, true).toBool();
}

bool Settings::autoSaveBeforeCompile() const
{
    return mSettings.value(SettingAutoSaveBeforeCompile, false).toBool();
}

bool Settings::enableSound() const
{
    return mSettings.value(SettingEnableSound, true).toBool();
}

bool Settings::fastTapeLoading() const
{
    return mSettings.value(SettingFastTapeLoading, true).toBool();
}

bool Settings::playTapeSound() const
{
    return mSettings.value(SettingPlayTapeSound, false).toBool();
}

Machine Settings::emulatorMachine() const
{
    QString str = mSettings.value(SettingEmulatorMachine, MachineSpectrum48).toString();
    if (str == MachineSpectrum16) return Machine::Spectrum16;
    else if (str == MachineSpectrum48) return Machine::Spectrum48;
    else if (str == MachineSpectrum48NTSC) return Machine::Spectrum48NTSC;
    else if (str == MachineSpectrum128) return Machine::Spectrum128;
    else if (str == MachineSpectrumPlus2) return Machine::SpectrumPlus2;
    else if (str == MachineSpectrumPlus2A) return Machine::SpectrumPlus2A;
    else if (str == MachineSpectrumPlus3) return Machine::SpectrumPlus3;
    else {
        qDebug("Unknown machine '%s'", qPrintable(str));
        return Machine::Spectrum48;
    }
}

void Settings::setLastProjectFile(const QString& file)
{
    mSettings.setValue(SettingLastProjectFile, file);
}

void Settings::setLastImportedPNG(const QString& file)
{
    mSettings.setValue(SettingLastImportedPNG, file);
}

void Settings::setLastImportedSCR(const QString& file)
{
    mSettings.setValue(SettingLastImportedSCR, file);
}

void Settings::setLoadLastProjectOnStart(bool flag)
{
    mSettings.setValue(SettingLoadLastProject, flag);
}

void Settings::setAutoIndent(bool flag)
{
    mSettings.setValue(SettingAutoIndent, flag);
}

void Settings::setTabIndents(bool flag)
{
    mSettings.setValue(SettingTabIndents, flag);
}

void Settings::setBackspaceUnindents(bool flag)
{
    mSettings.setValue(SettingBackspaceUnindents, flag);
}

void Settings::setUseTabs(bool flag)
{
    mSettings.setValue(SettingUseTabs, flag);
}

void Settings::setTabWidth(int value)
{
    mSettings.setValue(SettingTabWidth, value);
}

void Settings::setWhitespaceVisibility(int value)
{
    mSettings.setValue(SettingShowWhitespace, value);
}

void Settings::setShowEol(bool flag)
{
    mSettings.setValue(SettingShowEndOfLine, flag);
}

void Settings::setShowLineNumbers(bool flag)
{
    mSettings.setValue(SettingShowLineNumbers, flag);
}

void Settings::setAutoSaveBeforeCompile(bool flag)
{
    mSettings.setValue(SettingAutoSaveBeforeCompile, flag);
}

void Settings::setEnableSound(bool flag)
{
    mSettings.setValue(SettingEnableSound, flag);
}

void Settings::setFastTapeLoading(bool flag)
{
    mSettings.setValue(SettingFastTapeLoading, flag);
}

void Settings::setPlayTapeSound(bool flag)
{
    mSettings.setValue(SettingPlayTapeSound, flag);
}

void Settings::setEmulatorMachine(Machine machine)
{
    switch (machine) {
        case Machine::Spectrum16: mSettings.setValue(SettingEmulatorMachine, MachineSpectrum16); return;
        case Machine::Spectrum48: mSettings.setValue(SettingEmulatorMachine, MachineSpectrum48); return;
        case Machine::Spectrum48NTSC: mSettings.setValue(SettingEmulatorMachine, MachineSpectrum48NTSC); return;
        case Machine::Spectrum128: mSettings.setValue(SettingEmulatorMachine, MachineSpectrum128); return;
        case Machine::SpectrumPlus2: mSettings.setValue(SettingEmulatorMachine, MachineSpectrumPlus2); return;
        case Machine::SpectrumPlus2A: mSettings.setValue(SettingEmulatorMachine, MachineSpectrumPlus2A); return;
        case Machine::SpectrumPlus3: mSettings.setValue(SettingEmulatorMachine, MachineSpectrumPlus3); return;
    }

    Q_ASSERT(false);
}
