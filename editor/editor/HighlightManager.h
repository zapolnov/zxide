#ifndef EDITOR_HIGHLIGHTMANAGER_H
#define EDITOR_HIGHLIGHTMANAGER_H

#include <QObject>
#include <unordered_map>

enum class Highlight : int
{
    CurrentPC = 0,
    Error,
    RunToCursor,
    MemoryLog,
};

class HighlightManager : public QObject
{
    Q_OBJECT

public:
    enum { MaxBreakpoints = 20 };

    struct Info
    {
        QString file;
        int line;
    };

    explicit HighlightManager(QObject* parent = nullptr);
    ~HighlightManager();

    static HighlightManager* instance() { return mInstance; }

    bool canAddBreakpoint() const;
    void addCodeBreakpoint(const QString& file, int line);
    void removeCodeBreakpoint(const QString& file, int line);

    const Info* highlight(Highlight highlight) const;
    void setHighlight(Highlight highlight, const QString& file, int line);
    void clearHighlight(Highlight highlight);

signals:
    void highlightsChanged();

private:
    static HighlightManager* mInstance;
    std::unordered_map<Highlight, Info> mHighlights;
    std::vector<Info> mCodeBreakpoints;

    Q_DISABLE_COPY(HighlightManager)
};

#endif
