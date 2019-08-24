#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include "ProgramSection.h"
#include <functional>
#include <map>
#include <string>
#include <memory>

struct Token;
class IErrorReporter;
class ProgramLabel;
class Expression;

class Program
{
public:
    Program();
    ~Program();

    bool addConstant(std::string name, std::unique_ptr<Expression> expr);
    const std::unique_ptr<Expression>& findConstant(const std::string& name) const;
    void validateConstants(IErrorReporter* reporter);

    bool isDeclared(const std::string& name) const;

    ProgramLabel* addLabel(const Token& token, CodeEmitter* codeEmitter, const std::string& name);
    ProgramLabel* findLabel(const std::string& name) const;

    size_t sectionCount() const { return mSections.size(); }
    ProgramSection* getOrCreateSection(const std::string& name);
    void forEachSection(const std::function<void(ProgramSection*)>& iterator) const;

private:
    std::map<std::string, std::unique_ptr<Expression>> mConstants;
    std::map<std::string, std::unique_ptr<ProgramSection>> mSections;
    std::map<std::string, ProgramLabel*> mLabels;

    Q_DISABLE_COPY(Program)
};

#endif
