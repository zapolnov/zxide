#include "ProgramLabel.h"
#include "compiler/Value.h"
#include <unordered_map>

class ProgramLabel::AbstractAddress
{
public:
    AbstractAddress() = default;
    virtual ~AbstractAddress() = default;

    virtual std::shared_ptr<AbstractAddress> clone() const = 0;

    virtual bool hasAddress() const = 0;
    virtual unsigned address() const = 0;
    virtual void setAddress(unsigned value) = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ProgramLabel::SimpleAddress final : public AbstractAddress
{
public:
    SimpleAddress()
        : mAddress(0)
        , mHasAddress(false)
    {
    }

    std::shared_ptr<AbstractAddress> SimpleAddress::clone() const final override
    {
        return std::make_shared<SimpleAddress>(*this);
    }

    bool hasAddress() const final override
    {
        return mHasAddress;
    }

    unsigned address() const final override
    {
        Q_ASSERT(mHasAddress);
        return mAddress;
    }

    void setAddress(unsigned value) final override
    {
        Q_ASSERT(!mHasAddress);
        mAddress = value;
        mHasAddress = true;
    }

private:
    unsigned mAddress;
    bool mHasAddress;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ProgramLabel::CounterDependentAddress final : public AbstractAddress
{
public:
    CounterDependentAddress(std::shared_ptr<AbstractAddress> prototype, std::shared_ptr<Value> counter)
        : mPrototype(std::move(prototype))
        , mCounter(std::move(counter))
    {
    }

    std::shared_ptr<AbstractAddress> CounterDependentAddress::clone() const final override
    {
        return std::make_shared<CounterDependentAddress>(*this);
    }

    bool hasAddress() const final override
    {
        auto it = mAddresses.find(mCounter->number);
        return (it == mAddresses.end() ? false : it->second->hasAddress());
    }

    unsigned address() const final override
    {
        auto it = mAddresses.find(mCounter->number);
        Q_ASSERT(it != mAddresses.end());
        return it->second->address();
    }

    void setAddress(unsigned value) final override
    {
        auto& addr = mAddresses[mCounter->number];
        if (!addr)
            addr = mPrototype->clone();
        addr->setAddress(value);
    }

private:
    std::shared_ptr<AbstractAddress> mPrototype;
    std::shared_ptr<Value> mCounter;
    std::unordered_map<qint64, std::shared_ptr<AbstractAddress>> mAddresses;
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

bool ProgramLabel::hasAddress() const
{
    return mAddress->hasAddress();
}

unsigned ProgramLabel::address() const
{
    return mAddress->address();
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
    mAddress->setAddress(unsigned(address));
}

void ProgramLabel::emitBinary(Program*, ProgramBinary*, IErrorReporter*) const
{
}
