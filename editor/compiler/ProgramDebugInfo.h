#ifndef COMPILER_PROGRAMDEBUGINFO_H
#define COMPILER_PROGRAMDEBUGINFO_H

#include <QtGlobal>
#include <map>
#include <unordered_map>

class File;

struct TStates
{
    unsigned taken;
    unsigned notTaken;
};

struct SourceLocation
{
    File* file;
    int line;
};

class ProgramDebugInfo
{
public:
    ProgramDebugInfo();
    ~ProgramDebugInfo();

    const SourceLocation& sourceLocationForAddress(unsigned address) const;
    void setSourceLocation(unsigned address, File* file, int line);

    void setTStatesForLocation(const File* file, int line, unsigned taken, unsigned notTaken);
    const std::map<int, TStates>& tstatesForFile(const File* file) const;

    int resolveAddress(const File* file, int line) const;

private:
    std::unordered_map<const File*, std::map<int, unsigned>> mFileToMemory;
    std::unordered_map<const File*, std::map<int, TStates>> mFileToTStates;
    // that's quite suboptimal use of memory, but who counts memory these days?!
    SourceLocation mSourceLocations[0x10000];

    Q_DISABLE_COPY(ProgramDebugInfo)
};

#endif
