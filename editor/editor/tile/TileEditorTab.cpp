#include "TileEditorTab.h"
#include "editor/FileManager.h"
#include "editor/tile/TileData.h"
#include "ui_TileEditorTab.h"
#include <QMessageBox>
#include <QSaveFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

static const QString JsonKey_Version = QStringLiteral("version");
static const QString JsonKey_Identifier = QStringLiteral("identifier");
static const QString JsonKey_Section = QStringLiteral("section");
static const QString JsonKey_Format = QStringLiteral("format");
static const QString JsonKey_Width = QStringLiteral("width");
static const QString JsonKey_Height = QStringLiteral("height");
static const QString JsonKey_ColorMode = QStringLiteral("color_mode");
static const QString JsonKey_Pixels = QStringLiteral("pixels");
static const QString JsonKey_Attribs = QStringLiteral("attribs");
static const QString JsonValue_Standard = QStringLiteral("standard");
static const QString JsonValue_Multicolor = QStringLiteral("multicolor");
static const QString JsonValue_Bicolor = QStringLiteral("bicolor");
static const QString JsonValue_Monochrome = QStringLiteral("monochrome");
static const QString JsonValue_NirvanaPlusCode = QStringLiteral("nirvana+_code");
static const int FileFormatVersion = 1;

TileEditorTab::TileEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_TileEditorTab)
    , mSavedWidth(0)
    , mSavedHeight(0)
    , mSelectedColor(-1)
{
    mUi->setupUi(this);
    mUi->editorWidget->setPreviewWidget(mUi->previewWidget);

    for (int i = 8; i <= 128; i += 8) {
        mUi->widthCombo->addItem(QString::number(i), QVariant(i));
        mUi->heightCombo->addItem(QString::number(i), QVariant(i));
    }

    mUi->colorModeCombo->addItem(tr("Standard"), JsonValue_Standard);
    mUi->colorModeCombo->addItem(tr("Multicolor (8x1)"), JsonValue_Multicolor);
    mUi->colorModeCombo->addItem(tr("Bicolor (8x2)"), JsonValue_Bicolor);
    on_colorModeCombo_currentIndexChanged(-1);

    mUi->formatCombo->addItem(tr("Bitmap (8 bytes)"), JsonValue_Monochrome);
    mUi->formatCombo->addItem(tr("NIRVANA+ code"), JsonValue_NirvanaPlusCode);

    setColor(0, false);
}

TileEditorTab::~TileEditorTab()
{
}

bool TileEditorTab::loadFile(File* f)
{
    if (f == file() && isModified())
        return true;

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

        int w = root[JsonKey_Width].toInt();
        int h = root[JsonKey_Height].toInt();

        if (!mUi->editorWidget->setPixels(w, h, root[JsonKey_Pixels].toArray(), root[JsonKey_Attribs].toArray())) {
            mUi->editorWidget->reset();
            QMessageBox::critical(this, tr("Error"),
                tr("Unable to read file \"%1\": file is corrupt.").arg(f->fileInfo().absoluteFilePath()));
            return false;
        }

        mUi->identifierEdit->setText(root[JsonKey_Identifier].toString());
        mUi->sectionEdit->setText(root[JsonKey_Section].toString());
        selectItem(mUi->formatCombo, root[JsonKey_Format].toString());
        selectItem(mUi->widthCombo, w);
        selectItem(mUi->heightCombo, h);
        selectItem(mUi->colorModeCombo, root[JsonKey_ColorMode].toString());
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

    return mUi->editorWidget->isModified();
}

bool TileEditorTab::canUndo() const
{
    return file() && mUi->editorWidget->canUndo();
}

bool TileEditorTab::canRedo() const
{
    return file() && mUi->editorWidget->canRedo();
}

bool TileEditorTab::canCut() const
{
    return file() && mUi->editorWidget->canCut();
}

bool TileEditorTab::canCopy() const
{
    return file() && mUi->editorWidget->canCopy();
}

bool TileEditorTab::canPaste() const
{
    return file() != nullptr;
}

bool TileEditorTab::canClear() const
{
    return file() && mUi->editorWidget->canClearArea();
}

bool TileEditorTab::canSelectAll() const
{
    return file() != nullptr;
}

bool TileEditorTab::canClearSelection() const
{
    return file() && mUi->editorWidget->hasSelection();
}

bool TileEditorTab::canDraw() const
{
    return file() != nullptr;
}

bool TileEditorTab::canDrawRect() const
{
    return file() != nullptr;
}

bool TileEditorTab::canFill() const
{
    return file() != nullptr;
}

bool TileEditorTab::canColorize() const
{
    return file() != nullptr;
}

bool TileEditorTab::canSelect() const
{
    return file() != nullptr;
}

bool TileEditorTab::canToggleGrid() const
{
    return file() != nullptr;
}

bool TileEditorTab::isDrawToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == TileEditorTool::Draw;
}

bool TileEditorTab::isDrawRectToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == TileEditorTool::DrawRect;
}

bool TileEditorTab::isFillToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == TileEditorTool::Fill;
}

bool TileEditorTab::isColorizeToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == TileEditorTool::Colorize;
}

bool TileEditorTab::isSelectToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == TileEditorTool::Select;
}

bool TileEditorTab::isGridActive() const
{
    return file() && mUi->editorWidget->gridVisible();
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
    root[JsonKey_Pixels] = mUi->editorWidget->pixels();
    root[JsonKey_Attribs] = mUi->editorWidget->attribs();
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

    setSaved();
    emit updateUi();

    return true;
}

void TileEditorTab::undo()
{
    mUi->editorWidget->undo();
}

void TileEditorTab::redo()
{
    mUi->editorWidget->redo();
}

