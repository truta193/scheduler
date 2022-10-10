#include "mainwindow.h"
#include "xmlfile.h"
#include "xmlcoursedetails.h"

#include <QApplication>
#include <QFontDatabase>
#include "xmlfile.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/InputMono-Regular.ttf");
    /*
    XmlFile file = XmlFile("teo.xml");
    file.addModule("Anatomie", "#ff0000", "Ana");
    file.addModule("Biochimie", "#ff00ff", "BCH");
    file.addModule("Fiziologie", "#00ffff", "Fiz");
    file.addModule("Biostatistica", "#0f0f0f", "BFZ");
    file.addLecture("Anatomie", QTime(16,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Mon);
    file.addLecture("Biochimie", QTime(18,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Mon);
    file.addLecture("Anatomie", QTime(8,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Tue);
    file.addLecture("Fiziologie", QTime(10,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Wed);
    file.addLecture("Biostatistica", QTime(18,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Wed);
    file.addLecture("Anatomie", QTime(8,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Thu);
    file.addLecture("Fiziologie", QTime(10,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Fri);
    file.addLab("Anatomie", QTime(12,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Tue);
    file.addLab("Biostatistica", QTime(16,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Tue);
    file.addLab("Fiziologie", QTime(8,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Wed);
    file.addLab("Anatomie", QTime(12,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Thu);
    file.addLab("Biochimie", QTime(18,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Thu);
    file.addLab("Fiziologie", QTime(12,0,0,0), QTime(2,0,0,0), 1, XmlFile::Day::Fri);
    file.writeXml();
    */
    /*
    file.addModule("Programare", "#ffffff");
    file.addModule("Electrotehnica", "#ff44ff");
    file.addLecture("Programare", QTime(0,0,0,0), QTime(3,0,0,0), 1, "monday");
    file.addLecture("Programare", QTime(0,0,0,0), QTime(3,0,0,0), 1, "tuesday");
    file.addSeminar("Electrotehnica", QTime(5,0,0,0), QTime(2,0,0,0), 2, "wednesday");
    file.writeXml();


    CourseDetails c(&file);

    ModuleDetails m = c.getModule(0);

    QVector<Activity> ac = m.getLectureList();
    for(int i = 0; i < ac.count(); i++)
    {
        qInfo() << ac.at(i).day << ac.at(i).duration << ac.at(i).start << ac.at(i).week;
    }*/

    MainWindow w;
    w.show();

    return a.exec();
}
