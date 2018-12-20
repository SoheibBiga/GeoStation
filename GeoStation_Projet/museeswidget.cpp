#include "museeswidget.h"

MuseesWidget::MuseesWidget(QWidget *parent):
    AWidget(parent)
{
    musees_mozaic_widget = new MuseesMozaicWidget(this);
    //mozaicLayout_ = new QHBoxLayout(this);
    //mozaicLayout_->addWidget(sncf_mozaic_widget);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),musees_mozaic_widget,SLOT(receive_info(QMap<QString,QString>)));

}

MuseesWidget::~MuseesWidget()
{
}

bool				MuseesWidget::contentMap() const
{
    return (true);
}

bool				MuseesWidget::hasMozaicLayout() const
{
    return (true);
}

bool				MuseesWidget::refresh() const
{
    return (true);
}

bool				MuseesWidget::init()
{
    return true;
}

bool				MuseesWidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				MuseesWidget::end()
{
    return (true);
}

void				MuseesWidget::addWidget(QWidget* )
{
}
