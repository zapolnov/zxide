#include "Util.h"
#include "IErrorReporter.h"
#include <cctype>
#include <QApplication>
#include <QFile>
#include <QFileInfo>

std::string toLower(std::string str)
{
    for (char& ch : str)
        ch = tolower(ch);
    return str;
}

bool writeFile(const QString& fileName, const void* data, size_t size, IErrorReporter* reporter)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        reporter->error(nullptr, 0, QApplication::tr("unable to write file '%1': %2")
            .arg(QFileInfo(fileName).fileName()).arg(file.errorString()));
        QFile::remove(fileName);
        return false;
    }

    qint64 bytesWritten = file.write(reinterpret_cast<const char*>(data), qint64(size));
    if (bytesWritten < 0) {
        reporter->error(nullptr, 0, QApplication::tr("unable to write file '%1': %2")
            .arg(QFileInfo(fileName).fileName()).arg(file.errorString()));
        file.close();
        QFile::remove(fileName);
        return false;
    }

    if (bytesWritten != qint64(size)) {
        reporter->error(nullptr, 0, QApplication::tr("unable to write file '%1'").arg(QFileInfo(fileName).fileName()));
        file.close();
        QFile::remove(fileName);
        return false;
    }

    if (!file.flush()) {
        reporter->error(nullptr, 0, QApplication::tr("unable to write file '%1': %2")
            .arg(QFileInfo(fileName).fileName()).arg(file.errorString()));
        file.close();
        QFile::remove(fileName);
        return false;
    }

    return true;
}
