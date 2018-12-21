#ifndef GEOLOCALISATIONMOZAICWIDGET_H
#define GEOLOCALISATIONMOZAICWIDGET_H

#include <QWidget>

namespace Ui {
class GeolocalisationMozaicWidget;
}

class GeolocalisationMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GeolocalisationMozaicWidget(QWidget *parent = nullptr);
    ~GeolocalisationMozaicWidget();

private:
    Ui::GeolocalisationMozaicWidget *ui;
};

#endif // GEOLOCALISATIONMOZAICWIDGET_H
