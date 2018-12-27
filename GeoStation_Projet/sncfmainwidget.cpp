#include "sncfmainwidget.h"
#include "ui_sncfmainwidget.h"

SncfMainWidget::SncfMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SncfMainWidget)
{
    ui->setupUi(this);
    map = new PokeMap(PokeMap::CINQ_CENT_M);
    ui->label->setPixmap(map->pixmap().scaled(ui->label->parentWidget()->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

SncfMainWidget::~SncfMainWidget()
{
    delete ui;
}

void SncfMainWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    ui->tableWidget->refresh_ameliore(map_ameliore,false);
    QString lat = map_ameliore["Parametre"].toMap()["lat"].toString();
    QString lon = map_ameliore["Parametre"].toMap()["long"].toString();
    map->addPoint(lat,lon);
    //ui->label->setPixmap(map->pixmap().scaled(ui->label->parentWidget()->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

}
