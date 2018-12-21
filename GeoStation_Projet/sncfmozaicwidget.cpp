#include "sncfmozaicwidget.h"
#include "ui_sncfmozaicwidget.h"

SncfMozaicWidget::SncfMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SncfMozaicWidget)
{
    ui->setupUi(this);
}

SncfMozaicWidget::~SncfMozaicWidget()
{
    delete ui;
}

void SncfMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    ui->tableWidget->refresh(map_formulaire);

}


void SncfMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    ui->tableWidget->refresh_ameliore(map_ameliore);
}
