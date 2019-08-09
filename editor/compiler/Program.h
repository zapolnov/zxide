#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include "ProgramSection.h"
#include <map>
#include <string>
#include <memory>

class Program
{
public:
    Program();
    ~Program();

    ProgramSection* getOrCreateSection(const std::string& name);

private:
    std::map<std::string, std::unique_ptr<ProgramSection>> mSections;

    Q_DISABLE_COPY(Program)
};

#endif
