#include "meteomozaicwidget.h"
#include "ui_meteomozaicwidget.h"

MeteoMozaicWidget::MeteoMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeteoMozaicWidget)
{
    ui->setupUi(this);
}

MeteoMozaicWidget::~MeteoMozaicWidget()
{
    delete ui;
}

void MeteoMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
}
