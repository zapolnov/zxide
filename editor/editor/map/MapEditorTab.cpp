#include "MapEditorTab.h"
#include "editor/FileManager.h"
#include "editor/EditorTabFactory.h"
#include "compiler/MapData.h"
#include "compiler/MapFile.h"
#include "compiler/GfxData.h"
#include "compiler/GfxFile.h"
#include "compiler/TileSetData.h"
#include "compiler/TileSetFile.h"
#include "util/FileSelectorMenu.h"
#include "util/GfxFileUtil.h"
#include "ui_MapEditorTab.h"
#include <QTimer>
#include <QIcon>
#include <QMessageBox>
#include <QSaveFile>

MapEditorTab::MapEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_MapEditorTab)
    , mSavedFormat(MapFormat::None)
    , mSavedWidth(0)
    , mSavedHeight(0)
    , mSelectedTile(-1)
{
    mUi->setupUi(this);
    mUi->splitter->setSizes(QList<int>() << (width() * 4 / 5) << (width() / 5));

    mUi->widthSpin->setRange(1, 128);
    mUi->heightSpin->setRange(1, 128);

    mUi->formatCombo->addItem(tr("None"), int(MapFormat::None));
    mUi->formatCombo->addItem(tr("Byte array"), int(MapFormat::ByteArray));

    connect(EditorTabFactory::instance(), &EditorTabFactory::tileChanged, this, &MapEditorTab::refreshTileList);
    connect(EditorTabFactory::instance(), &EditorTabFactory::tileSetChanged, this, &MapEditorTab::refreshTileList);

    refreshTileList();
}

MapEditorTab::~MapEditorTab()
{
}

void MapEditorTab::selectTile(char item)
{
    int n = mUi->paletteListWidget->count();
    for (int i = 0; i < n; i++) {
        QListWidgetItem* listItem = mUi->paletteListWidget->item(i);
        if (listItem->type() - QListWidgetItem::UserType == item) {
            mUi->paletteListWidget->setCurrentItem(listItem);
            break;
        }
    }
}

bool MapEditorTab::loadFile(File* f)
{
    if (f == file() && isModified())
        return true;

    reset();

    MapFile fileData(loadFileData(f));
    if (!mUi->editorWidget->deserialize(fileData)) {
        QMessageBox::critical(this, tr("Error"),
            QCoreApplication::tr("Unable to read file \"%1\": %2")
                .arg(f->fileInfo().absoluteFilePath()).arg(fileData.lastError()));
        return false;
    }

    selectItem(mUi->formatCombo, int(fileData.format));
    setTilesetButton(fileData.tileSetFile);
    mUi->widthSpin->setValue(mUi->editorWidget->width());
    mUi->heightSpin->setValue(mUi->editorWidget->height());

    mUi->formatCombo->setEnabled(true);
    mUi->tilesetButton->setEnabled(true);
    mUi->widthSpin->setEnabled(true);
    mUi->heightSpin->setEnabled(true);
    mUi->editScrollArea->setEnabled(true);
    mUi->paletteListWidget->setEnabled(true);

    setSaved();
    refreshTileList();
    reloadSettings();
    emit updateUi();

    return true;
}

bool MapEditorTab::isModified() const
{
    if (!file())
        return false;

    if (mSavedFormat != MapFormat(selectedItem(mUi->formatCombo).toInt()))
        return true;
    if (mSavedTileset != tilesetButtonSelection())
        return true;
    if (mSavedWidth != mUi->widthSpin->value())
        return true;
    if (mSavedHeight != mUi->heightSpin->value())
        return true;

    return mUi->editorWidget->isModified();
}

bool MapEditorTab::canUndo() const
{
    return file() && mUi->editorWidget->canUndo();
}

bool MapEditorTab::canRedo() const
{
    return file() && mUi->editorWidget->canRedo();
}

bool MapEditorTab::canCut() const
{
    return file() && mUi->editorWidget->canCut();
}

