#include "vigicruesmosaicwidget.h"
#include "ui_vigicruesmosaicwidget.h"

Vigicruesmosaicwidget::Vigicruesmosaicwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vigicruesmosaicwidget)
{
    ui->setupUi(this);
}

Vigicruesmosaicwidget::~Vigicruesmosaicwidget()
{
    delete ui;
}

void Vigicruesmosaicwidget::receive_info(QMap<QString, QString> map_formulaire)
{
    ui->widget->refresh(map_formulaire);
}
