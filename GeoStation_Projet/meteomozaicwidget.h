#ifndef METEOMOZAICWIDGET_H
#define METEOMOZAICWIDGET_H

#include <QWidget>
#include <QMap>
#include <QVariant>

namespace Ui {
class MeteoMozaicWidget;
}

class MeteoMozaicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MeteoMozaicWidget(QWidget *parent = nullptr);
    ~MeteoMozaicWidget();

private:
    Ui::MeteoMozaicWidget *ui;

public slots:
    void receive_info2(QMap<QString,QVariant> map_ameliore);
};

#endif // METEOMOZAICWIDGET_H
