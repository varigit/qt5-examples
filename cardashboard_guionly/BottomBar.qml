import QtQuick 2.8

Item {
    id: bottomBar

    property string ctime: "8:30"
    property string cdate: "12 April 2020"
    property int font_size: 12


    Text {
        id: date
        font.pointSize: font_size
        color: "white"
        text: cdate
        anchors.left: bottomBar.left
        anchors.leftMargin: -24


    }

    Text {
        id: time
        font.pointSize: font_size
        anchors.right: bottomBar.right
        anchors.rightMargin: 40

        color: "white"
        text: ctime
    }
}
