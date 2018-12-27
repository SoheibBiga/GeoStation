#include "avionswidget.h"

AvionsWidget::AvionsWidget(QWidget *parent) :
    AWidget(parent)
{
    avions_mozaic_widget = new AvionsMozaicWidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(avions_mozaic_widget);

   avions_main_widget = new AvionsMainWidget();
    mainLayout_ = new QHBoxLayout();
    mainLayout_->addWidget(avions_main_widget);


    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),avions_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));

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

bool				AvionsWidget::refresh()
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

bool				AvionsWidget::hasMainLayout() const
{
    return false;
}

