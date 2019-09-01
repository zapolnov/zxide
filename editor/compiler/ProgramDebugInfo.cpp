#include "ProgramDebugInfo.h"
#include <cstring>

static const SourceLocation dummySourceLocation{};
static const std::map<int, TStates> dummyTStatesMap;

ProgramDebugInfo::ProgramDebugInfo()
{
    memset(mSourceLocations, 0, sizeof(mSourceLocations));
}

ProgramDebugInfo::~ProgramDebugInfo()
{
}

const SourceLocation& ProgramDebugInfo::sourceLocationForAddress(unsigned address) const
{
    Q_ASSERT(address < 0x10000);
    if (address < 0x10000)
        return mSourceLocations[address];
    return dummySourceLocation;
}

void ProgramDebugInfo::setSourceLocation(unsigned address, File* file, int line)
{
    Q_ASSERT(address < 0x10000);
    if (address < 0x10000) {
        auto& loc = mSourceLocations[address];
        loc.file = file;
        loc.line = line;
        mFileToMemory[file][line] = address;
    }
}

void ProgramDebugInfo::setTStatesForLocation(const File* file, int line, unsigned taken, unsigned notTaken)
{
    TStates s;
    s.taken = taken;
    s.notTaken = notTaken;
    mFileToTStates[file][line] = s;
}

const std::map<int, TStates>& ProgramDebugInfo::tstatesForFile(const File* file) const
{
    auto it = mFileToTStates.find(file);
    return (it != mFileToTStates.end() ? it->second : dummyTStatesMap);
}

int ProgramDebugInfo::resolveAddress(const File* file, int line) const
{
    auto it = mFileToMemory.find(file);
    if (it == mFileToMemory.end())
        return -1;

    auto jt = it->second.lower_bound(line);
    if (jt == it->second.end())
        return -1;

    return jt->second;
}
