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

#include <QStandardPaths>
HANDLE jobMainProcess = NULL;
#include <QDebug>
#include <QDir>
#include <QStringListModel>

QObject * s_qml_text_edit = 0;

Process::Process(QObject *parent) :
     QObject(parent),
     m_process(new QProcess(this))
 {
}
void Process::start(const QString &program, const QString &arguments)
{
      QStringList processargs= arguments.split(",");
   //QStringList processargs =  (QStringList() << "-f" << "dshow" << "-i" << "audio=\""         );

      if (!jobMainProcess) {
          jobMainProcess = CreateJobObject(NULL, NULL);
          if(NULL == jobMainProcess)
          {
            std::cout << "[WIN32] Could not create WIN32 Job. Node.exe will leak";
          }
          else
          {
              JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli = { 0 };
              jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE |\
                      JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION;
              if(0 == SetInformationJobObject( jobMainProcess, JobObjectExtendedLimitInformation, &jeli, sizeof(jeli)))
              {
                std::cout <<  "[WIN32] Failed to SetInformationJobObject";
              }
          }
      }



    QStringList args;

       // convert QVariantList from QML to QStringList for QProcess
        std::cout<<"Start..." << program.toStdString() <<  "\n";

       for (int i = 0; i < processargs.length(); i++)
           args << processargs[i];
       for (int i = 0; i < processargs.length(); i++)
           std::cout<< processargs[i].toStdString() << " ";

            std::cout<< "\n";

  std::cout<<"start@@\n";
 // QObject::connect(this, &QProcess::started, this, &Process::onStarted);

  QObject::connect( m_process, SIGNAL( started() ), this, SLOT( process_started() ) );

     m_process->start(program, args);

}

void Process::stop()
{
       std::cout<<"Stop..." <<  "\n";
     m_process->kill();


}

//QByteArray Process::readAll()
//{
//       return m_process->readAll();
//   }

