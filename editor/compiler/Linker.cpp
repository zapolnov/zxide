#include "Linker.h"
#include "Program.h"
#include "ProgramSection.h"
#include "ProgramBinary.h"
#include "Expression.h"
#include "IErrorReporter.h"

namespace
{
    class LinkerError
    {
    };
}

Linker::Linker(Program* program, IErrorReporter* reporter)
    : mProgram(program)
    , mReporter(reporter)
{
}

Linker::~Linker()
{
}

std::unique_ptr<ProgramBinary> Linker::emitCode()
{
    try {
        auto sections = collectSections();
        if (sections.size() == 0)
            error(tr("Empty program"));

        if (!sections[0]->hasBase())
            error(tr("No sections with base address"));

        auto binary = std::make_unique<ProgramBinary>(sections[0]->base());

        // Resolve addresses of labels
        quint32 addr = binary->baseAddress();
        for (ProgramSection* section : sections) {
            if (!section->resolveAddresses(mReporter, mProgram, addr))
                throw LinkerError();
        }

        // Emit code
        for (ProgramSection* section : sections)
            section->emitCode(mProgram, binary.get(), mReporter);

        // Ensure that all EQUs are validated
        mProgram->validateConstants(mReporter);

        return binary;
    } catch (const EvalError&) {
        return {};
    } catch (const LinkerError&) {
        return {};
    }
}

std::vector<ProgramSection*> Linker::collectSections() const
{
    std::vector<ProgramSection*> sections;
    sections.reserve(mProgram->sectionCount());

    // First collect sections that have a base address and sort them by it
    std::multimap<unsigned, ProgramSection*> sectionsWithBaseAddress;
    mProgram->forEachSection([&sectionsWithBaseAddress](ProgramSection* section) {
            if (section->hasBase())
                sectionsWithBaseAddress.emplace(section->base(), section);
        });
    for (const auto& it : sectionsWithBaseAddress)
        sections.emplace_back(it.second);

    // Now collect sections without base address
    mProgram->forEachSection([&sections](ProgramSection* section) {
            if (!section->hasBase() && !section->isEmpty())
                sections.emplace_back(section);
        });

    return sections;
}

void Linker::error(const QString& message)
{
    mReporter->error(nullptr, 0, message);
    throw LinkerError();
}
