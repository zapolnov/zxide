#include "Linker.h"
#include "Program.h"
#include "ProgramSection.h"
#include "ProgramBinary.h"
#include "ProgramDebugInfo.h"
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
        auto binary = std::make_unique<ProgramBinary>();

        auto sections = collectSections();
        if (sections.empty())
            error(tr("program has no sections"));

        for (const auto& it : sections) {
            ProgramSection* firstSectionWithBaseAddress = nullptr;
            for (const auto& jt : it.second) {
                if (!jt->isImaginary() && jt->hasBase()) {
                    firstSectionWithBaseAddress = jt;
                    break;
                }
            }

            if (it.first.empty()) {
                if (!hasCode(it.second))
                    error(tr("program has no code in default file"));
                if (!firstSectionWithBaseAddress)
                    error(tr("no sections with base address in default file"));
            } else {
                if (!hasCode(it.second))
                    error(tr("program has no code in file '%1'").arg(it.first.c_str()));
                if (!firstSectionWithBaseAddress)
                    error(tr("no sections with base address in file '%1'").arg(it.first.c_str()));
            }

            binary->setCurrentFile(it.first, firstSectionWithBaseAddress->base(mReporter));
            quint32 addr = binary->baseAddress();

            // Resolve addresses of labels
            for (ProgramSection* section : it.second) {
                if (!section->resolveAddresses(mReporter, mProgram, addr))
                    throw LinkerError();

                unsigned start = section->resolvedBase();
                unsigned length = addr - start;
                binary->debugInfo()->addSection(section, start, length);
            }

            // Emit code
            for (ProgramSection* section : it.second) {
                if (!section->isImaginary()) {
                    binary->setCurrentSection(section);
                    section->emitCode(mProgram, binary.get(), mReporter);
                }
            }

            binary->setCurrentSection(nullptr);
        }

        // Ensure that all EQUs are validated
        mProgram->validateConstants(mReporter);

        return binary;
    } catch (const EvalError&) {
        return {};
    } catch (const LinkerError&) {
        return {};
    }
}

bool Linker::isEmpty(const std::vector<ProgramSection*>& sections) const
{
    for (const auto& section : sections) {
        if (!section->isEmpty())
            return false;
    }

    return true;
}

bool Linker::hasCode(const std::vector<ProgramSection*>& sections) const
{
    for (const auto& section : sections) {
        if (!section->isImaginary() && section->hasCode(mProgram, mReporter))
            return true;
    }

    return false;
}

std::map<std::string, std::vector<ProgramSection*>> Linker::collectSections() const
{
    struct Interim
    {
        std::multimap<unsigned, ProgramSection*> sectionsWithBaseAddress;
        std::multimap<unsigned, ProgramSection*, std::greater<unsigned>> sectionsWithAlignment;
    };

    std::map<std::string, Interim> map;
    std::map<std::string, std::vector<ProgramSection*>> result;

    // First collect sections that have a base address and sort them by it
    mProgram->forEachSection([this, &map](ProgramSection* section) {
            if (section->hasBase())
                map[section->fileName()].sectionsWithBaseAddress.emplace(section->base(mReporter), section);
        });

    // Now collect sections without base address but with alignment and sort them by it
    mProgram->forEachSection([this, &map](ProgramSection* section) {
            if (!section->hasBase() && section->hasAlignment())
                map[section->fileName()].sectionsWithAlignment.emplace(section->alignment(mReporter), section);
        });

    for (auto& it : map) {
        auto& vec = result[it.first];
        vec.reserve(mProgram->sectionCount());
        for (const auto& jt : it.second.sectionsWithBaseAddress)
            vec.emplace_back(jt.second);
        for (const auto& jt : it.second.sectionsWithAlignment)
            vec.emplace_back(jt.second);
    }

    // Finally collect all other sections
    mProgram->forEachSection([&result](ProgramSection* section) {
            if (!section->hasBase() && !section->hasAlignment())
                result[section->fileName()].emplace_back(section);
        });

    return result;
}

void Linker::error(const QString& message)
{
    mReporter->error(nullptr, 0, message);
    throw LinkerError();
}
