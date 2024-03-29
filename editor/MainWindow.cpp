#include "MainWindow.h"
#include "CompilerDialog.h"
#include "AboutDialog.h"
#include "SettingsDialog.h"
#include "PlayAudioDialog.h"
#include "debugger/MemoryLogWindow.h"
#include "debugger/ControlFlowLogWindow.h"
#include "debugger/BreakpointsWindow.h"
#include "debugger/BreakpointsModel.h"
#include "debugger/AddBreakpointDialog.h"
#include "debugger/EmulatorCore.h"
#include "debugger/MemoryMapDialog.h"
#include "debugger/WatchModel.h"
#include "editor/AbstractEditorTab.h"
#include "editor/EditorTabFactory.h"
#include "editor/HighlightManager.h"
#include "editor/Project.h"
#include "editor/ProjectSettingsDialog.h"
#include "editor/FileManager.h"
#include "editor/disasm/DisassemblyTab.h"
#include "compiler/Program.h"
#include "compiler/ProgramDebugInfo.h"
#include "compiler/ProgramBinary.h"
#include "compiler/IO.h"
#include "compiler/GfxFile.h"
#include "util/ClickableLabel.h"
#include "util/Settings.h"
#include "util/ImageImport.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QCloseEvent>
#include <QCheckBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QSaveFile>
#include <QDesktopServices>
#include <QTimer>
#include <QLabel>
#include <QApplication>
#include <QProcess>

MainWindow::MainWindow()
    : mUi(new Ui_MainWindow)
    , mDummyTab(new AbstractEditorTab(this))
    , mTabFactory(new EditorTabFactory(this))
{
    mBreakpointsModel = new BreakpointsModel(this);
    mWatchModel = new WatchModel(this);
    mHighlightManager = new HighlightManager(this);

    mEmulatorCore = new EmulatorCore(this);
    connect(mEmulatorCore, &EmulatorCore::updateUi, this, &MainWindow::updateUi);
    connect(mEmulatorCore, &EmulatorCore::enterDebugger, this,
        std::bind(&MainWindow::navigateToAddress, this, std::placeholders::_1, true));
    connect(mEmulatorCore, &EmulatorCore::leaveDebugger,
        mHighlightManager, std::bind(&HighlightManager::clearHighlight, mHighlightManager, Highlight::CurrentPC, true));
    connect(mEmulatorCore, &EmulatorCore::stopped, this, &MainWindow::onEmulationStopped);
    connect(mEmulatorCore, &EmulatorCore::error, this, [this](QString message) {
            QMessageBox::critical(this, tr("Emulator error"), message);
        });
    connect(mEmulatorCore, &EmulatorCore::runtoAddressChanged, this, [this](int address) {
            if (address >= 0) {
                auto loc = EmulatorCore::instance()->sourceLocationForAddress(address, true);
                File* file = (!loc.file.isEmpty() ? mUi->fileManager->file(loc.file) : nullptr);
                if (file) {
                    HighlightManager::instance()->setHighlight(Highlight::RunToCursor, loc.file, loc.line);
                    return;
                }
            }
            HighlightManager::instance()->clearHighlight(Highlight::RunToCursor);
        });

    mUi->setupUi(this);

    mUi->actionLoadAsTAP->setChecked(true);
    mUi->actionLoadAsTRD->setChecked(false);

    mUi->memoryWidget->setScrollBar(mUi->memoryWidgetScrollBar);
    mUi->watchView->setModel(WatchModel::instance());

    tabifyDockWidget(mUi->registersDockWidget, mUi->stackDockWidget);
    tabifyDockWidget(mUi->memoryDockWidget, mUi->watchDockWidget);
    QTimer::singleShot(0, mUi->registersDockWidget, &QDockWidget::raise);
    QTimer::singleShot(0, mUi->memoryDockWidget, &QDockWidget::raise);

    mInsOverwriteLabel = new QLabel(mUi->statusBar);
    mInsOverwriteLabel->setFixedWidth(35);
    mInsOverwriteLabel->setFrameShape(QFrame::StyledPanel);
    mInsOverwriteLabel->setFrameShadow(QFrame::Sunken);
    mInsOverwriteLabel->setAlignment(Qt::AlignCenter);
    mUi->statusBar->addPermanentWidget(mInsOverwriteLabel);

    mLineColumnLabel = new QLabel(mUi->statusBar);
    mLineColumnLabel->setFixedWidth(120);
    mLineColumnLabel->setFrameShape(QFrame::StyledPanel);
    mLineColumnLabel->setFrameShadow(QFrame::Sunken);
    mLineColumnLabel->setAlignment(Qt::AlignCenter);
    mUi->statusBar->addPermanentWidget(mLineColumnLabel);

    mEmulatorSpeedLabel = new QLabel(mUi->statusBar);
    mEmulatorSpeedLabel->setFixedWidth(70);
    mEmulatorSpeedLabel->setFrameShape(QFrame::StyledPanel);
    mEmulatorSpeedLabel->setFrameShadow(QFrame::Sunken);
    mEmulatorSpeedLabel->setAlignment(Qt::AlignCenter);
    mUi->statusBar->addPermanentWidget(mEmulatorSpeedLabel);

    mBuildResultLabel = new ClickableLabel(mUi->statusBar);
    mUi->statusBar->addWidget(mBuildResultLabel);
    clearBuildResult();

    for (QMenu* menu : { mUi->menuTutorials, mUi->menuReferences, mUi->menuBooks, mUi->menuCodeSnippets }) {
        for (QAction* action : menu->actions())
            connect(action, &QAction::triggered, this, &MainWindow::openUsefulLink);
    }

    updateUi();
}

