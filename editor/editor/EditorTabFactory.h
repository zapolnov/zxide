#ifndef EDITOR_EDITORTABFACTORY_H
#define EDITOR_EDITORTABFACTORY_H

#include <QObject>
#include <QHash>
#include <functional>

class File;
class AbstractEditorTab;

class EditorTabFactory : public QObject
{
    Q_OBJECT

public:
    explicit EditorTabFactory(QObject* parent = nullptr);
    ~EditorTabFactory() override;

    static EditorTabFactory* instance() { return mInstance; }

    template <typename T, typename... ARGS> void add(const QString& name, const QString& extension, ARGS&&... args)
    {
        Q_ASSERT(!mExtensions.contains(extension));
        mExtensions[extension] =
            [args = std::make_tuple(std::forward<ARGS>(args)...)](QWidget* parent) mutable -> AbstractEditorTab* {
                AbstractEditorTab* result = nullptr;
                std::apply([&result, parent](auto&&... args) {
                        result = new T(parent, std::forward<ARGS>(args)...);
                    }, std::move(args));
                return result;
            };
    }

    QStringList filters() const;
    AbstractEditorTab* createTabForFile(File* file, QWidget* parent);

private:
    static EditorTabFactory* mInstance;
    QHash<QString, std::function<AbstractEditorTab*(QWidget* parent)>> mExtensions;

    Q_DISABLE_COPY(EditorTabFactory)
};

#endif
