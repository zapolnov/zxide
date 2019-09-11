#include "TestUtil.h"
#include "AssemblerLexer.h"
#include "AssemblerParser.h"
#include "Linker.h"
#include "Program.h"
#include "ProgramBinary.h"
#include "ProgramSection.h"
#include "ErrorConsumer.h"
#include "DataBlob.h"

static void assemble(IErrorReporter& errorConsumer, Program* program, const char* source)
{
    QByteArray fileData = source;
    AssemblerLexer lexer(nullptr, fileData, &errorConsumer);
    AssemblerParser parser(&lexer, program, &errorConsumer);
    parser.parse();
}

static DataBlob link(IErrorReporter& errorConsumer, Program* program)
{
    Linker linker(program, &errorConsumer);
    auto binary = linker.emitCode();
    if (!binary)
        return DataBlob();

    binary->setCurrentFile(std::string());
    DataBlob result(binary->codeBytes(), binary->codeLength());

    for (const auto& it : binary->files()) {
        if (!it.first.empty()) {
            binary->setCurrentFile(it.first);
            result.setFileData(it.first, DataBlob(binary->codeBytes(), binary->codeLength()));
        }
    }

    return result;
}

DataBlob assemble(IErrorReporter& errorConsumer, const char* source)
{
    try {
        Program program;
        assemble(errorConsumer, &program, source);
        return link(errorConsumer, &program);
    } catch (const LexerError&) {
        return DataBlob();
    } catch (const ParserError&) {
        return DataBlob();
    }
}

DataBlob assemble2(IErrorReporter& errorConsumer, const char* source1, const char* source2)
{
    try {
        Program program;
        assemble(errorConsumer, &program, source1);
        assemble(errorConsumer, &program, source2);
        return link(errorConsumer, &program);
    } catch (const LexerError&) {
        return DataBlob();
    } catch (const ParserError&) {
        return DataBlob();
    }
}

DataBlob assemble3(IErrorReporter& errorConsumer, const char* source1, const char* source2, const char* source3)
{
    try {
        Program program;
        assemble(errorConsumer, &program, source1);
        assemble(errorConsumer, &program, source2);
        assemble(errorConsumer, &program, source3);
        return link(errorConsumer, &program);
    } catch (const LexerError&) {
        return DataBlob();
    } catch (const ParserError&) {
        return DataBlob();
    }
}
