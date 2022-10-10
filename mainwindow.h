#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QStackedWidget>
#include <QScrollBar>
#include <QLabel>
#include "xmlcoursedetails.h"
#include "xmlmoduledetails.h"
#include "xmlfile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QHBoxLayout *mainLayout;
    QWidget *mainWidget;
    //Make this a list to support multiple courses

public:
    XmlCourseDetails *courseDetails;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



};
#endif // MAINWINDOW_H
