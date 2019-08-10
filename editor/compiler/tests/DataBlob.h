#ifndef COMPILER_TESTS_DATABLOB_H
#define COMPILER_TESTS_DATABLOB_H

#include <string>
#include <ostream>

class DataBlob
{
public:
    DataBlob();
    DataBlob(const void* data, size_t length);
    ~DataBlob();

    const std::string& data() const { return mData; }

    bool operator==(const DataBlob& other) const { return mData == other.mData; }
    bool operator!=(const DataBlob& other) const { return mData != other.mData; }

private:
    std::string mData;
};

std::ostream& operator<<(std::ostream& stream, const DataBlob& str);

#endif
