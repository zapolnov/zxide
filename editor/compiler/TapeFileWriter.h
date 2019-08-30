#ifndef COMPILER_TAPEFILEWRITER_H
#define COMPILER_TAPEFILEWRITER_H

#include <QObject>
#include <memory>

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

    bool makeTape();

    bool writeTapeFile(const QString& file);
    bool writeWavFile(const QString& file);

private:
    ProgramBinary* mProgram;
    IErrorReporter* mReporter;
    std::unique_ptr<ILibSpectrum> mLibSpectrum;
    std::unique_ptr<ILibSpectrumTape> mTape;

    Q_DISABLE_COPY(TapeFileWriter)
};

#endif
