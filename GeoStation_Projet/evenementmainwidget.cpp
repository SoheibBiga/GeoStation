#include "evenementmainwidget.h"
#include "ui_evenementmainwidget.h"

EvenementMainWidget::EvenementMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvenementMainWidget)
{
    ui->setupUi(this);
}

EvenementMainWidget::~EvenementMainWidget()
{
    delete ui;
}
