#ifndef POLLUTIONWIDGET_H
#define POLLUTIONWIDGET_H

#include "awidget.h"
#include "pollutionmozaicwidget.h"

class pollutionwidget : public AWidget
{
    Q_OBJECT
public:
    explicit pollutionwidget(QWidget *parent = 0);
    ~pollutionwidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				hasMainLayout() const ;
    virtual bool				refresh();
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();

    PollutionMozaicWidget *pollution_mozaic_widget;


signals:
    void send_info(QMap<QString,QString>);
    void send_info2(QMap<QString,QVariant>);
};

#endif // POLLUTIONWIDGET_H

