#include "Program.h"
#include "ProgramLabel.h"

Program::Program()
{
}

Program::~Program()
{
}

ProgramLabel* Program::addLabel(const Token& token, ProgramSection* section, const std::string& name)
{
    Q_ASSERT(section != nullptr);
    if (!section)
        return nullptr;

    auto it = mLabels.find(name);
    if (it != mLabels.end())
        return nullptr;

    auto label = section->emit<ProgramLabel>(token, section, name);
    mLabels[name] = label;

    return label;
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
