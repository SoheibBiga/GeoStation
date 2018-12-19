#include "sncfwidget.h"
#include "ui_sncfwidget.h"

sncfwidget::sncfwidget(QWidget *parent) :
    AWidget(parent),
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
    ui->tableWidget->refresh(map_formulaire);
}

bool				sncfwidget::contentMap() const
{
    return (true);
}

bool				sncfwidget::hasMozaicLayout() const
{
    return (true);
}

bool				sncfwidget::refresh() const
{
    return (true);
}

bool				sncfwidget::init()
{
    return true;
}

bool				sncfwidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				sncfwidget::end()
{
    return (true);
}

void				sncfwidget::addWidget(QWidget* widget)
{
}
