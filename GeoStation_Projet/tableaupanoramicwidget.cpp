#include "tableaupanoramicwidget.h"
#include "ui_tableaupanoramicwidget.h"

TableauPanoramicWidget::TableauPanoramicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableauPanoramicWidget)
{
    ui->setupUi(this);
}

TableauPanoramicWidget::~TableauPanoramicWidget()
{
    delete ui;
}
