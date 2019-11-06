#include "ProgramSection.h"
#include "Compiler.h"
#include "ProgramOpcode.h"
#include "ProgramBinary.h"
#include "Expression.h"
#include "ExprEvalContext.h"
#include "IErrorReporter.h"
#include <QCoreApplication>

ProgramSection::ProgramSection(Program* program, const Token& token, std::string name)
    : mProgram(program)
    , mToken(token)
    , mCompression(Compression::Unspecified)
    , mName(std::move(name))
    , mResolvedBase(0)
    , mCalculatedBase(0)
    , mCalculatedAlignment(0)
    , mHasCalculatedBase(false)
    , mHasCalculatedAlignment(false)
    , mHasFileName(false)
    , mIsImaginary(false)
{
}

ProgramSection::~ProgramSection()
{
}

void ProgramSection::setBase(std::unique_ptr<Expression> expr)
{
    mBase = std::move(expr);
}

unsigned ProgramSection::base(IErrorReporter* reporter) const
{
    ExprEvalContext context(mProgram, reporter);
    Value value = context.evaluate(mBase);
    if (value.number < 0 || value.number > 0xffff) {
        QString fileName = (mToken.file ? mToken.file->name : QString());
        reporter->error(fileName, mToken.line,
            QCoreApplication::tr("section '%1' has invalid base address 0x%2")
            .arg(nameCStr()).arg(value.number, 0, 16));
        throw EvalError();
    }

    return quint32(value.number);
}

void ProgramSection::setAlignment(std::unique_ptr<Expression> expr)
{
    mAlignment = std::move(expr);
}

unsigned ProgramSection::alignment(IErrorReporter* reporter) const
{
    ExprEvalContext context(mProgram, reporter);
    Value value = context.evaluate(mAlignment);
    if (value.number < 0 || value.number > 0xffff) {
        QString fileName = (mToken.file ? mToken.file->name : QString());
        reporter->error(fileName, mToken.line,
            QCoreApplication::tr("section '%1' has invalid alignment %2").arg(nameCStr()).arg(value.number));
        throw EvalError();
    }

    return quint32(value.number);
}

bool ProgramSection::resolveAddresses(IErrorReporter* reporter, Program* program, quint32& address) const
{
    mHasCalculatedBase = false;
    mHasCalculatedAlignment = false;

    if (mBase) {
        mCalculatedBase = base(reporter);
        mHasCalculatedBase = true;
        address = mCalculatedBase;
    }

    if (mAlignment) {
        mCalculatedAlignment = alignment(reporter);
        mHasCalculatedAlignment = true;

        if (!mBase)
            address = (address + mCalculatedAlignment - 1) / mCalculatedAlignment * mCalculatedAlignment;
        else if ((mCalculatedBase % mCalculatedAlignment) != 0) {
            QString fileName = (mToken.file ? mToken.file->name : QString());
            reporter->error(fileName, mToken.line,
                QCoreApplication::tr("base address 0x%2 of section '%1' is not aligned to %3")
                .arg(nameCStr()).arg(mCalculatedBase, 0, 16).arg(mCalculatedAlignment));
        }
    }

    if (!isEmpty() && address > 0xFFFF) {
        QString fileName = (mToken.file ? mToken.file->name : QString());
        reporter->error(fileName, mToken.line,
            QCoreApplication::tr("section '%1' overflows 64K barrier").arg(nameCStr()));
        return false;
    }

    mResolvedBase = address;
    return CodeEmitter::resolveAddresses(reporter, program, address);
}

size_t ProgramSection::emitCode(Program* program, IProgramBinary* binary, IErrorReporter* reporter) const
{
    if (hasCode(program, reporter)) {
        if (mHasCalculatedBase) {
            if (mCalculatedBase < binary->endAddress()) {
                QString fileName = (mToken.file ? mToken.file->name : QString());
                reporter->error(fileName, mToken.line,
                    QCoreApplication::tr("section '%1' overlaps with address 0x%2 which belongs to another section")
                    .arg(nameCStr()).arg(mCalculatedBase, 0, 16));
            }
            while (binary->endAddress() < mCalculatedBase)
                binary->emitByte(mToken.file, mToken.line, 0); // NOP
        } else if (mHasCalculatedAlignment && mCalculatedAlignment > 1) {
            auto a = (binary->endAddress() + mCalculatedAlignment - 1) / mCalculatedAlignment * mCalculatedAlignment;
            while (binary->endAddress() < a)
                binary->emitByte(mToken.file, mToken.line, 0); // NOP
        }
    }

    Q_ASSERT(!mHasCalculatedBase || binary->endAddress() == mCalculatedBase);
    Q_ASSERT(!mHasCalculatedAlignment || binary->endAddress() % mCalculatedAlignment == 0);

    mHasCalculatedBase = false;
    mHasCalculatedAlignment = false;

    return CodeEmitter::emitCode(program, binary, reporter);
}
