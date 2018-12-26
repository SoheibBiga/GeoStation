#include "vigicruesmosaicwidget.h"
#include "ui_vigicruesmosaicwidget.h"

Vigicruesmosaicwidget::Vigicruesmosaicwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vigicruesmosaicwidget)
{
    ui->setupUi(this);

    QMap<QString,QString> mp;
    mp.insert("2018-12-20T20:00:00+00:00","4.1");
    mp.insert("2018-12-20T20:30:00+00:00","3");
    mp.insert("2018-12-20T21:30:00+00:00","4.1");
    mp.insert("2018-12-20T22:30:00+00:00","5.23");
    mp.insert("2018-12-20T23:30:00+00:00","4.5");
    mp.insert("2018-12-21T00:30:00+00:00","3");
    this->receive_info(mp);
}

Vigicruesmosaicwidget::~Vigicruesmosaicwidget()
{
    delete ui;
}

void Vigicruesmosaicwidget::receive_info(QMap<QString, QString> map_formulaire)
{
   ui->graphique->refresh(map_formulaire);
   //qDebug()<<ui->graphique->size();
    //ui->graphique->update();
}
