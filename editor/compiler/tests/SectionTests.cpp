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
    REQUIRE(errorConsumer.lastErrorMessage() == "program has no code in default file");
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("empty program 2", "[sections]")
{
    static const char source[] =
        "section main [file 'file3']\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "program has no code in default file");
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
    REQUIRE(errorConsumer.lastErrorMessage() == "no sections with base address in default file");
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("require section with base address in main file", "[sections]")
{
    static const char source[] =
        "section main\n"
        "db 0\n"
        "section file [file 'file1', base 0xc000]\n"
        "db 1\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "no sections with base address in default file");
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("base address for file", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "labl: dw labl\n"
        "section file [file 'file1', base 0xdeda]\n"
        "label: dw label\n"
        ;

    static const unsigned char binary_main[] = {
        0x34,
        0x12,
        };
    static const unsigned char binary_file1[] = {
        0xda,
        0xde,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_file1(binary_file1, sizeof(binary_file1));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.fileData("file1") == expected_file1);
    REQUIRE(actual.numFiles() == 1);
}

TEST_CASE("no default base address for file", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0xbb\n"
        "section file [file 'file1', base 0xc000]\n"
        "label: dw label\n"
        ;

    static const unsigned char binary_main[] = {
        0xbb,
        };
    static const unsigned char binary_file1[] = {
        0x00,
        0xc0,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_file1(binary_file1, sizeof(binary_file1));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.fileData("file1") == expected_file1);
    REQUIRE(actual.numFiles() == 1);
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
    REQUIRE(!actual.hasFiles());
}

TEST_CASE("multiple declaration of section", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0\n"
        "section other [align 2]\n"
        "section main [align 2]\n"
        "section main\n"
        "section other [base 0x1236]\n"
        "section other\n"
        "section file1 [file 'file1', base 0x9000]\n"
        "section file1\n"
        "db 2\n"
        "section file3\n"
        "section file3 [file 'file3', base 0x8000]\n"
        "db 4\n"
        ;

    static const unsigned char binary_main[] = {
        0x00,
        };
    static const unsigned char binary_file1[] = {
        0x02,
        };
    static const unsigned char binary_file3[] = {
        0x04,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_file1(binary_file1, sizeof(binary_file1));
    DataBlob expected_file3(binary_file3, sizeof(binary_file3));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.fileData("file1") == expected_file1);
    REQUIRE(actual.fileData("file3") == expected_file3);
    REQUIRE(actual.numFiles() == 2);
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
    REQUIRE(!actual.hasFiles());
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
    REQUIRE(!actual.hasFiles());
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
    REQUIRE(!actual.hasFiles());
}

TEST_CASE("section base multiple specification", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "section main [base 0x1236]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "multiple specification of base address for section 'main'");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("section alignment multiple specification", "[sections]")
{
    static const char source[] =
        "section main [align 2]\n"
        "section main [align 4]\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "multiple specification of alignment for section 'main'");
    REQUIRE(errorConsumer.lastErrorLine() == 2);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("can't change section file", "[sections]")
{
    static const char source[] =
        "section dummy [base 0x1234]\n"
        "section main [file 'file1', base 0x4321]\n"
        "section main [file 'file3']\n"
        "db 0\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "conflicting file name for section 'main' ('file3' != 'file1')");
    REQUIRE(errorConsumer.lastErrorLine() == 3);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("alignment conflicts with base", "[sections]")
{
    static const char source[] =
        "section main [base 0x1235]\n"
        "section main [align 2]\n"
        "db 0\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "base address 0x1235 of section 'main' is not aligned to 2");
    REQUIRE(errorConsumer.lastErrorLine() == 1);
    REQUIRE(errorConsumer.errorCount() == 1);
}

TEST_CASE("base conflicts with alignment", "[sections]")
{
    static const char source[] =
        "section main [align 2]\n"
        "section main [base 0x1235]\n"
        "db 0\n"
        ;

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    REQUIRE(errorConsumer.lastErrorMessage() == "base address 0x1235 of section 'main' is not aligned to 2");
    REQUIRE(errorConsumer.lastErrorLine() == 1);
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
    REQUIRE(!actual.hasFiles());
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
    REQUIRE(!actual.hasFiles());
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
    REQUIRE(!actual.hasFiles());
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
    REQUIRE(!actual.hasFiles());
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

TEST_CASE("sections could overlap with files", "[sections]")
{
    static const char source[] =
        "section main [base 0xc000]\n"
        "db 0xaa\n"
        "section sec1 [base 0xc000, file 'file1']\n"
        "db 0xbb\n"
        ;

    static const unsigned char binary_main[] = {
        0xaa,
        };
    static const unsigned char binary_file1[] = {
        0xbb,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_file1(binary_file1, sizeof(binary_file1));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.fileData("file1") == expected_file1);
    REQUIRE(actual.numFiles() == 1);
}

TEST_CASE("section files 1", "[sections]")
{
    static const char source[] =
        "section sec0 [base 0xbfff]\n"
        "db 0xaa\n"
        "section sec1 [file 'file3', base 0xc000]\n"
        "db 0xbb\n"
        "section sec2 [base 0xc001, file 'file3']\n"
        "db 0xcc\n"
        "section sec3 [file 'file4', base 0xc002]\n"
        "db 0xdd\n"
        "section sec4 [base 0xc003, file 'file4']\n"
        "db 0xee\n"
        "section sec5 [file 'file6', base 0x1234]\n"
        "db 0xff\n"
        ;

    static const unsigned char binary_main[] = {
        0xaa,
        };
    static const unsigned char binary_file3[] = {
        0xbb,
        0xcc,
        };
    static const unsigned char binary_file4[] = {
        0xdd,
        0xee,
        };
    static const unsigned char binary_file6[] = {
        0xff,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_file3(binary_file3, sizeof(binary_file3));
    DataBlob expected_file4(binary_file4, sizeof(binary_file4));
    DataBlob expected_file6(binary_file6, sizeof(binary_file6));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.fileData("file3") == expected_file3);
    REQUIRE(actual.fileData("file4") == expected_file4);
    REQUIRE(actual.fileData("file6") == expected_file6);
    REQUIRE(actual.numFiles() == 3);
}

TEST_CASE("section files 2", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0xcc\n"
        "section file1_start [file 'file1', base 0xc000]\n"
        "db 1\n"
        "section file1_end [file 'file1', base 0xffff]\n"
        "db 1\n"
        "section file3_start [file 'file3', base 0xc000]\n"
        "db 1\n"
        "section file3_end [file 'file3', base 0xffff]\n"
        "db 1\n"
        "section file4_start [file 'file4', base 0xc000]\n"
        "db 1\n"
        "section file4_end [file 'file4', base 0xffff]\n"
        "db 1\n"
        "section file6_start [file 'file6', base 0xc000]\n"
        "db 1\n"
        "section file6_end [file 'file6', base 0xffff]\n"
        "db 1\n"
        "section file7_start [file 'file7', base 0xc000]\n"
        "db 1\n"
        "section file7_end [file 'file7', base 0xffff]\n"
        "db 1\n"
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
    REQUIRE(actual.numFiles() == 5);
}

TEST_CASE("sections can overlap in different files", "[sections]")
{
    static const char source[] =
        "section main [base 0x1234]\n"
        "db 0xaa\n"
        "section sec1 [file 'file3', base 0xc800]\n"
        "db 0xbb\n"
        "section sec2 [file 'file4', base 0xc800]\n"
        "db 0xcc\n"
        ;

    static const unsigned char binary_main[] = {
        0xaa,
        };
    static const unsigned char binary_file3[] = {
        0xbb,
        };
    static const unsigned char binary_file4[] = {
        0xcc,
        };

    ErrorConsumer errorConsumer;
    DataBlob actual = assemble(errorConsumer, source);
    DataBlob expected_main(binary_main, sizeof(binary_main));
    DataBlob expected_file3(binary_file3, sizeof(binary_file3));
    DataBlob expected_file4(binary_file4, sizeof(binary_file4));
    REQUIRE(errorConsumer.lastErrorMessage() == "");
    REQUIRE(errorConsumer.errorCount() == 0);
    REQUIRE(actual == expected_main);
    REQUIRE(actual.fileData("file3") == expected_file3);
    REQUIRE(actual.fileData("file4") == expected_file4);
    REQUIRE(actual.numFiles() == 2);
}

// FIXME: test imaginary sections
// FIXME: test compression modes
