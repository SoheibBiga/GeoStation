#ifndef BORNEELECTRIQUEMOZAICWIDGET_H
#define BORNEELECTRIQUEMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include "QDebug"

namespace Ui {
class borneelectriquemozaicwidget;
}

class borneelectriquemozaicwidget : public QWidget
{
    Q_OBJECT

public:
    explicit borneelectriquemozaicwidget(QWidget *parent = nullptr);
    ~borneelectriquemozaicwidget();

private:
    Ui::borneelectriquemozaicwidget *ui;
public slots:
    void receive_info2(QMap<QString,QVariant> map_ameliore);
};

#endif // BORNEELECTRIQUEMOZAICWIDGET_H
