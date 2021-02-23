import QtQuick 2.10

Rectangle {
    id: grid_icons

    width: 160
    height: 218

    color: "transparent"

    property int on_off_icon_flags: 0x0000


    Grid {

        columns: 3
        spacing: 2
        opacity: 0.6

        OnOffIcon{
            id: ico_0
            onImage: "assets/images/engine/01_ico_red.png"
            offImage:"assets/images/engine/01_ico_green.png"
            onoff: (on_off_icon_flags & 0x0001) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/engine/02_ico_red.png"
            offImage:"assets/images/engine/02_ico_green.png"
            onoff: (on_off_icon_flags & 0x0002) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/engine/03_ico_red.png"
            offImage:"assets/images/engine/03_ico_green.png"
            onoff: (on_off_icon_flags & 0x0004) ? true : false
        }

        OnOffIcon{
            onImage: "assets/images/engine/04_ico_red.png"
            offImage:"assets/images/engine/04_ico_green.png"
            onoff: (on_off_icon_flags & 0x0008) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/engine/05_ico_red.png"
            offImage:"assets/images/engine/05_ico_green.png"
            onoff: (on_off_icon_flags & 0x0010) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/engine/06_ico_red.png"
            offImage:"assets/images/engine/06_ico_green.png"
            onoff: (on_off_icon_flags & 0x0020) ? true : false
        }

        OnOffIcon{
            onImage: "assets/images/engine/07_ico_red.png"
            offImage:"assets/images/engine/07_ico_green.png"
            onoff: (on_off_icon_flags & 0x0040) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/engine/08_ico_red.png"
            offImage:"assets/images/engine/08_ico_green.png"
            onoff: (on_off_icon_flags & 0x0080) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/engine/09_ico_red.png"
            offImage:"assets/images/engine/09_ico_green.png"
            onoff: (on_off_icon_flags & 0x0100) ? true : false
        }

        OnOffIcon{
            onImage: "assets/images/engine/0A_ico_red.png"
            offImage:"assets/images/engine/0A_ico_green.png"
            onoff: (on_off_icon_flags & 0x0200) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/engine/0B_ico_red.png"
            offImage:"assets/images/engine/0B_ico_green.png"
            onoff: (on_off_icon_flags & 0x0400) ? true : false
        }
        OnOffIcon{
            onImage: "assets/images/engine/0C_ico_red.png"
            offImage:"assets/images/engine/0C_ico_green.png"
            onoff: (on_off_icon_flags & 0x0800) ? true : false
        }
    }
}
