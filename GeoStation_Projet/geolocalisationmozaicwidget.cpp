#include "geolocalisationmozaicwidget.h"
#include "ui_geolocalisationmozaicwidget.h"

GeolocalisationMozaicWidget::GeolocalisationMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeolocalisationMozaicWidget)
{
    ui->setupUi(this);
}

GeolocalisationMozaicWidget::~GeolocalisationMozaicWidget()
{
    delete ui;
}
