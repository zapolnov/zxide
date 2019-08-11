#include "Linker.h"
#include "Program.h"
#include "ProgramSection.h"
#include "ProgramBinary.h"
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
            throw LinkerError();

        if (!sections[0]->hasBase())
            error(tr("No sections with base address"));

        auto binary = std::make_unique<ProgramBinary>(sections[0]->base());

        quint32 addr = binary->baseAddress();
        for (ProgramSection* section : sections) {
            if (!section->resolveAddresses(mReporter, addr))
                throw LinkerError();
        }

        for (ProgramSection* section : sections)
            section->emitCode(mReporter, binary.get());

        return binary;
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
