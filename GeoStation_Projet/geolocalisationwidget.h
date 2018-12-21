#ifndef GEOLOCALISATIONWIDGET_H
#define GEOLOCALISATIONWIDGET_H

#include "awidget.h"
#include "geolocmozaicwidget.h"

class GeolocalisationWidget : public AWidget
{
public:
    explicit GeolocalisationWidget(QWidget *parent = nullptr);
    ~GeolocalisationWidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
		virtual bool				refresh();
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();

    GeoLocMozaicWidget *geolocalisation_mozaic_widget;


signals:
    void send_info(QMap<QString,QString>);
    void send_info2(QMap<QString,QVariant>);
};

#endif // GEOLOCALISATIONWIDGET_H
