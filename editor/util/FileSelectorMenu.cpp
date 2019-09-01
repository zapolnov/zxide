#include "FileSelectorMenu.h"
#include "editor/EditorTabFactory.h"
#include "editor/FileManager.h"
#include <QMenu>
#include <QCoreApplication>
#include <QWidget>
#include <functional>

static void fillMenu(QMenu* menu, const Directory* directory, const QString& ext, const std::function<void(File*)>& cb)
{
    directory->forEachSubdirectory([menu, &ext, &cb](Directory* subdir) {
            if (!subdir->isGenerated()) {
                QMenu* submenu = new QMenu(subdir->name(), menu);
                fillMenu(submenu, subdir, ext, cb);
                if (submenu->actions().count() > 0) {
                    submenu->setIcon(EditorTabFactory::instance()->folderIcon());
                    menu->addMenu(submenu);
                }
            }
        });

    directory->forEachFile([menu, &ext, &cb](File* file) {
            if (!file->isGenerated() && file->fileInfo().suffix() == ext) {
                QIcon icon = EditorTabFactory::instance()->iconForFile(file->fileInfo());
                QAction* action = menu->addAction(icon, file->name());
                QObject::connect(action, &QAction::triggered, menu, [file, &cb]{ cb(file); });
            }
        });
}

bool selectFile(QWidget* parent, FileOrDirectory* anyFileOrDirectory, File** selected, const QString& extension)
{
    Directory* rootDirectory = anyFileOrDirectory->rootDirectory();
    if (!rootDirectory)
        return false;

    std::function<void(File*)> onClicked = [selected](File* file) { *selected = file; };

    QMenu menu;
    QAction* noneAction = menu.addAction(QCoreApplication::tr("(None)"));
    QObject::connect(noneAction, &QAction::triggered, &menu, [selected]{ *selected = nullptr; });
    menu.addSeparator();
    fillMenu(&menu, rootDirectory, extension, onClicked);

    QPoint p = parent->parentWidget()->mapToGlobal(parent->geometry().center());
    return menu.exec(p);
}
