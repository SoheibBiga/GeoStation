#ifndef VIGICRUESWIDGET_H
#define VIGICRUESWIDGET_H

#include "awidget.h"
#include "vigicruesmosaicwidget.h"

class Vigicrueswidget : public AWidget
{
    Q_OBJECT

public:
    explicit Vigicrueswidget(QWidget *parent = 0);
    ~Vigicrueswidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh() const;
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();

    Vigicruesmosaicwidget *vigicruesmosaicwidget;


signals:
    void send_info(QMap<QString,QString>);
};

#endif // VIGICRUESWIDGET_H
