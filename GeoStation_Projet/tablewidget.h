#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class TableWidget;
}

class TableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TableWidget(QWidget *parent = 0);
    ~TableWidget();
    QTableWidgetItem *AdressItem, *DateItem, *TarifItem,  *ItineraireItem;

private:
    Ui::TableWidget *ui;

};

#endif // TABLEWIDGET_H
