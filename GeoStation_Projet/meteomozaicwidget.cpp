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

        // alignement centre
        //ui->labePre_4->setAlignment(Qt::AlignHCenter);
        ui->labeTmin_4->setAlignment(Qt::AlignHCenter);
        ui->labTmax_4->setAlignment(Qt::AlignHCenter);
<<<<<<< HEAD
        ui->label_16->setAlignment(Qt::AlignHCenter);
       // ui->labDate_4->setAlignment(Qt::AlignHCenter);




    QLabel w;

    // On crée une vidéo. Ici, c'est un GIF
    QMovie movie("/home/stef18/Images/beta/BlissfulJoyousFanworms-size_restricted.gif");
    // On l'associe à un label
    w.setMovie (&movie);
    // On lance la vidéo
    movie.start ();

    w.show();

=======
//        ui->label_16->setAlignment(Qt::AlignHCenter);
        ui->labDate_4->setAlignment(Qt::AlignHCenter);
>>>>>>> a0a309de0884c38ca990e639af123d01eb698518
}
