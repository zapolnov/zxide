#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <unordered_map>
#include <memory>

class File;
class EditorTabFactory;
class AbstractEditorTab;
class Project;
class EmulatorCore;
class Ui_MainWindow;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow() override;

    void openLastProject();
    void openProject(const QString& file, bool mayLaunchNewInstance = true);

    AbstractEditorTab* currentTab() const;
    AbstractEditorTab* setCurrentTab(File* file);
    void closeTab(File* file);
    void closeTab(AbstractEditorTab* tab);

    bool hasModifiedFiles() const;

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    std::unique_ptr<Ui_MainWindow> mUi;
    AbstractEditorTab* mDummyTab;
    QLabel* mInsOverwriteLabel;
    QLabel* mLineColumnLabel;
    QLabel* mEmulatorSpeedLabel;
    QLabel* mBuildResultLabel;
    std::unique_ptr<Project> mProject;
    EmulatorCore* mEmulatorCore;
    EditorTabFactory* mTabFactory;

    bool confirmSaveAll();
    bool confirmSave(File* file);
    bool saveAll();

    bool build();
    void clearBuildResult();

    void updateUi();

    Q_SLOT void on_actionNewProject_triggered();
    Q_SLOT void on_actionOpenProject_triggered();
    Q_SLOT void on_actionNewFile_triggered();
    Q_SLOT void on_actionNewDirectory_triggered();
    Q_SLOT void on_actionSave_triggered();
    Q_SLOT void on_actionSaveAll_triggered();
    Q_SLOT void on_actionCloseWindow_triggered();
    Q_SLOT void on_actionCloseAllWindows_triggered();
    Q_SLOT void on_actionRenameFile_triggered();
    Q_SLOT void on_actionDeleteFile_triggered();
    Q_SLOT void on_actionRefreshFileList_triggered();

    Q_SLOT void on_actionUndo_triggered();
    Q_SLOT void on_actionRedo_triggered();

    Q_SLOT void on_actionCut_triggered();
    Q_SLOT void on_actionCopy_triggered();
    Q_SLOT void on_actionPaste_triggered();
    Q_SLOT void on_actionDelete_triggered();
    Q_SLOT void on_actionSelectAll_triggered();
    Q_SLOT void on_actionClearSelection_triggered();
    Q_SLOT void on_actionGoToLine_triggered();

    Q_SLOT void on_actionBuild_triggered();
    Q_SLOT void on_actionRun_triggered();
    Q_SLOT void on_actionPause_triggered();
    Q_SLOT void on_actionStop_triggered();
    Q_SLOT void on_actionStepInto_triggered();
    Q_SLOT void on_actionStepOut_triggered();
    Q_SLOT void on_actionStepOver_triggered();
    Q_SLOT void on_actionRunToCursor_triggered();

    Q_SLOT void on_actionDraw_triggered();
    Q_SLOT void on_actionDrawRect_triggered();
    Q_SLOT void on_actionFill_triggered();
    Q_SLOT void on_actionColorize_triggered();
    Q_SLOT void on_actionPick_triggered();
    Q_SLOT void on_actionSelect_triggered();

    Q_SLOT void on_actionSettings_triggered();

    Q_SLOT void on_actionAbout_triggered();

    Q_SLOT void on_tabWidget_currentChanged(int index);
    Q_SLOT void on_tabWidget_tabCloseRequested(int index);

    Q_SLOT void on_fileManager_updateUi();
    Q_SLOT void on_fileManager_fileCreated(File* file);
    Q_SLOT void on_fileManager_willRenameFile(File* file, bool* shouldAbort);
    Q_SLOT void on_fileManager_didRenameFile(File* file);
    Q_SLOT void on_fileManager_fileDoubleClicked(File* file);
    Q_SLOT void on_fileManager_fileDisappeared(File* file);

    Q_SLOT void on_registersDockWidget_dockLocationChanged(Qt::DockWidgetArea area);

    Q_DISABLE_COPY(MainWindow)
};

#endif
