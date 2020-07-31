#include "MapEditorTab.h"
#include "editor/FileManager.h"
#include "editor/EditorTabFactory.h"
#include "compiler/MapData.h"
#include "compiler/MapFile.h"
#include "compiler/GfxData.h"
#include "compiler/GfxFile.h"
#include "compiler/TileSetData.h"
#include "compiler/TileSetFile.h"
#include "compiler/IO.h"
#include "util/ComboBox.h"
#include "util/FileSelectorMenu.h"
#include "scripting/GfxFileUtil.h"
#include "ui_MapEditorTab.h"
#include <QTimer>
#include <QIcon>
#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>

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

    mUi->entitiesVisibleCheck->setChecked(mUi->editorWidget->entitiesVisible());
    mUi->entityNamesVisibleCheck->setEnabled(mUi->editorWidget->entitiesVisible());
    mUi->entityNamesVisibleCheck->setChecked(mUi->editorWidget->entityNamesVisible());
    mUi->flashingCheck->setChecked(mUi->editorWidget->enableFlashing());

    connect(EditorTabFactory::instance(), &EditorTabFactory::tileChanged, this, &MapEditorTab::refreshTileList);
    connect(EditorTabFactory::instance(), &EditorTabFactory::tileSetChanged, this, &MapEditorTab::refreshTileList);

    refreshTileList();
}

MapEditorTab::~MapEditorTab()
{
}

