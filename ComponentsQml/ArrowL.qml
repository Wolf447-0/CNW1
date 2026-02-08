import QtQuick
import QtQuick.Window


Item {
    id:rootl
    width: 40
    height: 25
    signal clicked()
    Canvas {
        id:arrowCanvasL
        anchors.fill: parent
        onPaint: {
            const context = getContext("2d");
            context.reset();
            context.strokeStyle = mouseareaL.pressed? "#7b838f":"white"; 
            context.lineWidth = 2.5;
            context.lineCap = "round";
            context.lineJoin = "round";

            context.beginPath()
            context.moveTo(parent.width * 0.8, parent.height * 0.1);
            context.lineTo(parent.width * 0.2, parent.height / 2);
            context.lineTo(parent.width * 0.8, parent.height * 0.9)
            context.stroke();
        }
    }
        MouseArea{
        id:mouseareaL
        anchors.fill: parent
        hoverEnabled: true
        onClicked: rootl.clicked() 
        onPressedChanged: arrowCanvasL.requestPaint()
    }
}