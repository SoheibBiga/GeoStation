#include "museesmainwidget.h"
#include "ui_museesmainwidget.h"

MuseesMainWidget::MuseesMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MuseesMainWidget)
{
    ui->setupUi(this);
}

/*MuseesMozaicWidget::~MuseesMozaicWidget()
{
    delete ui;
}*/


void MuseesMainWidget::receive_info(QMap<QString, QString> )
{
}

void MuseesMainWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
        ui->label_nomMusee->setText ( map_ameliore["nom_du_musee"].toString() );
        ui->label_nomMusee->setWordWrap(true);
        ui->label_nomMusee->setAlignment(Qt::AlignCenter);

        if ( map_ameliore.contains("adresse")  ){
            ui->gauche_adresse->setVisible(true) ;
            ui->droite_adresse->setVisible(true) ;
            ui->gauche_adresse->setPixmap(QPixmap(QString::fromUtf8(":/Icons/adresse.svg")));
            ui->droite_adresse->setText ( map_ameliore["adresse"].toString());
            ui->droite_adresse->setWordWrap(true);
        }
        else {
            ui->gauche_adresse->setVisible(false) ;
            ui->droite_adresse->setVisible(false) ;
        }

        if ( map_ameliore.contains("horaires") ){
            ui->gauche_horaires->setVisible(true) ;
            ui->droite_horaires->setVisible(true) ;
            ui->gauche_horaires->setPixmap(QPixmap(QString::fromUtf8(":/Icons/horaires.svg")));
            ui->droite_horaires->setText ( map_ameliore["horaires"].toString());
            ui->droite_horaires->setWordWrap(true);
        }
        else {
            ui->gauche_horaires->setVisible(false) ;
            ui->droite_horaires->setVisible(false) ;
        }

        if ( map_ameliore.contains("fermeture") ){
            ui->gauche_fermeture->setVisible(true) ;
            ui->droite_fermeture->setVisible(true) ;
            ui->gauche_fermeture->setPixmap(QPixmap(QString::fromUtf8(":/Icons/fermeture.svg")));
            ui->droite_fermeture->setText ( map_ameliore["fermeture"].toString());
            ui->droite_fermeture->setWordWrap(true);
        }
        else {
            ui->gauche_fermeture->setVisible(false) ;
            ui->droite_fermeture->setVisible(false) ;
        }

        if ( map_ameliore.contains("nocturnes") ){
            ui->gauche_nocturnes->setVisible(true) ;
            ui->droite_nocturnes->setVisible(true) ;
            ui->gauche_nocturnes->setPixmap(QPixmap(QString::fromUtf8(":/Icons/nocturnes.svg")));
            ui->droite_nocturnes->setText ( map_ameliore["nocturnes"].toString());
            ui->droite_nocturnes->setWordWrap(true);
        }
        else {
            ui->gauche_nocturnes->setVisible(false) ;
            ui->droite_nocturnes->setVisible(false) ;
        }


        // Affichage des photos :
        long long doublePhoto1 = map_ameliore["photo1"] . toLongLong();
        photo1 = reinterpret_cast <QPixmap*> (doublePhoto1) ;
        long long doublePhoto2 = map_ameliore["photo2"] . toLongLong();
        photo2 = reinterpret_cast <QPixmap*> (doublePhoto2) ;
        long long doublePhoto3 = map_ameliore["photo3"] . toLongLong();
        photo3 = reinterpret_cast <QPixmap*> (doublePhoto3) ;
        long long doublePhoto4 = map_ameliore["photo4"] . toLongLong();
        photo4 = reinterpret_cast <QPixmap*> (doublePhoto4) ;
        long long doublePhotoMap = map_ameliore["photoMap"] . toLongLong();
        photoMap = reinterpret_cast <QPixmap*> (doublePhotoMap) ;

        ajusteTaillesPhoto() ;
}




void MuseesMainWidget::ajusteTaillesPhoto()
{
    // get label dimensions
    int w1 = ui->label_photo1->width();
    int h1 = ui->label_photo1->height();
    int w2 = ui->label_photo2->width();
    int h2 = ui->label_photo2->height();
    int w3 = ui->label_photo3->width();
    int h3 = ui->label_photo3->height();
    int w4 = ui->label_photo4->width();
    int h4 = ui->label_photo4->height();
    int w5 = ui->label_map->width();
    int h5 = ui->label_map->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->label_photo1->setPixmap((*photo1).scaled(w1,h1,Qt::KeepAspectRatio));
    ui->label_photo2->setPixmap((*photo2).scaled(w2,h2,Qt::KeepAspectRatio));
    ui->label_photo3->setPixmap((*photo3).scaled(w3,h3,Qt::KeepAspectRatio));
    ui->label_photo4->setPixmap((*photo4).scaled(w4,h4,Qt::KeepAspectRatio));
    ui->label_map->setPixmap((*photoMap).scaled(w5,h5,Qt::KeepAspectRatio));

    ui->label_photo1->setAlignment(Qt::AlignCenter);
    ui->label_photo2->setAlignment(Qt::AlignCenter);
    ui->label_photo3->setAlignment(Qt::AlignCenter);
    ui->label_photo4->setAlignment(Qt::AlignCenter);
    ui->label_map->setAlignment(Qt::AlignCenter);
}



/*void MuseesMozaicWidget::resizeEvent ( QResizeEvent * )

{
    if ( ! photo.isNull() ){
        ajusteTaillePhoto() ;
    }
}*/

