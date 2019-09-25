#ifndef DEBUGGER_WATCHMODEL_H
#define DEBUGGER_WATCHMODEL_H

#include <QAbstractTableModel>
#include <vector>

enum class WatchType
{
    SignedByte,
    UnsignedByte,
    SignedWord,
    UnsignedWord,
    SignedDWord,
    UnsignedDWord,
};

class WatchModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    struct Item
    {
        QString expression;
        WatchType type;
    };

    explicit WatchModel(QObject* parent);
    ~WatchModel();

    static WatchModel* instance() { return mInstance; }

    const std::vector<Item>& items() const { return mItems; }
    const Item* itemAtRow(int row) const;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

private:
    static WatchModel* mInstance;
    std::vector<Item> mItems;

    Q_DISABLE_COPY(WatchModel)
};

#endif
