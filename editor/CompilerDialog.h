#ifndef COMPILERDIALOG_H
#define COMPILERDIALOG_H

#include <QDialog>
#include <QThread>
#include <QDir>
#include <memory>

class QTimer;
class Ui_CompilerDialog;
class File;
class Program;
class ProgramBinary;
class Compiler;

class CompilerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CompilerDialog(QWidget* parent = nullptr);
    ~CompilerDialog() override;

    std::unique_ptr<Program> takeProgram();
    std::unique_ptr<ProgramBinary> takeProgramBinary();

    void addSourceFile(File* file);
    void setOutputTapeFile(const QString& file);
    void setOutputWavFile(const QString& file);
    void setGeneratedFilesDirectory(const QDir& dir);
    void setProjectDirectory(const QDir& dir);

    bool runCompiler();

protected:
    void done(int r) override;
    void closeEvent(QCloseEvent* event) override;

signals:
    void compilationSucceeded();
    void compilationFailed(const QString& file, int line, const QString& message);

private:
    std::unique_ptr<Ui_CompilerDialog> mUi;
    QThread* mThread;
    QTimer* mTimer;
    Compiler* mCompiler;
    bool mCanClose;

    void updateUi();
    void onDiagnosticMessage(const QString& message);
    void onCompilationEnded();

    Q_DISABLE_COPY(CompilerDialog)
};

#endif
