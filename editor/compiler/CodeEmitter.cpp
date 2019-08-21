#include "CodeEmitter.h"
#include "ProgramOpcode.h"
#include "ProgramBinary.h"
#include "IErrorReporter.h"
#include <QCoreApplication>

CodeEmitter::CodeEmitter()
{
}

CodeEmitter::~CodeEmitter()
{
}

bool CodeEmitter::resolveAddresses(IErrorReporter* reporter, quint32& address) const
{
    for (auto& opcode : mOpcodes) {
        quint32 old = address;
        opcode->resolveAddress(address, reporter);
        Q_ASSERT(address == old + opcode->lengthInBytes());
        if (address > 0xFFFF) {
            reporter->error(opcode->token().file, opcode->token().line, QCoreApplication::tr("address is over 64K"));
            return false;
        }
    }

    return true;
}

void CodeEmitter::emitCode(Program* program, ProgramBinary* binary, IErrorReporter* reporter) const
{
    for (auto& opcode : mOpcodes) {
        unsigned old = binary->endAddress();
        opcode->emitBinary(program, binary, reporter);
        Q_ASSERT(binary->endAddress() == old + opcode->lengthInBytes());
    }
}