MainWindow::~MainWindow()
{
    delete mEmulatorCore;
}

void MainWindow::openLastProject()
{
    Settings settings;
    if (settings.loadLastProjectOnStart()) {
        QString lastProject = settings.lastProjectFile();
        if (!lastProject.isEmpty())
            openProject(lastProject, false);
    }
}

void MainWindow::openProject(const QString& file, bool mayLaunchNewInstance)
{
    Settings settings;
    settings.setLastProjectFile(file);

    auto project = std::make_unique<Project>(this);
    if (!project->load(file))
        return;

    if (mProject) {
        if (!QProcess::startDetached(QApplication::applicationFilePath(), QStringList() << file))
            QMessageBox::critical(this, tr("Error"), tr("Unable to launch new instance of the application."));
    } else {
        mProject = std::move(project);
        setWindowTitle(QStringLiteral("%1[*] - %2").arg(mProject->name()).arg(windowTitle()));
        mUi->fileManager->init(mProject->dir().absolutePath());
        updateUi();
    }
}

DisassemblyTab* MainWindow::disassemblyTab() const
{
    int n = mUi->tabWidget->count();
    for (int i = 0; i < n; i++) {
        auto tab = qobject_cast<AbstractEditorTab*>(mUi->tabWidget->widget(i));
        Q_ASSERT(tab != nullptr);
        if (tab && tab->isDisassembly()) {
            auto dtab = qobject_cast<DisassemblyTab*>(tab);
            Q_ASSERT(dtab != nullptr);
            return dtab;
        }
    }
    return nullptr;
}

AbstractEditorTab* MainWindow::currentTab() const
{
    QWidget* widget = mUi->tabWidget->currentWidget();
    if (widget == nullptr)
        return mDummyTab;

    auto tab = qobject_cast<AbstractEditorTab*>(widget);
    Q_ASSERT(tab != nullptr);
    if (tab == nullptr)
        return mDummyTab;

    return tab;
}

AbstractEditorTab* MainWindow::setCurrentTab(File* file)
{
    if (!file)
        return nullptr;

    AbstractEditorTab* tab = file->tab();
    if (!tab) {
        tab = file->createTab(this);
        if (!tab)
            return nullptr;

        if (!tab->loadFile(file)) {
            file->destroyTab();
            tab->deleteLater();
            return nullptr;
        }

        connect(tab, &AbstractEditorTab::updateUi, this, &MainWindow::updateUi);
        mUi->tabWidget->addTab(tab, file->name());
    }

    if (tab != currentTab()) {
        mUi->tabWidget->setCurrentWidget(tab);
        if (mUi->fileManager && mUi->fileManager->selectedFileOrDirectory() != file)
            mUi->fileManager->selectFileOrDirectory(file);
        tab->loadFile(file);
    }

    updateUi();

    return tab;
}

void MainWindow::closeTab(File* file)
{
    if (file)
        closeTab(file->tab());
}

void MainWindow::closeTab(AbstractEditorTab* tab)
{
    // FIXME: check if saved !!!

    if (!tab || tab == mDummyTab)
        return;

    if (currentTab() == tab)
        mUi->fileManager->selectFileOrDirectory(nullptr);

    int index = mUi->tabWidget->indexOf(tab);
    Q_ASSERT(index >= 0);
    mUi->tabWidget->removeTab(index);

    if (tab->isDisassembly())
        tab->deleteLater();
    else {
        Q_ASSERT(tab->file());
        if (tab->file())
            tab->file()->destroyTab();
        else
            tab->deleteLater();
    }

    updateUi();
}

