#ifndef METEOWIDGET_H
#define METEOWIDGET_H
#include "awidget.h"
#include "meteomozaicwidget.h"
#include "meteomainwidget.h"

class MeteoWidget : public AWidget
{
     Q_OBJECT
public:
    MeteoWidget(QWidget *parent = 0);
    ~MeteoWidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh();
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();

    MeteoMozaicWidget *meteo_mozaic_widget;
    MeteoMainWidget *meteo_main_widget;

signals:
    void send_info2(QMap<QString,QVariant>);
};

#endif // METEOWIDGET_H
