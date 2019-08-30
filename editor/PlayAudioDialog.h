#ifndef PLAYAUDIODIALOG_H
#define PLAYAUDIODIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <memory>

class Project;
class Ui_PlayAudioDialog;
class QLabel;

class PlayAudioDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayAudioDialog(Project* project, QWidget* parent = nullptr);
    ~PlayAudioDialog() override;

private:
    std::unique_ptr<Ui_PlayAudioDialog> mUi;
    QMediaPlayer* mPlayer;
    bool mDurationKnown;

    void onPositionChanged(qint64 position);
    void onDurationChanged(qint64 duration);
    void onStateChanged(QMediaPlayer::State state);

    static void setLabelTime(QLabel* label, qint64 time);

    Q_DISABLE_COPY(PlayAudioDialog)
};

#endif
