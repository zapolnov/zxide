#ifndef COMPILER_COMPILESETTINGS_H
#define COMPILER_COMPILESETTINGS_H

#include <string>

struct CompileSettings
{
    std::string loaderName = "loader";
    std::string programName = "program";
    int basicStartLine = 10;
};

#endif
