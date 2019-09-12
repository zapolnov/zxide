#ifndef COMPILER_PROGRAMDEBUGINFO_H
#define COMPILER_PROGRAMDEBUGINFO_H

#include <QHash>
#include <QString>
#include <map>
#include <unordered_map>

struct SourceFile;

struct TStates
{
    unsigned taken;
    unsigned notTaken;
};

struct SourceLocation
{
    QString file;
    int line;
};

class ProgramDebugInfo
{
public:
    ProgramDebugInfo();
    ~ProgramDebugInfo();

    const SourceLocation& sourceLocationForAddress(unsigned address) const;
    void setSourceLocation(unsigned address, const QString& file, int line);

    void setTStatesForLocation(const SourceFile* file, int line, unsigned taken, unsigned notTaken);
    const std::map<int, TStates>& tstatesForFile(const QString& file) const;

    int resolveAddress(const QString& file, int line) const;

private:
    struct hash
    {
        size_t operator()(const QString& str) const { return qHash(str); }
    };

    std::unordered_map<QString, std::map<int, unsigned>, hash> mFileToMemory;
    std::unordered_map<QString, std::map<int, TStates>, hash> mFileToTStates;
    // that's quite suboptimal use of memory, but who counts memory these days?!
    SourceLocation mSourceLocations[0x10000];

    Q_DISABLE_COPY(ProgramDebugInfo)
};

#endif
