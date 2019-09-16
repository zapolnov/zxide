#ifndef DEBUGGER_BREAKPOINTSMODEL_H
#define DEBUGGER_BREAKPOINTSMODEL_H

#include <QAbstractTableModel>
#include <vector>

enum class BreakpointType
{
    Code,
};

enum class BreakpointValidity
{
    Unknown,
    Valid,
    Invalid,
};

class BreakpointsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum { MaxBreakpoints = 20 };

    struct Item
    {
        BreakpointType type;
        BreakpointValidity valid;
        QString file;
        int line;
    };

    explicit BreakpointsModel(QObject* parent);
    ~BreakpointsModel();

    static BreakpointsModel* instance() { return mInstance; }

    const std::vector<Item>& items() const { return mItems; }
    const Item* itemAtRow(int row) const;

    void addCodeBreakpoint(QWidget* widget, const QString& file, int line, bool notify = true);
    bool removeCodeBreakpoint(const QString& file, int line, bool notify = true);
    void toggleCodeBreakpoint(QWidget* widget, const QString& file, int line);

    void setBreakpointValid(std::vector<Item>::const_iterator& it, bool notify = true);
    void setBreakpointInvalid(std::vector<Item>::const_iterator& it, bool notify = true);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

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
