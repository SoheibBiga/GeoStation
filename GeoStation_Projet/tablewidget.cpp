#include "tablewidget.h"
#include "ui_tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWidget)
{
    ui->setupUi(this);
    QStringList vlabels;

    vlabels << tr("Adresse") << tr("Date") << tr("Tarif") << tr("Itineraire");
    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setColumnCount(1);

    //ui->tableWidget->setHorizontalHeaderLabels(hlabels);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setVerticalHeaderLabels(vlabels);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    //ui->tableWidget->setShowGrid(false); //sans lignes (column 0)

    AdressItem = new QTableWidgetItem;
    DateItem = new QTableWidgetItem;
    TarifItem = new QTableWidgetItem;
    ItineraireItem = new QTableWidgetItem;

    ui->lineEditTitre->setText("titre");

    AdressItem->setText("will street");
    DateItem->setText("12/12/2018");
    TarifItem->setText("12£");
    ItineraireItem->setText("meilleur itinéraire");

    ui->tableWidget->setItem(0, 0, AdressItem);
    ui->tableWidget->setItem(0, 1, DateItem);
    ui->tableWidget->setItem(0, 2, TarifItem);
    ui->tableWidget->setItem(0, 3, ItineraireItem);
}

TableWidget::~TableWidget()
{
    delete ui;
}
