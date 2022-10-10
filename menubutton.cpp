#include "menubutton.h"

MenuButton::MenuButton(QWidget *parent, QString text)
    : QPushButton{parent}
{
    //QFont btnFont = QFont("Input Mono", 24, 2);
    this->setText(text);
    //this->setFont(btnFont);
    this->setMinimumSize(QSize(50, 50));
    this->setMaximumSize(QSize(50, 50));
    //this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void MenuButton::setViewIndex(int i)
{
    this->viewIndex = i;
}

int MenuButton::getViewIndex()
{
    return this->viewIndex;
}

void MenuButton::emitOpenView()
{
    emit openView(this->viewIndex);
}

