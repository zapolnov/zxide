#include "AssemblerContext.h"
#include "compiler/IErrorReporter.h"
#include "compiler/Program.h"
#include "compiler/ProgramLabel.h"
#include "compiler/Expression.h"
#include "compiler/ExprEvalContext.h"
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

AssemblerContext::AssemblerContext(const AssemblerContext& source)
    : mPrev(source.mPrev ? source.mPrev->clone() : nullptr)
    , mLocalLabelsPrefix(source.mLocalLabelsPrefix)
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

std::string AssemblerContext::localLabelsPrefix() const
{
    return mLocalLabelsPrefix;
}

void AssemblerContext::setLocalLabelsPrefix(std::string prefix, const Token&, IErrorReporter*)
{
    Q_ASSERT(prefix.find("@@") == std::string::npos);
    mLocalLabelsPrefix = std::move(prefix);
}

Value AssemblerContext::resolveLocalValue(ExprEvalContext& context, const Token& token) const
{
    std::stringstream ss;
    ss << localLabelsPrefix();
    ss << "@@";
    ss << token.text;
    std::string name = ss.str();

    ProgramLabel* label = context.program()->findLabel(name);
    if (label) {
        if (!label->hasAddress()) {
            context.errorReporter()->error(token.file, token.line,
                QCoreApplication::tr("value for '%1' is not available in this context").arg(name.c_str()));
            throw EvalError();
        }
        return Value(label->address()->value());
    }

    const auto& expr = context.program()->findConstant(name);
    if (expr)
        return context.evaluate(expr);

    AssemblerContext* previous = prev();
    if (previous)
        return previous->resolveLocalValue(context, token);

    context.errorReporter()->error(token.file, token.line,
        QCoreApplication::tr("use of undeclared identifier '%1'").arg(name.c_str()));
    throw EvalError();
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

std::unique_ptr<AssemblerContext> AssemblerDefaultContext::clone() const
{
    return std::make_unique<AssemblerDefaultContext>(*this);
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

AssemblerRepeatContext::AssemblerRepeatContext(std::unique_ptr<AssemblerContext> prev,
        const Token& token, std::string var, std::unique_ptr<Expression> count)
    : AssemblerContext(std::move(prev))
    , mVariable(std::move(var))
    , mCodeEmitter(std::make_shared<RepeatedCodeEmitter>(std::move(count)))
    , mToken(token)
{
}

std::unique_ptr<AssemblerContext> AssemblerRepeatContext::clone() const
{
    return std::make_unique<AssemblerRepeatContext>(*this);
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

std::string AssemblerRepeatContext::localLabelsPrefix() const
{
    int depth = 0;
    for (AssemblerContext* p = prev(); p != nullptr; p = p->prev())
        ++depth;

    std::stringstream ss;
    ss << "repeat$";
    ss << mToken.file;
    ss << "$";
    ss << mToken.line;
    ss << "$";
    ss << depth;

    return ss.str();
}

void AssemblerRepeatContext::setLocalLabelsPrefix(std::string prefix, const Token& token, IErrorReporter* reporter)
{
    Q_ASSERT(false);
    reporter->error(token.file, token.line, QCoreApplication::tr("internal compiler error"));
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
