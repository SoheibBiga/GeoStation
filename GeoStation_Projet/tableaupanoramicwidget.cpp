#include "tableaupanoramicwidget.h"
#include "ui_tableaupanoramicwidget.h"

TableauPanoramicWidget::TableauPanoramicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableauPanoramicWidget)
{
    ui->setupUi(this);
}

TableauPanoramicWidget::~TableauPanoramicWidget()
{
    delete ui;
}


void TableauPanoramicWidget::refresh_ameliore(QMap<QString,QVariant> map_ameliore)
{
    //if(map_formulaire.keys().size() == 0) return;
    QStringList vlabels;
    int nb_row = map_ameliore["Tableau"].toList().at(0).toMap().keys().size();
    ui->tableWidget->setRowCount(nb_row);
    //    int nb_Column= map_formulaire.keys().size();
    //    ui->tableWidget->setColumnCount(nb_Column);

    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section {background-color:blue}");

//    ui->labelTitle->setText ( map_ameliore["Parametre"].toMap()["Titre"].toString());
//    ui->labelTitle->setWordWrap(true);
//    ui->labelTitle->setAlignment(Qt::AlignCenter);

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
