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

    const SourceLocation& sourceLocationForAddress(unsigned address, bool withAux) const;
    void setSourceLocation(const ProgramSection* section, unsigned address, const QString& file, int line);

    int addressForName(const QString& name, bool withAux) const;
    QString nameForAddress(unsigned address, bool withAux) const;
    void setAddressForName(const ProgramSection* section, const QString& name, unsigned address);

    const std::vector<ProgramSectionInfo>& sections() const { return mSections; }
    void addSection(const ProgramSection* section, unsigned start, unsigned originalLength);
    void setSectionCompressedLength(const ProgramSection* section, unsigned compressedLength);

    void setTStatesForLocation(const SourceFile* file, int line, unsigned taken, unsigned notTaken);
    const std::map<int, TStates>& tstatesForFile(const QString& file, bool withAux) const;

    int resolveAddress(const QString& file, int line, bool withAux) const;

    void addAuxiliaryDebugInfo(const std::shared_ptr<ProgramDebugInfo>& info) { mAuxiliaryInfos.emplace_back(info); }

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
    std::vector<std::shared_ptr<ProgramDebugInfo>> mAuxiliaryInfos;
    // that's quite suboptimal use of memory, but who counts memory these days?!
    SourceLocation mSourceLocations[0x10000 * 8];

    Q_DISABLE_COPY(ProgramDebugInfo)
};

#endif
