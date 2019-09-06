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

    bool hasBanks() const { return !mBankData.empty(); }
    int numBanks() const { return int(mBankData.size()); }
    const DataBlob& bankData(int index) const;
    void setBankData(int index, DataBlob blob);

    bool operator==(const DataBlob& other) const { return mData == other.mData; }
    bool operator!=(const DataBlob& other) const { return mData != other.mData; }

private:
    std::string mData;
    std::unordered_map<int, DataBlob> mBankData;
};

std::ostream& operator<<(std::ostream& stream, const DataBlob& str);

#endif
