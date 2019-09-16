#include "TextEditor.h"
#include "editor/AbstractEditorTab.h"
#include "editor/HighlightManager.h"
#include "debugger/BreakpointsModel.h"
#include "compiler/ProgramDebugInfo.h"
#include "util/Settings.h"
#include <unordered_set>
#include <cstdio>

TextEditor::TextEditor(QWidget* parent)
    : ScintillaEdit(parent)
    , mTStatesVisible(false)
{
    reloadSettings();
    connect(HighlightManager::instance(), &HighlightManager::highlightsChanged, this, &TextEditor::updateHighlights);
    connect(BreakpointsModel::instance(), &BreakpointsModel::breakpointsChanged, this, &TextEditor::updateHighlights);
}

TextEditor::~TextEditor()
{
}

void TextEditor::setFileName(const QString& fileName)
{
    if (mFileName != fileName)
        mFileName = fileName;
    updateHighlights();
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

void TextEditor::updateHighlights()
{
    while (!mBreakpointMarkers.empty()) {
        markerDeleteHandle(mBreakpointMarkers.back().handle);
        mBreakpointMarkers.pop_back();
    }

    int index = 0;
    for (const auto& it : BreakpointsModel::instance()->items()) {
        if (it.type == BreakpointType::Code && it.file == mFileName) {
            markerDefine(index, SC_MARK_CIRCLE);
            markerSetFore(index, 0);
            markerSetBack(index, (it.valid == BreakpointValidity::Invalid ? 0xc0c0c0 : 0x0000ff));
            auto handle = markerAdd(it.line - 1, index++);
            mBreakpointMarkers.emplace_back(BreakpointMarker{ handle, it.line - 1 });
        }
    }

    for (auto highlight : { Highlight::CurrentPC, Highlight::Error, Highlight::RunToCursor, Highlight::MemoryLog }) {
        auto& marker = mMarkers[highlight];
        if (marker.visible) {
            markerDeleteHandle(marker.handle);
            marker.visible = false;
        }

        auto info = HighlightManager::instance()->highlight(highlight);
        if (!info || info->file != mFileName)
            continue;

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
            case Highlight::RunToCursor:
                markerDefine(index, SC_MARK_SHORTARROW);
                markerSetFore(index, 0);
                markerSetBack(index, 0xff80ff);
                break;
            case Highlight::MemoryLog:
                markerDefine(index, SC_MARK_VERTICALBOOKMARK);
                markerSetFore(index, 0);
                markerSetBack(index, 0xffff00);
                break;
        }

        marker.handle = markerAdd(info->line - 1, index);
        marker.line = info->line - 1;
        marker.visible = true;
    }
}

void TextEditor::clearHighlight(Highlight highlight)
{
    auto& marker = mMarkers[highlight];
    if (marker.visible) {
        markerDeleteHandle(marker.handle);
        marker.visible = false;
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

    setMarginMaskN(1, SC_MASK_FOLDERS | 0x1ffffff);
    setMarginSensitiveN(1, true);

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

void TextEditor::marginClicked(int position, int modifiers, int margin)
{
    int line = lineFromPosition(position);
    emit marginClicked(line);
}

void TextEditor::textModified(int position, int length)
{
    bool highlightChanged = false;
    std::unordered_set<int> lines;

    for (int i = position; i <= position + length; i++) {
        int line = lineFromPosition(i);
        if (!lines.emplace(line).second)
            continue;

        // Clear markers at this line
        for (const auto& it : mMarkers) {
            if (it.second.line == line && it.second.visible) {
                HighlightManager::instance()->clearHighlight(it.first, false);
                highlightChanged = true;
            }
        }

        // Clear t-states counter at this line
        if (mTStatesVisible)
            marginSetText(line, "");
    }

    if (highlightChanged)
        emit HighlightManager::instance()->highlightsChanged();
    else
        updateHighlights();
}
