#include "vigicrueswidget.h"

Vigicrueswidget::Vigicrueswidget(QWidget *parent) :
    AWidget(parent)
{
    vigicruesmosaicwidget = new Vigicruesmosaicwidget();
    mozaicLayout_ = new QHBoxLayout();
    mozaicLayout_->addWidget(vigicruesmosaicwidget);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),vigicruesmosaicwidget,
            SLOT(receive_info(QMap<QString,QString>)));
}

Vigicrueswidget::~Vigicrueswidget()
{
    delete vigicruesmosaicwidget;
}

bool				Vigicrueswidget::contentMap() const
{
    return (true);
}

bool				Vigicrueswidget::hasMozaicLayout() const
{
    return (true);
}

bool				Vigicrueswidget::refresh()
{
    return (true);
}

bool				Vigicrueswidget::init()
{
    return true;
}

bool				Vigicrueswidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				Vigicrueswidget::end()
{
    return (true);
}

bool				Vigicrueswidget::hasMainLayout() const
{
    return false;
}

