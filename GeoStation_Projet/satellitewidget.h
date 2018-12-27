#ifndef SATELLITEWIDGET_H
#define SATELLITEWIDGET_H

#include "awidget.h"
#include "satellitemozaicwidget.h"



class SatelliteWidget : public AWidget
{
    Q_OBJECT

public:
    explicit SatelliteWidget(QWidget *parent = 0);
    ~SatelliteWidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				hasMainLayout() const ;
    virtual bool				refresh();
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();


    SatelliteMozaicWidget *satellite_mozaic_widget;


signals:
    //void send_info(QMap<QString,QString>);
    void send_info2(QMap<QString,QVariant>);
};


#endif // SATELLITEWIDGET_H
