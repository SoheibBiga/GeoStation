#include "pollutionwidget.h"

pollutionwidget::pollutionwidget(QWidget *parent) :
    AWidget(parent)
{
    pollution_mozaic_widget = new PollutionMozaicWidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(pollution_mozaic_widget);
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),pollution_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));
}

pollutionwidget::~pollutionwidget()
{
}

bool				pollutionwidget::contentMap() const
{
    return (false);
}

bool				pollutionwidget::hasMozaicLayout() const
{
    return (true);
}

bool				pollutionwidget::refresh()
{
    return (true);
}

bool				pollutionwidget::init()
{
    return true;
}

bool				pollutionwidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				pollutionwidget::end()
{
    return (true);
}

//gilles@gillesmaire.com
