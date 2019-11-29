#include "ControlFlowLogWindow.h"
#include "debugger/EmulatorCore.h"
#include "ui_ControlFlowLogWindow.h"
#include <algorithm>
#include <QAbstractTableModel>
#include <QMenu>
#include <QAction>
#include <QThread>
#include <QMutex>

static const int MaxEntries = 104857600;

// FIXME !!!
extern QMutex cfLock;
extern std::vector<std::function<void(FILE*)>> cfProducer;
extern std::vector<std::function<void(FILE*)>> cfConsumer;

class Thread : public QThread
{
public:
    void run() override
    {
        FILE* f = fopen("D:/Work/zxrpg_3/log.txt", "wb");
        while (!isInterruptionRequested()) {
            {
                QMutexLocker lock(&cfLock);
                auto v = std::move(cfProducer);
                cfProducer = std::move(cfConsumer);
                cfConsumer = std::move(v);
            }

            for (const auto& it : cfConsumer)
                it(f);

            cfConsumer.clear();
        }
        fclose(f);
    }
};

static Thread xthread;

class ControlFlowLogWindow::Model : public QAbstractTableModel
{
public:
    explicit Model(QObject* parent)
        : QAbstractTableModel(parent)
    {
        if (!xthread.isRunning())
            xthread.start();
    }

    ~Model()
    {
        xthread.requestInterruption();
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
        if (operations.empty())
            return;

        /* FIXME
        size_t newSize = mControlFlow.size() + operations.size() - 1;
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
        mControlFlow.insert(mControlFlow.end(), operations.begin(), operations.end());
        emit endInsertRows();
        */
    }

    int getCodeAddress(int row) const
    {
        if (row < 0 || row >= count())
            return -1;
        return int(mControlFlow[size_t(row)].codeAddress);
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
        return 3;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
    {
        if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
            return QAbstractTableModel::headerData(section, orientation, role);

        switch (section) {
            case 0: return tr("Bank");
            case 1: return tr("Code address");
            case 2: return tr("Instruction");
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
                QString name = EmulatorCore::instance()->nameForAddress(op.codeAddress);
                if (name.isEmpty())
                    return QStringLiteral("0x%1").arg(op.codeAddress, 4, 16, QChar('0'));
                else
                    return QStringLiteral("0x%1 (%2)").arg(op.codeAddress, 4, 16, QChar('0')).arg(name);
            }

            case 2:
                return QString::fromLatin1(op.instruction);

            default:
                return QVariant();
        }
    }

private:
    std::vector<ControlFlowInfo> mControlFlow;

    Q_DISABLE_COPY(Model)
};

ControlFlowLogWindow::ControlFlowLogWindow(QWidget* parent)
    : QWidget(parent, Qt::Window)
    , mUi(new Ui_ControlFlowLogWindow)
{
    mUi->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    mModel = new ControlFlowLogWindow::Model(this);
    mUi->tableView->setModel(mModel);

    //qRegisterMetaType<std::vector<MemoryOperationInfo>>();
    //qRegisterMetaType<std::vector<ControlFlowInfo>>();

    // FIXME
    //connect(EmulatorCore::instance(), &EmulatorCore::controlFlow, mModel, &ControlFlowLogWindow::Model::addOperations);
    //connect(EmulatorCore::instance(), &EmulatorCore::controlFlow, writer, &ControlFlowWriter::addOperations, Qt::QueuedConnection);
    EmulatorCore::instance()->setCollectControlFlow(true);
    //connect(EmulatorCore::instance(), &EmulatorCore::memoryOperations, mModel, &ControlFlowLogWindow::Model::addMemOperations);
    //connect(EmulatorCore::instance(), &EmulatorCore::memoryOperations, writer, &ControlFlowWriter::addMemOperations, Qt::QueuedConnection);
    EmulatorCore::instance()->setCollectMemoryOperations(true);
}

ControlFlowLogWindow::~ControlFlowLogWindow()
{
    EmulatorCore::instance()->setCollectControlFlow(false);
    EmulatorCore::instance()->setCollectMemoryOperations(false);
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
