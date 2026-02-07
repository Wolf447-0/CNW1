import QtQuick
import QtQuick.Window


Item {
    width: 40
    height: 25

    Canvas {
        anchors.fill: parent
        onPaint: {
            const context = getContext("2d");
            context.reset();
            context.strokeStyle = "#7b838f";
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
}