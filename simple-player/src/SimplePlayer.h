/*
* VLC-Qt Simple Player
* Copyright (C) 2015 Tadej Novak <tadej@tano.si>
*/

#ifndef SIMPLEPLAYER_H_
#define SIMPLEPLAYER_H_
#include <QTimer>
#include <QMainWindow>
#include <QProcess>
namespace Ui {
    class SimplePlayer;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;
class EqualizerDialog;
class QProcess;

class SimplePlayer : public QMainWindow
{
    Q_OBJECT
public:
    explicit SimplePlayer(QWidget *parent = 0);
    ~SimplePlayer();
    QString ffmpeg;
    QString mic;
    void setProcess(const QString &ffmpegurl);
private slots:
    void openUrl();
    void slotTimerAlarm();
    void StopTimer();
    void Play();
    void onClicked();
    void closeEvent(QCloseEvent *event);
private:
    Ui::SimplePlayer *ui;
    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
    EqualizerDialog *_equalizerDialog;	
    QTimer *timer;
	QProcess *process;
};

#endif // SIMPLEPLAYER_H_
