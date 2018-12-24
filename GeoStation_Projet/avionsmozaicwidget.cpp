#include "avionsmozaicwidget.h"
#include "ui_avionsmozaicwidget.h"

AvionsMozaicWidget::AvionsMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AvionsMozaicWidget)
{
    ui->setupUi(this);

    //ui->textEdit->setText("JE VEUX VOIR ");

}

AvionsMozaicWidget::~AvionsMozaicWidget()
{
    delete ui;
}

void AvionsMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
   //ui->tableWidget->refresh(map_ameliore);


}

void AvionsMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    map_ameliore["Tableau"].toList().at(0).toMap().size();
 //   ui->tableWidget->refresh_ameliore(map_ameliore);
}
