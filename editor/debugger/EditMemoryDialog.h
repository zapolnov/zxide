#ifndef DEBUGGER_EDITMEMORYDIALOG_H
#define DEBUGGER_EDITMEMORYDIALOG_H

#include <QDialog>
#include <memory>

class Ui_EditMemoryDialog;

class EditMemoryDialog : public QDialog
{
    Q_OBJECT

public:
    EditMemoryDialog(unsigned value, unsigned max, QWidget* parent = nullptr);
    ~EditMemoryDialog() override;

    void setLabelText(const QString& text);

    unsigned value() const;

protected:
    void done(int r) override;

private:
    std::unique_ptr<Ui_EditMemoryDialog> mUi;
    bool mHexadecimal;

    void updateUi();

    Q_SLOT void on_decimalRadio_toggled(bool flag);
    Q_SLOT void on_hexadecimalRadio_toggled(bool flag);

    Q_DISABLE_COPY(EditMemoryDialog)
};

#endif
