#ifndef SCHEDULEVIEW_H
#define SCHEDULEVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <xmlcoursedetails.h>
#include <QPalette>

class ScheduleView : public QWidget
{
    Q_OBJECT

private:
    QGridLayout *_layout;


public:
    explicit ScheduleView(QWidget *parent = nullptr);
    void createSchedule(XmlCourseDetails courseDetails);
signals:

};

#endif // SCHEDULEVIEW_H
