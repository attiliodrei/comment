/*
* VLC-Qt Simple Player
* Copyright (C) 2015 Tadej Novak <tadej@tano.si>
*/

#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>

#include <VLCQtCore/Common.h>
#include <QProcess>
#include "SimplePlayer.h"

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <QDebug>
void Console()
{
    AllocConsole();
    FILE *pFileCon = NULL;
    pFileCon = freopen("CONOUT$", "w", stdout);

    COORD coordInfo;
    coordInfo.X = 130;
    coordInfo.Y = 9000;

    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coordInfo);
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE),ENABLE_QUICK_EDIT_MODE| ENABLE_EXTENDED_FLAGS);
}

	
	
int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("VLC-Qt Simple Player");
    QCoreApplication::setAttribute(Qt::AA_X11InitThreads);

    QApplication app(argc, argv);
    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");

    SimplePlayer mainWindow;
	
QString findmic=app.applicationDirPath() + "/mic.cmd";
QProcess mprocess;
QStringList params={">", "%temp%\mic1.txt"}; 
mprocess.start(findmic);
mprocess.waitForFinished();
//QFile file("/home/hamad/lesson11.txt");
//if(!file.open(QIODevice::ReadOnly)) {
//QStandardPaths::writableLocation(QStandardPaths::TempLocation) to get the temporary directory path as a QString. You'll need to #include <QStandardPaths> 
//  QMessageBox::information(0, "error", file.errorString());
//}
//QTextStream in(&file);..

QString micp = mprocess.readAllStandardOutput();
mainWindow.mic=micp.simplified();

	
	 QStringList args = app.arguments();
    if (args.count() > 1) 
    {
 
       	Console();
    }
	
	
    std::cout<<"start@@\n";


	
	QString ffmpegp=app.applicationDirPath() + "/ffmpeg.exe";
    mainWindow.ffmpeg=ffmpegp;
	//SimplePlayer::setProcess(app.applicationDirPath() + "/ffmpeg.exe");
		
    mainWindow.show();
    
    return app.exec();
}
