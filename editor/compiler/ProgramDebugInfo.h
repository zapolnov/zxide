#ifndef COMPILER_PROGRAMDEBUGINFO_H
#define COMPILER_PROGRAMDEBUGINFO_H

#include <QHash>
#include <QString>
#include <map>
#include <unordered_map>
#include <vector>

struct SourceFile;
class ProgramSection;

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

struct ProgramSectionInfo
{
    QString name;
    unsigned startAddress;
    unsigned originalLength;
    unsigned compressedLength;
    std::multimap<unsigned, QString> symbols;
};

class ProgramDebugInfo
{
public:
    ProgramDebugInfo();
    ~ProgramDebugInfo();

    const SourceLocation& sourceLocationForAddress(unsigned address) const;
    void setSourceLocation(const ProgramSection* section, unsigned address, const QString& file, int line);

    int addressForName(const QString& name) const;
    QString nameForAddress(unsigned address) const;
    void setAddressForName(const ProgramSection* section, const QString& name, unsigned address);

    const std::vector<ProgramSectionInfo>& sections() const { return mSections; }
    void addSection(const ProgramSection* section, unsigned start, unsigned originalLength);
    void setSectionCompressedLength(const ProgramSection* section, unsigned compressedLength);

    void setTStatesForLocation(const SourceFile* file, int line, unsigned taken, unsigned notTaken);
    const std::map<int, TStates>& tstatesForFile(const QString& file) const;

    int resolveAddress(const QString& file, int line) const;

private:
    struct hash
    {
        size_t operator()(const QString& str) const { return qHash(str); }
    };

    std::vector<ProgramSectionInfo> mSections;
    std::unordered_map<const ProgramSection*, size_t> mSectionIndex;
    std::unordered_map<QString, std::map<int, unsigned>, hash> mFileToMemory;
    std::unordered_map<QString, std::map<int, TStates>, hash> mFileToTStates;
    std::unordered_map<QString, unsigned, hash> mNameToAddress;
    std::map<unsigned, QString> mAddressToName;
    // that's quite suboptimal use of memory, but who counts memory these days?!
    SourceLocation mSourceLocations[0x10000 * 8];

    Q_DISABLE_COPY(ProgramDebugInfo)
};

#endif
