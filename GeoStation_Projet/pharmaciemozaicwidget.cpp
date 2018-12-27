#include "pharmaciemozaicwidget.h"
#include "ui_pharmaciemozaicwidget.h"

#include "cherchephotos.h"

PharmacieMozaicWidget::PharmacieMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PharmacieMozaicWidget)
{
    ui->setupUi(this);

}

PharmacieMozaicWidget::~PharmacieMozaicWidget()
{
    delete ui;
}



void PharmacieMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
//    CherchePhotos* cherchePhotos = new CherchePhotos("Musée du Louvre", 4/*, nullptr, nullptr*/);
//    QPixmap photoPixmap = * (cherchePhotos->getPhoto());

    QPixmap *photoPixmap;
    photoPixmap= new QPixmap(":/Images/enseignePharmacie2.png");
    int w =ui->label_photo->width();
    int h = ui->label_photo->height();
    ui->label_photo->setPixmap(*photoPixmap);
    ui->label_photo->setPixmap(photoPixmap->scaled(w,h, Qt::KeepAspectRatio));
    ui->label_photo->setAlignment(Qt::AlignCenter);


    //ui->label_nom->setVisible(true);
    ui->label_nom2->setText(map_ameliore["Tableau"].toList().at(0).toMap().value("Nom").toString());
    //ui->label_nom->setPixmap(QPixmap(QString::fromUtf8(":/Icons/pharmacie.png")));
    ui->label_adresse2->setText(map_ameliore["Tableau"].toList().at(0).toMap().value("Adresse").toString());
    //ui->label_adresse->setPixmap(QPixmap(QString::fromUtf8(":/Icons/adresse.svg")));
    ui->label_codePostal->setText(map_ameliore["Tableau"].toList().at(0).toMap().value("CodePostal").toString());
    //ui->label_distance->setPixmap(QPixmap(QString::fromUtf8(":/Icons/distance.jpeg")));
    ui->label_distance_2->setText(map_ameliore["Tableau"].toList().at(0).toMap().value("Distance").toString());
}
