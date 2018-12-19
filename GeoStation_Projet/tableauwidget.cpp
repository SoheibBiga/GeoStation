#include "tableauwidget.h"
#include "ui_tableauwidget.h"

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
