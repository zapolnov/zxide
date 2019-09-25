#include "EditMemoryDialog.h"
#include "ui_EditMemoryDialog.h"

static bool hexadecimal = false;

EditMemoryDialog::EditMemoryDialog(unsigned value, unsigned max, QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_EditMemoryDialog)
    , mHexadecimal(hexadecimal)
{
    mUi->setupUi(this);
    mUi->valueSpin->setRange(0, max);
    mUi->valueSpin->setValue(value);
    mUi->decimalRadio->setChecked(!mHexadecimal);
    mUi->hexadecimalRadio->setChecked(mHexadecimal);
    updateUi();
}

EditMemoryDialog::~EditMemoryDialog()
{
}

void EditMemoryDialog::setLabelText(const QString& text)
{
    mUi->valueLabel->setText(text);
}

unsigned EditMemoryDialog::value() const
{
    return unsigned(mUi->valueSpin->value());
}

void EditMemoryDialog::done(int r)
{
    if (r == QDialog::Accepted)
        hexadecimal = mHexadecimal;

    QDialog::done(r);
}

void EditMemoryDialog::updateUi()
{
    mUi->valueSpin->setPrefix(mHexadecimal ? QStringLiteral("0x") : QString());
    mUi->valueSpin->setDisplayIntegerBase(mHexadecimal ? 16 : 10);
}

void EditMemoryDialog::on_decimalRadio_toggled(bool flag)
{
    mHexadecimal = !flag;
    updateUi();
}

void EditMemoryDialog::on_hexadecimalRadio_toggled(bool flag)
{
    mHexadecimal = flag;
    updateUi();
}
