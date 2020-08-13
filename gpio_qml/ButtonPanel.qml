import QtQuick 2.0

Rectangle {

    id: root
    color: "gray"

    property alias btn1_label: btn_1.btn_label
    property alias btn2_label: btn_2.btn_label
    property alias btn3_label: btn_3.btn_label
    property alias btn4_label: btn_4.btn_label

    property alias btn4_checked: btn_4.checked

    property bool animationRunning: tr_on.running | tr_off.running

    signal clicked(int  nBtn, bool onoff_state)
    signal pressed(bool onoff)

    height: btn_1.height+ btn_2.height+ btn_3.height +  btn_4.height + 60
    width:  btn_1.width + 20

    x : -width

    state: 'hide'

    LedButton {
        id: btn_1

        btn_label: " - "
        checkable:true

        anchors.left: parent.left
        anchors.leftMargin: 2

        anchors.top: parent.top
        anchors.topMargin: 10

        // @disable-check M16
        onClicked: {
            //console.log("Click on Pulsante btn_1")
            hide_timer.restart()
            root.clicked(1,onoff_state);
        }

    }

    LedButton {
        id: btn_2

        btn_label: " - "
        checkable:true

        anchors.left: parent.left
        anchors.leftMargin: 2

        anchors.top: btn_1.bottom
        anchors.topMargin: 10

        // @disable-check M16
        onClicked: {
            //console.log("Click on Pulsante btn_2")
            hide_timer.restart()
            root.clicked(2,onoff_state);
        }
    }

    LedButton {
        id: btn_3

        btn_label: " - "
        checkable:true

        anchors.left: parent.left
        anchors.leftMargin: 2

        anchors.top: btn_2.bottom
        anchors.topMargin: 10

        // @disable-check M16
        onClicked: {
            //console.log("Click on Pulsante btn_3")
            hide_timer.restart()
            root.clicked(3, onoff_state);
        }
    }

    LedButton {
        id: btn_4

        btn_label: " - "
        checkable:false


        anchors.left: parent.left
        anchors.leftMargin: 2

        anchors.top: btn_3.bottom
        anchors.topMargin: 10


        onClicked: {
            //console.log("Click on Pulsante btn_4")
            hide_timer.restart()
            root.clicked(4,onoff_state);
        }

        // @disable-check M16
        onPressed: {
            //console.log("Press on Pulsante btn_4 :", onoff);
            hide_timer.restart()
            root.pressed(onoff);
        }


    }

    states: [
        State {
            name: "hide"
            PropertyChanges {
                target: root
                x : -width
            }
            PropertyChanges {
                target: hide_timer
                running:false
            }
        },
        State {
            name: "visible"
            PropertyChanges {
                target: root
                x : 40
            }
            PropertyChanges {
                target: hide_timer
                running:true
            }

        }
    ]

    transitions: [

        Transition {
            id: tr_on

            from: "hide"
            to: "visible"

            SequentialAnimation {

                id:anim_to_visible

                NumberAnimation {
                    target: root
                    property: "x"
                    duration: 800
                    easing.type: Easing.InOutQuad
                    to: 40
                }


                NumberAnimation {
                    target: root
                    property: "opacity"
                    duration: 1000
                    easing.type: Easing.InOutQuad
                    to:1.0
                }

                onStopped: {
                    console.log("anim_to_visible terminata")
                    ide_timer.start();
                }
            }
        },
        Transition {
            id: tr_off

            from: "visible"
            to: "hide"

            SequentialAnimation {

                id:anim_to_hide

                NumberAnimation {
                    target: root
                    property: "rotation"
                    duration: 800
                    to:360
                    from: 0
                }

                NumberAnimation {
                    target: root
                    property: "x"
                    duration: 800
                    easing.type: Easing.InOutQuad
                    to: -width
                }
            }
        }
    ]


    Timer {
        id: hide_timer
        interval: 3500;
        onTriggered: {
            console.log("Time out");
            root.state = 'hide'
        }
    }
}
