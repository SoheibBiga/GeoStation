#include "pollutionmozaicwidget.h"
#include "ui_pollutionmozaicwidget.h"

PollutionMozaicWidget::PollutionMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PollutionMozaicWidget)
{
    ui->setupUi(this);
}

PollutionMozaicWidget::~PollutionMozaicWidget()
{
    delete ui;
}

void PollutionMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    //ui->tableWidget->refresh_ameliore(map_ameliore);
}
