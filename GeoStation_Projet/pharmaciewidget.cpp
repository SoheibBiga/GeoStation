#include "pharmaciewidget.h"
#include "ui_pharmaciewidget.h"

PharmacieWidget::PharmacieWidget(QWidget *parent) :
    AWidget(parent),
    ui(new Ui::PharmacieWidget)
{
    ui->setupUi(this);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),this,SLOT(receive_info(QMap<QString,QString>)));
}

PharmacieWidget::~PharmacieWidget()
{
    delete ui;
}

void PharmacieWidget::receive_info(QMap<QString, QString>)
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

bool PharmacieWidget::refresh() const
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

void PharmacieWidget::addWidget(QWidget *widget)
{

}
