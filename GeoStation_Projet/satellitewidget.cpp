#include "satellitewidget.h"
#include "ui_satellitewidget.h"

satelliteWidget::satelliteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::satelliteWidget)
{
    ui->setupUi(this);
}

satelliteWidget::~satelliteWidget()
{
    delete ui;
}
