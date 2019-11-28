#include "ProgramLabel.h"
#include "compiler/Compiler.h"
#include "compiler/IErrorReporter.h"
#include "compiler/Value.h"
#include "compiler/ProgramDebugInfo.h"
#include "compiler/ProgramBinary.h"
#include <unordered_map>
#include <QCoreApplication>

class ProgramLabel::SimpleAddress final : public Address
{
public:
    SimpleAddress()
        : mValue(0)
        , mIsValid(false)
    {
    }

    std::shared_ptr<Address> clone() const final override
    {
        return std::make_shared<SimpleAddress>(*this);
    }

    bool isValid() const final override
    {
        return mIsValid;
    }

    unsigned value() const final override
    {
        Q_ASSERT(mIsValid);
        return mValue;
    }

    void setValue(unsigned value) final override
    {
        Q_ASSERT(!mIsValid);
        mValue = value;
        mIsValid = true;
    }

private:
    unsigned mValue;
    bool mIsValid;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ProgramLabel::CounterDependentAddress final : public Address
{
public:
    CounterDependentAddress(std::shared_ptr<Address> prototype, std::shared_ptr<Value> counter)
        : mPrototype(std::move(prototype))
        , mCounter(std::move(counter))
    {
    }

    std::shared_ptr<Address> clone() const final override
    {
        return std::make_shared<CounterDependentAddress>(*this);
    }

    bool isValid() const final override
    {
        auto it = mAddresses.find(mCounter->number);
        return (it == mAddresses.end() ? false : it->second->isValid());
    }

    unsigned value() const final override
    {
        auto it = mAddresses.find(mCounter->number);
        Q_ASSERT(it != mAddresses.end());
        return it->second->value();
    }

    void setValue(unsigned value) final override
    {
        auto& addr = mAddresses[mCounter->number];
        if (!addr)
            addr = mPrototype->clone();
        addr->setValue(value);
    }

private:
    std::shared_ptr<Address> mPrototype;
    std::shared_ptr<Value> mCounter;
    std::unordered_map<qint64, std::shared_ptr<Address>> mAddresses;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ProgramLabel::ProgramLabel(const Token& token, std::string name)
    : ProgramOpcode(token)
    , mAddress(std::make_shared<SimpleAddress>())
    , mName(std::move(name))
{
}

ProgramLabel::~ProgramLabel()
{
}

void ProgramLabel::addCounter(std::shared_ptr<Value> counter)
{
    mAddress = std::make_shared<CounterDependentAddress>(std::move(mAddress), std::move(counter));
}

unsigned ProgramLabel::lengthInBytes(const Program*, IErrorReporter*) const
{
    return 0;
}

unsigned ProgramLabel::tstatesIfNotTaken(const Program*, IErrorReporter*) const
{
    return 0;
}

unsigned ProgramLabel::tstatesIfTaken(const Program*, IErrorReporter*) const
{
    return 0;
}

bool ProgramLabel::resolveAddress(quint32& address, Program*, IErrorReporter* reporter)
{
    if (address > 0xFFFF) {
        QString fileName = (token().file ? token().file->name : QString());
        reporter->error(fileName, token().line, QCoreApplication::tr("address is over 64K"));
        return false;
    }

    mAddress->setValue(unsigned(address));
    return true;
}

void ProgramLabel::emitBinary(Program*, IProgramBinary* binary, IErrorReporter*) const
{
    Q_ASSERT(binary->endAddress() == mAddress->value());
    binary->setAddressForName(QString::fromUtf8(mName.c_str(), int(mName.length())), mAddress->value());
}
