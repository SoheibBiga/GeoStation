#ifndef SNCFWIDGET_H
#define SNCFWIDGET_H

#include "awidget.h"
#include <QMap>

namespace Ui {
class sncfwidget;
}

class sncfwidget : public AWidget
{
    Q_OBJECT

public:
    explicit sncfwidget(QWidget *parent = 0);
    ~sncfwidget();

private:
    Ui::sncfwidget *ui;

signals:
    void send_info(QMap<QString,QString>);

private slots:
    void receive_info(QMap<QString,QString>);
};

#endif // SNCFWIDGET_H
