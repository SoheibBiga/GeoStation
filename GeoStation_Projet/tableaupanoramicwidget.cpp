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

bool TableauPanoramicWidget::refresh(QMap<QString, QString> map_formulaire)
{
    if(map_formulaire.keys().size() == 0) return false;


    QStringList vlabels;
    int nb_row = map_formulaire.keys().size();
    ui->tableWidget->setRowCount(nb_row);

    int nb_Column= map_formulaire.keys().size();
    ui->tableWidget->setColumnCount(nb_Column);

    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section {background-color:blue}");

    int i = 0;
    for(i = 0; i < nb_row; i++){
            //qDebug() << map_formulaire.keys()[i] << "  :  " << map_formulaire.value(map_formulaire.keys()[i]) << endl;
            QTableWidgetItem *item =new QTableWidgetItem();
            vlabels << map_formulaire.keys()[i];
            item ->setText(map_formulaire.value(map_formulaire.keys()[i]));
            ui->tableWidget->setItem(0, i, item);
    }
    return true;
}
