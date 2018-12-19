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
    QTableWidgetItem *item =new QTableWidgetItem();

    QStringList vlabels;
    int nb_row = map_formulaire.keys().size();
    ui->tableWidget->setRowCount(nb_row);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section {background-color:yellow}");
    int i = 0;
    for(i = 0; i < nb_row; i++){
            //qDebug() << map_formulaire.keys()[i] << "  :  " << map_formulaire.value(map_formulaire.keys()[i]) << endl;
            vlabels << map_formulaire.keys()[i];
            item ->setText(map_formulaire.value(map_formulaire.keys()[i]));
            ui->tableWidget->setItem(i, 1, item);
    }
    return true;
}
