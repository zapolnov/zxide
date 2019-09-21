#ifndef COMPILER_IO_H
#define COMPILER_IO_H

#include <QString>

class QJsonDocument;

class IOException
{
public:
    IOException(const QString& message) : mMessage(message) {}
    ~IOException() = default;

    const QString& message() const { return mMessage; }

private:
    QString mMessage;
};

QByteArray loadFile(const QString& file);
QJsonDocument loadJson(const QString& file);

void saveFile(const QString& file, const QByteArray& data, bool canOverwrite = true);
void saveFile(const QString& file, const void* data, size_t size, bool canOverwrite = true);
void saveJson(const QString& file, const QJsonDocument& doc);

#endif
