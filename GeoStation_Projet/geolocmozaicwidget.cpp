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

void GeoLocMozaicWidget::receive_info(QMap<QString, QString>)
{

}

void GeoLocMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    if (ui->AdresseEdit->text().size() == 0)
    {
        ui->AdresseEdit->setText(map_ameliore["Tableau"].toList().at(0).toMap()["adresse"].toString());
        ui->CP_edit->setText(map_ameliore["Tableau"].toList().at(0).toMap()["codePostal"].toString());
        ui->VilleEdit->setText(map_ameliore["Tableau"].toList().at(0).toMap()["ville"].toString());
        ui->RegionEdit->setText(map_ameliore["Tableau"].toList().at(0).toMap()["region"].toString());
    }
    else if (pix.isNull())
    {
        pix.loadFromData(map_ameliore["Tableau"].toList().at(0).toMap()["map"].toByteArray());
        ui->label_2->setPixmap(pix.scaled(ui->label->parentWidget()->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
}
