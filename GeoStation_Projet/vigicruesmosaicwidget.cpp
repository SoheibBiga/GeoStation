#include "vigicruesmosaicwidget.h"
#include "ui_vigicruesmosaicwidget.h"

Vigicruesmosaicwidget::Vigicruesmosaicwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vigicruesmosaicwidget)
{
    ui->setupUi(this);

/*Pour tester le linechart
    QMap<QString,QString> mp;
    mp.insert("2018-12-20T20:00:00+00:00","4.1");
    mp.insert("2018-12-20T20:30:00+00:00","3");
    mp.insert("2018-12-20T21:30:00+00:00","4.1");
    mp.insert("2018-12-20T22:30:00+00:00","5.23");
    mp.insert("2018-12-20T23:30:00+00:00","4.5");
    mp.insert("2018-12-21T00:30:00+00:00","3");
    mp.insert("lbstationhydro","La Seine à Paris - Austerlitz");
    mp.insert("dist","2463");
    mp.insert("cdcommune","75056");
    mp.insert("période","journalière");

    this->receive_info(mp);
*/
}

Vigicruesmosaicwidget::~Vigicruesmosaicwidget()
{
    delete ui;
}

void Vigicruesmosaicwidget::receive_info(QMap<QString, QString> map_formulaire)
{

    ui->label->setText(QString("Station : "+map_formulaire.value("lbstationhydro")));
    map_formulaire.remove("lbstationhydro");
    ui->label_5->setText(QString("Distance (mètres) : "+map_formulaire.value("dist")));
    map_formulaire.remove("dist");
    ui->label_2->setText(QString("Code commune : "+map_formulaire.value("cdcommune")));
    map_formulaire.remove("cdcommune");
    ui->label_3->setText(QString("Période : "+map_formulaire.value("période")));
    map_formulaire.remove("période");


   ui->graphique->refresh(map_formulaire);
   //qDebug()<<ui->graphique->size();
    //ui->graphique->update();
}