bool MapEditorTab::canCopy() const
{
    return file() && mUi->editorWidget->canCopy();
}

bool MapEditorTab::canPaste() const
{
    return file() != nullptr;
}

bool MapEditorTab::canClear() const
{
    return file() && mUi->editorWidget->canClearArea();
}

bool MapEditorTab::canSelectAll() const
{
    return file() != nullptr;
}

bool MapEditorTab::canClearSelection() const
{
    return file() && mUi->editorWidget->hasSelection();
}

bool MapEditorTab::canDraw() const
{
    return file() != nullptr;
}

bool MapEditorTab::canDrawRect() const
{
    return file() != nullptr;
}

bool MapEditorTab::canFill() const
{
    return file() != nullptr;
}

bool MapEditorTab::canPick() const
{
    return file() != nullptr;
}

bool MapEditorTab::canSelect() const
{
    return file() != nullptr;
}

bool MapEditorTab::canToggleGrid() const
{
    return file() != nullptr;
}

bool MapEditorTab::isDrawToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == MapEditorTool::Draw;
}

bool MapEditorTab::isDrawRectToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == MapEditorTool::DrawRect;
}

bool MapEditorTab::isFillToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == MapEditorTool::Fill;
}

bool MapEditorTab::isPickToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == MapEditorTool::Pick;
}

bool MapEditorTab::isSelectToolActive() const
{
    return file() && mUi->editorWidget->currentTool() == MapEditorTool::Select;
}

bool MapEditorTab::isGridActive() const
{
    return file() && mUi->editorWidget->gridVisible();
}

