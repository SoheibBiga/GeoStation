#include "geolocalisationwidget.h"

GeolocalisationWidget::GeolocalisationWidget(QWidget *parent) :
    AWidget(parent)
{
   /* sncf_mozaic_widget = new SncfMozaicWidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(sncf_mozaic_widget);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),sncf_mozaic_widget,SLOT(receive_info(QMap<QString,QString>)));
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));*/

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

bool				GeolocalisationWidget::refresh() const
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
