#include "RegistersWidget.h"
#include "EmulatorCore.h"
#include "ui_RegistersWidget.h"

extern "C" {
#include <libspectrum.h>
#include <z80/z80.h>
#include <z80/z80_macros.h>
}

RegistersWidget::RegistersWidget(QWidget* parent)
    : QWidget(parent)
    , mUi(new Ui_RegistersWidget)
{
    mUi->setupUi(this);

    connect(EmulatorCore::instance(), &EmulatorCore::ticked, this, &RegistersWidget::refresh);

    mUi->regAF->nameLabel->setText(QStringLiteral("AF"));
    mUi->regBC->nameLabel->setText(QStringLiteral("BC"));
    mUi->regDE->nameLabel->setText(QStringLiteral("DE"));
    mUi->regHL->nameLabel->setText(QStringLiteral("HL"));
    mUi->regIX->nameLabel->setText(QStringLiteral("IX"));
    mUi->regIY->nameLabel->setText(QStringLiteral("IY"));
    mUi->regSP->nameLabel->setText(QStringLiteral("SP"));
    mUi->regPC->nameLabel->setText(QStringLiteral("PC"));

    mUi->regShadowAF->nameLabel->setText(QStringLiteral("AF`"));
    mUi->regShadowBC->nameLabel->setText(QStringLiteral("BC`"));
    mUi->regShadowDE->nameLabel->setText(QStringLiteral("DE`"));
    mUi->regShadowHL->nameLabel->setText(QStringLiteral("HL`"));

    mUi->regA->nameLabel->setText(QStringLiteral("A"));
    mUi->regF->nameLabel->setText(QStringLiteral("F"));
    mUi->regB->nameLabel->setText(QStringLiteral("B"));
    mUi->regC->nameLabel->setText(QStringLiteral("C"));
    mUi->regD->nameLabel->setText(QStringLiteral("D"));
    mUi->regE->nameLabel->setText(QStringLiteral("E"));
    mUi->regH->nameLabel->setText(QStringLiteral("H"));
    mUi->regL->nameLabel->setText(QStringLiteral("L"));
    mUi->regI->nameLabel->setText(QStringLiteral("I"));
    mUi->regR->nameLabel->setText(QStringLiteral("R"));

    mUi->regShadowA->nameLabel->setText(QStringLiteral("A`"));
    mUi->regShadowF->nameLabel->setText(QStringLiteral("F`"));
    mUi->regShadowB->nameLabel->setText(QStringLiteral("B`"));
    mUi->regShadowC->nameLabel->setText(QStringLiteral("C`"));
    mUi->regShadowD->nameLabel->setText(QStringLiteral("D`"));
    mUi->regShadowE->nameLabel->setText(QStringLiteral("E`"));
    mUi->regShadowH->nameLabel->setText(QStringLiteral("H`"));
    mUi->regShadowL->nameLabel->setText(QStringLiteral("L`"));
}

RegistersWidget::~RegistersWidget()
{
}

