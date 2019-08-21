#include "AssemblerContext.h"
#include "compiler/Program.h"

AssemblerContext::AssemblerContext(std::unique_ptr<AssemblerContext> prev)
    : mPrev(std::move(prev))
{
}

AssemblerContext::~AssemblerContext()
{
}

std::unique_ptr<AssemblerContext> AssemblerContext::takePrev()
{
    std::unique_ptr<AssemblerContext> ret{std::move(mPrev)};
    return ret;
}

bool AssemblerContext::isRepeat() const
{
    return false;
}

bool AssemblerContext::hasVariable(const std::string& name) const
{
    return false;
}

bool AssemblerContext::setCurrentSection(ProgramSection*)
{
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AssemblerDefaultContext::AssemblerDefaultContext(Program* program)
    : AssemblerContext(nullptr)
{
    mSection = program->getOrCreateSection(std::string());
}

CodeEmitter* AssemblerDefaultContext::codeEmitter() const
{
    return mSection;
}

bool AssemblerDefaultContext::setCurrentSection(ProgramSection* section)
{
    mSection = section;
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AssemblerRepeatContext::AssemblerRepeatContext(std::unique_ptr<AssemblerContext> prev, std::string variable)
    : AssemblerContext(std::move(prev))
    , mVariable(std::move(variable))
{
}

bool AssemblerRepeatContext::isRepeat() const
{
    return true;
}

bool AssemblerRepeatContext::hasVariable(const std::string& name) const
{
    return mVariable == name || prev()->hasVariable(name);
}

CodeEmitter* AssemblerRepeatContext::codeEmitter() const
{
    // FIXME
    return prev()->codeEmitter();
}
