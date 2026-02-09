#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "calendarmodel.h"
#include "timemanager.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<CalendarModel>("MyCalendar", 1, 0, "CalendarClass");
    qmlRegisterType<TimeManager>("MyTime", 1, 0, "Time");
  
    engine.loadFromModule("QtFormQuick", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


