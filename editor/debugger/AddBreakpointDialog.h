#ifndef DEBUGGER_ADDBREAKPOINTDIALOG_H
#define DEBUGGER_ADDBREAKPOINTDIALOG_H

#include <QDialog>
#include <memory>
#include "debugger/BreakpointsModel.h"

class Ui_AddBreakpointDialog;

class AddBreakpointDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBreakpointDialog(QWidget* parent = nullptr);
    ~AddBreakpointDialog() override;

    unsigned address() const;
    BreakpointType breakpointType() const;

protected:
    void done(int r) override;

private:
    std::unique_ptr<Ui_AddBreakpointDialog> mUi;
    bool mHexadecimal;

    void updateUi();

    Q_SLOT void on_decimalRadio_toggled(bool flag);
    Q_SLOT void on_hexadecimalRadio_toggled(bool flag);

    Q_DISABLE_COPY(AddBreakpointDialog)
};

#endif
