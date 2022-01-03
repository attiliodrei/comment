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
        

    
    //QUrl appPath(QString("/Applications/qml-player.app/Contents/MacOS/ffmpeg" ));
    engine.rootContext()->setContextProperty("appPath", appPath );
    QQmlComponent component(&engine);
    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");
    VlcQmlVideoPlayer::registerPlugin();
    qmlRegisterType<Process>("Process", 1, 0, "Process");

    qInfo() << "C++ Style Info Message" << appPath;
    QQuickView quickView;
    engine.load(QUrl(QStringLiteral("qrc:/qml/video.qml")));
  //  quickView.setSource(QUrl(QStringLiteral("qrc:/qml/video.qml")));
    quickView.setResizeMode(QQuickView::SizeRootObjectToView);
    quickView.show();

    return app.exec();
}
