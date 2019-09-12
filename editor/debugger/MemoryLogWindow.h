#ifndef DEBUGGER_MEMORYLOGWINDOW_H
#define DEBUGGER_MEMORYLOGWINDOW_H

#include <QWidget>
#include <memory>
#include <vector>

class Ui_MemoryLogWindow;
struct MemoryOperationInfo;

class MemoryLogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryLogWindow(QWidget* parent = nullptr);
    ~MemoryLogWindow() override;

signals:
    void cleared();
    void addressDoubleClicked(unsigned address);

private:
    class Model;

    std::unique_ptr<Ui_MemoryLogWindow> mUi;
    Model* mModel;

    Q_SLOT void on_clearButton_clicked();
    Q_SLOT void on_filtersButton_clicked();
    Q_SLOT void on_tableView_doubleClicked(const QModelIndex& index);

    Q_DISABLE_COPY(MemoryLogWindow)
};

#endif
