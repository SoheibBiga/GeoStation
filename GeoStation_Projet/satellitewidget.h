#ifndef SATELLITEWIDGET_H
#define SATELLITEWIDGET_H

#include "awidget.h"
#include "satellitemozaicwidget.h"

namespace Ui {
class SatelliteWidget;
}

class SatelliteWidget : public AWidget
{
    Q_OBJECT

public:
    explicit SatelliteWidget(QWidget *parent = 0);
    ~SatelliteWidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh() const;
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();
    virtual void				addWidget(QWidget* widget);

    SatelliteMozaicWidget *satellite_mozaic_widget;


signals:
    void send_info(QMap<QString,QString>);
};


#endif // SATELLITEWIDGET_H
