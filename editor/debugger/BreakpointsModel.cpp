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

void BreakpointsModel::toggleCodeBreakpoint(QWidget* widget, const QString& file, int line)
{
    auto start = mItems.begin();
    auto end = mItems.end();
    for (auto it = start; it != end; ++it) {
        if (it->file == file && it->line == line) {
            int n = int(it - start);
            beginRemoveRows(QModelIndex(), n, n);
            emit breakpointRemoved(*it);
            mItems.erase(it);
            endRemoveRows();
            emit breakpointsChanged();
            return;
        }
    }

    if (mItems.size() >= MaxBreakpoints) {
        QMessageBox::critical(widget, tr("Error"), tr("Too many breakpoints."));
        return;
    }

    Item item;
    item.type = BreakpointType::Code;
    item.file = file;
    item.line = line;

    int n = int(mItems.size());
    beginInsertRows(QModelIndex(), n, n);
    emit breakpointAdded(item);
    mItems.emplace_back(std::move(item));
    endInsertRows();
	emit breakpointsChanged();
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
    return 2;
}

QVariant BreakpointsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QAbstractTableModel::headerData(section, orientation, role);

    switch (section) {
        case 0: return tr("Type");
        case 1: return tr("Condition");
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
                default: return tr("Other");
            }
            break;

        case 1:
            switch (item.type) {
                case BreakpointType::Code: return QStringLiteral("%1:%2").arg(item.file).arg(item.line);
                default: return QVariant();
            }
            break;

        default:
            return QVariant();
    }
}
