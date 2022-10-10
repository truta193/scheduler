#include "scheduleview.h"
#include "schedulebutton.h"

ScheduleView::ScheduleView(QWidget *parent)
    : QWidget{parent}
{
    _layout = new QGridLayout(this);
    setLayout(_layout);
    _layout->setColumnStretch(0, 1);

    QString days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // Days row
    for (int i = 1; i < 8; i++)
    {
        QLabel *l = new QLabel(this);
        l->setText(days[i-1]);
        _layout->setColumnStretch(i, 10);
        _layout->setColumnMinimumWidth(i, 50);
        _layout->addWidget(l, 0, i, 1, 1, Qt::AlignTop | Qt::AlignCenter);
    }

    //Hour column
    for (int i = 7; i < 24; i++)
    {
        QLabel *l = new QLabel(this);
        l->setMinimumSize(16, 50);
        l->setMaximumSize(16, 100);
        l->setText(QString("%1").arg(i));
        l->setAlignment(Qt::AlignBottom | Qt::AlignRight);
        _layout->addWidget(l, i, 0, 1, 1);
    }

    /*
    for (int i = 2; i < 4; i++)
    {
        ScheduleButton *b = new ScheduleButton(this);
        _layout->addWidget(b, i, 1, 1, 1);
    }
    for (int i = 1; i < 15; i++)
    {
        ScheduleButton *b = new ScheduleButton(this);
        _layout->addWidget(b, i, 2, 1, 1);
    }

    for (int i = 1; i < 7; i++)
    {
        ScheduleButton *b = new ScheduleButton(this);
        _layout->addWidget(b, i, 3, 1, 1);
    }

    for (int i = 1; i < 7; i++)
    {
        ScheduleButton *b = new ScheduleButton(this);
        _layout->addWidget(b, i, 4, 1, 1);
    }

    ScheduleButton *tt = new ScheduleButton(this);
    _layout->addWidget(tt, 2, 6, 1, 1);

    ScheduleButton *bb = new ScheduleButton(this);
    bb->setMaximumSize(200, 2*200);
    bb->setMinimumSize(80, 2*100);
    _layout->addWidget(bb, 4, 1, 2, 1);
    */

}

void ScheduleView::createSchedule(XmlCourseDetails courseDetails)
{
    QVector<XmlModuleDetails> moduleList = courseDetails.getModuleList();
    /*  For each module
     *      Day represents column
     *      Need to convert time to 0-24 integer and get row
     *      Extract color
     *      Determine abreviation
     */

    for (XmlModuleDetails module : moduleList)
    {
        auto looper = [&](QVector<Activity> list)
        {
            for (Activity actv : list)
            {
                ScheduleButton *b = new ScheduleButton(this);
                int column = actv.day;
                int row = actv.start.hour() + 1 % 24;
                int span = actv.duration.hour() % 24;
                b->setText(module.getAbbreviation().toUpper());
                b->setObjectName(QString("%1").arg(actv.name));
                QString textColor = "#000000";
                QString idleColor = module.getColor();
                QColor temp = QColor(idleColor);

                //Check for contrast, if not enough, switch text from black to white
                if ((temp.lightness() + 0.05) / 0.05 < 900) textColor = "#ffffff";
                temp.setRed(temp.red() / 2);
                temp.setGreen(temp.green() / 2);
                temp.setBlue(temp.blue() / 2);
                QString hoverColor = temp.name(QColor::HexRgb);
                temp.setRed(temp.red() / 2);
                temp.setGreen(temp.green() / 2);
                temp.setBlue(temp.blue() / 2);
                QString pressColor = temp.name(QColor::HexRgb);


                b->setStyleSheet(QString("ScheduleButton#%1 { \
                                            background-color: %2; \
                                            color: %5; \
                                            border: none; \
                                            border-radius: 10px; \
                                            outline: none } \
                                         ScheduleButton#%1:hover { \
                                            background-color: %3; } \
                                         ScheduleButton#%1:pressed { \
                                            background-color: %4; \
                                         }").arg(actv.name).arg(idleColor).arg(hoverColor).arg(pressColor).arg(textColor));

                _layout->addWidget(b, row, column, span, 1);
            }
        };

        looper(module.getLectureList());
        looper(module.getSeminarList());
        looper(module.getLabList());
    }
}
