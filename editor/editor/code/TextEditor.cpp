#include "TextEditor.h"
#include "editor/AbstractEditorTab.h"
#include "compiler/ProgramDebugInfo.h"
#include "util/Settings.h"
#include <cstdio>

TextEditor::TextEditor(QWidget* parent)
    : ScintillaEdit(parent)
    , mTStatesVisible(false)
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

void TextEditor::setHighlight(Highlight highlight, int line)
{
    auto& marker = mMarkers[highlight];
    if (marker.visible) {
        markerDeleteHandle(marker.handle);
        marker.visible = false;
    }

    int index = 24 - int(highlight);

    switch (highlight) {
        case Highlight::CurrentPC:
            markerDefine(index, SC_MARK_SHORTARROW);
            markerSetFore(index, 0);
            markerSetBack(index, 0x00ffff);
            break;
        case Highlight::Error:
            markerDefine(index, SC_MARK_EXCLAMATION);
            markerSetFore(index, 0);
            markerSetBack(index, 0x0000ff);
            break;
        case Highlight::MemoryLog:
            markerDefine(index, SC_MARK_VERTICALBOOKMARK);
            markerSetFore(index, 0);
            markerSetBack(index, 0xffff00);
            break;
    }

    marker.handle = markerAdd(line, index);
    marker.line = line;
    marker.visible = true;
}

void TextEditor::clearHighlight(Highlight highlight)
{
    auto& marker = mMarkers[highlight];
    if (marker.visible) {
        markerDeleteHandle(marker.handle);
        marker.visible = false;
    }
}

void TextEditor::updateTStates(const std::map<int, TStates>& tstates)
{
    if (!mTStatesVisible) {
        mTStatesVisible = true;
        reloadSettings();
    }

    marginTextClearAll();
    for (const auto& it : tstates) {
        char buf[64];
        if (it.second.taken == it.second.notTaken)
            snprintf(buf, sizeof(buf), "%u", it.second.taken);
        else
            snprintf(buf, sizeof(buf), "%u/%u", it.second.taken, it.second.notTaken);
        marginSetText(it.first - 1, buf);
    }
}

void TextEditor::clearTStates()
{
    if (mTStatesVisible) {
        mTStatesVisible = false;
        marginTextClearAll();
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

    setMarginMaskN(1, SC_MASK_FOLDERS | (1 << 24) | (1 << 23) | (1 << 22));
    setMarginTypeN(3, SC_MARGIN_RTEXT);
    setMarginWidthN(3, mTStatesVisible ? textWidth(STYLE_LINENUMBER, "_9/99") : 0);

    if (!settings.showLineNumbers()) {
        setMarginWidthN(2, 0);
        setMarginMaskN(3, 0);
    } else {
        setMarginTypeN(2, SC_MARGIN_NUMBER);
        setMarginWidthN(2, textWidth(STYLE_LINENUMBER, "_99999"));
        setMarginMaskN(2, 0);
        setMarginMaskN(3, SC_MASK_FOLDERS);
    }
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

void TextEditor::textModified(int position, int length)
{
    auto& errorMarker = mMarkers[Highlight::Error];
    auto& memoryLogMarker = mMarkers[Highlight::MemoryLog];

    for (int i = position; i < position + length; i++) {
        int line = lineFromPosition(i);

        if (errorMarker.line == line && errorMarker.visible)
            clearHighlight(Highlight::Error);
        if (memoryLogMarker.line == line && memoryLogMarker.visible)
            clearHighlight(Highlight::MemoryLog);

        if (mTStatesVisible)
            marginSetText(line, "");
    }
}
