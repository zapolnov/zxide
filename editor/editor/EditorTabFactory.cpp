#include "EditorTabFactory.h"
#include "editor/code/CodeEditorTab.h"
#include "editor/FileManager.h"

EditorTabFactory* EditorTabFactory::mInstance;

EditorTabFactory::EditorTabFactory(QObject* parent)
    : QObject(parent)
{
    Q_ASSERT(mInstance == nullptr);
    mInstance = this;

    add<CodeEditorTab>(tr("Assembler source"), QStringLiteral("asm"));
}

EditorTabFactory::~EditorTabFactory()
{
    Q_ASSERT(mInstance == this);
    mInstance = nullptr;
}

QStringList EditorTabFactory::filters() const
{
    QStringList result;
    for (auto it = mExtensions.begin(); it != mExtensions.end(); ++it)
        result << QStringLiteral("*.%1").arg(it.key());
    return result;
}

AbstractEditorTab* EditorTabFactory::createTabForFile(File* file, QWidget* parent)
{
    auto it = mExtensions.find(file->fileInfo().suffix());
    return (it != mExtensions.end() ? it.value()(parent) : nullptr);
}
