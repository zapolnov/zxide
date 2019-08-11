#ifndef COMPILERDIALOG_H
#define COMPILERDIALOG_H

#include <QDialog>
#include <QThread>
#include <memory>

class QTimer;
class Ui_CompilerDialog;
class File;
class Compiler;

class CompilerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CompilerDialog(QWidget* parent = nullptr);
    ~CompilerDialog() override;

    void addSourceFile(File* file);
    bool runCompiler();

protected:
    void done(int r) override;
    void closeEvent(QCloseEvent* event) override;

signals:
    void compilationSucceeded();
    void compilationFailed(File* file, int line, const QString& message);

private:
    std::unique_ptr<Ui_CompilerDialog> mUi;
    QThread* mThread;
    QTimer* mTimer;
    Compiler* mCompiler;
    bool mCanClose;

    void updateUi();
    void onCompilationEnded();

    Q_DISABLE_COPY(CompilerDialog)
};

#endif