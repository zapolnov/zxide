#include "ProjectSettings.h"
#include "compiler/IO.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QCoreApplication>

static const QString JsonKey_Version = QStringLiteral("version");
static const QString JsonKey_CStandard = QStringLiteral("Cstandard");
static const QString JsonKey_COptimization = QStringLiteral("Coptimization");
static const QString JsonKey_CDefines = QStringLiteral("Cdefines");
static const QString JsonKey_CharIsUnsigned = QStringLiteral("charIsUnsigned");
static const QString JsonKey_StackAutomaticVariables = QStringLiteral("stackAutomaticVariables");
static const QString JsonKey_CalleeSaves = QStringLiteral("calleeSaves");
static const QString JsonKey_OmitFramePointer = QStringLiteral("omitFramePointer");
static const QString JsonKey_CodeSeg = QStringLiteral("codeSeg");
static const QString JsonKey_ConstSeg = QStringLiteral("constSeg");
static const QString JsonKey_DataSeg = QStringLiteral("dataSeg");
static const QString JsonValue_C89 = QStringLiteral("c89");
static const QString JsonValue_C99 = QStringLiteral("c99");
static const QString JsonValue_C11 = QStringLiteral("c11");
static const QString JsonValue_Default = QStringLiteral("default");
static const QString JsonValue_Speed = QStringLiteral("speed");
static const QString JsonValue_Size = QStringLiteral("size");
static const int FileFormatVersion = 1;

const std::string ProjectSettings::DefaultSegmentName = "main";
const std::string ProjectSettings::DefaultLoaderFileName = "BOOT";
const std::string ProjectSettings::DefaultProgramFileName = "MAIN";

ProjectSettings::ProjectSettings()
    : standard(CStandard::C99)
    , optimization(COptimization::FavorSize)
    , basicStartLine(10)
    , charIsUnsigned(false)
    , stackAutomaticVariables(false)
    , calleeSaves(false)
    , omitFramePointer(false)
    , mCodeSeg(DefaultSegmentName)
    , mConstSeg(DefaultSegmentName)
    , mDataSeg(DefaultSegmentName)
    , mLoaderName(DefaultLoaderFileName)
    , mProgramName(DefaultProgramFileName)
{
}

ProjectSettings::~ProjectSettings()
{
}

void ProjectSettings::setLoaderFileName(std::string name)
{
    if (!name.empty())
        mLoaderName = std::move(name);
    else
        mLoaderName = DefaultLoaderFileName;
}

void ProjectSettings::setProgramFileName(std::string name)
{
    if (!name.empty())
        mProgramName = std::move(name);
    else
        mProgramName = DefaultProgramFileName;
}

void ProjectSettings::setCodeSeg(std::string name)
{
    if (!name.empty())
        mCodeSeg = std::move(name);
    else
        mCodeSeg = DefaultSegmentName;
}

void ProjectSettings::setConstSeg(std::string name)
{
    if (!name.empty())
        mConstSeg = std::move(name);
    else
        mConstSeg = DefaultSegmentName;
}

void ProjectSettings::setDataSeg(std::string name)
{
    if (!name.empty())
        mDataSeg = std::move(name);
    else
        mDataSeg = DefaultSegmentName;
}

void ProjectSettings::load(const QString& file)
{
    QJsonDocument doc = loadJson(file);

    QJsonObject root = doc.object();
    int formatVersion = root[JsonKey_Version].toInt();
    if (formatVersion < 1 || formatVersion > FileFormatVersion)
        throw IOException(QCoreApplication::tr("Unable to read file \"%1\": file has unsupported format.").arg(file));

    QString standardString = root[JsonKey_CStandard].toString();
    if (standardString == JsonValue_C89) standard = CStandard::C89;
    else if (standardString == JsonValue_C99) standard = CStandard::C99;
    else if (standardString == JsonValue_C11) standard = CStandard::C11;
    else {
        throw IOException(QCoreApplication::tr("Unable to read file \"%1\": invalid standard \"%2\".")
            .arg(file).arg(standardString));
    }

    QString optimizationString = root[JsonKey_COptimization].toString();
    if (optimizationString == JsonValue_Default) optimization = COptimization::Default;
    else if (optimizationString == JsonValue_Speed) optimization = COptimization::FavorSpeed;
    else if (optimizationString == JsonValue_Size) optimization = COptimization::FavorSize;
    else {
        throw IOException(QCoreApplication::tr("Unable to read file \"%1\": invalid optimization \"%2\".")
            .arg(file).arg(optimizationString));
    }

    defines.clear();
    for (const auto& it : root[JsonKey_CDefines].toArray())
        defines.emplace_back(it.toString().toLatin1());

    charIsUnsigned = root[JsonKey_CharIsUnsigned].toBool();
    stackAutomaticVariables = root[JsonKey_StackAutomaticVariables].toBool();
    calleeSaves = root[JsonKey_CalleeSaves].toBool();
    omitFramePointer = root[JsonKey_OmitFramePointer].toBool();
    setCodeSeg(root[JsonKey_CodeSeg].toString().toLatin1().constData());
    setConstSeg(root[JsonKey_ConstSeg].toString().toLatin1().constData());
    setDataSeg(root[JsonKey_DataSeg].toString().toLatin1().constData());
}

void ProjectSettings::save(const QString& file)
{
    QJsonDocument doc;
    QJsonObject root;

    root[JsonKey_Version] = FileFormatVersion;
    root[JsonKey_CharIsUnsigned] = charIsUnsigned;
    root[JsonKey_StackAutomaticVariables] = stackAutomaticVariables;
    root[JsonKey_CalleeSaves] = calleeSaves;
    root[JsonKey_OmitFramePointer] = omitFramePointer;
    root[JsonKey_CodeSeg] = QString::fromLatin1(codeSeg().c_str());
    root[JsonKey_ConstSeg] = QString::fromLatin1(constSeg().c_str());
    root[JsonKey_DataSeg] = QString::fromLatin1(dataSeg().c_str());

    switch (standard) {
        case CStandard::C89: root[JsonKey_CStandard] = JsonValue_C89; break;
        case CStandard::C99: root[JsonKey_CStandard] = JsonValue_C99; break;
        case CStandard::C11: root[JsonKey_CStandard] = JsonValue_C11; break;
    }

    switch (optimization) {
        case COptimization::Default: root[JsonKey_COptimization] = JsonValue_Default; break;
        case COptimization::FavorSpeed: root[JsonKey_COptimization] = JsonValue_Speed; break;
        case COptimization::FavorSize: root[JsonKey_COptimization] = JsonValue_Size; break;
    }

    QJsonArray definesArray;
    for (const auto& it : defines)
        definesArray.append(QString::fromLatin1(it.c_str()));
    root[JsonKey_CDefines] = definesArray;

    doc.setObject(root);
    saveJson(file, doc);
}
