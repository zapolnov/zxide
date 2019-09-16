#ifndef DEBUGGER_MEMORYMAPDIALOG_H
#define DEBUGGER_MEMORYMAPDIALOG_H

#include <QDialog>
#include <memory>

class Ui_MemoryMapDialog;

class MemoryMapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryMapDialog(QWidget* parent = nullptr);
    ~MemoryMapDialog() override;

private:
    std::unique_ptr<Ui_MemoryMapDialog> mUi;

    Q_DISABLE_COPY(MemoryMapDialog)
};

#endif
