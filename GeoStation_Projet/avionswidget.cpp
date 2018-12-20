#include "avionswidget.h"

AvionsWidget::AvionsWidget(QWidget *parent) :
    AWidget(parent)
{
    avions_mozaic_widget = new AvionsMozaicWidget(this);
    mozaicLayout_ = new QHBoxLayout(this);
    mozaicLayout_->addWidget(avions_mozaic_widget);
//    connect(this,SIGNAL(send_info(QMap<QString,QString>)),avions_mozaic_widget,SLOT(receive_info(QMap<QString,QString>)));
//    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),avions_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));

}

AvionsWidget::~AvionsWidget()
{
}

bool				AvionsWidget::contentMap() const
{
    return (true);
}

bool				AvionsWidget::hasMozaicLayout() const
{
    return (true);
}

bool				AvionsWidget::refresh() const
{
    return (true);
}

bool				AvionsWidget::init()
{
    return true;
}

bool				AvionsWidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				AvionsWidget::end()
{
    return (true);
}

void				AvionsWidget::addWidget(QWidget* widget)
{
}
