#ifndef COMPILER_BASICPROGRAM_H
#define COMPILER_BASICPROGRAM_H

#include <QtGlobal>
#include <map>
#include <sstream>
#include <string>

class BasicProgram
{
public:
    enum Token : quint8
    {
        TokRND = 0xA5,
        TokINKEYs = 0xA6, // INKEY$
        TokPI = 0xA7,
        TokFN = 0xA8,
        TokPOINT = 0xA9,
        TokSCREENs = 0xAA, // SCREEN$
        TokATTR = 0xAB,
        TokAT = 0xAC,
        TokTAB = 0xAD,
        TokVALs = 0xAE, // VAL$
        TokCODE = 0xAF,
        TokVAL = 0xB0,
        TokLEN = 0xB1,
        TokSIN = 0xB2,
        TokCOS = 0xB3,
        TokTAN = 0xB4,
        TokASN = 0xB5,
        TokACS = 0xB6,
        TokATN = 0xB7,
        TokLN = 0xB8,
        TokEXP = 0xB9,
        TokINT = 0xBA,
        TokSQR = 0xBB,
        TokSGN = 0xBC,
        TokABS = 0xBD,
        TokPEEK = 0xBE,
        TokIN = 0xBF,
        TokUSR = 0xC0,
        TokSTRs = 0xC1, // STR$
        TokCHRs = 0xC2, // CHR$
        TokNOT = 0xC3,
        TokBIN = 0xC4,
        TokOR = 0xC5,
        TokAND = 0xC6,
        TokLessEqual = 0xC7, // <=
        TokGreaterEqual = 0xC8, // >=
        TokNotEqual = 0xC9, // <>
        TokLINE = 0xCA,
        TokTHEN = 0xCB,
        TokTO = 0xCC,
        TokSTEP = 0xCD,
        TokDEFFN = 0xCE,
        TokCAT = 0xCF,
        TokFORMAT = 0xD0,
        TokMOVE = 0xD1,
        TokERASE = 0xD2,
        TokOPENx = 0xD3, // OPEN#
        TokCLOSEx = 0xD4, // CLOSE#
        TokMERGE = 0xD5,
        TokVERIFY = 0xD6,
        TokBEEP = 0xD7,
        TokCIRCLE = 0xD8,
        TokINK = 0xD9,
        TokPAPER = 0xDA,
        TokFLASH = 0xDB,
        TokBRIGHT = 0xDC,
        TokINVERSE = 0xDD,
        TokOVER = 0xDE,
        TokOUT = 0xDF,
        TokLPRINT = 0xE0,
        TokLLIST = 0xE1,
        TokSTOP = 0xE2,
        TokREAD = 0xE3,
        TokDATA = 0xE4,
        TokRESTORE = 0xE5,
        TokNEW = 0xE6,
        TokBORDER = 0xE7,
        TokCONTINUE = 0xE8,
        TokDIM = 0xE9,
        TokREM = 0xEA,
        TokFOR = 0xEB,
        TokGOTO = 0xEC,
        TokGOSUB = 0xED,
        TokINPUT = 0xEE,
        TokLOAD = 0xEF,
        TokLIST = 0xF0,
        TokLET = 0xF1,
        TokPAUSE = 0xF2,
        TokNEXT = 0xF3,
        TokPOKE = 0xF4,
        TokPRINT = 0xF5,
        TokPLOT = 0xF6,
        TokRUN = 0xF7,
        TokSAVE = 0xF8,
        TokRANDOMIZE = 0xF9,
        TokIF = 0xFA,
        TokCLS = 0xFB,
        TokDRAW = 0xFC,
        TokCLEAR = 0xFD,
        TokRETURN = 0xFE,
        TokCOPY = 0xFF,
    };

    struct Line
    {
    public:
        Line();
        ~Line();

        // high-level
        void CLEAR(unsigned address);
        void POKE(unsigned address, unsigned value);
        Line& LOAD(const char* name);
        void CODE();
        Line& RANDOMIZE();
        Line& USR(unsigned address);

        // low-level
        void writeByte(quint8 byte);
        void writeChar(char ch);
        void writeString(const char* str);
        void writeInt(int number);
        void writeUInt(unsigned number);

        std::string toBinary() const;

    private:
        std::stringstream mStream;

        Q_DISABLE_COPY(Line);
    };

    BasicProgram();
    ~BasicProgram();

    Line& line(int number);
    const Line& line(int number) const;

    std::string toBinary() const;

private:
    std::map<int, Line> mLines;

    Q_DISABLE_COPY(BasicProgram)
};

#endif
