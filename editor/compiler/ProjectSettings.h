#ifndef COMPILER_PROJECTSETTINGS_H
#define COMPILER_PROJECTSETTINGS_H

#include <QString>
#include <vector>
#include <string>

enum class CStandard
{
    C89,
    C99,
    C11,
};

enum class COptimization
{
    None,
    Speed,
    Size,
};

class ProjectSettings
{
public:
    CStandard standard;
    COptimization optimization;
    std::vector<std::string> defines;
    bool charIsUnsigned;

    ProjectSettings();
    ~ProjectSettings();

    void load(const QString& file);
    void save(const QString& file);

private:
    Q_DISABLE_COPY(ProjectSettings)
};

#endif
