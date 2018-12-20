#include "evenementmozaicwidget.h"
#include "ui_evenementmozaicwidget.h"

EvenementMozaicWidget::EvenementMozaicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvenementMozaicWidget)
{
    ui->setupUi(this);
}

EvenementMozaicWidget::~EvenementMozaicWidget()
{
    delete ui;
}
