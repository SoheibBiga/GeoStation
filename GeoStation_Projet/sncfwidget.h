#ifndef SNCFWIDGET_H
#define SNCFWIDGET_H

#include <QWidget>

namespace Ui {
class sncfwidget;
}

class sncfwidget : public QWidget
{
    Q_OBJECT

public:
    explicit sncfwidget(QWidget *parent = 0);
    ~sncfwidget();

private:
    Ui::sncfwidget *ui;
};

#endif // SNCFWIDGET_H
