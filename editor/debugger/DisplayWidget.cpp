#include "DisplayWidget.h"
#include "debugger/EmulatorCore.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

DisplayWidget::DisplayWidget(QWidget* parent)
    : QOpenGLWidget(parent)
    , mTimer(new QTimer(this))
    , mScale(1)
{
    setFixedSize(EmulatorCore::ScreenWidth, EmulatorCore::ScreenHeight);

    mTimer->setInterval(1000 / 25);
    connect(mTimer, &QTimer::timeout, this, QOverload<>::of(&DisplayWidget::update));

    connect(EmulatorCore::instance(), &EmulatorCore::started, this, QOverload<>::of(&DisplayWidget::setFocus));
    connect(EmulatorCore::instance(), &EmulatorCore::started, mTimer, QOverload<>::of(&QTimer::start));
    connect(EmulatorCore::instance(), &EmulatorCore::stopped, mTimer, &QTimer::stop);
}

DisplayWidget::~DisplayWidget()
{
}

QSize DisplayWidget::sizeHint() const
{
    return QSize(EmulatorCore::ScreenWidth * mScale, EmulatorCore::ScreenHeight * mScale);
}

void DisplayWidget::paintGL()
{
    QPainter painter(this);

    if (!EmulatorCore::instance()->isRunning()) {
        painter.fillRect(0, 0, width(), height(), Qt::black);
        return;
    }

    QImage screen = EmulatorCore::instance()->getScreen();
    if (mScale > 1) {
        QSize size(screen.width() * mScale, screen.height() * mScale);
        // screen = screen.scaled(size, Qt::IgnoreAspectRatio, Qt::FastTransformation);
        painter.drawImage(QRect(0, 0, size.width(), size.height()), screen);
        return;
    }

    painter.drawImage(0, 0, screen);
}

void DisplayWidget::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_PageUp && mScale < 6) {
        ++mScale;
        setFixedSize(EmulatorCore::ScreenWidth * mScale, EmulatorCore::ScreenHeight * mScale);
    } else if (event->key() == Qt::Key_PageDown && mScale > 1) {
        --mScale;
        setFixedSize(EmulatorCore::ScreenWidth * mScale, EmulatorCore::ScreenHeight * mScale);
    }

    EmulatorCore::instance()->pressKey(event->key());
}

void DisplayWidget::keyReleaseEvent(QKeyEvent* event)
{
    EmulatorCore::instance()->releaseKey(event->key());
}
