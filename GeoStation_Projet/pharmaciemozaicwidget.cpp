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

void PharmacieMozaicWidget::receive_info(QMap<QString, QString> map_formulare)
{
    ui->tableWidget->refresh(map_formulare);
}

void PharmacieMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    CherchePhotos* cherchePhotos = new CherchePhotos("Musée du Louvre", 4, nullptr, nullptr);
    QPixmap photoPixmap = * (cherchePhotos->getPhoto());

    int w =ui->label_photo->width();
    int h = ui->label_photo->height();
    //bool b = photoPixmap.isNull();
    ui->label_photo->setPixmap(photoPixmap.scaled(w,h, Qt::KeepAspectRatio));
    ui->label_photo->setAlignment(Qt::AlignCenter);

    //Ne pas oublier de le metttre
    //delete cherchePhotos;

    //ui->tableWidget->refresh_ameliore(map_ameliore);
}
