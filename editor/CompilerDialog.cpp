#include "CompilerDialog.h"
#include "editor/FileManager.h"
#include "compiler/Compiler.h"
#include "compiler/Program.h"
#include "compiler/ProgramBinary.h"
#include "ui_CompilerDialog.h"
#include <QCloseEvent>
#include <QTimer>
#include <QThread>

#ifndef emit
#define emit
#endif

CompilerDialog::CompilerDialog(QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_CompilerDialog)
    , mCanClose(false)
{
    mUi->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);

    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &CompilerDialog::updateUi);
    mTimer->start(0);

    mCompiler = new Compiler();

    mThread = new QThread(this);
    mCompiler->moveToThread(mThread);
    connect(mThread, &QThread::started, mCompiler, &Compiler::compile);
    connect(mThread, &QThread::finished, this, &CompilerDialog::onCompilationEnded);
    connect(mCompiler, &Compiler::compilationEnded, mThread, &QThread::quit);
}

CompilerDialog::~CompilerDialog()
{
    mThread->wait();
    delete mCompiler;
}

std::unique_ptr<Program> CompilerDialog::takeProgram()
{
    Q_ASSERT(!mThread->isRunning());
    return mCompiler->takeProgram();
}

std::unique_ptr<ProgramBinary> CompilerDialog::takeProgramBinary()
{
    Q_ASSERT(!mThread->isRunning());
    return mCompiler->takeProgramBinary();
}

void CompilerDialog::addSourceFile(File* file)
{
    mCompiler->addSourceFile(file, file->fileInfo().absoluteFilePath());
}

void CompilerDialog::setOutputFile(const QString& file)
{
    mCompiler->setOutputFile(file);
}

void CompilerDialog::setGeneratedFilesDirectory(const QDir& dir)
{
    mCompiler->setGeneratedFilesDirectory(dir);
}

bool CompilerDialog::runCompiler()
{
    mThread->start();
    return exec() == QDialog::Accepted;
}

void CompilerDialog::done(int r)
{
    if (mCanClose)
        QDialog::done(r);
}

void CompilerDialog::closeEvent(QCloseEvent* event)
{
    if (mCanClose)
        QDialog::closeEvent(event);
    else
        event->ignore();
}

void CompilerDialog::updateUi()
{
    mUi->statusLabel->setText(mCompiler->statusText());
    if (mCompiler->wasError())
        mUi->statusLabel->setStyleSheet(QStringLiteral("color: red; font-weight: bold"));
    else if (mCanClose)
        mUi->statusLabel->setStyleSheet(QStringLiteral("color: green; font-weight: bold"));
}

void CompilerDialog::onCompilationEnded()
{
    mCanClose = true;

    updateUi();

    if (!mCompiler->wasError()) {
        emit compilationSucceeded();
        QTimer::singleShot(200, this, &QDialog::accept);
    } else {
        emit compilationFailed(mCompiler->errorFile(), mCompiler->errorLine(), mCompiler->errorMessage());
        QTimer::singleShot(200, this, &QDialog::reject);
    }
}
