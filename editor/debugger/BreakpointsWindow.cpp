#include "BreakpointsWindow.h"
#include "debugger/EmulatorCore.h"
#include "ui_BreakpointsWindow.h"
#include <QMenu>
#include <QAction>

BreakpointsWindow::BreakpointsWindow(QWidget* parent)
    : QWidget(parent, Qt::Window)
    , mUi(new Ui_BreakpointsWindow)
{
    mUi->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

BreakpointsWindow::~BreakpointsWindow()
{
}

void BreakpointsWindow::setModel(BreakpointsModel* model)
{
    // FIXME
    //mUi->tableView->setModel(model);
}

void BreakpointsWindow::on_tableView_doubleClicked(const QModelIndex& index)
{
    /* FIXME
    int address = mModel->getCodeAddress(index.row());
    if (address >= 0)
        emit addressDoubleClicked(unsigned(address));
    */
}
