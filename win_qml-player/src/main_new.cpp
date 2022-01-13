#include <QtCore/QCoreApplication>
#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QQmlApplicationEngine>
#include <QFileInfo>
#include <QProcess>
#include "process.h"
//#include "launcher.h"
#include <QtQml>

#include <VLCQtCore/Common.h>
#include <VLCQtQml/QmlVideoPlayer.h>
#include <QDebug>

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <QVariant>
#include <QObject>



Process::Process(QObject *parent) :
    QObject(parent),
    m_process(new QProcess(this))
{
}



void Process::start(const QString &program, const QVariantList &arguments)
{
    QStringList args;

           // convert QVariantList from QML to QStringList for QProcess

           for (int i = 0; i < arguments.length(); i++)
               args << arguments[i].toString();

            std::cout<<"Start Proc..." << program.toStdString() << "\n";


    m_process->start(program,args);
    m_process->waitForFinished(-1);

}


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


int main(int argc, char** argv)
{




    QGuiApplication app(argc, argv);

         QStringList args = app.arguments();
    if (args.count() > 0)
     {

         Console();
     }


     std::cout<<"start@@\n";



 QQmlApplicationEngine engine;

  qmlRegisterType<Process>("Process", 1, 0, "Process");

QQmlComponent component(&engine);



    QString  ffmpegpath=app.applicationDirPath() + "/ffmpeg.exe";
        if(QFileInfo::exists(ffmpegpath))
         {
                  
         }
         else {
            ffmpegpath=app.applicationDirPath() + "/Contents/MacOS/ffmpeg";
          
         }



       QUrl appPath(ffmpegpath );
 //   QUrl appPath(QString("%1").arg(app.applicationDirPath() +   "/ffmpeg" ));
        


//  qmlRegisterType<VlcQmlVideoPlayer>("VLCQt", 1, 0, "NetworkStream");


VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");

VlcQmlVideoPlayer::registerPlugin();

    //QUrl appPath(QString("/Applications/qml-player.app/Contents/MacOS/ffmpeg" ));

       QString findmic=app.applicationDirPath() + "/mic.cmd";
       QProcess mprocess;
       QStringList params={">", "%temp%/mic1.txt"};
       mprocess.start(findmic);
       mprocess.waitForFinished();
       QString micp = mprocess.readAllStandardOutput();
  QProcess process;
//engine.rootContext()->setContextProperty("process", mprocess );
    qInfo() << "C++ Style Info Message" << appPath;
engine.rootContext()->setContextProperty("appPath", appPath );

 engine.load(QUrl(QStringLiteral("qrc:/video.qml")));
    return app.exec();
} 
