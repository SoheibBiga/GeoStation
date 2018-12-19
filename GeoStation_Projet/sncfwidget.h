#ifndef SNCFWIDGET_H
#define SNCFWIDGET_H

#include "awidget.h"

namespace Ui {
class sncfwidget;
}

class sncfwidget : public AWidget
{
    Q_OBJECT

public:
    explicit sncfwidget(QWidget *parent = 0);
    ~sncfwidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh() const;
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();
    virtual void				addWidget(QWidget* widget);

private:
    Ui::sncfwidget *ui;

signals:
    void send_info(QMap<QString,QString>);

private slots:
    void receive_info(QMap<QString,QString>);
};

#endif // SNCFWIDGET_H
