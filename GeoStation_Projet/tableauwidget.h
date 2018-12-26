#ifndef TABLEAUWIDGET_H
#define TABLEAUWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class tableauwidget;
}

class tableauwidget : public QWidget
{
    Q_OBJECT

public:
    explicit tableauwidget(QWidget *parent = 0);
    ~tableauwidget();
    void refresh_ameliore(QMap<QString,QVariant> map_ameliore);

private:
    Ui::tableauwidget *ui;
    QTimer *timer;
    int map_size,NextEvent;
    QMap<QString, QVariant> data_map;
    void TimerFunction(QMap<QString, QVariant> map, bool mozaic = true, int index=0);

private slots:
   void repeat();

};

#endif // TABLEAUWIDGET_H
