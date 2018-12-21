#include "borneelectriquemozaicwidget.h"
#include "ui_borneelectriquemozaicwidget.h"

borneelectriquemozaicwidget::borneelectriquemozaicwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borneelectriquemozaicwidget)
{
    ui->setupUi(this);
}

borneelectriquemozaicwidget::~borneelectriquemozaicwidget()
{
    delete ui;
}
