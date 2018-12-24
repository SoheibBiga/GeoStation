#ifndef GEOLOCMOZAICWIDGET_H
#define GEOLOCMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include <QDebug>

namespace Ui {
class GeoLocMozaicWidget;
}

class GeoLocMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GeoLocMozaicWidget(QWidget *parent = nullptr);
    ~GeoLocMozaicWidget();

private:
    Ui::GeoLocMozaicWidget *ui;
    QPixmap pix;
public slots:
    void    receive_info(QMap<QString,QString> map_formulaire);
    void    receive_info2(QMap<QString,QVariant> map_ameliore);
};

#endif // GEOLOCMOZAICWIDGET_H
