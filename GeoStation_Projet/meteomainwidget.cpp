#include "meteomainwidget.h"
#include "ui_meteomainwidget.h"

MeteoMainWidget::MeteoMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeteoMainWidget)
{
    ui->setupUi(this);
}

MeteoMainWidget::~MeteoMainWidget()
{
    delete ui;
}
