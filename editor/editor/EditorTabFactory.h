#ifndef EDITOR_EDITORTABFACTORY_H
#define EDITOR_EDITORTABFACTORY_H

#include <QObject>
#include <QHash>
#include <QIcon>
#include <functional>
#include <vector>
#include <memory>

class File;
class AbstractEditorTab;
class QFileInfo;

struct FileFormat
{
    QString name;
    QString extension;
    QIcon icon;
    std::function<AbstractEditorTab*(QWidget* parent)> factory;
};

class EditorTabFactory : public QObject
{
    Q_OBJECT

public:
    explicit EditorTabFactory(QObject* parent = nullptr);
    ~EditorTabFactory() override;

    static EditorTabFactory* instance() { return mInstance; }

    const std::vector<std::unique_ptr<FileFormat>>& formats() const { return mFormats; }

    const QIcon& iconForFile(const QFileInfo& file) const;
    AbstractEditorTab* createTabForFile(File* file, QWidget* parent);

    template <typename T, typename... ARGS>
    void add(const QString& name, const QString& extension, const QString& icon, ARGS&&... args)
    {
        Q_ASSERT(!mExtensions.contains(extension));

        auto fmt = std::make_unique<FileFormat>();
        fmt->name = name;
        fmt->extension = extension;
        fmt->icon = QIcon(icon);
        fmt->factory = [args = std::make_tuple(std::forward<ARGS>(args)...)](QWidget* p) mutable {
                AbstractEditorTab* r = nullptr;
                std::apply([&r, p](auto&&... args) { r = new T(p, std::forward<ARGS>(args)...); }, std::move(args));
                return r;
            };

        mExtensions[extension] = fmt.get();
        mFormats.emplace_back(std::move(fmt));
    }

private:
    static EditorTabFactory* mInstance;
    QIcon mUnknownFileIcon;
    std::vector<std::unique_ptr<FileFormat>> mFormats;
    QHash<QString, FileFormat*> mExtensions;

    Q_DISABLE_COPY(EditorTabFactory)
};

#endif
