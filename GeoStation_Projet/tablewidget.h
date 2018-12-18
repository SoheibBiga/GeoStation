#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include "awidget.h"
#include <QTableWidget>


namespace Ui {
class TableWidget;
}

class TableWidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit TableWidget(QWidget *parent = 0);
    ~TableWidget();
    QTableWidgetItem *AdressItem, *DateItem, *TarifItem,  *ItineraireItem;

    bool refresh(QMap<QString, QString> map_formulaire);

private:
    Ui::TableWidget *ui;
};

#endif // TABLEWIDGET_H
