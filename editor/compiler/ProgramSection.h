#ifndef COMPILER_PROGRAMSECTION_H
#define COMPILER_PROGRAMSECTION_H

#include <QtGlobal>
#include <string>
#include <memory>
#include <vector>

#ifdef emit
#undef emit
#endif

class ProgramLabel;
class ProgramOpcode;

class ProgramSection
{
public:
    explicit ProgramSection(std::string name);
    ~ProgramSection();

    const std::string& name() const { return mName; }
    const char* nameCStr() const { return mName.c_str(); }

    bool hasBase() const { return mHasBase; }
    unsigned base() const { Q_ASSERT(mHasBase); return mBase; }
    void setBase(unsigned value) { mBase = value; mHasBase = true; }

    bool hasAlignment() const { return mHasAlignment; }
    unsigned alignment() const { return mAlignment; }
    void setAlignment(unsigned value) { mAlignment = value; mHasAlignment = true; }

    template <typename T, typename... ARGS> T* emit(ARGS&&... args)
    {
        auto uniq = std::make_unique<T>(std::forward<ARGS>(args)...);
        auto ptr = uniq.get();
        mOpcodes.emplace_back(std::move(uniq));
        return ptr;
    }

private:
    std::string mName;
    std::vector<ProgramLabel*> mLabels;
    std::vector<std::unique_ptr<ProgramOpcode>> mOpcodes;
    unsigned mBase;
    unsigned mAlignment;
    bool mHasBase;
    bool mHasAlignment;

    Q_DISABLE_COPY(ProgramSection)
    friend class ProgramLabel;
};

#endif
