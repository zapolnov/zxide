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
static const QString JsonValue_C89 = QStringLiteral("c89");
static const QString JsonValue_C99 = QStringLiteral("c99");
static const QString JsonValue_C11 = QStringLiteral("c11");
static const QString JsonValue_None = QStringLiteral("none");
static const QString JsonValue_Speed = QStringLiteral("speed");
static const QString JsonValue_Size = QStringLiteral("size");
static const int FileFormatVersion = 1;

ProjectSettings::ProjectSettings()
    : standard(CStandard::C99)
    , charIsUnsigned(false)
{
}

ProjectSettings::~ProjectSettings()
{
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
    if (optimizationString == JsonValue_None) optimization = COptimization::None;
    else if (optimizationString == JsonValue_Speed) optimization = COptimization::Speed;
    else if (optimizationString == JsonValue_Size) optimization = COptimization::Size;
    else {
        throw IOException(QCoreApplication::tr("Unable to read file \"%1\": invalid optimization \"%2\".")
            .arg(file).arg(optimizationString));
    }

    defines.clear();
    for (const auto& it : root[JsonKey_CDefines].toArray())
        defines.emplace_back(it.toString().toLatin1());

    charIsUnsigned = root[JsonKey_CharIsUnsigned].toBool();
}

void ProjectSettings::save(const QString& file)
{
    QJsonDocument doc;
    QJsonObject root;

    root[JsonKey_Version] = FileFormatVersion;
    root[JsonKey_CharIsUnsigned] = charIsUnsigned;

    switch (standard) {
        case CStandard::C89: root[JsonKey_CStandard] = JsonValue_C89; break;
        case CStandard::C99: root[JsonKey_CStandard] = JsonValue_C99; break;
        case CStandard::C11: root[JsonKey_CStandard] = JsonValue_C11; break;
    }

    switch (optimization) {
        case COptimization::None: root[JsonKey_COptimization] = JsonValue_None; break;
        case COptimization::Speed: root[JsonKey_COptimization] = JsonValue_Speed; break;
        case COptimization::Size: root[JsonKey_COptimization] = JsonValue_Size; break;
    }

    QJsonArray definesArray;
    for (const auto& it : defines)
        definesArray.append(QString::fromLatin1(it.c_str()));
    root[JsonKey_CDefines] = definesArray;

    doc.setObject(root);
    saveJson(file, doc);
}
