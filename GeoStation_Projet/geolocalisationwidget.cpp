#include "geolocalisationwidget.h"

GeolocalisationWidget::GeolocalisationWidget(QWidget *parent) :
    AWidget(parent)
{
    geolocalisation_mozaic_widget = new GeoLocMozaicWidget;
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(geolocalisation_mozaic_widget);

    connect(this, SIGNAL(send_info(QMap<QString,QString>)), geolocalisation_mozaic_widget, SLOT(receive_info(QMap<QString,QString>)));
    connect(this, SIGNAL(send_info2(QMap<QString,QVariant>)), geolocalisation_mozaic_widget, SLOT(receive_info2(QMap<QString,QVariant>)));
}

GeolocalisationWidget::~GeolocalisationWidget()
{
}

bool				GeolocalisationWidget::contentMap() const
{
    return (true);
}

bool				GeolocalisationWidget::hasMozaicLayout() const
{
    return (true);
}

bool				GeolocalisationWidget::refresh()
{
    return (true);
}

bool				GeolocalisationWidget::init()
{
    return true;
}

bool				GeolocalisationWidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				GeolocalisationWidget::end()
{
    return (true);
}
