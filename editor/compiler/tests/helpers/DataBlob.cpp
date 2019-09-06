#include "DataBlob.h"

static const DataBlob dummy;

DataBlob::DataBlob()
{
}

DataBlob::DataBlob(const void* data, size_t length)
    : mData(reinterpret_cast<const char*>(data), length)
{
}

DataBlob::~DataBlob()
{
}

const DataBlob& DataBlob::bankData(int index) const
{
    auto it = mBankData.find(index);
    return (it != mBankData.end() ? it->second : dummy);
}

void DataBlob::setBankData(int index, DataBlob blob)
{
    mBankData[index] = std::move(blob);
}

std::ostream& operator<<(std::ostream& stream, const DataBlob& str)
{
    static const char hex[] = "0123456789abcdef";

    stream << '[';
    for (char ch : str.data()) {
        auto v = unsigned(static_cast<unsigned char>(ch));
        stream << ' ' << hex[v >> 4] << hex[v & 15];
    }
    stream << " ]";

    return stream;
}
