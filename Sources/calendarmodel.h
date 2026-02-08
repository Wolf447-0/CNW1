#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H
#include <QAbstractListModel>

class CalendarModel : public QAbstractListModel
{
    Q_OBJECT
        Q_PROPERTY(int this_month READ getThis_month NOTIFY monthChanged)
        Q_PROPERTY(int this_year READ getThis_year NOTIFY yearChanged)
        Q_PROPERTY(int this_day READ getThis_day NOTIFY dayChanged)

        Q_PROPERTY(int realDay READ getRealDay CONSTANT)
        Q_PROPERTY(int realMonth READ getRealMonth CONSTANT)
        Q_PROPERTY(int realYear READ getRealYear CONSTANT)

public:
   
    enum Roles {
        DayNumberRole = Qt::UserRole + 1, 
        IsTodayRole                       
    };

    explicit CalendarModel(QObject *parent = nullptr);
    int getThis_month() const;
    int getThis_year() const;
    int getThis_day() const;

    int getRealDay() const;
    int getRealMonth() const;
    int getRealYear() const;

    void SetToCurrentDate();

    Q_INVOKABLE QVariant Get_name_month(int monthNum);
    Q_INVOKABLE QVariant Get_name_month_n(int monthNum);
    Q_INVOKABLE void Next_month();
    Q_INVOKABLE void Previos_month();

    
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    
    QHash<int, QByteArray> roleNames() const override;
signals:
void monthChanged();
void yearChanged();
void dayChanged();

private:
    int m_year;
    int m_month;
    int m_day;
};

#endif