#include "TileSetEditorTab.h"
#include "editor/EditorTabFactory.h"
#include "editor/FileManager.h"
#include "compiler/TileSetData.h"
#include "compiler/TileSetFile.h"
#include "compiler/GfxData.h"
#include "compiler/GfxFile.h"
#include "util/FileSelectorMenu.h"
#include "util/GfxFileUtil.h"
#include "ui_TileSetEditorTab.h"
#include <QMessageBox>
#include <QSaveFile>
#include <QToolButton>
#include <QTimer>
#include <functional>

static const int IconScale = 2;
static const int IconWidth = 16 * IconScale;
static const int IconHeight = 16 * IconScale;
static const int ButtonWidth = 8 + IconWidth;
static const int ButtonHeight = 8 + IconHeight;
static const int GridWidth = 16;
static const int GridHeight = 16;

TileSetEditorTab::TileSetEditorTab(QWidget* parent)
    : AbstractEditorTab(parent)
    , mUi(new Ui_TileSetEditorTab)
    , mImageMissingIcon(QStringLiteral(":/resources/tango16x16/image-missing.png"))
    , mModified(false)
{
    mUi->setupUi(this);
    mUi->scrollAreaContents->setFixedSize(GridWidth * ButtonWidth, GridHeight * ButtonHeight);

    mButtons.reserve(GridWidth * GridHeight);
    for (int y = 0; y < GridHeight; y++) {
        for (int x = 0; x < GridWidth; x++) {
            QToolButton* button = new QToolButton(mUi->scrollAreaContents);
            button->setGeometry(x * ButtonWidth, y * ButtonHeight, ButtonWidth, ButtonHeight);
            button->setToolButtonStyle(Qt::ToolButtonIconOnly);
            button->setIconSize(QSize(IconWidth, IconHeight));
            button->setFixedSize(ButtonWidth, ButtonHeight);
            connect(button, &QToolButton::clicked,
                this, std::bind(&TileSetEditorTab::onButtonClicked, this, button, x, y));
            mButtons.emplace_back(button);
        }
    }

    connect(EditorTabFactory::instance(), &EditorTabFactory::tileChanged, this, &TileSetEditorTab::refresh);
    refresh();
}

TileSetEditorTab::~TileSetEditorTab()
{
}

bool TileSetEditorTab::loadFile(File* f)
{
    if (f == file() && isModified())
        return true;

    TileSetFile serializer(loadFileData(f));
    if (!serializer.deserializeFromJson(&mData)) {
        QMessageBox::critical(this, tr("Error"),
            QCoreApplication::tr("Unable to read file \"%1\": %2")
                .arg(f->fileInfo().absoluteFilePath()).arg(serializer.lastError()));
        return false;
    }

    refresh();
    mModified = false;
    emit updateUi();

    return true;
}

bool TileSetEditorTab::isModified() const
{
    return (file() && mModified);
}

bool TileSetEditorTab::save()
{
    QString fileName = file()->fileInfo().absoluteFilePath();

    TileSetFile serializer;
    serializer.serializeToJson(&mData);

    QSaveFile f(fileName);
    if (!f.open(QFile::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"),
            tr("Unable to write file \"%1\": %2").arg(fileName).arg(f.errorString()));
        return false;
    }

    QByteArray fileData = serializer.data();
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

    mModified = false;
    emit updateUi();

    return true;
}

void TileSetEditorTab::refresh()
{
    File* f = file();
    Directory* rootDirectory = (f ? f->rootDirectory() : nullptr);

    auto data = std::make_unique<GfxData>(0, 0);

    for (int y = 0; y < GridHeight; y++) {
        for (int x = 0; x < GridWidth; x++) {
            QToolButton* button = mButtons[y * GridWidth + x];
            QString file = mData.tileAt(x, y);
            if (button->text() != file) {
                if (file.isEmpty()) {
                    mButtons[y * GridWidth + x]->setText(QString());
                    mButtons[y * GridWidth + x]->setToolTip(QString());
                    mButtons[y * GridWidth + x]->setIcon(QIcon());
                } else {
                    mButtons[y * GridWidth + x]->setText(file);
                    mButtons[y * GridWidth + x]->setToolTip(file);
                    FileOrDirectory* item = (rootDirectory ? rootDirectory->findChild(file) : nullptr);
                    if (!item) {
                        QMessageBox::critical(this, tr("Error"), tr("File not found: \"%1\".").arg(file));
                        mButtons[y * GridWidth + x]->setIcon(mImageMissingIcon);
                    } else if (item->type() != File::Type) {
                        QMessageBox::critical(this, tr("Error"), tr("Not a file: \"%1\".").arg(file));
                        mButtons[y * GridWidth + x]->setIcon(EditorTabFactory::instance()->folderIcon());
                    } else {
                        QFile file(static_cast<File*>(item)->fileInfo().absoluteFilePath());
                        if (!file.open(QFile::ReadOnly)) {
                            QMessageBox::critical(this, tr("Error"),
                                tr("Unable to open file \"%1\": %2").arg(file.fileName()).arg(file.errorString()));
                            mButtons[y * GridWidth + x]->setIcon(mImageMissingIcon);
                        } else {
                            GfxFile gfxFile(file.readAll());
                            file.close();
                            if (gfxFile.deserializeFromJson(data.get())) {
                                QIcon icon = QPixmap::fromImage(gfxToQImage(data.get(), gfxFile.colorMode, IconScale));
                                mButtons[y * GridWidth + x]->setIcon(icon);
                            } else {
                                QMessageBox::critical(this, tr("Error"),
                                    tr("Unable to load file \"%1\": %2").arg(file.fileName()).arg(gfxFile.lastError()));
                                mButtons[y * GridWidth + x]->setIcon(mImageMissingIcon);
                            }
                        }
                    }
                }
            }
        }
    }
}

void TileSetEditorTab::onButtonClicked(QToolButton* button, int x, int y)
{
    QTimer::singleShot(0, this, [this, button, x, y] {
            File* selected = nullptr;
            selectFile(button, file(), &selected, QStringLiteral("gfx"));
            mData.setTileAt(x, y, (selected ? selected->relativeName() : QString()));
            mModified = true;
            refresh();
            emit updateUi();
        });
}
