#include "vigicruesmainwidget.h"
#include "ui_vigicruesmainwidget.h"

VigicruesMainWidget::VigicruesMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VigicruesMainWidget)
{
    ui->setupUi(this);
}

VigicruesMainWidget::~VigicruesMainWidget()
{
    delete ui;
}
