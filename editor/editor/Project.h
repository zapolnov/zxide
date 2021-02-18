#ifndef EDITOR_PROJECT_H
#define EDITOR_PROJECT_H

#include <QObject>
#include <QDir>

class Project : public QObject
{
    Q_OBJECT

public:
    static const QString FileSuffix;
    static const QString GeneratedDirectory;
    static const QString OutDirectory;
    static const QString PortDirectory;

    explicit Project(QWidget* parent = nullptr);
    ~Project() override;

    QString name() const;
    const QString& file() const { return mFile; }
    const QDir& dir() const { return mDir; }

    QString tapeFileName() const;
    QString sclFileName() const;
    QString trdFileName() const;
    QString wavFileName() const;
    const QDir& projectDirectory() const { return mDir; }
    QDir generatedFilesDirectory() const;

    bool create(const QString& file);
    bool load(const QString& file);

private:
    QString mFile;
    QDir mDir;

    Q_DISABLE_COPY(Project)
};

#endif
