#ifndef DEBUGGER_BREAKPOINTSWINDOW_H
#define DEBUGGER_BREAKPOINTSWINDOW_H

#include <QWidget>
#include <memory>
#include <vector>

class Ui_BreakpointsWindow;
class BreakpointsModel;

class BreakpointsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BreakpointsWindow(QWidget* parent = nullptr);
    ~BreakpointsWindow() override;

    void setModel(BreakpointsModel* model);

signals:
    void fileDoubleClicked(const QString& file, int line);

private:
    std::unique_ptr<Ui_BreakpointsWindow> mUi;

    Q_SLOT void on_tableView_doubleClicked(const QModelIndex& index);

    Q_DISABLE_COPY(BreakpointsWindow)
};

#endif
