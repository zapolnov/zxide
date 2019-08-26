#ifndef COMPILER_PROGRAMLABEL_H
#define COMPILER_PROGRAMLABEL_H

#include "ProgramOpcode.h"
#include <string>

class Program;
class ProgramBinary;
struct Value;

class ProgramLabel : public ProgramOpcode
{
public:
    class Address
    {
    public:
        Address() = default;
        virtual ~Address() = default;

        virtual bool isValid() const = 0;
        virtual unsigned value() const = 0;
        virtual void setValue(unsigned value) = 0;

    protected:
        virtual std::shared_ptr<Address> clone() const = 0;

        friend class ProgramLabel;
    };

    explicit ProgramLabel(const Token& token);
    ~ProgramLabel() override;

    bool hasAddress() const { return mAddress->isValid(); }
    const std::shared_ptr<Address>& address() const { return mAddress; }

    void addCounter(std::shared_ptr<Value> counter);

    unsigned lengthInBytes(const Program* program, IErrorReporter* reporter) const override;
    unsigned tstatesIfNotTaken(const Program* program, IErrorReporter* reporter) const override;
    unsigned tstatesIfTaken(const Program* program, IErrorReporter* reporter) const override;

    bool resolveAddress(quint32& address, Program* program, IErrorReporter* reporter) override;
    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    class SimpleAddress;
    class CounterDependentAddress;

    std::shared_ptr<Address> mAddress;

    Q_DISABLE_COPY(ProgramLabel)
};

#endif
