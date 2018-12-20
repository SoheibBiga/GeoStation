#include "evenementmozaicwidget.h"
#include "ui_evenementmozaicwidget.h"

EvenementMozaicWidget::EvenementMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvenementMozaicWidget)
{
    ui->setupUi(this);
}

EvenementMozaicWidget::~EvenementMozaicWidget()
{
    delete ui;
}
void EvenementMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    //ui->tableWidget->refresh(map_formulaire);
}

void EvenementMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
   // ui->tableWidget->refresh_ameliore(map_ameliore);
}
