import QtQuick 2.0

Item {

    id: icon_image

    property bool onoff: false;

    property string  onImage: "";
    property string  offImage: "";

    state: "off";

    height: off_icon_image.sourceSize.height;
    width: off_icon_image.sourceSize.width;

    onOnoffChanged: {
        if(onoff)
            state = "on";
        else
            state = "off";
    }

    Image {
        id: off_icon_image

        source: offImage
        visible: true;
        opacity: 0.7
        scale: 1.0

        anchors.centerIn: parent

    }

    Image {
        id: on_icon_image

        source: onImage

        visible: false;
        asynchronous: true;
        opacity: 0.8
        scale: 1.4

        anchors.centerIn: parent
    }

    states: [
        State {
            name: "on"

            PropertyChanges {
                target: off_icon_image
                visible: false
            }
            PropertyChanges {
                target: on_icon_image
                visible: true
            }

        },
        State {
            name: "off"

            PropertyChanges {
                target: off_icon_image
                visible: true
            }
            PropertyChanges {
                target: on_icon_image
                visible: false
            }
        }
    ]
}
