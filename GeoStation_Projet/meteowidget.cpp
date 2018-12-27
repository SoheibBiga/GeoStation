#include "meteowidget.h"

MeteoWidget::MeteoWidget(QWidget *parent) :
    AWidget(parent)
{
    meteo_mozaic_widget = new MeteoMozaicWidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(meteo_mozaic_widget);
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),meteo_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));
    meteo_main_widget = new MeteoMainWidget();
    mainLayout_ = new QHBoxLayout();
}

MeteoWidget::~MeteoWidget()
{
}

bool				MeteoWidget::contentMap() const
{
    return (false);
}

bool				MeteoWidget::hasMozaicLayout() const
{
    return (true);
}

bool				MeteoWidget::refresh()
{
    return (true);
}

bool				MeteoWidget::init()
{
    return true;
}

bool				MeteoWidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				MeteoWidget::end()
{
    return (true);
}

bool				MeteoWidget::hasMainLayout() const
{
    return false;
}
