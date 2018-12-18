#include "sncfwidget.h"
#include "ui_sncfwidget.h"

sncfwidget::sncfwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sncfwidget)
{
    ui->setupUi(this);
    connect(this,SIGNAL(send_info(QMap<QString,QString>)),this,SLOT(receive_info(QMap<QString,QString>)));
}

sncfwidget::~sncfwidget()
{
    delete ui;
}

void sncfwidget::receive_info(QMap<QString, QString> map_formulaire){
    //refresh(map_formulaire);
}
