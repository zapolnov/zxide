#include "Settings.h"
#include "ScintillaEdit/ScintillaEdit.h"

static const QString SettingLoadLastProject = QStringLiteral("LoadLastProject");
static const QString SettingLastProjectFile = QStringLiteral("LastProjectFile");
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

void Settings::setLastProjectFile(const QString& file)
{
    mSettings.setValue(SettingLastProjectFile, file);
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
