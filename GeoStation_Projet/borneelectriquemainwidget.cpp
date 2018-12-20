#include "borneelectriquemainwidget.h"
#include "ui_borneelectriquemainwidget.h"

borneelectriquemainwidget::borneelectriquemainwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borneelectriquemainwidget)
{
    ui->setupUi(this);
}

borneelectriquemainwidget::~borneelectriquemainwidget()
{
    delete ui;
}
