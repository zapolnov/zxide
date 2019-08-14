#include "RegistersWidget.h"
#include "ui_EditRegisterDialog.h"
#include <QTimer>
#include <QPainter>
#include <QContextMenuEvent>
#include <QMenu>
#include <QDialog>

RegistersWidget::RegistersWidget(QWidget* parent)
    : QWidget(parent)
    , mTimer(new QTimer(this))
    , mOrientation(Qt::Horizontal)
{
    setOrientation(Qt::Vertical);

    #define REG(BITS, HX, HY, VX, VY, REG, N, NW, NW2, ID) \
        mRegisters.emplace_back( \
            std::make_unique<Register<quint##BITS>>(this, ID, HX, HY, VX, VY, NW, NW2, offsetof(Registers, REG), N))
    #define SREG(HX, HY, VX, VY, REG, N, NW, NW2) \
        mRegisters.emplace_back( \
            std::make_unique<SimpleRegister>(this, HX, HY, VX, VY, NW, NW2, offsetof(Registers, REG), N))
    #define UREG(HX, HY, VX, VY, REG, N, NW) \
        mRegisters.emplace_back(std::make_unique<ULA>(this, HX, HY, VX, VY, NW, offsetof(Registers, REG), N))
    #define FLAG(HX, HY, VX, VY, REG, N, NW) \
        mRegisters.emplace_back(std::make_unique<Flag>(this, HX, HY, VX, VY, NW, offsetof(Registers, REG), N))
    #define TSTATES(HX, HY, VX, VY, REG, N, NW) \
        mRegisters.emplace_back(std::make_unique<TStates>(this, HX, HY, VX, VY, NW, offsetof(Registers, REG), N))

    REG(16,  2, 1,  2,  1, af , "AF" , 2, 2, Reg_AF );
    REG(16,  2, 2,  2,  2, bc , "BC" , 2, 2, Reg_BC );
    REG(16,  2, 3,  2,  3, de , "DE" , 2, 2, Reg_DE );
    REG(16,  2, 4,  2,  4, hl , "HL" , 2, 2, Reg_HL );
    REG(16,  2, 5,  2,  5, ix , "IX" , 2, 2, Reg_IX );
    REG(16,  2, 6,  2,  6, iy , "IY" , 2, 2, Reg_IY );
    REG(16, 13, 1, 12,  1, af_, "AF'", 3, 3, Reg_AF_);
    REG(16, 13, 2, 12,  2, bc_, "BC'", 3, 3, Reg_BC_);
    REG(16, 13, 3, 12,  3, de_, "DE'", 3, 3, Reg_DE_);
    REG(16, 13, 4, 12,  4, hl_, "HL'", 3, 3, Reg_HL_);
    REG(16, 13, 5, 12,  5, sp , "SP" , 3, 3, Reg_SP );
    REG(16, 13, 6, 12,  6, pc , "PC" , 3, 3, Reg_PC );

    REG( 8, 25, 1,  2,  8,  b , "B"  , 1, 1, Reg_B );
    REG( 8, 25, 2,  2,  9,  c , "C"  , 1, 1, Reg_C );
    REG( 8, 25, 3,  2, 10,  d , "D"  , 1, 1, Reg_D );
    REG( 8, 25, 4,  2, 11,  e , "E"  , 1, 1, Reg_E );
    REG( 8, 25, 5,  2, 12,  h , "H"  , 1, 1, Reg_H );
    REG( 8, 25, 6,  2, 13,  l , "L"  , 1, 1, Reg_L );
    REG( 8, 33, 1, 10,  8,  b_, "B'" , 2, 2, Reg_B_);
    REG( 8, 33, 2, 10,  9,  c_, "C'" , 2, 2, Reg_C_);
    REG( 8, 33, 3, 10, 10,  d_, "D'" , 2, 2, Reg_D_);
    REG( 8, 33, 4, 10, 11,  e_, "E'" , 2, 2, Reg_E_);
    REG( 8, 33, 5, 10, 12,  h_, "H'" , 2, 2, Reg_H_);
    REG( 8, 33, 6, 10, 13,  l_, "L'" , 2, 2, Reg_L_);
    REG( 8, 42, 1, 19,  8,  a , "A"  , 2, 2, Reg_A );
    REG( 8, 42, 2, 19,  9,  a_, "A'" , 2, 2, Reg_A_);
    REG( 8, 42, 3, 19, 10,  f , "F"  , 2, 2, Reg_F );
    REG( 8, 42, 4, 19, 11,  f_, "F'" , 2, 2, Reg_F_);
    REG( 8, 42, 5, 19, 12,  i , "I"  , 2, 2, Reg_I );
    REG( 8, 42, 6, 19, 13,  r , "R"  , 2, 2, Reg_R );

    FLAG(   51, 1, 23,  1, sf ,  "S" , 3);
    FLAG(   51, 2, 23,  2, zf ,  "Z" , 3);
    FLAG(   51, 3, 23,  3, hf ,  "H" , 3);
    FLAG(   51, 4, 23,  4, pf , "P/V", 3);
    FLAG(   51, 5, 23,  5, nf ,  "N" , 3);
    FLAG(   51, 6, 23,  6, cf ,  "C" , 3);

    SREG(   56, 1,  2, 15, im,      "IM", 2, 4);
    SREG(   56, 2,  7, 15, iff1,  "IFF1", 4, 4);
    SREG(   56, 3, 14, 15, iff2,  "IFF2", 4, 4);
    SREG(   56, 4, 21, 15, halted, "HLT", 3, 4);

    UREG(   56, 5,  2, 16, ula,   "ULA", 3);
    TSTATES(56, 6, 18, 16, tstates, "T", 1);

    mTimer->setInterval(1000 / 4);
    connect(mTimer, &QTimer::timeout, this, &RegistersWidget::refresh);

    connect(EmulatorCore::instance(), &EmulatorCore::started, mTimer, QOverload<>::of(&QTimer::start));
    connect(EmulatorCore::instance(), &EmulatorCore::started, this, &RegistersWidget::refresh);
    connect(EmulatorCore::instance(), &EmulatorCore::stopped, mTimer, &QTimer::stop);
    connect(EmulatorCore::instance(), &EmulatorCore::stopped, this, &RegistersWidget::reset);
}

RegistersWidget::~RegistersWidget()
{
}

void RegistersWidget::refresh()
{
    auto r = EmulatorCore::instance()->registers();
    for (const auto& reg : mRegisters)
        reg->updateValue(r);
}

void RegistersWidget::reset()
{
    for (const auto& reg : mRegisters)
        reg->clear();
}

void RegistersWidget::setOrientation(Qt::Orientation orientation)
{
    if (mOrientation != orientation) {
        mOrientation = orientation;
        update();

        switch (mOrientation) {
            case Qt::Horizontal:
                setFixedHeight(8 * SimpleTextPainter::CharHeight);
                setMinimumWidth(66 * SimpleTextPainter::CharWidth);
                setMaximumWidth(QWIDGETSIZE_MAX);
                break;

            case Qt::Vertical:
                setFixedWidth(28 * SimpleTextPainter::CharWidth);
                setMinimumHeight(18 * SimpleTextPainter::CharHeight);
                setMaximumHeight(QWIDGETSIZE_MAX);
                break;
        }
    }
}

void RegistersWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    for (const auto& reg : mRegisters)
        reg->paint(&painter);
}

