#include "EditorTabFactory.h"
#include "editor/code/CodeEditorTab.h"
#include "editor/gfx/GfxEditorTab.h"
#include "editor/tileset/TileSetEditorTab.h"
#include "editor/Project.h"
#include "editor/FileManager.h"
#include <QFileInfo>

#define STR QStringLiteral

EditorTabFactory* EditorTabFactory::mInstance;

EditorTabFactory::EditorTabFactory(QObject* parent)
    : QObject(parent)
    , mUnknownFileIcon(STR(":/resources/fatcow16x16/rules.png"))
    , mFolderIcon(QStringLiteral(":/resources/fatcow16x16/folder.png"))
    , mGeneratedFolderIcon(QStringLiteral(":/resources/fatcow16x16/folder_blue.png"))
    , mRootDirectoryIcon(QStringLiteral(":/resources/fatcow16x16/book.png"))
    , mProjectFileFormat(new FileFormat)
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;

    mProjectFileFormat->name = tr("Project file");
    mProjectFileFormat->extension = Project::FileSuffix;
    mProjectFileFormat->icon = QIcon(STR(":/resources/fatcow16x16/book.png"));
    mProjectFileFormat->factory = [](QWidget* p) mutable -> AbstractEditorTab* { return nullptr; };
    mExtensions[mProjectFileFormat->extension] = mProjectFileFormat.get();

    add<CodeEditorTab>(tr("Assembler source"), STR("asm"), STR(":/resources/fatcow16x16/script_binary.png"));
    add<CodeEditorTab>(tr("Basic source"), STR("bas"), STR(":/resources/fatcow16x16/script_bricks.png"));
    add<CodeEditorTab>(tr("Build script (Lua)"), STR("lua"), STR(":/resources/fatcow16x16/modified/script_php.png"));
    add<GfxEditorTab>(tr("Graphic"), STR("gfx"), STR(":/resources/fatcow16x16/picture.png"));
    add<TileSetEditorTab>(tr("Tile set"), STR("tileset"), STR(":/resources/fatcow16x16/pictures.png"));
}

EditorTabFactory::~EditorTabFactory()
{
    Q_ASSERT(mInstance == this);
    mInstance = nullptr;
}

const QIcon& EditorTabFactory::iconForFile(const QFileInfo& file) const
{
    auto it = mExtensions.find(file.suffix());
    return (it != mExtensions.end() ? it.value()->icon : mUnknownFileIcon);
}

AbstractEditorTab* EditorTabFactory::createTabForFile(File* file, QWidget* parent)
{
    auto it = mExtensions.find(file->fileInfo().suffix());
    return (it != mExtensions.end() ? it.value()->factory(parent) : nullptr);
}
