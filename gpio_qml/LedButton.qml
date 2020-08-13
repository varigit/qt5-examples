import QtQuick 2.0

Rectangle {
    id: root

    color: "transparent"

    implicitWidth:  button.width + led.width + 10
    implicitHeight: Math.max(button.height,led.height)

    property alias btn_label: btn_label.text
    property bool checkable: true
    property bool checked:   false

    state : (checked == true) ? 'on' : 'off';

    signal pressed(bool onoff)
    signal clicked(bool onoff_state)

    Image {

        id: button

        width: 180
        height: 60

        source: "/images/bottoneOff.png"

        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter

        Text {
            id: btn_label
            text: qsTr("btn")

            width: parent.width - 10
            height: 20

            color:  "white"

            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea {
            anchors.fill: parent

            onPressed: {
                root.pressed(true);
                if(checkable === false){
                   root.state = 'on';
                }
            }

            onReleased: {
                root.pressed(false);
                 if(checkable === false){
                    root.state = 'off';
                 }
            }

            onClicked:{
                if(checkable){
                    root.state = (root.state == 'on') ? 'off' : 'on';
                    //console.log("state: ", root.state );
                    root.clicked(root.state == 'on');
                }
            }
        }
    }

    Image {
        id: led

        width:  50
        height: 50

        source: "/images/circle_grey.png"

        anchors.left: button.right
        anchors.leftMargin: 10
        anchors.verticalCenter: button.verticalCenter

    }


    states: [
        State {
            name: "on"
            PropertyChanges {
                target: button
                source: "/images/bottoneOn.png"
            }
            PropertyChanges {
                target: led
                source: "/images/circle_green.png"
            }
        },
        State {
            name: "off"
            PropertyChanges {
                target: button
                source: "/images/bottoneOff.png"
            }
            PropertyChanges {
                target: led
                 source: "/images/circle_grey.png"
            }
        }
    ]



/*
    Component.onCompleted: {
        root.height = button.height + 10
        root.width  = button.width + led.width + 10
        console.log("w:",root.width, " h:",root.height);
    }
*/
}
