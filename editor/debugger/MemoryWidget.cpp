#include "MemoryWidget.h"
#include "debugger/EmulatorCore.h"
#include "debugger/EditMemoryDialog.h"
#include "util/ScrollBar.h"
#include "ui_EditRegisterDialog.h"
#include <QPainter>
#include <QContextMenuEvent>
#include <QMenu>
#include <QToolTip>
#include <QTimer>
#include <QDialog>

static constexpr int AddressWidth = 4;
static constexpr int Spacing = 2;
static constexpr int HexWidth = 3;
static constexpr int SymWidth = 1;

MemoryWidget::MemoryWidget(QWidget* parent)
    : QOpenGLWidget(parent)
    , mScrollBar(nullptr)
    , mMouseX(INT_MIN)
    , mMouseY(INT_MIN)
    , mAddressUnderMouse(-1)
    , mShowContextMenu(false)
    , mUpdateToolTip(false)
    , mShowingToolTip(false)
{
    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &MemoryWidget::updateToolTip);
    mTimer->start(100);

    setMouseTracking(true);

    connect(EmulatorCore::instance(), &EmulatorCore::memoryChanged, this, QOverload<>::of(&MemoryWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::started, this, QOverload<>::of(&MemoryWidget::update));
    connect(EmulatorCore::instance(), &EmulatorCore::stopped, this, QOverload<>::of(&MemoryWidget::update));

    setMinimumWidth((AddressWidth + Spacing + HexWidth - 1 + Spacing + SymWidth) * CharWidth);
    setMinimumHeight(CharHeight);
}

MemoryWidget::~MemoryWidget()
{
}

QSize MemoryWidget::sizeHint() const
{
    const int hintWidth = 62;
    const int hintHeight = 7;
    int x = (AddressWidth + Spacing + hintWidth * HexWidth - 1 + Spacing + SymWidth * hintWidth) * CharWidth;
    int y = hintHeight * CharHeight;
    return QSize(x, y);
}

void MemoryWidget::setScrollBar(ScrollBar* scrollBar)
{
    mScrollBar = scrollBar;
    mScrollBar->setSingleStep(CharHeight);
    mScrollBar->setPageStep(CharHeight);
    connect(mScrollBar, &ScrollBar::valueChanged, this, QOverload<>::of(&MemoryWidget::update));
    update();
}

