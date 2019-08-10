#include "TestUtil.h"
#include "AssemblerLexer.h"
#include "AssemblerParser.h"
#include "Linker.h"
#include "Program.h"
#include "ProgramBinary.h"
#include "ErrorConsumer.h"
#include "DataBlob.h"

DataBlob assemble(IErrorReporter& errorConsumer, const char* source)
{
    try {
        QByteArray fileData = source;
        AssemblerLexer lexer(nullptr, fileData, &errorConsumer);

        Program program;
        AssemblerParser parser(&lexer, &program, &errorConsumer);
        parser.parse();

        Linker linker(&program, &errorConsumer);
        auto binary = linker.emitCode();
        if (!binary)
            return DataBlob();

        return DataBlob(binary->codeBytes(), binary->codeLength());
    } catch (const LexerError&) {
        return DataBlob();
    } catch (const ParserError&) {
        return DataBlob();
    }
}
