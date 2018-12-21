#include "pharmaciemozaicwidget.h"
#include "ui_pharmaciemozaicwidget.h"

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

}

void PharmacieMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{

}
