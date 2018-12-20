#ifndef MUSEESWIDGET_H
#define MUSEESWIDGET_H

#include "awidget.h"
#include "museesmozaicwidget.h"
#include "museesmainwidget.h"


class MuseesWidget : public AWidget
{
    Q_OBJECT

public:
    explicit MuseesWidget(QWidget *parent = nullptr);
    ~MuseesWidget() ;
    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh() const;
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();
    virtual void				addWidget(QWidget* widget);

    MuseesMozaicWidget *musees_mozaic_widget;
    MuseesMainWidget *musees_main_widget;


signals:
    void send_info(QMap<QString,QString>);
};

#endif // MUSEESWIDGET_H
