#include "museesmainwidget.h"
#include "ui_museesmainwidget.h"

MuseesMainWidget::MuseesMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MuseesMainWidget)
{
    ui->setupUi(this);
}

MuseesMainWidget::~MuseesMainWidget()
{
    delete ui;
}

void MuseesMainWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    //ui->tableWidget->refresh(map_formulaire);
}
