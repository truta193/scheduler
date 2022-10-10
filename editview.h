#ifndef EDITVIEW_H
#define EDITVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class EditView : public QWidget
{
    Q_OBJECT
public:
    explicit EditView(QWidget *parent = nullptr);

private:
    QVBoxLayout *_layout;

signals:

};

#endif // EDITVIEW_H
