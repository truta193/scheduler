#ifndef MENUSIDE_H
#define MENUSIDE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <qstyleoption.h>
#include <QPainter>
#include <QSizePolicy>
#include <menubutton.h>

class MenuSide : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *_layout;

public:
    explicit MenuSide(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    MenuButton *scheduleBtn;
    MenuButton *settingsBtn;
    MenuButton *coursesBtn;


signals:

};

#endif // MENUSIDE_H
