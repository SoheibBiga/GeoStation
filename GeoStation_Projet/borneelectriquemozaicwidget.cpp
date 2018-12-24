#include "borneelectriquemozaicwidget.h"
#include "ui_borneelectriquemozaicwidget.h"

borneelectriquemozaicwidget::borneelectriquemozaicwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borneelectriquemozaicwidget)
{
    ui->setupUi(this);
}

borneelectriquemozaicwidget::~borneelectriquemozaicwidget()
{
    delete ui;
}

void borneelectriquemozaicwidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    ui->tableWidget->refresh_ameliore(map_ameliore);
}
