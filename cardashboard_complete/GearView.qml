import QtQuick 2.10

Rectangle {

    id: gears

    width: 80
    height: 30

    color: "transparent"

    Row {
        spacing: 10

        Image {
            id: img_p
            source: "assets/images/Pr.png"

        }
        Image {
            id: img_r
            source: "assets/images/Rr.png"

        }
        Image {
            id: img_n
            source: "assets/images/Nr.png"

        }
        Image {
            id: img_d
            source: "assets/images/Dr.png"

        }
    }

    states: [
        State {
            name: "p"
            when: _engine_control_unit.gear === 1
            PropertyChanges {
                target: img_p
                scale: 1.8
            }
        },
        State {
            name: "r"
            when: _engine_control_unit.gear === 2
            PropertyChanges {
                target: img_r
                scale: 1.8
            }
        },
        State {
            name: "n"
            when: _engine_control_unit.gear === 3
            PropertyChanges {
                target: img_n
                scale: 1.8

            }
        },
        State {
            name: "d"
            when: _engine_control_unit.gear === 4
            PropertyChanges {
                target: img_d
                scale: 1.8
            }
        }
    ]
}
