#include "satellitemainwidget.h"
#include "ui_satellitemainwidget.h"

SatelliteMainWidget::SatelliteMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SatelliteMainWidget)
{
    ui->setupUi(this);
}

SatelliteMainWidget::~SatelliteMainWidget()
{
    delete ui;
}
