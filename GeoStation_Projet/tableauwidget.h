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

    bool refresh(QMap<QString, QString> map_formulaire);
    void refresh_ameliore(QMap<QString,QVariant> map_ameliore);

private:
    Ui::tableauwidget *ui;
};

#endif // TABLEAUWIDGET_H
