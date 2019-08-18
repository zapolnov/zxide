#include "ProgramDebugInfo.h"
#include <cstring>

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
    static const SourceLocation dummy;
    return dummy;
}

void ProgramDebugInfo::setSourceLocation(unsigned address, File* file, int line)
{
    Q_ASSERT(address < 0x10000);
    if (address < 0x10000) {
        auto& loc = mSourceLocations[address];
        loc.file = file;
        loc.line = line;
    }
}
