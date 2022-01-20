/*
* VLC-Qt QML Player
* Copyright (C) 2015 Tadej Novak <tadej@tano.si>
*/

#include <QtCore/QCoreApplication>
#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>

#include <VLCQtCore/Common.h>
#include <VLCQtQml/QmlVideoPlayer.h>
#include <QDebug>
#include <QtQml>
#include "process.h"

//void saveText(QQmlApplicationEngine &engine );



int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("VLC-Qt QML Player");
    QCoreApplication::setAttribute(Qt::AA_X11InitThreads);
    
    QGuiApplication app(argc, argv);
       QQmlApplicationEngine engine;
       QString  ffmpegpath=app.applicationDirPath() + "/ffmpeg";
        if(QFileInfo::exists(ffmpegpath))
         {
                  
         }
         else {
            ffmpegpath=app.applicationDirPath() + "/Contents/MacOS/ffmpeg";
          
         }

       QUrl appPath(ffmpegpath );
 //   QUrl appPath(QString("%1").arg(app.applicationDirPath() +   "/ffmpeg" ));
        
//QObject::connect(&app, &QCoreApplication::aboutToQuit, saveText( QQmlApplicationEngine &engine));  // qt5.9.6

      
    //QUrl appPath(QString("/Applications/qml-player.app/Contents/MacOS/ffmpeg" ));


    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");
    VlcQmlVideoPlayer::registerPlugin();
    qmlRegisterType<Process>("Process", 1, 0, "Process");

    qInfo() << "C++ Style Info Message" << appPath;
    QQuickView quickView;
    
Process process;


 //QObject::connect(&application, &QCoreApplication::aboutToQuit, handler); 
    
quickView.resize(1024, 768);

    
QQmlComponent component(&engine);

engine.rootContext()->setContextProperty("appPath", appPath );

quickView.rootContext()->setContextProperty("appPath", appPath );    
quickView.rootContext()->setContextProperty("process", &process ); 
//
 //QObject::connect(&app, &QCoreApplication::aboutToQuit,&process,process::stop()) {
 //       });
//

//QObject::connect(qApp, &QCoreApplication::aboutToQuit, qApp, [](){
//		qDebug() << "App about to quit!";
//		qApp->process;
//	});


QObject::connect(qApp, &QCoreApplication::aboutToQuit, &Process, [](){
		qDebug() << "App about to quit!";
		Process::kill();
	});
		
	

//  QObject::connect(&app, &QCoreApplication::aboutToQuit, []() {
//    qDebug() << "QApplication::aboutToQuit";
    //    process.kill();
     
//    });
      
  // QObject::connect(&app, &QCoreApplication::aboutToQuit, process, SLOT(kill()));
   
//engine.load(QUrl(QStringLiteral("qrc:/qml/video.qml")));

quickView.setSource(QUrl(QStringLiteral("qrc:/qml/video.qml")));


  
quickView.setResizeMode(QQuickView::SizeViewToRootObject);
engine.rootContext()->setContextProperty("_window", &quickView);  
//quickView.rootContext()->setContextProperty("_window", &engine);  

quickView.hide();
    return app.exec();
}

//void saveText(QQmlApplicationEngine &engine)
//{
// qInfo()  << "got signal: ";
// 
// QObject *root = 
//   qobject_cast<QObject *>(engine.rootObjects().value(0));
//   
//    QObject *object = root->findChild<QObject *>("ffmpegtimer");
//    if (!object) {
//        qDebug() << "Could not find processo";
//    }
//    else {
//        qDebug() << "Found processo";
//       object->setProperty("running", "running");
//
//    }
//     exit(0);
//     
//}

    