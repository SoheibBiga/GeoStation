#include "evenementwidget.h"

EvenementWidget::EvenementWidget(QWidget *parent) :
    AWidget(parent)
{
    evenement_mozaic_widget = new EvenementMozaicWidget(this);
    mozaicLayout_ = new QHBoxLayout(this);
    mozaicLayout_->addWidget(evenement_mozaic_widget);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),evenement_mozaic_widget,SLOT(receive_info(QMap<QString,QString>)));
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),evenement_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));
}

EvenementWidget::~EvenementWidget()
{
}

bool				EvenementWidget::contentMap() const
{
    return (true);
}

bool				EvenementWidget::hasMozaicLayout() const
{
    return (true);
}

bool				EvenementWidget::refresh() const
{
    return (true);
}

bool				EvenementWidget::init()
{
    return true;
}

bool				EvenementWidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				EvenementWidget::end()
{
    return (true);
}

void				EvenementWidget::addWidget(QWidget* widget)
{
}
