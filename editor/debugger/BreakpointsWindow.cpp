#include "BreakpointsWindow.h"
#include "debugger/BreakpointsModel.h"
#include "debugger/EmulatorCore.h"
#include "ui_BreakpointsWindow.h"
#include <QMenu>
#include <QAction>

BreakpointsWindow::BreakpointsWindow(QWidget* parent)
    : QWidget(parent, Qt::Window)
    , mUi(new Ui_BreakpointsWindow)
{
    mUi->setupUi(this);
    mUi->tableView->setModel(BreakpointsModel::instance());
    setAttribute(Qt::WA_DeleteOnClose);
}

BreakpointsWindow::~BreakpointsWindow()
{
}

void BreakpointsWindow::on_tableView_doubleClicked(const QModelIndex& index)
{
    auto item = BreakpointsModel::instance()->itemAtRow(index.row());
    if (item && item->type == BreakpointType::Code)
        emit fileDoubleClicked(item->file, item->line);
}
