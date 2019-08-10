#ifndef COMPILER_TESTS_TESTUTIL_H
#define COMPILER_TESTS_TESTUTIL_H

class DataBlob;
class IErrorReporter;

DataBlob assemble(IErrorReporter& errorConsumer, const char* source);

#endif
