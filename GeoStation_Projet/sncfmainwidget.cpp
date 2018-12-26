#include "sncfmainwidget.h"
#include "ui_sncfmainwidget.h"

SncfMainWidget::SncfMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SncfMainWidget)
{
    ui->setupUi(this);
}

SncfMainWidget::~SncfMainWidget()
{
    delete ui;
}
