#ifndef AVIONSWIDGET_H
#define AVIONSWIDGET_H



#include "awidget.h"
#include "avionsmozaicwidget.h"
#include "avionsmainwidget.h"

class AvionsWidget : public AWidget
{
    Q_OBJECT

public:
    explicit AvionsWidget(QWidget *parent = 0);
    ~AvionsWidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				hasMainLayout() const ;
    virtual bool				refresh();
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();
    virtual void				addWidget(QWidget* widget);

    AvionsMozaicWidget *avions_mozaic_widget;
    AvionsMainWidget *avions_main_widget;

signals:
    void send_info2(QMap<QString,QString>);
};



#endif // AVIONSWIDGET_H