void RegistersWidget::contextMenuEvent(QContextMenuEvent* event)
{
    constexpr int charW = SimpleTextPainter::CharWidth;
    constexpr int charH = SimpleTextPainter::CharHeight;

    QPoint pos = event->pos();
    int x = pos.x();
    int y = pos.y();

    for (const auto& reg : mRegisters) {
        int rx = reg->x();
        int ry = reg->y();
        if (x >= rx * charW && y >= ry * charH && x < (rx + reg->width()) * charW && y < (ry + 1) * charH) {
            if (reg->isValid())
                reg->showContextMenu(mapToGlobal(pos));
            return;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RegistersWidget::AbstractRegister::AbstractRegister()
{
}

RegistersWidget::AbstractRegister::~AbstractRegister()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T> RegistersWidget::Register<T>::Register(
        RegistersWidget* widget, ::Register reg,
            int hx, int hy, int vx, int vy, int nw, int nw2, ptrdiff_t offset, std::string name)
    : mWidget(widget)
    , mRegister(reg)
    , mHorizontalX(hx)
    , mHorizontalY(hy)
    , mVerticalX(vx)
    , mVerticalY(vy)
    , mName(std::move(name))
    , mOffset(offset)
    , mNameWidth(nw)
    , mNameWidthHorz(nw2)
    , mMode(Hexadecimal_Unsigned)
    , mValue(0)
    , mOldValue(0)
    , mIsValid(false)
{
}

template <typename T> int RegistersWidget::Register<T>::x() const
{
    return mWidget->mOrientation == Qt::Horizontal ? mHorizontalX : mVerticalX;
}

template <typename T> int RegistersWidget::Register<T>::y() const
{
    return mWidget->mOrientation == Qt::Horizontal ? mHorizontalY : mVerticalY;
}

template <typename T> int RegistersWidget::Register<T>::nameWidth() const
{
    return mWidget->mOrientation == Qt::Horizontal ? mNameWidthHorz : mNameWidth;
}

template <typename T> int RegistersWidget::Register<T>::width() const
{
    switch (sizeof(T) * CHAR_BIT) {
        case 8: return nameWidth() + 5;
        case 16: return nameWidth() + 7;
        default: Q_ASSERT(false); return 0;
    }
}

template <typename T> void RegistersWidget::Register<T>::setMode(Mode mode)
{
    if (mMode != mode) {
        mMode = mode;
        mWidget->update();
    }
}

template <typename T> void RegistersWidget::Register<T>::clear()
{
    if (mIsValid) {
        mIsValid = false;
        mWidget->update();
    }
}

template <typename T> void RegistersWidget::Register<T>::updateValue(const Registers& reg)
{
    T value = *reinterpret_cast<const T*>(reinterpret_cast<const char*>(&reg) + mOffset);
    if (mValue != value || mOldValue != mValue || !mIsValid) {
        mIsValid = true;
        mOldValue = mValue;
        mValue = value;
        mWidget->update();
    }
}

template <typename T> void RegistersWidget::Register<T>::paint(QPainter* painter) const
{
    int xx = x();
    int yy = y();

    int color = (mValue == mOldValue || !mIsValid ? BLACK | INTENSITY : BLACK);
    drawTextAt(painter, xx, yy, mName, color);

    char buf[16];
    switch (sizeof(T) * CHAR_BIT) {
        case 8:
            if (!mIsValid) {
                color = BLACK | INTENSITY;
                strcpy(buf, "----");
            } else {
                color = BLUE;
                auto uvalue = unsigned(quint8(mValue));
                auto svalue = int(qint8(mValue));
                switch (mMode) {
                    case Decimal_Unsigned: sprintf(buf, " %3u", uvalue); break;
                    case Decimal_Signed: sprintf(buf, "%+4d", svalue); break;
                    case Hexadecimal_Unsigned: sprintf(buf, " %02xh", uvalue); break;
                    case Hexadecimal_Signed: sprintf(buf, "%c%02xh", (svalue < 0 ? '-' : '+'), abs(svalue)); break;
                }
            }
            break;

        case 16:
            if (!mIsValid) {
                color = BLACK | INTENSITY;
                strcpy(buf, "------");
            } else {
                color = BLUE;
                auto uvalue = unsigned(quint16(mValue));
                auto svalue = int(qint16(mValue));
                switch (mMode) {
                    case Decimal_Unsigned: sprintf(buf, " %5u", uvalue); break;
                    case Decimal_Signed: sprintf(buf, "%+6d", svalue); break;
                    case Hexadecimal_Unsigned: sprintf(buf, " %04xh", uvalue); break;
                    case Hexadecimal_Signed: sprintf(buf, "%c%04xh", (svalue < 0 ? '-' : '+'), abs(svalue)); break;
                }
            }
            break;

        default:
            Q_ASSERT(false);
            return;
    }

    drawTextAt(painter, xx + nameWidth() + 1, yy, buf, color);
}

template <typename T> void RegistersWidget::Register<T>::showContextMenu(const QPoint& pos)
{
    QMenu menu;

    #define ACTION(ID, TEXT) \
        { \
            QAction* action = menu.addAction(TEXT); \
            action->setCheckable(true); \
            action->setChecked(mMode == ID); \
            connect(action, &QAction::triggered, mWidget, [this]{ setMode(ID); }); \
        }

    menu.addAction(QLatin1String(mName.c_str()))->setEnabled(false);
    menu.addSeparator();

    ACTION(Decimal_Unsigned, tr("Decimal / &Unsigned"));
    ACTION(Decimal_Signed, tr("Decimal / &Signed"));
    ACTION(Hexadecimal_Unsigned, tr("He&xadecimal / Unsigned"));
    ACTION(Hexadecimal_Signed, tr("&Hexadecimal / Signed"));

    menu.addSeparator();

    QAction* editAction = menu.addAction(tr("&Edit value..."));
    connect(editAction, &QAction::triggered, mWidget, [this]{
            QDialog dlg(mWidget);
            dlg.setWindowTitle(QLatin1String(mName.c_str()));

            Ui_EditRegisterDialog ui;
            ui.setupUi(&dlg);

            bool is8Bit = (sizeof(T) * CHAR_BIT == 8);
            bool isSigned = (mMode == Decimal_Signed || mMode == Hexadecimal_Signed);
            bool isHex = (mMode == Hexadecimal_Signed || mMode == Hexadecimal_Unsigned);
            int min = (isSigned ? (is8Bit ? -128 : -32768) : 0);
            int max = (isSigned ? (is8Bit ? 127 : 32767) : (is8Bit ? 255 : 65535));
            ui.spinBox->setRange(min, max);
            ui.spinBox->setValue(mValue);
            ui.spinBox->setDisplayIntegerBase(isHex ? 16 : 0);

            if (dlg.exec() == QDialog::Accepted) {
                int value = ui.spinBox->value();
                quint16 newValue = (isSigned ? qint16(value) : quint16(value));
                EmulatorCore::instance()->setRegister(mRegister, newValue);
            }
        });

    menu.exec(pos);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RegistersWidget::SimpleRegister::SimpleRegister(
        RegistersWidget* w, int hx, int hy, int vx, int vy, int nw, int nw2, ptrdiff_t o, std::string n)
    : Register(w, Reg_None, hx, hy, vx, vy, nw, nw2, o, std::move(n))
{
}

int RegistersWidget::SimpleRegister::width() const
{
    return nameWidth() + 2;
}

void RegistersWidget::SimpleRegister::paint(QPainter* painter) const
{
    int xx = x();
    int yy = y();

    int color = (mValue == mOldValue || !mIsValid ? BLACK | INTENSITY : BLACK);
    drawTextAt(painter, xx, yy, mName, color);

    char buf[8];
    if (!mIsValid) {
        color = BLACK | INTENSITY;
        strcpy(buf, "-");
    } else {
        color = BLUE;
        sprintf(buf, "%d", static_cast<int>(mValue));
    }

    drawTextAt(painter, xx + nameWidth() + 1, yy, buf, color);
}

void RegistersWidget::SimpleRegister::showContextMenu(const QPoint& pos)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RegistersWidget::Flag::Flag(
        RegistersWidget* widget, int hx, int hy, int vx, int vy, int nw, ptrdiff_t offset, std::string name)
    : Register(widget, Reg_None, hx, hy, vx, vy, nw, nw, offset, std::move(name))
{
}

int RegistersWidget::Flag::width() const
{
    return nameWidth() + 2;
}

void RegistersWidget::Flag::paint(QPainter* painter) const
{
    int xx = x();
    int yy = y();

    char buf[8];
    switch (mName.length()) {
        case 1: sprintf(buf, " %c ", mName[0]); break;
        case 3: strcpy(buf, mName.c_str()); break;
        default: Q_ASSERT(false); return;
    }

    int color;
    if (!mIsValid)
        color = COLOR(BLACK | INTENSITY, GRAY);
    else if (mValue)
        color = COLOR((mValue != mOldValue ? GRAY | INTENSITY : GREEN | INTENSITY), GREEN);
    else
        color = COLOR((mValue != mOldValue ? BLACK : BLACK | INTENSITY), GRAY);

    drawTextAt(painter, xx, yy, buf, 3, color);
}

void RegistersWidget::Flag::showContextMenu(const QPoint& pos)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RegistersWidget::TStates::TStates(
        RegistersWidget* widget, int hx, int hy, int vx, int vy, int nw, ptrdiff_t offset, std::string name)
    : Register(widget, Reg_None, hx, hy, vx, vy, nw, nw, offset, std::move(name))
{
}

int RegistersWidget::TStates::width() const
{
    return nameWidth() + 7;
}

void RegistersWidget::TStates::paint(QPainter* painter) const
{
    int xx = x();
    int yy = y();

    int color;
    char buf[16];

    if (!mIsValid) {
        color = BLACK | INTENSITY;
        strcpy(buf, "------ ");
    } else {
        color = BLUE;
        if (mWidget->mOrientation == Qt::Horizontal)
            sprintf(buf, "%lu", static_cast<unsigned long>(mValue));
        else
            sprintf(buf, "%7lu", static_cast<unsigned long>(mValue));
    }

    if (mWidget->mOrientation == Qt::Vertical) {
        drawTextAt(painter, xx, yy, buf, color);
        drawTextAt(painter, xx + 7, yy, mName, BLACK | INTENSITY);
    } else {
        if (mIsValid) {
            drawTextAt(painter, xx, yy, buf, color);
            drawTextAt(painter, xx + int(strlen(buf)), yy, mName, BLACK | INTENSITY);
        } else {
            drawTextAt(painter, xx, yy, mName, BLACK | INTENSITY);
            drawTextAt(painter, xx + nameWidth() + 1, yy, buf, color);
        }
    }
}

void RegistersWidget::TStates::showContextMenu(const QPoint& pos)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RegistersWidget::ULA::ULA(
        RegistersWidget* widget, int hx, int hy, int vx, int vy, int nw, ptrdiff_t offset, std::string name)
    : Register(widget, Reg_None, hx, hy, vx, vy, nw, nw, offset, std::move(name))
{
}

void RegistersWidget::ULA::showContextMenu(const QPoint& pos)
{
}
