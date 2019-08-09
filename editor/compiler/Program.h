#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include "ProgramSection.h"
#include <functional>
#include <map>
#include <string>
#include <memory>

struct Token;

class Program
{
public:
    Program();
    ~Program();

    ProgramLabel* addLabel(const Token& token, ProgramSection* section, const std::string& name);

    size_t sectionCount() const { return mSections.size(); }
    ProgramSection* getOrCreateSection(const std::string& name);
    void forEachSection(const std::function<void(ProgramSection*)>& iterator) const;

private:
    std::map<std::string, std::unique_ptr<ProgramSection>> mSections;
    std::map<std::string, ProgramLabel*> mLabels;

    Q_DISABLE_COPY(Program)
};

#endif
