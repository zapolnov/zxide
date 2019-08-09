#include "Assembler.h"
#include "AssemblerParser.h"
#include "AssemblerLexer.h"

Assembler::Assembler(Program* program, IErrorReporter* reporter)
    : mProgram(program)
    , mReporter(reporter)
{
}

Assembler::~Assembler()
{
}

bool Assembler::parse(File* file, const QByteArray& fileData)
{
    try {
        AssemblerLexer lexer(file, fileData, mReporter);
        AssemblerParser parser(&lexer, mProgram, mReporter);
        parser.parse();
        return true;
    } catch (const LexerError&) {
        return false;
    } catch (const ParserError&) {
        return false;
    }
}
