#include "AddBreakpointDialog.h"
#include "ui_AddBreakpointDialog.h"
#include "util/ComboBox.h"

static bool hexadecimal = false;
static int lastAddress;
static BreakpointType lastBreakpointType = BreakpointType::MemoryRead;

AddBreakpointDialog::AddBreakpointDialog(QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_AddBreakpointDialog)
    , mHexadecimal(hexadecimal)
{
    mUi->setupUi(this);

    mUi->addressSpin->setValue(lastAddress);

    mUi->typeCombo->addItem(tr("Memory read"), int(BreakpointType::MemoryRead));
    mUi->typeCombo->addItem(tr("Memory write"), int(BreakpointType::MemoryWrite));
    comboSelectItem(mUi->typeCombo, int(lastBreakpointType));

    mUi->decimalRadio->setChecked(!mHexadecimal);
    mUi->hexadecimalRadio->setChecked(mHexadecimal);

    updateUi();
}

AddBreakpointDialog::~AddBreakpointDialog()
{
}

unsigned AddBreakpointDialog::address() const
{
    return unsigned(mUi->addressSpin->value());
}

BreakpointType AddBreakpointDialog::breakpointType() const
{
    return BreakpointType(comboSelectedItem(mUi->typeCombo).toInt());
}

void AddBreakpointDialog::done(int r)
{
    if (r == QDialog::Accepted) {
        lastAddress = int(address());
        lastBreakpointType = breakpointType();
        hexadecimal = mHexadecimal;

        switch (lastBreakpointType) {
            case BreakpointType::MemoryRead:
                BreakpointsModel::instance()->addMemoryReadBreakpoint(this, lastAddress);
                break;
            case BreakpointType::MemoryWrite:
                BreakpointsModel::instance()->addMemoryWriteBreakpoint(this, lastAddress);
                break;
        }
    }

    QDialog::done(r);
}

void AddBreakpointDialog::updateUi()
{
    mUi->addressSpin->setPrefix(mHexadecimal ? QStringLiteral("0x") : QString());
    mUi->addressSpin->setDisplayIntegerBase(mHexadecimal ? 16 : 10);
}

void AddBreakpointDialog::on_decimalRadio_toggled(bool flag)
{
    mHexadecimal = !flag;
    updateUi();
}

void AddBreakpointDialog::on_hexadecimalRadio_toggled(bool flag)
{
    mHexadecimal = flag;
    updateUi();
}