void RegistersWidget::refresh()
{
    mUi->regAF->setValue(AF);
    mUi->regBC->setValue(BC);
    mUi->regDE->setValue(DE);
    mUi->regHL->setValue(HL);
    mUi->regIX->setValue(IX);
    mUi->regIY->setValue(IY);
    mUi->regSP->setValue(SP);
    mUi->regPC->setValue(PC);

    mUi->regShadowAF->setValue(AF_);
    mUi->regShadowBC->setValue(BC_);
    mUi->regShadowDE->setValue(DE_);
    mUi->regShadowHL->setValue(HL_);

    mUi->regA->setValue(A);
    mUi->regF->setValue(F);
    mUi->regB->setValue(B);
    mUi->regC->setValue(C);
    mUi->regD->setValue(D);
    mUi->regE->setValue(E);
    mUi->regH->setValue(H);
    mUi->regL->setValue(L);
    mUi->regI->setValue(I);
    mUi->regR->setValue(R);

    mUi->regShadowA->setValue(A);
    mUi->regShadowF->setValue(F);
    mUi->regShadowB->setValue(B);
    mUi->regShadowC->setValue(C);
    mUi->regShadowD->setValue(D);
    mUi->regShadowE->setValue(E);
    mUi->regShadowH->setValue(H);
    mUi->regShadowL->setValue(L);

    #define FLAG(NAME) ((F) & FLAG_##NAME ? QStringLiteral("green") : QStringLiteral("red"))
    mUi->signFlagFrame->setStyleSheet(QStringLiteral("background-color: %1").arg(FLAG(S)));
    mUi->zeroFlagFrame->setStyleSheet(QStringLiteral("background-color: %1").arg(FLAG(Z)));
    mUi->halfCarryFlagFrame->setStyleSheet(QStringLiteral("background-color: %1").arg(FLAG(H)));
    mUi->parityOverflowFlagFrame->setStyleSheet(QStringLiteral("background-color: %1").arg(FLAG(P)));
    mUi->subtractFlagFrame->setStyleSheet(QStringLiteral("background-color: %1").arg(FLAG(N)));
    mUi->carryFlagFrame->setStyleSheet(QStringLiteral("background-color: %1").arg(FLAG(C)));
}

void RegistersWidget::reset()
{
    mUi->regAF->setValue(0); mUi->regAF->clearHighlight();
    mUi->regBC->setValue(0); mUi->regBC->clearHighlight();
    mUi->regDE->setValue(0); mUi->regDE->clearHighlight();
    mUi->regHL->setValue(0); mUi->regHL->clearHighlight();
    mUi->regIX->setValue(0); mUi->regIX->clearHighlight();
    mUi->regIY->setValue(0); mUi->regIY->clearHighlight();
    mUi->regSP->setValue(0); mUi->regSP->clearHighlight();
    mUi->regPC->setValue(0); mUi->regPC->clearHighlight();

    mUi->regShadowAF->setValue(0); mUi->regShadowAF->clearHighlight();
    mUi->regShadowBC->setValue(0); mUi->regShadowBC->clearHighlight();
    mUi->regShadowDE->setValue(0); mUi->regShadowDE->clearHighlight();
    mUi->regShadowHL->setValue(0); mUi->regShadowHL->clearHighlight();

    mUi->regA->setValue(0); mUi->regA->clearHighlight();
    mUi->regF->setValue(0); mUi->regF->clearHighlight();
    mUi->regB->setValue(0); mUi->regB->clearHighlight();
    mUi->regC->setValue(0); mUi->regC->clearHighlight();
    mUi->regD->setValue(0); mUi->regD->clearHighlight();
    mUi->regE->setValue(0); mUi->regE->clearHighlight();
    mUi->regH->setValue(0); mUi->regH->clearHighlight();
    mUi->regL->setValue(0); mUi->regL->clearHighlight();
    mUi->regI->setValue(0); mUi->regI->clearHighlight();
    mUi->regR->setValue(0); mUi->regR->clearHighlight();

    mUi->regShadowA->setValue(0); mUi->regShadowA->clearHighlight();
    mUi->regShadowF->setValue(0); mUi->regShadowF->clearHighlight();
    mUi->regShadowB->setValue(0); mUi->regShadowB->clearHighlight();
    mUi->regShadowC->setValue(0); mUi->regShadowC->clearHighlight();
    mUi->regShadowD->setValue(0); mUi->regShadowD->clearHighlight();
    mUi->regShadowE->setValue(0); mUi->regShadowE->clearHighlight();
    mUi->regShadowH->setValue(0); mUi->regShadowH->clearHighlight();
    mUi->regShadowL->setValue(0); mUi->regShadowL->clearHighlight();

    mUi->signFlagFrame->setStyleSheet(QString());
    mUi->zeroFlagFrame->setStyleSheet(QString());
    mUi->halfCarryFlagFrame->setStyleSheet(QString());
    mUi->parityOverflowFlagFrame->setStyleSheet(QString());
    mUi->subtractFlagFrame->setStyleSheet(QString());
    mUi->carryFlagFrame->setStyleSheet(QString());
}
