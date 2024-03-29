#ifndef COMPILER_LINKER_H
#define COMPILER_LINKER_H

#include <QObject>
#include <vector>
#include <memory>

class Program;
class ProgramSection;
class ProgramBinary;
class IProgramBinary;
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

    size_t emitCodeForSection(IProgramBinary* binary, ProgramSection* section);

    bool isEmpty(const std::vector<ProgramSection*>& sections) const;
    bool hasCode(const std::vector<ProgramSection*>& sections) const;
    std::map<std::string, std::vector<ProgramSection*>> collectSections() const;

    void error(const QString& message);

    Q_DISABLE_COPY(Linker)
};

#endif