bool MainWindow::hasModifiedFiles() const
{
    int n = mUi->tabWidget->count();
    for (int i = 0; i < n; i++) {
        auto tab = qobject_cast<AbstractEditorTab*>(mUi->tabWidget->widget(i));
        Q_ASSERT(tab != nullptr);
        if (tab && tab->isModified())
            return true;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (confirmSaveAll())
        event->accept();
    else
        event->ignore();
}

bool MainWindow::confirmSaveAll()
{
    if (!hasModifiedFiles())
        return true;

    QMessageBox msgbox(QMessageBox::Warning, tr("Confirmation"), tr("Save changes?"), QMessageBox::NoButton, this);
    auto btnSave = msgbox.addButton(tr("Save changes"), QMessageBox::AcceptRole);
    auto btnDontSave = msgbox.addButton(tr("Discard changes"), QMessageBox::DestructiveRole);
    auto btnCancel = msgbox.addButton(tr("Cancel"), QMessageBox::RejectRole);
    msgbox.setDefaultButton(btnCancel);
    msgbox.setEscapeButton(btnCancel);
    msgbox.exec();

    auto clicked = msgbox.clickedButton();
    if (clicked == btnSave)
        return saveAll();
    if (clicked == btnDontSave)
        return true;

    return false;
}

bool MainWindow::confirmSave(File* file)
{
    if (!file)
        return true;

    AbstractEditorTab* tab = file->tab();
    if (!tab || !tab->isModified())
        return true;

    QMessageBox msgbox(QMessageBox::Warning,
        tr("Confirmation"), tr("Save changes to \"%1\"?").arg(file->name()), QMessageBox::NoButton, this);
    auto btnSave = msgbox.addButton(tr("Save"), QMessageBox::AcceptRole);
    auto btnDiscard = msgbox.addButton(tr("Discard"), QMessageBox::DestructiveRole);
    auto btnCancel = msgbox.addButton(tr("Cancel"), QMessageBox::RejectRole);
    msgbox.setDefaultButton(btnCancel);
    msgbox.setEscapeButton(btnCancel);
    msgbox.exec();

    auto clicked = msgbox.clickedButton();
    if (clicked == btnSave)
        return tab->save();
    else if (clicked == btnDiscard)
        return true;

    return false;
}

bool MainWindow::saveAll()
{
    bool success = true;
    int n = mUi->tabWidget->count();
    for (int i = 0; i < n; i++) {
        auto tab = qobject_cast<AbstractEditorTab*>(mUi->tabWidget->widget(i));
        Q_ASSERT(tab != nullptr);
        if (tab && !tab->save())
            success = false;
    }
    return success;
}

bool MainWindow::build()
{
    if (!mProject)
        return false;
    if (mEmulatorCore->isRunning())
        return false;

    if (hasModifiedFiles()) {
        Settings settings;
        if (!settings.autoSaveBeforeCompile()) {
            QCheckBox* autoSaveCheck = new QCheckBox(this);
            autoSaveCheck->setText(tr("Automatically save files before each build"));

            QMessageBox msgbox(QMessageBox::Warning, tr("Confirmation"),
                QStringLiteral("%1\n\n%2")
                    .arg(tr("All modified files have to be saved before compiling the code."))
                    .arg(tr("Save all files now?")),
                QMessageBox::NoButton, this);
            msgbox.addButton(tr("Save all and build"), QMessageBox::AcceptRole);
            auto btnCancel = msgbox.addButton(tr("Cancel"), QMessageBox::RejectRole);
            msgbox.setCheckBox(autoSaveCheck);
            msgbox.setDefaultButton(btnCancel);
            msgbox.setEscapeButton(btnCancel);
            msgbox.exec();

            auto clicked = msgbox.clickedButton();
            if (clicked == btnCancel) {
                clearBuildResult();
                return false;
            }

            if (autoSaveCheck->isChecked())
                settings.setAutoSaveBeforeCompile(true);
        }

        if (!saveAll()) {
            clearBuildResult();
            return false;
        }
    }

    HighlightManager::instance()->clearHighlight(Highlight::Error);

    mBuildResultLabel->setToolTip(QString());
    mBuildResultLabel->setText(tr("Compiling..."));
    mBuildResultLabel->setStyleSheet(QStringLiteral("color: #ccaa00; font-weight: bold; padding-right: 5px"));

    CompilerDialog dlg(this);
    dlg.setProjectFile(mProject->file());
    dlg.setProjectDirectory(mProject->projectDirectory());
    dlg.setGeneratedFilesDirectory(mProject->generatedFilesDirectory());
    dlg.setOutputWavFile(mProject->wavFileName());
    dlg.setOutputTapeFile(mProject->tapeFileName());
    dlg.setOutputSclFile(mProject->sclFileName());
    dlg.setOutputTrdFile(mProject->trdFileName());

    std::vector<File*> files;
    mUi->fileManager->enumerateFiles(files, false);
    for (File* file : files)
        dlg.addSourceFile(file);

    connect(&dlg, &CompilerDialog::compilationSucceeded, this, [this, &dlg]() {
            clearBuildResult();

            auto binary = dlg.takeProgramBinary();
            ProgramDebugInfo* debugInfo = binary->debugInfo();
            EmulatorCore::instance()->setProgramBinary(std::move(binary));

            int n = mUi->tabWidget->count();
            for (int i = 0; i < n; i++) {
                auto tab = qobject_cast<AbstractEditorTab*>(mUi->tabWidget->widget(i));
                Q_ASSERT(tab != nullptr);
                if (tab)
                    tab->updateTStates(debugInfo);
            }

            mUi->fileManager->refresh();
            updateUi();
        });
    connect(&dlg, &CompilerDialog::compilationFailed, this,
        [this](const QString& fileName, int line, const QString& errorMessage) {
            File* file = (!fileName.isEmpty() ? mUi->fileManager->file(fileName) : nullptr);

            QString message;
            if (!file)
                message = errorMessage;
            else if (file && line <= 0) {
                setCurrentTab(file);
                message = tr("%1: %2").arg(file->fileInfo().fileName()).arg(errorMessage);
            } else {
                auto tab = setCurrentTab(file);
                if (tab)
                    tab->goToLine(line - 1);
                HighlightManager::instance()->setHighlight(Highlight::Error, fileName, line);
                if (tab)
                    tab->setFocusToEditor();
                QApplication::setActiveWindow(this);
                message = tr("%1(%2): %3").arg(file->fileInfo().fileName()).arg(line).arg(errorMessage);
            }

            mBuildResultLabel->setText(message);
            mBuildResultLabel->setToolTip(message);
            mBuildResultLabel->setStyleSheet(QStringLiteral("color: red; font-weight: bold; padding-right: 5px"));
            connect(mBuildResultLabel, &ClickableLabel::doubleClicked, this, [this, fileName, line]{
                    HighlightManager::instance()->clearHighlight(Highlight::Error);
                    File* file = (!fileName.isEmpty() ? mUi->fileManager->file(fileName) : nullptr);
                    if (file) {
                        auto tab = setCurrentTab(file);
                        if (line > 0) {
                            tab->goToLine(line - 1);
                            HighlightManager::instance()->setHighlight(Highlight::Error, fileName, line);
                            tab->setFocusToEditor();
                            QApplication::setActiveWindow(this);
                        }
                    }
                });

            mUi->fileManager->refresh();
            updateUi();
        });

    return dlg.runCompiler();
}

void MainWindow::clearBuildResult()
{
    mBuildResultLabel->setToolTip(QString());
    mBuildResultLabel->setText(tr("Ready"));
    mBuildResultLabel->setStyleSheet(QStringLiteral("color: black; font-weight: bold; padding-right: 5px"));
    mBuildResultLabel->disconnect(this);
}

void MainWindow::navigateToAddress(unsigned address, bool setHighlight)
{
    SourceLocation loc = EmulatorCore::instance()->sourceLocationForAddress(address, true);
    File* file = (!loc.file.isEmpty() ? mUi->fileManager->file(loc.file) : nullptr);

    if (setHighlight) {
        if (file)
            HighlightManager::instance()->setHighlight(Highlight::CurrentPC, loc.file, loc.line);
        else
            HighlightManager::instance()->clearHighlight(Highlight::CurrentPC);
    }

    if (file) {
        auto tab = setCurrentTab(file);
        if (tab && tab->canGoToLine()) {
            tab->goToLine(loc.line - 1);
            tab->setFocusToEditor();
            QApplication::setActiveWindow(this);
            return;
        }
    }

    on_actionDisassembly_triggered();
}

void MainWindow::onEmulationStopped()
{
    mHighlightManager->clearHighlight(Highlight::CurrentPC, true);
    auto tab = disassemblyTab();
    if (tab)
        tab->deleteLater();
}

void MainWindow::updateUi()
{
    bool modified = hasModifiedFiles();
    bool emulatorRunning = mEmulatorCore->isRunning();

    setWindowModified(modified);

    AbstractEditorTab* tab = currentTab();
    mUi->actionSave->setEnabled(tab->isModified());
    mUi->actionSaveAll->setEnabled(modified);
    mUi->actionCloseWindow->setEnabled(tab != nullptr && tab != mDummyTab);
    mUi->actionCloseAllWindows->setEnabled(mUi->tabWidget->count() > 0);
    mUi->actionNewFile->setEnabled(mProject && mUi->fileManager->canCreateFile());
    mUi->actionNewDirectory->setEnabled(mProject && mUi->fileManager->canCreateDirectory());
    mUi->actionImportPNG->setEnabled(mProject && mUi->fileManager->canCreateFile());
    mUi->actionImportSCR->setEnabled(mProject && mUi->fileManager->canCreateFile());
    mUi->actionRenameFile->setEnabled(mProject && mUi->fileManager->canRename());
    mUi->actionDuplicateFile->setEnabled(mProject && mUi->fileManager->canDuplicate());
    mUi->actionDeleteFile->setEnabled(mProject && mUi->fileManager->canDelete());
    mUi->actionRefreshFileList->setEnabled(mProject != nullptr);
    mUi->actionUndo->setEnabled(tab->canUndo());
    mUi->actionRedo->setEnabled(tab->canRedo());
    mUi->actionCut->setEnabled(tab->canCut());
    mUi->actionCopy->setEnabled(tab->canCopy());
    mUi->actionPaste->setEnabled(tab->canPaste());
    mUi->actionDelete->setEnabled(tab->canClear());
    mUi->actionSelectAll->setEnabled(tab->canSelectAll());
    mUi->actionClearSelection->setEnabled(tab->canClearSelection());
    mUi->actionGoToLine->setEnabled(tab->canGoToLine());
    mUi->actionDraw->setEnabled(tab->canDraw());
    mUi->actionDrawRect->setEnabled(tab->canDrawRect());
    mUi->actionFill->setEnabled(tab->canFill());
    mUi->actionColorize->setEnabled(tab->canColorize());
    mUi->actionPick->setEnabled(tab->canPick());
    mUi->actionSelect->setEnabled(tab->canSelect());
    mUi->actionToggleGrid->setEnabled(tab->canToggleGrid());
    mUi->actionRotateClockwise->setEnabled(tab->canRotateClockwise());
    mUi->actionRotateCounterClockwise->setEnabled(tab->canRotateCounterClockwise());
    mUi->actionFlipVertically->setEnabled(tab->canFlipVertical());
    mUi->actionFlipHorizontally->setEnabled(tab->canFlipHorizontal());
    mUi->actionBuild->setEnabled(mProject && !emulatorRunning);
    mUi->actionViewMemoryMap->setEnabled(mProject && mEmulatorCore->hasProgramBinary());
    mUi->actionPlayAudio->setEnabled(mProject && !emulatorRunning);
    mUi->actionRun->setEnabled(mProject && (!emulatorRunning || mEmulatorCore->isPaused()));
    mUi->actionPause->setEnabled(emulatorRunning && !mEmulatorCore->isPaused());
    mUi->actionPause->setChecked(emulatorRunning && mEmulatorCore->isPaused());
    mUi->actionStop->setEnabled(emulatorRunning);
    mUi->actionStepInto->setEnabled(emulatorRunning && mEmulatorCore->isPaused());
    mUi->actionStepOut->setEnabled(emulatorRunning && mEmulatorCore->isPaused());
    mUi->actionStepOver->setEnabled(emulatorRunning && mEmulatorCore->isPaused());
    mUi->actionRunToCursor->setEnabled(emulatorRunning && mEmulatorCore->isPaused() && tab->canRunToCursor());
    mUi->actionToggleBreakpoint->setEnabled(tab->canToggleBreakpoint());
    mUi->actionDisassembly->setEnabled(emulatorRunning);
    mUi->actionLoadAsTAP->setEnabled(mProject && !emulatorRunning);
    mUi->actionLoadAsTRD->setEnabled(mProject && !emulatorRunning);
    mUi->actionLoadSnapshot->setEnabled(mProject && !emulatorRunning);
    mUi->actionEditProjectSettings->setEnabled(mProject != nullptr);

    mUi->actionDraw->setChecked(tab->isDrawToolActive());
    mUi->actionDrawRect->setChecked(tab->isDrawRectToolActive());
    mUi->actionFill->setChecked(tab->isFillToolActive());
    mUi->actionColorize->setChecked(tab->isColorizeToolActive());
    mUi->actionPick->setChecked(tab->isPickToolActive());
    mUi->actionSelect->setChecked(tab->isSelectToolActive());
    mUi->actionToggleGrid->setChecked(tab->isGridActive());

    mLineColumnLabel->setText(tab->lineColumnLabelText());
    mInsOverwriteLabel->setText(tab->insOverwriteLabelText());
    mEmulatorSpeedLabel->setText(QStringLiteral("%1 %2")
        .arg(mEmulatorCore->currentSpeedString()).arg(mEmulatorCore->currentMachineShortName()));

    if (!mUi->displayDockWidget->isVisible() || emulatorRunning)
        mUi->displayDockWidget->setVisible(emulatorRunning);
    else {
        // clear out remaining picture from the framebuffer
        QDockWidget* dockWidget = mUi->displayDockWidget;
        DisplayWidget* displayWidget = mUi->displayWidget;

        #pragma warning(push)
        #pragma warning(disable:4573) // 'QObject::disconnect' requires the compiler to capture 'this' (NB: not really)
        auto conn = std::make_shared<QMetaObject::Connection>();
        *conn = connect(displayWidget, &QOpenGLWidget::frameSwapped, dockWidget, [dockWidget, conn] {
                if (!EmulatorCore::instance()->isRunning())
                    dockWidget->hide();
                QObject::disconnect(*conn);
            });
        #pragma warning(pop)

        displayWidget->repaint();
    }

    mUi->registersDockWidget->setVisible(emulatorRunning);
    mUi->stackDockWidget->setVisible(emulatorRunning);
    mUi->memoryDockWidget->setVisible(emulatorRunning);
    mUi->watchDockWidget->setVisible(emulatorRunning);

    mUi->fileManager->setEnabled(mProject != nullptr);
}

void MainWindow::on_actionNewProject_triggered()
{
    Settings settings;
    auto filter = QStringLiteral("%1 (*.%2)").arg(tr("Project files")).arg(Project::FileSuffix);
    QString file = QFileDialog::getSaveFileName(this, tr("Create project"), settings.lastProjectFile(), filter);
    if (file.isEmpty())
        return;

    settings.setLastProjectFile(file);

    auto project = std::make_unique<Project>(this);
    if (!project->create(file))
        return;

    if (mProject) {
        if (!QProcess::startDetached(QApplication::applicationFilePath(), QStringList() << file))
            QMessageBox::critical(this, tr("Error"), tr("Unable to launch new instance of the application."));
    } else {
        mProject = std::move(project);
        setWindowTitle(QStringLiteral("%1[*] - %2").arg(mProject->name()).arg(windowTitle()));
        mUi->fileManager->init(mProject->dir().absolutePath());
        updateUi();
    }
}

void MainWindow::on_actionOpenProject_triggered()
{
    Settings settings;
    auto filter = QStringLiteral("%1 (*.%2)").arg(tr("Project files")).arg(Project::FileSuffix);
    QString file = QFileDialog::getOpenFileName(this, tr("Open project"), settings.lastProjectFile(), filter);
    if (file.isEmpty())
        return;

    openProject(file);
}

void MainWindow::on_actionEditProjectSettings_triggered()
{
    try {
        ProjectSettingsDialog dlg(mProject.get(), this);
        dlg.exec();
    } catch (const IOException& e) {
        QMessageBox::critical(this, tr("Error"), e.message());
    }
}

void MainWindow::on_actionNewFile_triggered()
{
    if (mProject)
        mUi->fileManager->createFile();
}

void MainWindow::on_actionNewDirectory_triggered()
{
    if (mProject)
        mUi->fileManager->createDirectory();
}

void MainWindow::on_actionSave_triggered()
{
    currentTab()->save();
}

void MainWindow::on_actionSaveAll_triggered()
{
    saveAll();
}

void MainWindow::on_actionCloseWindow_triggered()
{
    auto tab = currentTab();
    if (tab)
        closeTab(tab);
}

void MainWindow::on_actionCloseAllWindows_triggered()
{
    while (mUi->tabWidget->count() > 0) {
        auto tab = qobject_cast<AbstractEditorTab*>(mUi->tabWidget->widget(0));
        Q_ASSERT(tab != nullptr);
        if (!tab)
            break;
        closeTab(tab);
    }
}

void MainWindow::on_actionImportPNG_triggered()
{
    Directory* parent = mUi->fileManager->selectedParentDirectory();
    if (!parent)
        return;

    Settings settings;
    auto filter = QStringLiteral("%1 (*.png)").arg(tr("PNG files"));
    QString fileName = QFileDialog::getOpenFileName(this, tr("Import image"), settings.lastImportedPNG(), filter);
    if (fileName.isEmpty())
        return;

    settings.setLastImportedPNG(fileName);

    QImage image;
    if (!image.load(fileName)) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to load image \"%1\".").arg(fileName));
        return;
    }

    // FIXME: extension should go from a constant
    QString name = QStringLiteral("%1.gfx").arg(QFileInfo(fileName).completeBaseName());

    QDir dir(parent->fileInfo().absoluteFilePath());
    QSaveFile file(dir.absoluteFilePath(name));
    if (QFileInfo(file.fileName()).exists()) {
        QMessageBox::critical(this, tr("Error"), tr("File or directory \"%1\" already exists.").arg(name));
        return;
    }

    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to create file \"%1\" in \"%2\": %3")
            .arg(name).arg(dir.absolutePath()).arg(file.errorString()));
        return;
    }

    auto gfxData = importMonochromeImage(image);

    GfxFile gfxFile;
    gfxFile.format = GfxFormat::None;
    gfxFile.colorMode = GfxColorMode::Standard;
    gfxFile.serializeToJson(gfxData.get());
    const QByteArray& data = gfxFile.data();

    qint64 bytesWritten = file.write(data.constData(), data.length());
    if (bytesWritten < 0) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\" in \"%2\": %3")
            .arg(name).arg(dir.absolutePath()).arg(file.errorString()));
        return;
    }
    if (bytesWritten != data.length()) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\" in \"%2\": %3")
            .arg(name).arg(dir.absolutePath()).arg(tr("incomplete write.")));
        return;
    }

    if (!file.commit()) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\" in \"%2\": %3")
            .arg(name).arg(dir.absolutePath()).arg(file.errorString()));
        return;
    }

    mUi->fileManager->refreshDirectory(parent);

    File* newFile = parent->file(name);
    Q_ASSERT(newFile);
    if (newFile) {
        mUi->fileManager->selectFileOrDirectory(newFile);
        on_fileManager_fileCreated(newFile);
    }
}

