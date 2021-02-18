#ifndef COMPILER_DISKFILEWRITER_H
#define COMPILER_DISKFILEWRITER_H

#include <QObject>
#include <memory>
#include <string>

class ProgramBinary;
class IErrorReporter;

class DiskFileWriter : public QObject
{
    Q_OBJECT

public:
    DiskFileWriter(ProgramBinary* program, IErrorReporter* reporter);
    ~DiskFileWriter() override;

    void setBasicCode(const QByteArray& basicCode) { mBasicCode = basicCode; }
    void setBasicStartLine(int line) { mBasicStartLine = line; }

    void setLoaderName(std::string loaderName) { mLoaderName = std::move(loaderName); }
    void setProgramName(std::string programName) { mProgramName = std::move(programName); }
    void setDontOutputMainFile(bool flag) { mDontOutputMainFile = flag; }

    bool writeSclFile(const QString& fileName);
    bool writeTrdFile(const QString& fileName);

private:
    ProgramBinary* mProgram;
    IErrorReporter* mReporter;
    std::string mLoaderName;
    std::string mProgramName;
    bool mDontOutputMainFile;
    QByteArray mBasicCode;
    int mBasicStartLine;

    Q_DISABLE_COPY(DiskFileWriter)
};

#endif
