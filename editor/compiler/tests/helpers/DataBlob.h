#ifndef COMPILER_TESTS_HELPERS_DATABLOB_H
#define COMPILER_TESTS_HELPERS_DATABLOB_H

#include <string>
#include <unordered_map>
#include <ostream>

class DataBlob
{
public:
    DataBlob();
    DataBlob(const void* data, size_t length);
    DataBlob(DataBlob&& other) = default;
    ~DataBlob();

    DataBlob& operator=(DataBlob&& other) = default;

    const std::string& data() const { return mData; }

    bool hasFiles() const { return !mFileData.empty(); }
    int numFiles() const { return int(mFileData.size()); }
    const DataBlob& fileData(const std::string& fileName) const;
    void setFileData(const std::string& fileName, DataBlob blob);

    bool operator==(const DataBlob& other) const { return mData == other.mData; }
    bool operator!=(const DataBlob& other) const { return mData != other.mData; }

private:
    std::string mData;
    std::unordered_map<std::string, DataBlob> mFileData;
};

std::ostream& operator<<(std::ostream& stream, const DataBlob& str);

#endif
