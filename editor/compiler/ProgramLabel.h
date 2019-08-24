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
    explicit ProgramLabel(const Token& token);
    ~ProgramLabel() override;

    bool hasAddress() const;
    unsigned address() const;

    void addCounter(std::shared_ptr<Value> counter);

    unsigned lengthInBytes(const Program* program, IErrorReporter* reporter) const override;
    unsigned tstatesIfNotTaken(const Program* program, IErrorReporter* reporter) const override;
    unsigned tstatesIfTaken(const Program* program, IErrorReporter* reporter) const override;

    void resolveAddress(quint32& address, Program* program, IErrorReporter* reporter) override;
    void emitBinary(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const override;

private:
    class AbstractAddress;
    class SimpleAddress;
    class CounterDependentAddress;

    std::shared_ptr<AbstractAddress> mAddress;

    Q_DISABLE_COPY(ProgramLabel)
};

#endif
