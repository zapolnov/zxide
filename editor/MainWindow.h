#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class Ui_MainWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow() override;

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    std::unique_ptr<Ui_MainWindow> mUi;

    bool confirmSave();
    bool saveAll();

    void updateUi();

    Q_SLOT void on_actionSaveAll_triggered();

    Q_SLOT void on_actionUndo_triggered();
    Q_SLOT void on_actionRedo_triggered();

    Q_SLOT void on_actionCut_triggered();
    Q_SLOT void on_actionCopy_triggered();
    Q_SLOT void on_actionPaste_triggered();
    Q_SLOT void on_actionDelete_triggered();

    Q_SLOT void on_actionSelectAll_triggered();
    Q_SLOT void on_actionClearSelection_triggered();

    Q_SLOT void on_actionRun_triggered();

    Q_SLOT void on_actionAbout_triggered();

    Q_DISABLE_COPY(MainWindow)
};

#endif
