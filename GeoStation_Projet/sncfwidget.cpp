#include "sncfwidget.h"

SncfWidget::SncfWidget(QWidget *parent) :
    AWidget(parent)
{
    sncf_mozaic_widget = new SncfMozaicWidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(sncf_mozaic_widget);

    sncf_main_widget = new SncfMainWidget();
    mainLayout_ = new QHBoxLayout();
    mainLayout_->addWidget(sncf_main_widget);
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),sncf_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));
}

SncfWidget::~SncfWidget()
{
    delete sncf_mozaic_widget;
    delete sncf_main_widget;
}

bool				SncfWidget::contentMap() const
{
    return (true);
}

bool				SncfWidget::hasMozaicLayout() const
{
    return (true);
}

bool				SncfWidget::refresh()
{
    return (true);
}

bool				SncfWidget::init()
{
    return true;
}

bool				SncfWidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				SncfWidget::end()
{
    return (true);
}