void MainWindow::on_actionImportSCR_triggered()
{
    Directory* parent = mUi->fileManager->selectedParentDirectory();
    if (!parent)
        return;

    Settings settings;
    auto filter = QStringLiteral("%1 (*.scr)").arg(tr("SCR files"));
    QString fileName = QFileDialog::getOpenFileName(this, tr("Import screen"), settings.lastImportedSCR(), filter);
    if (fileName.isEmpty())
        return;

    settings.setLastImportedSCR(fileName);

    QByteArray scrData;
    try {
        scrData = loadFile(fileName);
    } catch (const IOException& e) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to load file \"%1\": %2").arg(fileName).arg(e.message()));
        return;
    }

    // FIXME: extension should go from a constant
    QString name = QStringLiteral("%1.gfx").arg(QFileInfo(fileName).completeBaseName());

    QDir dir(parent->fileInfo().absoluteFilePath());
    QSaveFile file(dir.absoluteFilePath(name));
    if (QFileInfo(file.fileName()).exists()) {
        QMessageBox::critical(this, tr("Error"), tr("File or directory \"%1\" already exists.").arg(name));
        return;
    }

    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to create file \"%1\" in \"%2\": %3")
            .arg(name).arg(dir.absolutePath()).arg(file.errorString()));
        return;
    }

    auto gfxData = importScrFile(scrData);

    GfxFile gfxFile;
    gfxFile.format = GfxFormat::None;
    gfxFile.colorMode = GfxColorMode::Standard;
    gfxFile.serializeToJson(gfxData.get());
    const QByteArray& data = gfxFile.data();

    qint64 bytesWritten = file.write(data.constData(), data.length());
    if (bytesWritten < 0) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\" in \"%2\": %3")
            .arg(name).arg(dir.absolutePath()).arg(file.errorString()));
        return;
    }
    if (bytesWritten != data.length()) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\" in \"%2\": %3")
            .arg(name).arg(dir.absolutePath()).arg(tr("incomplete write.")));
        return;
    }

    if (!file.commit()) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to write file \"%1\" in \"%2\": %3")
            .arg(name).arg(dir.absolutePath()).arg(file.errorString()));
        return;
    }

    mUi->fileManager->refreshDirectory(parent);

    File* newFile = parent->file(name);
    Q_ASSERT(newFile);
    if (newFile) {
        mUi->fileManager->selectFileOrDirectory(newFile);
        on_fileManager_fileCreated(newFile);
    }
}

