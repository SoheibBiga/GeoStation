#ifndef GEOLOCALISATIONWIDGET_H
#define GEOLOCALISATIONWIDGET_H

#include "awidget.h"

namespace Ui {
class GeolocalisationWidget;
}

class GeolocalisationWidget : public AWidget
{
    Q_OBJECT

public:
    explicit GeolocalisationWidget(QWidget *parent = nullptr);
    ~GeolocalisationWidget();

private:
    Ui::GeolocalisationWidget *ui;
};

#endif // GEOLOCALISATIONWIDGET_H