void MemoryWidget::paintGL()
{
    QPainter painter(this);

    painter.fillRect(0, 0, width(), height(), Qt::white);
    if (!EmulatorCore::instance()->isRunning())
        return;

    int pixW = width() - (AddressWidth + Spacing * 2) * CharWidth;
    int pixH = height();

    int w = qMax(pixW / ((HexWidth + SymWidth) * CharWidth), 1);
    int h = 1 + (pixH + CharHeight - 1) / CharHeight;

    int totalLines = (0x10000 + w - 1) / w;
    mScrollBar->setRange(0, qMax(totalLines * CharHeight - pixH, 0));
    mScrollBar->setPageStep(qMax(pixH / CharHeight, 1) * CharHeight);

    int offset = mScrollBar->value();
    int address = offset / CharHeight * w;

    size_t lineBufferSize = AddressWidth + Spacing + w * HexWidth - 1 + Spacing + w * SymWidth;
    if (lineBufferSize != mLineBuffer.size())
        mLineBuffer.resize(lineBufferSize);

    int x = (width() - (int(lineBufferSize) * CharWidth)) / 2;
    int y = -(offset % CharHeight);

    int firstAddr = address;
    int lastAddr = qMin(address + h * w, 0xffff);
    size_t dataBufferSize = lastAddr - firstAddr + 1;
    if (dataBufferSize != mDataBuffer.size())
        mDataBuffer.resize(dataBufferSize);

    int dataOffset = 0;
    EmulatorCore::instance()->getMemory(firstAddr, mDataBuffer.data(), dataBufferSize);

    int tooltipX = 0;
    int tooltipY = 0;
    int addressUnderMouse = -1;
    int valueUnderMouse = -1;

    for (int n = 0; n < h; n++) {
        int mid = AddressWidth + Spacing + w * HexWidth - 1 + Spacing;
        int i = 0, j = mid;

        char buf[16];
        sprintf(buf, "%04X", (quint16)address);
        mLineBuffer[i++] = buf[0];
        mLineBuffer[i++] = buf[1];
        mLineBuffer[i++] = buf[2];
        mLineBuffer[i++] = buf[3];
        mLineBuffer[i++] = ' ';
        mLineBuffer[i++] = ' ';

        for (int xx = 0; xx < w && address <= 0xffff; xx++) {
            char byte = mDataBuffer[dataOffset++];

            int y1 = y;
            int y2 = y + CharHeight;
            int hexX1 = x + i * CharWidth - CharWidth / 2;
            int hexX2 = hexX1 + 3 * CharWidth;
            int txtX1 = x + j * CharWidth;
            int txtX2 = txtX1 + 1 * CharWidth;

            bool mouseOverHex = (mMouseX >= hexX1 && mMouseX < hexX2 && mMouseY >= y1 && mMouseY < y2);
            bool mouseOverTxt = (mMouseX >= txtX1 && mMouseX < txtX2 && mMouseY >= y1 && mMouseY < y2);

            if (mouseOverHex || mouseOverTxt) {
                addressUnderMouse = int((dataOffset - 1) + firstAddr);
                valueUnderMouse = (unsigned char)byte;
                painter.fillRect(hexX1, y1, 3 * CharWidth, CharHeight, Qt::green);
                painter.fillRect(txtX1, y1, 1 * CharWidth, CharHeight, Qt::green);
                tooltipX = (mouseOverHex ? hexX1 : txtX1);
                tooltipY = y1;
            }

            sprintf(buf, "%02X", (unsigned char)byte);
            mLineBuffer[i++] = buf[0];
            mLineBuffer[i++] = buf[1];
            mLineBuffer[i++] = ' ';

            // hide editor special characters
            unsigned char code = static_cast<unsigned char>(byte);
            if (code >= 0xFD)
                byte = 0;

            mLineBuffer[j++] = byte;

            ++address;
        }

        while (i < mid)
            mLineBuffer[i++] = ' ';

        drawText(&painter, x, y, mLineBuffer.data(), j, BLACK);
        y += CharHeight;
    }

    int startX1 = x + AddressWidth * CharWidth;
    int lineX1 = startX1 + (Spacing * CharWidth - 1) / 2;
    painter.setPen(Qt::gray);
    painter.drawLine(lineX1, 0, lineX1, pixH);

    int startX2 = x + (AddressWidth + Spacing + w * HexWidth - 1) * CharWidth;
    int lineX2 = startX2 + (Spacing * CharWidth - 1) / 2;
    painter.setPen(Qt::gray);
    painter.drawLine(lineX2, 0, lineX2, pixH);

    if (addressUnderMouse != mAddressUnderMouse) {
        mAddressUnderMouse = addressUnderMouse;
        if (addressUnderMouse < 0)
            mToolTip = QString();
        else {
            mToolTipX = tooltipX;
            mToolTipY = tooltipY;
            mToolTip = QStringLiteral("0x%1 / %2")
                .arg(QStringLiteral("%1").arg(addressUnderMouse, 4, 16, QChar('0')).toUpper())
                .arg(addressUnderMouse);
        }
        mUpdateToolTip = true;
    }

    if (mShowContextMenu) {
        mShowContextMenu = false;
        int mouseX = mMouseX;
        int mouseY = mMouseY;
        QTimer::singleShot(0, this, [this, firstAddr, addressUnderMouse, valueUnderMouse, mouseX, mouseY, w]() {
                QMenu menu;

                QAction* editAction = menu.addAction(tr("&Edit value..."));
                editAction->setEnabled(addressUnderMouse >= 0);
                connect(editAction, &QAction::triggered, this, [this, addressUnderMouse, valueUnderMouse] {
                        EditMemoryDialog dlg(unsigned(valueUnderMouse), 255, this);
                        if (dlg.exec() == QDialog::Accepted)
                            EmulatorCore::instance()->setMemory(addressUnderMouse, dlg.value());
                    });

                menu.addSeparator();

                QAction* gotoAddressAction = menu.addAction(tr("&Go to address..."));
                connect(gotoAddressAction, &QAction::triggered, this, [this, firstAddr, addressUnderMouse, w] {
                        auto addr = unsigned(addressUnderMouse >= 0 ? addressUnderMouse : firstAddr);
                        EditMemoryDialog dlg(addr, 65535, this);
                        dlg.setWindowTitle(tr("Go to address"));
                        dlg.setLabelText(tr("&Address:"));
                        if (dlg.exec() == QDialog::Accepted)
                            mScrollBar->setValue(dlg.value() / w * CharHeight);
                    });

                menu.exec(mapToGlobal(QPoint(mouseX, mouseY)));
            });
    }
}

