#include "Assembler.h"
#include "AssemblerLexer.h"
#include "AssemblerParser.h"
#include "Compiler.h"
#include "Expression.h"
#include "ProjectSettings.h"
#include "IO.h"
#include "Util.h"
#include <sstream>
#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <QDir>
#include <QDataStream>

bool generateBlobs = false;

static std::vector<std::string> stringTable;
static std::unordered_map<std::string, uint16_t> stringMapping;
static size_t numPredefinedStrings;

static uint16_t stringId(const std::string& str)
{
    auto it = stringMapping.find(str);
    if (it != stringMapping.end())
        return it->second;

    it = stringMapping.find(toLower(str));
    if (it != stringMapping.end() && it->second < numPredefinedStrings)
        return it->second;

    if (stringTable.size() > 65535)
        throw std::runtime_error("precondition 2 failed.");
    uint16_t id = uint16_t(stringTable.size());
    stringMapping[str] = id;
    stringTable.emplace_back(str);
    return id;
}

static void initStringMapping()
{
    stringTable.clear();
    stringMapping.clear();

    stringId(std::string());
    stringId("a");
    stringId("align");
    stringId("adc");
    stringId("add");
    stringId("af");
    stringId("af'");
    stringId("and");
    stringId("b");
    stringId("base");
    stringId("bc");
    stringId("bit");
    stringId("c");
    stringId("call");
    stringId("ccf");
    stringId("compress");
    stringId("cp");
    stringId("cpd");
    stringId("cpdr");
    stringId("cpi");
    stringId("cpir");
    stringId("cpl");
    stringId("d");
    stringId("daa");
    stringId("db");
    stringId("de");
    stringId("dec");
    stringId("defb");
    stringId("defm");
    stringId("defw");
    stringId("defs");
    stringId("dd");
    stringId("di");
    stringId("djnz");
    stringId("dw");
    stringId("e");
    stringId("ei");
    stringId("else");
    stringId("endif");
    stringId("endrepeat");
    stringId("equ");
    stringId("ex");
    stringId("exx");
    stringId("file");
    stringId("halt");
    stringId("i");
    stringId("if");
    stringId("im");
    stringId("imaginary");
    stringId("in");
    stringId("inc");
    stringId("indr");
    stringId("ini");
    stringId("inir");
    stringId("ix");
    stringId("ixh");
    stringId("ixl");
    stringId("iy");
    stringId("iyh");
    stringId("iyl");
    stringId("jp");
    stringId("jr");
    stringId("h");
    stringId("hl");
    stringId("l");
    stringId("ld");
    stringId("ldd");
    stringId("lddr");
    stringId("ldi");
    stringId("ldir");
    stringId("m");
    stringId("nc");
    stringId("neg");
    stringId("none");
    stringId("nop");
    stringId("nz");
    stringId("or");
    stringId("otdr");
    stringId("otir");
    stringId("out");
    stringId("outd");
    stringId("outi");
    stringId("p");
    stringId("pe");
    stringId("po");
    stringId("pop");
    stringId("push");
    stringId("r");
    stringId("repeat");
    stringId("res");
    stringId("ret");
    stringId("reti");
    stringId("retn");
    stringId("rl");
    stringId("rla");
    stringId("rlc");
    stringId("rlca");
    stringId("rld");
    stringId("rr");
    stringId("rra");
    stringId("rrc");
    stringId("rrca");
    stringId("rrd");
    stringId("rst");
    stringId("sbc");
    stringId("scf");
    stringId("section");
    stringId("set");
    stringId("sla");
    stringId("sll");
    stringId("sp");
    stringId("sra");
    stringId("srl");
    stringId("sub");
    stringId("xor");
    stringId("z");
    stringId("zx7");
    numPredefinedStrings = stringTable.size();
}

static size_t nextObfuscated = 0;
static std::unordered_map<std::string, std::string> obfuscatedNames;
static QString obfuscatorDatFile;

