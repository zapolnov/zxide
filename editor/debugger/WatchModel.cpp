#include "WatchModel.h"

WatchModel* WatchModel::mInstance;

WatchModel::WatchModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;
}

WatchModel::~WatchModel()
{
    Q_ASSERT(mInstance == this);
    mInstance = nullptr;
}

const WatchModel::Item* WatchModel::itemAtRow(int row) const
{
    if (row < 0 || row >= int(mItems.size()))
        return nullptr;
    return &mItems[size_t(row)];
}

int WatchModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;
    return int(mItems.size());
}

int WatchModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;
    return 4;
}

QVariant WatchModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return QAbstractTableModel::headerData(section, orientation, role);

    switch (section) {
        case 0: return tr("Expression");
        case 1: return tr("Type");
        case 2: return tr("Address");
        case 3: return tr("Value");
        default: return QVariant();
    }
}

QVariant WatchModel::data(const QModelIndex& index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    int row = index.row();
    if (row < 0 || row >= int(mItems.size()))
        return QVariant();

    const auto& item = mItems[size_t(row)];

    switch (index.column()) {
        case 0:
            return item.expression;

        case 1:
            switch (item.type) {
                case WatchType::SignedByte: return tr("Byte (signed)");
                case WatchType::UnsignedByte: return tr("Byte (unsigned)");
                case WatchType::SignedWord: return tr("Word (signed)");
                case WatchType::UnsignedWord: return tr("Word (unsigned)");
                case WatchType::SignedDWord: return tr("DWord (signed)");
                case WatchType::UnsignedDWord: return tr("DWord (unsigned)");
                default: return tr("Other");
            }
            break;

        case 2:
            // FIXME

        case 3:
            // FIXME

        default:
            return QVariant();
    }
}

bool WatchModel::removeRows(int row, int count, const QModelIndex& parent)
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
    }

    endRemoveRows();

    return true;
}
