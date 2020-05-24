#ifndef COMPILER_TAPEFILEWRITER_H
#define COMPILER_TAPEFILEWRITER_H

#include <QObject>
#include <memory>
#include <string>

class ProgramBinary;
class IErrorReporter;

class TapeFileWriter : public QObject
{
    Q_OBJECT

public:
    class ILibSpectrum;
    class ILibSpectrumTape;

    TapeFileWriter(ProgramBinary* program, IErrorReporter* reporter);
    ~TapeFileWriter() override;

    void setBasicCode(const QByteArray& basicCode) { mBasicCode = basicCode; }
    void setBasicStartLine(int line) { mBasicStartLine = line; }

    void setLoaderName(std::string loaderName) { mLoaderName = std::move(loaderName); }
    void setProgramName(std::string programName) { mProgramName = std::move(programName); }
    void setDontOutputMainFile(bool flag) { mDontOutputMainFile = flag; }

    bool makeTape();

    bool writeTapeFile(const QString& file);
    bool writeWavFile(const QString& file);

private:
    ProgramBinary* mProgram;
    IErrorReporter* mReporter;
    std::unique_ptr<ILibSpectrum> mLibSpectrum;
    std::unique_ptr<ILibSpectrumTape> mTape;
    std::string mLoaderName;
    std::string mProgramName;
    bool mDontOutputMainFile;
    QByteArray mBasicCode;
    int mBasicStartLine;

    Q_DISABLE_COPY(TapeFileWriter)
};

#endif
