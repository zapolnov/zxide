#include "ControlFlowLogWindow.h"
#include "debugger/EmulatorCore.h"
#include "ui_ControlFlowLogWindow.h"
#include <algorithm>
#include <QAbstractTableModel>
#include <QMenu>
#include <QAction>

static const int MaxEntries = 104857600;

class ControlFlowLogWindow::Model : public QAbstractTableModel
{
public:
    explicit Model(QObject* parent)
        : QAbstractTableModel(parent)
    {
    }

    int count() const
    {
        return int(std::min<size_t>(mControlFlow.size(), size_t(MaxEntries)));
    }

    void clear()
    {
        int n = count();
        emit beginRemoveRows(QModelIndex(), 0, n - 1);
        mControlFlow.clear();
        emit endRemoveRows();
    }

    void addOperations(std::vector<ControlFlowInfo>& operations)
    {
        if (mReachedROM)
            return;

        size_t n = operations.size();
        if (n == 0)
            return;

        for (size_t i = 0; i < n; i++) {
            if (operations[i].codeAddress < 0x4000) {
                mReachedROM = true;
                n = i + 1;
                break;
            }
        }

        size_t newSize = mControlFlow.size() + n - 1;
        if (newSize > size_t(MaxEntries)) {
            size_t numToRemove = newSize - MaxEntries;
            emit beginRemoveRows(QModelIndex(), 0, (int)numToRemove);
            mControlFlow.erase(mControlFlow.begin(), mControlFlow.begin() + numToRemove);
            emit endRemoveRows();
        }

        int first = count();
        int last = int(std::min<size_t>(newSize, size_t(MaxEntries)));
        if (last < first)
            return;

        emit beginInsertRows(QModelIndex(), first, last);
        mControlFlow.insert(mControlFlow.end(), operations.begin(), operations.begin() + n);
        emit endInsertRows();
    }

    int getCodeAddress(int row) const
    {
        if (row < 0 || row >= count())
            return -1;

        unsigned addr = mControlFlow[size_t(row)].codeAddress;
        int bank = mControlFlow[size_t(row)].bank;
        if (bank != 2 && bank != 5 && addr >= 0xc000)
            addr |= bank << 16;

        return int(addr);
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        if (parent.isValid())
            return 0;
        return count();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override
    {
        if (parent.isValid())
            return 0;
        return 10;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
    {
        if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
            return QAbstractTableModel::headerData(section, orientation, role);

        switch (section) {
            case 0: return tr("Bank");
            case 1: return tr("Code address");
            case 2: return tr("Instruction");
            case 3: return tr("SP");
            case 4: return tr("AF");
            case 5: return tr("BC");
            case 6: return tr("DE");
            case 7: return tr("HL");
            case 8: return tr("IX");
            case 9: return tr("IY");
            default: return QVariant();
        }
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
    {
        if (role != Qt::DisplayRole)
            return QVariant();

        int row = index.row();
        if (row < 0 || row >= count())
            return QVariant();

        const auto& op = mControlFlow[size_t(row)];

        switch (index.column()) {
            case 0:
                return QStringLiteral("%1").arg(op.bank);

            case 1: {
                QString name = EmulatorCore::instance()->nameForAddress(op.codeAddress, true);
                if (name.isEmpty())
                    return QStringLiteral("0x%1").arg(op.codeAddress, 4, 16, QChar('0'));
                else
                    return QStringLiteral("0x%1 (%2)").arg(op.codeAddress, 4, 16, QChar('0')).arg(name);
            }

            case 2:
                return QString::fromLatin1(op.instruction);
            case 3:
                return QString::number(op.regs.sp, 16);
            case 4:
                return QString::number(op.regs.af, 16);
            case 5:
                return QString::number(op.regs.bc, 16);
            case 6:
                return QString::number(op.regs.de, 16);
            case 7:
                return QString::number(op.regs.hl, 16);
            case 8:
                return QString::number(op.regs.ix, 16);
            case 9:
                return QString::number(op.regs.iy, 16);

            default:
                return QVariant();
        }
    }

private:
    std::vector<ControlFlowInfo> mControlFlow;
    bool mReachedROM = false;

    Q_DISABLE_COPY(Model)
};

ControlFlowLogWindow::ControlFlowLogWindow(QWidget* parent)
    : QWidget(parent, Qt::Window)
    , mUi(new Ui_ControlFlowLogWindow)
{
    mUi->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    mModel = new Model(this);
    mUi->tableView->setModel(mModel);

    connect(EmulatorCore::instance(), &EmulatorCore::controlFlow, mModel, &ControlFlowLogWindow::Model::addOperations);
    EmulatorCore::instance()->setCollectControlFlow(true);
}

ControlFlowLogWindow::~ControlFlowLogWindow()
{
    EmulatorCore::instance()->setCollectControlFlow(false);
}

void ControlFlowLogWindow::on_clearButton_clicked()
{
    mModel->clear();
    emit cleared();
}

void ControlFlowLogWindow::on_tableView_doubleClicked(const QModelIndex& index)
{
    int address = mModel->getCodeAddress(index.row());
    if (address >= 0)
        emit addressDoubleClicked(unsigned(address));
}
