#include "CompilerDialog.h"
#include "editor/FileManager.h"
#include "compiler/Compiler.h"
#include "compiler/Program.h"
#include "compiler/ProgramBinary.h"
#include "ui_CompilerDialog.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QTimer>
#include <QThread>

#ifndef emit
#define emit
#endif

CompilerDialog::CompilerDialog(QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_CompilerDialog)
    , mCompiler(new Compiler())
    , mCanClose(false)
{
    mUi->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);

    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &CompilerDialog::updateUi);
    mTimer->start(0);

    mThread = new QThread(this);
    mCompiler->moveToThread(mThread);
    connect(mThread, &QThread::started, mCompiler.get(), &Compiler::compile);
    connect(mThread, &QThread::finished, this, &CompilerDialog::onCompilationEnded);
    connect(mCompiler.get(), &Compiler::diagnosticMessage, this, &CompilerDialog::onDiagnosticMessage);
    connect(mCompiler.get(), &Compiler::compilationEnded, mThread, &QThread::quit);
}

CompilerDialog::~CompilerDialog()
{
    mThread->wait();
    mCompiler.reset();
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
    mCompiler->addSourceFile(file->relativeName(), file->fileInfo().absoluteFilePath());
}

void CompilerDialog::setOutputTapeFile(const QString& file)
{
    mCompiler->setOutputTapeFile(file);
}

void CompilerDialog::setOutputSclFile(const QString& file)
{
    mCompiler->setOutputSclFile(file);
}

void CompilerDialog::setOutputTrdFile(const QString& file)
{
    mCompiler->setOutputTrdFile(file);
}

void CompilerDialog::setOutputWavFile(const QString& file)
{
    mCompiler->setOutputWavFile(file);
}

void CompilerDialog::setGeneratedFilesDirectory(const QDir& dir)
{
    mCompiler->setGeneratedFilesDirectory(dir);
}

void CompilerDialog::setProjectFile(const QString& file)
{
    mCompiler->setProjectFile(file);
}

void CompilerDialog::setProjectDirectory(const QDir& dir)
{
    mCompiler->setProjectDirectory(dir);
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

void CompilerDialog::onDiagnosticMessage(const QString& message)
{
    QMessageBox::warning(parentWidget(), tr("Message"), message);
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
