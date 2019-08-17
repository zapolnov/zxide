#include "EditorTabFactory.h"
#include "editor/code/CodeEditorTab.h"
#include "editor/FileManager.h"
#include <QFileInfo>

#define STR QStringLiteral

EditorTabFactory* EditorTabFactory::mInstance;

EditorTabFactory::EditorTabFactory(QObject* parent)
    : QObject(parent)
    , mUnknownFileIcon(STR(":/resources/fatcow16x16/rules.png"))
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;

    add<CodeEditorTab>(tr("Assembler source"), STR("asm"), STR(":/resources/fatcow16x16/page_white_text.png"));
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
