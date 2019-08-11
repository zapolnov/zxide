#include "3rdparty/catch.hpp"
#include "DataBlob.h"
#include "ErrorConsumer.h"
#include "TestUtil.h"

TEST_CASE("forward label", "[expr]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "ld hl, fwdlabel\n"
        "fwdlabel:\n"
        ;

    static const unsigned char binary[] = {
        0x21,
        0x03,
        0x01,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("backward label", "[expr]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "backlabel:\n"
        "ld hl, backlabel\n"
        ;

    static const unsigned char binary[] = {
        0x21,
        0x00,
        0x01,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("duplicate label", "[label]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "label1: nop\n"
        "label1: nop\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "duplicate identifier 'label1'");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("local labels", "[label]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "test@@1:\n"
        "nonlocal1:\n"
        "@@1: ld hl, @@1\n"
        "ld hl, nonlocal1@@1\n"
        "ld hl, nonlocal2@@1\n"
        "nonlocal2:\n"
        "@@1: ld hl, @@1\n"
        "ld hl, nonlocal1@@1\n"
        "ld hl, nonlocal2@@1\n"
        "ld hl, test@@1\n"
        "nonlocal2@@2:\n"
        "test@@3:\n"
        "ld hl, test@@3\n"
        "ld hl, nonlocal2@@2\n"
        ;

    static const unsigned char binary[] = {
        0x21,
        0x00,
        0x01,
        0x21,
        0x00,
        0x01,
        0x21,
        0x09,
        0x01,
        0x21,
        0x09,
        0x01,
        0x21,
        0x00,
        0x01,
        0x21,
        0x09,
        0x01,
        0x21,
        0x00,
        0x01,
        0x21,
        0x15,
        0x01,
        0x21,
        0x15,
        0x01,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("duplicate local label", "[label]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "nonlocal: nop\n"
        "@@1: nop\n"
        "@@1: nop\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "duplicate identifier 'nonlocal@@1'");
    REQUIRE(errorConsumer.lastErrorLine() == 4);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("duplicate full local label", "[label]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "nonlocal: nop\n"
        "@@1: nop\n"
        "nonlocal@@1: nop\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "duplicate identifier 'nonlocal@@1'");
    REQUIRE(errorConsumer.lastErrorLine() == 4);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("local without global", "[label]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "@@1: nop\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "found local label name without previous global label");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("label arithmetics", "[expr]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "ld hl, fwdlabel+1\n"
        "ld hl, fwdlabel-3+1\n"
        "fwdlabel:\n"
        ;

    static const unsigned char binary[] = {
        0x21,
        0x07,
        0x01,
        0x21,
        0x04,
        0x01,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}
