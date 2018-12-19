#ifndef PHARMACIEWIDGET_H
#define PHARMACIEWIDGET_H

#include "awidget.h"

namespace Ui {
class PharmacieWidget;
}

class PharmacieWidget : public AWidget
{
    Q_OBJECT

public:
    explicit PharmacieWidget(QWidget *parent = nullptr);
    ~PharmacieWidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh() const;
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();
    virtual void				addWidget(QWidget* widget);


private:
    Ui::PharmacieWidget *ui;

signals:
    void send_info(QMap<QString,QString>);

private slots:
    void receive_info(QMap<QString,QString>);
};

#endif // PHARMACIEWIDGET_H
