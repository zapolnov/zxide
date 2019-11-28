#ifndef DEBUGGER_CONTROLFLOWLOGWINDOW_H
#define DEBUGGER_CONTROLFLOWLOGWINDOW_H

#include <QWidget>
#include <memory>
#include <vector>

class Ui_ControlFlowLogWindow;
struct ControlFlowInfo;

class ControlFlowLogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ControlFlowLogWindow(QWidget* parent = nullptr);
    ~ControlFlowLogWindow() override;

signals:
    void cleared();
    void addressDoubleClicked(unsigned address);

private:
    class Model;

    std::unique_ptr<Ui_ControlFlowLogWindow> mUi;
    Model* mModel;

    Q_SLOT void on_clearButton_clicked();
    Q_SLOT void on_tableView_doubleClicked(const QModelIndex& index);

    Q_DISABLE_COPY(ControlFlowLogWindow)
};

#endif
