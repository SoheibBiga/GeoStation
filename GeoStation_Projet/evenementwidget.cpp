#include "evenementwidget.h"
#include "ui_evenementwidget.h"

evenementwidget::evenementwidget(QWidget *parent) :
    AWidget(parent),
    ui(new Ui::evenementwidget)
{
    ui->setupUi(this);
}

evenementwidget::~evenementwidget()
{
    delete ui;
}

void evenementwidget::receive_info(QMap<QString, QString> map_formulaire){
    ui->tableWidget->refresh(map_formulaire);
}

bool				evenementwidget::contentMap() const
{
    return (true);
}

bool				evenementwidget::hasMozaicLayout() const
{
    return (true);
}

bool				evenementwidget::refresh() const
{
    return (true);
}

bool				evenementwidget::init()
{
    return true;
}

bool				evenementwidget::run()
{
    qDebug() << "[ DBG ] : run";
    return (true);
}

bool				evenementwidget::end()
{
    return (true);
}

void				evenementwidget::addWidget(QWidget* widget)
{
}
