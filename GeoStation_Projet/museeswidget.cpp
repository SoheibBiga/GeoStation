#include "museeswidget.h"
#include "ui_museeswidget.h"

MuseesWidget::MuseesWidget(QWidget *parent) :
    AWidget(parent),
    ui(new Ui::MuseesWidget)
{
    ui->setupUi(this);
}

MuseesWidget::~MuseesWidget()
{
    delete ui;
}
