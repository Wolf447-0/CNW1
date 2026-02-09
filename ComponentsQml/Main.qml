import QtQuick
import QtQuick.Window
import QtQuick.Controls
import MyCalendar 1.0
import MyTime 1.0


Window {
    id: root
    width: 440
    height: 300
    visible: true
    title: qsTr("CNW")
    flags: Qt.Window | Qt.FramelessWindowHint
    color:"#80293240"

 
    DragHandler {
        target: null 
        onActiveChanged: if (active) root.startSystemMove()
    }



    Row{
        id:top_row
        anchors.top: parent.top
        height:50
        width: parent.width

        Rectangle{
            anchors.fill: parent
            color: "black"
            opacity: 0.4 
        } 
       Time {
    id: time
}


Item {
    height: parent.height
    width: parent.width / 2
   

    Text {
        anchors.centerIn: parent
        text: time.currentTime  
        font.pixelSize: 22
        color: "white"
        font.family: "Consolas"
    }
}

        Item{
            height:parent.height
            width:parent.width/2
           anchors.right: parent.right
            Rectangle{
                anchors.fill: parent
                color: "#2f2d40"
                opacity: 0.4 
            }
            Text{
                anchors.centerIn:parent
                text:calendarView.realDay + " " + calendarView.Get_name_month(calendarView.realMonth) +" "+ calendarView.realYear +" г."
                color: "#d0def5"
                font.family: "Consolas"
                font.pixelSize: 16
            }
        }

        Rectangle{
            id: line
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            height:2
            width: parent.width-10
            color: "white"
        }
    }


Row {
    id: line_day
    width: parent.width
    height:20
    anchors.top: top_row.bottom
    Repeater {
        model: ["Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"]
        
        delegate: Text {
            width: parent.width / 7 
            text: modelData        
            color: "white"
            horizontalAlignment: Text.AlignHCenter
        }
    }
}

GridView{
    id: model_day
    width:line_day.width
    anchors.top: line_day.bottom
    anchors.bottom: bottom_bar.top
    cellWidth: model_day.width/7
    cellHeight:(300-(50+50+10))/6

    model: CalendarClass {id: calendarView} 
    
    delegate: Rectangle {
        width: model_day.cellWidth
        height: model_day.cellHeight
        color: "transparent"
        border.color: isToday ? "red" : "transparent"
        border.width: isToday ? 2 : 0
        Text {
            anchors.centerIn: parent
            text: dayNumber
            color: "white"
        }
    }
}



Item {
    id: bottom_bar
    anchors.bottom: parent.bottom
    width: parent.width
    height: 50

    
    Rectangle {
        anchors.fill: parent
        color: "black"
        opacity: 0.4
    }
    Text{
        anchors.centerIn: parent
        text:calendarView.Get_name_month_n(calendarView.this_month) +" "+ calendarView.this_year
        font.pixelSize: 14
        color: "#d0def5"
        font.family: "Consolas"
    }
 
    ArrowL {
        id: arrow_l
        anchors.left: parent.left
        anchors.leftMargin: 20 
        anchors.verticalCenter: parent.verticalCenter 

        onClicked:{
            calendarView.Previos_month()
        }
    }

   
    ArrowR {
        id: arrow_r
        anchors.right: parent.right
        anchors.rightMargin: 20 
        anchors.verticalCenter: parent.verticalCenter
         onClicked:{
            calendarView.Next_month()
        }
    }
}

}
