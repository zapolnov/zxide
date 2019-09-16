#include "BreakpointsWindow.h"
#include "debugger/BreakpointsModel.h"
#include "debugger/EmulatorCore.h"
#include "ui_BreakpointsWindow.h"
#include <QMenu>
#include <QAction>

BreakpointsWindow::BreakpointsWindow(QWidget* parent)
    : QWidget(parent, Qt::Window)
    , mUi(new Ui_BreakpointsWindow)
    , mDeleteIcon(QStringLiteral(":/resources/fatcow16x16/bin_closed.png"))
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

void BreakpointsWindow::on_tableView_customContextMenuRequested(const QPoint& pos)
{
    auto indexUnderMouse = mUi->tableView->indexAt(pos);
    mUi->tableView->setCurrentIndex(indexUnderMouse);
    if (!indexUnderMouse.isValid())
        return;

    QMenu menu;

    QAction* action = menu.addAction(mDeleteIcon, tr("Delete"));
    connect(action, &QAction::triggered, this, [indexUnderMouse] {
            BreakpointsModel::instance()->removeRow(indexUnderMouse.row());
        });

    menu.exec(mUi->tableView->viewport()->mapToGlobal(pos));
}
