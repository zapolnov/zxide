#ifndef COMPILER_UTIL_H
#define COMPILER_UTIL_H

#include <QString>
#include <string>

class IErrorReporter;

std::string toLower(std::string str);

bool writeFile(const QString& fileName, const void* data, size_t size, IErrorReporter* reporter);

#endif
