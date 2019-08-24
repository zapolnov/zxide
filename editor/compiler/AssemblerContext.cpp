#include "AssemblerContext.h"
#include "compiler/Program.h"
#include "compiler/Value.h"
#include "compiler/Expression.h"

static const std::shared_ptr<Value> nullValue;

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

const std::shared_ptr<Value>& AssemblerContext::getVariable(const std::string& name) const
{
    return nullValue;
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

AssemblerRepeatContext::AssemblerRepeatContext(
        std::unique_ptr<AssemblerContext> prev, std::string var, std::unique_ptr<Expression> count)
    : AssemblerContext(std::move(prev))
    , mVariable(std::move(var))
    , mCodeEmitter(std::make_shared<RepeatedCodeEmitter>(std::move(count)))
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

const std::shared_ptr<Value>& AssemblerRepeatContext::getVariable(const std::string& name) const
{
    if (mVariable == name)
        return mCodeEmitter->counter();
    return prev()->getVariable(name);
}

CodeEmitter* AssemblerRepeatContext::codeEmitter() const
{
    return mCodeEmitter.get();
}
