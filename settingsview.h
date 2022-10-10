#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class SettingsView : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsView(QWidget *parent = nullptr);

private:
    QVBoxLayout *_layout;

signals:

};

#endif // SETTINGSVIEW_H
