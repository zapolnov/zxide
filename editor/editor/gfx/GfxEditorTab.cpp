#include "GfxEditorTab.h"
#include "editor/FileManager.h"
#include "editor/gfx/GfxData.h"
#include "ui_GfxEditorTab.h"
#include <QMessageBox>
#include <QSaveFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

static const QString JsonKey_Version = QStringLiteral("version");
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

GfxEditorTab::GfxEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_GfxEditorTab)
    , mSavedWidth(0)
    , mSavedHeight(0)
    , mSelectedColor(-1)
{
    mUi->setupUi(this);
    mUi->editorWidget->setPreviewWidget(mUi->previewWidget);
    mUi->splitter->setSizes(QList<int>() << (width() * 4 / 5) << (width() / 5));

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

GfxEditorTab::~GfxEditorTab()
{
}

bool GfxEditorTab::loadFile(File* f)
{
    if (f == file() && isModified())
        return true;

    reset();

    QByteArray data = loadFileData(f);
    if (data.isEmpty()) {
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

        selectItem(mUi->formatCombo, root[JsonKey_Format].toString());
        selectItem(mUi->widthCombo, w);
        selectItem(mUi->heightCombo, h);
        selectItem(mUi->colorModeCombo, root[JsonKey_ColorMode].toString());
    }

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

bool GfxEditorTab::isModified() const
{
    if (!file())
        return false;

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

bool GfxEditorTab::canUndo() const
{
    return file() && mUi->editorWidget->canUndo();
}

bool GfxEditorTab::canRedo() const
{
    return file() && mUi->editorWidget->canRedo();
}

bool GfxEditorTab::canCut() const
{
    return file() && mUi->editorWidget->canCut();
}

bool GfxEditorTab::canCopy() const
{
    return file() && mUi->editorWidget->canCopy();
}

bool GfxEditorTab::canPaste() const
{
    return file() != nullptr;
}

bool GfxEditorTab::canClear() const
{
    return file() && mUi->editorWidget->canClearArea();
}

bool GfxEditorTab::canSelectAll() const
{
    return file() != nullptr;
}

bool GfxEditorTab::canClearSelection() const
{
    return file() && mUi->editorWidget->hasSelection();
}

bool GfxEditorTab::canDraw() const
{
    return file() != nullptr;
}

bool GfxEditorTab::canDrawRect() const
{
    return file() != nullptr;
}

bool GfxEditorTab::canFill() const
{
    return file() != nullptr;
}

bool GfxEditorTab::canColorize() const
{
    return file() != nullptr;
}

bool GfxEditorTab::canSelect() const
{
    return file() != nullptr;
}

bool GfxEditorTab::canToggleGrid() const
{
    return file() != nullptr;
}

bool GfxEditorTab::isDrawToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == GfxEditorTool::Draw;
}

bool GfxEditorTab::isDrawRectToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == GfxEditorTool::DrawRect;
}

bool GfxEditorTab::isFillToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == GfxEditorTool::Fill;
}

bool GfxEditorTab::isColorizeToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == GfxEditorTool::Colorize;
}

bool GfxEditorTab::isSelectToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == GfxEditorTool::Select;
}

bool GfxEditorTab::isGridActive() const
{
    return file() && mUi->editorWidget->gridVisible();
}

bool GfxEditorTab::save()
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

void GfxEditorTab::undo()
{
    mUi->editorWidget->undo();
}

void GfxEditorTab::redo()
{
    mUi->editorWidget->redo();
}

void GfxEditorTab::cut()
{
    mUi->editorWidget->cut();
}

void GfxEditorTab::copy()
{
    mUi->editorWidget->copy();
}

void GfxEditorTab::paste()
{
    mUi->editorWidget->paste();
}

void GfxEditorTab::clear()
{
    mUi->editorWidget->clearArea();
}

void GfxEditorTab::selectAll()
{
    mUi->editorWidget->selectAll();
}

