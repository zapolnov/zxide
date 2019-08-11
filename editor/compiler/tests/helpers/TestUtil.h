#ifndef COMPILER_TESTS_HELPERS_TESTUTIL_H
#define COMPILER_TESTS_HELPERS_TESTUTIL_H

class DataBlob;
class IErrorReporter;

DataBlob assemble(IErrorReporter& errorConsumer, const char* source);
DataBlob assemble2(IErrorReporter& errorConsumer, const char* source1, const char* source2);

#endif
