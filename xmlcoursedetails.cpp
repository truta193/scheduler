#include "xmlcoursedetails.h"

XmlCourseDetails::XmlCourseDetails(XmlFile *file)
{
    this->xmlFile = file;
    QDomElement root = file->getDoc().documentElement();
    QDomNodeList modules = root.childNodes();
    int count = modules.count();

    for (int i = 0; i < count; i++)
    {
        XmlModuleDetails module(modules.at(i).toElement());
        this->modules.append(module);
    }
}

void XmlCourseDetails::update()
{
    this->modules.clear();
    QDomElement root = this->xmlFile->getDoc().documentElement();
    QDomNodeList modules = root.childNodes();
    int count = modules.count();

    for (int i = 0; i < count; i++)
    {
        XmlModuleDetails module(modules.at(i).toElement());
        this->modules.append(module);
    }
}

QVector<XmlModuleDetails> XmlCourseDetails::getModuleList()
{
    return this->modules;
}

XmlModuleDetails XmlCourseDetails::getModule(int index)
{
    return this->modules.at(index);
}