void GfxEditorTab::clearSelection()
{
    mUi->editorWidget->clearSelection();
}

void GfxEditorTab::draw()
{
    mUi->editorWidget->setTool(GfxEditorTool::Draw);
}

void GfxEditorTab::drawRect()
{
    mUi->editorWidget->setTool(GfxEditorTool::DrawRect);
}

void GfxEditorTab::fill()
{
    mUi->editorWidget->setTool(GfxEditorTool::Fill);
}

void GfxEditorTab::colorize()
{
    mUi->editorWidget->setTool(GfxEditorTool::Colorize);
}

void GfxEditorTab::select()
{
    mUi->editorWidget->setTool(GfxEditorTool::Select);
}

void GfxEditorTab::toggleGrid()
{
    mUi->editorWidget->setGridVisible(!mUi->editorWidget->gridVisible());
}

void GfxEditorTab::reloadSettings()
{
}

void GfxEditorTab::setFocusToEditor()
{
    mUi->editorWidget->setFocus();
}

void GfxEditorTab::reset()
{
    mSavedFormat = QString();
    mSavedColorMode = QString();
    mSavedWidth = 0;
    mSavedHeight = 0;

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

void GfxEditorTab::setSaved()
{
    mSavedFormat = selectedItem(mUi->formatCombo).toString();
    mSavedColorMode = selectedItem(mUi->colorModeCombo).toString();
    mSavedWidth = selectedItem(mUi->widthCombo).toInt();
    mSavedHeight = selectedItem(mUi->heightCombo).toInt();
    mUi->editorWidget->setSaved();
}

void GfxEditorTab::on_editorWidget_sizeChanged()
{
    selectItem(mUi->widthCombo, mUi->editorWidget->width());
    selectItem(mUi->heightCombo, mUi->editorWidget->height());
}

void GfxEditorTab::on_colorModeCombo_currentIndexChanged(int)
{
    GfxColorMode mode;

    QString colorMode = selectedItem(mUi->colorModeCombo).toString();
    if (colorMode == JsonValue_Standard || colorMode.isEmpty())
        mode = GfxColorMode::Standard;
    else if (colorMode == JsonValue_Multicolor)
        mode = GfxColorMode::Multicolor;
    else if (colorMode == JsonValue_Bicolor)
        mode = GfxColorMode::Bicolor;
    else {
        Q_ASSERT(false);
        return;
    }

    mUi->editorWidget->setColorMode(mode);
}

void GfxEditorTab::on_widthCombo_currentIndexChanged(int)
{
    int w = selectedItem(mUi->widthCombo).toInt();
    int h = selectedItem(mUi->heightCombo).toInt();
    if (w != 0 && h != 0)
        mUi->editorWidget->setSize(w, h);
    emit updateUi();
}

void GfxEditorTab::on_heightCombo_currentIndexChanged(int)
{
    int w = selectedItem(mUi->widthCombo).toInt();
    int h = selectedItem(mUi->heightCombo).toInt();
    if (w != 0 && h != 0)
        mUi->editorWidget->setSize(w, h);
    emit updateUi();
}

bool GfxEditorTab::selectItem(QComboBox* combo, const QVariant& value)
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

QVariant GfxEditorTab::selectedItem(const QComboBox* combo)
{
    int selected = combo->currentIndex();
    return (selected < 0 ? QVariant() : combo->itemData(selected));
}

void GfxEditorTab::setColor(int color, bool setTool)
{
    if (mUi->blinkingCheck->isChecked())
        color |= 16;
    else
        color &= ~16;

    if (mSelectedColor != color) {
        mSelectedColor = color;

        mUi->editorWidget->setColor(color);
        if (setTool)
            mUi->editorWidget->setTool(GfxEditorTool::Colorize);

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

        mUi->blinkingCheck->setChecked((color & 16) != 0);
    }
}
