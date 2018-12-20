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

void SatelliteMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    //ui->SatelliteMozaicWidget->refresh(map_formulaire);
}

