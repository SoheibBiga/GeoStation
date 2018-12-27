#include "tableauwidget.h"
#include "ui_tableauwidget.h"
#include <QDebug>
#include <QTimer>

tableauwidget::tableauwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableauwidget)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    NextEvent=0;
    connect(timer, SIGNAL(timeout()),this, SLOT(repeat()));
}

tableauwidget::~tableauwidget()
{
    delete ui;
    timer->stop();
    delete  timer;
}


void tableauwidget::refresh_ameliore(QMap<QString,QVariant> map_ameliore)
{

    data_map=map_ameliore;
    map_size = data_map["Tableau"].toList().size();
    NextEvent = 0;

    if(map_size!=0){
        timer->start(1);
    }
    else TimerFunction(data_map);
}

void tableauwidget::repeat()
{
    TimerFunction(data_map,NextEvent);
    if(map_size >= 1){
        if(NextEvent < map_size-1) NextEvent++;
        else NextEvent = 0;
    }
    timer->start(10000);
}

void tableauwidget::TimerFunction(QMap<QString, QVariant> map, bool mozaic, int index)
{

//  if(mozaic)
//   {

    QStringList vlabels;
    int nb_row = map["Tableau"].toList().at(0).toMap().keys().size();
    ui->tableWidget->setRowCount(nb_row);

    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section {background-color:blue}");

    ui->tableWidget->resizeColumnsToContents();

   ui->tableWidget->horizontalHeader()->setStretchLastSection(1);

    ui->labelTitle->setText ( map["Parametre"].toMap()["Titre"].toString());
    ui->labelTitle->setWordWrap(true);
    ui->labelTitle->setAlignment(Qt::AlignCenter);

    QTableWidgetItem *item = new QTableWidgetItem();
    int i = 0;
    for(i = 0; i < nb_row; i++)
    {
        item = new QTableWidgetItem(map["Tableau"].toList().at(index).toMap().keys()[i]);
        ui->tableWidget->setItem(i, 0, item);

        item = new QTableWidgetItem(map["Tableau"].toList().at(index).toMap().value(map["Tableau"].toList().at(index).toMap().keys()[i]).toString());
        ui->tableWidget->setItem(i, 1, item);

    }
//  }
//  else
//  {

//  }


}

