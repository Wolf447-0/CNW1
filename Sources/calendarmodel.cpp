#include "calendarmodel.h"
#include <QDate>


int CalendarModel::getThis_year() const{
    return m_year;
}
int CalendarModel::getThis_month() const{
    return m_month;
}
int CalendarModel::getThis_day() const{
    return m_day;
}

int CalendarModel::getRealDay() const { return QDate::currentDate().day(); }
int CalendarModel::getRealMonth() const { return QDate::currentDate().month(); }
int CalendarModel::getRealYear() const { return QDate::currentDate().year(); }


void CalendarModel::SetToCurrentDate(){
    QDate today = QDate::currentDate();

    m_year = today.year();
    m_month = today.month();
    m_day = today.day();
   emit monthChanged();
   emit yearChanged();
   emit dayChanged();

   emit dataChanged(index(0), index(41));
}

QVariant CalendarModel:: Get_name_month(int monthNum){
    QString name;
    switch (monthNum)
    {
    case 1:name="Января";
        break;
    case 2:name="Февраля";
        break;    
    case 3:name="Марта";
        break;
     case 4:name="Апреля";
        break;
    case 5:name="Мая";
        break;    
    case 6:name="Июня";
        break;   
      case 7:name="Июля";
        break;
    case 8:name="Августа";
        break;    
    case 9:name="Сентября";
        break;
     case 10:name="Октября";
        break;
    case 11:name="Ноября";
        break;    
    case 12:name="Декабря";
        break;       
    default:
        break;
    }
    return name;
}

QVariant CalendarModel:: Get_name_month_n(int monthNum){
    QString name;
    switch (monthNum)
    {
    case 1:name="Январь";
        break;
    case 2:name="Февраль";
        break;    
    case 3:name="Март";
        break;
     case 4:name="Апрель";
        break;
    case 5:name="Май";
        break;    
    case 6:name="Июнь";
        break;   
      case 7:name="Июль";
        break;
    case 8:name="Август";
        break;    
    case 9:name="Сентябрь";
        break;
     case 10:name="Октябрь";
        break;
    case 11:name="Ноябрь";
        break;    
    case 12:name="Декабрь";
        break;       
    default:
        break;
    }
    return name;
}

CalendarModel::CalendarModel(QObject *parent) : QAbstractListModel(parent) {
   SetToCurrentDate();
}

int CalendarModel::rowCount(const QModelIndex &parent) const {
    return 42; 
}

QHash<int, QByteArray> CalendarModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DayNumberRole] = "dayNumber";
    roles[IsTodayRole] = "isToday";   
    return roles;
}


QVariant CalendarModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return QVariant();

  
    QDate firstDay(getThis_year(), getThis_month(), 1);
    int startOffset = firstDay.dayOfWeek() - 1; 
    int daysInMonth = firstDay.daysInMonth();
    int dayNum = index.row() - startOffset + 1;

    if (role == DayNumberRole) {
        if (dayNum > 0 && dayNum <= daysInMonth) {
            return QString::number(dayNum);
        }
        return QString(""); 
    }

 if (role == IsTodayRole) {
    QDate realToday = QDate::currentDate(); 
    return (dayNum == realToday.day() && 
            m_month == realToday.month() && 
            m_year == realToday.year());
}

    return QVariant();
}

void CalendarModel::Next_month(){
    bool flag=true;
    if (m_month>=1 && m_month<=12){
        m_month++;
        if (m_month==13){
            m_month=1;
            flag=false;
        }
    }
    if (flag==false){
        m_year++;
        flag=true;
    }
    emit monthChanged();
    emit yearChanged();
    emit dataChanged(index(0), index(41));
}

void CalendarModel::Previos_month(){
    bool flag=true;
    if (m_month>=1 && m_month<=12){
        m_month--;
        if (m_month==0){
            m_month=12;
            flag=false;
        }
    }
    if (flag==false){
        m_year--;
        flag=true;
    }
    emit monthChanged();
    emit yearChanged();
    emit dataChanged(index(0), index(41));
}