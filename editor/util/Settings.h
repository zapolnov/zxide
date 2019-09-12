#ifndef UTIL_SETTINGS_H
#define UTIL_SETTINGS_H

#include <QSettings>

enum class Machine : int;

class Settings
{
public:
    Settings();
    ~Settings();

    QString lastProjectFile() const;
    bool loadLastProjectOnStart() const;
    bool autoIndent() const;
    bool tabIndents() const;
    bool backspaceUnindents() const;
    bool useTabs() const;
    int tabWidth() const;
    int whitespaceVisibility() const;
    bool showEol() const;
    bool showLineNumbers() const;
    bool autoSaveBeforeCompile() const;
    bool enableSound() const;
    bool fastTapeLoading() const;
    bool playTapeSound() const;
    Machine emulatorMachine() const;

    void setLastProjectFile(const QString& file);
    void setLoadLastProjectOnStart(bool flag);
    void setAutoIndent(bool flag);
    void setTabIndents(bool flag);
    void setBackspaceUnindents(bool flag);
    void setUseTabs(bool flag);
    void setTabWidth(int value);
    void setWhitespaceVisibility(int value);
    void setShowEol(bool flag);
    void setShowLineNumbers(bool flag);
    void setAutoSaveBeforeCompile(bool flag);
    void setEnableSound(bool flag);
    void setFastTapeLoading(bool flag);
    void setPlayTapeSound(bool flag);
    void setEmulatorMachine(Machine machine);

private:
    QSettings mSettings;

    Q_DISABLE_COPY(Settings)
};

#endif
