#include "tableauwidget.h"
#include "ui_tableauwidget.h"
#include <QDebug>

tableauwidget::tableauwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableauwidget)
{
    ui->setupUi(this);
}

tableauwidget::~tableauwidget()
{
    delete ui;
}

bool tableauwidget::refresh(QMap<QString, QString> map_formulaire)
{
    if(map_formulaire.keys().size() == 0) return false;


    QStringList vlabels;
    int nb_row = map_formulaire.keys().size();
    ui->tableWidget->setRowCount(nb_row);

    ui->tableWidget->setColumnCount(1);

    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section {background-color:blue}");

    int i = 0;
    for(i = 0; i < nb_row; i++){

        QTableWidgetItem *item =new QTableWidgetItem();
        vlabels << map_formulaire.keys()[i];
        item ->setText(map_formulaire.value(map_formulaire.keys()[i]));
        ui->tableWidget->setItem(0, i, item);
    }
    return true;
}

void tableauwidget::refresh_ameliore(QMap<QString,QVariant> map_ameliore,bool mozaic)
{
   if(mozaic)
   {

    QStringList vlabels;
    int nb_row = map_ameliore["Tableau"].toList().at(0).toMap().keys().size();
    ui->tableWidget->setRowCount(nb_row);

    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section {background-color:blue}");

    ui->labelTitle->setText ( map_ameliore["Parametre"].toMap()["Titre"].toString());
    ui->labelTitle->setWordWrap(true);
    ui->labelTitle->setAlignment(Qt::AlignCenter);

    QTableWidgetItem *item = new QTableWidgetItem();
    int i = 0;
    for(i = 0; i < nb_row; i++)
    {
        item = new QTableWidgetItem(map_ameliore["Tableau"].toList().at(0).toMap().keys()[i]);
        ui->tableWidget->setItem(i, 0, item);
        item = new QTableWidgetItem(map_ameliore["Tableau"].toList().at(0).toMap().value(map_ameliore["Tableau"].toList().at(0).toMap().keys()[i]).toString());
        ui->tableWidget->setItem(i, 1, item);

    }
   }
   else
   {
       QStringList vlabels;
       QTableWidgetItem *item = new QTableWidgetItem();

       QTableWidgetItem *icon_item = new QTableWidgetItem;

       int nb_row = map_ameliore["Tableau"].toList().size();
       ui->tableWidget->setRowCount(nb_row);

       int nb_Column = map_ameliore["Tableau"].toList().at(1).toMap().keys().size();
       ui->tableWidget->setColumnCount(nb_Column);
       qDebug() << nb_Column;
       qDebug() << nb_row;

      // ui->tableWidget->horizontalHeader()->setVisible(false);
       ui->tableWidget->verticalHeader()->setVisible(false);
       ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:green}");

       ui->labelTitle->setText ( map_ameliore["Parametre"].toMap()["Titre"].toString());
       ui->labelTitle->setWordWrap(true);
       ui->labelTitle->setAlignment(Qt::AlignCenter);

       QIcon icon("/home/ghania/Bureau/projet/GeoStation_old_7/GeoStation_Projet/Icons/adresse.svg");
       QIcon icon2("/home/ghania/Bureau/projet/GeoStation_old_7/GeoStation_Projet/Icons/Date.svg");

       for(int i = 0; i < nb_row; i++)
       {
         for(int j = 0; j < nb_Column; j++)
         {

          // item = new QTableWidgetItem(map_ameliore["Tableau"].toList().at(0).toMap().keys()[i]);
           //ui->tableWidget->setItem(0, i, item);

           item = new QTableWidgetItem(map_ameliore["Tableau"].toList().at(i).toMap().value(map_ameliore["Tableau"].toList().at(i).toMap().keys()[j]).toString());
           ui->tableWidget->setItem(i, j, item);
          }
       }
     }

}

