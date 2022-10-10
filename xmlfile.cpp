#include "xmlfile.h"

XmlFile::XmlFile(QString file)
{
    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QDir dir(documentsPath);

    this->fileName = file;

    if (!dir.exists()) dir.mkpath(documentsPath);
    if (!dir.exists(this->documentsFolder)) dir.mkdir(this->documentsFolder);
    dir.cd(this->documentsFolder);
    QString testXml = dir.absoluteFilePath(this->fileName);
    bool xmlExists = false;
    if (QFile::exists(testXml)) xmlExists = true;
    QFile *f = new QFile(testXml);

    if (!xmlExists)
    {
        bool result = f->open(QIODevice::ReadWrite);
        if (!result)
        {
            delete f;
            qInfo() << "Can't open file";
            throw;
        }

        QTextStream out(f);
        out << "<Modules/>";
        f->close();
    }

    bool result = f->open(QIODevice::ReadWrite);
    if (!result)
    {
        delete f;
        qInfo() << "Can't open file";
        throw;
    }

    this->doc.setContent(f);
    f->close();
}


void XmlFile::addActivity(QString moduleName, QString activity, QTime start, QTime duration, int week, Day day)
{
    QDomDocument doc = this->doc;
    QDomNode root = doc.documentElement();
    QDomNodeList moduleList = root.childNodes();
    int moduleCount = moduleList.count();

    int i = 0;
    while (moduleList.at(i).toElement().attribute("name") != moduleName)
    {
        i++;
        if ( i >= moduleCount)
        {
            qInfo() << QString("Could not find module %1!").arg(moduleName);
            return;
        }
    }
    QDomNode module = moduleList.at(i);

    QDomElement activityNode = module.firstChildElement(activity);
    QDomNodeList activityList = activityNode.childNodes();
    int nextActivityIndex = activityList.count();
    QDomElement newEntry = doc.createElement(QString("%1%2").arg(activity[0]).arg(nextActivityIndex));
    newEntry.setAttribute("day", day);
    newEntry.setAttribute("week", week);
    newEntry.setAttribute("time", start.toString());
    newEntry.setAttribute("duration", duration.toString());
    activityNode.appendChild(newEntry);
}

void XmlFile::addModule(QString moduleName, QString color, QString abbreviation) {
    QDomDocument doc = this->doc;
    QDomNode root = doc.documentElement();
    QDomNodeList childList = root.childNodes();
    int nextModule = childList.count();
    QDomElement newModule = doc.createElement(QString("Module%1").arg(nextModule));
    newModule.setAttribute("name", moduleName.toLower());
    newModule.setAttribute("color", color);
    newModule.setAttribute("abbr", abbreviation.toUpper());
    QDomElement lectureChild = doc.createElement("Lectures");
    QDomElement seminarChild = doc.createElement("Seminars");
    QDomElement labChild = doc.createElement("Labs");
    newModule.appendChild(lectureChild);
    newModule.appendChild(seminarChild);
    newModule.appendChild(labChild);
    root.appendChild(newModule);
}

void XmlFile::addLecture(QString moduleName, QTime start, QTime duration, int week, Day day)
{
    addActivity(moduleName, "Lectures", start, duration, week, day);
}

void XmlFile::addSeminar(QString moduleName, QTime start, QTime duration, int week, Day day)
{
    addActivity(moduleName, "Seminars", start, duration, week, day);
}

void XmlFile::addLab(QString moduleName, QTime start, QTime duration, int week, Day day)
{
    addActivity(moduleName, "Labs", start, duration, week, day);
}

void XmlFile::writeXml()
{
    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QDir dir(documentsPath);
    dir.cd(this->documentsFolder);

    QFile *f = new QFile(dir.absoluteFilePath(this->fileName));
    f->open(QIODevice::WriteOnly);
    QTextStream out(f);
    out << this->doc.toString(4);
    f->close();
}

QDomDocument XmlFile::getDoc()
{
    return this->doc;
}
