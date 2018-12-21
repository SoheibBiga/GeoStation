#ifndef GEOLOCALISATIONWIDGET_H
#define GEOLOCALISATIONWIDGET_H

#include "awidget.h"

class GeolocalisationWidget : public AWidget
{
public:
    explicit GeolocalisationWidget(QWidget *parent = nullptr);
    ~GeolocalisationWidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh() const;
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();

    //SncfMozaicWidget *sncf_mozaic_widget;


signals:
    void send_info(QMap<QString,QString>);
    void send_info2(QMap<QString,QVariant>);
};

#endif // GEOLOCALISATIONWIDGET_H