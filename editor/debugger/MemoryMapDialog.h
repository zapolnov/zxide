#ifndef DEBUGGER_MEMORYMAPDIALOG_H
#define DEBUGGER_MEMORYMAPDIALOG_H

#include <QDialog>
#include <memory>

class QTreeWidgetItem;
class Ui_MemoryMapDialog;

class MemoryMapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryMapDialog(QWidget* parent = nullptr);
    ~MemoryMapDialog() override;

signals:
    void addressClicked(unsigned address);

private:
    std::unique_ptr<Ui_MemoryMapDialog> mUi;

    Q_SLOT void on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column);

    Q_DISABLE_COPY(MemoryMapDialog)
};

#endif
