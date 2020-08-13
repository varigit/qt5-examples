import QtQuick 2.0

Canvas {
    id: root

    width:  300
    height: 300

    property int  nGridDivision: 10

    property real dx: width/nGridDivision
    property real dy: height/nGridDivision

    property int  nHDorPoint: 50
    property real dxPoint: width/nHDorPoint

    property int cursorPosition: 0
    property var arrpoints : []

    property int chStatus: 0

    property color colorLine : "green"

    signal myclicked

    Component.onCompleted: {

        for(var i=0;i<(nHDorPoint+1);i++){
            arrpoints[i]=0;
        }
        update_timer.running = true;

        console.log("complete");
    }

    onPaint: {

        var ctx = getContext("2d");
        ctx.reset();


        ctx.fillStyle = Qt.rgba(0, 0, 0, 1);
        ctx.fillRect(0, 0, width, height);

        //Grid
        ctx.beginPath();

        ctx.strokeStyle = "gray";
        ctx.strokeWidth = 1;

        for(var i=1; i<nGridDivision;i++){
            ctx.moveTo(i*dx,0);
            ctx.lineTo(i*dx,height);
        }

        for(i=1; i<nGridDivision;i++){
            ctx.moveTo(0,i*dy);
            ctx.lineTo(width, i*dy);
        }

        ctx.stroke();

        ctx.beginPath();

        ctx.strokeStyle = colorLine;
        ctx.lineWidth   = 3;
        ctx.fillStyle   = "green";

        for(i=0; i < (nHDorPoint+1); i++){

            var x1 = (i-1)*dxPoint;
            var y1 = -(arrpoints[i-1]*100)+(height/2);

            if(i == cursorPosition)
                ctx.ellipse(x1,y1-4,8,8);

            ctx.moveTo(x1,y1);

            var x2 = i*dxPoint;
            var y2 = -(arrpoints[i]*100)+(height/2);

            ctx.lineTo(x2,y2);

        }

        ctx.stroke();

    }

    Timer {
        id: update_timer

        interval: 25;
        running:  false;
        repeat:   true

        onTriggered:{

            parent.arrpoints[parent.cursorPosition] = root.chStatus;

            parent.cursorPosition = parent.cursorPosition  + 1;
            if(parent.cursorPosition > parent.nHDorPoint)
                parent.cursorPosition = 0

            root.requestPaint()

        }
    }

    MouseArea{
        id: area

        anchors.fill: parent

        onClicked: {
            console.log("clicked");
            root.myclicked();
        }
    }
}