void initObfuscator(const QDir& generatedFilesDir, ProjectSettings& settings)
{
    nextObfuscated = 0;
    obfuscatedNames.clear();

    if (!generateBlobs)
        return;

    obfuscatorDatFile = generatedFilesDir.absoluteFilePath(QStringLiteral("obfuscator.dat"));
    if (QFileInfo::exists(obfuscatorDatFile)) {
        QByteArray data = loadFile(obfuscatorDatFile);
        QDataStream stream(&data, QIODevice::ReadOnly);
        quint32 n = 0;
        stream >> n;
        quint32 next = 0;
        stream >> next;
        nextObfuscated = next;
        while (n-- > 0) {
            QByteArray name, mapping;
            stream >> name;
            stream >> mapping;
            obfuscatedNames[std::string(name.constData(), name.length())] =
                std::string(mapping.constData(), mapping.length());
        }
    }

    for (const auto& it : settings.dontObfuscate)
        obfuscatedNames[it] = it;
}

void dontObfuscate(const std::string& id)
{
    if (!generateBlobs)
        return;

    auto it = obfuscatedNames.find(id);
    if (it != obfuscatedNames.end() && it->second != id) {
        std::stringstream ss;
        ss << "Can't prevent obfuscation of id \"" << id << "\" because it is already obfuscated.";
        throw std::runtime_error(ss.str());
    }

    obfuscatedNames[id] = id;
}

void saveObfuscatorData(IErrorReporter* errorReporter)
{
    if (!generateBlobs)
        return;

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream << quint32(obfuscatedNames.size());
    stream << quint32(nextObfuscated);
    for (const auto& it : obfuscatedNames) {
        stream << QByteArray(it.first.c_str());
        stream << QByteArray(it.second.c_str());
    }

    if (!writeFile(obfuscatorDatFile, data.constData(), data.length(), errorReporter))
        throw std::runtime_error("Can't write obfuscator.dat.");
}

