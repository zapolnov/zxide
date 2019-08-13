#ifndef DEBUGGER_REG16WIDGET_H
#define DEBUGGER_REG16WIDGET_H

#include <QWidget>
#include "ui_Reg16Widget.h"

class Reg16Widget : public QWidget, public Ui_Reg16Widget
{
    Q_OBJECT

public:
    explicit Reg16Widget(QWidget* parent = nullptr);
    ~Reg16Widget() override;

    void setHighlight();
    void clearHighlight();

    void setMode(int mode);
    void setValue(quint16 value);

private:
    enum Mode
    {
        Decimal_Unsigned = 0,
        Decimal_Signed,
        Hexadecimal_Unsigned,
        Hexadecimal_Signed,
    };

    int mMode;
    quint16 mValue;

    Q_SLOT void on_valueLabel_customContextMenuRequested(const QPoint& pos);

    Q_SLOT void on_actionDecimalUnsigned_triggered() { setMode(Decimal_Unsigned); }
    Q_SLOT void on_actionDecimalSigned_triggered() { setMode(Decimal_Signed); }
    Q_SLOT void on_actionHexadecimalUnsigned_triggered() { setMode(Hexadecimal_Unsigned); }
    Q_SLOT void on_actionHexadecimalSigned_triggered() { setMode(Hexadecimal_Signed); }

    void updateValueLabel();

    Q_DISABLE_COPY(Reg16Widget)
};

#endif
