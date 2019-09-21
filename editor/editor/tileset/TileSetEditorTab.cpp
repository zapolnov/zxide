#include "TileSetEditorTab.h"
#include "editor/EditorTabFactory.h"
#include "editor/FileManager.h"
#include "compiler/TileSetData.h"
#include "compiler/TileSetFile.h"
#include "compiler/GfxData.h"
#include "compiler/GfxFile.h"
#include "util/ComboBox.h"
#include "util/IO.h"
#include "util/FileSelectorMenu.h"
#include "util/GfxFileUtil.h"
#include "ui_TileSetEditorTab.h"
#include <set>
#include <QMessageBox>
#include <QSaveFile>
#include <QToolButton>
#include <QTimer>
#include <functional>

static const int IconScale = 2;
static const int ButtonPadding = 8;

namespace
{
    class MyToolButton : public QToolButton
    {
    public:
        explicit MyToolButton(QWidget* parent = nullptr) : QToolButton(parent) {}
        void leaveEvent(QEvent* e) override { QToolButton::leaveEvent(e); }
    };
}

TileSetEditorTab::TileSetEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_TileSetEditorTab)
    , mImageMissingIcon(QStringLiteral(":/resources/tango16x16/image-missing.png"))
    , mSavedTileWidth(TileSetFile::MinTileWidth)
    , mSavedTileHeight(TileSetFile::MinTileHeight)
    , mModified(false)
{
    mUi->setupUi(this);

    mButtons.reserve(TileSetData::GridWidth * TileSetData::GridHeight);
    for (int y = 0; y < TileSetData::GridHeight; y++) {
        for (int x = 0; x < TileSetData::GridWidth; x++) {
            QToolButton* button = new MyToolButton(mUi->scrollAreaContents);
            button->setToolButtonStyle(Qt::ToolButtonIconOnly);
            connect(button, &QToolButton::clicked,
                this, std::bind(&TileSetEditorTab::onButtonClicked, this, button, x, y));
            mButtons.emplace_back(button);
        }
    }

    connect(EditorTabFactory::instance(), &EditorTabFactory::tileChanged, this, &TileSetEditorTab::refresh);

    for (int i = TileSetFile::MinTileWidth; i <= TileSetFile::MaxTileWidth; i += 8)
        mUi->tileWidthCombo->addItem(QString::number(i), QVariant(i));
    for (int i = TileSetFile::MinTileHeight; i <= TileSetFile::MaxTileHeight; i += 8)
        mUi->tileHeightCombo->addItem(QString::number(i), QVariant(i));

    reset();
    refresh();
}

TileSetEditorTab::~TileSetEditorTab()
{
}

bool TileSetEditorTab::loadFile(File* f)
{
    if (f == file() && isModified())
        return true;

    reset();

    TileSetFile serializer(loadFileData(f));
    if (!serializer.deserializeFromJson(&mData)) {
        QMessageBox::critical(this, tr("Error"),
            QCoreApplication::tr("Unable to read file \"%1\": %2")
                .arg(f->fileInfo().absoluteFilePath()).arg(serializer.lastError()));
        return false;
    }

    comboSelectItem(mUi->tileWidthCombo, mData.tileWidth);
    comboSelectItem(mUi->tileHeightCombo, mData.tileHeight);

    setSaved();
    refresh();
    emit updateUi();

    mUi->tileWidthCombo->setEnabled(true);
    mUi->tileHeightCombo->setEnabled(true);
    mUi->scrollArea->setEnabled(true);

    return true;
}

bool TileSetEditorTab::isModified() const
{
    return (file() && (mModified || mData.tileWidth != mSavedTileWidth || mData.tileHeight != mSavedTileHeight));
}

bool TileSetEditorTab::save()
{
    QString fileName = file()->fileInfo().absoluteFilePath();

    TileSetFile serializer;
    serializer.serializeToJson(&mData);

    try {
        saveFile(fileName, serializer.data());
    } catch (const IOException& e) {
        QMessageBox::critical(this, tr("Error"), e.message());
        return false;
    }

    setSaved();
    emit updateUi();
    emit EditorTabFactory::instance()->tileSetChanged();

    return true;
}

void TileSetEditorTab::on_tileWidthCombo_currentIndexChanged(int)
{
    int w = comboSelectedItem(mUi->tileWidthCombo).toInt();
    if (w != mData.tileWidth) {
        mData.tileWidth = w;
        emit updateUi();
        refresh();
    }
}

void TileSetEditorTab::on_tileHeightCombo_currentIndexChanged(int)
{
    int h = comboSelectedItem(mUi->tileHeightCombo).toInt();
    if (h != mData.tileHeight) {
        mData.tileHeight = h;
        emit updateUi();
        refresh();
    }
}

void TileSetEditorTab::setSaved()
{
    mSavedTileWidth = mData.tileWidth;
    mSavedTileHeight = mData.tileHeight;
    mModified = false;
}

