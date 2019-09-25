#include "Assembler.h"
#include "AssemblerLexer.h"
#include "AssemblerParser.h"
#include "Expression.h"

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
