#include "satellitewidget.h"
#include "satellitemozaicwidget.h"


SatelliteWidget::SatelliteWidget(QWidget *parent) :
    AWidget(parent),
    satellite_mozaic_widget(Q_NULLPTR)

{
    satellite_mozaic_widget = new SatelliteMozaicWidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(satellite_mozaic_widget);
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),satellite_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));
}

SatelliteWidget::~SatelliteWidget()
{}

bool				SatelliteWidget::contentMap() const
{
    return (true);
}

bool				SatelliteWidget::hasMozaicLayout() const
{
    return (true);
}

bool				SatelliteWidget::refresh()
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

