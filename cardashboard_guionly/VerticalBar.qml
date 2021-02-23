import QtQuick 2.0

Item {

    width: 20
    height: 260
    property int value: 100 //%
    property alias text: text_msg.text

    Text {

        id: text_msg
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

        text: text_msg
        color: "white"
    }

    Rectangle{
        id: container_rect

        anchors.top: text_msg.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        height: parent.height - (text_msg.height+6)
        width: parent.width

        color: "#414c50"

        Rectangle {
            id: filler

            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter            

            gradient: Gradient {
                GradientStop { position: 0.0; color: value > 25 ? "#148586" : "red" }
                GradientStop { position: 1.0; color: "white" }
            }

            radius: 2

            width: parent.width
            height: (parent.height/100.0)*value

        }
    }
}
