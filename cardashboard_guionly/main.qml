import QtQuick 2.10
import QtQuick.Window 2.2

Window {

    //visibility: Window.FullScreen

    visible: true
    width: 800
    height: 480
    title: qsTr("Car demo dashboard")

    Rectangle {
        anchors.fill: parent

        CentralDashboard {

            id: centralDashboard
            anchors.centerIn: parent

        }
    }
}
