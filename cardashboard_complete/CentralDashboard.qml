import QtQuick 2.10

Item {
    id: centralDashboard

    width:  dashBackground.width
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
                rotation    : 0
                arcOffset   : 40
                arcEnd      : _engine_control_unit.speed
                colorCircle: "yellow"
            }

            Image {
                visible: true
                id: revolution_counter_top
                source: "assets/images/03_taki_top.png"
                anchors.centerIn: parent

                SpeedMeter {
                    id: speed_meter
                    anchors.top:parent.top
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.topMargin: 140
                    speed:    _engine_control_unit.speed
                    total_km: _engine_control_unit.totalKm
                }

                GearView {
                    id: gear_view
                    anchors.top: speed_meter.bottom
                    anchors.topMargin: 30
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }

    GridIcons{
        id: icon_grid
        anchors.bottom : parent.bottom
        anchors.right  : parent.right
        anchors.bottomMargin: 250
        anchors.rightMargin: 90
        opacity: 0.90

        on_off_icon_flags : _engine_control_unit.leds
    }

    BottomBar {

        anchors.left:  centralDashboard.left
        anchors.right: centralDashboard.right
        anchors.leftMargin:  50
        anchors.rightMargin: 50
        height: 20
        anchors.bottom: centralDashboard.bottom
        anchors.bottomMargin: 14

        ctime:_engine_control_unit.currentime;
        cdate:_engine_control_unit.currentdate;
    }

    LogoImage{
        id: logo_image
        y: 10
        x: 5
    }

    VerticalBar{
       id: oil_bar

       anchors.left: parent.left
       anchors.leftMargin: 130
       anchors.bottom: parent.bottom
       anchors.bottomMargin: 80

        text: "Oil"
        value: _engine_control_unit.oilLevel
        opacity: 0.80

    }

    VerticalBar{
       id: fuel_bar

        anchors.right: oil_bar.left
        anchors.rightMargin: 10
        anchors.bottom: oil_bar.bottom

        text: "Fuel"
        value: _engine_control_unit.fuelLevel
        opacity: 0.80
    }
}
