#include "avionsmainwidget.h"
#include "ui_avionsmainwidget.h"

AvionsMainWidget::AvionsMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AvionsMainWidget)
{
    ui->setupUi(this);
}

AvionsMainWidget::~AvionsMainWidget()
{
    delete ui;
}

