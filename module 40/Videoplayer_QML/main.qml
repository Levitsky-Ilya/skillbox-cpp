import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    minimumWidth : 420
    minimumHeight : 100
    visible: true
    title: qsTr("Videoplayer QML")

    Button {
        text: "▶️"
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.horizontalCenterOffset: -150
        width: 70
    }

    Button {
        text: "⏸️"
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.horizontalCenterOffset: -75
        width: 70
    }

    Button {
        text: "⏹"
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.horizontalCenterOffset: 0
        width: 70
    }

    Button {
        text: "⏪️"
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.horizontalCenterOffset: 75
        width: 70
    }

    Button {
        text: "⏩️"
        font.pointSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40
        anchors.horizontalCenterOffset: 150
        width: 70
    }



    ProgressBar {
        value: 0.5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        width: parent.width-50
    }

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        width: parent.width-50
        height: parent.height-110
        color: "white"
        border.color: "black"
        border.width: 3
        radius: 0
    }
}