void TileEditorTab::cut()
{
    mUi->editorWidget->cut();
}

void TileEditorTab::copy()
{
    mUi->editorWidget->copy();
}

void TileEditorTab::paste()
{
    mUi->editorWidget->paste();
}

void TileEditorTab::clear()
{
    mUi->editorWidget->clearArea();
}

void TileEditorTab::selectAll()
{
    mUi->editorWidget->selectAll();
}

void TileEditorTab::clearSelection()
{
    mUi->editorWidget->clearSelection();
}

void TileEditorTab::draw()
{
    mUi->editorWidget->setTool(TileEditorTool::Draw);
}

void TileEditorTab::drawRect()
{
    mUi->editorWidget->setTool(TileEditorTool::DrawRect);
}

void TileEditorTab::fill()
{
    mUi->editorWidget->setTool(TileEditorTool::Fill);
}

void TileEditorTab::colorize()
{
    mUi->editorWidget->setTool(TileEditorTool::Colorize);
}

void TileEditorTab::select()
{
    mUi->editorWidget->setTool(TileEditorTool::Select);
}

void TileEditorTab::toggleGrid()
{
    mUi->editorWidget->setGridVisible(!mUi->editorWidget->gridVisible());
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
    mUi->editorWidget->reset();
}

void TileEditorTab::setSaved()
{
    mSavedIdentifier = mUi->identifierEdit->text();
    mSavedSection = mUi->sectionEdit->text();
    mSavedFormat = selectedItem(mUi->formatCombo).toString();
    mSavedColorMode = selectedItem(mUi->colorModeCombo).toString();
    mSavedWidth = selectedItem(mUi->widthCombo).toInt();
    mSavedHeight = selectedItem(mUi->heightCombo).toInt();
    mUi->editorWidget->setSaved();
}

void TileEditorTab::on_editorWidget_sizeChanged()
{
    selectItem(mUi->widthCombo, mUi->editorWidget->width());
    selectItem(mUi->heightCombo, mUi->editorWidget->height());
}

void TileEditorTab::on_colorModeCombo_currentIndexChanged(int)
{
    TileColorMode mode;

    QString colorMode = selectedItem(mUi->colorModeCombo).toString();
    if (colorMode == JsonValue_Standard || colorMode.isEmpty())
        mode = TileColorMode::Standard;
    else if (colorMode == JsonValue_Multicolor)
        mode = TileColorMode::Multicolor;
    else if (colorMode == JsonValue_Bicolor)
        mode = TileColorMode::Bicolor;
    else {
        Q_ASSERT(false);
        return;
    }

    mUi->editorWidget->setColorMode(mode);
}

void TileEditorTab::on_widthCombo_currentIndexChanged(int)
{
    int w = selectedItem(mUi->widthCombo).toInt();
    int h = selectedItem(mUi->heightCombo).toInt();
    if (w != 0 && h != 0)
        mUi->editorWidget->setSize(w, h);
    emit updateUi();
}

void TileEditorTab::on_heightCombo_currentIndexChanged(int)
{
    int w = selectedItem(mUi->widthCombo).toInt();
    int h = selectedItem(mUi->heightCombo).toInt();
    if (w != 0 && h != 0)
        mUi->editorWidget->setSize(w, h);
    emit updateUi();
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

void TileEditorTab::setColor(int color, bool setTool)
{
    bool bright = mUi->brightCheck->isChecked();
    if (bright)
        color |= 8;
    else
        color &= ~8;

    if (mUi->blinkingCheck->isChecked())
        color |= 16;
    else
        color &= ~16;

    if (mSelectedColor != color) {
        mSelectedColor = color;

        mUi->editorWidget->setColor(color);
        if (setTool)
            mUi->editorWidget->setTool(TileEditorTool::Colorize);

        mUi->blueButton->setVisible(!bright);
        mUi->redButton->setVisible(!bright);
        mUi->magentaButton->setVisible(!bright);
        mUi->greenButton->setVisible(!bright);
        mUi->cyanButton->setVisible(!bright);
        mUi->yellowButton->setVisible(!bright);
        mUi->whiteButton->setVisible(!bright);

        mUi->brightBlueButton->setVisible(bright);
        mUi->brightRedButton->setVisible(bright);
        mUi->brightMagentaButton->setVisible(bright);
        mUi->brightGreenButton->setVisible(bright);
        mUi->brightCyanButton->setVisible(bright);
        mUi->brightYellowButton->setVisible(bright);
        mUi->brightWhiteButton->setVisible(bright);

        mUi->blackButton->setChecked((color & 7) == 0);
        mUi->blueButton->setChecked((color & 15) == 1);
        mUi->redButton->setChecked((color & 15) == 2);
        mUi->magentaButton->setChecked((color & 15) == 3);
        mUi->greenButton->setChecked((color & 15) == 4);
        mUi->cyanButton->setChecked((color & 15) == 5);
        mUi->yellowButton->setChecked((color & 15) == 6);
        mUi->whiteButton->setChecked((color & 15) == 7);

        mUi->brightBlueButton->setChecked((color & 15) == 9);
        mUi->brightRedButton->setChecked((color & 15) == 10);
        mUi->brightMagentaButton->setChecked((color & 15) == 11);
        mUi->brightGreenButton->setChecked((color & 15) == 12);
        mUi->brightCyanButton->setChecked((color & 15) == 13);
        mUi->brightYellowButton->setChecked((color & 15) == 14);
        mUi->brightWhiteButton->setChecked((color & 15) == 15);

        mUi->brightCheck->setChecked((color & 8) != 0);
        mUi->blinkingCheck->setChecked((color & 16) != 0);
    }
}
