#include "TextEditor.h"
#include "Settings.h"
#include <QSettings>

TextEditor::TextEditor(QWidget* parent)
    : ScintillaEdit(parent)
{
    reloadSettings();
}

TextEditor::~TextEditor()
{
}

void TextEditor::reloadSettings()
{
    setCodePage(SC_CP_UTF8);
    setEndAtLastLine(true);
    setEOLMode(SC_EOL_LF);
    setIndent(0); // 0 = the same as tab size
    setScrollWidth(10);
    setScrollWidthTracking(true);
    setTabDrawMode(SCTD_LONGARROW);
    setUndoCollection(true);
    setWrapMode(SC_WRAP_NONE);

    QSettings settings;
    setBackSpaceUnIndents(settings.value(SettingBackspaceUnindents, true).toBool());
    setTabIndents(settings.value(SettingTabIndents, false).toBool());
    setTabWidth(settings.value(SettingTabWidth, 4).toInt());
    setUseTabs(settings.value(SettingUseTabs, false).toBool());
    setViewEOL(settings.value(SettingShowEndOfLine, false).toBool());
    setViewWS(settings.value(SettingShowWhitespace, SCWS_VISIBLEALWAYS).toInt());
}
