#include "meteomozaicwidget.h"
#include "ui_meteomozaicwidget.h"
#include <QDebug>
#include <QtGui>

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
    double max = map_ameliore["Tableau"].toList().at(0).toMap().value("Temperature Maximale").toDouble() - 273.15;
    double min = map_ameliore["Tableau"].toList().at(0).toMap().value("Temperature Minimale").toDouble() - 273.15;

    ui->labTmax_4->setText(QString::number(max)+ "°");
    ui->labeTmin_4->setText(QString::number(min)+ "°");

}
