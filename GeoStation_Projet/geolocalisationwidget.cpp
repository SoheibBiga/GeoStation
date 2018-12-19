#include "geolocalisationwidget.h"
#include "ui_geolocalisationwidget.h"

GeolocalisationWidget::GeolocalisationWidget(QWidget *parent) :
    AWidget(parent),
    ui(new Ui::GeolocalisationWidget)
{
    ui->setupUi(this);
    connect(this, &Abstract)
}

GeolocalisationWidget::~GeolocalisationWidget()
{
    delete ui;
}