void TileSetEditorTab::reset()
{
    mSavedTileWidth = TileSetFile::MinTileWidth;
    mSavedTileHeight = TileSetFile::MinTileHeight;

    comboSelectItem(mUi->tileWidthCombo, mSavedTileWidth);
    mUi->tileWidthCombo->setEnabled(false);
    comboSelectItem(mUi->tileHeightCombo, mSavedTileHeight);
    mUi->tileHeightCombo->setEnabled(false);
    mUi->scrollArea->setEnabled(false);
}

void TileSetEditorTab::refresh()
{
    File* f = file();
    Directory* rootDirectory = (f ? f->rootDirectory() : nullptr);

    GfxData data(0, 0);
    std::set<std::pair<int, int>> occupied;

    int tileW = mData.tileWidth;
    int tileH = mData.tileHeight;
    int scaledW = tileW * IconScale;
    int scaledH = tileH * IconScale;
    int buttonW = scaledW + ButtonPadding;
    int buttonH = scaledH + ButtonPadding;
    mUi->scrollAreaContents->setFixedSize(TileSetData::GridWidth * buttonW, TileSetData::GridHeight * buttonH);

    QStringList errors;

    for (int y = 0; y < TileSetData::GridHeight; y++) {
        for (int x = 0; x < TileSetData::GridWidth; x++) {
            int index = y * TileSetData::GridWidth + x;

            QToolButton* button = mButtons[index];
            button->setIconSize(QSize(scaledW, scaledH));
            button->setGeometry(x * buttonW, y * buttonH, buttonW, buttonH);
            button->setFixedSize(buttonW, buttonH);

            QString file = mData.tileAt(x, y);
            if (file.isEmpty()) {
                if (occupied.find(std::make_pair(x, y)) == occupied.end()) {
                    mButtons[index]->setToolTip(QString());
                    mButtons[index]->setIcon(QIcon());
                }
                continue;
            }

            mButtons[index]->setToolTip(file);
            FileOrDirectory* item = (rootDirectory ? rootDirectory->findChild(file) : nullptr);
            if (!item) {
                errors << tr("File not found: \"%1\".").arg(file);
                mButtons[index]->setIcon(mImageMissingIcon);
                continue;
            }
            if (item->type() != File::Type) {
                errors << tr("Not a file: \"%1\".").arg(file);
                mButtons[index]->setIcon(EditorTabFactory::instance()->folderIcon());
                continue;
            }

            GfxColorMode colorMode;
            if (!loadTile(static_cast<File*>(item)->fileInfo().absoluteFilePath(), &data, &errors, &colorMode)) {
                mButtons[index]->setIcon(mImageMissingIcon);
                continue;
            }

            QImage image = gfxToQImage(&data, colorMode, IconScale);
            int nx = (data.width() + tileW - 1) / tileW;
            int ny = (data.height() + tileH - 1) / tileH;
            for (int yy = 0; yy < ny; yy++) {
                for (int xx = 0; xx < nx; xx++) {
                    if (x + xx >= TileSetData::GridWidth || y + yy >= TileSetData::GridHeight)
                        continue;
                    QIcon icon = QPixmap::fromImage(image.copy(xx * scaledW, yy * scaledH, scaledW, scaledH));
                    mButtons[(y + yy) * TileSetData::GridWidth + (x + xx)]->setIcon(icon);
                    occupied.emplace(x + xx, y + yy);
                }
            }
        }
    }

    if (errors.count() > 0)
        QMessageBox::critical(this, tr("Error"), errors.join('\n'));
}

bool TileSetEditorTab::loadTile(const QString& fileName, GfxData* data, QStringList* errors, GfxColorMode* colorMode)
{
    QByteArray fileData;
    try {
        fileData = ::loadFile(fileName);
    } catch (const IOException& e) {
        *errors << e.message();
        return false;
    }

    GfxFile gfxFile(fileData);
    if (!gfxFile.deserializeFromJson(data)) {
        *errors << tr("Unable to load file \"%1\": %2").arg(fileName).arg(gfxFile.lastError());
        return false;
    }

    if (colorMode)
        *colorMode = gfxFile.colorMode;

    return true;
}

void TileSetEditorTab::onButtonClicked(QToolButton* button, int x, int y)
{
    QTimer::singleShot(0, this, [this, button, x, y] {
            button->setEnabled(false);

            File* selected = nullptr;
            if (selectFile(button, file(), &selected, QStringLiteral("gfx"))) {
                int nx = 1, ny = 1;
                QString file = (selected ? selected->relativeName() : QString());
                if (!file.isEmpty()) {
                    const int tileW = mData.tileWidth;
                    const int tileH = mData.tileHeight;

                    GfxData data(tileW, tileH);
                    QStringList errors;
                    if (!loadTile(selected->fileInfo().absoluteFilePath(), &data, &errors)) {
                        QMessageBox::critical(this, tr("Error"), errors.join('\n'));
                        return;
                    }

                    nx = (data.width() + tileW - 1) / tileW;
                    ny = (data.height() + tileH - 1) / tileH;
                }

                for (int yy = 0; yy < ny; yy++) {
                    for (int xx = 0; xx < nx; xx++)
                        mData.setTileAt(x + xx, y + yy, (xx == 0 && yy == 0 ? file : QString()));
                }

                mModified = true;
                refresh();
                emit updateUi();
            }

            button->setEnabled(true);
        });
}
