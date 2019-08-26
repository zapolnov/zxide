#include "3rdparty/catch.hpp"
#include "helpers/DataBlob.h"
#include "helpers/ErrorConsumer.h"
#include "helpers/TestUtil.h"

TEST_CASE("multiple declaration of section", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "section other [align 2]\n"
        "section main [base 0x1234]\n"
        "section other [align 2]\n"
        "section main [align 2]\n"
        "section main\n"
        "section other [base 0x1236]\n"
        "section other\n"
        ;

    static const unsigned char binary[] = {
        0x00,
        0x00,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("section alignment", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "ld a,a\n"
        "section other [align 8]\n"
        "ld b,b\n"
        "section other2 [align 7]\n"
        "ld c,c\n"
        "section other1 [align 1]\n"
        "ld d,d\n"
        ;

    static const unsigned char binary[] = {
        0x7f,
        0x00,
        0x00,
        0x00,
        0x40,
        0x52,
        0x00,
        0x00,
        0x00,
        0x49,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("section padding", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "ld a,a\n"
        "section other [base 0x1238]\n"
        "ld b,b\n"
        ;

    static const unsigned char binary[] = {
        0x7f,
        0x00,
        0x00,
        0x00,
        0x40,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("section ordering", "[sections]")
{
    static const char source1[] =
        "section a [base 0x1000]\n"
        "ld c,c\n"
        "section b [base 0x0fff]\n"
        "ld a,a\n"
        "section d\n"
        "section c\n"
        "section z\n"
        "ld e,e\n"
        "section e\n"
        "ld h,h\n"
        ;

    static const char source2[] =
        "section d [base 0x1001]\n"
        "ld b,b\n"
        "section c\n"
        "ld d,d\n"
        ;

    static const unsigned char binary[] = {
        0x7f,
        0x49,
        0x40,
        0x52,
        0x64,
        0x5b,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble2(errorConsumer, source1, source2);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("can't change section base", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "section main [base 0x1236]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "conflicting base address for section 'main' (0x1236 != 0x1234)");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("can't change section alignment", "[sections]")
{
    static const char source[] =
        "section main [align 2]\n"
        "section main [align 4]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "conflicting alignment for section 'main' (4 != 2)");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("alignment conflicts with base", "[sections]")
{
    static const char source[] =
        "section main [base 0x1235]\n"
        "section main [align 2]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "base address 0x1235 of section 'main' is not aligned to 2");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("base conflicts with alignment", "[sections]")
{
    static const char source[] =
        "section main [align 2]\n"
        "section main [base 0x1235]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "base address 0x1235 of section 'main' is not aligned to 2");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("last byte fits well 1", "[sections]")
{
    static const char source[] =
        "section main [base 0xffff]\n"
        "db 0xc3\n"
        ;

    static const unsigned char binary[] = {
        0xc3,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("last byte fits well 2", "[sections]")
{
    static const char source[] =
        "section main [base 0xffff]\n"
        "repeat 1\n"
        "db 0xeb\n"
        "endrepeat\n"
        "repeat 0\n"
        "db 0xbf\n"
        "endrepeat\n"
        ;

    static const unsigned char binary[] = {
        0xeb,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("last byte fits well 3", "[sections]")
{
    static const char source[] =
        "section main [base 0xffff]\n"
        "if 1\n"
        "db 0xa4\n"
        "endif\n"
        "if 0\n"
        "db 0xbb\n"
        "endif\n"
        ;

    static const unsigned char binary[] = {
        0xa4,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
}

TEST_CASE("address is too large 1", "[sections]")
{
    static const char source[] =
        "section main [base 0xffff]\n"
        "db 0xcc\n"
        "db 0xee\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "address is over 64K");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("address is too large 2", "[sections]")
{
    static const char source[] =
        "section main [base 0xffff]\n"
        "repeat 2\n"
        "db 0xcc\n"
        "endrepeat\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "address is over 64K");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("address is too large 3", "[sections]")
{
    static const char source[] =
        "section main [base 0xffff]\n"
        "db 0xbb\n"
        "if 1\n"
        "db 0xee\n"
        "endif\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "address is over 64K");
    REQUIRE(errorConsumer.lastErrorLine() == 4);
    REQUIRE(errorConsumer.errorCount() == 1);
}