void MainWindow::on_actionRenameFile_triggered()
{
    if (mProject)
        mUi->fileManager->renameSelected();
}

void MainWindow::on_actionDuplicateFile_triggered()
{
    if (mProject)
        mUi->fileManager->duplicateSelected();
}

void MainWindow::on_actionDeleteFile_triggered()
{
    if (mProject)
        mUi->fileManager->deleteSelected();
}

void MainWindow::on_actionRefreshFileList_triggered()
{
    if (mProject)
        mUi->fileManager->refresh();
}

void MainWindow::on_actionUndo_triggered()
{
    currentTab()->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    currentTab()->redo();
}

void MainWindow::on_actionCut_triggered()
{
    currentTab()->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    currentTab()->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    currentTab()->paste();
}

void MainWindow::on_actionDelete_triggered()
{
    currentTab()->clear();
}

void MainWindow::on_actionSelectAll_triggered()
{
    currentTab()->selectAll();
}

void MainWindow::on_actionClearSelection_triggered()
{
    currentTab()->clearSelection();
}

void MainWindow::on_actionGoToLine_triggered()
{
    auto tab = currentTab();
    if (tab->canGoToLine()) {
        QInputDialog dlg(this);
        dlg.setInputMode(QInputDialog::IntInput);
        dlg.setWindowTitle(tr("Go to line"));
        dlg.setLabelText(tr("Line number:"));
        dlg.setIntRange(1, INT_MAX);
        dlg.setIntStep(1);
        dlg.setIntValue(1);
        if (dlg.exec() != QDialog::Accepted)
            return;
        tab->goToLine(dlg.intValue() - 1);
        tab->setFocusToEditor();
    }
}

