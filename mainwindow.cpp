#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "menuside.h"
#include "scheduleview.h"
#include "settingsview.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //root layout containing all others
    mainLayout = new QHBoxLayout();
    mainWidget = new QWidget;
    mainWidget->setLayout(mainLayout);
    mainLayout->setAlignment(Qt::AlignTop);
    this->setCentralWidget(mainWidget);

    //Top menu including buttons
    MenuSide *menu = new MenuSide(this);
    mainLayout->addWidget(menu);

    //Schedule view with scroll area
    ScheduleView *sch = new ScheduleView();
    QScrollArea *scrollAreaSch = new QScrollArea();
    scrollAreaSch->setWidgetResizable(true);
    scrollAreaSch->setWidget(sch);
    scrollAreaSch->setMinimumWidth(570);
    //scrollAreaSch->verticalScrollBar()->setValue(400);
    menu->scheduleBtn->setViewIndex(0);

    XmlFile schedule("teo.xml");
    this->courseDetails = new XmlCourseDetails(&schedule);
    sch->createSchedule(*(this->courseDetails));

    //Courses view with scroll area
    SettingsView *crs = new SettingsView();
    QScrollArea *scrollAreaCrs = new QScrollArea();
    scrollAreaCrs->setWidgetResizable(true);
    scrollAreaCrs->setWidget(crs);
    menu->coursesBtn->setViewIndex(1);

    //Settings view with scroll area
    SettingsView *sett = new SettingsView();
    QScrollArea *scrollAreaSett = new QScrollArea();
    scrollAreaSett->setWidgetResizable(true);
    scrollAreaSett->setWidget(sett);
    menu->settingsBtn->setViewIndex(2);

    //Stack widget containing the views
    QStackedWidget *mainStack = new QStackedWidget(this);
    mainStack->setObjectName(QString("mainStack"));
    mainStack->addWidget(scrollAreaSch);
    mainStack->addWidget(scrollAreaCrs);
    mainStack->addWidget(scrollAreaSett);

    mainLayout->addWidget(mainStack);

    connect(menu->settingsBtn, &MenuButton::clicked, menu->settingsBtn, &MenuButton::emitOpenView);
    connect(menu->settingsBtn, &MenuButton::openView, mainStack, &QStackedWidget::setCurrentIndex);

    connect(menu->coursesBtn, &MenuButton::clicked, menu->coursesBtn, &MenuButton::emitOpenView);
    connect(menu->coursesBtn, &MenuButton::openView, mainStack, &QStackedWidget::setCurrentIndex);

    connect(menu->scheduleBtn, &MenuButton::clicked, menu->scheduleBtn, &MenuButton::emitOpenView);
    connect(menu->scheduleBtn, &MenuButton::openView, mainStack, &QStackedWidget::setCurrentIndex);


}

MainWindow::~MainWindow()
{
    delete this->courseDetails;
    delete ui;
}

