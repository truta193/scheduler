#include "xmlmoduledetails.h"

XmlModuleDetails::XmlModuleDetails(QDomElement module)
{
    QDomNodeList lectures = module.firstChildElement("Lectures").childNodes();
    QDomNodeList seminars = module.firstChildElement("Seminars").childNodes();
    QDomNodeList labs = module.firstChildElement("Labs").childNodes();

    auto looper = [&](QDomNodeList list, QVector<Activity> *out)
    {
        int count = list.count();
        for (int i = 0; i < count; i++)
        {
            QDomElement temp = list.at(i).toElement();
            Activity actv;
            QTime time;
            actv.start = time.fromString(temp.attribute("time", ""));
            actv.duration = time.fromString(temp.attribute("duration", ""));
            actv.day = temp.attribute("day", "").toInt();
            actv.week = temp.attribute("week", "").toInt();
            actv.name = temp.tagName();
            out->append(actv);
        }
    };

    looper(lectures, &this->lectures);
    looper(seminars, &this->seminars);
    looper(labs, &this->labs);

    this->color = module.attribute("color", "");
    this->name = module.attribute("name", "");
    this->abbreviation = module.attribute("abbr", "");

}

QVector<Activity> XmlModuleDetails::getLectureList()
{
    return this->lectures;
}

Activity XmlModuleDetails::getLecture(int index)
{
    return this->lectures.at(index);
}

QVector<Activity> XmlModuleDetails::getSeminarList()
{
    return this->seminars;
}

Activity XmlModuleDetails::getSeminar(int index)
{
    return this->seminars.at(index);
}

QVector<Activity> XmlModuleDetails::getLabList()
{
    return this->labs;
}

Activity XmlModuleDetails::getLab(int index)
{
    return this->labs.at(index);
}

QString XmlModuleDetails::getName()
{
    return this->name;
}

QString XmlModuleDetails::getColor()
{
    return this->color;
}

QString XmlModuleDetails::getAbbreviation()
{
    return this->abbreviation;
}
