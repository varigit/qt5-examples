import QtQuick 2.10

Rectangle {

    id: prindle

    width: 80
    height: 30

    color: "transparent"
    
    enum Status {
        None,
        Park,
        Reverse,
        Neutral,
        Drive
    }

    property int gear_status: GearView.Status.None

    Row {

        spacing: 10

        Image {
            id: img_p
            source: "assets/images/prndl/Pr.png"
            scale: (gear_status == GearView.Status.Park) ? 1.7 : 1
        }
        Image {
            id: img_r
            source: "assets/images/prndl/Rr.png"
            scale: (gear_status == GearView.Status.Reverse) ? 1.7 : 1
        }
        Image {
            id: img_n
            source: "assets/images/prndl/Nr.png"
            scale: (gear_status == GearView.Status.Neutral) ? 1.7 : 1
        }
        Image {
            id: img_d
            source: "assets/images/prndl/Dr.png"
            scale: (gear_status == GearView.Status.Drive) ? 1.7 : 1
        }
    }
}
