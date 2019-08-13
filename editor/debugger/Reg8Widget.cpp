#include "Reg8Widget.h"
#include <QMenu>

Reg8Widget::Reg8Widget(QWidget* parent)
    : QWidget(parent)
    , mMode(Hexadecimal_Unsigned)
    , mValue(0)
{
    setupUi(this);
    updateValueLabel();
}

Reg8Widget::~Reg8Widget()
{
}

void Reg8Widget::setHighlight()
{
    auto font = nameLabel->font();
    font.setBold(true);
    nameLabel->setFont(font);
}

void Reg8Widget::clearHighlight()
{
    auto font = nameLabel->font();
    font.setBold(false);
    nameLabel->setFont(font);
}

void Reg8Widget::setMode(int mode)
{
    if (mMode != mode) {
        mMode = mode;
        updateValueLabel();
    }
}

void Reg8Widget::setValue(quint8 value)
{
    if (mValue == value)
        clearHighlight();
    else {
        mValue = value;
        updateValueLabel();
        setHighlight();
    }
}

void Reg8Widget::on_valueLabel_customContextMenuRequested(const QPoint& pos)
{
    actionDecimalUnsigned->setChecked(mMode == Decimal_Unsigned);
    actionDecimalSigned->setChecked(mMode == Decimal_Signed);
    actionHexadecimalUnsigned->setChecked(mMode == Hexadecimal_Unsigned);
    actionHexadecimalSigned->setChecked(mMode == Hexadecimal_Signed);

    QMenu menu;
    menu.addAction(actionDecimalUnsigned);
    menu.addAction(actionDecimalSigned);
    menu.addAction(actionHexadecimalUnsigned);
    menu.addAction(actionHexadecimalSigned);
    menu.exec(mapToGlobal(pos));
}

void Reg8Widget::updateValueLabel()
{
    QString text;
    switch (mMode) {
        case Decimal_Unsigned:
            text = QString::number(quint8(mValue));
            break;
        case Decimal_Signed:
            text = QString::number(qint8(mValue));
            break;
        case Hexadecimal_Unsigned:
            text = QStringLiteral("%1").arg(quint8(mValue), 2, 16, QChar('0'));
            break;
        case Hexadecimal_Signed:
            if (qint8(mValue) >= 0)
                text = QStringLiteral("%1").arg(quint8(mValue), 2, 16, QChar('0'));
            else
                text = QStringLiteral("-%1").arg(-qint32(qint8(mValue)), 2, 16, QChar('0'));
            break;
    }
    valueLabel->setText(text);
}
