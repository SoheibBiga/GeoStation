#ifndef VIGICRUESMOSAICWIDGET_H
#define VIGICRUESMOSAICWIDGET_H

#include <QWidget>
#include <QMap>
#include "QDebug"

namespace Ui {
class Vigicruesmosaicwidget;
}

class Vigicruesmosaicwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Vigicruesmosaicwidget(QWidget *parent = 0);
    ~Vigicruesmosaicwidget();

private:
    Ui::Vigicruesmosaicwidget *ui;
  /*  void paintEvent(QPaintEvent *p) {
        //qDebug()<<"paint evet VIGIMO";
    }*/


public slots:
    void receive_info(QMap<QString,QString> map_formulaire);
};

#endif // VIGICRUESMOSAICWIDGET_H
