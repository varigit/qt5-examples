import QtQuick 2.10

Item {
    id: centralDashboard

    width: dashBackground.width
    height: dashBackground.height

    Image {

        id: dashBackground
        source: "assets/images/01_screen_background.png"
        anchors.centerIn: parent

        Image {
            id: taki_back
            source: "assets/images/02_taki_back.png"
            anchors.centerIn: parent

            ProgressCircle{
                anchors.fill: parent
                rotation: 0
                arcOffset: 30
                arcEnd: 76 //Speed
                colorCircle: "yellow"
            }

            Image {
                visible: true
                id: contagiri_top
                source: "assets/images/03_taki_top.png"
                anchors.centerIn: parent

                Speedometer {
                    id: speed_meter
                    anchors.top:parent.top
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.topMargin: 140
                    speed: 76 //Speed
                    total_km: 98
                }

                GearView {
                    id: gear_view
                    anchors.top: speed_meter.bottom
                    anchors.topMargin: 30
                    anchors.horizontalCenter: parent.horizontalCenter
                    
                    gear_status: GearView.Status.Drive
                }
            }
        }
    }

    GridIcons{
        id: icon_grid

        anchors.bottom: centralDashboard.bottom
        anchors.right: centralDashboard.right
        anchors.bottomMargin: 60
        anchors.rightMargin: 15

        on_off_icon_flags: 0x0002
    }

    BottomBar {
        id: bottom_bar

        anchors.left: centralDashboard.left
        anchors.right: centralDashboard.right
        anchors.leftMargin: 50
        anchors.rightMargin: 50
        height: 20
        anchors.bottom: centralDashboard.bottom
        anchors.bottomMargin: 14

        ctime:"10:32:54";
        cdate:"Wed Feb 24 2021";
    }

    LogoImage{
        id: logo_image
        y: 10
        x: 5
    }

    VerticalBar{
       id: oil_bar

       anchors.left: centralDashboard.left
       anchors.bottom: centralDashboard.bottom
       anchors.leftMargin: 130
       anchors.bottomMargin: 80

        text: "Oil"
        value: 75
        opacity: 0.80

    }

    VerticalBar{
       id: fuel_bar

        anchors.right: oil_bar.left
        anchors.rightMargin: 10
        anchors.bottom: oil_bar.bottom

        text: "Fuel"
        value: 53
        opacity: 0.80
    }
}
