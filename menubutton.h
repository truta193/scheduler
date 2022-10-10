#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QDebug>

class MenuButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MenuButton(QWidget *parent = nullptr, QString text = "");
    void setViewIndex(int i);
    int getViewIndex();

private:
    int viewIndex = -1;

signals:
    void openView(int index);

public slots:
    void emitOpenView();

};

#endif // MENUBUTTON_H
