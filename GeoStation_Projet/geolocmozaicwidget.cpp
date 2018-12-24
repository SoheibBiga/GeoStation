#include "geolocmozaicwidget.h"
#include "ui_geolocmozaicwidget.h"
#include "pokemap.h"

GeoLocMozaicWidget::GeoLocMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeoLocMozaicWidget)
{
    ui->setupUi(this);
    ui->CP_edit->setEnabled(false);
    ui->VilleEdit->setEnabled(false);
    ui->AdresseEdit->setEnabled(false);
    ui->RegionEdit->setEnabled(false);
}

GeoLocMozaicWidget::~GeoLocMozaicWidget()
{
    delete ui;
}

void GeoLocMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    //ui->tableWidget->refresh(map_formulaire);
}

void GeoLocMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
   ui->AdresseEdit->setText(map_ameliore["Tableau"].toList().at(0).toMap()["adresse"].toString());
   ui->CP_edit->setText(map_ameliore["Tableau"].toList().at(0).toMap()["codePostal"].toString());
   ui->VilleEdit->setText(map_ameliore["Tableau"].toList().at(0).toMap()["ville"].toString());
   ui->RegionEdit->setText(map_ameliore["Tableau"].toList().at(0).toMap()["region"].toString());
}
