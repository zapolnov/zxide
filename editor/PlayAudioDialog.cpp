#include "PlayAudioDialog.h"
#include "editor/Project.h"
#include "ui_PlayAudioDialog.h"
#include <QMediaPlayer>

PlayAudioDialog::PlayAudioDialog(Project* project, QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_PlayAudioDialog)
    , mDurationKnown(false)
{
    mUi->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);

    mUi->progressBar->setRange(0, 100);
    mUi->progressBar->setValue(0);

    mPlayer = new QMediaPlayer(this);
    connect(mPlayer, &QMediaPlayer::positionChanged, this, &PlayAudioDialog::onPositionChanged);
    connect(mPlayer, &QMediaPlayer::durationChanged, this, &PlayAudioDialog::onDurationChanged);
    connect(mPlayer, &QMediaPlayer::stateChanged, this, &PlayAudioDialog::onStateChanged);
    mPlayer->setVolume(100);
    mPlayer->setNotifyInterval(100);
    mPlayer->setMedia(QUrl::fromLocalFile(project->wavFileName()));
    mPlayer->play();
}

PlayAudioDialog::~PlayAudioDialog()
{
}

void PlayAudioDialog::onPositionChanged(qint64 position)
{
    setLabelTime(mUi->positionLabel, position);
    if (mDurationKnown) {
        qint64 duration = mPlayer->duration();
        mUi->progressBar->setRange(0, mUi->progressBar->width());
        mUi->progressBar->setValue(int(position * mUi->progressBar->maximum() / duration));
    }
}

void PlayAudioDialog::onDurationChanged(qint64 duration)
{
    setLabelTime(mUi->durationLabel, duration);
    mDurationKnown = true;
}

void PlayAudioDialog::onStateChanged(QMediaPlayer::State state)
{
    if (state != QMediaPlayer::PlayingState)
        reject();
}

void PlayAudioDialog::setLabelTime(QLabel* label, qint64 time)
{
    time /= 1000;

    int h = time / 3600;
    int m = (time % 3600) / 60;
    int s = (time % 3600) % 60;

    const QChar zero('0');
    label->setText(QStringLiteral("%1:%2:%3").arg(h, 2, 10, zero).arg(m, 2, 10, zero).arg(s, 2, 10, zero));
}