void MainWindow::on_actionBuild_triggered()
{
    if (mProject)
        build();
}

void MainWindow::on_actionViewMemoryMap_triggered()
{
    if (!mProject)
        return;

    MemoryMapDialog dlg(this);
    connect(&dlg, &MemoryMapDialog::addressClicked,
        this, std::bind(&MainWindow::navigateToAddress, this, std::placeholders::_1, false));
    dlg.exec();
}

void MainWindow::on_actionPlayAudio_triggered()
{
    if (!mProject)
        return;

    if (build()) {
        PlayAudioDialog dlg(mProject.get(), this);
        dlg.exec();
    }
}

void MainWindow::on_actionRun_triggered()
{
    if (!mProject)
        return;

    if (!mEmulatorCore->isRunning()) {
        if (build()) {
            if (mUi->actionLoadAsTAP->isChecked())
                mEmulatorCore->setTapeFile(mProject->tapeFileName());
            else
                mEmulatorCore->setTrdFile(mProject->trdFileName());
            mEmulatorCore->start();
        }
    } else {
        if (mEmulatorCore->isPaused())
            mEmulatorCore->unpause();
    }
}

void MainWindow::on_actionPause_triggered()
{
    if (mEmulatorCore->isRunning() && !mEmulatorCore->isPaused())
        mEmulatorCore->pause();
}

