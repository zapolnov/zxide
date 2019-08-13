#ifndef DEBUGGER_REGISTERSWIDGET_H
#define DEBUGGER_REGISTERSWIDGET_H

#include <QWidget>
#include <memory>

class Ui_RegistersWidget;

class RegistersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegistersWidget(QWidget* parent = nullptr);
    ~RegistersWidget() override;

    void refresh();
    void reset();

private:
    std::unique_ptr<Ui_RegistersWidget> mUi;

    Q_DISABLE_COPY(RegistersWidget)
};

#endif
