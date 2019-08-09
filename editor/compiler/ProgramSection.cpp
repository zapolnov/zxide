#include "ProgramSection.h"
#include "ProgramOpcode.h"

ProgramSection::ProgramSection(std::string name)
    : mName(std::move(name))
    , mBase(0)
    , mAlignment(1)
    , mHasBase(false)
    , mHasAlignment(false)
{
}

ProgramSection::~ProgramSection()
{
}
