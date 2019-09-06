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
        auto sections = collectSections(-1);
        if (!hasCode(sections))
            error(tr("program has no code in primary memory space"));
        if (!sections[0]->hasBase())
            error(tr("no sections with base address in primary memory space"));

        auto binary = std::make_unique<ProgramBinary>(sections[0]->base());
        quint32 addr = binary->baseAddress();
        int bank = -1;

        do {
            // Resolve addresses of labels
            for (ProgramSection* section : sections) {
                if (!section->resolveAddresses(mReporter, mProgram, addr))
                    throw LinkerError();
            }

            // Emit code
            for (ProgramSection* section : sections)
                section->emitCode(mProgram, binary.get(), mReporter);

            do {
                ++bank;
                if (ProgramSection::isValidBankNumber(bank)) {
                    sections = collectSections(bank);
                    if (!isEmpty(sections)) {
                        addr = sections[0]->baseRelativeTo(ProgramSection::BankBaseAddress);
                        binary->setCurrentBank(bank, addr);
                        break;
                    }
                }
            } while (bank <= ProgramSection::MaxBank);
        } while (bank <= ProgramSection::MaxBank);
        binary->setCurrentBank(-1);

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
        if (section->hasCode(mProgram, mReporter))
            return true;
    }

    return false;
}

std::vector<ProgramSection*> Linker::collectSections(int bank) const
{
    // First collect sections that have a base address and sort them by it
    std::multimap<unsigned, ProgramSection*> sectionsWithBaseAddress;
    mProgram->forEachSection([&sectionsWithBaseAddress, bank](ProgramSection* section) {
            bool include = (bank < 0 ? !section->hasBank() : section->hasBank() && section->bank() == unsigned(bank));
            if (section->hasBase() && include)
                sectionsWithBaseAddress.emplace(section->base(), section);
        });

    // Now collect sections without base address but with alignment and sort them by it
    std::multimap<unsigned, ProgramSection*, std::greater<unsigned>> sectionsWithAlignment;
    mProgram->forEachSection([&sectionsWithAlignment, bank](ProgramSection* section) {
            bool include = (bank < 0 ? !section->hasBank() : section->hasBank() && section->bank() == unsigned(bank));
            if (!section->hasBase() && section->hasAlignment() && include)
                sectionsWithAlignment.emplace(section->alignment(), section);
        });

    std::vector<ProgramSection*> sections;
    sections.reserve(mProgram->sectionCount());
    for (const auto& it : sectionsWithBaseAddress)
        sections.emplace_back(it.second);
    for (const auto& it : sectionsWithAlignment)
        sections.emplace_back(it.second);

    // Finally collect all other sections
    mProgram->forEachSection([&sections, bank](ProgramSection* section) {
        bool include = (bank < 0 ? !section->hasBank() : section->hasBank() && section->bank() == unsigned(bank));
        if (!section->hasBase() && !section->hasAlignment() && include)
            sections.emplace_back(section);
        });

    return sections;
}

void Linker::error(const QString& message)
{
    mReporter->error(nullptr, 0, message);
    throw LinkerError();
}
