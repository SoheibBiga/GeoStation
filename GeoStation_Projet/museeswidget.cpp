#include "museeswidget.h"

MuseesWidget::MuseesWidget(QWidget *parent):
    AWidget(parent)
{
    musees_mozaic_widget = new MuseesMozaicWidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(musees_mozaic_widget);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),musees_mozaic_widget,SLOT(receive_info(QMap<QString,QString>)));
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),musees_mozaic_widget,SLOT(receive_info2(QMap<QString,QVariant>)));

    musees_main_widget = new MuseesMainWidget();
    mainLayout_ = new QHBoxLayout();
    mainLayout_->addWidget(musees_main_widget);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),musees_main_widget,SLOT(receive_info(QMap<QString,QString>)));
    connect(this,SIGNAL(send_info2(QMap<QString,QVariant>)),musees_main_widget,SLOT(receive_info2(QMap<QString,QVariant>)));

}

/*MuseesWidget::~MuseesWidget()
{
}*/

bool				MuseesWidget::contentMap() const
{
    return (true);
}

bool				MuseesWidget::hasMozaicLayout() const
{
    return (true);
}

bool				MuseesWidget::refresh()
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

/*void				MuseesWidget::addWidget(QWidget* )
{
}*/
