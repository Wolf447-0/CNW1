#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <QObject>
#include <QTimer>
#include <QTime>

class TimeManager : public QObject
{
    Q_OBJECT 
    Q_PROPERTY(QString currentTime READ currentTime NOTIFY timeChanged)

public:
    explicit TimeManager(QObject *parent = nullptr);
    QString currentTime() const; 

signals:
    void timeChanged();
};

#endif