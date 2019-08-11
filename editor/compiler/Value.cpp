#include "Value.h"

Value::Value()
    : number(0)
    , sign(Sign::Unsigned)
    , bits(SignificantBits::NoMoreThan8)
{
}

Value::Value(qint64 n)
    : number(n)
    , sign(n < 0 ? Sign::Signed : Sign::Unsigned)
    , bits(significantBitsForNumber(n))
{
}

Value::Value(qint64 n, Sign sign)
    : number(n)
    , sign(sign)
    , bits(significantBitsForNumber(n))
{
}

Value::Value(qint64 n, Sign sign, SignificantBits b)
    : number(n)
    , sign(sign)
    , bits(b)
{
}

void Value::truncateTo8Bit()
{
    if (sign == Sign::Signed)
        number = qint64(qint8(number & 0xff));
    else
        number = qint64(quint8(number & 0xff));
}

void Value::truncateTo16Bit()
{
    if (sign == Sign::Signed)
        number = qint64(qint16(number & 0xffff));
    else
        number = qint64(quint16(number & 0xffff));
}

void Value::truncateToSignificantBits()
{
    switch (bits) {
        case SignificantBits::NoMoreThan8: truncateTo8Bit(); return;
        case SignificantBits::NoMoreThan16: truncateTo16Bit(); return;
    }
}

SignificantBits Value::significantBitsForNumber(qint64 n)
{
    if (n >= -128 && n < 256)
        return SignificantBits::NoMoreThan8;
    else if (n >= -32768 && n < 65536)
        return SignificantBits::NoMoreThan16;
    else
        return SignificantBits::All;
}

SignificantBits Value::significantBitsForNumber16(qint64 n)
{
    if (n >= -32768 && n < 65536)
        return SignificantBits::NoMoreThan16;
    else
        return SignificantBits::All;
}
