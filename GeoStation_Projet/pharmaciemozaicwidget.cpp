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
    QPixmap *photoPixmap;
    photoPixmap = new QPixmap(":/Images/enseignePharmacie.png");

    int w =ui->label_photo->width();
    int h = ui->label_photo->height();

    ui->label_photo->setPixmap(photoPixmap->scaled(w,h, Qt::KeepAspectRatio));
    ui->label_photo->setAlignment(Qt::AlignCenter);

    ui->tableWidget->refresh_ameliore(map_ameliore);
}
