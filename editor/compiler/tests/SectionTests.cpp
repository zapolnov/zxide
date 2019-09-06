#include "3rdparty/catch.hpp"
#include "helpers/DataBlob.h"
#include "helpers/ErrorConsumer.h"
#include "helpers/TestUtil.h"

TEST_CASE("empty program 1", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "program has no code in primary memory space");
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("empty program 2", "[sections]")
{
    static const char source[] =
        "section main [bank 3]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "program has no code in primary memory space");
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("require section with base address", "[sections]")
{
    static const char source[] =
        "section main\n"
        "db 0\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "no sections with base address in primary memory space");
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("require section with base address in primary memory space", "[sections]")
{
    static const char source[] =
        "section main\n"
        "db 0\n"
        "section bank [bank 1, base 0xc000]\n"
        "db 1\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "no sections with base address in primary memory space");
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("base address for bank", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "labl: dw labl\n"
        "section bank [bank 1, base 0xdeda]\n"
        "label: dw label\n"
        ;

    static const unsigned char binary_main[] = {
        0x34,
        0x12,
        };
    static const unsigned char binary_bank1[] = {
        0xda,
        0xde,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_bank1(binary_bank1, sizeof(binary_bank1));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.bankData(1) == expected_bank1);
    REQUIRE(actual.numBanks() == 1);
}

TEST_CASE("default base address for bank", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0xbb\n"
        "section bank [bank 1]\n"
        "label: dw label\n"
        ;

    static const unsigned char binary_main[] = {
        0xbb,
        };
    static const unsigned char binary_bank1[] = {
        0x00,
        0xc0,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_bank1(binary_bank1, sizeof(binary_bank1));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.bankData(1) == expected_bank1);
    REQUIRE(actual.numBanks() == 1);
}

TEST_CASE("default base address with alignment for bank", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0xcc\n"
        "section bank [bank 1, align 5]\n" // (0xC000 = 49152) % 5 != 0
        "label1: dw label1\n"
        "section abank [bank 1]\n"
        "label2: dw label2\n"
        ;

    static const unsigned char binary_main[] = {
        0xcc,
        };
    static const unsigned char binary_bank1[] = {
        0x03, // (0xC003 = 49155) % 5 == 0
        0xc0,
        0x05,
        0xc0,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_bank1(binary_bank1, sizeof(binary_bank1));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.bankData(1) == expected_bank1);
    REQUIRE(actual.numBanks() == 1);
}

TEST_CASE("label in empty section", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "dw label\n"
        "section empty [align 16]\n"
        "label:\n"
        ;

    static const unsigned char binary[] = {
        0x40,
        0x12,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
    REQUIRE(!actual.hasBanks());
}

TEST_CASE("multiple declaration of section", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0\n"
        "section other [align 2]\n"
        "section main [base 0x1234]\n"
        "section other [align 2]\n"
        "section main [align 2]\n"
        "section main\n"
        "section other [base 0x1236]\n"
        "section other\n"
        "section bank1 [bank 1]\n"
        "section bank1\n"
        "section bank3\n"
        "section bank3 [bank 3]\n"
        ;

    static const unsigned char binary[] = {
        0x00,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
    REQUIRE(!actual.hasBanks());
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
        0x00,
        0x00,
        0x00,
        0x00,
        0x49,
        0x52,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
    REQUIRE(!actual.hasBanks());
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
    REQUIRE(!actual.hasBanks());
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
    REQUIRE(!actual.hasBanks());
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

TEST_CASE("can't change section bank", "[sections]")
{
    static const char source[] =
        "section dummy [base 0x1234]\n"
        "section main [bank 1]\n"
        "section main [bank 3]\n"
        "db 0\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "conflicting bank for section 'main' (3 != 1)");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
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
    REQUIRE(!actual.hasBanks());
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
    REQUIRE(!actual.hasBanks());
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
    REQUIRE(!actual.hasBanks());
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

TEST_CASE("nearby sections", "[sections]")
{
    static const char source[] =
        "section sec1 [base 0x1000]\n"
        "db 0xbb\n"
        "section sec2 [base 0x1001]\n"
        "db 0xdd\n"
        ;

    static const unsigned char binary[] = {
        0xbb,
        0xdd,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
    REQUIRE(!actual.hasBanks());
}

TEST_CASE("sections shouldn't overlap", "[sections]")
{
    static const char source[] =
        "section sec1 [base 0x1000]\n"
        "db 0xbb,0xcc\n"
        "section sec2 [base 0x1001]\n"
        "db 0xdd\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "section 'sec2' overlaps with address 0x1001 which belongs to another section");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("sections shouldn't overlap with banks", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0xaa\n"
        "section sec1 [base 0xc000, bank 1]\n"
        "db 0xbb\n"
        "section sec2 [base 0xc000, bank 1]\n"
        "db 0xbb\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "section 'sec2' overlaps with address 0xc000 which belongs to another section");
    REQUIRE(errorConsumer.lastErrorLine() == 5);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("sections could overlap with banks", "[sections]")
{
    static const char source[] =
        "section main [base 0xc000]\n"
        "db 0xaa\n"
        "section sec1 [base 0xc000, bank 1]\n"
        "db 0xbb\n"
        ;

    static const unsigned char binary_main[] = {
        0xaa,
        };
    static const unsigned char binary_bank1[] = {
        0xbb,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_bank1(binary_bank1, sizeof(binary_bank1));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.bankData(1) == expected_bank1);
    REQUIRE(actual.numBanks() == 1);
}

TEST_CASE("section banks 1", "[sections]")
{
    static const char source[] =
        "section sec0 [base 0xbfff]\n"
        "db 0xaa\n"
        "section sec1 [bank 3, base 0xc000]\n"
        "db 0xbb\n"
        "section sec2 [base 0xc001, bank 3]\n"
        "db 0xcc\n"
        "section sec3 [bank 4, base 0xc002]\n"
        "db 0xdd\n"
        "section sec4 [base 0xc003, bank 4]\n"
        "db 0xee\n"
        "section sec5 [bank 6]\n"
        "db 0xff\n"
        ;

    static const unsigned char binary_main[] = {
        0xaa,
        };
    static const unsigned char binary_bank3[] = {
        0xbb,
        0xcc,
        };
    static const unsigned char binary_bank4[] = {
        0xdd,
        0xee,
        };
    static const unsigned char binary_bank6[] = {
        0xff,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_bank3(binary_bank3, sizeof(binary_bank3));
    DataBlob expected_bank4(binary_bank4, sizeof(binary_bank4));
    DataBlob expected_bank6(binary_bank6, sizeof(binary_bank6));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.bankData(3) == expected_bank3);
    REQUIRE(actual.bankData(4) == expected_bank4);
    REQUIRE(actual.bankData(6) == expected_bank6);
    REQUIRE(actual.numBanks() == 3);
}

TEST_CASE("section banks 2", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0xcc\n"
        "section bank1_start [bank 1, base 0xc000]\n"
        "section bank1_end [bank 1, base 0xffff]\n"
        "section bank3_start [bank 3, base 0xc000]\n"
        "section bank3_end [bank 3, base 0xffff]\n"
        "section bank4_start [bank 4, base 0xc000]\n"
        "section bank4_end [bank 4, base 0xffff]\n"
        "section bank6_start [bank 6, base 0xc000]\n"
        "section bank6_end [bank 6, base 0xffff]\n"
        "section bank7_start [bank 7, base 0xc000]\n"
        "section bank7_end [bank 7, base 0xffff]\n"
        ;

    static const unsigned char binary[] = {
        0xcc,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected(binary, sizeof(binary));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected);
    REQUIRE(!actual.hasBanks());
}

TEST_CASE("sections can overlap in different banks", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0xaa\n"
        "section sec1 [bank 3, base 0xc800]\n"
        "db 0xbb\n"
        "section sec2 [bank 4, base 0xc800]\n"
        "db 0xcc\n"
        ;

    static const unsigned char binary_main[] = {
        0xaa,
        };
    static const unsigned char binary_bank3[] = {
        0xbb,
        };
    static const unsigned char binary_bank4[] = {
        0xcc,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_bank3(binary_bank3, sizeof(binary_bank3));
    DataBlob expected_bank4(binary_bank4, sizeof(binary_bank4));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.bankData(3) == expected_bank3);
    REQUIRE(actual.bankData(4) == expected_bank4);
    REQUIRE(actual.numBanks() == 2);
}

TEST_CASE("disallow bank 0", "[sections]")
{
    static const char source[] =
        "section sec1 [base 0xC000, bank 0]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "invalid bank 0");
    REQUIRE(errorConsumer.lastErrorLine() == 1);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("disallow bank 2", "[sections]")
{
    static const char source[] =
        "section sec1 [base 0xC000, bank 2]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "invalid bank 2");
    REQUIRE(errorConsumer.lastErrorLine() == 1);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("disallow bank 5", "[sections]")
{
    static const char source[] =
        "section sec1 [base 0xC000, bank 5]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "invalid bank 5");
    REQUIRE(errorConsumer.lastErrorLine() == 1);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("section bank invalid address", "[sections]")
{
    static const char source[] =
        "section sec1 [base 0x8000, bank 6]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "invalid base address 0x8000 for section 'sec1' in bank 6");
    REQUIRE(errorConsumer.lastErrorLine() == 1);
    REQUIRE(errorConsumer.errorCount() == 1);
}
