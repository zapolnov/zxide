#ifndef COMPILER_VALUE_H
#define COMPILER_VALUE_H

#include <QtGlobal>

enum class Sign
{
    Signed,
    Unsigned,
};

enum class SignificantBits
{
    // note: order of constants is important
    NoMoreThan8 = 0,
    NoMoreThan16 = 1,
    All = 2,
};

struct Value
{
    qint64 number;
    Sign sign;
    SignificantBits bits;

    Value();
    explicit Value(qint64 n);
    Value(qint64 n, Sign sign);
    Value(qint64 n, Sign sign, SignificantBits b);

    void truncateTo8Bit();
    void truncateTo16Bit();
    void truncateTo32Bit();
    void truncateToSignificantBits();

    static SignificantBits significantBitsForNumber(qint64 n);
    static SignificantBits significantBitsForNumber16(qint64 n);
};

#endif
