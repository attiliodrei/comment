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
void Process::start(const QString &program, const QString &arguments)
{
      QStringList processargs= arguments.split(",");
   //QStringList processargs =  (QStringList() << "-f" << "dshow" << "-i" << "audio=\""         );


    QStringList args;

       // convert QVariantList from QML to QStringList for QProcess
        std::cout<<"Start..." << program.toStdString() <<  "\n";

       for (int i = 0; i < processargs.length(); i++)
           args << processargs[i];
       for (int i = 0; i < processargs.length(); i++)
           std::cout<< processargs[i].toStdString() << " ";

            std::cout<< "\n";

  std::cout<<"start@@\n";

     m_process->start(program, args);


}

void Process::stop()
{
       std::cout<<"Stop..." <<  "\n";
     m_process->kill();


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
    if (args.count() > 1)
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
      // QStringList params={">", "%temp/mic1.txt"};
       mprocess.start(findmic);
       mprocess.waitForFinished();
       QString micp = mprocess.readAllStandardOutput();
//  QProcess process;
//engine.rootContext()->setContextProperty("process", mprocess );
    qInfo() << "C++ Style Info Message" << appPath;
engine.rootContext()->setContextProperty("appPath", appPath );

QString dshow = "audio=""" +  micp.trimmed() + """";
QString argproc =  "-f,dshow,-i," + dshow +  ",-stats,-v,panic,-acodec,aac,-ab,128k,-ac,2,-f,rtsp,-rtsp_transport,tcp,rtsp://aws-reflector.tngrm.io:8654/comment-";


 //QString dshow = "audio=\"" + micp.trimmed()  + "\"";
engine.rootContext()->setContextProperty("Mic", argproc );
 engine.load(QUrl(QStringLiteral("qrc:/video.qml")));
    return app.exec();
} 
