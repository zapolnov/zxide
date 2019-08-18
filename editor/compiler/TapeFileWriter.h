#ifndef COMPILER_TAPEFILEWRITER_H
#define COMPILER_TAPEFILEWRITER_H

#include <QObject>

class ProgramBinary;
class IErrorReporter;

class TapeFileWriter : public QObject
{
    Q_OBJECT

public:
    TapeFileWriter(ProgramBinary* program, IErrorReporter* reporter);
    ~TapeFileWriter() override;

    bool writeTapeFile(const QString& file);

private:
    ProgramBinary* mProgram;
    IErrorReporter* mReporter;

    Q_DISABLE_COPY(TapeFileWriter)
};

#endif
