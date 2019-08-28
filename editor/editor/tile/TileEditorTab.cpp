#include "TileEditorTab.h"
#include "editor/FileManager.h"
#include "ui_TileEditorTab.h"
#include <QMessageBox>
#include <QSaveFile>
#include <QJsonDocument>
#include <QJsonObject>

static const QString JsonKey_Version = QStringLiteral("version");
static const QString JsonKey_Identifier = QStringLiteral("identifier");
static const QString JsonKey_Section = QStringLiteral("section");
static const QString JsonKey_Format = QStringLiteral("format");
static const QString JsonKey_Width = QStringLiteral("width");
static const QString JsonKey_Height = QStringLiteral("height");
static const QString JsonKey_ColorMode = QStringLiteral("color_mode");
static const QString JsonValue_Standard = QStringLiteral("standard");
static const QString JsonValue_Multicolor = QStringLiteral("multicolor");
static const QString JsonValue_Bicolor = QStringLiteral("bicolor");
static const QString JsonValue_Monochrome = QStringLiteral("monochrome");
static const QString JsonValue_NirvanaPlusCode = QStringLiteral("nirvana+_code");
static const int FileFormatVersion = 1;

TileEditorTab::TileEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_TileEditorTab)
{
    mUi->setupUi(this);

    for (int i = 8; i <= 128; i += 8) {
        mUi->widthCombo->addItem(QString::number(i), QVariant(i));
        mUi->heightCombo->addItem(QString::number(i), QVariant(i));
    }

    mUi->colorModeCombo->addItem(tr("Standard"), JsonValue_Standard);
    mUi->colorModeCombo->addItem(tr("Multicolor (8x1)"), JsonValue_Multicolor);
    mUi->colorModeCombo->addItem(tr("Bicolor (8x2)"), JsonValue_Bicolor);

    mUi->formatCombo->addItem(tr("Bitmap (8 bytes)"), JsonValue_Monochrome);
    mUi->formatCombo->addItem(tr("NIRVANA+ code"), JsonValue_NirvanaPlusCode);

    mUi->tabBar->addTab(tr("Pixels"));
    mUi->tabBar->addTab(tr("Colors"));
}

TileEditorTab::~TileEditorTab()
{
}

bool TileEditorTab::loadFile(File* f)
{
    reset();

    QByteArray data = loadFileData(f);
    if (data.isEmpty()) {
        mUi->identifierEdit->setText(QString());
        mUi->sectionEdit->setText(QString());
        mUi->formatCombo->setCurrentIndex(0);
        mUi->widthCombo->setCurrentIndex(0);
        mUi->heightCombo->setCurrentIndex(0);
        mUi->colorModeCombo->setCurrentIndex(0);
    } else {
        QJsonParseError error;
        auto doc = QJsonDocument::fromJson(data, &error);
        if (doc.isNull()) {
            QMessageBox::critical(this, tr("Error"),
                tr("Unable to read file \"%1\": %2").arg(f->fileInfo().absoluteFilePath()).arg(error.errorString()));
            return false;
        }

        QJsonObject root = doc.object();
        int formatVersion = root[JsonKey_Version].toInt();
        if (formatVersion < 1 || formatVersion > FileFormatVersion) {
            QMessageBox::critical(this, tr("Error"),
                tr("Unable to read file \"%1\": file has unsupported format.").arg(f->fileInfo().absoluteFilePath()));
            return false;
        }

        mUi->identifierEdit->setText(root[JsonKey_Identifier].toString());
        mUi->sectionEdit->setText(root[JsonKey_Section].toString());
        selectItem(mUi->formatCombo, root[JsonKey_Format].toString());
        selectItem(mUi->widthCombo, root[JsonKey_Width].toInt());
        selectItem(mUi->heightCombo, root[JsonKey_Height].toInt());
        selectItem(mUi->colorModeCombo, root[JsonKey_ColorMode].toString());

        // FIXME: read pixels
    }

    mUi->identifierEdit->setEnabled(true);
    mUi->sectionEdit->setEnabled(true);
    mUi->formatCombo->setEnabled(true);
    mUi->widthCombo->setEnabled(true);
    mUi->heightCombo->setEnabled(true);
    mUi->colorModeCombo->setEnabled(true);
    mUi->editScrollArea->setEnabled(true);
    mUi->previewScrollArea->setEnabled(true);

    reloadSettings();
    setSaved();
    emit updateUi();

    return true;
}

bool TileEditorTab::isModified() const
{
    if (!file())
        return false;

    if (mSavedIdentifier != mUi->identifierEdit->text())
        return true;
    if (mSavedSection != mUi->sectionEdit->text())
        return true;
    if (mSavedFormat != selectedItem(mUi->formatCombo).toString())
        return true;
    if (mSavedColorMode != selectedItem(mUi->colorModeCombo).toString())
        return true;
    if (mSavedWidth != selectedItem(mUi->widthCombo).toInt())
        return true;
    if (mSavedHeight != selectedItem(mUi->heightCombo).toInt())
        return true;

    // FIXME
    return false;
}

