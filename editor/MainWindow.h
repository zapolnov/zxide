#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <memory>

class IEditorTab;
class EmulatorCore;
class QLabel;
class Ui_MainWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString& path);
    ~MainWindow() override;

    IEditorTab* currentTab() const;
    bool hasModifiedFiles() const;

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    std::unique_ptr<Ui_MainWindow> mUi;
    std::vector<IEditorTab*> mEditorTabs;
    QLabel* mInsOverwriteLabel;
    QLabel* mLineColumnLabel;
    QLabel* mEmulatorSpeedLabel;
    QLabel* mBuildResultLabel;
    EmulatorCore* mEmulatorCore;

    bool confirmSave();
    bool saveAll();

    bool build();
    void clearBuildResult();

    void updateUi();

    Q_SLOT void on_actionNewFile_triggered();
    Q_SLOT void on_actionNewDirectory_triggered();
    Q_SLOT void on_actionSaveAll_triggered();
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
    Q_SLOT void on_actionStop_triggered();

    Q_SLOT void on_actionSettings_triggered();

    Q_SLOT void on_actionAbout_triggered();

    Q_SLOT void on_tabWidget_currentChanged(int index);
    Q_SLOT void on_registersDockWidget_dockLocationChanged(Qt::DockWidgetArea area);

    Q_DISABLE_COPY(MainWindow)
};

#endif
