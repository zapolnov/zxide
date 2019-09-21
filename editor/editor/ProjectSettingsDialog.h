#ifndef EDITOR_PROJECTSETTINGSDIALOG_H
#define EDITOR_PROJECTSETTINGSDIALOG_H

#include <QDialog>
#include <memory>

class Project;
class ProjectSettings;
class QListWidgetItem;
class Ui_ProjectSettingsDialog;

class ProjectSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectSettingsDialog(Project* project, QWidget* parent = nullptr);
    ~ProjectSettingsDialog() override;

    void done(int r) override;

private:
    std::unique_ptr<Ui_ProjectSettingsDialog> mUi;
    std::unique_ptr<ProjectSettings> mSettings;
    Project* mProject;

    Q_SLOT void on_addDefineButton_clicked();
    Q_SLOT void on_removeDefineButton_clicked();
    Q_SLOT void on_definesList_currentItemChanged(QListWidgetItem*, QListWidgetItem*) { updateUi(); }

    void updateUi();

    Q_DISABLE_COPY(ProjectSettingsDialog)
};

#endif