void Process::process_started()
{
       std::cout<<"Started ..." <<  "\n";
       int err = AssignProcessToJobObject(jobMainProcess, ((_PROCESS_INFORMATION*)m_process->pid())->hProcess);
        if (0 == err) {
            qDebug() << "[WIN32] AssignProcessToJobObject failed with code: " << err;
        };


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


QStringListModel model1;

QStringList list;
// list.append("-");
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

//const QString temppath= QStandardPaths::writableLocation(QStandardPaths::TempLocation);

//const QString temppath= QDir::tempPath();

QString temppath= app.applicationDirPath();
// temp     QString  ffmpegpath=app.applicationDirPath() + "/ffmpeg.exe";
     QString  ffmpegpath = temppath + "/ffmpeg.exe"    ;

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

  // temp...
//QString findmic=app.applicationDirPath() + "/mic.cmd";

    //   QString findmic= temppath + "/mic.cmd";
 QString findmic=temppath  + "/ffmpeg.exe";



       QString findmicpar=  "-hide_banner,-loglevel,info,-f,dshow,-list_devices,true,-i,\"\"";

       QProcess mprocess;
      // QStringList params={">", "%temp/mic1.txt"};
    //   mprocess.start(findmic);
//const QStringList fparams= findmicpar.split(",");
QStringList fparams= {"-hide_banner","-loglevel","info","-f","dshow","-list_devices","true","-i", "\"\"" };
//QString line= "  pippo \"| -pluto !\"as \" ssss \" ";
//  std::cout<< line.toStdString() << "\n";
QString line;
 //QString micss= line.section('"', 0, 0)  ;
// QString micss= line.split('"').at(1);
 // std::cout<< micss.toStdString() << "\n";
 //std::cout<< findmicpar.toStdString() << "\n" ;
// std::cout<< micss.toStdString() << "\n";
//std::cout<< fparams.toStdString() << "\n" ;

  std::cout<< findmic.toStdString();
  mprocess.start(findmic,fparams);
//   mprocess.start(findmic);

       mprocess.waitForFinished(-1);
        QString micp;
 //      QString micp = mprocess.readAllStandardOutput();

//QString response = QString::fromUtf8( mprocess.readAll() );
   QString response = mprocess.readAllStandardError();
    //      QString response = mprocess.readAll();
       QString searchString("DirectShow audio devices");
         std::cout<< "Response";
         std::cout<< response.toStdString();

       QTextStream in (&response);
int found=0;

       do {
           line = in.readLine();
            std::cout<< line.toStdString();
       } while (!line.contains(searchString, Qt::CaseInsensitive));
const QString searchString2("]  \"");
std::cout<< "initial audio";
       do {
           line = in.readLine();

           std::cout<< "|" << line.toStdString()<< "|\n";


         if (line.contains(searchString2)) {
             QString device=line.split('"').at(1);
             std::cout<< "trovato: " << device.toStdString()  << "\n";
          // micp= line.section('"', 0, 0)  ;
             if ( found==0)
                    micp= device ;
             found=1;
            list.append(device);
         }

           } while (!line.isNull());



model1.setStringList(list);

       std::cout << "\nInput Audio Device  ... |"<< micp.toStdString() << "|\n";
engine.rootContext()->setContextProperty("model1", &model1);
//  QProcess process;
//engine.rootContext()->setContextProperty("process", mprocess );
    qInfo() << "C++ Style Info Message" << appPath;
engine.rootContext()->setContextProperty("appPath", appPath );

// old
//QString dshow = "audio=""" +  micp.trimmed() + """";
////dshow ="anullsrc";
////QString argproc =  "-f,lavfi,-i," + dshow +  ",-stats,-v,panic,-acodec,aac,-ab,128k,-ac,2,-f,rtsp,-rtsp_transport,tcp,rtsp://aws-reflector.tngrm.io:8654/comment-";
//
//QString argproc =  "-f,dshow,-i," + dshow +  ",-stats,-v,panic,-acodec,aac,-ab,128k,-ac,2,-f,rtsp,-rtsp_transport,tcp,rtsp://aws-reflector.tngrm.io:8654/comment-";

// tentativo lista
//QObject *rootObject = engine.rootObjects().first();
//s_qml_text_edit = engine.rootObjects().first()->findChild<QObject*>("micInput");
//QStringListModel<QObject *> list2 = = engine.rootObjects().first()->findChild<QObject*>("micInput");

//o= engine.rootObjects().first()->findChild<QObject*>("micInput");
//QStringListMod

//QList<QWidget *> childWidgets = ui->frame_3->findChildren<QWidget *>();

//QList<QWidget *> childWidgets = ui->frame_3->findChildren<QWidget *>();
//QStringList data;

//for(auto widget : childWidgets){
//    auto combo = dynamic_cast<QComboBox*>(widget);
//    if (combo) {
//       data << combo->currentText(); // currentText() returns the text from the combobox
//    }
//    else {
//        auto lineEdit = dynamic_cast<QLineEdit*>(widget);
//        if (lineEdit) {
//            data << lineEdit->text(); // A line edit has a text() member.
//        }
//    }
//}



//QObject *comboFaturacao_t = engine.rootObjects().first()->findChild<QObject*>("micInput");
//qDebug() << comboFaturacao_t->property("currentText");

//QString qv= comboFaturacao_t->property("currentText").toString();
//QString dshow = "audio=""" + qv  + """";

QString dshow = "audio=""" +  micp.trimmed()  + """";



//dshow ="anullsrc";
//QString argproc =  "-f,lavfi,-i," + dshow +  ",-stats,-v,panic,-acodec,aac,-ab,128k,-ac,2,-f,rtsp,-rtsp_transport,tcp,rtsp://aws-reflector.tngrm.io:8654/comment-";

QString argproc =  "-f,dshow,-i," + dshow +  ",-stats,-v,panic,-acodec,aac,-ab,128k,-ac,2,-f,rtsp,-rtsp_transport,tcp,rtsp://aws-reflector.tngrm.io:8654/comment-";

engine.rootContext()->setContextProperty("Mic", argproc );





//QString dshow = "audio=\"" + micp.trimmed()  + "\"";


 engine.load(QUrl(QStringLiteral("qrc:/video.qml")));
    return app.exec();
} 
