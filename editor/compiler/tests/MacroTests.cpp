#include "3rdparty/catch.hpp"
#include "helpers/DataBlob.h"
#include "helpers/ErrorConsumer.h"
#include "helpers/TestUtil.h"

TEST_CASE("repeat", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "repeat 5\n"
        "db 0x01\n"
        "endrepeat\n"
        "repeat 2\n"
        "db 0x1b\n"
        "repeat 3\n"
        "db 0x2a\n"
        "endrepeat\n"
        "endrepeat\n"
        ;

    static const unsigned char binary[] = {
        0x01,
        0x01,
        0x01,
        0x01,
        0x01,
        0x1b,
        0x2a,
        0x2a,
        0x2a,
        0x1b,
        0x2a,
        0x2a,
        0x2a,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("repeat with counter", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "repeat 3, cnt\n"
        "db cnt\n"
        "endrepeat\n"
        "repeat 5, cnt\n"
        "db cnt + 9\n"
        "endrepeat\n"
        "repeat 3, cnt1\n"
        "db 0x80|cnt1\n"
        "repeat 4, cnt2\n"
        "db (cnt1+1)*(cnt2+1)\n"
        "endrepeat\n"
        "repeat 1\n"
        "db 0xff\n"
        "endrepeat\n"
        "endrepeat\n"
        ;

    static const unsigned char binary[] = {
        0x00,
        0x01,
        0x02,
        0x09,
        0x0a,
        0x0b,
        0x0c,
        0x0d,
        0x80,
        0x01,
        0x02,
        0x03,
        0x04,
        0xff,
        0x81,
        0x02,
        0x04,
        0x06,
        0x08,
        0xff,
        0x82,
        0x03,
        0x06,
        0x09,
        0x0c,
        0xff,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("non-conflicting name in repeat", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "db 0x30\n"
        "repeat 0, cnt\n"
        "db 0x14\n"
        "endrepeat\n"
        "cnt:\n"
        "db 0x40\n"
        ;

    static const unsigned char binary[] = {
        0x30,
        0x40,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("conflicting name in repeat 1", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "label1:\n"
        "repeat 5, label1\n"
        "endrepeat\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "duplicate identifier 'label1'");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("conflicting name in repeat 2", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "repeat 5, label1\n"
        "label1:\n"
        "endrepeat\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "duplicate identifier 'label1'");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("conflicting name in repeat 3", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "count equ 4\n"
        "repeat 5, count\n"
        "endrepeat\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "duplicate identifier 'count'");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("conflicting name in inner repeat", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "repeat 5, cnt1\n"
        "repeat 3, cnt1\n"
        "endrepeat\n"
        "endrepeat\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "duplicate identifier 'cnt1'");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("equ in repeat", "[macros]")
{
    static const char source1[] =
        "section main [base 0x100]\n"
        "db 0xaa,counter\n"
        "section main1\n"
        "db 0xbb,counter\n"
        "section main2\n"
        "db 0xee,counter\n"
        ;

    static const char source2[] =
        "section main1\n"
        "db 0xcc,counter\n"
        "repeat 4, cnt\n"
        "counter equ cnt*2+1\n"
        "db counter\n"
        "endrepeat\n"
        "db 0x88,counter\n"
        ;

    static const char source3[] =
        "section main1\n"
        "db 0xdd,counter\n"
        "section main2\n"
        "db 0xff,counter\n"
        ;

    static const unsigned char binary[] = {
        0xaa,
        0x07,
        0xbb,
        0x07,
        0xcc,
        0x07,
        0x01,
        0x03,
        0x05,
        0x07,
        0x88,
        0x07,
        0xdd,
        0x07,
        0xee,
        0x07,
        0xff,
        0x07,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble3(errorConsumer, source1, source2, source3);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("expression as repeat counter", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "count equ 4+(10/2)-3\n"
        "repeat count, cnt\n"
        "db cnt+0x40\n"
        "repeat cnt, cnt2\n"
        "db cnt2|0x80\n"
        "endrepeat\n"
        "endrepeat\n"
        ;

    static const unsigned char binary[] = {
        0x40,
        0x41,
        0x80,
        0x42,
        0x80,
        0x81,
        0x43,
        0x80,
        0x81,
        0x82,
        0x44,
        0x80,
        0x81,
        0x82,
        0x83,
        0x45,
        0x80,
        0x81,
        0x82,
        0x83,
        0x84,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("missing endrepeat", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "repeat 5\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "missing 'endrepeat'");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("negative repeat count", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "repeat -1\n"
        "endrepeat\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "invalid repeat count");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
}

TEST_CASE("too large repeat count", "[macros]")
{
    static const char source[] =
        "section main [base 0x100]\n"
        "repeat 0x10000\n"
        "endrepeat\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "invalid repeat count");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
}

// FIXME: test for global and local labels inside repeat macro
