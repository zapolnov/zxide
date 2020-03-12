#include "Assembler.h"
#include "AssemblerLexer.h"
#include "AssemblerParser.h"
#include "Compiler.h"
#include "Expression.h"
#include "IO.h"
#include <sstream>

bool assemblerTokenize;

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
        if (assemblerTokenize) {
            AssemblerLexer lexer(file, fileData, mReporter);

            std::vector<uint8_t> tokenBytes;

            std::vector<std::string> stringTable;
            std::unordered_map<std::string, uint16_t> stringMapping;
            stringMapping[""] = 0;

            auto stringId = [&stringTable, &stringMapping](const std::string& str) -> uint16_t {
                    auto it = stringMapping.find(str);
                    if (it != stringMapping.end())
                        return it->second;
                    if (stringTable.size() > 65535)
                        throw std::runtime_error("precondition 2 failed.");
                    uint16_t id = uint16_t(stringTable.size());
                    stringMapping[str] = id;
                    stringTable.emplace_back(str);
                    return id;
                };

            Token token;
            std::vector<Token> tokens;
            do {
                token = lexer.nextToken();
                Q_ASSERT(token.file == file);
                Q_ASSERT(token.id >= 0 && token.id <= 255);
                if (token.file != file || token.id < 0 || token.id > 255)
                    throw std::runtime_error("precondition 1 failed.");
                tokenBytes.emplace_back(uint8_t(token.id));
                uint16_t textId = stringId(token.text);
                tokenBytes.emplace_back(textId & 0xff);
                tokenBytes.emplace_back(textId >> 8);
                if (token.number <= 253)
                    tokenBytes.emplace_back(uint8_t(token.number));
                else if (token.number >= 254 && token.number <= 65535 + 254) {
                    tokenBytes.emplace_back(254);
                    quint32 n = token.number - 254;
                    tokenBytes.emplace_back(n & 0xff);
                    tokenBytes.emplace_back((n >> 8) & 0xff);
                } else {
                    tokenBytes.emplace_back(255);
                    quint32 n = token.number - (65536 + 254);
                    tokenBytes.emplace_back(n & 0xff);
                    tokenBytes.emplace_back((n >> 8) & 0xff);
                    tokenBytes.emplace_back((n >> 16) & 0xff);
                    tokenBytes.emplace_back((n >> 24) & 0xff);
                }
            } while (token.id != T_EOF);

            std::stringstream ss;
            ss.write(reinterpret_cast<const char*>(tokenBytes.data()), tokenBytes.size());
            writeFile(QStringLiteral("%1.bin").arg(file->path), ss.str(), mReporter);
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
