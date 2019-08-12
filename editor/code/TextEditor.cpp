#include "TextEditor.h"
#include "Settings.h"

TextEditor::TextEditor(QWidget* parent)
    : ScintillaEdit(parent)
{
    reloadSettings();
}

TextEditor::~TextEditor()
{
}

void TextEditor::setLineIndent(int line, int indent)
{
    long selStart = selectionStart();
    long selEnd = selectionEnd();

    long oldPos = lineIndentPosition(line);
    setLineIndentation(line, indent);
    long newPos = lineIndentPosition(line);

    if (newPos > oldPos) {
        if (selStart >= oldPos)
            setSelectionStart(selStart + newPos - oldPos);
        if (selEnd >= oldPos)
            setSelectionEnd(selEnd + newPos - oldPos);
    } else if (newPos < oldPos) {
        if (selStart >= newPos)
            setSelectionStart(selStart < oldPos ? newPos : selStart + newPos - oldPos);
        if (selEnd >= newPos)
            setSelectionStart(selEnd < oldPos ? newPos : selEnd + newPos - oldPos);
    }
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
    setCaretStyle(CARETSTYLE_LINE | CARETSTYLE_OVERSTRIKE_BLOCK);

    Settings settings;
    mAutoIndent = settings.autoIndent();
    setTabIndents(settings.tabIndents());
    setBackSpaceUnIndents(settings.backspaceUnindents());
    setUseTabs(settings.useTabs());
    setTabWidth(settings.tabWidth());
    setViewWS(settings.whitespaceVisibility());
    setViewEOL(settings.showEol());
}

void TextEditor::charAdded(int ch)
{
    if ((ch == '\r' || ch == '\n') && mAutoIndent) {
        int curLine = lineFromPosition(currentPos());
        if (curLine > 0 && positionFromLine(curLine) == selectionStart())
            setLineIndent(curLine, lineIndentation(curLine - 1));
    }

    ScintillaEdit::charAdded(ch);
}
