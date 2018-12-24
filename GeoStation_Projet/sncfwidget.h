#ifndef SNCFWIDGET_H
#define SNCFWIDGET_H

#include "awidget.h"
#include "sncfmozaicwidget.h"
#include "sncfmainwidget.h"

class SncfWidget : public AWidget
{
    Q_OBJECT

public:
    explicit SncfWidget(QWidget *parent = 0);
    ~SncfWidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh();
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();

    SncfMozaicWidget *sncf_mozaic_widget;
    SncfMainWidget *sncf_main_widget;
signals:
    void send_info2(QMap<QString,QVariant>);
};

#endif // SNCFWIDGET_H