void MapEditorTab::selectTile(unsigned char item)
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

    comboSelectItem(mUi->formatCombo, int(fileData.format));
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

    if (mSavedFormat != MapFormat(comboSelectedItem(mUi->formatCombo).toInt()))
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
    file.format = MapFormat(comboSelectedItem(mUi->formatCombo).toInt());
    file.tileSetFile = tilesetButtonSelection();
    mUi->editorWidget->serialize(file);

    try {
        saveFile(fileName, file.data());
    } catch (const IOException& e) {
        QMessageBox::critical(this, tr("Error"), e.message());
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
    mSavedFormat = MapFormat(comboSelectedItem(mUi->formatCombo).toInt());
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

void MapEditorTab::on_editorWidget_itemPicked(unsigned char item)
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

void MapEditorTab::on_entitiesVisibleCheck_toggled(bool flag)
{
    mUi->editorWidget->setEntitiesVisible(flag);
    mUi->entityNamesVisibleCheck->setEnabled(flag);
}

void MapEditorTab::on_entityNamesVisibleCheck_toggled(bool flag)
{
    mUi->editorWidget->setEntityNamesVisible(flag);
}

void MapEditorTab::on_flashingCheck_toggled(bool flag)
{
    mUi->editorWidget->setEnableFlashing(flag);
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

void MapEditorTab::on_exportImageButton_clicked()
{
    QString name = QStringLiteral("%1.png").arg(file()->fileInfo().completeBaseName());

    auto filter = QStringLiteral("%1 (*.png)").arg(tr("PNG files"));
    QString file = QFileDialog::getSaveFileName(this, tr("Save image"), name, filter);
    if (file.isEmpty())
        return;

    QImage image(mUi->editorWidget->size(), QImage::Format_RGB32);
    QPainter painter(&image);
    mUi->editorWidget->paint(painter);

    if (!image.save(file, "PNG")) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to save image \"%1\".").arg(file));
        return;
    }
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
        mUi->editorWidget->setTiles(tiles, 8, 8);
        return;
    }

    QString tilesetFile = tilesetButtonSelection();
    if (tilesetFile.isEmpty()) {
        mUi->editorWidget->setTiles(tiles, 8, 8);
        return;
    }

    Directory* rootDirectory = file()->rootDirectory();
    if (!rootDirectory) {
        mUi->editorWidget->setTiles(tiles, 8, 8);
        return;
    }

    FileOrDirectory* child = rootDirectory->findChild(tilesetFile);
    if (!child) {
        mUi->editorWidget->setTiles(tiles, 8, 8);
        QMessageBox::critical(this, tr("Error"), tr("File not found: \"%1\".").arg(tilesetFile));
        return;
    }
    if (child->type() != File::Type) {
        mUi->editorWidget->setTiles(tiles, 8, 8);
        QMessageBox::critical(this, tr("Error"), tr("Not a file: \"%1\".").arg(tilesetFile));
        return;
    }

    File* f = static_cast<File*>(child);
    QString fileName = f->fileInfo().absoluteFilePath();
    QByteArray fileData;

    try {
        fileData = ::loadFile(fileName);
    } catch (const IOException& e) {
        mUi->editorWidget->setTiles(tiles, 8, 8);
        QMessageBox::critical(this, tr("Error"), e.message());
        return;
    }

    TileSetFile loader(fileData);
    TileSetData tileSet;
    if (!loader.deserializeFromJson(&tileSet)) {
        mUi->editorWidget->setTiles(tiles, 8, 8);
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to load file \"%1\": %2").arg(fileName).arg(loader.lastError()));
        return;
    }

    struct Item
    {
        QString name;
        QImage image;
        int type;
        bool current;
    };

    int iconSize = qMax(tileSet.tileWidth, tileSet.tileHeight);
    std::vector<Item> items;

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

            fileName = static_cast<File*>(fileOrDirectory)->fileInfo().absoluteFilePath();
            try {
                fileData = ::loadFile(fileName);
            } catch (const IOException& e) {
                QMessageBox::critical(this, tr("Error"), e.message());
                continue;
            }

            GfxFile gfxFile(fileData);
            if (!gfxFile.deserializeFromJson(&tileData)) {
                QMessageBox::critical(this, tr("Error"),
                    tr("Unable to load file \"%1\": %2").arg(fileName).arg(gfxFile.lastError()));
                continue;
            }

            int tileIndex = y * TileSetData::GridWidth + x;
            int type = QListWidgetItem::UserType + tileIndex;
            QString name = fileOrDirectory->fileInfo().completeBaseName();
            QImage image1 = gfxToQImage(&tileData, gfxFile.colorMode, 1, false);
            QImage image2 = gfxToQImage(&tileData, gfxFile.colorMode, 1, true);
            iconSize = qMax(qMax(iconSize, image1.width()), image1.height());

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
                    tile.pixmap1 = QPixmap::fromImage(image1.copy(xx * tileW, yy * tileH, tileW, tileH));
                    tile.pixmap2 = QPixmap::fromImage(image2.copy(xx * tileW, yy * tileH, tileW, tileH));
                    tile.fullPixmap = (xx == 0 && yy == 0 ? QPixmap::fromImage(image1) : tile.pixmap1);
                    tile.width = (xx == 0 && yy == 0 ? nx : 1);
                    tile.height = (xx == 0 && yy == 0 ? ny : 1);
                    tiles[(y + yy) * TileSetData::GridWidth + (x + xx)] = tile;
                }
            }

            items.emplace_back(Item{ name, image1, type, tileIndex == selectedTile });
        }
    }

    if (iconSize > 48)
        iconSize = 48;

    for (const auto& it : items) {
        QImage image = it.image;
        if (image.width() != iconSize || image.height() != iconSize) {
            QImage fullImage(iconSize, iconSize, QImage::Format_ARGB32);
            fullImage.fill(qRgb(0x40, 0x40, 0x40));

            if (image.width() > iconSize || image.height() > iconSize)
                image = image.scaled(QSize(iconSize, iconSize), Qt::KeepAspectRatio, Qt::FastTransformation);

            QPainter painter(&fullImage);
            painter.drawImage((iconSize - image.width()) / 2, (iconSize - image.height()) / 2, image);
            image = fullImage;
        }

        QPixmap pixmap = QPixmap::fromImage(image);

        auto item = new QListWidgetItem(pixmap, it.name, mUi->paletteListWidget, it.type);
        item->setSizeHint(QSize(iconSize + 2, iconSize + 2));
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        if (it.current)
            mUi->paletteListWidget->setCurrentItem(item);
    }

    mUi->paletteListWidget->setIconSize(QSize(iconSize, iconSize));
    mUi->editorWidget->setTiles(tiles, tileSet.tileWidth, tileSet.tileHeight);
}
