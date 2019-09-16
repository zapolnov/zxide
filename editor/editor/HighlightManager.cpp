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
