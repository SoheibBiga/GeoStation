#include "sncfwidget.h"
#include "ui_sncfwidget.h"

sncfwidget::sncfwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sncfwidget)
{
    ui->setupUi(this);
}

sncfwidget::~sncfwidget()
{
    delete ui;
}
