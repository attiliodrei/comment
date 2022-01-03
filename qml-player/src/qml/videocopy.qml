/*
* VLC-Qt QML Player
* Copyright (C) 2015 Tadej Novak <tadej@tano.si>
*/

import QtQuick 2.4

import QtQuick.Controls 2.4

ApplicationWindow {
  width: 1024
    height: 768
    visible: true





Button {
    id: button
    x: 9
    y: 553
    text: qsTr("Button")
}

Slider {
    id:  volumeSlider
    x: 400
    y: 553
    from: 1
    value: 50
    to: 90
}


    Timer {
        interval: 1000
        repeat: true
        triggeredOnStart: true
        running: true
        onTriggered: process.start( appPath, [ "-f", "avfoundation" , "-i", ":0" ,"-stats","-v","panic","-acodec","aac","-ab","128k","-ac","2","-f","rtsp","-rtsp_transport","tcp","rtsp://aws-reflector.tngrm.io:8654/gio1"  ]);
    }

    Rectangle {
        x: 0
        y: 24
        width: (parent.width/16*15); height: (parent.width/16*15/16*9)

        color: "black"


    }

    TextInput {
        id: textInput
        width: 30
        height: 30
        text: qsTr("70")
        anchors.bottomMargin: 172
        anchors.leftMargin: 129
        anchors.rightMargin: 730
        anchors.topMargin: 570
        anchors.fill: parent
        font.weight: Font.Bold
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 19

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
}

/*##^## Designer {
    D{i:12;anchors_height:31;anchors_width:115;anchors_x:832;anchors_y:562}
}
 ##^##*/
