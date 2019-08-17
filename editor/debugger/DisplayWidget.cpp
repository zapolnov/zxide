#include "DisplayWidget.h"
#include "debugger/EmulatorCore.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

DisplayWidget::DisplayWidget(QWidget* parent)
    : QOpenGLWidget(parent)
    , mTimer(new QTimer(this))
{
    setFixedSize(EmulatorCore::ScreenWidth, EmulatorCore::ScreenHeight);

    mTimer->setInterval(1000 / 50);
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
    return QSize(EmulatorCore::ScreenWidth, EmulatorCore::ScreenHeight);
}

void DisplayWidget::paintGL()
{
    QPainter painter(this);

    if (!EmulatorCore::instance()->isRunning()) {
        painter.fillRect(0, 0, width(), height(), Qt::black);
        return;
    }

    painter.drawImage(0, 0, EmulatorCore::instance()->getScreen());
}

void DisplayWidget::keyPressEvent(QKeyEvent* event)
{
    EmulatorCore::instance()->pressKey(event->key());
}

void DisplayWidget::keyReleaseEvent(QKeyEvent* event)
{
    EmulatorCore::instance()->releaseKey(event->key());
}
