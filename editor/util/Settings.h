#ifndef UTIL_SETTINGS_H
#define UTIL_SETTINGS_H

#include <QSettings>

class Settings
{
public:
    Settings();
    ~Settings();

    bool autoIndent() const;
    bool tabIndents() const;
    bool backspaceUnindents() const;
    bool useTabs() const;
    int tabWidth() const;
    int whitespaceVisibility() const;
    bool showEol() const;
    bool autoSaveBeforeCompile() const;
    bool enableSound() const;

    void setAutoIndent(bool flag);
    void setTabIndents(bool flag);
    void setBackspaceUnindents(bool flag);
    void setUseTabs(bool flag);
    void setTabWidth(int value);
    void setWhitespaceVisibility(int value);
    void setShowEol(bool flag);
    void setAutoSaveBeforeCompile(bool flag);
    void setEnableSound(bool flag);

private:
    QSettings mSettings;

    Q_DISABLE_COPY(Settings)
};

#endif
