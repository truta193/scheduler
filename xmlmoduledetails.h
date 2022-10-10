#ifndef XMLMODULEDETAILS_H
#define XMLMODULEDETAILS_H

#include <QVector>
#include <QTime>
#include "xmlfile.h"
#include <QString>

typedef struct Activity
{
    QString name;
    QTime start;
    QTime duration;
    int week;
    int day;
} Activity;

class XmlModuleDetails
{
private:
    QString name;
    QString color;
    QString abbreviation;
    QVector<Activity> lectures;
    QVector<Activity> seminars;
    QVector<Activity> labs;
public:
    XmlModuleDetails(QDomElement module);
    QVector<Activity> getLectureList();
    Activity getLecture(int index = 0);
    QVector<Activity> getSeminarList();
    Activity getSeminar(int index = 0);
    QVector<Activity> getLabList();
    Activity getLab(int index = 0);
    QString getName();
    QString getColor();
    QString getAbbreviation();
};

#endif // XMLMODULEDETAILS_H
