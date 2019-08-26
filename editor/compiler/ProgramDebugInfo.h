#ifndef COMPILER_PROGRAMDEBUGINFO_H
#define COMPILER_PROGRAMDEBUGINFO_H

#include <QtGlobal>
#include <map>
#include <unordered_map>

class File;

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

    int resolveAddress(const File* file, int line) const;

private:
    std::unordered_map<const File*, std::map<int, unsigned>> mFileToMemory;
    // that's quite suboptimal use of memory, but who counts memory these days?!
    SourceLocation mSourceLocations[0x10000];

    Q_DISABLE_COPY(ProgramDebugInfo)
};

#endif
