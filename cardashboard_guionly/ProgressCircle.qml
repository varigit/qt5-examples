import QtQuick 2.10

Rectangle {
    id: root

    color: "#00000000"

    width: size
    height: size

    property int  size: 200              // The size of the circle in pixel
    property real arcBegin: 0            // start arc angle in degree
    property real arcEnd: 0            // end arc angle in degree
    property real arcOffset: 0           // rotation
    property real lineWidth: 20          // width of the line
    property string colorCircle: "#CC3333"

    onArcEndChanged: canvas.requestPaint()

    Canvas {
        id: canvas
        anchors.fill: parent
        rotation: 90+parent.arcOffset

        onPaint: {
            var ctx   = getContext("2d")
            var x     = width  / 2
            var y     = height / 2
            var start = Math.PI * (parent.arcBegin / 120)
            var end =   Math.PI * ((parent.arcEnd )/ 120)
            ctx.reset()

            ctx.beginPath();
            ctx.arc(x, y, (width / 2) - parent.lineWidth / 2, start, end, false)
            ctx.lineWidth = root.lineWidth
            ctx.strokeStyle = root.colorCircle
            ctx.stroke()
        }
    }
}
