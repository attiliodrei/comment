import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.platform 1.1
import Process 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        py.start("bash")
    }

    // use py.close() or py.kill(0 or py.terminate() to kill the process
    Component.onDestruction: py.close()

    Process {
        id: py

        property string output: ""

        onStarted: print("Started")
        onFinished: print("Closed")

        onErrorOccurred: console.log("Error Ocuured: ", error)

        onReadyReadStandardOutput: {
            output = py.readAll()
            term.text += output
        }
    }

    Page {

        anchors.fill: parent

        ScrollView {
            id: view
            anchors.fill: parent

            TextArea {
                id: term
                textFormat: TextArea.RichText
            }
        }

        footer: RowLayout {
            Layout.fillWidth: true

            TextField {
                id: input
                Layout.fillWidth: true
            }
            Button {
                text: "Send!"
                property string command: input.text.trim() + "\n"
                onClicked: {
                    py.write(command)
                    term.text += ("<br /><b>" + command + " : </b>")
                }
            }
        }
    }
}