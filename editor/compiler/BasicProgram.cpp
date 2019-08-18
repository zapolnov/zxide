#include "BasicProgram.h"

BasicProgram::Line::Line()
{
}

BasicProgram::Line::~Line()
{
}

void BasicProgram::Line::CLEAR(unsigned address)
{
    writeByte(TokCLEAR);
    writeUInt(address);
}

void BasicProgram::Line::POKE(unsigned address, unsigned value)
{
    writeByte(TokPOKE);
    writeUInt(address);
    writeChar(',');
    writeUInt(value);
}

BasicProgram::Line& BasicProgram::Line::LOAD(const char* name)
{
    writeByte(TokLOAD);
    writeChar('"');
    writeString(name);
    writeChar('"');
    return *this;
}

void BasicProgram::Line::CODE()
{
    writeByte(TokCODE);
}

BasicProgram::Line& BasicProgram::Line::RANDOMIZE()
{
    writeByte(TokRANDOMIZE);
    return *this;
}

BasicProgram::Line& BasicProgram::Line::USR(unsigned address)
{
    writeByte(TokUSR);
    writeUInt(address);
    return *this;
}

void BasicProgram::Line::writeByte(quint8 byte)
{
    mStream << static_cast<char>(byte);
}

void BasicProgram::Line::writeChar(char ch)
{
    mStream << ch;
}

void BasicProgram::Line::writeString(const char* str)
{
    mStream << str;
}

void BasicProgram::Line::writeInt(int number)
{
    Q_ASSERT(number >= -32768 && number <= 65535);
    mStream << number;
    mStream << '\x0E'; // number token
    mStream << '\x00';
    mStream << '\x00';
    mStream << static_cast<unsigned char>(number & 0xFF);
    mStream << static_cast<unsigned char>((number >> 8) & 0xFF);
    mStream << '\x00';
}

void BasicProgram::Line::writeUInt(unsigned number)
{
    Q_ASSERT(number <= 65535);
    writeInt(int(number));
}

std::string BasicProgram::Line::toBinary() const
{
    return mStream.str();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static const BasicProgram::Line emptyLine;

BasicProgram::BasicProgram()
{
}

BasicProgram::~BasicProgram()
{
}

BasicProgram::Line& BasicProgram::line(int number)
{
    Q_ASSERT(number >= 0 && number <= 9999);
    return mLines[number];
}

const BasicProgram::Line& BasicProgram::line(int number) const
{
    Q_ASSERT(number >= 0 && number <= 9999);
    auto it = mLines.find(number);
    return (it != mLines.end() ? it->second : emptyLine);
}

std::string BasicProgram::toBinary() const
{
    std::stringstream ss;
    for (const auto& it : mLines) {
        std::string lineData = it.second.toBinary();
        size_t lineLength = lineData.size() + 1;
        unsigned lineNumber = unsigned(it.first);
        // line number
        ss << static_cast<char>((lineNumber >> 8) & 0xFF);
        ss << static_cast<char>(lineNumber & 0xFF);
        // line length
        ss << static_cast<char>(lineLength & 0xFF);
        ss << static_cast<char>((lineLength >> 8) & 0xFF);
        // line data
        ss << lineData;
        // end-of-line marker
        ss << '\x0D';
    }
    return ss.str();
}
