#include "TextEditor.h"
#include "Settings.h"
#include <LineMarker.h>
#include <Indicator.h>
#include <UniqueString.h>
#include <Style.h>
#include <ViewStyle.h>
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
    QSettings settings;
    setViewWS(settings.value(SettingShowWhitespace, Scintilla::wsVisibleAlways).toInt());
    setViewEOL(settings.value(SettingShowEndOfLine, 0).toInt());
    setTabDrawMode(Scintilla::tdLongArrow);
}