static const char table[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";

static std::string nextObfuscatedName()
{
    std::stringstream ss;
    ss << '$';

    size_t i = nextObfuscated++;
    do {
        ss << table[i % (sizeof(table) - 1)];
        i /= sizeof(table) - 1;
    } while (i != 0);

    return ss.str();
}

static std::string obfuscateString(const std::string& name)
{
    auto it = obfuscatedNames.find(name);
    if (it != obfuscatedNames.end())
        return it->second;

    if (name.length() > 4 && memcmp(name.data(), "bank", 4) == 0) {
        obfuscatedNames[name] = name;
        return name;
    }

    std::string oname = nextObfuscatedName();
    obfuscatedNames[name] = oname;

    return oname;
}

static std::string obfuscateName(std::string name)
{
    auto it = stringMapping.find(toLower(name));
    if (it != stringMapping.end() && it->second < numPredefinedStrings)
        return name;

    const char* suffix = "";
    if (name.length() > 0 && name[name.length() - 1] == ':') {
        suffix = ":";
        name = name.substr(0, name.length() - 1);
    }

    size_t index = name.find("@@");
    if (index == std::string::npos)
        return obfuscateString(name) + suffix;
    else {
        auto part1 = obfuscateString(name.substr(0, index));
        auto part2 = obfuscateString(name.substr(index + 2));
        return part1 + "@@" + part2 + suffix;
    }
}

Assembler::Assembler(Compiler* compiler, Program* program, IErrorReporter* reporter)
    : mCompiler(compiler)
    , mProgram(program)
    , mReporter(reporter)
{
}

Assembler::~Assembler()
{
}

bool Assembler::parse(const SourceFile* file, const QByteArray& fileData)
{
    try {
        bool noBlob = false;
        if (fileData.length() > 7 && memcmp(fileData.constData(), ";NOBLOB", 7) == 0
                && (fileData[7] == '\r' || fileData[7] == '\n'))
            noBlob = true;

        if (generateBlobs && !noBlob) {
            AssemblerLexer lexer(file, fileData, mReporter);
            initStringMapping();

            std::vector<uint8_t> tokenBytes;

            Token token;
            std::vector<Token> tokens;
            do {
                token = lexer.nextToken();

                Q_ASSERT(token.file == file);
                Q_ASSERT(token.id >= 0 && token.id <= 63);
                if (token.file != file || token.id < 0 || token.id > 63)
                    throw std::runtime_error("precondition 1 failed.");

                bool hasText = false;
                std::string text;
                switch (token.id) {
                    case T_AF_SHADOW:
                    case T_STRING:
                        text = token.text;
                        hasText = true;
                        break;

                    case T_IDENTIFIER:
                    case T_LABEL:
                    case T_FULL_LABEL:
                    case T_LOCAL_LABEL:
                    case T_LOCAL_LABEL_NAME:
                        text = obfuscateName(token.text);
                        hasText = true;
                        break;
                }

                uint16_t textId = 0;
                if (hasText)
                    textId = stringId(text);

                if (token.id == T_IDENTIFIER && textId < (256 - 64))
                    tokenBytes.emplace_back(uint8_t(textId + 64));
                else {
                    tokenBytes.emplace_back(uint8_t(token.id));
                    if (hasText) {
                        if (textId < 255)
                            tokenBytes.emplace_back(textId);
                        else {
                            tokenBytes.emplace_back(255);
                            tokenBytes.emplace_back(textId >> 8);
                            tokenBytes.emplace_back(textId & 0xff);
                        }
                    }
                }

                if (token.id == T_NUMBER) {
                    if (token.number <= 253)
                        tokenBytes.emplace_back(uint8_t(token.number) + 2);
                    else if (token.number >= 254 && token.number <= 65535 + 254) {
                        tokenBytes.emplace_back(1);
                        quint32 n = token.number - 254;
                        tokenBytes.emplace_back(n & 0xff);
                        tokenBytes.emplace_back((n >> 8) & 0xff);
                    } else {
                        tokenBytes.emplace_back(0);
                        quint32 n = token.number - (65536 + 254);
                        tokenBytes.emplace_back((n >> 24) & 0xff);
                        tokenBytes.emplace_back((n >> 8) & 0xff);
                        tokenBytes.emplace_back((n >> 16) & 0xff);
                        tokenBytes.emplace_back(n & 0xff);
                    }
                }
            } while (token.id != T_EOF);

            std::stringstream ss;

            size_t n = stringTable.size();
            size_t nn = n - numPredefinedStrings;
            if (nn < 255)
                ss << uint8_t(nn + 1);
            else {
                ss << uint8_t(0);
                ss << uint8_t(nn >> 8);
                ss << uint8_t(nn & 0xff);
            }

            for (size_t i = numPredefinedStrings; i < n; i++) {
                size_t n = stringTable[i].length();
                if (n < 255)
                    ss << uint8_t(n);
                else {
                    ss << uint8_t(255);
                    ss << uint8_t(nn & 0xff);
                    ss << uint8_t(nn >> 8);
                }
                ss << stringTable[i];
            }

            ss.write(reinterpret_cast<const char*>(tokenBytes.data()), tokenBytes.size());

            QString filePath = mCompiler->projectDirectory().absoluteFilePath(QStringLiteral("blobs/%1.blob").arg(file->name));
            if (!writeFile(filePath, ss.str(), mReporter))
                throw std::runtime_error("Can't write blob file.");
        }

        AssemblerLexer lexer(file, fileData, mReporter);
        AssemblerParser parser(mCompiler, &lexer, mProgram, mReporter);
        parser.parse();
        return true;
    } catch (const LexerError&) {
        return false;
    } catch (const ParserError&) {
        return false;
    } catch (const EvalError&) {
        return false;
    }
}

bool Assembler::parseBlob(const SourceFile* file, const QByteArray& fileData)
{
    try {
        class FakeLexer : public IAssemblerLexer
        {
        public:
            FakeLexer(const SourceFile* file, const QByteArray& fileData)
                : mIndex(-1)
                , mSavedIndex(-1)
            {
                initStringMapping();

                const unsigned char* p = reinterpret_cast<const unsigned char*>(fileData.constData());
                const unsigned char* end = p + fileData.length();

                if (p >= end)
                    throw std::runtime_error("unexpected end of file.");

                uint32_t n = *p++;
                if (n != 0)
                    --n;
                else {
                    if (p + 2 > end)
                        throw std::runtime_error("unexpected end of file.");
                    n = uint32_t(*p++) << 8;
                    n |= *p++;
                }

                while (n-- > 0) {
                    if (p >= end)
                        throw std::runtime_error("unexpected end of file.");

                    uint32_t len = *p++;
                    if (len == 255) {
                        if (p + 2 > end)
                            throw std::runtime_error("unexpected end of file.");
                        len = *p++;
                        len |= uint32_t(*p++) << 8;
                    }

                    if (p + len > end)
                        throw std::runtime_error("unexpected end of file.");

                    stringId(std::string(p, p + len));
                    p += len;
                }

                Token token;
                token.id = 0xff;

                while (p < end) {
                    token.file = file;
                    token.line = 0;
                    token.text.clear();
                    token.number = 0;

                    uint8_t tokenId = *p++;
                    if (tokenId >= 64) {
                        token.id = T_IDENTIFIER;
                        if (tokenId - 64 >= stringTable.size())
                            throw std::runtime_error("invalid string id.");
                        token.text = stringTable[tokenId - 64];
                    } else {
                        token.id = tokenId;

                        bool hasText = false;
                        switch (tokenId) {
                        case T_AF_SHADOW:
                        case T_STRING:
                        case T_IDENTIFIER:
                        case T_LABEL:
                        case T_FULL_LABEL:
                        case T_LOCAL_LABEL:
                        case T_LOCAL_LABEL_NAME:
                            hasText = true;
                            break;
                        }

                        if (hasText) {
                            if (p >= end)
                                throw std::runtime_error("unexpected end of file.");

                            uint32_t textId = *p++;
                            if (textId == 255) {
                                if (p + 2 > end)
                                    throw std::runtime_error("unexpected end of file.");
                                textId = uint32_t(*p++) << 8;
                                textId |= *p++;
                            }

                            if (textId >= stringTable.size())
                                throw std::runtime_error("invalid string id.");

                            token.text = stringTable[textId];
                        }
                    }

                    if (token.id == T_NUMBER) {
                        if (p >= end)
                            throw std::runtime_error("unexpected end of file.");

                        uint32_t num = *p++;
                        if (num == 0) {
                            if (p + 4 > end)
                                throw std::runtime_error("unexpected end of file.");
                            num |= uint32_t(*p++) << 24;
                            num |= uint32_t(*p++) << 8;
                            num |= uint32_t(*p++) << 16;
                            num = *p++;
                            num += (65536 + 254);
                        } else if (num == 1) {
                            if (p + 2 > end)
                                throw std::runtime_error("unexpected end of file.");
                            num = *p++;
                            num |= uint32_t(*p++) << 8;
                            num += 254;
                        } else
                            num -= 2;
                        token.number = num;
                    }

                    mTokens.emplace_back(token);
                }

                if (token.id != 0)
                    throw std::runtime_error("invalid last token.");
            }

            const Token& nextToken() override
            {
                if (mIndex + 1 < mTokens.size())
                    ++mIndex;
                return mTokens[mIndex];
            }

            const Token& lastToken() const override
            {
                Q_ASSERT(mIndex >= 0);
                return mTokens[mIndex];
            }

            void save() override
            {
                mSavedIndex = mIndex;
            }

            void restore() override
            {
                mIndex = mSavedIndex;
            }

            void forget() override
            {
            }

        private:
            std::vector<Token> mTokens;
            int mIndex;
            int mSavedIndex;
        };

        FakeLexer lexer(file, fileData);
        AssemblerParser parser(mCompiler, &lexer, mProgram, mReporter);
        parser.parse();
        return true;
    } catch (const LexerError&) {
        return false;
    } catch (const ParserError&) {
        return false;
    } catch (const EvalError&) {
        return false;
    }
}