void MainWindow::on_actionStop_triggered()
{
    mEmulatorCore->stop();
}

void MainWindow::on_actionStepInto_triggered()
{
    if (mEmulatorCore->isRunning() && mEmulatorCore->isPaused())
        mEmulatorCore->stepInto();
}

void MainWindow::on_actionStepOut_triggered()
{
    if (mEmulatorCore->isRunning() && mEmulatorCore->isPaused())
        mEmulatorCore->stepOut();
}

void MainWindow::on_actionStepOver_triggered()
{
    if (mEmulatorCore->isRunning() && mEmulatorCore->isPaused())
        mEmulatorCore->stepOver();
}

void MainWindow::on_actionRunToCursor_triggered()
{
    if (mEmulatorCore->isRunning() && mEmulatorCore->isPaused()) {
        File* file = currentTab()->file();
        if (!file) {
            QMessageBox::critical(this, tr("Error"), tr("No source file."));
            return;
        }

        int line = currentTab()->line();
        if (line <= 0) {
            QMessageBox::critical(this, tr("Error"), tr("No source line."));
            return;
        }

        mEmulatorCore->runTo(file, line);
    }
}

void MainWindow::on_actionToggleBreakpoint_triggered()
{
    currentTab()->toggleBreakpoint();
}

void MainWindow::on_actionAddDataBreakpoint_triggered()
{
    AddBreakpointDialog dlg(this);
    dlg.exec();
}

void MainWindow::on_actionManageBreakpoints_triggered()
{
    if (!mBreakpointsWindow) {
        mBreakpointsWindow = new BreakpointsWindow(this);
        connect(mBreakpointsWindow, &BreakpointsWindow::fileDoubleClicked, this,
            [this](const QString& fileName, int line) {
                File* file = (!fileName.isEmpty() ? mUi->fileManager->file(fileName) : nullptr);
                if (!file)
                    QMessageBox::critical(this, tr("Error"), tr("Selected file was not found."));
                else {
                    auto tab = setCurrentTab(file);
                    if (tab && tab->canGoToLine()) {
                        tab->goToLine(line - 1);
                        tab->setFocusToEditor();
                        QApplication::setActiveWindow(this);
                        return;
                    }
                }
            });
    }

    mBreakpointsWindow->show();
    qApp->setActiveWindow(mBreakpointsWindow);
    mBreakpointsWindow->setFocus();
}

void MainWindow::on_actionDisassembly_triggered()
{
    auto tab = disassemblyTab();
    if (!tab) {
        tab = new DisassemblyTab(this);
        connect(tab, &AbstractEditorTab::updateUi, this, &MainWindow::updateUi);
        mUi->tabWidget->addTab(tab, tr("Disassembly"));
    }

    mUi->tabWidget->setCurrentWidget(tab);
}

void MainWindow::on_actionMemoryLog_triggered()
{
    if (!mMemoryLogWindow) {
        mMemoryLogWindow = new MemoryLogWindow(this);
        connect(mMemoryLogWindow, &MemoryLogWindow::destroyed, mHighlightManager,
            std::bind(&HighlightManager::clearHighlight, mHighlightManager, Highlight::MemoryLog, true));
        connect(mMemoryLogWindow, &MemoryLogWindow::cleared, mHighlightManager,
            std::bind(&HighlightManager::clearHighlight, mHighlightManager, Highlight::MemoryLog, true));
        connect(mMemoryLogWindow, &MemoryLogWindow::addressDoubleClicked, this, [this](unsigned addr) {
                auto loc = EmulatorCore::instance()->sourceLocationForAddress(addr, true);
                File* file = (!loc.file.isEmpty() ? mUi->fileManager->file(loc.file) : nullptr);
                if (file) {
                    auto tab = setCurrentTab(file);
                    if (tab && tab->canGoToLine()) {
                        tab->goToLine(loc.line - 1);
                        HighlightManager::instance()->setHighlight(Highlight::MemoryLog, loc.file, loc.line);
                        tab->setFocusToEditor();
                        QApplication::setActiveWindow(this);
                        return;
                    }
                }
                HighlightManager::instance()->clearHighlight(Highlight::MemoryLog);
            });
    }

    mMemoryLogWindow->show();
    qApp->setActiveWindow(mMemoryLogWindow);
    mMemoryLogWindow->setFocus();
}

