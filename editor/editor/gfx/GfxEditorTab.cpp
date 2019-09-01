#include "GfxEditorTab.h"
#include "editor/FileManager.h"
#include "editor/EditorTabFactory.h"
#include "compiler/GfxData.h"
#include "compiler/GfxFile.h"
#include "ui_GfxEditorTab.h"
#include <QMessageBox>
#include <QSaveFile>

GfxEditorTab::GfxEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_GfxEditorTab)
    , mSavedFormat(GfxFormat::None)
    , mSavedColorMode(GfxColorMode::Standard)
    , mSavedWidth(0)
    , mSavedHeight(0)
    , mSelectedColor(-1)
{
    mUi->setupUi(this);
    mUi->editorWidget->setPreviewWidget(mUi->previewWidget);
    mUi->splitter->setSizes(QList<int>() << (width() * 4 / 5) << (width() / 5));

    for (int i = 8; i <= 256; i += 8)
        mUi->widthCombo->addItem(QString::number(i), QVariant(i));
    for (int i = 8; i <= 192; i += 8)
        mUi->heightCombo->addItem(QString::number(i), QVariant(i));

    mUi->colorModeCombo->addItem(tr("Standard"), int(GfxColorMode::Standard));
    mUi->colorModeCombo->addItem(tr("Multicolor (8x1)"), int(GfxColorMode::Multicolor));
    mUi->colorModeCombo->addItem(tr("Bicolor (8x2)"), int(GfxColorMode::Bicolor));
    on_colorModeCombo_currentIndexChanged(-1);

    mUi->formatCombo->addItem(tr("None"), int(GfxFormat::None));
    mUi->formatCombo->addItem(tr("BTile 16x16"), int(GfxFormat::BTile16));

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

    GfxFile fileData(loadFileData(f));
    if (!mUi->editorWidget->deserialize(fileData)) {
        QMessageBox::critical(this, tr("Error"),
            QCoreApplication::tr("Unable to read file \"%1\": %2")
                .arg(f->fileInfo().absoluteFilePath()).arg(fileData.lastError()));
        return false;
    }

    selectItem(mUi->formatCombo, int(fileData.format));
    selectItem(mUi->colorModeCombo, int(fileData.colorMode));
    selectItem(mUi->widthCombo, mUi->editorWidget->width());
    selectItem(mUi->heightCombo, mUi->editorWidget->height());

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

    if (mSavedFormat != GfxFormat(selectedItem(mUi->formatCombo).toInt()))
        return true;
    if (mSavedColorMode != GfxColorMode(selectedItem(mUi->colorModeCombo).toInt()))
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

    GfxFile file;
    file.format = GfxFormat(selectedItem(mUi->formatCombo).toInt());
    file.colorMode = GfxColorMode(selectedItem(mUi->colorModeCombo).toInt());
    mUi->editorWidget->serialize(file);

    QSaveFile f(fileName);
    if (!f.open(QFile::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(fileName).arg(f.errorString()));
        return false;
    }

    QByteArray fileData = file.data();
    qint64 bytesWritten = f.write(fileData);
    if (bytesWritten < 0) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(fileName).arg(f.errorString()));
        return false;
    }
    if (bytesWritten != fileData.length()) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\".").arg(fileName));
        return false;
    }

    if (!f.commit()) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(fileName).arg(f.errorString()));
        return false;
    }

    setSaved();
    emit EditorTabFactory::instance()->tileChanged();
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
    mSavedFormat = GfxFormat::None;
    mSavedColorMode = GfxColorMode::Standard;
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
    mSavedFormat = GfxFormat(selectedItem(mUi->formatCombo).toInt());
    mSavedColorMode = GfxColorMode(selectedItem(mUi->colorModeCombo).toInt());
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
    mUi->editorWidget->setColorMode(GfxColorMode(selectedItem(mUi->colorModeCombo).toInt()));
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
