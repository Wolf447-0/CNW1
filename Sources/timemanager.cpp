#include "timemanager.h"

TimeManager::TimeManager(QObject *parent) : QObject(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TimeManager::timeChanged);
    timer->start(1000);
}

QString TimeManager::currentTime() const {
    return QTime::currentTime().toString("hh:mm:ss");
}