#include "3rdparty/catch.hpp"
#include "helpers/DataBlob.h"
#include "helpers/ErrorConsumer.h"
#include "helpers/TestUtil.h"

TEST_CASE("addition", "[expr]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "ld hl, 5+0x10\n"
        ;

    static const unsigned char binary[] = {
        0x21,
        0x15,
        0x00,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("subtraction", "[expr]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "ld hl, 5-1\n"
        "ld hl, 5-5\n"
        "ld hl, 5-6\n"
        "ld hl, 10-8-1\n"
        ;

    static const unsigned char binary[] = {
        0x21,
        0x04,
        0x00,
        0x21,
        0x00,
        0x00,
        0x21,
        0xff,
        0xff,
        0x21,
        0x01,
        0x00,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("negation", "[expr]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "ld hl, -0\n"
        "ld hl, -1\n"
        "ld hl, -0x8000\n"
        ;

    static const unsigned char binary[] = {
        0x21,
        0x00,
        0x00,
        0x21,
        0xff,
        0xff,
        0x21,
        0x00,
        0x80,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("parentheses", "[expr]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "ld hl, +(4)\n"
        "ld hl, +(1-4)\n"
        "ld hl, 1+(5-3)\n"
        ;

    static const unsigned char binary[] = {
        0x21,
        0x04,
        0x00,
        0x21,
        0xFD,
        0xFF,
        0x21,
        0x03,
        0x00,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}
