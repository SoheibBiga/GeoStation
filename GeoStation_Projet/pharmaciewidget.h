#ifndef PHARMACIEWIDGET_H
#define PHARMACIEWIDGET_H

#include "awidget.h"
#include "pharmaciemozaicwidget.h"

class PharmacieWidget : public AWidget
{
    Q_OBJECT
public:
    explicit PharmacieWidget(QWidget *parent = 0);
    ~PharmacieWidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh();
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();

    PharmacieMozaicWidget *pharmacie_mozaic_widget;

signals:
    void send_info(QMap<QString,QString>);
    void send_info2(QMap<QString,QVariant>);
};

#endif // PHARMACIEWIDGET_H
