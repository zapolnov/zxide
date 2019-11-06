#include "ProgramDebugInfo.h"
#include "compiler/ProgramSection.h"
#include "compiler/Compiler.h"
#include <cstring>

static const SourceLocation dummySourceLocation{};
static const std::map<int, TStates> dummyTStatesMap;

ProgramDebugInfo::ProgramDebugInfo()
{
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

void ProgramDebugInfo::setSourceLocation(unsigned address, const QString& file, int line)
{
    Q_ASSERT(address < 0x10000);
    if (address < 0x10000) {
        auto& loc = mSourceLocations[address];
        loc.file = file;
        loc.line = line;
        mFileToMemory[file].emplace(line, address);
    }
}

int ProgramDebugInfo::addressForName(const QString& name) const
{
    auto it = mNameToAddress.find(name);
    return (it != mNameToAddress.end() ? it->second : -1);
}

QString ProgramDebugInfo::nameForAddress(unsigned address) const
{
    auto it = mAddressToName.lower_bound(address);
    if (it == mAddressToName.end())
        return QString();

    if (it->first == address)
        return it->second;

    if (it == mAddressToName.begin())
        return QString();

    --it;
    return QStringLiteral("%1+%2").arg(it->second).arg(address - it->first);
}

void ProgramDebugInfo::setAddressForName(const ProgramSection* section, const QString& name, unsigned address)
{
    mNameToAddress[name] = address;
    mAddressToName.emplace(address, name);

    auto it = mSectionIndex.find(section);
    Q_ASSERT(it != mSectionIndex.end());
    if (it != mSectionIndex.end())
        mSections[it->second].symbols.emplace(address, name);
}

void ProgramDebugInfo::addSection(const ProgramSection* section, unsigned start, unsigned originalLength)
{
    size_t index = mSections.size();
    mSections.emplace_back(ProgramSectionInfo{ QString(section->nameCStr()), start, originalLength, 0 });
    mSectionIndex[section] = index;
}

void ProgramDebugInfo::setSectionCompressedLength(const ProgramSection* section, unsigned compressedLength)
{
    Q_ASSERT(mSectionIndex.find(section) != mSectionIndex.end());
    size_t index = mSectionIndex[section];
    Q_ASSERT(mSections[index].compressedLength == 0);
    mSections[index].compressedLength = compressedLength;
}

void ProgramDebugInfo::setTStatesForLocation(const SourceFile* file, int line, unsigned taken, unsigned notTaken)
{
    if (!file)
        return;

    TStates s;
    s.taken = taken;
    s.notTaken = notTaken;
    mFileToTStates[file->name][line] = s;
}

const std::map<int, TStates>& ProgramDebugInfo::tstatesForFile(const QString& file) const
{
    auto it = mFileToTStates.find(file);
    return (it != mFileToTStates.end() ? it->second : dummyTStatesMap);
}

int ProgramDebugInfo::resolveAddress(const QString& file, int line) const
{
    auto it = mFileToMemory.find(file);
    if (it == mFileToMemory.end())
        return -1;

    auto jt = it->second.lower_bound(line);
    if (jt == it->second.end())
        return -1;

    return jt->second;
}
