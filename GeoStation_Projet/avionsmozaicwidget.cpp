#include "avionsmozaicwidget.h"
#include "ui_avionsmozaicwidget.h"

AvionsMozaicWidget::AvionsMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AvionsMozaicWidget)
{
    ui->setupUi(this);
}

AvionsMozaicWidget::~AvionsMozaicWidget()
{
    delete ui;
}

void AvionsMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
   // ui->tableWidget->refresh(map_formulaire);
}
