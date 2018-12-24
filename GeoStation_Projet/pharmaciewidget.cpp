#include "pharmaciewidget.h"

PharmacieWidget::PharmacieWidget(QWidget *parent) :
    AWidget(parent)

{
    pharmacie_mozaic_widget = new PharmacieMozaicWidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(pharmacie_mozaic_widget);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),pharmacie_mozaic_widget,SLOT(receive_info(QMap<QString,QString>)));
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),pharmacie_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));

}

PharmacieWidget::~PharmacieWidget()
{

}

bool PharmacieWidget::contentMap() const
{
    return(true);
}

bool PharmacieWidget::hasMozaicLayout() const
{
    return(true);
}

bool PharmacieWidget::refresh()
{
    return(true);
}

bool PharmacieWidget::init()
{
    return(true);
}

bool PharmacieWidget::run()
{
    qDebug() << "[ DBG ] : run";
    return(true);
}

bool PharmacieWidget::end()
{
    return(true);
}


