#ifndef SNCFMOZAICWIDGET_H
#define SNCFMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include "QDebug"

namespace Ui {
class SncfMozaicWidget;
}

class SncfMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SncfMozaicWidget(QWidget *parent = 0);
    ~SncfMozaicWidget();

private:
    Ui::SncfMozaicWidget *ui;


public slots:
    void receive_info2(QMap<QString,QVariant> map_ameliore);

};

#endif // SNCFMOZAICWIDGET_H
