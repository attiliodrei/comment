/*
* VLC-Qt Simple Player
* Copyright (C) 2015 Tadej Novak <tadej@tano.si>
*/

#include <QFileDialog>
#include <QInputDialog>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <stdio.h>
#include <iostream>
#include <QCloseEvent>
#include "EqualizerDialog.h"

#include "SimplePlayer.h"
#include "ui_SimplePlayer.h"





SimplePlayer::SimplePlayer(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::SimplePlayer),
      _media(0),
      _equalizerDialog(new EqualizerDialog(this))
{
   	
    ui->setupUi(this);
    ui->start->setProperty("clicked", false);
    ui->start->setStyleSheet("QPushButton { background-color: blue; }\n");
    timer = new QTimer();
    process = new QProcess();

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);
    _equalizerDialog->setMediaPlayer(_player);
			
    ui->video->setMediaPlayer(_player);
    ui->volume->setMediaPlayer(_player);
    ui->volume->setVolume(50);
    ui->seek->setMediaPlayer(_player);
   
    SimplePlayer::Play();
     
// QString channel = ui->textEdit->toPlainText();
// QString currenturl= "rtmp://aws-reflector.tngrm.io:1935/comment-" + channel +"/live.pubproxy";
// _media = new VlcMedia(currenturl, _instance);
// _media->setOption(":network-caching=0" );
// _media->setOption(":live-caching=0" );
// _media->setOption(":rtsp-frame-buffer-size=300" );
// _media->setOption(":rtsp=tcp" );
// _media->setOption(":rtsp-caching=50" );
// _player->open(_media);

	
    connect(ui->actionOpenUrl, &QAction::triggered, this, &SimplePlayer::openUrl);
 //   connect(ui->actionStop, &QAction::triggered, _player, &VlcMediaPlayer::stop);
 //   connect(ui->stop, &QPushButton::clicked, this,   &SimplePlayer::StopTimer);
    connect(ui->start, &QPushButton::clicked, this,   &SimplePlayer::onClicked);
	connect(ui->textEdit, &QTextEdit::textChanged,   this,  &SimplePlayer::Play);
    connect(ui->openUrl, &QPushButton::clicked, this, &SimplePlayer::openUrl);
//  connect(ui->stop, &QPushButton::clicked, _player, &VlcMediaPlayer::stop);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    connect(ui->equalizer, &QPushButton::clicked, _equalizerDialog, &EqualizerDialog::show);	
	connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(quitMyApp()));

   // timer->start(1000); 
}

SimplePlayer::~SimplePlayer()
{
    delete _player;
    delete _media;
    delete _instance;
    delete ui;
}



void SimplePlayer::openUrl()
{
    QString url =
            QInputDialog::getText(this, tr("Open Url"), tr("Enter the URL you want to play"));

    if (url.isEmpty())
        return;

    _media = new VlcMedia(url, _instance);

    _player->open(_media);
}

void SimplePlayer::slotTimerAlarm()
{
    /* Ежесекундно обновляем данные по текущему времени
     * Перезапускать таймер не требуется
     * */
     
     std::cout<<"Timer..." << ffmpeg.toStdString() <<  "\n";
	 std::cout<<"Start Timer..." << mic.toStdString() << "\n";
    QString channel = ui->textEdit->toPlainText();
	 QString dshow = "audio=""" + mic + """";
	QString argproc =  "-f,dshow,-i," + dshow +  ",-stats,-v,panic,-acodec,aac,-ab,128k,-ac,2,-f,rtsp,-rtsp_transport,tcp,rtsp://aws-reflector.tngrm.io:8654/comment-" +channel;
	 QStringList processargs= argproc.split(",");
	//QStringList processargs =  (QStringList() << "-f" << "dshow" << "-i" << "audio=\""         );
    process->start( ffmpeg ,  processargs);

}

void SimplePlayer::StopTimer()
{
	 	std::cout<<" Stop Timer...\n";
        timer->stop();
}




void SimplePlayer::Play()
{
	    QString channel = ui->textEdit->toPlainText();
		
    std::cout<<"Start Play...\n";
    _player->stop();
	process->kill();
	timer->stop();
	ui->start->setProperty("clicked", false);
	ui->start->setStyleSheet("QPushButton { background-color: blue; }\n");
	
	//ui->video->setMediaPlayer(_player);
if (channel > "0" ) {
	QString currenturl= "rtmp://aws-reflector.tngrm.io:1935/comment-" + channel +"/live.pubproxy";
    _media = new VlcMedia(currenturl ,  _instance);
	//const QStringList mediaopt  ={":network-caching=0",":live-caching=0",":rtsp-frame-buffer-size=300",":rtsp=tcp",":rtsp-caching=50"} ;
	//QString mediaopt=":network-caching=0 :clock-jitter=0 :sout-mux-caching:0 :live-caching=0 :rtmp-caching=0 :tcp-caching=0 :rtsp-frame-buffer-size=300 :rtsp=tcp :rtsp-caching=50" ;
	//QStringList<QString> list;
	//list << "--network-caching=0" << ":live-caching=0" << ":rtsp-frame-buffer-size=300" << ":rtsp-frame-buffer-size=300" <<":rtsp=tcp" <<":rtsp-caching=50" ;
     _media->setOption(":network-caching=0"  );
     _media->setOption(":live-caching=0"  );
     _media->setOption(":rtsp-frame-buffer-size=300"  );
     _media->setOption(":rtsp=tcp"  );
	 _media->setOption(":rtmp-caching=0"  );
	 _media->setOption(":rtsp=tcp"  );
	 _media->setOption(":rtsp-caching=50"  );
     _media->setOption(":tcp-caching=0"  );
	 _media->setOption(":sout-mux-caching=0"  );
	 _media->setOption(":file-caching=0"  );
	 _media->setOption(":clock-jitter=0"  );

	//_media->setOption(mediaopt);
    _player->open(_media);

     }
 
}
void SimplePlayer::setProcess(const QString &ffmpegurl)
{
  ffmpeg = ffmpegurl;

}
void SimplePlayer::onClicked()
{
   std::cout<<"Start Timer...\n";
    QPushButton* target = qobject_cast<QPushButton*>(sender());
    //target->setProperty("clicked", !target->clicked);
   process->kill();
 if ( timer->isActive()) {
	  std::cout<<"Stop Timer...\n" ;
      timer->stop();
	  ui->start->setStyleSheet("QPushButton { background-color: blue; }\n");
		
 }
   else {
	      std::cout<<"Start Timer...\n";
   timer->start();
   	ui->start->setStyleSheet("QPushButton { background-color: green; }\n");
 }
}
void SimplePlayer::closeEvent (QCloseEvent *event)
{
        process->kill();
        timer->stop();
        event->accept();
		QWidget::closeEvent(event);
}


							   