#include "geolocmozaicwidget.h"
#include "ui_geolocmozaicwidget.h"
#include "pokemap.h"

GeoLocMozaicWidget::GeoLocMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeoLocMozaicWidget)
{
    ui->setupUi(this);

    this->setFixedSize(300, 477);
}

GeoLocMozaicWidget::~GeoLocMozaicWidget()
{
    delete ui;
}

void GeoLocMozaicWidget::receive_info(QMap<QString, QString>)
{

}

void GeoLocMozaicWidget::receive_info2(QMap<QString, QVariant> map_ameliore)
{
    if (ui->label_5->text().size() == 0)
    {
        QFont font;

        font.setPointSize(12);
        font.setBold(true);

        ui->label_3->setFont(font);
        ui->label_4->setFont(font);
        ui->label_5->setFont(font);
        ui->label_6->setFont(font);
        ui->label_3->setText(map_ameliore["Tableau"].toList().at(0).toMap()["adresse"].toString());
        ui->label_4->setText(map_ameliore["Tableau"].toList().at(0).toMap()["codePostal"].toString());
        ui->label_5->setText(map_ameliore["Tableau"].toList().at(0).toMap()["ville"].toString());
        ui->label_6->setText(map_ameliore["Tableau"].toList().at(0).toMap()["region"].toString());
    }
    else if (pix.isNull())
    {
        if (!map_ameliore["Tableau"].toList().at(0).toMap()["map"].toByteArray().isNull())
        {
            pix.loadFromData(map_ameliore["Tableau"].toList().at(0).toMap()["map"].toByteArray());
            ui->label_2->setPixmap(pix.scaled(ui->label->parentWidget()->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }


}