bool TileEditorTab::canUndo() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canRedo() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canCut() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canCopy() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canPaste() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canClear() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canSelectAll() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canClearSelection() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canDraw() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canDrawRect() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canFill() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canPick() const
{
    // FIXME
    return false;
}

bool TileEditorTab::canSelect() const
{
    // FIXME
    return false;
}

bool TileEditorTab::save()
{
    QString fileName = file()->fileInfo().absoluteFilePath();

    QSaveFile f(fileName);
    if (!f.open(QFile::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(fileName).arg(f.errorString()));
        return false;
    }

    QJsonDocument doc;
    QJsonObject root;
    root[JsonKey_Version] = FileFormatVersion;
    root[JsonKey_Identifier] = mUi->identifierEdit->text();
    root[JsonKey_Section] = mUi->sectionEdit->text();
    root[JsonKey_Format] = selectedItem(mUi->formatCombo).toString();
    root[JsonKey_Width] = selectedItem(mUi->widthCombo).toInt();
    root[JsonKey_Height] = selectedItem(mUi->heightCombo).toInt();
    root[JsonKey_ColorMode] = selectedItem(mUi->colorModeCombo).toString();
    doc.setObject(root);
    QByteArray json = doc.toJson(QJsonDocument::Indented);

    qint64 bytesWritten = f.write(json);
    if (bytesWritten < 0) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(fileName).arg(f.errorString()));
        return false;
    }
    if (bytesWritten != json.length()) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\".").arg(fileName));
        return false;
    }

    if (!f.commit()) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(fileName).arg(f.errorString()));
        return false;
    }

    // FIXME: save pixels

    setSaved();
    emit updateUi();

    return true;
}

void TileEditorTab::undo()
{
    // FIXME
}

void TileEditorTab::redo()
{
    // FIXME
}

void TileEditorTab::cut()
{
    // FIXME
}

void TileEditorTab::copy()
{
    // FIXME
}

void TileEditorTab::paste()
{
    // FIXME
}

void TileEditorTab::clear()
{
    // FIXME
}

void TileEditorTab::selectAll()
{
    // FIXME
}

void TileEditorTab::clearSelection()
{
    // FIXME
}

void TileEditorTab::draw()
{
    // FIXME
}

void TileEditorTab::drawRect()
{
    // FIXME
}

void TileEditorTab::fill()
{
    // FIXME
}

void TileEditorTab::pick()
{
    // FIXME
}

void TileEditorTab::select()
{
    // FIXME
}

void TileEditorTab::reloadSettings()
{
}

void TileEditorTab::setFocusToEditor()
{
    mUi->editorWidget->setFocus();
}

void TileEditorTab::reset()
{
    mSavedIdentifier = QString();
    mSavedSection = QString();
    mSavedFormat = QString();
    mSavedColorMode = QString();
    mSavedWidth = 0;
    mSavedHeight = 0;

    mUi->identifierEdit->clear();
    mUi->identifierEdit->setEnabled(false);
    mUi->sectionEdit->clear();
    mUi->sectionEdit->setEnabled(false);
    mUi->formatCombo->setCurrentIndex(-1);
    mUi->formatCombo->setEnabled(false);
    mUi->widthCombo->setCurrentIndex(-1);
    mUi->widthCombo->setEnabled(false);
    mUi->heightCombo->setCurrentIndex(-1);
    mUi->heightCombo->setEnabled(false);
    mUi->colorModeCombo->setCurrentIndex(-1);
    mUi->colorModeCombo->setEnabled(false);
    mUi->editScrollArea->setEnabled(false);
    mUi->previewScrollArea->setEnabled(false);
}

void TileEditorTab::setSaved()
{
    mSavedIdentifier = mUi->identifierEdit->text();
    mSavedSection = mUi->sectionEdit->text();
    mSavedFormat = selectedItem(mUi->formatCombo).toString();
    mSavedColorMode = selectedItem(mUi->colorModeCombo).toString();
    mSavedWidth = selectedItem(mUi->widthCombo).toInt();
    mSavedHeight = selectedItem(mUi->heightCombo).toInt();
}

bool TileEditorTab::selectItem(QComboBox* combo, const QVariant& value)
{
    int n = combo->count();
    for (int i = 0; i < n; i++) {
        if (combo->itemData(i) == value) {
            combo->setCurrentIndex(i);
            return true;
        }
    }
    return false;
}

QVariant TileEditorTab::selectedItem(const QComboBox* combo)
{
    int selected = combo->currentIndex();
    return (selected < 0 ? QVariant() : combo->itemData(selected));
}
