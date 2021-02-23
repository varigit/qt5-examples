import QtQuick 2.10

Item {
    id: speed_meter

    property real speed: 100
    property real total_km: 100000

    width: 200
    height: 200

    Text {
        id: speed_txt
        anchors.horizontalCenter: speed_meter.horizontalCenter
        anchors.top: speed_meter.top
        anchors.topMargin: 10

        text: Math.ceil(speed).toString()
        font.pointSize: 50
        font.bold: true
        color: "white"
    }

    Text {
        id: measure
        anchors.top: speed_txt.bottom
        anchors.horizontalCenter: speed_meter.horizontalCenter
        text: "Km/h"
        color: "darkgrey"
    }

    Rectangle{

        anchors.top: measure.bottom
        anchors.topMargin: 55

        width: 120
        anchors.horizontalCenter: speed_meter.horizontalCenter

        height: 50

        border.color: "gray"
        border.width: 1
        radius: 10

        color: "transparent"

        Text {
            id: total_km_id

            anchors.centerIn: parent
            text: total_km
            font.pointSize: 13
            font.bold: false
            color: "lightgrey"
        }

        Text {
            id: total_km_label

            anchors.left: total_km_id.right
            anchors.leftMargin: 8
            anchors.verticalCenter: total_km_id.bottom
            text: "Km"
            color: "darkgrey"
        }
    }
}
