#include "AssemblerContext.h"
#include "compiler/IErrorReporter.h"
#include "compiler/Program.h"
#include "compiler/ProgramLabel.h"
#include "compiler/Expression.h"
#include "compiler/Value.h"
#include <sstream>
#include <QCoreApplication>

#ifdef emit
#undef emit
#endif

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
    return (mPrev ? mPrev->hasVariable(name) : false);
}

const std::shared_ptr<Value>& AssemblerContext::getVariable(const std::string& name) const
{
    return (mPrev ? mPrev->getVariable(name) : nullValue);
}

void AssemblerContext::setLocalLabelsPrefix(std::string prefix, const Token&, IErrorReporter*)
{
    mLocalLabelsPrefix = std::move(prefix);
}

std::string AssemblerContext::resolveLocalLabel(
    Program* program, const Token& token, IErrorReporter* reporter, bool recursive)
{
    std::string name;
    if (!mLocalLabelsPrefix.empty()) {
        std::stringstream ss;
        ss << mLocalLabelsPrefix;
        ss << "@@";
        ss << token.text;
        name = ss.str();
        if (program->findLabel(name))
            return name;
    }

    if (recursive && mPrev)
        return mPrev->resolveLocalLabel(program, token, reporter, recursive);

    if (name.empty()) {
        reporter->error(token.file, token.line,
            QCoreApplication::tr("found local label name without previous global label"));
    }

    return name;
}

bool AssemblerContext::areGlobalLabelsAllowed() const
{
    return (mPrev ? mPrev->areGlobalLabelsAllowed() : true);
}

void AssemblerContext::adjustLabel(ProgramLabel* label)
{
    if (mPrev)
        mPrev->adjustLabel(label);
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
    return mVariable == name || AssemblerContext::hasVariable(name);
}

const std::shared_ptr<Value>& AssemblerRepeatContext::getVariable(const std::string& name) const
{
    return (mVariable == name ? mCodeEmitter->counter() : AssemblerContext::getVariable(name));
}

void AssemblerRepeatContext::setLocalLabelsPrefix(std::string prefix, const Token& token, IErrorReporter* reporter)
{
    Q_ASSERT(false);
    reporter->error(token.file, token.line, QCoreApplication::tr("internal compiler error"));
}

std::string AssemblerRepeatContext::resolveLocalLabel(
    Program* program, const Token& token, IErrorReporter* reporter, bool recursive)
{
    int depth = 0;
    for (AssemblerContext* p = prev(); p != nullptr; p = p->prev())
        ++depth;

    std::stringstream ss;
    ss << "repeat$";
    ss << depth;
    ss << "@@";
    ss << token.text;
    std::string name = ss.str();

    AssemblerContext* previous;
    if (recursive && (previous = prev()) != nullptr && !program->findLabel(name))
        return previous->resolveLocalLabel(program, token, reporter, recursive);

    return name;
}

bool AssemblerRepeatContext::areGlobalLabelsAllowed() const
{
    return false;
}


void AssemblerRepeatContext::adjustLabel(ProgramLabel* label)
{
    label->addCounter(mCodeEmitter->counter());
    AssemblerContext::adjustLabel(label);
}

CodeEmitter* AssemblerRepeatContext::codeEmitter() const
{
    return mCodeEmitter.get();
}
