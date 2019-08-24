#include "ProgramLabel.h"
#include "compiler/Value.h"
#include <unordered_map>

class ProgramLabel::SimpleAddress final : public Address
{
public:
    SimpleAddress()
        : mValue(0)
        , mIsValid(false)
    {
    }

    std::shared_ptr<Address> SimpleAddress::clone() const final override
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

    std::shared_ptr<Address> CounterDependentAddress::clone() const final override
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

ProgramLabel::ProgramLabel(const Token& token)
    : ProgramOpcode(token)
    , mAddress(std::make_shared<SimpleAddress>())
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

void ProgramLabel::resolveAddress(quint32& address, Program*, IErrorReporter*)
{
    mAddress->setValue(unsigned(address));
}

void ProgramLabel::emitBinary(Program*, ProgramBinary*, IErrorReporter*) const
{
}
