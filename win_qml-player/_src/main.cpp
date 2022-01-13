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
#include "cmd.h"



int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("VLC-Qt QML Player");
 
        QQmlApplicationEngine engine;
    QGuiApplication app(argc, argv);

       QString  ffmpegpath=app.applicationDirPath() + "/ffmpeg.exe";
        if(QFileInfo::exists(ffmpegpath))
         {
                  
         }
         else {
            ffmpegpath=app.applicationDirPath() + "/Contents/MacOS/ffmpeg";
          
         }

       QUrl appPath(ffmpegpath );


  VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");
   VlcQmlVideoPlayer::registerPlugin();
    qmlRegisterType<Process>("Process", 1, 0, "Process");

  
		
  QQmlComponent component(&engine);
  
 QQuickView quickView;
  engine.rootContext()->setContextProperty("appPath", appPath );

 engine.load(QUrl(QStringLiteral("qrc:/qml/video.qml")));

//quickView.setSource(QUrl(QStringLiteral("qrc:/qml/video.qml")));
quickView.setResizeMode(QQuickView::SizeRootObjectToView);
quickView.show();
    return app.exec();
}
