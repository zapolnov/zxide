#include "Settings.h"
#include "ScintillaEdit/ScintillaEdit.h"

static const QString SettingAutoIndent = QStringLiteral("SettingAutoIndent");
static const QString SettingBackspaceUnindents = QStringLiteral("SettingBackspaceUnindents");
static const QString SettingShowEndOfLine = QStringLiteral("ShowEndOfLine");
static const QString SettingShowWhitespace = QStringLiteral("ShowWhitespace");
static const QString SettingTabIndents = QStringLiteral("TabIndents");
static const QString SettingTabWidth = QStringLiteral("TabWidth");
static const QString SettingUseTabs = QStringLiteral("UseTabs");
static const QString SettingEnableSound = QStringLiteral("EnableSound");

Settings::Settings()
{
}

Settings::~Settings()
{
}

bool Settings::autoIndent() const
{
    return mSettings.value(SettingAutoIndent, true).toBool();
}

bool Settings::tabIndents() const
{
    return mSettings.value(SettingTabIndents, false).toBool();
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

bool Settings::enableSound() const
{
    return mSettings.value(SettingEnableSound, true).toBool();
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

void Settings::setEnableSound(bool flag)
{
    mSettings.setValue(SettingEnableSound, flag);
}
