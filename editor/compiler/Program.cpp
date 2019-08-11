#include "Program.h"
#include "ProgramLabel.h"
#include "Expression.h"

Program::Program()
{
}

Program::~Program()
{
}

bool Program::addConstant(std::string name, std::unique_ptr<Expression> expr)
{
    auto it = mConstants.find(name);
    if (it != mConstants.end())
        return false;
    auto jt = mLabels.find(name);
    if (jt != mLabels.end())
        return false;

    mConstants[name] = std::move(expr);
    return true;
}

Expression* Program::findConstant(const std::string& name) const
{
    auto it = mConstants.find(name);
    return (it != mConstants.end() ? it->second.get() : nullptr);
}

bool Program::resolveConstantValues(IErrorReporter* reporter) const
{
    for (const auto& it : mConstants) {
        if (!it.second->resolveValues(this, 0, reporter)) // FIXME
            return false;
    }
    return true;
}

ProgramLabel* Program::addLabel(const Token& token, ProgramSection* section, const std::string& name)
{
    Q_ASSERT(section != nullptr);
    if (!section)
        return nullptr;

    auto it = mLabels.find(name);
    if (it != mLabels.end())
        return nullptr;
    auto jt = mConstants.find(name);
    if (jt != mConstants.end())
        return nullptr;

    auto label = section->emit<ProgramLabel>(token, section, name);
    mLabels[name] = label;

    return label;
}

ProgramLabel* Program::findLabel(const std::string& name) const
{
    auto it = mLabels.find(name);
    return (it != mLabels.end() ? it->second : nullptr);
}

ProgramSection* Program::getOrCreateSection(const std::string& name)
{
    auto it = mSections.find(name);
    if (it != mSections.end())
        return it->second.get();

    auto section = std::make_unique<ProgramSection>(this, name);
    ProgramSection* ptr = section.get();
    mSections[name] = std::move(section);

    return ptr;
}

void Program::forEachSection(const std::function<void(ProgramSection*)>& iterator) const
{
    for (const auto& it : mSections)
        iterator(it.second.get());
}
