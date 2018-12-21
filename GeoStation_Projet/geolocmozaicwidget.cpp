#include "geolocmozaicwidget.h"
#include "ui_geolocmozaicwidget.h"

GeoLocMozaicWidget::GeoLocMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeoLocMozaicWidget)
{
    ui->setupUi(this);
}

GeoLocMozaicWidget::~GeoLocMozaicWidget()
{
    delete ui;
}

void GeoLocMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    ui->tableWidget->refresh(map_formulaire);
}

void GeoLocMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    ui->tableWidget->refresh_ameliore(map_ameliore);
}
