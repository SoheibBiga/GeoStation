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

    ui->Name->setText(map_ameliore["Tableau"].toList().at(0).toMap()["Nom"].toString());
    ui->ID->setText(map_ameliore["Tableau"].toList().at(0).toMap()["ID"].toString());
    ui->DateLancement->setText(map_ameliore["Tableau"].toList().at(0).toMap()["Date de Lancement"].toString());
    ui->Altitude->setText(map_ameliore["Tableau"].toList().at(0).toMap()["Altitude"].toString());
    ui->Latitude->setText(map_ameliore["Tableau"].toList().at(0).toMap()["Latitude"].toString());
    ui->Longitude->setText(map_ameliore["Tableau"].toList().at(0).toMap()["Longitude"].toString());

//    ui->SatelliteMozaicWidget.refresh_ameliore(map_ameliore);
}
