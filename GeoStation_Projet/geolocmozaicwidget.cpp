#include "geolocmozaicwidget.h"
#include "ui_geolocmozaicwidget.h"
#include "pokemap.h"

GeoLocMozaicWidget::GeoLocMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeoLocMozaicWidget)
{
    ui->setupUi(this);
    PokeMap *map = new PokeMap(PokeMap::CENT_M);

    map->addText(15, 40, "6 rue rougemont");
    map->addPoint("48.871554", "2.346000");
    ui->label->setPixmap(map->pixmap().scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

}

GeoLocMozaicWidget::~GeoLocMozaicWidget()
{
    delete ui;
}

void GeoLocMozaicWidget::receive_info(QMap<QString, QString> map_formulaire)
{
    //ui->tableWidget->refresh(map_formulaire);
}

void GeoLocMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    //ui->tableWidget->refresh_ameliore(map_ameliore);
}

void    GeoLocMozaicWidget::setTextButton()
{
    //ui->label->setText("CHIEHCIHECIHEICHEI");
}

void GeoLocMozaicWidget::on_pushButton_clicked()
{
    ui->label->setText("Chicken");
}

void GeoLocMozaicWidget::on_pushButton_2_clicked()
{
    ui->label->setText("Chickkjfklsmfsdkfjdsfjdsjfmdsfjldsjfklmsdkjfmsdkfmsdkflmsdklfdklfmsdkmfskdlmfksdlmfskdmlfkdsl");
}
