#include "tablewidget.h"
#include "ui_tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QTableWidget(parent),
    ui(new Ui::TableWidget)
{
    ui->setupUi(this);
   //refresh();
//    QStringList vlabels;

//    vlabels << tr("Adresse") << tr("Date") << tr("Tarif") << tr("Itineraire");
//    ui->tableWidget->setRowCount(4);
//    ui->tableWidget->setColumnCount(1);

//    //ui->tableWidget->setHorizontalHeaderLabels(hlabels);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget->setVerticalHeaderLabels(vlabels);
//    ui->tableWidget->horizontalHeader()->setVisible(false);
//    //ui->tableWidget->setShowGrid(false); //sans lignes (column 0)

//    AdressItem = new QTableWidgetItem();
//    DateItem = new QTableWidgetItem;
//    TarifItem = new QTableWidgetItem;
//    ItineraireItem = new QTableWidgetItem;

//    ui->lineEditTitre->setText("titre");

//    AdressItem->setText("will street");
//    DateItem->setText("12/12/2018");
//    TarifItem->setText("12£");
//    ItineraireItem->setText("meilleur itinéraire");

//    ui->tableWidget->setItem(0, 0, AdressItem);
//    ui->tableWidget->setItem(0, 1, DateItem);
//    ui->tableWidget->setItem(0, 2, TarifItem);
//    ui->tableWidget->setItem(0, 3, ItineraireItem);
}

TableWidget::~TableWidget()
{
    delete ui;
}

bool TableWidget::refresh(QMap<QString, QString> map_formulaire)
{
    if(map_formulaire.keys().size() == 0) return false;
    QTableWidgetItem *item =new QTableWidgetItem();
    QStringList vlabels;
    int nb_row = map_formulaire.keys().size();
    ui->tableWidget->setRowCount(nb_row);
    ui->tableWidget->setColumnCount(1);
    int i = 0, j = 0;
    for(i = 0; i < nb_row; i++){
        for(j = 0; j < nb_row; j++){
            vlabels << map_formulaire.keys()[i];
            item ->setText(map_formulaire.value(map_formulaire.keys()[i]));
            ui->tableWidget->setItem(i, j, item);
        }
    }
    return true;
}


