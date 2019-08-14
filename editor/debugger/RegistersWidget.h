#ifndef DEBUGGER_REGISTERSWIDGET_H
#define DEBUGGER_REGISTERSWIDGET_H

#include "EmulatorCore.h"
#include "util/SimpleTextWidget.h"
#include <memory>

class RegistersWidget : public SimpleTextWidget
{
    Q_OBJECT

public:
    explicit RegistersWidget(QWidget* parent = nullptr);
    ~RegistersWidget() override;

    void refresh();
    void reset();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Registers mRegisters;

    Q_DISABLE_COPY(RegistersWidget)
};

#endif
