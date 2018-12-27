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
    QString temps = map_ameliore["Tableau"].toList().at(0).toMap().value("Temps").toString();
    double humidite = map_ameliore["Tableau"].toList().at(0).toMap().value("Humidite").toDouble();
    double pression = map_ameliore["Tableau"].toList().at(0).toMap().value("Pression").toDouble();

    ui->Max->setText(QString::number(max)+ "°");
    ui->Min->setText(QString::number(min)+ "°");
    ui->Humidite->setText(QString::number(humidite)+ "%");
    ui->prev->setText(QString::number(pression)+ " HPa");

}
