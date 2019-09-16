#ifndef DEBUGGER_BREAKPOINTSMODEL_H
#define DEBUGGER_BREAKPOINTSMODEL_H

#include <QAbstractTableModel>
#include <vector>

enum class BreakpointType
{
    Code,
};

class BreakpointsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum { MaxBreakpoints = 20 };

    struct Item
    {
        BreakpointType type;
        QString file;
        int line;
    };

    explicit BreakpointsModel(QObject* parent);
    ~BreakpointsModel();

    static BreakpointsModel* instance() { return mInstance; }

    const std::vector<Item>& items() const { return mItems; }
    const Item* itemAtRow(int row) const;

    void toggleCodeBreakpoint(QWidget* widget, const QString& file, int line);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

signals:
    void breakpointAdded(const Item& breakpoint);
    void breakpointRemoved(const Item& breakpoint);
    void breakpointsChanged();

private:
    static BreakpointsModel* mInstance;
    std::vector<Item> mItems;

    Q_DISABLE_COPY(BreakpointsModel)
};

#endif
