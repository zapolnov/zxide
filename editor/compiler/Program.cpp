#include "Program.h"

Program::Program()
{
}

Program::~Program()
{
}

ProgramSection* Program::getOrCreateSection(const std::string& name)
{
    auto it = mSections.find(name);
    if (it != mSections.end())
        return it->second.get();

    auto section = std::make_unique<ProgramSection>(name);
    ProgramSection* ptr = section.get();
    mSections[name] = std::move(section);

    return ptr;
}
