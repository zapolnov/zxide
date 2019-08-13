#ifndef DEBUGGER_REG8WIDGET_H
#define DEBUGGER_REG8WIDGET_H

#include <QWidget>
#include "ui_Reg8Widget.h"

class Reg8Widget : public QWidget, public Ui_Reg8Widget
{
    Q_OBJECT

public:
    explicit Reg8Widget(QWidget* parent = nullptr);
    ~Reg8Widget() override;

    void setHighlight();
    void clearHighlight();

    void setMode(int mode);
    void setValue(quint8 value);

private:
    enum Mode
    {
        Decimal_Unsigned = 0,
        Decimal_Signed,
        Hexadecimal_Unsigned,
        Hexadecimal_Signed,
    };

    int mMode;
    quint8 mValue;

    Q_SLOT void on_valueLabel_customContextMenuRequested(const QPoint& pos);

    Q_SLOT void on_actionDecimalUnsigned_triggered() { setMode(Decimal_Unsigned); }
    Q_SLOT void on_actionDecimalSigned_triggered() { setMode(Decimal_Signed); }
    Q_SLOT void on_actionHexadecimalUnsigned_triggered() { setMode(Hexadecimal_Unsigned); }
    Q_SLOT void on_actionHexadecimalSigned_triggered() { setMode(Hexadecimal_Signed); }

    void updateValueLabel();

    Q_DISABLE_COPY(Reg8Widget)
};

#endif
