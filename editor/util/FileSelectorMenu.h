#ifndef UTIL_FILESELECTORMENU_H
#define UTIL_FILESELECTORMENU_H

#include <QString>

class QWidget;
class File;
class FileOrDirectory;

bool selectFile(QWidget* parent, FileOrDirectory* anyFileOrDirectory, File** selected, const QString& extension);

#endif
