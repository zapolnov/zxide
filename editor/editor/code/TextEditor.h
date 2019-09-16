#ifndef EDITOR_CODE_TEXTEDITOR_H
#define EDITOR_CODE_TEXTEDITOR_H

#include "ScintillaEdit/ScintillaEdit.h"
#include <map>
#include <unordered_map>

struct TStates;
enum class Highlight : int;

class TextEditor : public ScintillaEdit
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget* parent = nullptr);
    ~TextEditor() override;

    void setFileName(const QString& fileName);

    void setLineIndent(int line, int indent);

    void updateTStates(const std::map<int, TStates>& tstates);
    void clearTStates();

    void reloadSettings();

signals:
    void marginClicked(int line);

private:
    struct Marker
    {
        sptr_t handle = 0;
        int line = -1;
        bool visible = false;
    };

    struct BreakpointMarker
    {
        sptr_t handle = 0;
        int line = -1;
    };

    std::unordered_map<Highlight, Marker> mMarkers;
    std::vector<BreakpointMarker> mBreakpointMarkers;
    QString mFileName;
    bool mTStatesVisible;
    bool mAutoIndent;

    void updateHighlights();
    void clearHighlight(Highlight highlight);

    void charAdded(int ch) override;
    void marginClicked(int position, int modifiers, int margin) override;
    void textModified(int position, int length) override;

    Q_DISABLE_COPY(TextEditor)
};

#endif
