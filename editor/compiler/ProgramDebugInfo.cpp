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

const SourceLocation& ProgramDebugInfo::sourceLocationForAddress(unsigned address, bool withAux) const
{
    Q_ASSERT(address < 0x10000 * 8);
    if (address < 0x10000 * 8) {
        const auto& loc = mSourceLocations[address];
        if (!loc.file.isEmpty())
            return loc;

        if (withAux) {
            for (const auto& aux : mAuxiliaryInfos) {
                const auto& loc1 = aux->mSourceLocations[address];
                if (!loc1.file.isEmpty())
                    return loc1;
            }
        }

        return loc;
    }

    return dummySourceLocation;
}

void ProgramDebugInfo::setSourceLocation(const ProgramSection* section, unsigned address, const QString& file, int line)
{
    Q_ASSERT(address < 0x10000);
    if (address < 0x10000) {
        address |= section->bankAddress();
        auto& loc = mSourceLocations[address];
        loc.file = file;
        loc.line = line;
        mFileToMemory[file].emplace(line, address);
    }
}

int ProgramDebugInfo::addressForName(const QString& name, bool withAux) const
{
    auto it = mNameToAddress.find(name);
    if (it != mNameToAddress.end())
        return it->second;

    if (withAux) {
        for (const auto& aux : mAuxiliaryInfos) {
            int addr = aux->addressForName(name, withAux);
            if (addr != -1)
                return addr;
        }
    }

    return -1;
}

QString ProgramDebugInfo::nameForAddress(unsigned address, bool withAux) const
{
    auto it = mAddressToName.lower_bound(address);
    if (it != mAddressToName.end()) {
        if (it->first == address)
            return it->second;
        if (it != mAddressToName.begin()) {
            --it;
            return QStringLiteral("%1+%2").arg(it->second).arg(address - it->first);
        }
    }

    if (withAux) {
        for (const auto& aux : mAuxiliaryInfos) {
            QString str = aux->nameForAddress(address, withAux);
            if (!str.isEmpty())
                return str;
        }
    }

    return QString();
}

void ProgramDebugInfo::setAddressForName(const ProgramSection* section, const QString& name, unsigned address)
{
    address |= section->bankAddress();

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

void ProgramDebugInfo::addWriteProtection(const ProgramSection* section, unsigned address, ProgramWriteProtection protection)
{
    Q_ASSERT(address < 0x10000);
    if (address < 0x10000) {
        address |= section->bankAddress();
        mWriteProtection[address].emplace_back(std::move(protection));
    }
}

void ProgramDebugInfo::getWriteProtection(std::unordered_map<unsigned, std::vector<ProgramWriteProtection>>& writeProtection)
{
    writeProtection = mWriteProtection;
    for (const auto& auxInfo : mAuxiliaryInfos) {
        for (const auto& it : auxInfo->mWriteProtection) {
            Q_ASSERT(writeProtection.find(it.first) == writeProtection.end());
            writeProtection[it.first] = it.second;
        }
    }
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

const std::map<int, TStates>& ProgramDebugInfo::tstatesForFile(const QString& file, bool withAux) const
{
    auto it = mFileToTStates.find(file);
    if (it != mFileToTStates.end())
        return it->second;

    if (withAux) {
        for (const auto& aux : mAuxiliaryInfos) {
            const auto& map = aux->tstatesForFile(file, withAux);
            if (&map != &dummyTStatesMap)
                return map;
        }
    }

    return dummyTStatesMap;
}

int ProgramDebugInfo::resolveAddress(const QString& file, int line, bool withAux) const
{
    auto it = mFileToMemory.find(file);
    if (it != mFileToMemory.end()) {
        auto jt = it->second.lower_bound(line);
        if (jt != it->second.end())
            return jt->second;
    }

    if (withAux) {
        for (const auto& aux : mAuxiliaryInfos) {
            int addr = aux->resolveAddress(file, line, withAux);
            if (addr != -1)
                return addr;
        }
    }

    return -1;
}
