#ifndef CODE_TEXTEDITOR_H
#define CODE_TEXTEDITOR_H

#include "ScintillaEdit/ScintillaEdit.h"

class TextEditor : public ScintillaEdit
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget* parent = nullptr);
    ~TextEditor() override;

    void reloadSettings();

private:
    Q_DISABLE_COPY(TextEditor)
};

#endif
