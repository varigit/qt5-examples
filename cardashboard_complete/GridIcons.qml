import QtQuick 2.10

Rectangle {
    id: grid_icons

    width:  80
    height: 30

    color: "transparent"

    property int on_off_icon_flags: 0x0000


    Grid {

        columns: 3
        spacing: 2
        opacity: 0.6

        OnOffIcon{
            id: ico_0
            onImage: "assets/images/motore/01_ico_red.png"
            offImage:"assets/images/motore/01_ico_green.png"
            onoff : (on_off_icon_flags & 0x0001) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/motore/02_ico_red.png"
            offImage:"assets/images/motore/02_ico_green.png"
            onoff : (on_off_icon_flags & 0x0002) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/motore/03_ico_red.png"
            offImage:"assets/images/motore/03_ico_green.png"
            onoff : (on_off_icon_flags & 0x0004) ? true : false
        }

        OnOffIcon{
            onImage: "assets/images/motore/04_ico_red.png"
            offImage:"assets/images/motore/04_ico_green.png"
            onoff : (on_off_icon_flags & 0x0008) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/motore/05_ico_red.png"
            offImage:"assets/images/motore/05_ico_green.png"
            onoff : (on_off_icon_flags & 0x0010) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/motore/06_ico_red.png"
            offImage:"assets/images/motore/06_ico_green.png"
            onoff : (on_off_icon_flags & 0x0020) ? true : false
        }

        OnOffIcon{
            onImage: "assets/images/motore/07_ico_red.png"
            offImage:"assets/images/motore/07_ico_green.png"
            onoff : (on_off_icon_flags & 0x0040) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/motore/08_ico_red.png"
            offImage:"assets/images/motore/08_ico_green.png"
            onoff : (on_off_icon_flags & 0x0080) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/motore/09_ico_red.png"
            offImage:"assets/images/motore/09_ico_green.png"
            onoff : (on_off_icon_flags & 0x0100) ? true : false
        }

        OnOffIcon{
            onImage: "assets/images/motore/0A_ico_red.png"
            offImage:"assets/images/motore/0A_ico_green.png"
            onoff : (on_off_icon_flags & 0x0200) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/motore/0B_ico_red.png"
            offImage:"assets/images/motore/0B_ico_green.png"
            onoff : (on_off_icon_flags & 0x0400) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/motore/0C_ico_red.png"
            offImage:"assets/images/motore/0C_ico_green.png"
            onoff : (on_off_icon_flags & 0x0800) ? true : false
        }
    }
}
