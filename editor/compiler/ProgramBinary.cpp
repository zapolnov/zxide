#include "ProgramBinary.h"
#include "compiler/Compiler.h"
#include "compiler/ProgramDebugInfo.h"
#include "compiler/ProgramSection.h"

ProgramBinary::ProgramBinary()
{
}

ProgramBinary::~ProgramBinary()
{
}

void ProgramBinary::setCurrentFile(const std::string& fileName)
{
    auto it = mFiles.find(fileName);
    if (it == mFiles.end()) {
        Q_ASSERT(false);
        it = createFile(fileName, 0);
    }
    mCurrentFile = it;
}

void ProgramBinary::setCurrentFile(const std::string& fileName, unsigned baseAddress)
{
    auto it = mFiles.find(fileName);
    if (it == mFiles.end())
        it = createFile(fileName, baseAddress);
    mCurrentFile = it;
}

void ProgramBinary::emitByte(const SourceFile* file, int line, quint8 byte)
{
    QString fileName = (file ? file->name : QString());
    mCurrentFile->second.code.emplace_back(byte);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
}

void ProgramBinary::emitWord(const SourceFile* file, int line, quint16 word)
{
    QString fileName = (file ? file->name : QString());
    mCurrentFile->second.code.emplace_back(quint8(word & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((word >> 8) & 0xFF));
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
}

void ProgramBinary::emitDWord(const SourceFile* file, int line, quint32 dword)
{
    QString fileName = (file ? file->name : QString());
    mCurrentFile->second.code.emplace_back(quint8(dword & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((dword >> 8) & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((dword >> 16) & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((dword >> 24) & 0xFF));
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
}

void ProgramBinary::emitQWord(const SourceFile* file, int line, quint64 qword)
{
    QString fileName = (file ? file->name : QString());
    mCurrentFile->second.code.emplace_back(quint8(qword & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((qword >> 8) & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((qword >> 16) & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((qword >> 24) & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((qword >> 32) & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((qword >> 40) & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((qword >> 48) & 0xFF));
    mCurrentFile->second.code.emplace_back(quint8((qword >> 56) & 0xFF));
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
    mCurrentFile->second.debugInfo->setSourceLocation(mCurrentFile->second.endAddress++, fileName, line);
}

ProgramBinary::FileMap::iterator ProgramBinary::createFile(std::string fileName, unsigned baseAddress)
{
    File f;
    f.debugInfo = std::make_unique<ProgramDebugInfo>();
    f.baseAddress = baseAddress;
    f.endAddress = baseAddress;
    return mFiles.emplace(std::move(fileName), std::move(f)).first;
}