void MemoryWidget::wheelEvent(QWheelEvent* event)
{
    mScrollBar->wheelEvent(event);
}

void MemoryWidget::contextMenuEvent(QContextMenuEvent* event)
{
    mShowContextMenu = true;
    mMouseX = event->pos().x();
    mMouseY = event->pos().y();
    update();
}

void MemoryWidget::mouseMoveEvent(QMouseEvent* event)
{
    mMouseX = event->pos().x();
    mMouseY = event->pos().y();
    update();
}

void MemoryWidget::leaveEvent(QEvent* event)
{
    mMouseX = INT_MIN;
    mMouseY = INT_MIN;
    mAddressUnderMouse = -1;
    mToolTip.clear();
    hideToolTip();
    update();
}

void MemoryWidget::hideEvent(QHideEvent* event)
{
    mUpdateToolTip = false;
    hideToolTip();
}

void MemoryWidget::keyPressEvent(QKeyEvent* event)
{
    mScrollBar->keyPressEvent(event);
}

void MemoryWidget::keyReleaseEvent(QKeyEvent* event)
{
    mScrollBar->keyReleaseEvent(event);
}

void MemoryWidget::updateToolTip()
{
    if (mUpdateToolTip) {
        mUpdateToolTip = false;
        if (mToolTip.isEmpty())
            hideToolTip();
        else
            showToolTip(mToolTipX, mToolTipY, mToolTip);
    }
}

void MemoryWidget::showToolTip(int tooltipX, int tooltipY, const QString& text)
{
    bool fadeWasEnabled = QApplication::isEffectEnabled(Qt::UI_FadeTooltip);
    bool animateWasEnabled = QApplication::isEffectEnabled(Qt::UI_AnimateTooltip);
    QApplication::setEffectEnabled(Qt::UI_FadeTooltip, false);
    QApplication::setEffectEnabled(Qt::UI_AnimateTooltip, false);

    QToolTip::showText(mapToGlobal(QPoint(tooltipX + 5, tooltipY + 5)), text, this);
    mShowingToolTip = true;

    QApplication::setEffectEnabled(Qt::UI_FadeTooltip, fadeWasEnabled);
    QApplication::setEffectEnabled(Qt::UI_AnimateTooltip, animateWasEnabled);
}

void MemoryWidget::hideToolTip()
{
    if (!mShowingToolTip)
        return;

    bool fadeWasEnabled = QApplication::isEffectEnabled(Qt::UI_FadeTooltip);
    bool animateWasEnabled = QApplication::isEffectEnabled(Qt::UI_AnimateTooltip);
    QApplication::setEffectEnabled(Qt::UI_FadeTooltip, false);
    QApplication::setEffectEnabled(Qt::UI_AnimateTooltip, false);

    QToolTip::hideText();
    mShowingToolTip = false;

    QApplication::setEffectEnabled(Qt::UI_FadeTooltip, fadeWasEnabled);
    QApplication::setEffectEnabled(Qt::UI_AnimateTooltip, animateWasEnabled);
}
