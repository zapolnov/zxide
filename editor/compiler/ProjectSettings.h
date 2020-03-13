#ifndef COMPILER_PROJECTSETTINGS_H
#define COMPILER_PROJECTSETTINGS_H

#include <QString>
#include <set>
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
    Default,
    FavorSpeed,
    FavorSize,
};

class ProjectSettings
{
public:
    static const std::string DefaultSegmentName;
    static const std::string DefaultLoaderFileName;
    static const std::string DefaultProgramFileName;

    CStandard standard;
    COptimization optimization;
    std::vector<std::string> defines;
    std::set<std::string> dontObfuscate;
    int basicStartLine;
    bool charIsUnsigned;
    bool stackAutomaticVariables;
    bool calleeSaves;
    bool omitFramePointer;

    ProjectSettings();
    ~ProjectSettings();

    const std::string& loaderFileName() const { return (!mLoaderName.empty() ? mLoaderName : DefaultLoaderFileName); }
    const std::string& programFileName() const { return (!mProgramName.empty() ? mProgramName : DefaultProgramFileName); }
    void setLoaderFileName(std::string name);
    void setProgramFileName(std::string name);

    const std::string& codeSeg() const { return (!mCodeSeg.empty() ? mCodeSeg : DefaultSegmentName); }
    const std::string& constSeg() const { return (!mConstSeg.empty() ? mConstSeg : DefaultSegmentName); }
    const std::string& dataSeg() const { return (!mDataSeg.empty() ? mDataSeg : DefaultSegmentName); }
    void setCodeSeg(std::string name);
    void setConstSeg(std::string name);
    void setDataSeg(std::string name);

    void load(const QString& file);
    void save(const QString& file);

private:
    std::string mCodeSeg;
    std::string mConstSeg;
    std::string mDataSeg;
    std::string mLoaderName;
    std::string mProgramName;

    Q_DISABLE_COPY(ProjectSettings)
};

#endif
