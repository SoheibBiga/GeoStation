#include "museesmozaicwidget.h"
#include "ui_museesmozaicwidget.h"

MuseesMozaicWidget::MuseesMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MuseesMozaicWidget)
{
    ui->setupUi(this);
}

/*MuseesMozaicWidget::~MuseesMozaicWidget()
{
    delete ui;
}*/


void MuseesMozaicWidget::receive_info(QMap<QString, QString> )
{
}

void MuseesMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
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
        long long doublePhoto = map_ameliore["photo"] . toLongLong();
        photo = (QPixmap*) doublePhoto ;
        //qRegisterMetaType<QPixmap*>("qpixmap") ;
        //QVariant var = map_ameliore["photo"] ;
        //bool b = var.canConvert<QPixmap>() ;
        //photo = var.value<QPixmap*>() ;
        //photo = map_ameliore["photo"].value<QPixmap*>() ;
        //photo = map_ameliore["photo"].value<"qpixmap">() ;
        ui->label_photo->setPixmap(*photo);
        ajusteTaillePhoto() ;
}




void MuseesMozaicWidget::ajusteTaillePhoto()
{
    // get label dimensions
    int w = ui->label_photo->width();
    int h = ui->label_photo->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->label_photo->setPixmap((*photo).scaled(w,h,Qt::KeepAspectRatio));


    ui->label_photo->setAlignment(Qt::AlignCenter);
}



/*void MuseesMozaicWidget::resizeEvent ( QResizeEvent * )

{
    if ( ! photo.isNull() ){
        ajusteTaillePhoto() ;
    }
}*/

