#include "ProgramOpcode.h"

ProgramOpcode::ProgramOpcode(File* file, int line)
    : mFile(file)
    , mLine(line)
{
}

ProgramOpcode::~ProgramOpcode()
{
}
