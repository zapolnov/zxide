#include "Linker.h"
#include "Compressor.h"
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
                if (!section->isCompressed()) {
                    if (!section->resolveAddresses(mReporter, mProgram, addr))
                        throw LinkerError();

                    unsigned start = section->resolvedBase();
                    unsigned length = addr - start;
                    binary->debugInfo()->addSection(section, start, length);
                }
            }

            // Emit code
            for (ProgramSection* section : it.second) {
                if (!section->isCompressed()) {
                    if (!section->isImaginary())
                        emitCodeForSection(binary.get(), section);
                } else {
                    if (!section->resolveAddresses(mReporter, mProgram, addr))
                        throw LinkerError();

                    unsigned start = section->resolvedBase();
                    unsigned length = addr - start;
                    binary->debugInfo()->addSection(section, start, length);

                    if (section->isImaginary())
                        addr = start;
                    else {
                        size_t compressedLength = emitCodeForSection(binary.get(), section);
                        addr = unsigned(start + compressedLength);
                    }
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

size_t Linker::emitCodeForSection(ProgramBinary* binary, ProgramSection* section)
{
    size_t compressedLength = 0;

    binary->setCurrentSection(section);

    switch (section->compression()) {
        case Compression::Unspecified:
        case Compression::None:
            compressedLength = section->emitCode(mProgram, binary, mReporter);
            break;

        case Compression::Zx7: {
            Zx7Compressor compressor(binary);
            section->emitCode(mProgram, &compressor, mReporter);
            compressedLength = compressor.flush();
            break;
        }
    }

    binary->debugInfo()->setSectionCompressedLength(section, unsigned(compressedLength));
    return compressedLength;
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
        std::multimap<unsigned, ProgramSection*, std::greater<unsigned>> uncompressedSectionsWithAlignment;
        std::multimap<unsigned, ProgramSection*, std::greater<unsigned>> compressedSectionsWithAlignment;
    };

    std::map<std::string, Interim> map;
    std::map<std::string, std::vector<ProgramSection*>> result;

    // First collect sections that have a base address and sort them by it
    mProgram->forEachSection([this, &map](ProgramSection* section) {
            if (section->hasBase())
                map[section->fileName()].sectionsWithBaseAddress.emplace(section->base(mReporter), section);
        });

    // Now collect non-compressed sections without base address but with alignment and sort them by it
    mProgram->forEachSection([this, &map](ProgramSection* section) {
            if (!section->hasBase() && section->hasAlignment() && !section->isCompressed())
                map[section->fileName()].uncompressedSectionsWithAlignment.emplace(section->alignment(mReporter), section);
        });

    for (auto& it : map) {
        auto& vec = result[it.first];
        vec.reserve(vec.size() + mProgram->sectionCount());
        for (const auto& jt : it.second.sectionsWithBaseAddress)
            vec.emplace_back(jt.second);
        for (const auto& jt : it.second.uncompressedSectionsWithAlignment)
            vec.emplace_back(jt.second);
    }

    // Now collect other non-compressed sections
    mProgram->forEachSection([&result](ProgramSection* section) {
            if (!section->hasBase() && !section->hasAlignment() && !section->isCompressed())
                result[section->fileName()].emplace_back(section);
        });

    // Now collect compressed sections with alignment and sort them by it
    mProgram->forEachSection([this, &map](ProgramSection* section) {
            if (!section->hasBase() && section->hasAlignment() && section->isCompressed())
                map[section->fileName()].compressedSectionsWithAlignment.emplace(section->alignment(mReporter), section);
        });

    for (auto& it : map) {
        auto& vec = result[it.first];
        vec.reserve(vec.size() + mProgram->sectionCount());
        for (const auto& jt : it.second.compressedSectionsWithAlignment)
            vec.emplace_back(jt.second);
    }

    // Finally collect other compressed sections
    mProgram->forEachSection([&result](ProgramSection* section) {
            if (!section->hasBase() && !section->hasAlignment() && section->isCompressed())
                result[section->fileName()].emplace_back(section);
        });

    return result;
}

void Linker::error(const QString& message)
{
    mReporter->error(nullptr, 0, message);
    throw LinkerError();
}
