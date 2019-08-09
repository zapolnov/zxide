#ifndef COMPILER_LINKER_H
#define COMPILER_LINKER_H

#include <QObject>
#include <vector>
#include <memory>

class Program;
class ProgramSection;
class ProgramBinary;
class IErrorReporter;

class Linker : public QObject
{
    Q_OBJECT

public:
    Linker(Program* program, IErrorReporter* reporter);
    ~Linker() override;

    std::unique_ptr<ProgramBinary> emitCode();

private:
    Program* mProgram;
    IErrorReporter* mReporter;

    std::vector<ProgramSection*> collectSections() const;

    void error(const QString& message);

    Q_DISABLE_COPY(Linker)
};

#endif