void MainWindow::on_actionControlFlowLog_triggered()
{
    if (!mControlFlowLogWindow) {
        mControlFlowLogWindow = new ControlFlowLogWindow(this);
        connect(mControlFlowLogWindow, &ControlFlowLogWindow::destroyed, mHighlightManager,
            std::bind(&HighlightManager::clearHighlight, mHighlightManager, Highlight::ControlFlowLog, true));
        connect(mControlFlowLogWindow, &ControlFlowLogWindow::cleared, mHighlightManager,
            std::bind(&HighlightManager::clearHighlight, mHighlightManager, Highlight::ControlFlowLog, true));
        connect(mControlFlowLogWindow, &ControlFlowLogWindow::addressDoubleClicked, this, [this](unsigned addr) {
                auto loc = EmulatorCore::instance()->sourceLocationForAddress(addr, true);
                File* file = (!loc.file.isEmpty() ? mUi->fileManager->file(loc.file) : nullptr);
                if (file) {
                    auto tab = setCurrentTab(file);
                    if (tab && tab->canGoToLine()) {
                        tab->goToLine(loc.line - 1);
                        HighlightManager::instance()->setHighlight(Highlight::ControlFlowLog, loc.file, loc.line);
                        tab->setFocusToEditor();
                        QApplication::setActiveWindow(this);
                        return;
                    }
                }
                HighlightManager::instance()->clearHighlight(Highlight::ControlFlowLog);
            });
    }

    mControlFlowLogWindow->show();
    qApp->setActiveWindow(mControlFlowLogWindow);
    mControlFlowLogWindow->setFocus();
}

void MainWindow::on_actionLoadAsTAP_toggled()
{
    if (!mRecursiveLoadAsAction) {
        mRecursiveLoadAsAction = true;
        mUi->actionLoadAsTAP->setChecked(true);
        mUi->actionLoadAsTRD->setChecked(false);
        mRecursiveLoadAsAction = false;
    }
}

void MainWindow::on_actionLoadAsTRD_toggled()
{
    if (!mRecursiveLoadAsAction) {
        mRecursiveLoadAsAction = true;
        mUi->actionLoadAsTAP->setChecked(false);
        mUi->actionLoadAsTRD->setChecked(true);
        mRecursiveLoadAsAction = false;
    }
}

void MainWindow::on_actionLoadSnapshot_triggered()
{
    if (!mProject || mEmulatorCore->isRunning())
        return;

    Settings settings;
    auto filter = QStringLiteral("%1 (*.%2)").arg(tr("Snapshot files")).arg(QStringLiteral("sna"));
    QString file = QFileDialog::getOpenFileName(this, tr("Load snapshot"), settings.lastLoadedSNA(), filter);
    if (file.isEmpty())
        return;

    settings.setLastLoadedSNA(file);

    mEmulatorCore->setSnapshotFile(file);
    mEmulatorCore->start();
}

void MainWindow::on_actionDraw_triggered()
{
    currentTab()->draw();
}

void MainWindow::on_actionDrawRect_triggered()
{
    currentTab()->drawRect();
}

void MainWindow::on_actionFill_triggered()
{
    currentTab()->fill();
}

void MainWindow::on_actionColorize_triggered()
{
    currentTab()->colorize();
}

void MainWindow::on_actionPick_triggered()
{
    currentTab()->pick();
}

void MainWindow::on_actionSelect_triggered()
{
    currentTab()->select();
}

void MainWindow::on_actionToggleGrid_triggered()
{
    currentTab()->toggleGrid();
}

void MainWindow::on_actionRotateClockwise_triggered()
{
    currentTab()->rotateClockwise();
}

void MainWindow::on_actionRotateCounterClockwise_triggered()
{
    currentTab()->rotateCounterClockwise();
}

void MainWindow::on_actionFlipVertically_triggered()
{
    currentTab()->flipVertical();
}

void MainWindow::on_actionFlipHorizontally_triggered()
{
    currentTab()->flipHorizontal();
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        int n = mUi->tabWidget->count();
        for (int i = 0; i < n; i++) {
            auto tab = qobject_cast<AbstractEditorTab*>(mUi->tabWidget->widget(i));
            Q_ASSERT(tab != nullptr);
            if (tab)
                tab->reloadSettings();
        }
    }
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dlg(this);
    dlg.exec();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    auto tab = qobject_cast<AbstractEditorTab*>(mUi->tabWidget->widget(index));
    if (tab && tab->file()) {
        if (mUi->fileManager && mUi->fileManager->selectedFileOrDirectory() != tab->file())
            mUi->fileManager->selectFileOrDirectory(tab->file());
    }
    updateUi();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    auto tab = qobject_cast<AbstractEditorTab*>(mUi->tabWidget->widget(index));
    Q_ASSERT(tab != nullptr);
    if (tab && (tab->isDisassembly() || confirmSave(tab->file())))
        closeTab(tab);
}

void MainWindow::on_fileManager_updateUi()
{
    updateUi();
}

void MainWindow::on_fileManager_fileCreated(File* file)
{
    setCurrentTab(file);
}

void MainWindow::on_fileManager_willRenameFile(File* file, bool* shouldAbort)
{
    if (!confirmSave(file))
        *shouldAbort = true;
}

void MainWindow::on_fileManager_didRenameFile(File* file)
{
    setCurrentTab(file);
}

void MainWindow::on_fileManager_willDuplicateFile(File* file, bool* shouldAbort)
{
    if (!confirmSave(file))
        *shouldAbort = true;
}

void MainWindow::on_fileManager_fileDoubleClicked(File* file)
{
    setCurrentTab(file);
}

void MainWindow::on_fileManager_fileDisappeared(File* file)
{
    closeTab(file);
}

void MainWindow::on_registersDockWidget_dockLocationChanged(Qt::DockWidgetArea area)
{
    switch (area) {
        case Qt::LeftDockWidgetArea:
        case Qt::RightDockWidgetArea:
        default:
            mUi->registersWidget->setOrientation(Qt::Vertical);
            break;

        case Qt::TopDockWidgetArea:
        case Qt::BottomDockWidgetArea:
            mUi->registersWidget->setOrientation(Qt::Horizontal);
            break;
    }
}

void MainWindow::openUsefulLink()
{
    QAction* action = qobject_cast<QAction*>(sender());
    if (action)
        QDesktopServices::openUrl(action->whatsThis());
}
