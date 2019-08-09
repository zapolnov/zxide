#ifndef COMPILER_PROGRAMSECTION_H
#define COMPILER_PROGRAMSECTION_H

#include <QtGlobal>
#include <string>

class ProgramSection
{
public:
    explicit ProgramSection(std::string name);
    ~ProgramSection();

    const std::string& name() const { return mName; }

private:
    std::string mName;

    Q_DISABLE_COPY(ProgramSection)
};

#endif
