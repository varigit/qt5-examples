import QtQuick 2.5
import QtQuick.Window 2.5

Window {
    id: root

    title: qsTr("GPIO STEP FINAL")
    visible: true
    visibility: "FullScreen"

    width: 800
    height: 480

    Image {

        id: back_image
        source: "/images/background-05.png"

        anchors.fill: parent

        Image {

            id: qt_vari_logo
            source: "/images/qt_vari.png"
            z:1

            scale: 0.1
            x : -100

            NumberAnimation on x {
                easing.type: Easing.InElastic
                from:  -100
                to:400
                duration: 2000
            }

            NumberAnimation on rotation {
                from:  0
                to:360
                duration: 2000
            }

            NumberAnimation on scale {
                from: 0.1
                to:1.2
                duration: 2500
            }

            Behavior on x {

                ParallelAnimation {

                    NumberAnimation {
                        target: qt_vari_logo
                        property: "x"
                        duration: 2000
                        easing.type: Easing.InOutQuad
                    }


                    NumberAnimation {
                        target: qt_vari_logo
                        property: "rotation"
                        duration: 2000
                        easing.type: Easing.InOutQuad
                        from:0
                        to:360
                    }
                }
            }

            Behavior on y {
                NumberAnimation {
                    duration: 1000
                }
            }
        }

        ButtonPanel {

            id: left_panel
            z:1

            anchors.top: back_image.top
            anchors.topMargin: 100

            btn1_label: " GPIO 1 "
            btn2_label: " GPIO 2 "
            btn3_label: " GPIO 3 "
            btn4_label: " GPIO 4 "

            onClicked: {
                //Solo Pulsant1,2,3
                console.log("Cliccato puslante: ", nBtn);
                iocontrol.setPinSlot(nBtn,onoff_state);

                //iocontrol.autoBlink();
            }

            onPressed: {
                //Solo Pulsante 4
                console.log("Pressed: ", onoff);
                //scope.chStatus = onoff;
                //iocontrol.setPinSlot(4,onoff);
            }

            btn4_checked  :iocontrol.pin4Status

        }

        Scope {
            id: scope
            objectName: "myScope"
            z:1

            anchors.right: back_image.right
            anchors.rightMargin: 40
            anchors.verticalCenter: back_image.verticalCenter

            chStatus:iocontrol.pin4Status

            //onMyclicked: {
            //    console.log("CC");

            //}
        }


        MouseArea {
            anchors.fill: parent;

            onClicked: {

                console.log("Cliccato pannello background");

                qt_vari_logo.x = mouseX
                qt_vari_logo.y = mouseY

                if(left_panel.animationRunning == false)
                    left_panel.state = (left_panel.state == 'visible')?'hide':'visible';

            }
        }
    }
}
