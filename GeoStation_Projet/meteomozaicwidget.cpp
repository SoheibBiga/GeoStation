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
    ui->labTmax_4->setText(map_ameliore["Tableau"].toList().at(0).toMap().value("Temperature Maximale").toString());
    ui->labeTmin_4->setText(map_ameliore["Tableau"].toList().at(0).toMap().value("Temperature Minimale").toString());

        // alignement centre
        ui->labePre_4->setAlignment(Qt::AlignHCenter);
        ui->labeTmin_4->setAlignment(Qt::AlignHCenter);
        ui->labTmax_4->setAlignment(Qt::AlignHCenter);
        ui->label_16->setAlignment(Qt::AlignHCenter);
        ui->labDate_4->setAlignment(Qt::AlignHCenter);
}
