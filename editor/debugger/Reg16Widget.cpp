#include "Reg16Widget.h"
#include <QMenu>

Reg16Widget::Reg16Widget(QWidget* parent)
    : QWidget(parent)
    , mMode(Hexadecimal_Unsigned)
    , mValue(0)
{
    setupUi(this);
    updateValueLabel();
}

Reg16Widget::~Reg16Widget()
{
}

void Reg16Widget::setHighlight()
{
    auto font = nameLabel->font();
    font.setBold(true);
    nameLabel->setFont(font);
}

void Reg16Widget::clearHighlight()
{
    auto font = nameLabel->font();
    font.setBold(false);
    nameLabel->setFont(font);
}

void Reg16Widget::setMode(int mode)
{
    if (mMode != mode) {
        mMode = mode;
        updateValueLabel();
    }
}

void Reg16Widget::setValue(quint16 value)
{
    if (mValue == value)
        clearHighlight();
    else {
        mValue = value;
        updateValueLabel();
        setHighlight();
    }
}

void Reg16Widget::on_valueLabel_customContextMenuRequested(const QPoint& pos)
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

void Reg16Widget::updateValueLabel()
{
    QString text;
    switch (mMode) {
        case Decimal_Unsigned:
            text = QString::number(quint16(mValue));
            break;
        case Decimal_Signed:
            text = QString::number(qint16(mValue));
            break;
        case Hexadecimal_Unsigned:
            text = QStringLiteral("%1").arg(quint16(mValue), 4, 16, QChar('0'));
            break;
        case Hexadecimal_Signed:
            if (qint16(mValue) >= 0)
                text = QStringLiteral("%1").arg(quint16(mValue), 4, 16, QChar('0'));
            else
                text = QStringLiteral("-%1").arg(-qint32(qint16(mValue)), 4, 16, QChar('0'));
            break;
    }
    valueLabel->setText(text);
}
