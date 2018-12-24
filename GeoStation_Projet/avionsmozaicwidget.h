#ifndef AVOINSMOZAICWIDGET_H
#define AVOINSMOZAICWIDGET_H



#include <QWidget>
#include <QMap>
#include <QVariant>

namespace Ui {
class AvionsMozaicWidget;
}

class AvionsMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AvionsMozaicWidget(QWidget *parent = 0);
    ~AvionsMozaicWidget();

private:
    Ui::AvionsMozaicWidget *ui;


public slots:
    void receive_info(QMap<QString,QString> map_formulaire);  
    void receive_info2(QMap<QString, QVariant> map_ameliore);
};


#endif // AVOINSMOZAICWIDGET_H
