#ifndef PHARMACIEMAINWIDGET_H
#define PHARMACIEMAINWIDGET_H

#include <QWidget>
#include <QVariantMap>
namespace Ui {
class PharmacieMainWidget;
}

class PharmacieMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PharmacieMainWidget(QWidget *parent = 0);
    ~PharmacieMainWidget();

private:
    Ui::PharmacieMainWidget *ui;


public slots:
    void receive_info2(QVariantMap map_ameliore);
};

#endif // PHARMACIEMAINWIDGET_H
