#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "calendarmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<CalendarModel>("MyCalendar", 1, 0, "CalendarClass");
  
    engine.loadFromModule("QtFormQuick", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

