#include "HighlightManager.h"

HighlightManager* HighlightManager::mInstance;

HighlightManager::HighlightManager(QObject* parent)
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;
}

HighlightManager::~HighlightManager()
{
    Q_ASSERT(mInstance == this);
    mInstance = nullptr;
}

bool HighlightManager::canAddBreakpoint() const
{
    return mCodeBreakpoints.size() < MaxBreakpoints;
}

void HighlightManager::addCodeBreakpoint(const QString& file, int line)
{
    if (mCodeBreakpoints.size() >= MaxBreakpoints)
        return;

    for (const auto& it : mCodeBreakpoints) {
        if (it.file == file && it.line == line)
            return;
    }

    mCodeBreakpoints.emplace_back(Info{ file, line });
    emit highlightsChanged();
}

void HighlightManager::removeCodeBreakpoint(const QString& file, int line)
{
    for (auto it = mCodeBreakpoints.begin(); it != mCodeBreakpoints.end(); ++it) {
        if (it->file == file && it->line == line) {
            mCodeBreakpoints.erase(it);
            emit highlightsChanged();
            return;
        }
    }
}

const HighlightManager::Info* HighlightManager::highlight(Highlight highlight) const
{
    auto it = mHighlights.find(highlight);
    return (it != mHighlights.end() ? &it->second : nullptr);
}

void HighlightManager::setHighlight(Highlight highlight, const QString& file, int line)
{
    auto& info = mHighlights[highlight];
    info.file = file;
    info.line = line;
    emit highlightsChanged();
}

void HighlightManager::clearHighlight(Highlight highlight)
{
    mHighlights.erase(highlight);
    emit highlightsChanged();
}
