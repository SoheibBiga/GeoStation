#ifndef EVENEMENTWIDGET_H
#define EVENEMENTWIDGET_H
#include "awidget.h"

namespace Ui {
class evenementwidget;
}

class evenementwidget : public AWidget
{
    Q_OBJECT

public:
    explicit evenementwidget(QWidget *parent = nullptr);
    ~evenementwidget();

    virtual bool				contentMap() const;
    virtual bool				hasMozaicLayout() const;
    virtual bool				refresh() const;
    virtual bool				init();
    virtual bool				run();
    virtual bool				end();
    virtual void				addWidget(QWidget* widget);

private:
    Ui::evenementwidget *ui;
signals:
    void send_info(QMap<QString,QString>);

private slots:
    void receive_info(QMap<QString,QString>);
};

#endif // EVENEMENTWIDGET_H
