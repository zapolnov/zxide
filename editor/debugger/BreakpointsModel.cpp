#include "BreakpointsModel.h"
#include <QMessageBox>

BreakpointsModel* BreakpointsModel::mInstance;

BreakpointsModel::BreakpointsModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;
}

BreakpointsModel::~BreakpointsModel()
{
    Q_ASSERT(mInstance == this);
    mInstance = nullptr;
}

const BreakpointsModel::Item* BreakpointsModel::itemAtRow(int row) const
{
    if (row < 0 || row >= int(mItems.size()))
        return nullptr;
    return &mItems[size_t(row)];
}

void BreakpointsModel::addCodeBreakpoint(QWidget* widget, const QString& file, int line, bool notify)
{
    if (mItems.size() >= MaxBreakpoints) {
        QMessageBox::critical(widget, tr("Error"), tr("Too many breakpoints."));
        return;
    }

    Item item;
    item.type = BreakpointType::Code;
    item.valid = BreakpointValidity::Unknown;
    item.file = file;
    item.line = line;
    item.address = unsigned(-1);

    int n = int(mItems.size());
    beginInsertRows(QModelIndex(), n, n);
    mItems.emplace_back(item);
    emit breakpointAdded(item);
    endInsertRows();

    if (notify)
        emit breakpointsChanged();
}

bool BreakpointsModel::removeCodeBreakpoint(const QString& file, int line, bool notify)
{
    auto start = mItems.begin();
    auto end = mItems.end();
    for (auto it = start; it != end; ++it) {
        if (it->file == file && it->line == line) {
            int n = int(it - start);
            Item item = *it;

            beginRemoveRows(QModelIndex(), n, n);
            mItems.erase(it);
            emit breakpointRemoved(item);
            endRemoveRows();

            if (notify)
                emit breakpointsChanged();

            return true;
        }
    }

    return false;
}

void BreakpointsModel::toggleCodeBreakpoint(QWidget* widget, const QString& file, int line)
{
    if (removeCodeBreakpoint(file, line, true))
        return;

    addCodeBreakpoint(widget, file, line, true);
}

void BreakpointsModel::addMemoryReadBreakpoint(QWidget* widget, unsigned address, bool notify)
{
    if (mItems.size() >= MaxBreakpoints) {
        QMessageBox::critical(widget, tr("Error"), tr("Too many breakpoints."));
        return;
    }

    Item item;
    item.type = BreakpointType::MemoryRead;
    item.valid = BreakpointValidity::Valid;
    item.file = QString();
    item.line = -1;
    item.address = address;

    int n = int(mItems.size());
    beginInsertRows(QModelIndex(), n, n);
    mItems.emplace_back(item);
    emit breakpointAdded(item);
    endInsertRows();

    if (notify)
        emit breakpointsChanged();
}

void BreakpointsModel::addMemoryWriteBreakpoint(QWidget* widget, unsigned address, bool notify)
{
    if (mItems.size() >= MaxBreakpoints) {
        QMessageBox::critical(widget, tr("Error"), tr("Too many breakpoints."));
        return;
    }

    Item item;
    item.type = BreakpointType::MemoryWrite;
    item.valid = BreakpointValidity::Valid;
    item.file = QString();
    item.line = -1;
    item.address = address;

    int n = int(mItems.size());
    beginInsertRows(QModelIndex(), n, n);
    mItems.emplace_back(item);
    emit breakpointAdded(item);
    endInsertRows();

    if (notify)
        emit breakpointsChanged();
}

void BreakpointsModel::setBreakpointValid(std::vector<Item>::const_iterator& it, bool notify)
{
    int row = int(it - mItems.begin());
    Q_ASSERT(row >= 0 && row < int(mItems.size()));

    auto& item = mItems[size_t(row)];
    if (item.valid != BreakpointValidity::Valid) {
        item.valid = BreakpointValidity::Valid;

        auto idx = index(row, 1);
        emit dataChanged(idx, idx);

        if (notify)
            emit breakpointsChanged();
    }
}

void BreakpointsModel::setBreakpointInvalid(std::vector<Item>::const_iterator& it, bool notify)
{
    int row = int(it - mItems.begin());
    Q_ASSERT(row >= 0 && row < int(mItems.size()));

    auto& item = mItems[size_t(row)];
    if (item.valid != BreakpointValidity::Invalid) {
        item.valid = BreakpointValidity::Invalid;

        auto idx = index(row, 1);
        emit dataChanged(idx, idx);

        if (notify)
            emit breakpointsChanged();
    }
}

int BreakpointsModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;
    return int(mItems.size());
}

int BreakpointsModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;
    return 3;
}

QVariant BreakpointsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QAbstractTableModel::headerData(section, orientation, role);

    switch (section) {
        case 0: return tr("Type");
        case 1: return tr("Valid");
        case 2: return tr("Condition");
        default: return QVariant();
    }
}

QVariant BreakpointsModel::data(const QModelIndex& index, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    int row = index.row();
    if (row < 0 || row >= int(mItems.size()))
        return QVariant();

    const auto& item = mItems[size_t(row)];

    switch (index.column()) {
        case 0:
            switch (item.type) {
                case BreakpointType::Code: return tr("Code");
                case BreakpointType::MemoryRead: return tr("Memory Read");
                case BreakpointType::MemoryWrite: return tr("Memory Write");
                default: return tr("Other");
            }
            break;

        case 1:
            switch (item.valid) {
                case BreakpointValidity::Unknown: return tr("Unknown");
                case BreakpointValidity::Valid: return tr("Valid");
                case BreakpointValidity::Invalid: return tr("Invalid");
                default: return tr("Other");
            }
            break;

        case 2:
            switch (item.type) {
                case BreakpointType::Code:
                    return QStringLiteral("%1:%2").arg(item.file).arg(item.line);
                case BreakpointType::MemoryRead:
                case BreakpointType::MemoryWrite:
                    return QStringLiteral("%1 / 0x%2").arg(item.address).arg(item.address, 4, 16, QChar('0'));
                default:
                    return QVariant();
            }
            break;

        default:
            return QVariant();
    }
}

bool BreakpointsModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if (parent.isValid())
        return false;

    if (row < 0 || count < 1 || row + count > int(mItems.size()))
        return false;

    beginRemoveRows(QModelIndex(), row, row + count - 1);

    while (count-- > 0) {
        auto it = mItems.begin() + row + count;
        Item item = *it;
        mItems.erase(it);
        emit breakpointRemoved(item);
    }

    endRemoveRows();
    emit breakpointsChanged();

    return true;
}
