#include "meteomozaicwidget.h"
#include "ui_meteomozaicwidget.h"
#include <QDebug>

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
    ui->lineEdit_3->setText(map_ameliore["Tableau"].toList().at(0).toMap().value("Temperature Maximale").toString());
}
