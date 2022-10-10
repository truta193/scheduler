#include "menuside.h"

MenuSide::MenuSide(QWidget *parent)
    : QWidget{parent}
{
    this->setObjectName(QString("topbar"));
    this->setStyleSheet("#topbar { background-image: url(:/images/side-bg.png); } ");

    //Layout automatically assigns it's items the widget it belongs to as parent
    _layout = new QVBoxLayout(this);
    _layout->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    _layout->setMargin(0);
    setLayout(_layout);

    this->setMaximumWidth(50);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    scheduleBtn = new MenuButton(this);
    scheduleBtn->setIcon(QIcon(":/images/schedule.png"));
    scheduleBtn->setIconSize(QSize(50, 50));
    _layout->addWidget(scheduleBtn);
    coursesBtn = new MenuButton(this);
    coursesBtn->setIcon(QIcon(":/images/courses.png"));
    coursesBtn->setIconSize(QSize(50, 50));
    _layout->addWidget(coursesBtn);
    settingsBtn = new MenuButton(this);
    settingsBtn->setIcon(QIcon(":/images/settings.png"));
    settingsBtn->setIconSize(QSize(50, 50));
    _layout->addWidget(settingsBtn);

}

void MenuSide::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}
