/*
* VLC-Qt QML Player
* Copyright (C) 2015 Tadej Novak <tadej@tano.si>
*/

import QtQuick 2.4
import VLCQt 1.0
import QtQuick.Controls 2.4
import Process 1.0



ApplicationWindow {
  width: 1024
    height: 768
    visible: true


Process {
      id: myprocess
     // onReadyRead: element.text = readAll();
  }

Rectangle {
    id: rect
    x: 40
    y: 553
    width: 100
    height: 100
                    
    property bool isBlue: true
    color: isBlue ? "blue" : "green"
       border.color: "white"
                    border.width: 5
                    Text {
                        font.pixelSize: 25
                        anchors.centerIn: parent
                        text: rect.isBlue ? "start" : "stop"
                        color: "blue"
                    }
    
        MouseArea {
                        anchors.fill: parent
                        onClicked: {
                       //
                             rect.isBlue = !rect.isBlue
                            if ( rect.isBlue) {

                                //  myprocess.kill()
                                myprocess.stop()
                  //   mytimer.stop()
                               }
                             else {
                           //   myprocess.kill()
                   // myprocess.stop()
                     myprocess.start( appPath, Mic + textInput.text )
                    //mytimer.start()

                            }

                        }
                    }
    } 



Slider {
    id:  volumeSlider
    x: 400
    y: 553
    from: 1
    value: 20
    to: 90
}

  Text {
        id: element
        x: 9
        y: 650
        width: 913
        height: 48
        text: qsTr("test")
        font.pixelSize: 12
    }
    


  TextInput {
        id: textInput
        width: 2
        height: 30
        text: qsTr("7")
        anchors.bottomMargin: 172
        anchors.leftMargin: 129
        anchors.rightMargin: 730
        anchors.topMargin: 570
        anchors.fill: parent
        font.weight: Font.Bold
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 19
        onTextChanged: {   
           if (textInput.text > "0" ) {
         //  myprocess.kill()
         myprocess.stop()
        // mytimer.stop()
          rect.isBlue =  true
          }
        }
        Rectangle {
            id: rectangle
            x: 28
            y: -6
            width: 119
            height: 38
            color: "#00000000"
            radius: 9
            border.color: "#090808"
            border.width: 6
            opacity: 0.1
            visible: true
        }

    }


    Timer {
        id: mytimer
        interval: 1000
        repeat: true
        triggeredOnStart: false
        running: false
        onTriggered:   myprocess.start( appPath, [ "-f", "dshow" , "-i",  Mic ,"-stats","-v","panic","-acodec","aac","-ab","128k","-ac","2","-f","rtsp","-rtsp_transport","tcp","rtsp://aws-reflector.tngrm.io:8654/comment-" + textInput.text   ])
    }

Rectangle {
    x: 0
    y: 0
    width: (parent.width/16*15); height: (parent.width/16*15/16*9)

    color: "black"
    VlcVideoPlayer {
            id: vidwidget
            autoplay: true
            volume: volumeSlider.value
            anchors.fill: parent
            mediaOptions: [":network-caching=0", ":live-caching=0", ":rtsp-frame-buffer-size=300",":rtsp=tcp", ":rtsp-caching=50"]
            url: "rtmp://aws-reflector.tngrm.io:1935/comment-" + textInput.text +"/live.pubproxy"
        }
}

Component.onCompleted: {
          process.kill()
         Qt.callLater(Qt.quit)
    }

}
