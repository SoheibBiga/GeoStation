#include "pharmaciemozaicwidget.h"
#include "ui_pharmaciemozaicwidget.h"

#include "cherchephotos.h"

PharmacieMozaicWidget::PharmacieMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PharmacieMozaicWidget)
{
    ui->setupUi(this);
    CherchePhotos* cherchePhotos = new CherchePhotos("Enseigne de pharmacie", 4, nullptr, nullptr);
    QPixmap photoPixmap = * (cherchePhotos->getPhoto());
    ui->label_photo->setPixmap(photoPixmap);
    //Ne pas oublier de le metttre
    //delete cherchePhotos;
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
    ui->tableWidget->refresh_ameliore(map_ameliore);
}
