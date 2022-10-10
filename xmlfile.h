#ifndef XMLFILE_H
#define XMLFILE_H

#include <QStandardPaths>
#include <QString>
#include <QTime>
#include <QDir>
#include <QDebug>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomText>
#include <QTextStream>

class XmlFile
{
public:
    enum Day {
        Mon = 1,
        Tue = 2,
        Wed = 3,
        Thu = 4,
        Fri = 5,
        Sat = 6,
        Sun = 7
    };

    XmlFile(QString file = "");
    void addModule(QString moduleName, QString color, QString abbreviation);
    void addLecture(QString moduleName, QTime start, QTime duration, int week, Day day);
    void addSeminar(QString moduleName, QTime start, QTime duration, int week, Day day);
    void addLab(QString moduleName, QTime start, QTime duration, int week, Day day);
    void writeXml();
    QDomDocument getDoc();

private:
    QDomDocument doc;
    QString documentsFolder = "TestSchedule";
    QString fileName = "test.xml";
    void addActivity(QString moduleName, QString activity, QTime start, QTime duration, int week, XmlFile::Day day);

};
#endif // XMLFILE_H
