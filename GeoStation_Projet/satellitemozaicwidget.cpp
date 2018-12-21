#include "satellitemozaicwidget.h"
#include "ui_satellitemozaicwidget.h"

SatelliteMozaicWidget::SatelliteMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SatelliteMozaicWidget)
{
    ui->setupUi(this);
}

SatelliteMozaicWidget::~SatelliteMozaicWidget()
{
    delete ui;
}

/*void SatelliteMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    //ui->SatelliteMozaicWidget->refresh(map_formulaire);
}*/

void SatelliteMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{

<<<<<<< HEAD
    //qDebug() << "receive_info2";

=======
>>>>>>> 73d0b5ab60420d6d7c93c2409340a09af7260785
    ui->Name->setText(map_ameliore["Tableau"].toList().at(0).toMap()["Nom"].toString());
    ui->ID->setText(map_ameliore.value("ID").toString());
    ui->DateLancement->setText(map_ameliore.value("Date de lancement").toString());
    ui->Altitude->setText(map_ameliore.value("Altitude").toString());
    ui->Latitude->setText(map_ameliore.value("Latitude").toString());
    ui->Longitude->setText(map_ameliore.value("Longitude").toString());

//    ui->SatelliteMozaicWidget.refresh_ameliore(map_ameliore);
}
