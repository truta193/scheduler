#ifndef SCHEDULEBUTTON_H
#define SCHEDULEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QColor>

class ScheduleButton : public QPushButton
{
    Q_OBJECT

private:
    QString tag = "";
    QColor color = QColor(0, 0, 0);

public:
    explicit ScheduleButton(QWidget *parent = nullptr, QString color = "");
signals:

};

#endif // SCHEDULEBUTTON_H
