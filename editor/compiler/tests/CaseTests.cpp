#include "3rdparty/catch.hpp"
#include "helpers/DataBlob.h"
#include "helpers/ErrorConsumer.h"
#include "helpers/TestUtil.h"

TEST_CASE("case insensitivity in instructions and operands", "[case]")
{
    static const char source[] =
        "SeCtIoN main [base 0x1234]\n"
        "x eQu 43\n"
        "y eqU 85\n"
        "Adc A, (Ix-x)\n"
        "aDc a, (iX+y)\n"
        "adD hL, Sp\n"
        "sEt 0, (HL)\n"
        "ex Af, aF'\n"
        ;

    static const unsigned char binary[] = {
        0xdd,
        0x8e,
        0xd5,
        0xdd,
        0x8e,
        0x55,
        0x39,
        0xcb,
        0xc6,
        0x08,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("case sensitivity in names", "[case]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "section mAiN [base 0x1235]\n"
        "equ1 equ 1\n"
        "eQu1 equ 2\n"
        "label1:\n"
        "ld hl, label1\n"
        "lAbEl1:\n"
        "ld hl, lAbEl1\n"
        "ld hl, equ1\n"
        "ld hl, eQu1\n"
        ;

    static const unsigned char binary[] = {
        0x00,
        0x21,
        0x35,
        0x12,
        0x21,
        0x38,
        0x12,
        0x21,
        0x01,
        0x00,
        0x21,
        0x02,
        0x00,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}
