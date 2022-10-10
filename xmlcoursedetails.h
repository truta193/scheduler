#ifndef XMLCOURSEDETAILS_H
#define XMLCOURSEDETAILS_H

#include <QVector>
#include "xmlfile.h"
#include "xmlmoduledetails.h"

class XmlCourseDetails
{
private:
    QVector<XmlModuleDetails> modules;
    XmlFile *xmlFile;
public:
    XmlCourseDetails(XmlFile *file);
    void update();
    QVector<XmlModuleDetails> getModuleList();
    XmlModuleDetails getModule(int index = 0);
};

#endif // XMLCOURSEDETAILS_H
