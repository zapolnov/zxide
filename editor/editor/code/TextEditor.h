#ifndef EDITOR_CODE_TEXTEDITOR_H
#define EDITOR_CODE_TEXTEDITOR_H

#include "ScintillaEdit/ScintillaEdit.h"
#include <map>

struct TStates;

class TextEditor : public ScintillaEdit
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget* parent = nullptr);
    ~TextEditor() override;

    void setLineIndent(int line, int indent);

    void setHighlight(int line);
    void clearHighlight();

    void updateTStates(const std::map<int, TStates>& tstates);
    void clearTStates();

    void reloadSettings();

private:
    sptr_t mHighlightHandle;
    bool mHighlightVisible;
    bool mTStatesVisible;
    bool mAutoIndent;

    void charAdded(int ch) override;
    void textModified(int position, int length) override;

    Q_DISABLE_COPY(TextEditor)
};

#endif
