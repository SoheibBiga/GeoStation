#include "satellitewidget.h"
//#include "ui_satellitewidget.h"

SatelliteWidget::SatelliteWidget(QWidget *parent) :
    AWidget(parent)
{
    /*satellite_mozaic_widget = new SatelliteMozaicWidget(this);
    mozaicLayout_ = new QHBoxLayout(this);
    mozaicLayout_->addWidget(satellite_mozaic_widget);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),satellite_mozaic_widget,SLOT(receive_info(QMap<QString,QString>)));*/

}

SatelliteWidget::~SatelliteWidget()
{
}

bool				SatelliteWidget::contentMap() const
{
    return (true);
}

bool				SatelliteWidget::hasMozaicLayout() const
{
    return (true);
}

bool				SatelliteWidget::refresh() const
{
    return (true);
}

bool				SatelliteWidget::init()
{
    return true;
}

bool				SatelliteWidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				SatelliteWidget::end()
{
    return (true);
}

void				SatelliteWidget::addWidget(QWidget* widget)
{
}
