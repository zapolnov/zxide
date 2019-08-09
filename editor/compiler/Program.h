#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include "ProgramSection.h"
#include <map>
#include <string>
#include <memory>

class File;

class Program
{
public:
    Program();
    ~Program();

    ProgramLabel* addLabel(File* file, int line, ProgramSection* section, const std::string& name);

    ProgramSection* getOrCreateSection(const std::string& name);

private:
    std::map<std::string, std::unique_ptr<ProgramSection>> mSections;
    std::map<std::string, ProgramLabel*> mLabels;

    Q_DISABLE_COPY(Program)
};

#endif
