#include "schedulebutton.h"

ScheduleButton::ScheduleButton(QWidget *parent, QString color)
    : QPushButton{parent}
{
    QPalette *pl = new QPalette(QColor(255, 0, 0));

    this->setPalette(*pl);
    this->update();

    //this->setStyleSheet(QString("ScheduleButton#%1{ background-color: %2; color: #222222; border: none; }").arg(this->objectName()).arg(color));

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setMaximumSize(200, 200);
    this->setMinimumSize(100, 100);
}
