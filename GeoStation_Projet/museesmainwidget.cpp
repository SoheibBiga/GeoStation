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

        if ( ! map_ameliore.contains("adresse")  ){
            ui->gauche_adresse->setPixmap(QPixmap(QString::fromUtf8(":/Icons/adresse.svg")));
            ui->droite_adresse->setText ( map_ameliore["adresse"].toString());
            ui->droite_adresse->setWordWrap(true);
        }
        if ( ! map_ameliore.contains("horaires") ){
            ui->gauche_horaires->setPixmap(QPixmap(QString::fromUtf8(":/Icons/horaires.svg")));
            ui->droite_horaires->setText ( map_ameliore["horaires"].toString());
            ui->droite_horaires->setWordWrap(true);
        }
        if ( ! map_ameliore.contains("fermeture") ){
            ui->gauche_fermeture->setPixmap(QPixmap(QString::fromUtf8(":/Icons/fermeture.svg")));
            ui->droite_fermeture->setText ( map_ameliore["fermeture"].toString());
            ui->droite_fermeture->setWordWrap(true);
        }
        if ( ! map_ameliore.contains("nocturnes") ){
            ui->gauche_nocturnes->setPixmap(QPixmap(QString::fromUtf8(":/Icons/nocturnes.svg")));
            ui->droite_nocturnes->setText ( map_ameliore["nocturnes"].toString());
            ui->droite_nocturnes->setWordWrap(true);
        }

        // Affichage de la photo :
        //double doublePhoto = map_ameliore["photo"] . toDouble();
        long long doublePhoto = map_ameliore["photo1"] . toLongLong();
        photo_1 = (QPixmap*) doublePhoto ;
        //qRegisterMetaType<QPixmap*>("qpixmap") ;
        //QVariant var = map_ameliore["photo"] ;
        //bool b = var.canConvert<QPixmap>() ;
        //photo = var.value<QPixmap*>() ;
        //photo = map_ameliore["photo"].value<QPixmap*>() ;
        //photo = map_ameliore["photo"].value<"qpixmap">() ;
        doublePhoto = map_ameliore["photo2"] . toLongLong();
        photo_2 = (QPixmap*) doublePhoto ;
        doublePhoto = map_ameliore["photo3"] . toLongLong();
        photo_3 = (QPixmap*) doublePhoto ;
        doublePhoto = map_ameliore["photo4"] . toLongLong();
        photo_4 = (QPixmap*) doublePhoto ;

        ajusteTaillesPhoto() ;
}




void MuseesMainWidget::ajusteTaillesPhoto()
{
    // get label dimensions
    int w1 = ui->photo1->width();
    int h1 = ui->photo1->height();
    int w2 = ui->photo2->width();
    int h2 = ui->photo2->height();
    int w3 = ui->photo3->width();
    int h3 = ui->photo3->height();
    int w4 = ui->photo4->width();
    int h4 = ui->photo4->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->photo1->setPixmap((*photo_1).scaled(w1,h1,Qt::KeepAspectRatio));
    ui->photo2->setPixmap((*photo_2).scaled(w2,h2,Qt::KeepAspectRatio));
    ui->photo3->setPixmap((*photo_3).scaled(w3,h3,Qt::KeepAspectRatio));
    ui->photo4->setPixmap((*photo_4).scaled(w4,h4,Qt::KeepAspectRatio));

    ui->photo1->setAlignment(Qt::AlignCenter);
    ui->photo2->setAlignment(Qt::AlignCenter);
    ui->photo3->setAlignment(Qt::AlignCenter);
    ui->photo4->setAlignment(Qt::AlignCenter);
}



/*void MuseesMozaicWidget::resizeEvent ( QResizeEvent * )

{
    if ( ! photo.isNull() ){
        ajusteTaillePhoto() ;
    }
}*/

