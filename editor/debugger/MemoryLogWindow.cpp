#include "MemoryLogWindow.h"
#include "debugger/EmulatorCore.h"
#include "ui_MemoryLogWindow.h"
#include <algorithm>
#include <QAbstractTableModel>
#include <QMenu>
#include <QAction>

enum {
    ExcludeWritesToRomArea = 0x0001,
    ExcludeOperationsByRomCode = 0x0002,
    ExcludeWritesToScreenPixels = 0x0004,
    ExcludeWritesToScreenAttributes = 0x0008,
};

static const int MaxEntries = 104857600;
static int filters = 0;

class MemoryLogWindow::Model : public QAbstractTableModel
{
public:
    explicit Model(QObject* parent)
        : QAbstractTableModel(parent)
    {
    }

    int count() const
    {
        return int(std::min<size_t>(mOperations.size(), size_t(MaxEntries)));
    }

    void clear()
    {
        int n = count();
        emit beginRemoveRows(QModelIndex(), 0, n - 1);
        mOperations.clear();
        emit endRemoveRows();
    }

    void addOperations(std::vector<MemoryOperationInfo>& operations)
    {
        if (filters != 0) {
            size_t i = 0;
            for (auto it = operations.begin(); it != operations.end(); ++it) {
                if (it->memoryAddress < 0x4000 && (filters & ExcludeWritesToRomArea) != 0)
                    continue;
                if (it->codeAddress < 0x4000 && (filters & ExcludeOperationsByRomCode) != 0)
                    continue;
                if (it->memoryAddress >= 0x4000 && it->memoryAddress < 0x5800 && (filters & ExcludeWritesToScreenPixels) != 0)
                    continue;
                if (it->memoryAddress >= 0x5800 && it->memoryAddress < 0x5B00 && (filters & ExcludeWritesToScreenAttributes) != 0)
                    continue;
                operations[i++] = *it;
            }
            operations.resize(i);
        }

        if (operations.empty())
            return;

        size_t newSize = mOperations.size() + operations.size() - 1;
        if (newSize > size_t(MaxEntries))
            return;

        int first = count();
        int last = int(std::min<size_t>(newSize, size_t(MaxEntries)));
        if (last < first)
            return;

        emit beginInsertRows(QModelIndex(), first, last);
        mOperations.insert(mOperations.end(), operations.begin(), operations.end());
        emit endInsertRows();
    }

    int getCodeAddress(int row) const
    {
        if (row < 0 || row >= count())
            return -1;
        return int(mOperations[size_t(row)].codeAddress);
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
        return 4;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
    {
        if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
            return QAbstractTableModel::headerData(section, orientation, role);

        switch (section) {
            case 0: return tr("Operation");
            case 1: return tr("Address");
            case 2: return tr("Value");
            case 3: return tr("Code address");
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

        const auto& op = mOperations[size_t(row)];

        switch (index.column()) {
            case 0:
                switch (op.operation) {
                    case MemoryOperation::WriteByte: return tr("Write byte");
                    default: return tr("Other");
                }
                break;

            case 1: return QStringLiteral("0x%1").arg(op.memoryAddress, 4, 16, QChar('0'));
            case 2: return QStringLiteral("0x%1").arg(op.value, 2, 16, QChar('0'));
            case 3: return QStringLiteral("0x%1").arg(op.codeAddress, 4, 16, QChar('0'));

            default:
                return QVariant();
        }
    }

private:
    std::vector<MemoryOperationInfo> mOperations;

    Q_DISABLE_COPY(Model)
};

MemoryLogWindow::MemoryLogWindow(QWidget* parent)
    : QWidget(parent, Qt::Window)
    , mUi(new Ui_MemoryLogWindow)
{
    mUi->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    mModel = new Model(this);
    mUi->tableView->setModel(mModel);

    connect(EmulatorCore::instance(), &EmulatorCore::memoryOperations, mModel, &MemoryLogWindow::Model::addOperations);
    EmulatorCore::instance()->setCollectMemoryOperations(true);
}

MemoryLogWindow::~MemoryLogWindow()
{
    EmulatorCore::instance()->setCollectMemoryOperations(false);
}

void MemoryLogWindow::on_clearButton_clicked()
{
    mModel->clear();
    emit cleared();
}

void MemoryLogWindow::on_filtersButton_clicked()
{
    QAction* action;
    QMenu menu;

    action = new QAction(tr("Exclude writes to ROM area"), this);
    action->setCheckable(true);
    action->setChecked((filters & ExcludeWritesToRomArea) != 0);
    connect(action, &QAction::triggered, this, []{ filters ^= ExcludeWritesToRomArea; });
    menu.addAction(action);

    action = new QAction(tr("Exclude operations made by ROM code"), this);
    action->setCheckable(true);
    action->setChecked((filters & ExcludeOperationsByRomCode) != 0);
    connect(action, &QAction::triggered, this, []{ filters ^= ExcludeOperationsByRomCode; });
    menu.addAction(action);

    menu.addSeparator();

    action = new QAction(tr("Exclude writes to screen memory (pixel data)"), this);
    action->setCheckable(true);
    action->setChecked((filters & ExcludeWritesToScreenPixels) != 0);
    connect(action, &QAction::triggered, this, []{ filters ^= ExcludeWritesToScreenPixels; });
    menu.addAction(action);

    action = new QAction(tr("Exclude writes to screen memory (color data)"), this);
    action->setCheckable(true);
    action->setChecked((filters & ExcludeWritesToScreenAttributes) != 0);
    connect(action, &QAction::triggered, this, []{ filters ^= ExcludeWritesToScreenAttributes; });
    menu.addAction(action);

    QPoint p = mapToGlobal(mUi->filtersButton->geometry().center());
    menu.exec(p);
}

void MemoryLogWindow::on_tableView_doubleClicked(const QModelIndex& index)
{
    int address = mModel->getCodeAddress(index.row());
    if (address >= 0)
        emit addressDoubleClicked(unsigned(address));
}
