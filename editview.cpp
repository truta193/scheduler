#include "editview.h"

EditView::EditView(QWidget *parent)
    : QWidget{parent}
{
    _layout = new QVBoxLayout(this);
    setLayout(_layout);

    QPushButton *b = new QPushButton(this);
    _layout->addWidget(b);
}