bool MapEditorTab::save()
{
    QString fileName = file()->fileInfo().absoluteFilePath();

    MapFile file;
    file.format = MapFormat(selectedItem(mUi->formatCombo).toInt());
    file.tileSetFile = tilesetButtonSelection();
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

void MapEditorTab::undo()
{
    mUi->editorWidget->undo();
}

void MapEditorTab::redo()
{
    mUi->editorWidget->redo();
}

void MapEditorTab::cut()
{
    mUi->editorWidget->cut();
}

void MapEditorTab::copy()
{
    mUi->editorWidget->copy();
}

void MapEditorTab::paste()
{
    mUi->editorWidget->paste();
}

void MapEditorTab::clear()
{
    mUi->editorWidget->clearArea();
}

void MapEditorTab::selectAll()
{
    mUi->editorWidget->selectAll();
}

void MapEditorTab::clearSelection()
{
    mUi->editorWidget->clearSelection();
}

void MapEditorTab::draw()
{
    mUi->editorWidget->setTool(MapEditorTool::Draw);
}

void MapEditorTab::drawRect()
{
    mUi->editorWidget->setTool(MapEditorTool::DrawRect);
}

void MapEditorTab::fill()
{
    mUi->editorWidget->setTool(MapEditorTool::Fill);
}

void MapEditorTab::pick()
{
    mUi->editorWidget->setTool(MapEditorTool::Pick);
}

void MapEditorTab::select()
{
    mUi->editorWidget->setTool(MapEditorTool::Select);
}

void MapEditorTab::toggleGrid()
{
    mUi->editorWidget->setGridVisible(!mUi->editorWidget->gridVisible());
}

void MapEditorTab::reloadSettings()
{
}

void MapEditorTab::setFocusToEditor()
{
    mUi->editorWidget->setFocus();
}

void MapEditorTab::reset()
{
    mSavedFormat = MapFormat::None;
    mSavedTileset = QString();
    mSavedWidth = 0;
    mSavedHeight = 0;

    mUi->formatCombo->setCurrentIndex(-1);
    mUi->formatCombo->setEnabled(false);
    setTilesetButton(QString());
    mUi->tilesetButton->setEnabled(false);
    mUi->widthSpin->setValue(1);
    mUi->widthSpin->setEnabled(false);
    mUi->heightSpin->setValue(1);
    mUi->heightSpin->setEnabled(false);
    mUi->editScrollArea->setEnabled(false);
    mUi->paletteListWidget->setEnabled(false);
    mUi->editorWidget->reset();

    refreshTileList();
}

void MapEditorTab::setSaved()
{
    mSavedFormat = MapFormat(selectedItem(mUi->formatCombo).toInt());
    mSavedTileset = tilesetButtonSelection();
    mSavedWidth = mUi->widthSpin->value();
    mSavedHeight = mUi->heightSpin->value();
    mUi->editorWidget->setSaved();
}

void MapEditorTab::on_editorWidget_sizeChanged()
{
    mUi->widthSpin->setValue(mUi->editorWidget->width());
    mUi->heightSpin->setValue(mUi->editorWidget->height());
}

void MapEditorTab::on_editorWidget_itemPicked(char item)
{
    selectTile(item);
}

void MapEditorTab::on_widthSpin_valueChanged(int)
{
    int w = mUi->widthSpin->value();
    mUi->editorWidget->setSize(w, mUi->editorWidget->height());
    emit updateUi();
}

void MapEditorTab::on_heightSpin_valueChanged(int)
{
    int h = mUi->heightSpin->value();
    mUi->editorWidget->setSize(mUi->editorWidget->width(), h);
    emit updateUi();
}

void MapEditorTab::on_paletteListWidget_currentItemChanged(QListWidgetItem* current, QListWidgetItem* previous)
{
    if (!current || current->type() < QListWidgetItem::UserType)
        mUi->editorWidget->setItem(0);
    else
        mUi->editorWidget->setItem(current->type() - QListWidgetItem::UserType);
}

void MapEditorTab::on_tilesetButton_clicked()
{
    QTimer::singleShot(0, this, [this] {
            File* selected = nullptr;
            if (selectFile(mUi->tilesetButton, file(), &selected, QStringLiteral("tileset"))) {
                setTilesetButton(selected ? selected->relativeName() : QString());
                refreshTileList();
                emit updateUi();
            }
        });
}

QString MapEditorTab::tilesetButtonSelection() const
{
    return mUi->tilesetButton->text();
}

void MapEditorTab::setTilesetButton(const QString& file)
{
    if (!file.isEmpty()) {
        mUi->tilesetButton->setText(file);
        mUi->tilesetButton->setIcon(QIcon());
    } else {
        mUi->tilesetButton->setText(QString());
        mUi->tilesetButton->setIcon(QIcon(QStringLiteral(":/resources/fatcow16x16/error.png")));
    }
}

void MapEditorTab::refreshTileList()
{
    QHash<int, MapEditorTile> tiles;

    int selectedTile = mUi->editorWidget->currentItem();
    mUi->paletteListWidget->clear();

    if (!file()) {
        mUi->editorWidget->setTiles(tiles);
        return;
    }

    QString tilesetFile = tilesetButtonSelection();
    if (tilesetFile.isEmpty()) {
        mUi->editorWidget->setTiles(tiles);
        return;
    }

    Directory* rootDirectory = file()->rootDirectory();
    if (!rootDirectory) {
        mUi->editorWidget->setTiles(tiles);
        return;
    }

    FileOrDirectory* child = rootDirectory->findChild(tilesetFile);
    if (!child) {
        mUi->editorWidget->setTiles(tiles);
        QMessageBox::critical(this, tr("Error"), tr("File not found: \"%1\".").arg(tilesetFile));
        return;
    }
    if (child->type() != File::Type) {
        mUi->editorWidget->setTiles(tiles);
        QMessageBox::critical(this, tr("Error"), tr("Not a file: \"%1\".").arg(tilesetFile));
        return;
    }

    File* f = static_cast<File*>(child);
    QFile file(f->fileInfo().absoluteFilePath());
    if (!file.open(QFile::ReadOnly)) {
        mUi->editorWidget->setTiles(tiles);
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to load file \"%1\": %2").arg(file.fileName()).arg(file.errorString()));
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    TileSetFile loader(fileData);
    TileSetData tileSet;
    if (!loader.deserializeFromJson(&tileSet)) {
        mUi->editorWidget->setTiles(tiles);
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to load file \"%1\": %2").arg(file.fileName()).arg(loader.lastError()));
        return;
    }

    GfxData tileData(tileSet.tileWidth, tileSet.tileHeight);
    for (int y = 0; y < TileSetData::GridHeight; y++) {
        for (int x = 0; x < TileSetData::GridWidth; x++) {
            QString tileFile = tileSet.tileAt(x, y);
            if (tileFile.isEmpty())
                continue;

            FileOrDirectory* fileOrDirectory = rootDirectory->findChild(tileFile);
            if (!fileOrDirectory) {
                QMessageBox::critical(this, tr("Error"), tr("File not found: \"%1\".").arg(tileFile));
                continue;
            }
            if (fileOrDirectory->type() != File::Type) {
                QMessageBox::critical(this, tr("Error"), tr("Not a file: \"%1\".").arg(tileFile));
                continue;
            }

            file.setFileName(static_cast<File*>(fileOrDirectory)->fileInfo().absoluteFilePath());
            if (!file.open(QFile::ReadOnly)) {
                QMessageBox::critical(this, tr("Error"),
                    tr("Unable to open file \"%1\": %2").arg(file.fileName()).arg(file.errorString()));
                continue;
            }

            GfxFile gfxFile(file.readAll());
            file.close();

            if (!gfxFile.deserializeFromJson(&tileData)) {
                QMessageBox::critical(this, tr("Error"),
                    tr("Unable to load file \"%1\": %2").arg(file.fileName()).arg(gfxFile.lastError()));
                continue;
            }

            int tileIndex = y * TileSetData::GridWidth + x;
            int type = QListWidgetItem::UserType + tileIndex;
            QString name = fileOrDirectory->fileInfo().completeBaseName();
            QImage image = gfxToQImage(&tileData, gfxFile.colorMode);
            QPixmap fullPixmap = QPixmap::fromImage(image);

            auto item = new QListWidgetItem(fullPixmap, name, mUi->paletteListWidget, type);
            item->setSizeHint(QSize(64, 64));
            item->setTextAlignment(Qt::AlignCenter);

            int tileW = tileSet.tileWidth;
            int tileH = tileSet.tileHeight;
            int nx = (tileData.width() + tileW - 1) / tileW;
            int ny = (tileData.height() + tileH - 1) / tileH;
            if (x + nx > TileSetData::GridWidth)
                nx = TileSetData::GridWidth - x;
            if (y + ny > TileSetData::GridHeight)
                ny = TileSetData::GridHeight - y;

            for (int yy = 0; yy < ny; yy++) {
                for (int xx = 0; xx < nx; xx++) {
                    MapEditorTile tile;
                    tile.pixmap = QPixmap::fromImage(image.copy(xx * tileW, yy * tileH, tileW, tileH));
                    tile.fullPixmap = (xx == 0 && yy == 0 ? fullPixmap : tile.pixmap);
                    tile.width = (xx == 0 && yy == 0 ? nx : 1);
                    tile.height = (xx == 0 && yy == 0 ? ny : 1);
                    tiles[(y + yy) * TileSetData::GridWidth + (x + xx)] = tile;
                }
            }

            if (tileIndex == selectedTile)
                mUi->paletteListWidget->setCurrentItem(item);
        }
    }

    mUi->editorWidget->setTiles(tiles);
}

bool MapEditorTab::selectItem(QComboBox* combo, const QVariant& value)
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

QVariant MapEditorTab::selectedItem(const QComboBox* combo)
{
    int selected = combo->currentIndex();
    return (selected < 0 ? QVariant() : combo->itemData(selected));
}
