#include "borneelectriquewidget.h"

BorneElectriqueWidget::BorneElectriqueWidget(QWidget* parent)
    : AWidget(parent)
{
    borneelectrique_mozaic_widget = new borneelectriquemozaicwidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(borneelectrique_mozaic_widget);
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),borneelectrique_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));

}

bool				BorneElectriqueWidget::contentMap() const
{
    return (false);
}

bool				BorneElectriqueWidget::hasMozaicLayout() const
{
    return (true);
}

bool				BorneElectriqueWidget::refresh()
{
    return (true);
}

bool				BorneElectriqueWidget::init()
{
    return (true);
}

bool				BorneElectriqueWidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				BorneElectriqueWidget::end()
{
    return (true);
}

void				BorneElectriqueWidget::addWidget(QWidget* widget)
{

}
